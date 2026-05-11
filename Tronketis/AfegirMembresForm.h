#pragma once

#include "CtrlGestioMembreColla.h"
#include "CercadorUsuari.h"
#include "CercadorColla.h"

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
		AfegirMembresForm(void)
		{
			InitializeComponent();
			CarregarCastellers();
			CarregarColles();
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
		System::Windows::Forms::Label^ lblTitol;
		System::Windows::Forms::Label^ lblDni;
		System::Windows::Forms::Label^ lblColla;
		System::Windows::Forms::ComboBox^ cmbDni;
		System::Windows::Forms::ComboBox^ cmbColla;
		System::Windows::Forms::Button^ btnAfegir;
		System::Windows::Forms::Button^ btnTornar;
		System::Windows::Forms::Label^ lblMissatge;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblDni = (gcnew System::Windows::Forms::Label());
			this->lblColla = (gcnew System::Windows::Forms::Label());
			this->cmbDni = (gcnew System::Windows::Forms::ComboBox());
			this->cmbColla = (gcnew System::Windows::Forms::ComboBox());
			this->btnAfegir = (gcnew System::Windows::Forms::Button());
			this->btnTornar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblTitol
			// 
			this->lblTitol->AutoSize = true;
			this->lblTitol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->lblTitol->Location = System::Drawing::Point(105, 35);
			this->lblTitol->Name = L"lblTitol";
			this->lblTitol->Size = System::Drawing::Size(310, 31);
			this->lblTitol->TabIndex = 0;
			this->lblTitol->Text = L"Afegir membres a la colla";
			// 
			// lblDni
			// 
			this->lblDni->AutoSize = true;
			this->lblDni->Location = System::Drawing::Point(95, 120);
			this->lblDni->Name = L"lblDni";
			this->lblDni->Size = System::Drawing::Size(97, 16);
			this->lblDni->TabIndex = 1;
			this->lblDni->Text = L"DNI casteller";
			// 
			// lblColla
			// 
			this->lblColla->AutoSize = true;
			this->lblColla->Location = System::Drawing::Point(95, 175);
			this->lblColla->Name = L"lblColla";
			this->lblColla->Size = System::Drawing::Size(37, 16);
			this->lblColla->TabIndex = 2;
			this->lblColla->Text = L"Colla";
			// 
			// cmbDni
			// 
			this->cmbDni->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDni->FormattingEnabled = true;
			this->cmbDni->Location = System::Drawing::Point(210, 117);
			this->cmbDni->Name = L"cmbDni";
			this->cmbDni->Size = System::Drawing::Size(180, 24);
			this->cmbDni->TabIndex = 3;
			// 
			// cmbColla
			// 
			this->cmbColla->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbColla->FormattingEnabled = true;
			this->cmbColla->Location = System::Drawing::Point(210, 172);
			this->cmbColla->Name = L"cmbColla";
			this->cmbColla->Size = System::Drawing::Size(180, 24);
			this->cmbColla->TabIndex = 4;
			// 
			// btnAfegir
			// 
			this->btnAfegir->Location = System::Drawing::Point(145, 255);
			this->btnAfegir->Name = L"btnAfegir";
			this->btnAfegir->Size = System::Drawing::Size(110, 32);
			this->btnAfegir->TabIndex = 5;
			this->btnAfegir->Text = L"Afegir membre";
			this->btnAfegir->UseVisualStyleBackColor = true;
			this->btnAfegir->Click += gcnew System::EventHandler(this, &AfegirMembresForm::btnAfegir_Click);
			// 
			// btnTornar
			// 
			this->btnTornar->Location = System::Drawing::Point(280, 255);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(110, 32);
			this->btnTornar->TabIndex = 6;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->UseVisualStyleBackColor = true;
			this->btnTornar->Click += gcnew System::EventHandler(this, &AfegirMembresForm::btnTornar_Click);
			// 
			// lblMissatge
			// 
			this->lblMissatge->AutoSize = true;
			this->lblMissatge->Location = System::Drawing::Point(95, 320);
			this->lblMissatge->MaximumSize = System::Drawing::Size(320, 0);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Size = System::Drawing::Size(0, 16);
			this->lblMissatge->TabIndex = 7;
			// 
			// AfegirMembresForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 420);
			this->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->btnTornar);
			this->Controls->Add(this->btnAfegir);
			this->Controls->Add(this->cmbColla);
			this->Controls->Add(this->cmbDni);
			this->Controls->Add(this->lblColla);
			this->Controls->Add(this->lblDni);
			this->Controls->Add(this->lblTitol);
			this->Name = L"AfegirMembresForm";
			this->Text = L"Afegir membres";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		void CarregarCastellers()
		{
			cmbDni->Items->Clear();

			List<String^>^ castellers = CercadorUsuari::obtenirDnisCastellersActius();
			for each (String ^ dni in castellers) {
				cmbDni->Items->Add(dni);
			}
		}

		void CarregarColles()
		{
			cmbColla->Items->Clear();

			List<String^>^ colles = CercadorColla::obtenirNomsColles();
			for each (String ^ nom in colles) {
				cmbColla->Items->Add(nom);
			}
		}

	private: System::Void btnAfegir_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = "";
		String^ collaName = "";

		if (cmbDni->SelectedItem != nullptr) {
			dni = cmbDni->SelectedItem->ToString();
		}

		if (cmbColla->SelectedItem != nullptr) {
			collaName = cmbColla->SelectedItem->ToString();
		}

		String^ error = "";
		bool ok = CtrlGestioMembreColla::afegirMembre(dni, collaName, error);

		if (ok) {
			lblMissatge->ForeColor = Color::Green;
			lblMissatge->Text = L"Membre afegit correctament";
			cmbDni->SelectedIndex = -1;
			cmbColla->SelectedIndex = -1;
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