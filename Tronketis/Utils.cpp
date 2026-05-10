#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include "Utils.h"

using namespace System;

namespace Tronketis {

    bool Utils::esDataValida(const std::string& data) {
        // 1. Comprovar la longitud exacta ("AAAA-MM-DD HH:MM" són 16 caràcters)
        if (data.length() != 16) {
            return false;
        }

        // 2. Comprovar que hi hagi guions a les posicions correctes
        if (data[4] != '-' || data[7] != '-' || data[10] != ' ' || data[13] != ':') {
            return false;
        }

        // 3. Comprovar que la resta de caràcters siguin números
        for (int i = 0; i < 16; ++i) {
            if (i == 4 || i == 7 || i == 10 || i == 13) continue; // Saltem els guions
            if (!isdigit(data[i])) {
                return false;
            }
        }

        // 4. Extreure els valors numèrics (Dia, Mes, Any)
        int any = std::stoi(data.substr(0, 4));
        int mes = std::stoi(data.substr(5, 2));
        int dia = std::stoi(data.substr(8, 2));
		int hora = std::stoi(data.substr(11, 2));
		int minut = std::stoi(data.substr(14, 2));

        // 5. Validar el mes (ha d'estar entre 1 i 12)
        if (mes < 1 || mes > 12) {
            return false;
        }

        // 6. Determinar si l'any és de traspàs (regla dels 4, 100 i 400 anys)
        bool esDeTraspas = (any % 4 == 0 && any % 100 != 0) || (any % 400 == 0);

        // 7. Definir els dies màxims que té cada mes
        // Índexs de l'array: 0=Gener, 1=Febrer, 2=Març...
        int diesPerMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Si és febrer i és any de traspàs, canviem els dies màxims a 29
        if (mes == 2 && esDeTraspas) {
            diesPerMes[1] = 29;
        }

        // 8. Validar el dia (ha d'estar entre 1 i el màxim permès pel seu mes i any)
        if (dia < 1 || dia > diesPerMes[mes - 1]) {
            return false;
        }

		// 9. Validar l'hora (ha d'estar entre 0 i 23) i els minuts (entre 0 i 59)
        if (hora < 0 || hora > 23) {
            return false;
        }

        if (minut < 0 || minut > 59) {
            return false;
		}

        //10. Validar que la data no sigui anterior a l'actual

        // Per això, primer obtenim la data actual
        time_t t = time(0);
        tm now;
        localtime_s(&now, &t);

        int anyActual = now.tm_year + 1900;
        int mesActual = now.tm_mon + 1;
        int diaActual = now.tm_mday;
        int horaActual = now.tm_hour;
        int minutActual = now.tm_min;

        // Comparem com a un sol número: AAAA*10^10 + MM*10^8 + ...
        long long dataInput = (long long)any * 100000000LL + mes * 1000000 + dia * 10000 + hora * 100 + minut;
        long long dataActual = (long long)anyActual * 100000000LL + mesActual * 1000000 + diaActual * 10000 + horaActual * 100 + minutActual;

        if (dataInput <= dataActual) {
            return false;
        }

        // Si passa totes les comprovacions, la data és perfectament vàlida
        return true;
    }
}