#pragma once
#include "AppColors.h"
#include "CtrlAdminMenu.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class InhabilitarUsuarioForm : public System::Windows::Forms::Form
	{
	public:
		InhabilitarUsuarioForm(void)
		{
			InitializeComponent();
		}

	protected:
		~InhabilitarUsuarioForm()
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
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ txtDniAInhab;
		System::Windows::Forms::Button^ btnInhabOk;

		System::ComponentModel::Container^ components;

		void ConfigurarBotonPeligro(Button^ btn)
		{
			btn->BackColor = AppColors::DarkRed;
			btn->ForeColor = AppColors::White;
			btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			btn->FlatAppearance->BorderColor = AppColors::Yellow;
			btn->FlatAppearance->BorderSize = 1;
			btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(150, 35, 60);
			btn->FlatAppearance->MouseDownBackColor = AppColors::Black;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtDniAInhab = (gcnew System::Windows::Forms::TextBox());
			this->btnInhabOk = (gcnew System::Windows::Forms::Button());
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
			this->lblTitulo->Size = System::Drawing::Size(300, 41);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Inhabilitar usuario";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitulo->ForeColor = AppColors::White;
			this->lblSubtitulo->Location = System::Drawing::Point(39, 66);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(310, 17);
			this->lblSubtitulo->TabIndex = 1;
			this->lblSubtitulo->Text = L"Desactiva el acceso de un usuario";
			// 
			// panelContenido
			// 
			this->panelContenido->BackColor = AppColors::White;
			this->panelContenido->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelContenido->Controls->Add(this->label1);
			this->panelContenido->Controls->Add(this->txtDniAInhab);
			this->panelContenido->Controls->Add(this->btnInhabOk);
			this->panelContenido->Location = System::Drawing::Point(42, 130);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(536, 225);
			this->panelContenido->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.0F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = AppColors::Black;
			this->label1->Location = System::Drawing::Point(43, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(250, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"DNI del usuario a inhabilitar";
			// 
			// txtDniAInhab
			// 
			this->txtDniAInhab->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtDniAInhab->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.0F));
			this->txtDniAInhab->Location = System::Drawing::Point(47, 78);
			this->txtDniAInhab->Name = L"txtDniAInhab";
			this->txtDniAInhab->Size = System::Drawing::Size(440, 25);
			this->txtDniAInhab->TabIndex = 0;
			// 
			// btnInhabOk
			// 
			this->btnInhabOk->Location = System::Drawing::Point(47, 136);
			this->btnInhabOk->Name = L"btnInhabOk";
			this->btnInhabOk->Size = System::Drawing::Size(440, 42);
			this->btnInhabOk->TabIndex = 1;
			this->btnInhabOk->Text = L"Inhabilitar usuario";
			this->btnInhabOk->UseVisualStyleBackColor = false;
			this->btnInhabOk->Click += gcnew System::EventHandler(this, &InhabilitarUsuarioForm::btnInhabOk_Click);
			ConfigurarBotonPeligro(this->btnInhabOk);
			// 
			// InhabilitarUsuarioForm
			// 
			this->AcceptButton = this->btnInhabOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = AppColors::Background;
			this->ClientSize = System::Drawing::Size(620, 390);
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelHeader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"InhabilitarUsuarioForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Inhabilitar usuario";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void btnInhabOk_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = txtDniAInhab->Text;

		if (String::IsNullOrWhiteSpace(dni))
		{
			MessageBox::Show("Introduce un DNI", "Dato obligatorio", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show(
			"Seguro que quieres inhabilitar este usuario?",
			"Confirmacion",
			MessageBoxButtons::OKCancel,
			MessageBoxIcon::Warning
		);

		if (result == System::Windows::Forms::DialogResult::OK)
		{
			bool ok = CtrlAdminMenu::InhabilitarUsuario(dni);

			if (ok)
			{
				MessageBox::Show("Usuario inhabilitado correctamente", "Operacion completada", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
			else
			{
				MessageBox::Show("No se encontro el usuario o ya estaba inactivo", "No se pudo inhabilitar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	};
}
