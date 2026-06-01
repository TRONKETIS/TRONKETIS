#pragma once

#include "UiStyle.h"
#include "ConsultarCalendariForm.h"
#include "RegistrarAssistenciaForm.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuCastellerForm : public System::Windows::Forms::Form
	{
	public:
		MenuCastellerForm(String^ dniCasteller, String^ collaName)
		{
			this->dniCasteller = dniCasteller;
			this->collaName = collaName;
			InitializeComponent();
			this->lblDniValue->Text = dniCasteller;
			this->lblCollaValue->Text = collaName;
		}

	protected:
		~MenuCastellerForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ dniCasteller;
		String^ collaName;

		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblInfo;
		System::Windows::Forms::Label^ lblDniText;
		System::Windows::Forms::Label^ lblDniValue;
		System::Windows::Forms::Label^ lblCollaText;
		System::Windows::Forms::Label^ lblCollaValue;
		System::Windows::Forms::Label^ lblSeccionCalendari;
		System::Windows::Forms::Label^ lblSeccionAssistencia;
		System::Windows::Forms::Button^ btnCalendari;
		System::Windows::Forms::Button^ btnAssistencia;
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
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->lblDniText = (gcnew System::Windows::Forms::Label());
			this->lblDniValue = (gcnew System::Windows::Forms::Label());
			this->lblCollaText = (gcnew System::Windows::Forms::Label());
			this->lblCollaValue = (gcnew System::Windows::Forms::Label());
			this->lblSeccionCalendari = (gcnew System::Windows::Forms::Label());
			this->lblSeccionAssistencia = (gcnew System::Windows::Forms::Label());
			this->btnCalendari = (gcnew System::Windows::Forms::Button());
			this->btnAssistencia = (gcnew System::Windows::Forms::Button());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 680, 520, L"Menu Casteller");
			UiStyle::ApplyHeader(this->panelHeader, this->lblTitulo, this->lblSubtitulo, 680, L"Tronketis", L"Zona casteller");
			UiStyle::ApplyLogoutButton(this->btnTancarSessio);
			UiStyle::ApplyCard(this->panelContenido, 52, 125, 576, 330);

			this->btnTancarSessio->Location = System::Drawing::Point(526, 28);
			this->btnTancarSessio->Name = L"btnTancarSessio";
			this->btnTancarSessio->Size = System::Drawing::Size(120, 38);
			this->btnTancarSessio->TabIndex = 3;
			this->btnTancarSessio->Text = L"Cerrar sesion";
			this->btnTancarSessio->Click += gcnew System::EventHandler(this, &MenuCastellerForm::btnTancarSessio_Click);

			this->panelHeader->Controls->Add(this->btnTancarSessio);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelHeader->Controls->Add(this->lblTitulo);

			UiStyle::ApplyMessage(this->lblInfo, 500);
			this->lblInfo->Location = System::Drawing::Point(34, 28);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Text = L"Consulta el calendari de la teva colla i registra la teva assistencia a les diades.";

			UiStyle::ApplyLabel(this->lblDniText);
			this->lblDniText->Location = System::Drawing::Point(34, 78);
			this->lblDniText->Name = L"lblDniText";
			this->lblDniText->Text = L"DNI:";

			UiStyle::ApplyValueLabel(this->lblDniValue);
			this->lblDniValue->Location = System::Drawing::Point(92, 78);
			this->lblDniValue->Name = L"lblDniValue";
			this->lblDniValue->Text = L"dni";

			UiStyle::ApplyLabel(this->lblCollaText);
			this->lblCollaText->Location = System::Drawing::Point(34, 108);
			this->lblCollaText->Name = L"lblCollaText";
			this->lblCollaText->Text = L"Colla:";

			UiStyle::ApplyValueLabel(this->lblCollaValue);
			this->lblCollaValue->Location = System::Drawing::Point(92, 108);
			this->lblCollaValue->Name = L"lblCollaValue";
			this->lblCollaValue->Text = L"colla";

			UiStyle::ApplySection(this->lblSeccionCalendari);
			this->lblSeccionCalendari->Location = System::Drawing::Point(34, 158);
			this->lblSeccionCalendari->Name = L"lblSeccionCalendari";
			this->lblSeccionCalendari->Text = L"Calendari";

			UiStyle::ApplyButton(this->btnCalendari);
			this->btnCalendari->Location = System::Drawing::Point(34, 185);
			this->btnCalendari->Name = L"btnCalendari";
			this->btnCalendari->Size = System::Drawing::Size(508, 44);
			this->btnCalendari->TabIndex = 1;
			this->btnCalendari->Text = L"Consultar Calendari";
			this->btnCalendari->Click += gcnew System::EventHandler(this, &MenuCastellerForm::btnCalendari_Click);

			UiStyle::ApplySection(this->lblSeccionAssistencia);
			this->lblSeccionAssistencia->Location = System::Drawing::Point(34, 247);
			this->lblSeccionAssistencia->Name = L"lblSeccionAssistencia";
			this->lblSeccionAssistencia->Text = L"Assistencia";

			UiStyle::ApplyButton(this->btnAssistencia);
			this->btnAssistencia->Location = System::Drawing::Point(34, 274);
			this->btnAssistencia->Name = L"btnAssistencia";
			this->btnAssistencia->Size = System::Drawing::Size(508, 44);
			this->btnAssistencia->TabIndex = 2;
			this->btnAssistencia->Text = L"Registrar Assistencia";
			this->btnAssistencia->Click += gcnew System::EventHandler(this, &MenuCastellerForm::btnAssistencia_Click);

			this->panelContenido->Controls->Add(this->lblInfo);
			this->panelContenido->Controls->Add(this->lblDniText);
			this->panelContenido->Controls->Add(this->lblDniValue);
			this->panelContenido->Controls->Add(this->lblCollaText);
			this->panelContenido->Controls->Add(this->lblCollaValue);
			this->panelContenido->Controls->Add(this->lblSeccionCalendari);
			this->panelContenido->Controls->Add(this->btnCalendari);
			this->panelContenido->Controls->Add(this->lblSeccionAssistencia);
			this->panelContenido->Controls->Add(this->btnAssistencia);

			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelHeader);
			this->Name = L"MenuCastellerForm";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void btnCalendari_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ConsultarCalendariForm^ f = gcnew ConsultarCalendariForm("Casteller", this->collaName);
		f->ShowDialog();
	}

	private: System::Void btnAssistencia_Click(System::Object^ sender, System::EventArgs^ e)
	{
		RegistrarAssistenciaForm^ f = gcnew RegistrarAssistenciaForm(this->dniCasteller);
		f->ShowDialog();
	}

	private: System::Void btnTancarSessio_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	};
}
