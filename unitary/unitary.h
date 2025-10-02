//
// Created by Alex on 01/10/25.
//

#ifndef QQCOMPILER_UNITARY_H
#define QQCOMPILER_UNITARY_H
#include <armadillo>

struct ZYZParams {
    double alpha;
    double beta;
    double gamma;
    double delta;
};

struct ControlledGate {
    arma::cx_mat A;
    arma::cx_mat B;
    arma::cx_mat C;
    arma::cx_mat P;
};

ZYZParams get_zyz_params_from_matrix(arma::cx_mat U);
ControlledGate get_c_gate_from_matrix(const arma::cx_mat &V);

arma::cx_mat rz_from_angle(double angle);
arma::cx_mat ry_from_angle(double angle);


#endif //QQCOMPILER_UNITARY_H