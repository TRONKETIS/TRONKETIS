#pragma once

#include "CtrlAssignarCastellers.h"
#include "PasarelaCastell.h"
#include "PasarelaMuntatgeCastell.h"
#include "CastellDTO.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AssignarCastellersForm : public System::Windows::Forms::Form
	{
	public:
		AssignarCastellersForm(int castellId, int collaId)
		{
			castellIdActual = castellId;
			collaIdActual   = collaId;
			castellers      = gcnew List<CastellerDTO^>();
			comboBoxes      = gcnew List<ComboBox^>();
			comboPisos      = gcnew List<int>();
			comboPosicions  = gcnew List<int>();
			InitializeComponent();
			CarregarDades();
		}

		AssignarCastellersForm(void)
		{
			castellIdActual = 0;
			collaIdActual   = 0;
			castellers      = gcnew List<CastellerDTO^>();
			comboBoxes      = gcnew List<ComboBox^>();
			comboPisos      = gcnew List<int>();
			comboPosicions  = gcnew List<int>();
			InitializeComponent();
			CarregarDades();
		}

	protected:
		~AssignarCastellersForm()
		{
			if (components) delete components;
		}

	private:
		int                    castellIdActual;
		int                    collaIdActual;
		List<CastellerDTO^>^   castellers;
		List<ComboBox^>^       comboBoxes;
		List<int>^             comboPisos;
		List<int>^             comboPosicions;

		System::Windows::Forms::Label^  LabelTitol;
		System::Windows::Forms::Label^  LabelInfo;
		System::Windows::Forms::Label^  LabelResum;
		System::Windows::Forms::Panel^  PanelCastell;
		System::Windows::Forms::Button^ BtnGuardar;
		System::Windows::Forms::Button^ BtnCancel;
		System::Windows::Forms::Label^  LabelMissatge;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->LabelTitol    = (gcnew System::Windows::Forms::Label());
			this->LabelInfo     = (gcnew System::Windows::Forms::Label());
			this->LabelResum    = (gcnew System::Windows::Forms::Label());
			this->PanelCastell  = (gcnew System::Windows::Forms::Panel());
			this->BtnGuardar    = (gcnew System::Windows::Forms::Button());
			this->BtnCancel     = (gcnew System::Windows::Forms::Button());
			this->LabelMissatge = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			// LabelTitol
			this->LabelTitol->AutoSize  = true;
			this->LabelTitol->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold));
			this->LabelTitol->ForeColor = System::Drawing::Color::FromArgb(20, 60, 120);
			this->LabelTitol->Location  = System::Drawing::Point(15, 12);
			this->LabelTitol->Name      = L"LabelTitol";
			this->LabelTitol->Text      = L"Assignar Castellers";

			// LabelInfo
			this->LabelInfo->AutoSize  = true;
			this->LabelInfo->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F));
			this->LabelInfo->ForeColor = System::Drawing::Color::DimGray;
			this->LabelInfo->Location  = System::Drawing::Point(15, 45);
			this->LabelInfo->Name      = L"LabelInfo";
			this->LabelInfo->Text      = L"Carregant...";

			// LabelResum
			this->LabelResum->AutoSize  = true;
			this->LabelResum->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Bold));
			this->LabelResum->ForeColor = System::Drawing::Color::FromArgb(0, 100, 200);
			this->LabelResum->Location  = System::Drawing::Point(15, 65);
			this->LabelResum->Name      = L"LabelResum";
			this->LabelResum->Text      = L"";

			// PanelCastell
			this->PanelCastell->AutoScroll  = true;
			this->PanelCastell->BackColor   = System::Drawing::Color::FromArgb(245, 247, 250);
			this->PanelCastell->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PanelCastell->Location    = System::Drawing::Point(15, 88);
			this->PanelCastell->Name        = L"PanelCastell";
			this->PanelCastell->Size        = System::Drawing::Size(760, 490);

			// BtnGuardar
			this->BtnGuardar->BackColor = System::Drawing::Color::FromArgb(0, 123, 255);
			this->BtnGuardar->Enabled   = false;
			this->BtnGuardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnGuardar->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->BtnGuardar->ForeColor = System::Drawing::Color::White;
			this->BtnGuardar->Location  = System::Drawing::Point(440, 592);
			this->BtnGuardar->Name      = L"BtnGuardar";
			this->BtnGuardar->Size      = System::Drawing::Size(180, 38);
			this->BtnGuardar->Text      = L"Guardar assignaci\x00F3";
			this->BtnGuardar->UseVisualStyleBackColor = false;
			this->BtnGuardar->Click    += gcnew System::EventHandler(this, &AssignarCastellersForm::BtnGuardar_Click);

			// BtnCancel
			this->BtnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnCancel->Location  = System::Drawing::Point(640, 592);
			this->BtnCancel->Name      = L"BtnCancel";
			this->BtnCancel->Size      = System::Drawing::Size(120, 38);
			this->BtnCancel->Text      = L"Cancel\x00B7lar";
			this->BtnCancel->UseVisualStyleBackColor = true;
			this->BtnCancel->Click    += gcnew System::EventHandler(this, &AssignarCastellersForm::BtnCancel_Click);

			// LabelMissatge
			this->LabelMissatge->AutoSize  = true;
			this->LabelMissatge->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->LabelMissatge->Location  = System::Drawing::Point(15, 638);
			this->LabelMissatge->Name      = L"LabelMissatge";
			this->LabelMissatge->Text      = L"";

			// Form
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode       = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor           = System::Drawing::Color::FromArgb(250, 250, 250);
			this->ClientSize          = System::Drawing::Size(792, 660);
			this->Controls->Add(this->LabelMissatge);
			this->Controls->Add(this->BtnCancel);
			this->Controls->Add(this->BtnGuardar);
			this->Controls->Add(this->PanelCastell);
			this->Controls->Add(this->LabelResum);
			this->Controls->Add(this->LabelInfo);
			this->Controls->Add(this->LabelTitol);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox     = false;
			this->Name            = L"AssignarCastellersForm";
			this->StartPosition   = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text            = L"Assignar Castellers";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	// ─── Helpers ──────────────────────────────────────────────────────────────
	private:
		List<int>^ GenerarEstructura(String^ tipus, int pisos) {
			List<int>^ floors = gcnew List<int>();
			if (tipus == "pilar") {
				for (int i = 0; i < pisos; i++) floors->Add(1);
			}
			else {
				int base = (tipus == "2d") ? 2 : (tipus == "3d") ? 3 : 4;
				for (int i = 0; i < pisos - 3; i++) floors->Add(base);
				floors->Add(2); floors->Add(1); floors->Add(1);
			}
			return floors;
		}

		String^ NomPis(String^ tipus, int numPis, int totalPisos) {
			if (tipus != "pilar") {
				if (numPis == totalPisos)     return "Enxaneta";
				if (numPis == totalPisos - 1) return "Dosos";
				if (numPis == totalPisos - 2) return "Pom de dalt";
			}
			else if (numPis == totalPisos)    return "Cim";
			return "Pis " + numPis;
		}

		Color ColorPis(String^ tipus, int numPis, int totalPisos) {
			if (tipus != "pilar") {
				if (numPis == totalPisos)     return Color::FromArgb(34, 139, 34);
				if (numPis == totalPisos - 1) return Color::FromArgb(200, 80, 0);
				if (numPis == totalPisos - 2) return Color::FromArgb(160, 120, 0);
			}
			return Color::FromArgb(30, 80, 160);
		}

		void ActualitzarResum() {
			int assignats = 0;
			for each (ComboBox^ cbx in comboBoxes)
				if (cbx->SelectedIndex > 0) assignats++;
			int total = comboBoxes->Count;
			LabelResum->Text = String::Format("{0}/{1} posicions assignades", assignats, total);
			LabelResum->ForeColor = (assignats == total)
				? Color::FromArgb(34, 139, 34) : Color::FromArgb(0, 100, 200);
			BtnGuardar->Enabled = true;
		}

	// ─── Càrrega ──────────────────────────────────────────────────────────────
	private:
		void CarregarDades() {
			CastellDTO^ castell = PasarelaCastell::obtenirPerId(castellIdActual);
			if (castell == nullptr) {
				LabelInfo->Text = "No s'ha trobat el castell (ID " + castellIdActual + ")";
				return;
			}

			LabelTitol->Text = L"Assignar castellers - " + castell->nom;
			LabelInfo->Text  = String::Format(
				"Tipus: {0}  |  Pisos: {1}  |  Colla ID: {2}",
				castell->tipus, castell->pisos, collaIdActual);

			castellers = CtrlAssignarCastellers::CarregarCastellers(collaIdActual);

			List<PosicioCastellDTO^>^ existents =
				PasarelaMuntatgeCastell::obtenirAssignacions(castellIdActual, collaIdActual);

			ConstruirEstructura(castell, existents);
		}

		void ConstruirEstructura(CastellDTO^ castell, List<PosicioCastellDTO^>^ existents) {
			PanelCastell->Controls->Clear();
			comboBoxes->Clear();
			comboPisos->Clear();
			comboPosicions->Clear();

			List<int>^ floors   = GenerarEstructura(castell->tipus, castell->pisos);
			int pisos           = castell->pisos;
			const int comboW    = 130;
			const int comboH    = 22;
			const int rowH      = 42;
			const int labelW    = 120;
			const int gap       = 8;
			const int panelW    = PanelCastell->Width - 4;
			int rowY            = 10;

			// Mostra de dalt (enxaneta) a baix (pinya)
			for (int i = pisos - 1; i >= 0; i--) {
				int numPis = i + 1;
				int numPos = floors[i];

				// Etiqueta del pis
				Label^ lbl     = gcnew Label();
				lbl->AutoSize  = false;
				lbl->Size      = System::Drawing::Size(labelW, comboH);
				lbl->Location  = System::Drawing::Point(5, rowY + 1);
				lbl->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.0F, System::Drawing::FontStyle::Bold));
				lbl->ForeColor = ColorPis(castell->tipus, numPis, pisos);
				lbl->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				lbl->Text      = NomPis(castell->tipus, numPis, pisos) + ":";
				PanelCastell->Controls->Add(lbl);

				// Centra els ComboBoxes (forma piramidal)
				int totalComboW = numPos * comboW + (numPos - 1) * gap;
				int startX      = labelW + 10 + ((panelW - labelW - 10) - totalComboW) / 2;

				for (int p = 0; p < numPos; p++) {
					int posicio = p + 1;

					ComboBox^ cbx      = gcnew ComboBox();
					cbx->DropDownStyle = ComboBoxStyle::DropDownList;
					cbx->FlatStyle     = FlatStyle::Flat;
					cbx->Font          = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.0F));
					cbx->BackColor     = Color::FromArgb(220, 230, 245); // slot buit = blau
					cbx->Width         = comboW;
					cbx->Height        = comboH;
					cbx->Location      = System::Drawing::Point(startX + p * (comboW + gap), rowY);

					cbx->Items->Add("(buida)");
					for each (CastellerDTO^ c in castellers)
						cbx->Items->Add(c->nomUsuari);
					cbx->SelectedIndex = 0;

					// Pre-omple si ja hi ha assignació guardada
					for each (PosicioCastellDTO^ ex in existents) {
						if (ex->numPis == numPis && ex->numPosicio == posicio) {
							for (int ci = 0; ci < castellers->Count; ci++) {
								if (castellers[ci]->dniCasteller == ex->castellerDni) {
									cbx->SelectedIndex = ci + 1;
									cbx->BackColor     = Color::FromArgb(195, 230, 195); // slot ple = verd
									break;
								}
							}
							break;
						}
					}

					cbx->SelectedIndexChanged += gcnew System::EventHandler(
						this, &AssignarCastellersForm::Combo_Changed);

					PanelCastell->Controls->Add(cbx);
					comboBoxes->Add(cbx);
					comboPisos->Add(numPis);
					comboPosicions->Add(posicio);
				}
				rowY += rowH;
			}

			// Total castellers
			int total = 0;
			for each (int p in floors) total += p;
			Label^ lblTotal     = gcnew Label();
			lblTotal->AutoSize  = false;
			lblTotal->Size      = System::Drawing::Size(panelW, 20);
			lblTotal->Location  = System::Drawing::Point(2, rowY + 6);
			lblTotal->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			lblTotal->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.0F, System::Drawing::FontStyle::Bold));
			lblTotal->ForeColor = Color::DimGray;
			lblTotal->Text      = "Total: " + total + " castellers";
			PanelCastell->Controls->Add(lblTotal);

			ActualitzarResum();
		}

	// ─── Events ───────────────────────────────────────────────────────────────
	private: System::Void Combo_Changed(System::Object^ sender, System::EventArgs^ e) {
		ComboBox^ cbx  = cli::safe_cast<ComboBox^>(sender);
		cbx->BackColor = (cbx->SelectedIndex == 0)
			? Color::FromArgb(220, 230, 245)
			: Color::FromArgb(195, 230, 195);
		ActualitzarResum();
	}

	private: System::Void BtnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		List<PosicioCastellDTO^>^ posicions = gcnew List<PosicioCastellDTO^>();
		for (int i = 0; i < comboBoxes->Count; i++) {
			PosicioCastellDTO^ p = gcnew PosicioCastellDTO();
			p->numPis     = comboPisos[i];
			p->numPosicio = comboPosicions[i];
			int sel       = comboBoxes[i]->SelectedIndex;
			p->castellerDni = (sel > 0) ? castellers[sel - 1]->dniCasteller : nullptr;
			posicions->Add(p);
		}

		String^ error;
		bool ok = CtrlAssignarCastellers::Assignar(castellIdActual, collaIdActual, posicions, error);

		if (ok) {
			LabelMissatge->Text      = L"Assignaci\x00F3 desada correctament!";
			LabelMissatge->ForeColor = Color::Green;
			MessageBox::Show(L"L'assignaci\x00F3 s'ha desat amb \x00E8xit.",
				L"\x00C8xit", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else {
			LabelMissatge->Text      = L"Error: " + error;
			LabelMissatge->ForeColor = Color::Red;
			MessageBox::Show("No s'ha pogut desar:\n\n" + error,
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
	};
}
