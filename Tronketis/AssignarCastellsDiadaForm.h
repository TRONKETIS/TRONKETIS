#pragma once

#include "CercadorDiada.h"
#include "CercadorCastell.h"
#include "CercadorAssignacioCastellDiada.h"
#include "CtrlAssignarCastellDiada.h"
#include "UiStyle.h"

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

	private: System::Windows::Forms::Panel^ panelHeader;
	private: System::Windows::Forms::Panel^ panelContenido;
	private: System::Windows::Forms::Label^ lblTitol;
	private: System::Windows::Forms::Label^ lblSubtitulo;
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
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
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
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 640, 620, L"Assignar Castell a Diada");
			UiStyle::ApplyHeader(this->panelHeader, this->lblTitol, this->lblSubtitulo, 640, L"Assignar Castell", L"Relaciona un castell amb una diada");
			UiStyle::ApplyCard(this->panelContenido, 45, 122, 550, 440);

			UiStyle::ApplyValueLabel(this->lblColla);
			this->lblColla->Location = System::Drawing::Point(32, 26);
			this->lblColla->Name = L"lblColla";
			this->lblColla->Text = L"Colla:";

			UiStyle::ApplyLabel(this->lblDiada);
			this->lblDiada->Location = System::Drawing::Point(32, 82);
			this->lblDiada->Name = L"lblDiada";
			this->lblDiada->Text = L"Diada:";

			UiStyle::ApplyCombo(this->cmbDiades, 360);
			this->cmbDiades->Location = System::Drawing::Point(142, 79);
			this->cmbDiades->Name = L"cmbDiades";
			this->cmbDiades->TabIndex = 1;
			this->cmbDiades->SelectedIndexChanged += gcnew System::EventHandler(this, &AssignarCastellsDiadaForm::cmbDiades_SelectedIndexChanged);

			UiStyle::ApplyLabel(this->lblCastell);
			this->lblCastell->Location = System::Drawing::Point(32, 124);
			this->lblCastell->Name = L"lblCastell";
			this->lblCastell->Text = L"Castell:";

			UiStyle::ApplyCombo(this->cmbCastells, 360);
			this->cmbCastells->Location = System::Drawing::Point(142, 121);
			this->cmbCastells->Name = L"cmbCastells";
			this->cmbCastells->TabIndex = 2;

			UiStyle::ApplyButton(this->btnAssignar);
			this->btnAssignar->Location = System::Drawing::Point(32, 176);
			this->btnAssignar->Name = L"btnAssignar";
			this->btnAssignar->Size = System::Drawing::Size(230, 42);
			this->btnAssignar->TabIndex = 3;
			this->btnAssignar->Text = L"Assignar";
			this->btnAssignar->Click += gcnew System::EventHandler(this, &AssignarCastellsDiadaForm::btnAssignar_Click);

			UiStyle::ApplySecondaryButton(this->btnTornar);
			this->btnTornar->Location = System::Drawing::Point(272, 176);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(230, 42);
			this->btnTornar->TabIndex = 4;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->Click += gcnew System::EventHandler(this, &AssignarCastellsDiadaForm::btnTornar_Click);

			UiStyle::ApplyMessage(this->lblMissatge, 470);
			this->lblMissatge->Location = System::Drawing::Point(32, 238);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Text = L"";

			UiStyle::ApplySection(this->lblAssignats);
			this->lblAssignats->Location = System::Drawing::Point(32, 292);
			this->lblAssignats->Name = L"lblAssignats";
			this->lblAssignats->Text = L"Castells ja assignats";

			this->lstCastellsAssignats->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F);
			this->lstCastellsAssignats->FormattingEnabled = true;
			this->lstCastellsAssignats->ItemHeight = 15;
			this->lstCastellsAssignats->Location = System::Drawing::Point(32, 324);
			this->lstCastellsAssignats->Name = L"lstCastellsAssignats";
			this->lstCastellsAssignats->Size = System::Drawing::Size(470, 79);
			this->lstCastellsAssignats->TabIndex = 5;

			this->panelHeader->Controls->Add(this->lblTitol);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelContenido->Controls->Add(this->lblColla);
			this->panelContenido->Controls->Add(this->lblDiada);
			this->panelContenido->Controls->Add(this->cmbDiades);
			this->panelContenido->Controls->Add(this->lblCastell);
			this->panelContenido->Controls->Add(this->cmbCastells);
			this->panelContenido->Controls->Add(this->btnAssignar);
			this->panelContenido->Controls->Add(this->btnTornar);
			this->panelContenido->Controls->Add(this->lblMissatge);
			this->panelContenido->Controls->Add(this->lblAssignats);
			this->panelContenido->Controls->Add(this->lstCastellsAssignats);
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->panelContenido);
			this->Name = L"AssignarCastellsDiadaForm";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
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

			List<PasarelaCastell^>^ resultats = CercadorCastell::obtenirPerColla(this->collaName);

			for each (PasarelaCastell ^ p in resultats) {
				castells->Add(p);

				String^ text =
					p->getNom() + " (" + p->getTipus() + ", ID " + p->getId().ToString() + ")";

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
					p->getNom() + " (" + p->getTipus() + ", ID " + p->getId().ToString() + ")";
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