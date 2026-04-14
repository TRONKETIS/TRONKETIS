#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Tronketis {

    class Utils {
    public:
        // Declaració de la funció d'utilitat com a estàtica
        static bool esDataValida(const std::string& data);
    };

}

#endif