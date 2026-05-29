#pragma once
#include "CercadorDiada.h"
#include "CercadorCasteller.h"
#include "CtrlRegistrarAssistencia.h"
namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegistrarAssistenciaForm
	/// </summary>
	public ref class RegistrarAssistenciaForm : public System::Windows::Forms::Form
	{

	private:
		List<DiadaDTO^>^ diades;
		List<CastellerDTO^>^ castellers;

	public:
		RegistrarAssistenciaForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//


			diades = CercadorDiada::obtenirTotes();

			for each (DiadaDTO ^ d in diades)
			{
				cmbDiades->Items->Add(
					d->nom + " - " +
					d->data.ToString()
				);
			}

			castellers =
				CercadorCasteller::obtenirTots();

			for each (CastellerDTO ^ c in castellers)
			{
				cmbCastellers->Items->Add(
					c->dniCasteller + " - " +
					c->nomUsuari
				);
			}

			cmbEstat->Items->Add("Apuntat");
			cmbEstat->Items->Add("Confirmat");
			cmbEstat->Items->Add("Cancelat");


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegistrarAssistenciaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cmbDiades;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cmbCastellers;
	private: System::Windows::Forms::ComboBox^ cmbEstat;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnRegistrar;
	private: System::Windows::Forms::Label^ lblMissatge;
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
			this->cmbDiades = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmbCastellers = (gcnew System::Windows::Forms::ComboBox());
			this->cmbEstat = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(233, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(267, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Registrar assstencia";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cmbDiades
			// 
			this->cmbDiades->FormattingEnabled = true;
			this->cmbDiades->Location = System::Drawing::Point(431, 129);
			this->cmbDiades->Name = L"cmbDiades";
			this->cmbDiades->Size = System::Drawing::Size(177, 24);
			this->cmbDiades->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(191, 129);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Diada:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(191, 201);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Casteller:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cmbCastellers
			// 
			this->cmbCastellers->FormattingEnabled = true;
			this->cmbCastellers->Location = System::Drawing::Point(431, 200);
			this->cmbCastellers->Name = L"cmbCastellers";
			this->cmbCastellers->Size = System::Drawing::Size(177, 24);
			this->cmbCastellers->TabIndex = 4;
			// 
			// cmbEstat
			// 
			this->cmbEstat->FormattingEnabled = true;
			this->cmbEstat->Location = System::Drawing::Point(431, 268);
			this->cmbEstat->Name = L"cmbEstat";
			this->cmbEstat->Size = System::Drawing::Size(177, 24);
			this->cmbEstat->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(191, 269);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 23);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Estado:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->BackColor = System::Drawing::Color::DarkSalmon;
			this->btnRegistrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegistrar->Location = System::Drawing::Point(431, 342);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(176, 38);
			this->btnRegistrar->TabIndex = 7;
			this->btnRegistrar->Text = L"Registrar Asistencia";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &RegistrarAssistenciaForm::btnRegistrar_Click);
			// 
			// lblMissatge
			// 
			this->lblMissatge->BackColor = System::Drawing::SystemColors::ControlLight;
			this->lblMissatge->Location = System::Drawing::Point(194, 421);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Size = System::Drawing::Size(413, 38);
			this->lblMissatge->TabIndex = 8;
			this->lblMissatge->Text = L"label5";
			this->lblMissatge->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RegistrarAssistenciaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(765, 526);
			this->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->btnRegistrar);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->cmbEstat);
			this->Controls->Add(this->cmbCastellers);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cmbDiades);
			this->Controls->Add(this->label1);
			this->Name = L"RegistrarAssistenciaForm";
			this->Text = L"RegistrarAssistenciaForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cmbDiades->SelectedIndex < 0)
		{
			MessageBox::Show("Selecciona una diada");
			return;
		}

		if (cmbCastellers->SelectedIndex < 0)
		{
			MessageBox::Show("Selecciona un casteller");
			return;
		}

		if (cmbEstat->SelectedIndex < 0)
		{
			MessageBox::Show("Selecciona un estat");
			return;
		}

		DiadaDTO^ diada =
			diades[cmbDiades->SelectedIndex];

		CastellerDTO^ casteller =
			castellers[cmbCastellers->SelectedIndex];

		ParticipacioDiadaDTO^ dto =
			gcnew ParticipacioDiadaDTO();

		dto->diadaName = diada->nom;
		dto->dateDiada = diada->data;
		dto->dni = casteller->dniCasteller;
		dto->estat =
			cmbEstat->SelectedItem->ToString();

		String^ error;

		bool ok =
			CtrlRegistrarAssistencia::executar(
				dto,
				error
			);

		if (ok)
		{
			lblMissatge->ForeColor =
				Color::Green;

			lblMissatge->Text =
				"Assistència registrada";

			MessageBox::Show(
				"Operació correcta"
			);
		}
		else
		{
			lblMissatge->ForeColor =
				Color::Red;

			lblMissatge->Text = error;

			MessageBox::Show(error);
		}
	}
};
}
