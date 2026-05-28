#pragma once
#include "CtrlIniciarSesion.h"
#include "MenuAdminForm.h"
#include "MenuCapColla.h"
#include "CercadorColla.h"
#include "CercadorMembre.h"
#include "ConsultarCalendariForm.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for IniciarSesionForm
	/// </summary>
	public ref class IniciarSesionForm : public System::Windows::Forms::Form
	{
	public:
		IniciarSesionForm(void)
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
		~IniciarSesionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnLogin;


	protected:

	protected:

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
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblEmail
			// 
			this->lblEmail->Location = System::Drawing::Point(64, 64);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(97, 51);
			this->lblEmail->TabIndex = 0;
			this->lblEmail->Text = L"Email";
			this->lblEmail->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(226, 78);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(198, 22);
			this->txtEmail->TabIndex = 1;
			// 
			// lblPassword
			// 
			this->lblPassword->Location = System::Drawing::Point(64, 152);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(97, 51);
			this->lblPassword->TabIndex = 2;
			this->lblPassword->Text = L"Contraseña";
			this->lblPassword->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(226, 166);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(198, 22);
			this->txtPassword->TabIndex = 3;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnLogin->Location = System::Drawing::Point(313, 255);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(111, 38);
			this->btnLogin->TabIndex = 4;
			this->btnLogin->Text = L"Entrar";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &IniciarSesionForm::btnLogin_Click);
			// 
			// IniciarSesionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 443);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->lblEmail);
			this->Name = L"IniciarSesionForm";
			this->Text = L"IniciarSesionForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// El evento de click del botón de login
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = txtEmail->Text;
		String^ password = txtPassword->Text;
		if (String::IsNullOrEmpty(email) || String::IsNullOrEmpty(password))
		{
			MessageBox::Show("Rellena todos los campos");
			return;
		}
		String^ dni = "";
		String^ rol = "";
		bool ok = CtrlIniciarSesion::Execute(email, password, dni, rol);

		if (!ok)
		{
			MessageBox::Show("Credenciales incorrectas");
			return;
		}
		if (rol == "Administrador")
		{
			MenuAdminForm^ adminForm = gcnew MenuAdminForm(email);
			this->Hide();

			adminForm->ShowDialog(); 

			this->Close(); 
		}
		else if (rol == "CapColla")
		{
			String^ collaName = "";

			if (CercadorColla::obtenirCollaPerCap(dni, collaName)) {
				MenuCapColla^ capCollaForm = gcnew MenuCapColla(collaName);
				capCollaForm->ShowDialog();
			}
			else {
				MessageBox::Show("Aquest usuari no té cap colla assignada.");
			}
			this->Close();
		}
		else
		{
			String^ collaName = ""; 
			if (rol == "Casteller") {
				CercadorMembre::obtenirCollaDeMembre(dni, collaName);
			}

			// Si es Casteller le abrimos el calendario con su rol 
			// por ahora como no hay Menu para casteller o usuari lo abrimos directo
			ConsultarCalendariForm^ calForm = gcnew ConsultarCalendariForm(rol, collaName);
			this->Hide();
			calForm->ShowDialog();
			this->Close();
		}
		
	}
};
}
