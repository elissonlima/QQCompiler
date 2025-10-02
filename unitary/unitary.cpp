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

ControlledGate get_c_gate_from_matrix(const cx_mat &V) {

    ZYZParams params = get_zyz_params_from_matrix(V);

    cx_mat A = rz_from_angle(params.beta) * ry_from_angle(params.gamma/2);
    cx_mat B = ry_from_angle(-params.gamma/2) * rz_from_angle(-(params.delta + params.beta)/2);
    cx_mat C = rz_from_angle((params.delta - params.beta)/2);
    cx_mat P = {
        {cx_double(1, 0), cx_double(0,0)},
            {cx_double(0, 0), std::polar(1.0, params.alpha)},
    };

    ControlledGate gate_params { A,
        B,
        C,
        P
    };

    return gate_params;
}

cx_mat rz_from_angle(const double angle) {
    cx_mat Rz = {
        { std::polar(1.0, -angle/2), cx_double(0,0)},
        { cx_double(0, 0), std::polar(1.0, angle/2) }
    };
    return Rz;
}
cx_mat ry_from_angle(const double angle) {
    cx_mat Ry = {
        {cx_double(cos(angle/2), 0), cx_double(-sin(angle/2)), 0 },
        {cx_double(sin(angle/2), 0), cx_double(cos(angle/2)), 0 },
    };
    return Ry;
}