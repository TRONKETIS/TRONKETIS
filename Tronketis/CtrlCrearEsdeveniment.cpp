#include "pch.h"
#include "Utils.h"
#include "CtrlCrearEsdeveniment.h"
#include "CercadoraEsdeveniment.h"
#include "PassarellaEsdeveniment.h"
#include <msclr\marshal_cppstd.h>

namespace Tronketis
{
    void CtrlCrearEsdeveniment::crearEsdeveniment(EsdevenimentDTO^ e)
    {
        //Nom no massa curt ni massa llarg
        if (e->name->Length == 0 || e->name->Length > 60) {
            throw gcnew ArgumentException("Nom incorrecte.");
        }

        //Data en format correcte i no anterior a l'actual
        std::string dataConvertida = msclr::interop::marshal_as<std::string>(e->date);
        if (!esDataValida(dataConvertida)) {
            throw gcnew ArgumentException("Data incorrecta.");
        }

        //Ubicació no massa curta ni massa llarga
        if (e->location->Length == 0 || e->location->Length > 100) {
            throw gcnew ArgumentException("Ubicació incorrecta.");
        }

        //Una diada que no existeix en la base de dades
        CercadoraEsdeveniment^ cercador = gcnew CercadoraEsdeveniment();

        if (cercador->existeixDiada(e->name, e->date)) {
            throw gcnew Exception("Ja existeix un esdeveniment amb aquest nom en aquesta mateixa data.");
        }

        PassarellaEsdeveniment::insertar(e);
    }
}