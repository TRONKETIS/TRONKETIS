#pragma once

#include "CtrlAfegirMembreColla.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuCapColla : public System::Windows::Forms::Form
	{
	public:
		MenuCapColla(void)
		{
			InitializeComponent();
		}

	protected:
		~MenuCapColla()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(83, 92);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(30, 16);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"DNI";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(83, 132);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(38, 16);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Colla";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(83, 172);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(70, 16);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"Universitat";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(120, 250);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(120, 30);
			   this->button1->TabIndex = 3;
			   this->button1->Text = L"Afegir membre";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MenuCapColla::button1_Click);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(186, 89);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(180, 22);
			   this->textBox1->TabIndex = 5;
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(186, 129);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(180, 22);
			   this->textBox2->TabIndex = 6;
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(186, 169);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(180, 22);
			   this->textBox3->TabIndex = 7;
			   // 
			   // MenuCapColla
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(547, 470);
			   this->Controls->Add(this->textBox3);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Name = L"MenuCapColla";
			   this->Text = L"Menu Cap de Colla";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = textBox1->Text->Trim();
		String^ collaName = textBox2->Text->Trim();
		String^ uniName = textBox3->Text->Trim();

		String^ error = "";
		bool ok = CtrlAfegirMembreColla::afegirMembre(dni, collaName, uniName, error);

		if (ok) {
			MessageBox::Show("Membre afegit correctament", "Èxit",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show(error, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	/*private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = textBox1->Text->Trim();
		String^ collaName = textBox2->Text->Trim();
		String^ uniName = textBox3->Text->Trim();

		String^ error = "";
		bool ok = CtrlGestionarMembresColla::eliminarMembre(dni, collaName, uniName, error);

		if (ok) {
			MessageBox::Show("Membre eliminat correctament", "Èxit",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show(error, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}*/
	};
}