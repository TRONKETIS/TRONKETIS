#pragma once

#include "CtrlGestioMembreColla.h"
#include "CercadorUsuari.h"

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

	private: System::Windows::Forms::Label^ lblTitol;
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
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblCollaActual = (gcnew System::Windows::Forms::Label());
			this->lblCasteller = (gcnew System::Windows::Forms::Label());
			this->cmbCastellers = (gcnew System::Windows::Forms::ComboBox());
			this->btnAfegir = (gcnew System::Windows::Forms::Button());
			this->btnTornar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblTitol
			// 
			this->lblTitol->AutoSize = true;
			this->lblTitol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->lblTitol->Location = System::Drawing::Point(110, 35);
			this->lblTitol->Name = L"lblTitol";
			this->lblTitol->Size = System::Drawing::Size(239, 31);
			this->lblTitol->TabIndex = 0;
			this->lblTitol->Text = L"Afegir Membres";
			// 
			// lblCollaActual
			// 
			this->lblCollaActual->AutoSize = true;
			this->lblCollaActual->Location = System::Drawing::Point(75, 90);
			this->lblCollaActual->Name = L"lblCollaActual";
			this->lblCollaActual->Size = System::Drawing::Size(42, 16);
			this->lblCollaActual->TabIndex = 1;
			this->lblCollaActual->Text = L"Colla:";
			// 
			// lblCasteller
			// 
			this->lblCasteller->AutoSize = true;
			this->lblCasteller->Location = System::Drawing::Point(75, 145);
			this->lblCasteller->Name = L"lblCasteller";
			this->lblCasteller->Size = System::Drawing::Size(57, 16);
			this->lblCasteller->TabIndex = 2;
			this->lblCasteller->Text = L"Casteller";
			// 
			// cmbCastellers
			// 
			this->cmbCastellers->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCastellers->FormattingEnabled = true;
			this->cmbCastellers->Location = System::Drawing::Point(170, 142);
			this->cmbCastellers->Name = L"cmbCastellers";
			this->cmbCastellers->Size = System::Drawing::Size(180, 24);
			this->cmbCastellers->TabIndex = 3;
			// 
			// btnAfegir
			// 
			this->btnAfegir->Location = System::Drawing::Point(100, 215);
			this->btnAfegir->Name = L"btnAfegir";
			this->btnAfegir->Size = System::Drawing::Size(110, 32);
			this->btnAfegir->TabIndex = 4;
			this->btnAfegir->Text = L"Afegir";
			this->btnAfegir->UseVisualStyleBackColor = true;
			this->btnAfegir->Click += gcnew System::EventHandler(this, &AfegirMembresForm::btnAfegir_Click);
			// 
			// btnTornar
			// 
			this->btnTornar->Location = System::Drawing::Point(240, 215);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(110, 32);
			this->btnTornar->TabIndex = 5;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->UseVisualStyleBackColor = true;
			this->btnTornar->Click += gcnew System::EventHandler(this, &AfegirMembresForm::btnTornar_Click);
			// 
			// lblMissatge
			// 
			this->lblMissatge->AutoSize = true;
			this->lblMissatge->Location = System::Drawing::Point(75, 285);
			this->lblMissatge->MaximumSize = System::Drawing::Size(320, 0);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Size = System::Drawing::Size(0, 16);
			this->lblMissatge->TabIndex = 6;
			// 
			// AfegirMembresForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(466, 380);
			this->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->btnTornar);
			this->Controls->Add(this->btnAfegir);
			this->Controls->Add(this->cmbCastellers);
			this->Controls->Add(this->lblCasteller);
			this->Controls->Add(this->lblCollaActual);
			this->Controls->Add(this->lblTitol);
			this->Name = L"AfegirMembresForm";
			this->Text = L"Afegir Membres";
			this->ResumeLayout(false);
			this->PerformLayout();

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