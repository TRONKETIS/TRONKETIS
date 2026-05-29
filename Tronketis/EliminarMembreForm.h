#pragma once

#include "CtrlGestioMembreColla.h"
#include "CercadorMembre.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class EliminarMembreForm : public System::Windows::Forms::Form
	{
	public:
		EliminarMembreForm(String^ collaName)
		{
			InitializeComponent();
			this->collaName = collaName;
			lblCollaActual->Text = L"Colla: " + collaName;
			CarregarMembres();
		}

	protected:
		~EliminarMembreForm()
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
	private: System::Windows::Forms::Label^ lblMembre;
	private: System::Windows::Forms::ComboBox^ cmbMembres;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnTornar;
	private: System::Windows::Forms::Label^ lblMissatge;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblCollaActual = (gcnew System::Windows::Forms::Label());
			this->lblMembre = (gcnew System::Windows::Forms::Label());
			this->cmbMembres = (gcnew System::Windows::Forms::ComboBox());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
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
			this->lblTitol->Size = System::Drawing::Size(256, 31);
			this->lblTitol->TabIndex = 0;
			this->lblTitol->Text = L"Eliminar Membres";
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
			// lblMembre
			// 
			this->lblMembre->AutoSize = true;
			this->lblMembre->Location = System::Drawing::Point(75, 145);
			this->lblMembre->Name = L"lblMembre";
			this->lblMembre->Size = System::Drawing::Size(56, 16);
			this->lblMembre->TabIndex = 2;
			this->lblMembre->Text = L"Membre";
			// 
			// cmbMembres
			// 
			this->cmbMembres->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbMembres->FormattingEnabled = true;
			this->cmbMembres->Location = System::Drawing::Point(170, 142);
			this->cmbMembres->Name = L"cmbMembres";
			this->cmbMembres->Size = System::Drawing::Size(180, 24);
			this->cmbMembres->TabIndex = 3;
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(100, 215);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(110, 32);
			this->btnEliminar->TabIndex = 4;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &EliminarMembreForm::btnEliminar_Click);
			// 
			// btnTornar
			// 
			this->btnTornar->Location = System::Drawing::Point(240, 215);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(110, 32);
			this->btnTornar->TabIndex = 5;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->UseVisualStyleBackColor = true;
			this->btnTornar->Click += gcnew System::EventHandler(this, &EliminarMembreForm::btnTornar_Click);
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
			// EliminarMembreForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(466, 380);
			this->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->btnTornar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->cmbMembres);
			this->Controls->Add(this->lblMembre);
			this->Controls->Add(this->lblCollaActual);
			this->Controls->Add(this->lblTitol);
			this->Name = L"EliminarMembreForm";
			this->Text = L"Eliminar Membre";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		void CarregarMembres()
		{
			cmbMembres->Items->Clear();

			List<String^>^ membres = CercadorMembre::obtenirDnisMembresPerColla(this->collaName);
			for each (String ^ dni in membres) {
				cmbMembres->Items->Add(dni);
			}
		}

	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = "";

		if (cmbMembres->SelectedItem != nullptr) {
			dni = cmbMembres->SelectedItem->ToString();
		}

		String^ error = "";
		bool ok = CtrlGestioMembreColla::eliminarMembre(dni, this->collaName, error);

		if (ok) {
			lblMissatge->ForeColor = Color::Green;
			lblMissatge->Text = L"Membre eliminat correctament";
			CarregarMembres();
			cmbMembres->SelectedIndex = -1;
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