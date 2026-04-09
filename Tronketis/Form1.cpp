#include "pch.h"
#include "Form1.h"
#include "CercadorUsuari.h"

System::Void Form1::btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ username = txtUsername->Text;

    String^ id;
    String^ password;
    String^ rol;

    if (CercadorUsuari::CercaPerUsername(username, id, password))
    {
        lblResultado->Text = "ID: " + id + " | Password: " + password+ " | Rol: " + rol;
    }
    else
    {
        lblResultado->Text = "Usuario no encontrado";
    }
    
}

