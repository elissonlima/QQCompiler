//
// Created by Alex on 01/10/25.
//

#include <sstream>
#include <armadillo>
#include "../qasm/qasm.h"

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