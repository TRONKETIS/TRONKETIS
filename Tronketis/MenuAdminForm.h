#pragma once
#include "AppColors.h"
#include "CtrlAdminMenu.h"
#include "RegistrarForm.h"
#include "InhabilitarUsuarioForm.h"
#include "ModificarUsuariForm.h"

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
			ConfigurarEstiloBotones();
		}

		MenuAdminForm(String^ adminName)
		{
			InitializeComponent();
			lblAdminName->Text = adminName;
			ConfigurarEstiloBotones();
		}

	private:
		// Método para no repetir código de estilos en los dos constructores
		void ConfigurarEstiloBotones()
		{
			// Array con todos los botones para aplicarles lo mismo
			cli::array<Button^>^ botones = { btnGoToRegUser, btnGoToDelUser, button1 };

			for each (Button ^ btn in botones) {
				btn->BackColor = AppColors::DarkRed;
				btn->ForeColor = AppColors::White;
				btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				btn->FlatAppearance->BorderSize = 0;
				btn->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
				btn->FlatAppearance->MouseDownBackColor = AppColors::Black;

				// Misma fuente para todos (Negrita)
				btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold));

				// Suscribir a los eventos Hover
				btn->MouseEnter += gcnew EventHandler(this, &MenuAdminForm::OnHoverEnter);
				btn->MouseLeave += gcnew EventHandler(this, &MenuAdminForm::OnHoverLeave);
			}
		}

	protected:
		~MenuAdminForm()
		{
			if (components) delete components;
		}

	private:
		System::Windows::Forms::Label^ lblWelcom;
		System::Windows::Forms::Label^ lblAdminName;
		System::Windows::Forms::Button^ btnGoToRegUser;
		System::Windows::Forms::Button^ btnGoToDelUser;
		System::Windows::Forms::Button^ button1;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuAdminForm::typeid));
			this->lblWelcom = (gcnew System::Windows::Forms::Label());
			this->lblAdminName = (gcnew System::Windows::Forms::Label());
			this->btnGoToRegUser = (gcnew System::Windows::Forms::Button());
			this->btnGoToDelUser = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblWelcom
			// 
			this->lblWelcom->AutoSize = true;
			this->lblWelcom->Location = System::Drawing::Point(138, 56);
			this->lblWelcom->Name = L"lblWelcom";
			this->lblWelcom->Size = System::Drawing::Size(99, 13);
			this->lblWelcom->Text = L"Bienvenid@ admin ";
			// 
			// lblAdminName
			// 
			this->lblAdminName->AutoSize = true;
			this->lblAdminName->Location = System::Drawing::Point(231, 56);
			this->lblAdminName->Name = L"lblAdminName";
			this->lblAdminName->Size = System::Drawing::Size(67, 13);
			this->lblAdminName->Text = L"admin_name";
			// 
			// btnGoToRegUser
			// 
			this->btnGoToRegUser->Location = System::Drawing::Point(140, 100);
			this->btnGoToRegUser->Name = L"btnGoToRegUser";
			this->btnGoToRegUser->Size = System::Drawing::Size(154, 29);
			this->btnGoToRegUser->Text = L"Registrar Usuario";
			this->btnGoToRegUser->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToRegUser_Click);
			// 
			// btnGoToDelUser
			// 
			this->btnGoToDelUser->Location = System::Drawing::Point(140, 145);
			this->btnGoToDelUser->Name = L"btnGoToDelUser";
			this->btnGoToDelUser->Size = System::Drawing::Size(154, 29);
			this->btnGoToDelUser->Text = L"Borrar Usuario";
			this->btnGoToDelUser->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToDelUser_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(140, 190);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 29);
			this->button1->Text = L"Modificar Usuario";
			this->button1->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToModUser_Click);
			// 
			// MenuAdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 360);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnGoToDelUser);
			this->Controls->Add(this->btnGoToRegUser);
			this->Controls->Add(this->lblAdminName);
			this->Controls->Add(this->lblWelcom);
			this->Name = L"MenuAdminForm";
			this->Text = L"Menu Admin";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		
	private: System::Void OnHoverEnter(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = dynamic_cast<Button^>(sender);
		if (btn != nullptr) btn->ForeColor = AppColors::Black;
	}

	private: System::Void OnHoverLeave(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = dynamic_cast<Button^>(sender);
		if (btn != nullptr) btn->ForeColor = AppColors::White;
	}

		 
	private: System::Void btnGoToRegUser_Click(System::Object^ sender, System::EventArgs^ e) {
		RegistrarForm^ form = gcnew RegistrarForm();
		form->ShowDialog();
	}

	private: System::Void btnGoToDelUser_Click(System::Object^ sender, System::EventArgs^ e) {
		InhabilitarUsuarioForm^ form = gcnew InhabilitarUsuarioForm();
		form->ShowDialog();
	}

	private: System::Void btnGoToModUser_Click(System::Object^ sender, System::EventArgs^ e) {
		ModificarUsuariForm^ form = gcnew ModificarUsuariForm();
		form->ShowDialog();
	}

	private: System::Void MenuAdminForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	};
}