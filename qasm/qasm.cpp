//
// Created by Elisson on 27/09/25.
//
#include <sstream>
#include "qasm.h"

std::string QAsm::generate_qasm() const {
    std::ostringstream oss;
    oss << "include \"stdgates.inc\";" << std::endl;

    oss << "qubit q;" << std::endl;

    for (const ZYZParams zyz_param : zyz_gates) {

        oss << "p(" << zyz_param.alpha << ") q;" << std::endl;
        oss << "rz( " << zyz_param.beta << ") q;" << std::endl;
        oss << "ry( " << zyz_param.gamma << ") q;" << std::endl;
        oss << "rz( " << zyz_param.delta << ") q;" << std::endl;

    }

    oss << "c = measure q;" << std::endl;

    return oss.str();
}
