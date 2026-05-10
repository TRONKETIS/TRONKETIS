#include "pch.h"

#include "CtrlRegistrarAssistencia.h"
#include "PasarelaParticipacioDiada.h"

namespace Tronketis {

    bool CtrlRegistrarAssistencia::executar(
        ParticipacioDiadaDTO^ dto,
        String^% error
    )
    {
        if (String::IsNullOrWhiteSpace(dto->dni))
        {
            error = "DNI buit";
            return false;
        }

        if (String::IsNullOrWhiteSpace(dto->diadaName))
        {
            error = "Diada buida";
            return false;
        }

        if (String::IsNullOrWhiteSpace(dto->estat))
        {
            error = "Estat buit";
            return false;
        }

        bool existeix =
            PasarelaParticipacioDiada::existeix(
                dto->diadaName,
                dto->dateDiada,
                dto->dni
            );

        if (existeix)
        {
            return
                PasarelaParticipacioDiada::actualitzarEstat(
                    dto,
                    error
                );
        }

        return
            PasarelaParticipacioDiada::registrar(
                dto,
                error
            );
    }

}
