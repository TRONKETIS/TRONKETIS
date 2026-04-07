#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

//#include "IniciarSesionForm.h"
#include "RegistrarForm.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew Tronketis::RegistrarForm());
  return 0;
}