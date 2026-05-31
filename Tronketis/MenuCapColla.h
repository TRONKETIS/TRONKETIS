#pragma once

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
		System::Windows::Forms::Label^ lblTitol;
		System::Windows::Forms::Button^ btnGestioMembres;
		System::Windows::Forms::Button^ btnCalendari;
		System::Windows::Forms::Button^ btnAssignarCastellDiada;
		System::Windows::Forms::Button^ btnTancarSessio;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->btnGestioMembres = (gcnew System::Windows::Forms::Button());
			this->btnAssignarCastellDiada = (gcnew System::Windows::Forms::Button());
			this->btnCalendari = (gcnew System::Windows::Forms::Button());
			this->btnTancarSessio = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTitol
			// 
			this->lblTitol->AutoSize = true;
			this->lblTitol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->lblTitol->Location = System::Drawing::Point(135, 55);
			this->lblTitol->Name = L"lblTitol";
			this->lblTitol->Size = System::Drawing::Size(251, 31);
			this->lblTitol->TabIndex = 0;
			this->lblTitol->Text = L"Menu Cap de Colla";
			// 
			// btnGestioMembres
			// 
			this->btnGestioMembres->Location = System::Drawing::Point(170, 140);
			this->btnGestioMembres->Name = L"btnGestioMembres";
			this->btnGestioMembres->Size = System::Drawing::Size(180, 35);
			this->btnGestioMembres->TabIndex = 1;
			this->btnGestioMembres->Text = L"Gestio membres";
			this->btnGestioMembres->UseVisualStyleBackColor = true;
			this->btnGestioMembres->Click += gcnew System::EventHandler(this, &MenuCapColla::btnGestioMembres_Click);
			// 
			// btnAssignarCastellDiada
			// 
			this->btnAssignarCastellDiada->Location = System::Drawing::Point(170, 200);
			this->btnAssignarCastellDiada->Name = L"btnAssignarCastellDiada";
			this->btnAssignarCastellDiada->Size = System::Drawing::Size(180, 35);
			this->btnAssignarCastellDiada->TabIndex = 2;
			this->btnAssignarCastellDiada->Text = L"Assignar castell a diada";
			this->btnAssignarCastellDiada->UseVisualStyleBackColor = true;
			this->btnAssignarCastellDiada->Click += gcnew System::EventHandler(this, &MenuCapColla::btnAssignarCastellDiada_Click);
			// 
			// btnCalendari
			// 
			this->btnCalendari->Location = System::Drawing::Point(170, 220);
			this->btnCalendari->Name = L"btnCalendari";
			this->btnCalendari->Size = System::Drawing::Size(180, 35);
			this->btnCalendari->TabIndex = 2;
			this->btnCalendari->Text = L"Consultar Calendari";
			this->btnCalendari->UseVisualStyleBackColor = true;
			this->btnCalendari->Click += gcnew System::EventHandler(this, &MenuCapColla::btnCalendari_Click);
			// 
			// btnTancarSessio
			// 
			this->btnTancarSessio->Location = System::Drawing::Point(170, 260);
			this->btnTancarSessio->Name = L"btnTancarSessio";
			this->btnTancarSessio->Size = System::Drawing::Size(180, 35);
			this->btnTancarSessio->TabIndex = 3;
			this->btnTancarSessio->Text = L"Tancar sessio";
			this->btnTancarSessio->UseVisualStyleBackColor = true;
			this->btnTancarSessio->Click += gcnew System::EventHandler(this, &MenuCapColla::btnTancarSessio_Click);
			// 
			// MenuCapColla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(547, 470);
			this->Controls->Add(this->btnTancarSessio);
			this->Controls->Add(this->btnCalendari);
			this->Controls->Add(this->btnAssignarCastellDiada);
			this->Controls->Add(this->btnGestioMembres);
			this->Controls->Add(this->lblTitol);
			this->Name = L"MenuCapColla";
			this->Text = L"Menu Cap de Colla";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void btnGestioMembres_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnAssignarCastellDiada_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnTancarSessio_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCalendari_Click(System::Object^ sender, System::EventArgs^ e);
	};
}