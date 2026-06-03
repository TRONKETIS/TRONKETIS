#pragma once

#include "AfegirMembresForm.h"
#include "EliminarMembreForm.h"
#include "UiStyle.h"

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

	private: System::Windows::Forms::Panel^ panelHeader;
	private: System::Windows::Forms::Panel^ panelContenido;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblSubtitulo;
	private: System::Windows::Forms::Label^ lblCollaActual;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblCollaActual = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 560, 430, L"Gestio Membres Colla");
			UiStyle::ApplyHeader(this->panelHeader, this->label1, this->lblSubtitulo, 560, L"Gestio Membres", L"Afegir o eliminar membres de la colla");
			UiStyle::ApplyCard(this->panelContenido, 45, 122, 470, 255);

			UiStyle::ApplyValueLabel(this->lblCollaActual);
			this->lblCollaActual->Location = System::Drawing::Point(32, 28);
			this->lblCollaActual->Name = L"lblCollaActual";
			this->lblCollaActual->Text = L"Colla:";

			UiStyle::ApplyButton(this->button1);
			this->button1->Location = System::Drawing::Point(32, 74);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(406, 44);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Afegir Membre";
			this->button1->Click += gcnew System::EventHandler(this, &GestioMembresForm::button1_Click);

			UiStyle::ApplyDangerButton(this->button2);
			this->button2->Location = System::Drawing::Point(32, 128);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(406, 44);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Eliminar Membre";
			this->button2->Click += gcnew System::EventHandler(this, &GestioMembresForm::button2_Click);

			UiStyle::ApplySecondaryButton(this->button3);
			this->button3->Location = System::Drawing::Point(32, 188);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(406, 38);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Tornar";
			this->button3->Click += gcnew System::EventHandler(this, &GestioMembresForm::button3_Click);

			this->panelHeader->Controls->Add(this->label1);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelContenido->Controls->Add(this->lblCollaActual);
			this->panelContenido->Controls->Add(this->button1);
			this->panelContenido->Controls->Add(this->button2);
			this->panelContenido->Controls->Add(this->button3);
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->panelContenido);
			this->Name = L"GestioMembresForm";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
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
