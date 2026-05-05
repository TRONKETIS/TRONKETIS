#pragma once
#include "UsuariDTO.h"
#include "CtrlRegistrarUsuari.h"
namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegistrarForm
	/// </summary>
	public ref class RegistrarForm : public System::Windows::Forms::Form
	{
	public:
		RegistrarForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegistrarForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblDNI;
	private: System::Windows::Forms::Label^ lblUserName;
	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::Label^ lblConfPassword;
	private: System::Windows::Forms::Label^ lblRol;
	private: System::Windows::Forms::TextBox^ txtDNI;
	private: System::Windows::Forms::TextBox^ txtUserName;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtConfPassword;
	private: System::Windows::Forms::ComboBox^ comboBoxRol;
	private: System::Windows::Forms::Button^ btnRegistrar;





	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblDNI = (gcnew System::Windows::Forms::Label());
			this->lblUserName = (gcnew System::Windows::Forms::Label());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblConfPassword = (gcnew System::Windows::Forms::Label());
			this->lblRol = (gcnew System::Windows::Forms::Label());
			this->txtDNI = (gcnew System::Windows::Forms::TextBox());
			this->txtUserName = (gcnew System::Windows::Forms::TextBox());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtConfPassword = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxRol = (gcnew System::Windows::Forms::ComboBox());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblDNI
			// 
			this->lblDNI->Location = System::Drawing::Point(74, 70);
			this->lblDNI->Name = L"lblDNI";
			this->lblDNI->Size = System::Drawing::Size(100, 23);
			this->lblDNI->TabIndex = 0;
			this->lblDNI->Text = L"DNI";
			this->lblDNI->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblUserName
			// 
			this->lblUserName->Location = System::Drawing::Point(30, 110);
			this->lblUserName->Name = L"lblUserName";
			this->lblUserName->Size = System::Drawing::Size(144, 23);
			this->lblUserName->TabIndex = 1;
			this->lblUserName->Text = L"Nombre de usuario";
			this->lblUserName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblEmail
			// 
			this->lblEmail->Location = System::Drawing::Point(30, 150);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(144, 23);
			this->lblEmail->TabIndex = 2;
			this->lblEmail->Text = L"Correo electronico";
			this->lblEmail->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblPassword
			// 
			this->lblPassword->Location = System::Drawing::Point(30, 192);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(144, 23);
			this->lblPassword->TabIndex = 3;
			this->lblPassword->Text = L"Contraseña";
			this->lblPassword->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblConfPassword
			// 
			this->lblConfPassword->Location = System::Drawing::Point(30, 235);
			this->lblConfPassword->Name = L"lblConfPassword";
			this->lblConfPassword->Size = System::Drawing::Size(144, 23);
			this->lblConfPassword->TabIndex = 4;
			this->lblConfPassword->Text = L"Confirmar contraseña";
			this->lblConfPassword->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblRol
			// 
			this->lblRol->Location = System::Drawing::Point(30, 274);
			this->lblRol->Name = L"lblRol";
			this->lblRol->Size = System::Drawing::Size(144, 23);
			this->lblRol->TabIndex = 5;
			this->lblRol->Text = L"Rol";
			this->lblRol->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtDNI
			// 
			this->txtDNI->Location = System::Drawing::Point(254, 70);
			this->txtDNI->Name = L"txtDNI";
			this->txtDNI->Size = System::Drawing::Size(180, 22);
			this->txtDNI->TabIndex = 6;
			// 
			// txtUserName
			// 
			this->txtUserName->Location = System::Drawing::Point(254, 110);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(180, 22);
			this->txtUserName->TabIndex = 7;
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(254, 151);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(180, 22);
			this->txtEmail->TabIndex = 8;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(254, 193);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(180, 22);
			this->txtPassword->TabIndex = 9;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// txtConfPassword
			// 
			this->txtConfPassword->Location = System::Drawing::Point(254, 235);
			this->txtConfPassword->Name = L"txtConfPassword";
			this->txtConfPassword->Size = System::Drawing::Size(180, 22);
			this->txtConfPassword->TabIndex = 10;
			this->txtConfPassword->UseSystemPasswordChar = true;
			// 
			// comboBoxRol
			// 
			this->comboBoxRol->FormattingEnabled = true;
			this->comboBoxRol->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Casteller", L"CapColla", L"Administrador"
			});
			this->comboBoxRol->Location = System::Drawing::Point(254, 274);
			this->comboBoxRol->Name = L"comboBoxRol";
			this->comboBoxRol->Size = System::Drawing::Size(180, 24);
			this->comboBoxRol->TabIndex = 11;
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnRegistrar->Location = System::Drawing::Point(336, 343);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(98, 34);
			this->btnRegistrar->TabIndex = 12;
			this->btnRegistrar->Text = L"Registrar";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &RegistrarForm::btnRegistrar_Click);
			// 
			// RegistrarForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 425);
			this->Controls->Add(this->btnRegistrar);
			this->Controls->Add(this->comboBoxRol);
			this->Controls->Add(this->txtConfPassword);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->txtUserName);
			this->Controls->Add(this->txtDNI);
			this->Controls->Add(this->lblRol);
			this->Controls->Add(this->lblConfPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblEmail);
			this->Controls->Add(this->lblUserName);
			this->Controls->Add(this->lblDNI);
			this->Name = L"RegistrarForm";
			this->Text = L"RegistrarForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {
		Tronketis::UsuariDTO^ u = gcnew Tronketis::UsuariDTO();

		u->dni = txtDNI->Text;
		u->username = txtUserName->Text;
		u->email = txtEmail->Text;
		u->password = txtPassword->Text;
		u->rol = comboBoxRol->Text;

		Tronketis::CtrlRegistrarUsuari^ ctrl = gcnew Tronketis::CtrlRegistrarUsuari();

		String^ error;
		bool ok = ctrl->registrar(u, error);

		if (!ok) {
			MessageBox::Show(error);
		}
		else {
			MessageBox::Show("Usuario registrado correctamente");
		}
	}
};
}
