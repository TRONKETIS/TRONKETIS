#pragma once

#include "CtrlGestioMembreColla.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class EliminarMembreForm : public System::Windows::Forms::Form
	{
	public:
		EliminarMembreForm(void)
		{
			InitializeComponent();
		}

	protected:
		~EliminarMembreForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(80, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(308, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Eliminar Membres Colla";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(70, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"DNI";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(185, 107);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(180, 22);
			this->textBox1->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(110, 270);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 32);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Eliminar membre";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EliminarMembreForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(250, 270);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 32);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Tornar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EliminarMembreForm::button2_Click);
			// 
			// EliminarMembreForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(466, 380);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EliminarMembresForm";
			this->Text = L"Eliminar Membres Colla";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = textBox1->Text->Trim();

		String^ error = "";
		bool ok = CtrlGestioMembreColla::eliminarMembre(dni, error);

		if (ok) {
			MessageBox::Show(L"Membre eliminat correctament");
			textBox1->Clear();
		}
		else {
			MessageBox::Show(error);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
