#pragma once

#include "CtrlAfegirMembreColla.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GestionMembresForm : public System::Windows::Forms::Form
	{
	public:
		GestionMembresForm(void)
		{
			InitializeComponent();
		}

	protected:
		~GestionMembresForm()
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
		System::Windows::Forms::Label^ lblUni;
		System::Windows::Forms::TextBox^ txtDni;
		System::Windows::Forms::TextBox^ txtColla;
		System::Windows::Forms::TextBox^ txtUni;
		System::Windows::Forms::Button^ btnAfegir;
		System::Windows::Forms::Button^ btnVolver;
		System::Windows::Forms::Label^ lblMissatge;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblDni = (gcnew System::Windows::Forms::Label());
			this->lblColla = (gcnew System::Windows::Forms::Label());
			this->lblUni = (gcnew System::Windows::Forms::Label());
			this->txtDni = (gcnew System::Windows::Forms::TextBox());
			this->txtColla = (gcnew System::Windows::Forms::TextBox());
			this->txtUni = (gcnew System::Windows::Forms::TextBox());
			this->btnAfegir = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
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
			this->lblTitol->Text = L"Gestió de membres colla";
			// 
			// lblDni
			// 
			this->lblDni->AutoSize = true;
			this->lblDni->Location = System::Drawing::Point(95, 110);
			this->lblDni->Name = L"lblDni";
			this->lblDni->Size = System::Drawing::Size(28, 16);
			this->lblDni->TabIndex = 1;
			this->lblDni->Text = L"DNI";
			// 
			// lblColla
			// 
			this->lblColla->AutoSize = true;
			this->lblColla->Location = System::Drawing::Point(95, 155);
			this->lblColla->Name = L"lblColla";
			this->lblColla->Size = System::Drawing::Size(37, 16);
			this->lblColla->TabIndex = 2;
			this->lblColla->Text = L"Colla";
			// 
			// lblUni
			// 
			this->lblUni->AutoSize = true;
			this->lblUni->Location = System::Drawing::Point(95, 200);
			this->lblUni->Name = L"lblUni";
			this->lblUni->Size = System::Drawing::Size(73, 16);
			this->lblUni->TabIndex = 3;
			this->lblUni->Text = L"Universitat";
			// 
			// txtDni
			// 
			this->txtDni->Location = System::Drawing::Point(210, 107);
			this->txtDni->Name = L"txtDni";
			this->txtDni->Size = System::Drawing::Size(180, 22);
			this->txtDni->TabIndex = 4;
			// 
			// txtColla
			// 
			this->txtColla->Location = System::Drawing::Point(210, 152);
			this->txtColla->Name = L"txtColla";
			this->txtColla->Size = System::Drawing::Size(180, 22);
			this->txtColla->TabIndex = 5;
			// 
			// txtUni
			// 
			this->txtUni->Location = System::Drawing::Point(210, 197);
			this->txtUni->Name = L"txtUni";
			this->txtUni->Size = System::Drawing::Size(180, 22);
			this->txtUni->TabIndex = 6;
			// 
			// btnAfegir
			// 
			this->btnAfegir->Location = System::Drawing::Point(145, 265);
			this->btnAfegir->Name = L"btnAfegir";
			this->btnAfegir->Size = System::Drawing::Size(110, 32);
			this->btnAfegir->TabIndex = 7;
			this->btnAfegir->Text = L"Afegir membre";
			this->btnAfegir->UseVisualStyleBackColor = true;
			this->btnAfegir->Click += gcnew System::EventHandler(this, &GestionMembresForm::btnAfegir_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(280, 265);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(110, 32);
			this->btnVolver->TabIndex = 8;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &GestionMembresForm::btnVolver_Click);
			// 
			// lblMissatge
			// 
			this->lblMissatge->AutoSize = true;
			this->lblMissatge->Location = System::Drawing::Point(95, 330);
			this->lblMissatge->MaximumSize = System::Drawing::Size(320, 0);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Size = System::Drawing::Size(0, 16);
			this->lblMissatge->TabIndex = 9;
			// 
			// GestionMembresForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 420);
			this->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->btnAfegir);
			this->Controls->Add(this->txtUni);
			this->Controls->Add(this->txtColla);
			this->Controls->Add(this->txtDni);
			this->Controls->Add(this->lblUni);
			this->Controls->Add(this->lblColla);
			this->Controls->Add(this->lblDni);
			this->Controls->Add(this->lblTitol);
			this->Name = L"GestionMembresForm";
			this->Text = L"Gestió de membres";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void btnAfegir_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = txtDni->Text->Trim();
		String^ collaName = txtColla->Text->Trim();
		String^ uniName = txtUni->Text->Trim();

		String^ error = "";
		bool ok = CtrlAfegirMembreColla::afegirMembre(dni, collaName, uniName, error);

		if (ok) {
			lblMissatge->ForeColor = Color::Green;
			lblMissatge->Text = L"Membre afegit correctament";
			txtDni->Clear();
		}
		else {
			lblMissatge->ForeColor = Color::Red;
			lblMissatge->Text = error;
		}
	}

	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}