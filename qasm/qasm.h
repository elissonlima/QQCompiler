//
// Created by Elisson on 27/09/25.
//

#ifndef QQCOMPILER_QASM_H
#define QQCOMPILER_QASM_H
#include <string>
#include <vector>

#include "../unitary/unitary.h"


class QAsm {
    public:
        QAsm() {
            qasm_code << "include \"stdgates.inc\";" << std::endl;
        };
        ~QAsm() = default;
        void define_qubits(int n_qubits);
        void single_qubit_port(const ZYZParams &params);
        void two_qubit_controlled(const ZYZParams &params);
        [[nodiscard]] std::string generate_qasm();
    private:
       std::ostringstream qasm_code;
};

#endif //QQCOMPILER_QASM_H