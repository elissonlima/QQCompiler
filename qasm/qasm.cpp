//
// Created by Elisson on 27/09/25.
//
#include <sstream>
#include "qasm.h"

void QAsm::define_qubits(const int n_qubits) {
    if (n_qubits == 1)
        qasm_code << "qubit q;" << std::endl;
    else if (n_qubits == 2)
        qasm_code << "qubit[2] q;" << std::endl;
}

void QAsm::single_qubit_port(const ZYZParams &params) {
    qasm_code << "p(" << params.alpha << ") q;" << std::endl;
    qasm_code << "rz(" << params.beta << ") q;" << std::endl;
    qasm_code << "ry(" << params.gamma << ") q;" << std::endl;
    qasm_code << "rz(" << params.delta << ") q;" << std::endl;
}

void QAsm::two_qubit_controlled(const ZYZParams &params) {

    // Matrix C
    qasm_code << "rz(" << (params.delta - params.gamma)/2 << ") q[1];" << std::endl;
    // First C-NOT
    qasm_code << "CNOT q[0], q[1]" << std::endl;
    // Matrix B
    qasm_code << "rz(" << -(params.delta + params.gamma)/2 << ") q[1];" << std::endl;
    qasm_code << "ry(" << -params.gamma/2 << ") q[1];" << std::endl;
    // Second C-NOT
    qasm_code << "CNOT q[0], q[1]" << std::endl;
    // Matrix A
    qasm_code << "ry(" << params.gamma/2 << ") q[1];" << std::endl;
    qasm_code << "rz(" << params.beta << ") q[1];" << std::endl;
    qasm_code << "phase(" << params.alpha << ") q[0];" << std::endl;

}

std::string QAsm::generate_qasm() {
    //qasm_code << "c = measure q;" << std::endl;
    return qasm_code.str();
}


