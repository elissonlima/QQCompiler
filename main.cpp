#include <iostream>
#include <armadillo>
#include <gtest/gtest.h>

#include "qasm/qasm.h"
#include "unitary/unitary.h"

using namespace std;
using namespace arma;

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


