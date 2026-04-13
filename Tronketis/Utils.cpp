#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include "Utils.h"

using namespace System;

namespace Tronketis {

    bool esDataValida(const std::string& data) {
        // 1. Comprovar la longitud exacta ("DD-MM-AAAA" són 10 caràcters)
        if (data.length() != 10) {
            return false;
        }

        // 2. Comprovar que hi hagi guions a les posicions correctes
        if (data[2] != '-' || data[5] != '-') {
            return false;
        }

        // 3. Comprovar que la resta de caràcters siguin números
        for (int i = 0; i < 10; ++i) {
            if (i == 2 || i == 5) continue; // Saltem els guions
            if (!isdigit(data[i])) {
                return false;
            }
        }

        // 4. Extreure els valors numèrics (Dia, Mes, Any)
        int dia = std::stoi(data.substr(0, 2));
        int mes = std::stoi(data.substr(3, 2));
        int any = std::stoi(data.substr(6, 4));

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

        //9. Validar que la data no sigui anterior a l'actual

        // Per això, primer obtenim la data actual
        time_t t = time(0);
        tm now;

        localtime_s(&now, &t);

        int anyActual = now->tm_year + 1900; // tm_year és anys des de 1900
        int mesActual = now->tm_mon + 1;    // tm_mon és mesos des de gener (0-11)
        int diaActual = now->tm_mday;       // tm_mday és el dia del mes (1-31)

        // Comprovem si l'any de la data és menor que l'any actual
        if (any < anyActual) {
            return false;
        }

        // Si l'any és igual, comprovem el mes
        if (any == anyActual && mes < mesActual) {
            return false;
        }

        // Si l'any i el mes són iguals, comprovem el dia
        if (any == anyActual && mes == mesActual && dia < diaActual) {
            return false;
        }

        // Si passa totes les comprovacions, la data és perfectament vàlida
        return true;
    }
}