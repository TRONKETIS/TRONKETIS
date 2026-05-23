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
		System::Windows::Forms::Button^ btnCrearAssaig;
		System::Windows::Forms::Button^ btnTancarSessio;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->btnGestioMembres = (gcnew System::Windows::Forms::Button());
			this->btnCrearAssaig = (gcnew System::Windows::Forms::Button());
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
			this->btnGestioMembres->Location = System::Drawing::Point(170, 150);
			this->btnGestioMembres->Name = L"btnGestioMembres";
			this->btnGestioMembres->Size = System::Drawing::Size(180, 35);
			this->btnGestioMembres->TabIndex = 1;
			this->btnGestioMembres->Text = L"Gestio de membres";
			this->btnGestioMembres->UseVisualStyleBackColor = true;
			this->btnGestioMembres->Click += gcnew System::EventHandler(this, &MenuCapColla::btnGestioMembres_Click);
			// 
			// btnCrearAssaig
			// 
			this->btnCrearAssaig->Location = System::Drawing::Point(170, 220);
			this->btnCrearAssaig->Name = L"btnCrearAssaig";
			this->btnCrearAssaig->Size = System::Drawing::Size(180, 35);
			this->btnCrearAssaig->TabIndex = 2;
			this->btnCrearAssaig->Text = L"Crear Assaig";
			this->btnCrearAssaig->UseVisualStyleBackColor = true;
			this->btnCrearAssaig->Click += gcnew System::EventHandler(this, &MenuCapColla::btnCrearAssaig_Click);
			// 
			// btnTancarSessio
			// 
			this->btnTancarSessio->Location = System::Drawing::Point(170, 290);
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
			this->Controls->Add(this->btnCrearAssaig);
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
		System::Void btnCrearAssaig_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnTancarSessio_Click(System::Object^ sender, System::EventArgs^ e);
	};
}