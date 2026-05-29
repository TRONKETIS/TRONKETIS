#pragma once
#include "CtrlRegisterCasteller.h"
namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegisterCastellerForm
	/// </summary>
	public ref class RegisterCastellerForm : public System::Windows::Forms::Form
	{

	private:
		CtrlRegisterCasteller^ ctrl;
		String^ dniCasteller;
	public:
		RegisterCastellerForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public:
		RegisterCastellerForm(String^ dni)
		{
			InitializeComponent();

			ctrl = gcnew CtrlRegisterCasteller();

			dniCasteller = dni;

			lblDNIcasteller->Text = dni;
			//lblDNIcasteller->Enabled = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterCastellerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblDNIcasteller;
	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtTel;
	private: System::Windows::Forms::Button^ btnRegCasteller;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		//CtrlRegisterCasteller^ ctrl;
		//String^ dniCasteller;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblDNIcasteller = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtTel = (gcnew System::Windows::Forms::TextBox());
			this->btnRegCasteller = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(84, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"DNI";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblDNIcasteller
			// 
			this->lblDNIcasteller->Location = System::Drawing::Point(308, 73);
			this->lblDNIcasteller->Name = L"lblDNIcasteller";
			this->lblDNIcasteller->Size = System::Drawing::Size(100, 23);
			this->lblDNIcasteller->TabIndex = 1;
			this->lblDNIcasteller->Text = L"label2";
			this->lblDNIcasteller->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(84, 129);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Telefono";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtTel
			// 
			this->txtTel->Location = System::Drawing::Point(274, 129);
			this->txtTel->Name = L"txtTel";
			this->txtTel->Size = System::Drawing::Size(171, 22);
			this->txtTel->TabIndex = 3;
			// 
			// btnRegCasteller
			// 
			this->btnRegCasteller->BackColor = System::Drawing::Color::OrangeRed;
			this->btnRegCasteller->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegCasteller->Location = System::Drawing::Point(287, 247);
			this->btnRegCasteller->Name = L"btnRegCasteller";
			this->btnRegCasteller->Size = System::Drawing::Size(158, 41);
			this->btnRegCasteller->TabIndex = 4;
			this->btnRegCasteller->Text = L"Registrar casteller";
			this->btnRegCasteller->UseVisualStyleBackColor = false;
			this->btnRegCasteller->Click += gcnew System::EventHandler(this, &RegisterCastellerForm::btnRegCasteller_Click);
			// 
			// RegisterCastellerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(566, 362);
			this->Controls->Add(this->btnRegCasteller);
			this->Controls->Add(this->txtTel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblDNIcasteller);
			this->Controls->Add(this->label1);
			this->Name = L"RegisterCastellerForm";
			this->Text = L"RegisterCastellerForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnRegCasteller_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ telefon = txtTel->Text;

		if (String::IsNullOrWhiteSpace(telefon))
		{
			telefon = nullptr;
		}

		ctrl->registrarCasteller(dniCasteller, telefon);

		MessageBox::Show("Casteller registrat correctament");

		this->Close();
	}
};
}
