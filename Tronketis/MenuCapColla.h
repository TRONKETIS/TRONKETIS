#pragma once

#include "UiStyle.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuCapColla : public System::Windows::Forms::Form
	{
	public:
		MenuCapColla(String^ collaName);

	protected:
		~MenuCapColla();

	private:
		String^ collaName;
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblCollaText;
		System::Windows::Forms::Label^ lblCollaName;
		System::Windows::Forms::Label^ lblSeccionMembres;
		System::Windows::Forms::Label^ lblSeccionCastells;
		System::Windows::Forms::Label^ lblSeccionAssaigs;
		System::Windows::Forms::Button^ btnGestioMembres;
		System::Windows::Forms::Button^ btnCrearCastell;
		System::Windows::Forms::Button^ btnAssignarPosicio;
		System::Windows::Forms::Button^ btnAssignarCastellDiada;
		System::Windows::Forms::Button^ btnCrearAssaig;
		System::Windows::Forms::Button^ btnConsultarAssaig;
		System::Windows::Forms::Button^ btnCalendari;
		System::Windows::Forms::Button^ btnTancarSessio;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->btnTancarSessio = (gcnew System::Windows::Forms::Button());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->lblCollaText = (gcnew System::Windows::Forms::Label());
			this->lblCollaName = (gcnew System::Windows::Forms::Label());
			this->lblSeccionMembres = (gcnew System::Windows::Forms::Label());
			this->lblSeccionCastells = (gcnew System::Windows::Forms::Label());
			this->lblSeccionAssaigs = (gcnew System::Windows::Forms::Label());
			this->btnGestioMembres = (gcnew System::Windows::Forms::Button());
			this->btnCrearCastell = (gcnew System::Windows::Forms::Button());
			this->btnAssignarPosicio = (gcnew System::Windows::Forms::Button());
			this->btnAssignarCastellDiada = (gcnew System::Windows::Forms::Button());
			this->btnCrearAssaig = (gcnew System::Windows::Forms::Button());
			this->btnConsultarAssaig = (gcnew System::Windows::Forms::Button());
			this->btnCalendari = (gcnew System::Windows::Forms::Button());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 760, 610, L"Menu Cap de Colla");
			UiStyle::ApplyHeader(this->panelHeader, this->lblTitulo, this->lblSubtitulo, 760, L"Tronketis", L"Gestio de membres, castells, assaigs i diades");
			UiStyle::ApplyLogoutButton(this->btnTancarSessio);
			UiStyle::ApplyCard(this->panelContenido, 50, 126, 660, 430);

			this->btnTancarSessio->Location = System::Drawing::Point(598, 28);
			this->btnTancarSessio->Name = L"btnTancarSessio";
			this->btnTancarSessio->Size = System::Drawing::Size(126, 38);
			this->btnTancarSessio->TabIndex = 8;
			this->btnTancarSessio->Text = L"Cerrar sesion";
			this->btnTancarSessio->Click += gcnew System::EventHandler(this, &MenuCapColla::btnTancarSessio_Click);

			this->panelHeader->Controls->Add(this->btnTancarSessio);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelHeader->Controls->Add(this->lblTitulo);

			UiStyle::ApplyLabel(this->lblCollaText);
			this->lblCollaText->Location = System::Drawing::Point(34, 30);
			this->lblCollaText->Name = L"lblCollaText";
			this->lblCollaText->Text = L"Colla:";

			UiStyle::ApplyValueLabel(this->lblCollaName);
			this->lblCollaName->Location = System::Drawing::Point(88, 30);
			this->lblCollaName->Name = L"lblCollaName";
			this->lblCollaName->Text = L"colla_name";

			UiStyle::ApplySection(this->lblSeccionMembres);
			this->lblSeccionMembres->Location = System::Drawing::Point(34, 76);
			this->lblSeccionMembres->Name = L"lblSeccionMembres";
			this->lblSeccionMembres->Text = L"Membres";

			UiStyle::ApplySection(this->lblSeccionCastells);
			this->lblSeccionCastells->Location = System::Drawing::Point(34, 148);
			this->lblSeccionCastells->Name = L"lblSeccionCastells";
			this->lblSeccionCastells->Text = L"Castells";

			UiStyle::ApplySection(this->lblSeccionAssaigs);
			this->lblSeccionAssaigs->Location = System::Drawing::Point(34, 286);
			this->lblSeccionAssaigs->Name = L"lblSeccionAssaigs";
			this->lblSeccionAssaigs->Text = L"Assaigs i calendari";

			UiStyle::ApplyButton(this->btnGestioMembres);
			this->btnGestioMembres->Location = System::Drawing::Point(34, 102);
			this->btnGestioMembres->Name = L"btnGestioMembres";
			this->btnGestioMembres->Size = System::Drawing::Size(590, 44);
			this->btnGestioMembres->TabIndex = 1;
			this->btnGestioMembres->Text = L"Gestio de Membres";
			this->btnGestioMembres->Click += gcnew System::EventHandler(this, &MenuCapColla::btnGestioMembres_Click);

			UiStyle::ApplyButton(this->btnCrearCastell);
			this->btnCrearCastell->Location = System::Drawing::Point(34, 174);
			this->btnCrearCastell->Name = L"btnCrearCastell";
			this->btnCrearCastell->Size = System::Drawing::Size(285, 44);
			this->btnCrearCastell->TabIndex = 2;
			this->btnCrearCastell->Text = L"Crear Castell";
			this->btnCrearCastell->Click += gcnew System::EventHandler(this, &MenuCapColla::btnCrearCastell_Click);

			UiStyle::ApplyButton(this->btnAssignarPosicio);
			this->btnAssignarPosicio->Location = System::Drawing::Point(339, 174);
			this->btnAssignarPosicio->Name = L"btnAssignarPosicio";
			this->btnAssignarPosicio->Size = System::Drawing::Size(285, 44);
			this->btnAssignarPosicio->TabIndex = 3;
			this->btnAssignarPosicio->Text = L"Assignar Posicio";
			this->btnAssignarPosicio->Click += gcnew System::EventHandler(this, &MenuCapColla::btnAssignarPosicio_Click);

			UiStyle::ApplyButton(this->btnAssignarCastellDiada);
			this->btnAssignarCastellDiada->Location = System::Drawing::Point(34, 226);
			this->btnAssignarCastellDiada->Name = L"btnAssignarCastellDiada";
			this->btnAssignarCastellDiada->Size = System::Drawing::Size(590, 44);
			this->btnAssignarCastellDiada->TabIndex = 4;
			this->btnAssignarCastellDiada->Text = L"Assignar Castell a Diada";
			this->btnAssignarCastellDiada->Click += gcnew System::EventHandler(this, &MenuCapColla::btnAssignarCastellDiada_Click);

			UiStyle::ApplyButton(this->btnCrearAssaig);
			this->btnCrearAssaig->Location = System::Drawing::Point(34, 312);
			this->btnCrearAssaig->Name = L"btnCrearAssaig";
			this->btnCrearAssaig->Size = System::Drawing::Size(285, 44);
			this->btnCrearAssaig->TabIndex = 5;
			this->btnCrearAssaig->Text = L"Crear Assaig";
			this->btnCrearAssaig->Click += gcnew System::EventHandler(this, &MenuCapColla::btnCrearAssaig_Click);

			UiStyle::ApplyButton(this->btnConsultarAssaig);
			this->btnConsultarAssaig->Location = System::Drawing::Point(339, 312);
			this->btnConsultarAssaig->Name = L"btnConsultarAssaig";
			this->btnConsultarAssaig->Size = System::Drawing::Size(285, 44);
			this->btnConsultarAssaig->TabIndex = 6;
			this->btnConsultarAssaig->Text = L"Consultar Assaigs";
			this->btnConsultarAssaig->Click += gcnew System::EventHandler(this, &MenuCapColla::btnConsultarAssaig_Click);

			UiStyle::ApplyButton(this->btnCalendari);
			this->btnCalendari->Location = System::Drawing::Point(34, 364);
			this->btnCalendari->Name = L"btnCalendari";
			this->btnCalendari->Size = System::Drawing::Size(590, 44);
			this->btnCalendari->TabIndex = 7;
			this->btnCalendari->Text = L"Consultar Calendari";
			this->btnCalendari->Click += gcnew System::EventHandler(this, &MenuCapColla::btnCalendari_Click);

			this->panelContenido->Controls->Add(this->lblCollaText);
			this->panelContenido->Controls->Add(this->lblCollaName);
			this->panelContenido->Controls->Add(this->lblSeccionMembres);
			this->panelContenido->Controls->Add(this->btnGestioMembres);
			this->panelContenido->Controls->Add(this->lblSeccionCastells);
			this->panelContenido->Controls->Add(this->btnCrearCastell);
			this->panelContenido->Controls->Add(this->btnAssignarPosicio);
			this->panelContenido->Controls->Add(this->btnAssignarCastellDiada);
			this->panelContenido->Controls->Add(this->lblSeccionAssaigs);
			this->panelContenido->Controls->Add(this->btnCrearAssaig);
			this->panelContenido->Controls->Add(this->btnConsultarAssaig);
			this->panelContenido->Controls->Add(this->btnCalendari);

			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelHeader);
			this->Name = L"MenuCapColla";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void btnGestioMembres_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCrearCastell_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnAssignarPosicio_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnAssignarCastellDiada_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCrearAssaig_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnConsultarAssaig_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCalendari_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnTancarSessio_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
