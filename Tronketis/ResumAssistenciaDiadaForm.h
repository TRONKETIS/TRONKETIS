#pragma once

#include "CercadorDiada.h"
#include "CtrlResumAssistenciaDiada.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ResumAssistenciaDiadaForm : public System::Windows::Forms::Form
	{
	private:
		List<DiadaDTO^>^ diades;

	private: System::Windows::Forms::Label^ lblTitol;
	private: System::Windows::Forms::Label^ lblDiada;
	private: System::Windows::Forms::ComboBox^ cmbDiades;
	private: System::Windows::Forms::DataGridView^ dgvParticipants;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Button^ btnTancar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;

	private:
		System::ComponentModel::Container^ components;

	public:
		ResumAssistenciaDiadaForm(void)
		{
			InitializeComponent();
			carregarDiades();
		}

	protected:
		~ResumAssistenciaDiadaForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblDiada = (gcnew System::Windows::Forms::Label());
			this->cmbDiades = (gcnew System::Windows::Forms::ComboBox());
			this->dgvParticipants = (gcnew System::Windows::Forms::DataGridView());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->btnTancar = (gcnew System::Windows::Forms::Button());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvParticipants))->BeginInit();
			this->SuspendLayout();
			// 
			// lblTitol
			// 
			this->lblTitol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitol->Location = System::Drawing::Point(180, 25);
			this->lblTitol->Name = L"lblTitol";
			this->lblTitol->Size = System::Drawing::Size(360, 40);
			this->lblTitol->TabIndex = 0;
			this->lblTitol->Text = L"Resum assistència diada";
			this->lblTitol->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblDiada
			// 
			this->lblDiada->Location = System::Drawing::Point(90, 95);
			this->lblDiada->Name = L"lblDiada";
			this->lblDiada->Size = System::Drawing::Size(100, 25);
			this->lblDiada->TabIndex = 1;
			this->lblDiada->Text = L"Diada:";
			this->lblDiada->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cmbDiades
			// 
			this->cmbDiades->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDiades->FormattingEnabled = true;
			this->cmbDiades->Location = System::Drawing::Point(220, 96);
			this->cmbDiades->Name = L"cmbDiades";
			this->cmbDiades->Size = System::Drawing::Size(400, 24);
			this->cmbDiades->TabIndex = 2;
			this->cmbDiades->SelectedIndexChanged += gcnew System::EventHandler(this, &ResumAssistenciaDiadaForm::cmbDiades_SelectedIndexChanged);
			// 
			// dgvParticipants
			// 
			this->dgvParticipants->AllowUserToAddRows = false;
			this->dgvParticipants->AllowUserToDeleteRows = false;
			this->dgvParticipants->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvParticipants->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvParticipants->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->dgvParticipants->Location = System::Drawing::Point(90, 155);
			this->dgvParticipants->Name = L"dgvParticipants";
			this->dgvParticipants->ReadOnly = true;
			this->dgvParticipants->RowHeadersVisible = false;
			this->dgvParticipants->RowHeadersWidth = 51;
			this->dgvParticipants->RowTemplate->Height = 24;
			this->dgvParticipants->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvParticipants->Size = System::Drawing::Size(600, 303);
			this->dgvParticipants->TabIndex = 3;
			// 
			// lblTotal
			// 
			this->lblTotal->BackColor = System::Drawing::SystemColors::ControlLight;
			this->lblTotal->Location = System::Drawing::Point(90, 480);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(464, 35);
			this->lblTotal->TabIndex = 4;
			this->lblTotal->Text = L"Selecciona una diada";
			this->lblTotal->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnTancar
			// 
			this->btnTancar->Location = System::Drawing::Point(590, 480);
			this->btnTancar->Name = L"btnTancar";
			this->btnTancar->Size = System::Drawing::Size(100, 35);
			this->btnTancar->TabIndex = 5;
			this->btnTancar->Text = L"Tancar";
			this->btnTancar->UseVisualStyleBackColor = true;
			this->btnTancar->Click += gcnew System::EventHandler(this, &ResumAssistenciaDiadaForm::btnTancar_Click);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"DNI";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Nom casteller";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Estat";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			// 
			// ResumAssistenciaDiadaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 550);
			this->Controls->Add(this->btnTancar);
			this->Controls->Add(this->lblTotal);
			this->Controls->Add(this->dgvParticipants);
			this->Controls->Add(this->cmbDiades);
			this->Controls->Add(this->lblDiada);
			this->Controls->Add(this->lblTitol);
			this->Name = L"ResumAssistenciaDiadaForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Resum Assistència Diada";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvParticipants))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:
		void carregarDiades()
		{
			diades = CercadorDiada::obtenirTotes();

			cmbDiades->Items->Clear();

			for each (DiadaDTO ^ d in diades)
			{
				cmbDiades->Items->Add(
					d->nom + " - " +
					d->data.ToString("dd/MM/yyyy HH:mm")
				);
			}

			if (cmbDiades->Items->Count > 0)
			{
				cmbDiades->SelectedIndex = 0;
			}
			else
			{
				lblTotal->Text = "No hi ha diades registrades";
			}
		}

		void carregarParticipants()
		{
			if (cmbDiades->SelectedIndex < 0)
			{
				return;
			}

			DiadaDTO^ diada =
				diades[cmbDiades->SelectedIndex];

			List<ParticipantDiadaDTO^>^ participants =
				CtrlResumAssistenciaDiada::obtenirParticipants(
					diada->nom,
					diada->data
				);

			dgvParticipants->Rows->Clear();

			for each (ParticipantDiadaDTO ^ p in participants)
			{
				dgvParticipants->Rows->Add(
					p->dni,
					p->nomUsuari,
					p->estat
				);
			}

			lblTotal->Text =
				"Total participants: " +
				participants->Count.ToString();
		}

	private:
		System::Void cmbDiades_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			carregarParticipants();
		}

		System::Void btnTancar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
	};
}