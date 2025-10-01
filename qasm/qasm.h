//
// Created by Elisson on 27/09/25.
//

#ifndef QQCOMPILER_QASM_H
#define QQCOMPILER_QASM_H
#include <string>
#include <vector>

struct ZYZParams {
    double alpha;
    double beta;
    double gamma;
    double delta;
};

class QAsm {
    public:
        QAsm(const int number_qbits, const std::vector<ZYZParams>& zyz_params) {
            n_qbits = number_qbits;
            zyz_gates = zyz_params;
        }
        ~QAsm() = default;
        [[nodiscard]] std::string generate_qasm() const;
    private:
        int n_qbits;
        std::vector<ZYZParams> zyz_gates;
};

#endif //QQCOMPILER_QASM_H