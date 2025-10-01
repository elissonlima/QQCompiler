//
// Created by Alex on 01/10/25.
//

#ifndef QQCOMPILER_UNITARY_H
#define QQCOMPILER_UNITARY_H
#include <armadillo>
#include "../qasm/qasm.h"

ZYZParams get_zyz_params_from_matrix(arma::cx_mat U);

#endif //QQCOMPILER_UNITARY_H