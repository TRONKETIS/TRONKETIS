#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }
//#include "CrearCollaForm.h"
//#include "RegistrarForm.h"
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