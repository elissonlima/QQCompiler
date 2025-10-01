#include <armadillo>
#include <gtest/gtest.h>

#include "../qasm/qasm.h"       
#include "../unitary/unitary.h" 

TEST(UnitaryDecomposition, TestSQRTX) {
    
    arma::cx_mat SQRT_X(2, 2, arma::fill::zeros);
    SQRT_X(0, 0) = arma::cx_double(0.5, 0.5);
    SQRT_X(0, 1) = arma::cx_double(0.5, -0.5);
    SQRT_X(1, 0) = arma::cx_double(0.5, -0.5);
    SQRT_X(1, 1) = arma::cx_double(0.5, 0.5);

    ZYZParams params = get_zyz_params_from_matrix(SQRT_X);

    ASSERT_DOUBLE_EQ(params.alpha, arma::datum::pi / 4.0);
    ASSERT_DOUBLE_EQ(params.beta,  -arma::datum::pi / 2.0);
    ASSERT_DOUBLE_EQ(params.gamma,  arma::datum::pi / 2.0);
    ASSERT_DOUBLE_EQ(params.delta,  arma::datum::pi / 2.0);
}