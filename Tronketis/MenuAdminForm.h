#pragma once

#include "AppColors.h"
#include "CtrlAdminMenu.h"
#include "RegistrarForm.h"
#include "InhabilitarUsuarioForm.h"
#include "ModificarUsuariForm.h"
#include "CrearCollaForm.h"
#include "CrearDiadaForm.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuAdminForm : public System::Windows::Forms::Form
	{
	public:
		MenuAdminForm(void)
		{
			InitializeComponent();
			ConfigurarEstiloPantalla();
		}

		MenuAdminForm(String^ adminName)
		{
			InitializeComponent();
			lblAdminName->Text = adminName;
			ConfigurarEstiloPantalla();
		}

	protected:
		~MenuAdminForm()
		{
			if (components) delete components;
		}

	private:
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblBienvenida;
		System::Windows::Forms::Label^ lblAdminName;
		System::Windows::Forms::Label^ lblSeccionUsuarios;
		System::Windows::Forms::Label^ lblSeccionColles;
		System::Windows::Forms::Button^ btnGoToRegUser;
		System::Windows::Forms::Button^ btnGoToDelUser;
		System::Windows::Forms::Button^ btnGoToCrearColla;
		System::Windows::Forms::Button^ btnGoToCrearDiada;
		System::Windows::Forms::Button^ btnModificarUsuario;
		System::Windows::Forms::Button^ btnLogout;
		System::ComponentModel::Container^ components;

		void ConfigurarEstiloPantalla()
		{
			this->BackColor = AppColors::Background;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;

			ConfigurarBotonPrincipal(btnGoToRegUser);
			ConfigurarBotonPrincipal(btnGoToDelUser);
			ConfigurarBotonPrincipal(btnModificarUsuario);
			ConfigurarBotonPrincipal(btnGoToCrearColla);
			ConfigurarBotonPrincipal(btnGoToCrearDiada);

			btnLogout->BackColor = AppColors::DarkRed;
			btnLogout->ForeColor = AppColors::White;
			btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			btnLogout->FlatAppearance->BorderColor = AppColors::Yellow;
			btnLogout->FlatAppearance->BorderSize = 1;
			btnLogout->FlatAppearance->MouseOverBackColor = Color::FromArgb(150, 35, 60);
			btnLogout->FlatAppearance->MouseDownBackColor = AppColors::Black;
			btnLogout->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Bold);
		}

		void ConfigurarBotonPrincipal(Button^ btn)
		{
			if (btn == nullptr) return;

			btn->BackColor = AppColors::Yellow;
			btn->ForeColor = AppColors::Black;
			btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			btn->FlatAppearance->BorderSize = 0;
			btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(224, 197, 65);
			btn->FlatAppearance->MouseDownBackColor = AppColors::DarkRed;
			btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			btn->Cursor = System::Windows::Forms::Cursors::Hand;
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->lblSeccionColles = (gcnew System::Windows::Forms::Label());
			this->lblSeccionUsuarios = (gcnew System::Windows::Forms::Label());
			this->btnGoToCrearColla = (gcnew System::Windows::Forms::Button());
			this->btnGoToCrearDiada = (gcnew System::Windows::Forms::Button());
			this->btnModificarUsuario = (gcnew System::Windows::Forms::Button());
			this->btnGoToDelUser = (gcnew System::Windows::Forms::Button());
			this->btnGoToRegUser = (gcnew System::Windows::Forms::Button());
			this->lblAdminName = (gcnew System::Windows::Forms::Label());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = AppColors::DarkRed;
			this->panelHeader->Controls->Add(this->btnLogout);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelHeader->Controls->Add(this->lblTitulo);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(620, 116);
			this->panelHeader->TabIndex = 0;
			// 
			// btnLogout
			// 
			this->btnLogout->Location = System::Drawing::Point(470, 36);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(118, 38);
			this->btnLogout->TabIndex = 6;
			this->btnLogout->Text = L"Cerrar sesion";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnLogout_Click);
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitulo->ForeColor = AppColors::White;
			this->lblSubtitulo->Location = System::Drawing::Point(31, 67);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(263, 17);
			this->lblSubtitulo->TabIndex = 1;
			this->lblSubtitulo->Text = L"Gestion de usuarios y colles";
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.0F, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = AppColors::White;
			this->lblTitulo->Location = System::Drawing::Point(27, 25);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(188, 41);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Tronketis";
			// 
			// panelContenido
			// 
			this->panelContenido->BackColor = System::Drawing::Color::White;
			this->panelContenido->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelContenido->Controls->Add(this->lblSeccionColles);
			this->panelContenido->Controls->Add(this->lblSeccionUsuarios);
			this->panelContenido->Controls->Add(this->btnGoToCrearDiada);
			this->panelContenido->Controls->Add(this->btnGoToCrearColla);
			this->panelContenido->Controls->Add(this->btnModificarUsuario);
			this->panelContenido->Controls->Add(this->btnGoToDelUser);
			this->panelContenido->Controls->Add(this->btnGoToRegUser);
			this->panelContenido->Controls->Add(this->lblAdminName);
			this->panelContenido->Controls->Add(this->lblBienvenida);
			this->panelContenido->Location = System::Drawing::Point(42, 145);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(536, 352);
			this->panelContenido->TabIndex = 1;
			// 
			// lblSeccionColles
			// 
			this->lblSeccionColles->AutoSize = true;
			this->lblSeccionColles->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.0F, System::Drawing::FontStyle::Bold));
			this->lblSeccionColles->ForeColor = AppColors::DarkRed;
			this->lblSeccionColles->Location = System::Drawing::Point(36, 228);
			this->lblSeccionColles->Name = L"lblSeccionColles";
			this->lblSeccionColles->Size = System::Drawing::Size(116, 20);
			this->lblSeccionColles->TabIndex = 8;
			this->lblSeccionColles->Text = L"Colles i diades";
			// 
			// lblSeccionUsuarios
			// 
			this->lblSeccionUsuarios->AutoSize = true;
			this->lblSeccionUsuarios->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.0F, System::Drawing::FontStyle::Bold));
			this->lblSeccionUsuarios->ForeColor = AppColors::DarkRed;
			this->lblSeccionUsuarios->Location = System::Drawing::Point(36, 83);
			this->lblSeccionUsuarios->Name = L"lblSeccionUsuarios";
			this->lblSeccionUsuarios->Size = System::Drawing::Size(68, 20);
			this->lblSeccionUsuarios->TabIndex = 7;
			this->lblSeccionUsuarios->Text = L"Usuarios";
			// 
			// btnGoToCrearColla
			// 
			this->btnGoToCrearColla->Location = System::Drawing::Point(40, 263);
			this->btnGoToCrearColla->Name = L"btnGoToCrearColla";
			this->btnGoToCrearColla->Size = System::Drawing::Size(210, 42);
			this->btnGoToCrearColla->TabIndex = 4;
			this->btnGoToCrearColla->Text = L"Crear Colla";
			this->btnGoToCrearColla->UseVisualStyleBackColor = false;
			this->btnGoToCrearColla->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToCrearColla_Click);

			// 
			// btnGoToCrearDiada
			// 
			this->btnGoToCrearDiada->Location = System::Drawing::Point(280, 263);
			this->btnGoToCrearDiada->Name = L"btnGoToCrearDiada";
			this->btnGoToCrearDiada->Size = System::Drawing::Size(210, 42);
			this->btnGoToCrearDiada->TabIndex = 5;
			this->btnGoToCrearDiada->Text = L"Crear Diada";
			this->btnGoToCrearDiada->UseVisualStyleBackColor = false;
			this->btnGoToCrearDiada->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToCrearDiada_Click);
			// 
			// btnModificarUsuario
			// 
			this->btnModificarUsuario->Location = System::Drawing::Point(280, 124);
			this->btnModificarUsuario->Name = L"btnModificarUsuario";
			this->btnModificarUsuario->Size = System::Drawing::Size(210, 42);
			this->btnModificarUsuario->TabIndex = 2;
			this->btnModificarUsuario->Text = L"Modificar Usuario";
			this->btnModificarUsuario->UseVisualStyleBackColor = false;
			this->btnModificarUsuario->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToModUser_Click);
			// 
			// btnGoToDelUser
			// 
			this->btnGoToDelUser->Location = System::Drawing::Point(40, 176);
			this->btnGoToDelUser->Name = L"btnGoToDelUser";
			this->btnGoToDelUser->Size = System::Drawing::Size(450, 42);
			this->btnGoToDelUser->TabIndex = 3;
			this->btnGoToDelUser->Text = L"Inhabilitar Usuario";
			this->btnGoToDelUser->UseVisualStyleBackColor = false;
			this->btnGoToDelUser->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToDelUser_Click);
			// 
			// btnGoToRegUser
			// 
			this->btnGoToRegUser->Location = System::Drawing::Point(40, 124);
			this->btnGoToRegUser->Name = L"btnGoToRegUser";
			this->btnGoToRegUser->Size = System::Drawing::Size(210, 42);
			this->btnGoToRegUser->TabIndex = 1;
			this->btnGoToRegUser->Text = L"Registrar Usuario";
			this->btnGoToRegUser->UseVisualStyleBackColor = false;
			this->btnGoToRegUser->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToRegUser_Click);
			// 
			// lblAdminName
			// 
			this->lblAdminName->AutoSize = true;
			this->lblAdminName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.0F, System::Drawing::FontStyle::Bold));
			this->lblAdminName->ForeColor = AppColors::Black;
			this->lblAdminName->Location = System::Drawing::Point(145, 34);
			this->lblAdminName->Name = L"lblAdminName";
			this->lblAdminName->Size = System::Drawing::Size(94, 19);
			this->lblAdminName->TabIndex = 1;
			this->lblAdminName->Text = L"admin_name";
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->AutoSize = true;
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.0F));
			this->lblBienvenida->ForeColor = System::Drawing::Color::DimGray;
			this->lblBienvenida->Location = System::Drawing::Point(36, 34);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(112, 19);
			this->lblBienvenida->TabIndex = 0;
			this->lblBienvenida->Text = L"Bienvenid@,";
			// 
			// MenuAdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 535);
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelHeader);
			this->Name = L"MenuAdminForm";
			this->Text = L"Menu Administrador";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void btnGoToRegUser_Click(System::Object^ sender, System::EventArgs^ e) {
			RegistrarForm^ form = gcnew RegistrarForm();
			form->ShowDialog();
		}

		System::Void btnGoToDelUser_Click(System::Object^ sender, System::EventArgs^ e) {
			InhabilitarUsuarioForm^ form = gcnew InhabilitarUsuarioForm();
			form->ShowDialog();
		}

		System::Void btnGoToModUser_Click(System::Object^ sender, System::EventArgs^ e) {
			ModificarUsuariForm^ form = gcnew ModificarUsuariForm();
			form->ShowDialog();
		}

		System::Void btnGoToCrearColla_Click(System::Object^ sender, System::EventArgs^ e) {
			CrearCollaForm^ form = gcnew CrearCollaForm();
			form->ShowDialog();
		}

		System::Void btnGoToCrearDiada_Click(System::Object^ sender, System::EventArgs^ e) {
			CrearDiadaForm^ form = gcnew CrearDiadaForm();
			form->ShowDialog();
		}

		System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	};
}
