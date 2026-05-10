#pragma once
#include "CtrlConsultarCastell.h"
namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ConsultarCastellForm
	/// </summary>
	public ref class ConsultarCastellForm : public System::Windows::Forms::Form
	{

	private:

		CtrlConsultarCastell^ ctrl;
	public:
		ConsultarCastellForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			ctrl = gcnew CtrlConsultarCastell();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ConsultarCastellForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ txtNomCastell;
	private: System::Windows::Forms::Button^ btnConsultar;
	private: System::Windows::Forms::DataGridView^ dgvCastells;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colPisos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipus;


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
			this->txtNomCastell = (gcnew System::Windows::Forms::TextBox());
			this->btnConsultar = (gcnew System::Windows::Forms::Button());
			this->dgvCastells = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPisos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCastells))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(78, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nom del castell";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtNomCastell
			// 
			this->txtNomCastell->Location = System::Drawing::Point(268, 81);
			this->txtNomCastell->Name = L"txtNomCastell";
			this->txtNomCastell->Size = System::Drawing::Size(266, 22);
			this->txtNomCastell->TabIndex = 1;
			// 
			// btnConsultar
			// 
			this->btnConsultar->BackColor = System::Drawing::Color::LightCoral;
			this->btnConsultar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnConsultar->Location = System::Drawing::Point(428, 152);
			this->btnConsultar->Name = L"btnConsultar";
			this->btnConsultar->Size = System::Drawing::Size(106, 31);
			this->btnConsultar->TabIndex = 2;
			this->btnConsultar->Text = L"consultar";
			this->btnConsultar->UseVisualStyleBackColor = false;
			this->btnConsultar->Click += gcnew System::EventHandler(this, &ConsultarCastellForm::btnConsultar_Click);
			// 
			// dgvCastells
			// 
			this->dgvCastells->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCastells->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->colId, this->colNom,
					this->colPisos, this->colTipus
			});
			this->dgvCastells->Location = System::Drawing::Point(28, 291);
			this->dgvCastells->Name = L"dgvCastells";
			this->dgvCastells->RowHeadersWidth = 51;
			this->dgvCastells->RowTemplate->Height = 24;
			this->dgvCastells->Size = System::Drawing::Size(552, 147);
			this->dgvCastells->TabIndex = 3;
			// 
			// colId
			// 
			this->colId->HeaderText = L"ID";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			this->colId->Width = 125;
			// 
			// colNom
			// 
			this->colNom->HeaderText = L"Nom";
			this->colNom->MinimumWidth = 6;
			this->colNom->Name = L"colNom";
			this->colNom->Width = 125;
			// 
			// colPisos
			// 
			this->colPisos->HeaderText = L"Pisos";
			this->colPisos->MinimumWidth = 6;
			this->colPisos->Name = L"colPisos";
			this->colPisos->Width = 125;
			// 
			// colTipus
			// 
			this->colTipus->HeaderText = L"Tipus";
			this->colTipus->MinimumWidth = 6;
			this->colTipus->Name = L"colTipus";
			this->colTipus->Width = 125;
			// 
			// ConsultarCastellForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(603, 465);
			this->Controls->Add(this->dgvCastells);
			this->Controls->Add(this->btnConsultar);
			this->Controls->Add(this->txtNomCastell);
			this->Controls->Add(this->label1);
			this->Name = L"ConsultarCastellForm";
			this->Text = L"ConsultarCastellForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCastells))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnConsultar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nom = txtNomCastell->Text;

		List<PasarelaCastell^>^ resultats =
			ctrl->consultarPerNom(nom);

		dgvCastells->Rows->Clear();

		for each (PasarelaCastell ^ c in resultats)
		{
			dgvCastells->Rows->Add(
				c->getId(),
				c->getNom(),
				c->getPisos(),
				c->getTipus()
			);
		}
	}
};
}
