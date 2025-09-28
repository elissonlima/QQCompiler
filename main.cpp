#include <iostream>
#include <armadillo>

#include "qasm/qasm.h"

using namespace std;
using namespace arma;

ZYZParams get_zyz_params_from_matrix(cx_mat U) {

    ZYZParams params { 0.0, 0.0, 0.0, 0.0 };

    if (U.n_rows != 2 || U.n_cols != 2) {
        throw std::invalid_argument("U must be a 2x2 matrix");
    }

    const mat A = {
        { 1, -0.5, -0.5 },
        { 1, -0.5, 0.5 },
        { 1, 0.5, -0.5 }
    };

    const vec b = {
        std::arg(U(0,0)),
        std::arg(-U(0,1)),
        std::arg(U(1,0)),
    };

    mat X = solve(A, b);

    params.alpha = X(0);
    params.beta = X(1);
    params.delta = X(2);

    const double amplitude = std::abs(U(0,0));
    params.gamma = 2 * std::acos(amplitude);

    return params;
}

int main() {

    cx_mat SRQ_X(2, 2, fill::zeros);

    SRQ_X(0, 0 ) = cx_double(0.5, 0.5);
    SRQ_X(0, 1 ) = cx_double(0.5, -0.5);
    SRQ_X(1, 0 ) = cx_double(0.5, -0.5);
    SRQ_X(1, 1 ) = cx_double(0.5, 0.5);

    ZYZParams params = get_zyz_params_from_matrix(SRQ_X);

    QAsm qasm(1, std::vector<ZYZParams>{params});
    cout << qasm.generate_qasm() << endl;

    return 0;
}