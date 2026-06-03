#pragma once
#include "AppColors.h"
#include "UsuariDTO.h"
#include "CtrlRegistrarUsuari.h"
#include "RegisterCastellerForm.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class RegistrarForm : public System::Windows::Forms::Form
	{
	public:
		RegistrarForm(void)
		{
			InitializeComponent();
		}

	protected:
		~RegistrarForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblDNI;
		System::Windows::Forms::Label^ lblUserName;
		System::Windows::Forms::Label^ lblEmail;
		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::Label^ lblConfPassword;
		System::Windows::Forms::Label^ lblRol;
		System::Windows::Forms::TextBox^ txtDNI;
		System::Windows::Forms::TextBox^ txtUserName;
		System::Windows::Forms::TextBox^ txtEmail;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::TextBox^ txtConfPassword;
		System::Windows::Forms::ComboBox^ comboBoxRol;
		System::Windows::Forms::Button^ btnRegistrar;

		System::ComponentModel::Container^ components;

		void ConfigurarLabel(Label^ lbl)
		{
			lbl->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			lbl->ForeColor = AppColors::Black;
			lbl->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		}

		void ConfigurarTextBox(TextBox^ txt)
		{
			txt->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0F);
			txt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		}

		void ConfigurarBotonPrincipal(Button^ btn)
		{
			btn->BackColor = AppColors::Yellow;
			btn->ForeColor = AppColors::Black;
			btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			btn->FlatAppearance->BorderSize = 0;
			btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(224, 197, 65);
			btn->FlatAppearance->MouseDownBackColor = AppColors::DarkRed;
			btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0F, System::Drawing::FontStyle::Bold);
			btn->Cursor = System::Windows::Forms::Cursors::Hand;
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
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
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = AppColors::DarkRed;
			this->panelHeader->Controls->Add(this->lblTitulo);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(620, 105);
			this->panelHeader->TabIndex = 0;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.0F, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = AppColors::White;
			this->lblTitulo->Location = System::Drawing::Point(34, 22);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(260, 41);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Registrar usuario";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitulo->ForeColor = AppColors::White;
			this->lblSubtitulo->Location = System::Drawing::Point(39, 66);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(245, 17);
			this->lblSubtitulo->TabIndex = 1;
			this->lblSubtitulo->Text = L"Alta de usuarios en Tronketis";
			// 
			// panelContenido
			// 
			this->panelContenido->BackColor = AppColors::White;
			this->panelContenido->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelContenido->Controls->Add(this->lblDNI);
			this->panelContenido->Controls->Add(this->txtDNI);
			this->panelContenido->Controls->Add(this->lblUserName);
			this->panelContenido->Controls->Add(this->txtUserName);
			this->panelContenido->Controls->Add(this->lblEmail);
			this->panelContenido->Controls->Add(this->txtEmail);
			this->panelContenido->Controls->Add(this->lblPassword);
			this->panelContenido->Controls->Add(this->txtPassword);
			this->panelContenido->Controls->Add(this->lblConfPassword);
			this->panelContenido->Controls->Add(this->txtConfPassword);
			this->panelContenido->Controls->Add(this->lblRol);
			this->panelContenido->Controls->Add(this->comboBoxRol);
			this->panelContenido->Controls->Add(this->btnRegistrar);
			this->panelContenido->Location = System::Drawing::Point(42, 130);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(536, 415);
			this->panelContenido->TabIndex = 1;
			// 
			// labels
			// 
			this->lblDNI->Location = System::Drawing::Point(46, 39);
			this->lblDNI->Name = L"lblDNI";
			this->lblDNI->Size = System::Drawing::Size(170, 26);
			this->lblDNI->Text = L"DNI";
			this->lblUserName->Location = System::Drawing::Point(46, 88);
			this->lblUserName->Name = L"lblUserName";
			this->lblUserName->Size = System::Drawing::Size(170, 26);
			this->lblUserName->Text = L"Nombre de usuario";
			this->lblEmail->Location = System::Drawing::Point(46, 137);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(170, 26);
			this->lblEmail->Text = L"Correo electronico";
			this->lblPassword->Location = System::Drawing::Point(46, 186);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(170, 26);
			this->lblPassword->Text = L"Contrasena";
			this->lblConfPassword->Location = System::Drawing::Point(46, 235);
			this->lblConfPassword->Name = L"lblConfPassword";
			this->lblConfPassword->Size = System::Drawing::Size(170, 26);
			this->lblConfPassword->Text = L"Confirmar contrasena";
			this->lblRol->Location = System::Drawing::Point(46, 284);
			this->lblRol->Name = L"lblRol";
			this->lblRol->Size = System::Drawing::Size(170, 26);
			this->lblRol->Text = L"Rol";
			ConfigurarLabel(this->lblDNI);
			ConfigurarLabel(this->lblUserName);
			ConfigurarLabel(this->lblEmail);
			ConfigurarLabel(this->lblPassword);
			ConfigurarLabel(this->lblConfPassword);
			ConfigurarLabel(this->lblRol);
			// 
			// inputs
			// 
			this->txtDNI->Location = System::Drawing::Point(245, 39);
			this->txtDNI->Name = L"txtDNI";
			this->txtDNI->Size = System::Drawing::Size(240, 25);
			this->txtDNI->TabIndex = 0;
			this->txtUserName->Location = System::Drawing::Point(245, 88);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(240, 25);
			this->txtUserName->TabIndex = 1;
			this->txtEmail->Location = System::Drawing::Point(245, 137);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(240, 25);
			this->txtEmail->TabIndex = 2;
			this->txtPassword->Location = System::Drawing::Point(245, 186);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(240, 25);
			this->txtPassword->TabIndex = 3;
			this->txtPassword->UseSystemPasswordChar = true;
			this->txtConfPassword->Location = System::Drawing::Point(245, 235);
			this->txtConfPassword->Name = L"txtConfPassword";
			this->txtConfPassword->Size = System::Drawing::Size(240, 25);
			this->txtConfPassword->TabIndex = 4;
			this->txtConfPassword->UseSystemPasswordChar = true;
			ConfigurarTextBox(this->txtDNI);
			ConfigurarTextBox(this->txtUserName);
			ConfigurarTextBox(this->txtEmail);
			ConfigurarTextBox(this->txtPassword);
			ConfigurarTextBox(this->txtConfPassword);
			this->comboBoxRol->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxRol->FormattingEnabled = true;
			this->comboBoxRol->Items->AddRange(gcnew cli::array< System::Object^ >(3) {
				L"Casteller", L"CapColla", L"Administrador"
			});
			this->comboBoxRol->Location = System::Drawing::Point(245, 284);
			this->comboBoxRol->Name = L"comboBoxRol";
			this->comboBoxRol->Size = System::Drawing::Size(240, 25);
			this->comboBoxRol->TabIndex = 5;
			this->comboBoxRol->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0F);
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->Location = System::Drawing::Point(245, 340);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(240, 42);
			this->btnRegistrar->TabIndex = 6;
			this->btnRegistrar->Text = L"Registrar usuario";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &RegistrarForm::btnRegistrar_Click);
			ConfigurarBotonPrincipal(this->btnRegistrar);
			// 
			// RegistrarForm
			// 
			this->AcceptButton = this->btnRegistrar;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = AppColors::Background;
			this->ClientSize = System::Drawing::Size(620, 575);
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelHeader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"RegistrarForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Registrar usuario";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
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
			MessageBox::Show(error, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("Usuario registrado correctamente", "Registro completado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			if (u->rol == "Casteller") {
				RegisterCastellerForm^ form = gcnew RegisterCastellerForm(u->dni);
				form->ShowDialog();
			}
		}
	}
	};
}
