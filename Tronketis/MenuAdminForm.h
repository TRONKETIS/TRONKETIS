#pragma once
#include "AppColors.h"
#include "CtrlAdminMenu.h"
#include "RegistrarForm.h"
#include "InhabilitarUsuarioForm.h"
#include "AsignarCapForm.h"

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
		// Constructor por defecto
		MenuAdminForm(void)
		{
			InitializeComponent();
			ConfigurarBotones();
		}

		// Constructor con nombre de admin (el que usa tu login)
		MenuAdminForm(String^ adminName)
		{
			InitializeComponent();
			lblAdminName->Text = adminName;
			ConfigurarBotones();
		}

	private:
		// Función auxiliar para no repetir código de colores
		void ConfigurarBotones() {
			// Registrar Usuario
			this->btnGoToRegUser->BackColor = AppColors::Yellow;
			this->btnGoToRegUser->ForeColor = AppColors::Black;
			this->btnGoToRegUser->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
			this->btnGoToRegUser->FlatAppearance->MouseDownBackColor = AppColors::Black;

			// Borrar Usuario
			this->btnGoToDelUser->BackColor = AppColors::Yellow;
			this->btnGoToDelUser->ForeColor = AppColors::Black;
			this->btnGoToDelUser->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
			this->btnGoToDelUser->FlatAppearance->MouseDownBackColor = AppColors::Black;

			// Asignar Cap
			this->btnGoToAsignarCap->BackColor = AppColors::Yellow;
			this->btnGoToAsignarCap->ForeColor = AppColors::Black;
			this->btnGoToAsignarCap->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
			this->btnGoToAsignarCap->FlatAppearance->MouseDownBackColor = AppColors::Black;
		}

	protected:
		~MenuAdminForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblWelcom;
	private: System::Windows::Forms::Label^ lblAdminName;
	private: System::Windows::Forms::Button^ btnGoToRegUser;
	private: System::Windows::Forms::Button^ btnGoToDelUser;
	private: System::Windows::Forms::Button^ btnGoToAsignarCap;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuAdminForm::typeid));
			this->lblWelcom = (gcnew System::Windows::Forms::Label());
			this->lblAdminName = (gcnew System::Windows::Forms::Label());
			this->btnGoToRegUser = (gcnew System::Windows::Forms::Button());
			this->btnGoToDelUser = (gcnew System::Windows::Forms::Button());
			this->btnGoToAsignarCap = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblWelcom
			// 
			this->lblWelcom->AutoSize = true;
			this->lblWelcom->Location = System::Drawing::Point(184, 69);
			this->lblWelcom->Name = L"lblWelcom";
			this->lblWelcom->Size = System::Drawing::Size(124, 16);
			this->lblWelcom->TabIndex = 0;
			this->lblWelcom->Text = L"Bienvenid@ admin ";
			// 
			// lblAdminName
			// 
			this->lblAdminName->AutoSize = true;
			this->lblAdminName->Location = System::Drawing::Point(308, 69);
			this->lblAdminName->Name = L"lblAdminName";
			this->lblAdminName->Size = System::Drawing::Size(85, 16);
			this->lblAdminName->TabIndex = 1;
			this->lblAdminName->Text = L"admin_name";
			// 
			// btnGoToRegUser
			// 
			this->btnGoToRegUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold));
			this->btnGoToRegUser->Location = System::Drawing::Point(187, 123);
			this->btnGoToRegUser->Name = L"btnGoToRegUser";
			this->btnGoToRegUser->Size = System::Drawing::Size(206, 36);
			this->btnGoToRegUser->TabIndex = 2;
			this->btnGoToRegUser->Text = L"Registrar Usuario";
			this->btnGoToRegUser->UseVisualStyleBackColor = false;
			this->btnGoToRegUser->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToRegUser_Click);
			// 
			// btnGoToDelUser
			// 
			this->btnGoToDelUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold));
			this->btnGoToDelUser->Location = System::Drawing::Point(187, 178);
			this->btnGoToDelUser->Name = L"btnGoToDelUser";
			this->btnGoToDelUser->Size = System::Drawing::Size(206, 36);
			this->btnGoToDelUser->TabIndex = 3;
			this->btnGoToDelUser->Text = L"Borrar Usuario";
			this->btnGoToDelUser->UseVisualStyleBackColor = false;
			this->btnGoToDelUser->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToDelUser_Click);
			// 
			// btnGoToAsignarCap
			// 
			this->btnGoToAsignarCap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold));
			this->btnGoToAsignarCap->Location = System::Drawing::Point(187, 233);
			this->btnGoToAsignarCap->Name = L"btnGoToAsignarCap";
			this->btnGoToAsignarCap->Size = System::Drawing::Size(206, 36);
			this->btnGoToAsignarCap->TabIndex = 4;
			this->btnGoToAsignarCap->Text = L"Asignar Cap de Colla";
			this->btnGoToAsignarCap->UseVisualStyleBackColor = false;
			this->btnGoToAsignarCap->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToAsignarCap_Click);
			// 
			// MenuAdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 443);
			this->Controls->Add(this->btnGoToAsignarCap);
			this->Controls->Add(this->btnGoToDelUser);
			this->Controls->Add(this->btnGoToRegUser);
			this->Controls->Add(this->lblAdminName);
			this->Controls->Add(this->lblWelcom);
			this->Name = L"MenuAdminForm";
			this->Text = L"MenuAdminForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnGoToRegUser_Click(System::Object^ sender, System::EventArgs^ e) {
		RegistrarForm^ form = gcnew RegistrarForm();
		form->ShowDialog();
	}

	private: System::Void btnGoToDelUser_Click(System::Object^ sender, System::EventArgs^ e) {
		InhabilitarUsuarioForm^ form = gcnew InhabilitarUsuarioForm();
		form->ShowDialog();
	}

	private: System::Void btnGoToAsignarCap_Click(System::Object^ sender, System::EventArgs^ e) {
		AsignarCapForm^ form = gcnew AsignarCapForm();
		form->ShowDialog();
	}
	};
}