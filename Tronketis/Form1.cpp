#include "pch.h"
#include "Form1.h"
#include "CercadorColla.h"

private: System::Void btnInhabilitar_Click(System::Object^ sender, System::EventArgs^ e) {

    int idColla = Convert::ToInt32(txtIdColla->Text);

    bool ok = CercadorColla::InhabilitarColla(idColla);

    if (ok) {
        lblResultado->Text = "Colla inhabilitada correctamente";
    } else {
        lblResultado->Text = "Error al inhabilitar la colla";
    }
    
}