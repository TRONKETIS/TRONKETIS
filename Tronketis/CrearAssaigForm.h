#pragma once

#include "CtrlCrearAssaig.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CrearAssaigForm : public System::Windows::Forms::Form
	{
	public:
		CrearAssaigForm(String^ collaName, String^ collaUniName)
		{
			this->collaName = collaName;
			this->collaUniName = collaUniName;
			InitializeComponent();
			ConfigurarValidacions();
		}

	protected:
		~CrearAssaigForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		String^ collaName;
		String^ collaUniName;
		System::Windows::Forms::DateTimePicker^ dtpDataHora;
		System::Windows::Forms::Label^ lblTitol;
		System::Windows::Forms::Label^ lblDataHora;
		System::Windows::Forms::Button^ btnCrearAssaig;
		System::Windows::Forms::Button^ btnCancelar;
		System::Windows::Forms::Label^ lblMissatge;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dtpDataHora = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblDataHora = (gcnew System::Windows::Forms::Label());
			this->btnCrearAssaig = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// dtpDataHora
			// 
			this->dtpDataHora->CustomFormat = L"dd/MM/yyyy HH:mm";
			this->dtpDataHora->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtpDataHora->Location = System::Drawing::Point(150, 100);
			this->dtpDataHora->Name = L"dtpDataHora";
			this->dtpDataHora->Size = System::Drawing::Size(200, 22);
			this->dtpDataHora->TabIndex = 0;
			// 
			// lblTitol
			// 
			this->lblTitol->AutoSize = true;
			this->lblTitol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->lblTitol->Location = System::Drawing::Point(110, 30);
			this->lblTitol->Name = L"lblTitol";
			this->lblTitol->Size = System::Drawing::Size(200, 29);
			this->lblTitol->TabIndex = 1;
			this->lblTitol->Text = L"Crear Nou Assaig";
			this->lblTitol->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblDataHora
			// 
			this->lblDataHora->AutoSize = true;
			this->lblDataHora->Location = System::Drawing::Point(50, 105);
			this->lblDataHora->Name = L"lblDataHora";
			this->lblDataHora->Size = System::Drawing::Size(87, 16);
			this->lblDataHora->TabIndex = 2;
			this->lblDataHora->Text = L"Data i Hora:";
			// 
			// btnCrearAssaig
			// 
			this->btnCrearAssaig->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnCrearAssaig->ForeColor = System::Drawing::Color::White;
			this->btnCrearAssaig->Location = System::Drawing::Point(80, 160);
			this->btnCrearAssaig->Name = L"btnCrearAssaig";
			this->btnCrearAssaig->Size = System::Drawing::Size(120, 35);
			this->btnCrearAssaig->TabIndex = 3;
			this->btnCrearAssaig->Text = L"Crear Assaig";
			this->btnCrearAssaig->UseVisualStyleBackColor = false;
			this->btnCrearAssaig->Click += gcnew System::EventHandler(this, &CrearAssaigForm::btnCrearAssaig_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(230, 160);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(100, 35);
			this->btnCancelar->TabIndex = 4;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &CrearAssaigForm::btnCancelar_Click);
			// 
			// lblMissatge
			// 
			this->lblMissatge->AutoSize = true;
			this->lblMissatge->Location = System::Drawing::Point(50, 210);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Size = System::Drawing::Size(0, 16);
			this->lblMissatge->TabIndex = 5;
			// 
			// CrearAssaigForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 261);
			this->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnCrearAssaig);
			this->Controls->Add(this->lblDataHora);
			this->Controls->Add(this->lblTitol);
			this->Controls->Add(this->dtpDataHora);
			this->Name = L"CrearAssaigForm";
			this->Text = L"Crear Assaig";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void ConfigurarValidacions()
		{
			// Evitar que el usuari pogui escollir dates anteriors a avui des del component
			dtpDataHora->MinDate = DateTime::Today;
		}

		System::Void btnCrearAssaig_Click(System::Object^ sender, System::EventArgs^ e) {

			DateTime selectedDate = dtpDataHora->Value;

			String^ resultat = CtrlCrearAssaig::CrearAssaig(selectedDate, collaName, collaUniName);

			if (resultat->StartsWith("Error"))
			{
				lblMissatge->ForeColor = System::Drawing::Color::Red;
				lblMissatge->Text = resultat;
			}
			else
			{
				lblMissatge->ForeColor = System::Drawing::Color::Green;
				lblMissatge->Text = resultat;
				MessageBox::Show(resultat, "Èxit", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
		}

		System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
