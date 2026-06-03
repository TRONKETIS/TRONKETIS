#pragma once
#include "AppColors.h"
#include "CtrlIniciarSesion.h"
#include "MenuAdminForm.h"
#include "MenuCapColla.h"
#include "MenuCastellerForm.h"
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

	public ref class IniciarSesionForm : public System::Windows::Forms::Form
	{
	public:
		IniciarSesionForm(void)
		{
			InitializeComponent();
			ConfigurarEstiloPantalla();
		}

	protected:
		~IniciarSesionForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelCard;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblCardTitle;
		System::Windows::Forms::Label^ lblCardInfo;
		System::Windows::Forms::Label^ lblEmail;
		System::Windows::Forms::TextBox^ txtEmail;
		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::Button^ btnLogin;
		System::Windows::Forms::Label^ lblFooter;
		System::ComponentModel::Container^ components;

		void ConfigurarEstiloPantalla()
		{
			this->BackColor = AppColors::Background;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->AcceptButton = this->btnLogin;

			ConfigurarTextBox(txtEmail);
			ConfigurarTextBox(txtPassword);

			btnLogin->BackColor = AppColors::Yellow;
			btnLogin->ForeColor = AppColors::Black;
			btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			btnLogin->FlatAppearance->BorderSize = 0;
			btnLogin->FlatAppearance->MouseOverBackColor = Color::FromArgb(224, 197, 65);
			btnLogin->FlatAppearance->MouseDownBackColor = AppColors::DarkRed;
			btnLogin->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.5F, System::Drawing::FontStyle::Bold);
			btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
		}

		void ConfigurarTextBox(TextBox^ txt)
		{
			if (txt == nullptr) return;

			txt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			txt->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0F);
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->panelCard = (gcnew System::Windows::Forms::Panel());
			this->lblFooter = (gcnew System::Windows::Forms::Label());
			this->lblCardInfo = (gcnew System::Windows::Forms::Label());
			this->lblCardTitle = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->panelHeader->SuspendLayout();
			this->panelCard->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = AppColors::DarkRed;
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelHeader->Controls->Add(this->lblTitulo);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(620, 125);
			this->panelHeader->TabIndex = 0;
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.0F));
			this->lblSubtitulo->ForeColor = AppColors::White;
			this->lblSubtitulo->Location = System::Drawing::Point(37, 75);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(294, 19);
			this->lblSubtitulo->TabIndex = 1;
			this->lblSubtitulo->Text = L"Gestion sencilla para colles castelleres";
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24.0F, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = AppColors::White;
			this->lblTitulo->Location = System::Drawing::Point(34, 30);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(207, 45);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Tronketis";
			// 
			// panelCard
			// 
			this->panelCard->BackColor = System::Drawing::Color::White;
			this->panelCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelCard->Controls->Add(this->lblFooter);
			this->panelCard->Controls->Add(this->lblCardInfo);
			this->panelCard->Controls->Add(this->lblCardTitle);
			this->panelCard->Controls->Add(this->btnLogin);
			this->panelCard->Controls->Add(this->txtPassword);
			this->panelCard->Controls->Add(this->lblPassword);
			this->panelCard->Controls->Add(this->txtEmail);
			this->panelCard->Controls->Add(this->lblEmail);
			this->panelCard->Location = System::Drawing::Point(75, 158);
			this->panelCard->Name = L"panelCard";
			this->panelCard->Size = System::Drawing::Size(470, 315);
			this->panelCard->TabIndex = 1;
			// 
			// lblFooter
			// 
			this->lblFooter->AutoSize = true;
			this->lblFooter->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F));
			this->lblFooter->ForeColor = System::Drawing::Color::DimGray;
			this->lblFooter->Location = System::Drawing::Point(58, 271);
			this->lblFooter->Name = L"lblFooter";
			this->lblFooter->Size = System::Drawing::Size(242, 15);
			this->lblFooter->TabIndex = 7;
			this->lblFooter->Text = L"Introduce tus credenciales para continuar";
			// 
			// lblCardInfo
			// 
			this->lblCardInfo->AutoSize = true;
			this->lblCardInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F));
			this->lblCardInfo->ForeColor = System::Drawing::Color::DimGray;
			this->lblCardInfo->Location = System::Drawing::Point(58, 64);
			this->lblCardInfo->Name = L"lblCardInfo";
			this->lblCardInfo->Size = System::Drawing::Size(237, 15);
			this->lblCardInfo->TabIndex = 6;
			this->lblCardInfo->Text = L"Accede al sistema con tu cuenta registrada";
			// 
			// lblCardTitle
			// 
			this->lblCardTitle->AutoSize = true;
			this->lblCardTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.0F, System::Drawing::FontStyle::Bold));
			this->lblCardTitle->ForeColor = AppColors::DarkRed;
			this->lblCardTitle->Location = System::Drawing::Point(56, 34);
			this->lblCardTitle->Name = L"lblCardTitle";
			this->lblCardTitle->Size = System::Drawing::Size(137, 30);
			this->lblCardTitle->TabIndex = 5;
			this->lblCardTitle->Text = L"Iniciar sesion";
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(61, 217);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(348, 42);
			this->btnLogin->TabIndex = 2;
			this->btnLogin->Text = L"Entrar";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &IniciarSesionForm::btnLogin_Click);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(61, 177);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(348, 25);
			this->txtPassword->TabIndex = 1;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblPassword->ForeColor = AppColors::Black;
			this->lblPassword->Location = System::Drawing::Point(58, 154);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(78, 17);
			this->lblPassword->TabIndex = 3;
			this->lblPassword->Text = L"Contrasena";
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(61, 118);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(348, 25);
			this->txtEmail->TabIndex = 0;
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblEmail->ForeColor = AppColors::Black;
			this->lblEmail->Location = System::Drawing::Point(58, 95);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(40, 17);
			this->lblEmail->TabIndex = 0;
			this->lblEmail->Text = L"Email";
			// 
			// IniciarSesionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 505);
			this->Controls->Add(this->panelCard);
			this->Controls->Add(this->panelHeader);
			this->Name = L"IniciarSesionForm";
			this->Text = L"Iniciar sesion";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelCard->ResumeLayout(false);
			this->panelCard->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

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

			System::Windows::Forms::DialogResult resultado = adminForm->ShowDialog();

			if (resultado == System::Windows::Forms::DialogResult::OK)
			{
				txtPassword->Clear();
				this->Show();
				txtPassword->Focus();
			}
			else
			{
				this->Close();
			}
		}
		else if (rol == "CapColla")
		{
			String^ collaName = "";

			if (CercadorColla::obtenirCollaPerCap(dni, collaName)) {
				MenuCapColla^ capCollaForm = gcnew MenuCapColla(collaName);
				this->Hide();

				System::Windows::Forms::DialogResult resultado = capCollaForm->ShowDialog();

				if (resultado == System::Windows::Forms::DialogResult::OK)
				{
					txtPassword->Clear();
					this->Show();
					txtPassword->Focus();
				}
				else
				{
					this->Close();
				}
			}
			else {
				MessageBox::Show("Aquest usuari no te cap colla assignada.");
			}
		}
		else if (rol == "Casteller")
		{
			String^ collaName = "";

			if (!CercadorMembre::obtenirCollaDeMembre(dni, collaName))
			{
				MessageBox::Show("Aquest casteller no te cap colla assignada.");
				return;
			}

			MenuCastellerForm^ castellerForm = gcnew MenuCastellerForm(dni, collaName);
			this->Hide();

			System::Windows::Forms::DialogResult resultado = castellerForm->ShowDialog();

			if (resultado == System::Windows::Forms::DialogResult::OK)
			{
				txtPassword->Clear();
				this->Show();
				txtPassword->Focus();
			}
			else
			{
				this->Close();
			}
		}
		else
		{
			ConsultarCalendariForm^ calForm = gcnew ConsultarCalendariForm(rol, "");
			this->Hide();
			calForm->ShowDialog();
			this->Close();
		}
	}
	};
}
