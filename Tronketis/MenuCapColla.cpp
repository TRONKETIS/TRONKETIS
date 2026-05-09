#include "pch.h"
#include "MenuCapColla.h"
#include "GestioMembresForm.h"
#include "IniciarSesionForm.h"

using namespace Tronketis;

MenuCapColla::MenuCapColla(void)
{
	InitializeComponent();
}

MenuCapColla::~MenuCapColla()
{
	if (components)
	{
		delete components;
	}
}

System::Void MenuCapColla::btnGestioMembres_Click(System::Object^ sender, System::EventArgs^ e)
{
	GestioMembresForm^ f = gcnew GestioMembresForm();
	f->ShowDialog();
}

System::Void MenuCapColla::btnTancarSessio_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();

	IniciarSesionForm^ f = gcnew IniciarSesionForm();
	f->ShowDialog();

	this->Close();
}