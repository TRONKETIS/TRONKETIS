#include "pch.h"
#include "MenuCapColla.h"
#include "GestioMembresForm.h"
#include "AssignarCastellsDiadaForm.h"
#include "IniciarSesionForm.h"
#include "CrearAssaigForm.h"
#include "CercadorColla.h"
#include "ConsultarCalendariForm.h"

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

System::Void MenuCapColla::btnCrearAssaig_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ collaUniName = "";
	CercadorColla::obtenirUniPerNomColla(this->collaName, collaUniName);

	CrearAssaigForm^ f = gcnew CrearAssaigForm(this->collaName, collaUniName); 
	f->ShowDialog();
}

System::Void MenuCapColla::btnCalendari_Click(System::Object^ sender, System::EventArgs^ e)
{
	ConsultarCalendariForm^ f = gcnew ConsultarCalendariForm("CapColla", this->collaName);
	f->ShowDialog();
}

System::Void MenuCapColla::btnAssignarCastellDiada_Click(System::Object^ sender, System::EventArgs^ e)
{
	AssignarCastellsDiadaForm^ f = gcnew AssignarCastellsDiadaForm(this->collaName);
	f->ShowDialog();
}

System::Void MenuCapColla::btnTancarSessio_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();

	IniciarSesionForm^ f = gcnew IniciarSesionForm();
	f->ShowDialog();

	this->Close();
}