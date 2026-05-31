#pragma once

#include "CercadorDiada.h"
#include "CercadorCastell.h"
#include "CercadorAssignacioCastellDiada.h"
#include "CtrlAssignarCastellDiada.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AssignarCastellsDiadaForm : public System::Windows::Forms::Form
	{
	public:
		AssignarCastellsDiadaForm(String^ collaName)
		{
			InitializeComponent();

			this->collaName = collaName;
			this->diades = gcnew List<DiadaDTO^>();
			this->castells = gcnew List<PasarelaCastell^>();

			lblColla->Text = L"Colla: " + collaName;

			CarregarDiades();
			CarregarCastells();
		}

	protected:
		~AssignarCastellsDiadaForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ collaName;
		List<DiadaDTO^>^ diades;
		List<PasarelaCastell^>^ castells;

	private: System::Windows::Forms::Label^ lblTitol;
	private: System::Windows::Forms::Label^ lblColla;
	private: System::Windows::Forms::Label^ lblDiada;
	private: System::Windows::Forms::Label^ lblCastell;
	private: System::Windows::Forms::ComboBox^ cmbDiades;
	private: System::Windows::Forms::ComboBox^ cmbCastells;
	private: System::Windows::Forms::Button^ btnAssignar;
	private: System::Windows::Forms::Button^ btnTornar;
	private: System::Windows::Forms::Label^ lblMissatge;
	private: System::Windows::Forms::ListBox^ lstCastellsAssignats;
	private: System::Windows::Forms::Label^ lblAssignats;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblColla = (gcnew System::Windows::Forms::Label());
			this->lblDiada = (gcnew System::Windows::Forms::Label());
			this->lblCastell = (gcnew System::Windows::Forms::Label());
			this->cmbDiades = (gcnew System::Windows::Forms::ComboBox());
			this->cmbCastells = (gcnew System::Windows::Forms::ComboBox());
			this->btnAssignar = (gcnew System::Windows::Forms::Button());
			this->btnTornar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->lstCastellsAssignats = (gcnew System::Windows::Forms::ListBox());
			this->lblAssignats = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblTitol
			// 
			this->lblTitol->AutoSize = true;
			this->lblTitol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->lblTitol->Location = System::Drawing::Point(70, 25);
			this->lblTitol->Name = L"lblTitol";
			this->lblTitol->Size = System::Drawing::Size(321, 31);
			this->lblTitol->TabIndex = 0;
			this->lblTitol->Text = L"Assignar castells a diada";
			// 
			// lblColla
			// 
			this->lblColla->AutoSize = true;
			this->lblColla->Location = System::Drawing::Point(40, 75);
			this->lblColla->Name = L"lblColla";
			this->lblColla->Size = System::Drawing::Size(42, 16);
			this->lblColla->TabIndex = 1;
			this->lblColla->Text = L"Colla:";
			// 
			// lblDiada
			// 
			this->lblDiada->AutoSize = true;
			this->lblDiada->Location = System::Drawing::Point(40, 120);
			this->lblDiada->Name = L"lblDiada";
			this->lblDiada->Size = System::Drawing::Size(43, 16);
			this->lblDiada->TabIndex = 2;
			this->lblDiada->Text = L"Diada:";
			// 
			// lblCastell
			// 
			this->lblCastell->AutoSize = true;
			this->lblCastell->Location = System::Drawing::Point(40, 165);
			this->lblCastell->Name = L"lblCastell";
			this->lblCastell->Size = System::Drawing::Size(49, 16);
			this->lblCastell->TabIndex = 3;
			this->lblCastell->Text = L"Castell:";
			// 
			// cmbDiades
			// 
			this->cmbDiades->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDiades->FormattingEnabled = true;
			this->cmbDiades->Location = System::Drawing::Point(120, 117);
			this->cmbDiades->Name = L"cmbDiades";
			this->cmbDiades->Size = System::Drawing::Size(270, 24);
			this->cmbDiades->TabIndex = 4;
			this->cmbDiades->SelectedIndexChanged += gcnew System::EventHandler(this, &AssignarCastellsDiadaForm::cmbDiades_SelectedIndexChanged);
			// 
			// cmbCastells
			// 
			this->cmbCastells->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCastells->FormattingEnabled = true;
			this->cmbCastells->Location = System::Drawing::Point(120, 162);
			this->cmbCastells->Name = L"cmbCastells";
			this->cmbCastells->Size = System::Drawing::Size(270, 24);
			this->cmbCastells->TabIndex = 5;
			// 
			// btnAssignar
			// 
			this->btnAssignar->Location = System::Drawing::Point(120, 215);
			this->btnAssignar->Name = L"btnAssignar";
			this->btnAssignar->Size = System::Drawing::Size(110, 32);
			this->btnAssignar->TabIndex = 6;
			this->btnAssignar->Text = L"Assignar";
			this->btnAssignar->UseVisualStyleBackColor = true;
			this->btnAssignar->Click += gcnew System::EventHandler(this, &AssignarCastellsDiadaForm::btnAssignar_Click);
			// 
			// btnTornar
			// 
			this->btnTornar->Location = System::Drawing::Point(280, 215);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(110, 32);
			this->btnTornar->TabIndex = 7;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->UseVisualStyleBackColor = true;
			this->btnTornar->Click += gcnew System::EventHandler(this, &AssignarCastellsDiadaForm::btnTornar_Click);
			// 
			// lblMissatge
			// 
			this->lblMissatge->AutoSize = true;
			this->lblMissatge->Location = System::Drawing::Point(40, 270);
			this->lblMissatge->MaximumSize = System::Drawing::Size(380, 0);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Size = System::Drawing::Size(0, 16);
			this->lblMissatge->TabIndex = 8;
			// 
			// lblAssignats
			// 
			this->lblAssignats->AutoSize = true;
			this->lblAssignats->Location = System::Drawing::Point(40, 310);
			this->lblAssignats->Name = L"lblAssignats";
			this->lblAssignats->Size = System::Drawing::Size(143, 16);
			this->lblAssignats->TabIndex = 9;
			this->lblAssignats->Text = L"Castells ja assignats:";
			// 
			// lstCastellsAssignats
			// 
			this->lstCastellsAssignats->FormattingEnabled = true;
			this->lstCastellsAssignats->ItemHeight = 16;
			this->lstCastellsAssignats->Location = System::Drawing::Point(43, 340);
			this->lstCastellsAssignats->Name = L"lstCastellsAssignats";
			this->lstCastellsAssignats->Size = System::Drawing::Size(347, 132);
			this->lstCastellsAssignats->TabIndex = 10;
			// 
			// AssignarCastellsDiadaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 500);
			this->Controls->Add(this->lstCastellsAssignats);
			this->Controls->Add(this->lblAssignats);
			this->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->btnTornar);
			this->Controls->Add(this->btnAssignar);
			this->Controls->Add(this->cmbCastells);
			this->Controls->Add(this->cmbDiades);
			this->Controls->Add(this->lblCastell);
			this->Controls->Add(this->lblDiada);
			this->Controls->Add(this->lblColla);
			this->Controls->Add(this->lblTitol);
			this->Name = L"AssignarCastellsDiadaForm";
			this->Text = L"Assignar castells a diada";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		void CarregarDiades()
		{
			cmbDiades->Items->Clear();
			diades->Clear();

			List<DiadaDTO^>^ resultats = CercadorDiada::obtenirDiadesDisponibles();

			for each (DiadaDTO ^ dto in resultats) {
				diades->Add(dto);

				String^ text =
					dto->nom + " - " + dto->data.ToString("dd/MM/yyyy HH:mm");

				cmbDiades->Items->Add(text);
			}

			if (cmbDiades->Items->Count == 0) {
				lblMissatge->ForeColor = Color::Red;
				lblMissatge->Text = L"No hi ha diades disponibles.";
			}
			else {
				lblMissatge->Text = L"";
				cmbDiades->SelectedIndex = 0;
			}
		}

		void CarregarCastells()
		{
			cmbCastells->Items->Clear();
			castells->Clear();

			List<PasarelaCastell^>^ resultats = CercadorCastell::obtenirTots();

			for each (PasarelaCastell ^ p in resultats) {
				castells->Add(p);

				String^ text =
					p->getNom() + " (ID " + p->getId().ToString() + ")";

				cmbCastells->Items->Add(text);
			}
		}

		void CarregarCastellsAssignats()
		{
			lstCastellsAssignats->Items->Clear();

			if (cmbDiades->SelectedIndex < 0) {
				return;
			}

			DiadaDTO^ diadaSeleccionada = diades[cmbDiades->SelectedIndex];

			List<PasarelaCastell^>^ assignats =
				CercadorAssignacioCastellDiada::obtenirCastellsAssignats(
					diadaSeleccionada->nom,
					diadaSeleccionada->data,
					collaName);

			for each (PasarelaCastell ^ p in assignats) {
				String^ text =
					p->getNom() + " (ID " + p->getId().ToString() + ")";
				lstCastellsAssignats->Items->Add(text);
			}
		}

	private: System::Void cmbDiades_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		lblMissatge->Text = L"";
		CarregarCastellsAssignats();
	}

	private: System::Void btnAssignar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ error = "";

		String^ diadaName = "";
		DateTime dateDiada = DateTime::Now;
		int castellId = -1;

		if (cmbDiades->SelectedIndex >= 0) {
			DiadaDTO^ diadaSeleccionada = diades[cmbDiades->SelectedIndex];
			diadaName = diadaSeleccionada->nom;
			dateDiada = diadaSeleccionada->data;
		}

		if (cmbCastells->SelectedIndex >= 0) {
			PasarelaCastell^ castellSeleccionat = castells[cmbCastells->SelectedIndex];
			castellId = castellSeleccionat->getId();
		}

		bool ok = CtrlAssignarCastellDiada::assignarCastell(
			diadaName,
			dateDiada,
			castellId,
			collaName,
			error);

		if (ok) {
			lblMissatge->ForeColor = Color::Green;
			lblMissatge->Text = L"Castell assignat correctament.";
			cmbCastells->SelectedIndex = -1;
			CarregarCastellsAssignats();
		}
		else {
			lblMissatge->ForeColor = Color::Red;
			lblMissatge->Text = error;
		}
	}

	private: System::Void btnTornar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}