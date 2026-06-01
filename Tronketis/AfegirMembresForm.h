#pragma once

#include "CtrlGestioMembreColla.h"
#include "CercadorUsuari.h"
#include "UiStyle.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AfegirMembresForm : public System::Windows::Forms::Form
	{
	public:
		AfegirMembresForm(String^ collaName)
		{
			InitializeComponent();
			this->collaName = collaName;
			lblCollaActual->Text = L"Colla: " + collaName;
			CarregarCastellers();
		}

	protected:
		~AfegirMembresForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ collaName;

	private: System::Windows::Forms::Panel^ panelHeader;
	private: System::Windows::Forms::Panel^ panelContenido;
	private: System::Windows::Forms::Label^ lblTitol;
	private: System::Windows::Forms::Label^ lblSubtitulo;
	private: System::Windows::Forms::Label^ lblCollaActual;
	private: System::Windows::Forms::Label^ lblCasteller;
	private: System::Windows::Forms::ComboBox^ cmbCastellers;
	private: System::Windows::Forms::Button^ btnAfegir;
	private: System::Windows::Forms::Button^ btnTornar;
	private: System::Windows::Forms::Label^ lblMissatge;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblCollaActual = (gcnew System::Windows::Forms::Label());
			this->lblCasteller = (gcnew System::Windows::Forms::Label());
			this->cmbCastellers = (gcnew System::Windows::Forms::ComboBox());
			this->btnAfegir = (gcnew System::Windows::Forms::Button());
			this->btnTornar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 560, 440, L"Afegir Membre");
			UiStyle::ApplyHeader(this->panelHeader, this->lblTitol, this->lblSubtitulo, 560, L"Afegir Membre", L"Selecciona un casteller actiu");
			UiStyle::ApplyCard(this->panelContenido, 45, 122, 470, 270);

			UiStyle::ApplyValueLabel(this->lblCollaActual);
			this->lblCollaActual->Location = System::Drawing::Point(32, 26);
			this->lblCollaActual->Name = L"lblCollaActual";
			this->lblCollaActual->Text = L"Colla:";

			UiStyle::ApplyLabel(this->lblCasteller);
			this->lblCasteller->Location = System::Drawing::Point(32, 82);
			this->lblCasteller->Name = L"lblCasteller";
			this->lblCasteller->Text = L"Casteller:";

			UiStyle::ApplyCombo(this->cmbCastellers, 280);
			this->cmbCastellers->Location = System::Drawing::Point(150, 79);
			this->cmbCastellers->Name = L"cmbCastellers";
			this->cmbCastellers->TabIndex = 1;

			UiStyle::ApplyButton(this->btnAfegir);
			this->btnAfegir->Location = System::Drawing::Point(32, 140);
			this->btnAfegir->Name = L"btnAfegir";
			this->btnAfegir->Size = System::Drawing::Size(195, 42);
			this->btnAfegir->TabIndex = 2;
			this->btnAfegir->Text = L"Afegir";
			this->btnAfegir->Click += gcnew System::EventHandler(this, &AfegirMembresForm::btnAfegir_Click);

			UiStyle::ApplySecondaryButton(this->btnTornar);
			this->btnTornar->Location = System::Drawing::Point(235, 140);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(195, 42);
			this->btnTornar->TabIndex = 3;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->Click += gcnew System::EventHandler(this, &AfegirMembresForm::btnTornar_Click);

			UiStyle::ApplyMessage(this->lblMissatge, 400);
			this->lblMissatge->Location = System::Drawing::Point(32, 208);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Text = L"";

			this->panelHeader->Controls->Add(this->lblTitol);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelContenido->Controls->Add(this->lblCollaActual);
			this->panelContenido->Controls->Add(this->lblCasteller);
			this->panelContenido->Controls->Add(this->cmbCastellers);
			this->panelContenido->Controls->Add(this->btnAfegir);
			this->panelContenido->Controls->Add(this->btnTornar);
			this->panelContenido->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->panelContenido);
			this->Name = L"AfegirMembresForm";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		void CarregarCastellers()
		{
			cmbCastellers->Items->Clear();

			List<String^>^ castellers = CercadorUsuari::obtenirDnisCastellersActius();
			for each (String ^ dni in castellers) {
				cmbCastellers->Items->Add(dni);
			}
		}

	private: System::Void btnAfegir_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = "";

		if (cmbCastellers->SelectedItem != nullptr) {
			dni = cmbCastellers->SelectedItem->ToString();
		}

		String^ error = "";
		bool ok = CtrlGestioMembreColla::afegirMembre(dni, this->collaName, error);

		if (ok) {
			lblMissatge->ForeColor = Color::Green;
			lblMissatge->Text = L"Membre afegit correctament";
			cmbCastellers->SelectedIndex = -1;
		}
		else {
			lblMissatge->ForeColor = Color::Red;
			lblMissatge->Text = error;
		}
	}

	private: System::Void btnTornar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
