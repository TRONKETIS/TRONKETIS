#pragma once

#include "AfegirMembresForm.h"
#include "EliminarMembreForm.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GestioMembresForm : public System::Windows::Forms::Form
	{
	public:
		GestioMembresForm(String^ collaName)
		{
			InitializeComponent();
			this->collaName = collaName;
			lblCollaActual->Text = L"Colla: " + collaName;
		}

	protected:
		~GestioMembresForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ collaName;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblCollaActual;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblCollaActual = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(95, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(250, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Gestió Membres Colla";
			// 
			// lblCollaActual
			// 
			this->lblCollaActual->AutoSize = true;
			this->lblCollaActual->Location = System::Drawing::Point(98, 90);
			this->lblCollaActual->Name = L"lblCollaActual";
			this->lblCollaActual->Size = System::Drawing::Size(42, 16);
			this->lblCollaActual->TabIndex = 1;
			this->lblCollaActual->Text = L"Colla:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(140, 145);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 35);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Afegir Membre";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GestioMembresForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(140, 210);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(170, 35);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Eliminar Membre";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GestioMembresForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(140, 275);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(170, 35);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Tornar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GestioMembresForm::button3_Click);
			// 
			// GestioMembresForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(466, 380);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lblCollaActual);
			this->Controls->Add(this->label1);
			this->Name = L"GestioMembresForm";
			this->Text = L"Gestió Membres Colla";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AfegirMembresForm^ f = gcnew AfegirMembresForm(this->collaName);
		f->ShowDialog();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		EliminarMembreForm^ f = gcnew EliminarMembreForm(this->collaName);
		f->ShowDialog();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}