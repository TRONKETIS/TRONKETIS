#pragma once
#include "CtrlAdminMenu.h"
namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InhabilitarUsuarioForm
	/// </summary>
	public ref class InhabilitarUsuarioForm : public System::Windows::Forms::Form
	{
	public:
		InhabilitarUsuarioForm(void)
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
		~InhabilitarUsuarioForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtDniAInhab;
	private: System::Windows::Forms::Button^ btnInhabOk;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtDniAInhab = (gcnew System::Windows::Forms::TextBox());
			this->btnInhabOk = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(135, 136);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(294, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Introduce el dni de usuario a inhabilitar";
			// 
			// txtDniAInhab
			// 
			this->txtDniAInhab->Location = System::Drawing::Point(189, 195);
			this->txtDniAInhab->Name = L"txtDniAInhab";
			this->txtDniAInhab->Size = System::Drawing::Size(194, 22);
			this->txtDniAInhab->TabIndex = 1;
			// 
			// btnInhabOk
			// 
			this->btnInhabOk->BackColor = System::Drawing::Color::OrangeRed;
			this->btnInhabOk->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInhabOk->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnInhabOk->Location = System::Drawing::Point(231, 257);
			this->btnInhabOk->Name = L"btnInhabOk";
			this->btnInhabOk->Size = System::Drawing::Size(108, 38);
			this->btnInhabOk->TabIndex = 2;
			this->btnInhabOk->Text = L"Inhabilitar";
			this->btnInhabOk->UseVisualStyleBackColor = false;
			this->btnInhabOk->Click += gcnew System::EventHandler(this, &InhabilitarUsuarioForm::btnInhabOk_Click);
			// 
			// InhabilitarUsuarioForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 443);
			this->Controls->Add(this->btnInhabOk);
			this->Controls->Add(this->txtDniAInhab);
			this->Controls->Add(this->label1);
			this->Name = L"InhabilitarUsuarioForm";
			this->Text = L"InhabilitarUsuarioForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btnInhabOk_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ dni = txtDniAInhab->Text;

			if (String::IsNullOrWhiteSpace(dni))
			{
				MessageBox::Show("Introduce un DNI");
				return;
			}
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(
				"¿Seguro que quieres inhabilitar este usuario?",
				"Confirmación",
				MessageBoxButtons::OKCancel,
				MessageBoxIcon::Warning
			);

			if (result == System::Windows::Forms::DialogResult::OK)
			{
				
				bool ok = CtrlAdminMenu::InhabilitarUsuario(dni);

				
				if (ok)
				{
					MessageBox::Show("Usuario inhabilitado correctamente");
					this->Close();
				}
				else
				{
					MessageBox::Show("No se encontró el usuario o ya estaba inactivo");
				}
			}else{
				return;
			}



		}
	
};
}
