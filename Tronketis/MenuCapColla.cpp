#include "pch.h"
#include "MenuCapColla.h"
#include "GestioMembresForm.h"
#include "IniciarSesionForm.h"

using namespace Tronketis;

MenuCapColla::MenuCapColla(String^ collaName)
{
	InitializeComponent();
	this->collaName = collaName;
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
	GestioMembresForm^ f = gcnew GestioMembresForm(this->collaName);
	f->ShowDialog();
}

System::Void MenuCapColla::btnTancarSessio_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();

	IniciarSesionForm^ f = gcnew IniciarSesionForm();
	f->ShowDialog();

	this->Close();
}