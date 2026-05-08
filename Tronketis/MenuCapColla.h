#pragma once
#include "GestioMembresForm.h"

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
		MenuCapColla(void)
		{
			InitializeComponent();
		}

	protected:
		~MenuCapColla()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblTitol;
	private: System::Windows::Forms::Button^ btnGestionarMembres;
	private: System::Windows::Forms::Button^ btnEditarColla;
	private: System::Windows::Forms::Button^ btnConsultarColla;
	private: System::Windows::Forms::Button^ btnCrearEstructura;
	private: System::Windows::Forms::Button^ btnAssignarPosicions;
	private: System::Windows::Forms::Button^ btnConsultarCastell;
	private: System::Windows::Forms::Button^ btnTancarSessio;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->btnGestionarMembres = (gcnew System::Windows::Forms::Button());
			this->btnEditarColla = (gcnew System::Windows::Forms::Button());
			this->btnConsultarColla = (gcnew System::Windows::Forms::Button());
			this->btnCrearEstructura = (gcnew System::Windows::Forms::Button());
			this->btnAssignarPosicions = (gcnew System::Windows::Forms::Button());
			this->btnConsultarCastell = (gcnew System::Windows::Forms::Button());
			this->btnTancarSessio = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTitol
			// 
			this->lblTitol->AutoSize = true;
			this->lblTitol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->lblTitol->Location = System::Drawing::Point(145, 35);
			this->lblTitol->Name = L"lblTitol";
			this->lblTitol->Size = System::Drawing::Size(251, 31);
			this->lblTitol->TabIndex = 0;
			this->lblTitol->Text = L"Menú Cap de Colla";
			// 
			// btnGestionarMembres
			// 
			this->btnGestionarMembres->Location = System::Drawing::Point(170, 95);
			this->btnGestionarMembres->Name = L"btnGestionarMembres";
			this->btnGestionarMembres->Size = System::Drawing::Size(200, 30);
			this->btnGestionarMembres->TabIndex = 1;
			this->btnGestionarMembres->Text = L"Gestionar membres";
			this->btnGestionarMembres->UseVisualStyleBackColor = true;
			this->btnGestionarMembres->Click += gcnew System::EventHandler(this, &MenuCapColla::btnGestionarMembres_Click);
			// 
			// btnEditarColla
			// 
			this->btnEditarColla->Location = System::Drawing::Point(170, 140);
			this->btnEditarColla->Name = L"btnEditarColla";
			this->btnEditarColla->Size = System::Drawing::Size(200, 30);
			this->btnEditarColla->TabIndex = 2;
			this->btnEditarColla->Text = L"Editar colla";
			this->btnEditarColla->UseVisualStyleBackColor = true;
			this->btnEditarColla->Click += gcnew System::EventHandler(this, &MenuCapColla::btnEditarColla_Click);
			// 
			// btnConsultarColla
			// 
			this->btnConsultarColla->Location = System::Drawing::Point(170, 185);
			this->btnConsultarColla->Name = L"btnConsultarColla";
			this->btnConsultarColla->Size = System::Drawing::Size(200, 30);
			this->btnConsultarColla->TabIndex = 3;
			this->btnConsultarColla->Text = L"Consultar colla";
			this->btnConsultarColla->UseVisualStyleBackColor = true;
			this->btnConsultarColla->Click += gcnew System::EventHandler(this, &MenuCapColla::btnConsultarColla_Click);
			// 
			// btnCrearEstructura
			// 
			this->btnCrearEstructura->Location = System::Drawing::Point(170, 230);
			this->btnCrearEstructura->Name = L"btnCrearEstructura";
			this->btnCrearEstructura->Size = System::Drawing::Size(200, 30);
			this->btnCrearEstructura->TabIndex = 4;
			this->btnCrearEstructura->Text = L"Crear estructura de castell";
			this->btnCrearEstructura->UseVisualStyleBackColor = true;
			this->btnCrearEstructura->Click += gcnew System::EventHandler(this, &MenuCapColla::btnCrearEstructura_Click);
			// 
			// btnAssignarPosicions
			// 
			this->btnAssignarPosicions->Location = System::Drawing::Point(170, 275);
			this->btnAssignarPosicions->Name = L"btnAssignarPosicions";
			this->btnAssignarPosicions->Size = System::Drawing::Size(200, 30);
			this->btnAssignarPosicions->TabIndex = 5;
			this->btnAssignarPosicions->Text = L"Assignar castellers a posicions";
			this->btnAssignarPosicions->UseVisualStyleBackColor = true;
			this->btnAssignarPosicions->Click += gcnew System::EventHandler(this, &MenuCapColla::btnAssignarPosicions_Click);
			// 
			// btnConsultarCastell
			// 
			this->btnConsultarCastell->Location = System::Drawing::Point(170, 320);
			this->btnConsultarCastell->Name = L"btnConsultarCastell";
			this->btnConsultarCastell->Size = System::Drawing::Size(200, 30);
			this->btnConsultarCastell->TabIndex = 6;
			this->btnConsultarCastell->Text = L"Consultar castell";
			this->btnConsultarCastell->UseVisualStyleBackColor = true;
			this->btnConsultarCastell->Click += gcnew System::EventHandler(this, &MenuCapColla::btnConsultarCastell_Click);
			// 
			// btnTancarSessio
			// 
			this->btnTancarSessio->Location = System::Drawing::Point(170, 380);
			this->btnTancarSessio->Name = L"btnTancarSessio";
			this->btnTancarSessio->Size = System::Drawing::Size(200, 30);
			this->btnTancarSessio->TabIndex = 7;
			this->btnTancarSessio->Text = L"Tancar sessió";
			this->btnTancarSessio->UseVisualStyleBackColor = true;
			this->btnTancarSessio->Click += gcnew System::EventHandler(this, &MenuCapColla::btnTancarSessio_Click);
			// 
			// MenuCapColla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(547, 470);
			this->Controls->Add(this->btnTancarSessio);
			this->Controls->Add(this->btnConsultarCastell);
			this->Controls->Add(this->btnAssignarPosicions);
			this->Controls->Add(this->btnCrearEstructura);
			this->Controls->Add(this->btnConsultarColla);
			this->Controls->Add(this->btnEditarColla);
			this->Controls->Add(this->btnGestionarMembres);
			this->Controls->Add(this->lblTitol);
			this->Name = L"MenuCapColla";
			this->Text = L"Menu Cap de Colla";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void btnGestionarMembres_Click(System::Object^ sender, System::EventArgs^ e) {
		GestioMembresForm^ f = gcnew GestioMembresForm();
		f->ShowDialog();
	}

	private: System::Void btnEditarColla_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Pantalla d'editar colla pendent");
	}

	private: System::Void btnConsultarColla_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Pantalla de consultar colla pendent");
	}

	private: System::Void btnCrearEstructura_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Pantalla de crear estructura pendent");
	}

	private: System::Void btnAssignarPosicions_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Pantalla d'assignar posicions pendent");
	}

	private: System::Void btnConsultarCastell_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Pantalla de consultar castell pendent");
	}

	private: System::Void btnTancarSessio_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}