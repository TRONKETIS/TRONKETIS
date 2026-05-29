#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

//#include "IniciarSesionForm.h"
//#include "RegistrarAssistenciaForm.h"
//#include "ConsultarCastellForm.h"
//#include "CrearCastellForm.h"
//#include "RegistrarAssistenciaForm.h"
//#include "RegistrarForm.h"
//#include "ModificarUsuariForm.h"
#include "AssignarCastellersForm.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew Tronketis::AssignarCastellersForm());
  return 0;
}
