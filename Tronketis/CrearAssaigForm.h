#pragma once

#include "CtrlCrearAssaig.h"
#include "UiStyle.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CrearAssaigForm : public System::Windows::Forms::Form
	{
	public:
		CrearAssaigForm(String^ collaName, String^ collaUniName)
		{
			this->collaName = collaName;
			this->collaUniName = collaUniName;
			InitializeComponent();
			ConfigurarValidacions();
		}

	protected:
		~CrearAssaigForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ collaName;
		String^ collaUniName;
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::DateTimePicker^ dtpDataHora;
		System::Windows::Forms::Label^ lblTitol;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblDataHora;
		System::Windows::Forms::Button^ btnCrearAssaig;
		System::Windows::Forms::Button^ btnCancelar;
		System::Windows::Forms::Label^ lblMissatge;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->dtpDataHora = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblDataHora = (gcnew System::Windows::Forms::Label());
			this->btnCrearAssaig = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 560, 420, L"Crear Assaig");
			UiStyle::ApplyHeader(this->panelHeader, this->lblTitol, this->lblSubtitulo, 560, L"Crear Assaig", L"Indica data i hora de l'assaig");
			UiStyle::ApplyCard(this->panelContenido, 45, 122, 470, 245);

			UiStyle::ApplyLabel(this->lblDataHora);
			this->lblDataHora->Location = System::Drawing::Point(32, 52);
			this->lblDataHora->Name = L"lblDataHora";
			this->lblDataHora->Text = L"Data i hora:";

			this->dtpDataHora->CustomFormat = L"dd/MM/yyyy HH:mm";
			this->dtpDataHora->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtpDataHora->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			this->dtpDataHora->Location = System::Drawing::Point(150, 49);
			this->dtpDataHora->Name = L"dtpDataHora";
			this->dtpDataHora->Size = System::Drawing::Size(280, 25);
			this->dtpDataHora->TabIndex = 0;

			UiStyle::ApplyButton(this->btnCrearAssaig);
			this->btnCrearAssaig->Location = System::Drawing::Point(32, 112);
			this->btnCrearAssaig->Name = L"btnCrearAssaig";
			this->btnCrearAssaig->Size = System::Drawing::Size(195, 42);
			this->btnCrearAssaig->TabIndex = 1;
			this->btnCrearAssaig->Text = L"Crear Assaig";
			this->btnCrearAssaig->Click += gcnew System::EventHandler(this, &CrearAssaigForm::btnCrearAssaig_Click);

			UiStyle::ApplySecondaryButton(this->btnCancelar);
			this->btnCancelar->Location = System::Drawing::Point(235, 112);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(195, 42);
			this->btnCancelar->TabIndex = 2;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->Click += gcnew System::EventHandler(this, &CrearAssaigForm::btnCancelar_Click);

			UiStyle::ApplyMessage(this->lblMissatge, 400);
			this->lblMissatge->Location = System::Drawing::Point(32, 182);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Text = L"";

			this->panelHeader->Controls->Add(this->lblTitol);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelContenido->Controls->Add(this->lblDataHora);
			this->panelContenido->Controls->Add(this->dtpDataHora);
			this->panelContenido->Controls->Add(this->btnCrearAssaig);
			this->panelContenido->Controls->Add(this->btnCancelar);
			this->panelContenido->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->panelContenido);
			this->Name = L"CrearAssaigForm";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

		void ConfigurarValidacions()
		{
			// Evitar que el usuario pueda escoger fechas anteriores a hoy desde el componente
			dtpDataHora->MinDate = DateTime::Today;
		}

		System::Void btnCrearAssaig_Click(System::Object^ sender, System::EventArgs^ e) {

			DateTime selectedDate = dtpDataHora->Value;

			String^ resultat = CtrlCrearAssaig::CrearAssaig(selectedDate, collaName, collaUniName);

			if (resultat->StartsWith("Error"))
			{
				lblMissatge->ForeColor = System::Drawing::Color::Red;
				lblMissatge->Text = resultat;
			}
			else
			{
				lblMissatge->ForeColor = System::Drawing::Color::Green;
				lblMissatge->Text = resultat;
				MessageBox::Show(resultat, "Exit", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
		}

		System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
