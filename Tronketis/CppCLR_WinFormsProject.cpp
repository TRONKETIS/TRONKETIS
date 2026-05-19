/*#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "IniciarSesionForm.h"
//#include "RegistrarAssistenciaForm.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew Tronketis::IniciarSesionForm());
  return 0;
}
*/
#include "pch.h"
#include "Form1.h"
using namespace System::Windows::Forms;
[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew CppCLRWinFormsProject::Form1());
    return 0;
}