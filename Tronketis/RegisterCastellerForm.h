#pragma once
#include "AppColors.h"
#include "CtrlRegisterCasteller.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class RegisterCastellerForm : public System::Windows::Forms::Form
	{
	private:
		CtrlRegisterCasteller^ ctrl;
		String^ dniCasteller;

	public:
		RegisterCastellerForm(void)
		{
			InitializeComponent();
			ctrl = gcnew CtrlRegisterCasteller();
			dniCasteller = "";
		}

		RegisterCastellerForm(String^ dni)
		{
			InitializeComponent();
			ctrl = gcnew CtrlRegisterCasteller();
			dniCasteller = dni;
			lblDNIcasteller->Text = dni;
		}

	protected:
		~RegisterCastellerForm()
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
		System::Windows::Forms::Label^ lblDNIcasteller;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ txtTel;
		System::Windows::Forms::Button^ btnRegCasteller;

		System::ComponentModel::Container^ components;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblDNIcasteller = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtTel = (gcnew System::Windows::Forms::TextBox());
			this->btnRegCasteller = (gcnew System::Windows::Forms::Button());
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
			this->panelHeader->Size = System::Drawing::Size(580, 105);
			this->panelHeader->TabIndex = 0;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.0F, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = AppColors::White;
			this->lblTitulo->Location = System::Drawing::Point(34, 22);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(255, 41);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Datos casteller";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitulo->ForeColor = AppColors::White;
			this->lblSubtitulo->Location = System::Drawing::Point(39, 66);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(300, 17);
			this->lblSubtitulo->TabIndex = 1;
			this->lblSubtitulo->Text = L"Completa los datos de casteller";
			// 
			// panelContenido
			// 
			this->panelContenido->BackColor = AppColors::White;
			this->panelContenido->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelContenido->Controls->Add(this->label1);
			this->panelContenido->Controls->Add(this->lblDNIcasteller);
			this->panelContenido->Controls->Add(this->label3);
			this->panelContenido->Controls->Add(this->txtTel);
			this->panelContenido->Controls->Add(this->btnRegCasteller);
			this->panelContenido->Location = System::Drawing::Point(42, 130);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(496, 230);
			this->panelContenido->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = AppColors::Black;
			this->label1->Location = System::Drawing::Point(42, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"DNI";
			// 
			// lblDNIcasteller
			// 
			this->lblDNIcasteller->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.0F));
			this->lblDNIcasteller->ForeColor = AppColors::Black;
			this->lblDNIcasteller->Location = System::Drawing::Point(220, 40);
			this->lblDNIcasteller->Name = L"lblDNIcasteller";
			this->lblDNIcasteller->Size = System::Drawing::Size(230, 25);
			this->lblDNIcasteller->TabIndex = 1;
			this->lblDNIcasteller->Text = L"";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = AppColors::Black;
			this->label3->Location = System::Drawing::Point(42, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Telefono";
			// 
			// txtTel
			// 
			this->txtTel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtTel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.0F));
			this->txtTel->Location = System::Drawing::Point(220, 88);
			this->txtTel->Name = L"txtTel";
			this->txtTel->Size = System::Drawing::Size(230, 25);
			this->txtTel->TabIndex = 0;
			// 
			// btnRegCasteller
			// 
			this->btnRegCasteller->Location = System::Drawing::Point(220, 148);
			this->btnRegCasteller->Name = L"btnRegCasteller";
			this->btnRegCasteller->Size = System::Drawing::Size(230, 42);
			this->btnRegCasteller->TabIndex = 1;
			this->btnRegCasteller->Text = L"Guardar casteller";
			this->btnRegCasteller->UseVisualStyleBackColor = false;
			this->btnRegCasteller->Click += gcnew System::EventHandler(this, &RegisterCastellerForm::btnRegCasteller_Click);
			ConfigurarBotonPrincipal(this->btnRegCasteller);
			// 
			// RegisterCastellerForm
			// 
			this->AcceptButton = this->btnRegCasteller;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = AppColors::Background;
			this->ClientSize = System::Drawing::Size(580, 395);
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelHeader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"RegisterCastellerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Datos casteller";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void btnRegCasteller_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ telefon = txtTel->Text;

		if (String::IsNullOrWhiteSpace(telefon))
		{
			telefon = nullptr;
		}

		ctrl->registrarCasteller(dniCasteller, telefon);

		MessageBox::Show("Casteller registrado correctamente", "Registro completado", MessageBoxButtons::OK, MessageBoxIcon::Information);

		this->Close();
	}
	};
}
