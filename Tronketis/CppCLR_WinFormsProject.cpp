#include "pch.h"
#include "ConsultarCollaForm.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "IniciarSesionForm.h"
//#include "RegistrarAssistenciaForm.h"
//#include "ConsultarCastellForm.h"
//#include "CrearCastellForm.h"
#include "RegistrarAssistenciaForm.h"
#include "RegistrarForm.h"
#include "ModificarUsuariForm.h"
#include "MenuCapColla.h"
#include "EditarCollaForm.h"
 
#include "MenuCapColla.h"

using namespace System;
#include "AssignarCastellsDiadaForm.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew Tronketis::EditarCollaForm(1));
  return 0;
}
