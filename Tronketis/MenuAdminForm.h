#pragma once

#include "AppColors.h"
#include "CtrlAdminMenu.h"
#include "RegistrarForm.h"
#include "InhabilitarUsuarioForm.h"
#include "AsignarCapForm.h"
#include "ModificarUsuariForm.h"
#include "ResumAssistenciaDiadaForm.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuAdminForm
	/// </summary>
	public ref class MenuAdminForm : public System::Windows::Forms::Form
	{
	public:
		// Constructor por defecto
		MenuAdminForm(void)
		{
			InitializeComponent();
			ConfigurarEstiloBotones();
			ConfigurarBotones();
		}

		// Constructor con nombre de admin
		MenuAdminForm(String^ adminName)
		{
			InitializeComponent();
			lblAdminName->Text = adminName;
			ConfigurarEstiloBotones();
			ConfigurarBotones();
		}

	private:
		// Aplica el estilo base a los botones compartidos
		void ConfigurarEstiloBotones()
		{
			cli::array<Button^>^ botones = { btnGoToRegUser, btnGoToDelUser, button1, btnGoToAsignarCap, btnResumAssistencia };

			for each (Button ^ btn in botones) {
				if (btn != nullptr) {
					btn->BackColor = AppColors::DarkRed;
					btn->ForeColor = AppColors::White;
					btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					btn->FlatAppearance->BorderSize = 0;
					btn->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
					btn->FlatAppearance->MouseDownBackColor = AppColors::Black;
					btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold));

					// Suscribir a los eventos Hover
					btn->MouseEnter += gcnew EventHandler(this, &MenuAdminForm::OnHoverEnter);
					btn->MouseLeave += gcnew EventHandler(this, &MenuAdminForm::OnHoverLeave);
				}
			}
		}

		// Configuración específica de colores que venía de la otra feature
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

			// Modificar Usuario
			this->button1->BackColor = AppColors::Yellow;
			this->button1->ForeColor = AppColors::Black;
			this->button1->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
			this->button1->FlatAppearance->MouseDownBackColor = AppColors::Black;

			// Consultar assistencia de una diada
			this->btnResumAssistencia->BackColor = AppColors::Yellow;
			this->btnResumAssistencia->ForeColor = AppColors::Black;
			this->btnResumAssistencia->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
			this->btnResumAssistencia->FlatAppearance->MouseDownBackColor = AppColors::Black;
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
		System::Windows::Forms::Button^ btnGoToAsignarCap;
		System::Windows::Forms::Button^ button1; // Botón de Modificar Usuario
		System::Windows::Forms::Button^ btnResumAssistencia;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblWelcom = (gcnew System::Windows::Forms::Label());
			this->lblAdminName = (gcnew System::Windows::Forms::Label());
			this->btnGoToRegUser = (gcnew System::Windows::Forms::Button());
			this->btnGoToDelUser = (gcnew System::Windows::Forms::Button());
			this->btnGoToAsignarCap = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnResumAssistencia = (gcnew System::Windows::Forms::Button());
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
			// btnGoToAsignarCap
			// 
			this->btnGoToAsignarCap->Location = System::Drawing::Point(140, 235);
			this->btnGoToAsignarCap->Name = L"btnGoToAsignarCap";
			this->btnGoToAsignarCap->Size = System::Drawing::Size(154, 29);
			this->btnGoToAsignarCap->Text = L"Asignar Cap de Colla";
			this->btnGoToAsignarCap->UseVisualStyleBackColor = false;
			this->btnGoToAsignarCap->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToAsignarCap_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(140, 190);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 29);
			this->button1->Text = L"Modificar Usuario";
			this->button1->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToModUser_Click);
			// 
			// btnResumAssistencia
			// 
			this->btnResumAssistencia->Location = System::Drawing::Point(140, 280);
			this->btnResumAssistencia->Name = L"btnResumAssistencia";
			this->btnResumAssistencia->Size = System::Drawing::Size(154, 29);
			this->btnResumAssistencia->Text = L"Resum Assistencia";
			this->btnResumAssistencia->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnResumAssistencia_Click);
			// 
			// MenuAdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 360);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnGoToAsignarCap);
			this->Controls->Add(this->btnGoToDelUser);
			this->Controls->Add(this->btnGoToRegUser);
			this->Controls->Add(this->lblAdminName);
			this->Controls->Add(this->lblWelcom);
			this->Controls->Add(this->btnResumAssistencia);
			this->Name = L"MenuAdminForm";
			this->Text = L"Menu Admin";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void OnHoverEnter(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ btn = dynamic_cast<Button^>(sender);
			if (btn != nullptr) btn->ForeColor = AppColors::Black;
		}

		System::Void OnHoverLeave(System::Object^ sender, System::EventArgs^ e)
		{
			Button^ btn = dynamic_cast<Button^>(sender);
			if (btn != nullptr) btn->ForeColor = AppColors::White;
		}

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

		System::Void btnGoToAsignarCap_Click(System::Object^ sender, System::EventArgs^ e) {
			AsignarCapForm^ form = gcnew AsignarCapForm();
			form->ShowDialog();
		}

		System::Void btnResumAssistencia_Click(System::Object^ sender, System::EventArgs^ e) {
			ResumAssistenciaDiadaForm^ form = gcnew ResumAssistenciaDiadaForm();
			form->ShowDialog();
		}

		System::Void MenuAdminForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	};
}