#pragma once

#include "CtrlCrearCastell.h"
#include "CastellDTO.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CrearCastellForm : public System::Windows::Forms::Form
	{
	public:
		CrearCastellForm(void)
		{
			InitializeComponent();
			ConfigurarValidacions();
		}

	protected:
		~CrearCastellForm()
		{
			if (components) delete components;
		}

	private:
		System::Windows::Forms::Label^        LabelTitol;
		System::Windows::Forms::GroupBox^     GroupBoxTipus;
		System::Windows::Forms::RadioButton^  RbtnDos;
		System::Windows::Forms::RadioButton^  RbtnTres;
		System::Windows::Forms::RadioButton^  RbtnQuatre;
		System::Windows::Forms::RadioButton^  RbtnPilar;
		System::Windows::Forms::Label^        LabelNumPisos;
		System::Windows::Forms::NumericUpDown^ NumericPisos;
		System::Windows::Forms::Label^        LabelNom;
		System::Windows::Forms::TextBox^      TextBoxNom;
		System::Windows::Forms::Label^        LabelInfoNom;
		System::Windows::Forms::Label^        LabelPrevisualitzacio;
		System::Windows::Forms::Panel^        PanelPrevisualitzacio;
		System::Windows::Forms::Button^       BtnCrearCastell;
		System::Windows::Forms::Button^       BtnNetejar;
		System::Windows::Forms::Label^        LabelMissatge;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->LabelTitol             = (gcnew System::Windows::Forms::Label());
			this->GroupBoxTipus          = (gcnew System::Windows::Forms::GroupBox());
			this->RbtnDos                = (gcnew System::Windows::Forms::RadioButton());
			this->RbtnTres               = (gcnew System::Windows::Forms::RadioButton());
			this->RbtnQuatre             = (gcnew System::Windows::Forms::RadioButton());
			this->RbtnPilar              = (gcnew System::Windows::Forms::RadioButton());
			this->LabelNumPisos          = (gcnew System::Windows::Forms::Label());
			this->NumericPisos           = (gcnew System::Windows::Forms::NumericUpDown());
			this->LabelNom               = (gcnew System::Windows::Forms::Label());
			this->TextBoxNom             = (gcnew System::Windows::Forms::TextBox());
			this->LabelInfoNom           = (gcnew System::Windows::Forms::Label());
			this->LabelPrevisualitzacio  = (gcnew System::Windows::Forms::Label());
			this->PanelPrevisualitzacio  = (gcnew System::Windows::Forms::Panel());
			this->BtnCrearCastell        = (gcnew System::Windows::Forms::Button());
			this->BtnNetejar             = (gcnew System::Windows::Forms::Button());
			this->LabelMissatge          = (gcnew System::Windows::Forms::Label());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericPisos))->BeginInit();
			this->GroupBoxTipus->SuspendLayout();
			this->SuspendLayout();

			// LabelTitol
			this->LabelTitol->AutoSize  = true;
			this->LabelTitol->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->LabelTitol->ForeColor = System::Drawing::Color::FromArgb(20, 60, 120);
			this->LabelTitol->Location  = System::Drawing::Point(20, 15);
			this->LabelTitol->Name      = L"LabelTitol";
			this->LabelTitol->Text      = L"Crear Nou Castell";

			// GroupBoxTipus
			this->GroupBoxTipus->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->GroupBoxTipus->Location = System::Drawing::Point(20, 58);
			this->GroupBoxTipus->Name     = L"GroupBoxTipus";
			this->GroupBoxTipus->Size     = System::Drawing::Size(650, 75);
			this->GroupBoxTipus->Text     = L"Tipus de castell";
			this->GroupBoxTipus->Controls->Add(this->RbtnDos);
			this->GroupBoxTipus->Controls->Add(this->RbtnTres);
			this->GroupBoxTipus->Controls->Add(this->RbtnQuatre);
			this->GroupBoxTipus->Controls->Add(this->RbtnPilar);

			// RbtnDos
			this->RbtnDos->AutoSize = true;
			this->RbtnDos->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->RbtnDos->Location = System::Drawing::Point(10, 35);
			this->RbtnDos->Name     = L"RbtnDos";
			this->RbtnDos->Text     = L"Torre";
			this->RbtnDos->CheckedChanged += gcnew System::EventHandler(this, &CrearCastellForm::Tipus_CheckedChanged);

			// RbtnTres
			this->RbtnTres->AutoSize = true;
			this->RbtnTres->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->RbtnTres->Location = System::Drawing::Point(175, 35);
			this->RbtnTres->Name     = L"RbtnTres";
			this->RbtnTres->Text     = L"Tres";
			this->RbtnTres->CheckedChanged += gcnew System::EventHandler(this, &CrearCastellForm::Tipus_CheckedChanged);

			// RbtnQuatre
			this->RbtnQuatre->AutoSize = true;
			this->RbtnQuatre->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->RbtnQuatre->Location = System::Drawing::Point(345, 35);
			this->RbtnQuatre->Name     = L"RbtnQuatre";
			this->RbtnQuatre->Text     = L"Quatre";
			this->RbtnQuatre->CheckedChanged += gcnew System::EventHandler(this, &CrearCastellForm::Tipus_CheckedChanged);

			// RbtnPilar
			this->RbtnPilar->AutoSize = true;
			this->RbtnPilar->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->RbtnPilar->Location = System::Drawing::Point(515, 35);
			this->RbtnPilar->Name     = L"RbtnPilar";
			this->RbtnPilar->Text     = L"Pilar";
			this->RbtnPilar->CheckedChanged += gcnew System::EventHandler(this, &CrearCastellForm::Tipus_CheckedChanged);

			// LabelNumPisos
			this->LabelNumPisos->AutoSize = true;
			this->LabelNumPisos->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->LabelNumPisos->Location = System::Drawing::Point(20, 153);
			this->LabelNumPisos->Name     = L"LabelNumPisos";
			this->LabelNumPisos->Text     = L"Nombre de pisos:*";

			// NumericPisos
			this->NumericPisos->Location = System::Drawing::Point(175, 150);
			this->NumericPisos->Minimum  = System::Decimal(4);
			this->NumericPisos->Maximum  = System::Decimal(10);
			this->NumericPisos->Value    = System::Decimal(7);
			this->NumericPisos->Name     = L"NumericPisos";
			this->NumericPisos->Size     = System::Drawing::Size(65, 22);
			this->NumericPisos->TabIndex = 0;
			this->NumericPisos->ValueChanged += gcnew System::EventHandler(this, &CrearCastellForm::NumericPisos_ValueChanged);

			// LabelNom
			this->LabelNom->AutoSize = true;
			this->LabelNom->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->LabelNom->Location = System::Drawing::Point(20, 193);
			this->LabelNom->Name     = L"LabelNom";
			this->LabelNom->Text     = L"Nom del castell:*";

			// TextBoxNom
			this->TextBoxNom->Location = System::Drawing::Point(175, 190);
			this->TextBoxNom->Name     = L"TextBoxNom";
			this->TextBoxNom->Size     = System::Drawing::Size(280, 22);
			this->TextBoxNom->TabIndex = 1;
			this->TextBoxNom->TextChanged += gcnew System::EventHandler(this, &CrearCastellForm::TextBoxNom_TextChanged);

			// LabelInfoNom
			this->LabelInfoNom->AutoSize  = true;
			this->LabelInfoNom->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F));
			this->LabelInfoNom->ForeColor = System::Drawing::Color::Gray;
			this->LabelInfoNom->Location  = System::Drawing::Point(465, 194);
			this->LabelInfoNom->Name      = L"LabelInfoNom";
			this->LabelInfoNom->Text      = L"S'omple autom\x00e0ticament";

			// LabelPrevisualitzacio
			this->LabelPrevisualitzacio->AutoSize = true;
			this->LabelPrevisualitzacio->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->LabelPrevisualitzacio->Location = System::Drawing::Point(20, 230);
			this->LabelPrevisualitzacio->Name     = L"LabelPrevisualitzacio";
			this->LabelPrevisualitzacio->Text     = L"Estructura del castell:";

			// PanelPrevisualitzacio
			this->PanelPrevisualitzacio->AutoScroll  = true;
			this->PanelPrevisualitzacio->BackColor   = System::Drawing::Color::FromArgb(248, 249, 250);
			this->PanelPrevisualitzacio->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PanelPrevisualitzacio->Location    = System::Drawing::Point(20, 253);
			this->PanelPrevisualitzacio->Name        = L"PanelPrevisualitzacio";
			this->PanelPrevisualitzacio->Size        = System::Drawing::Size(650, 255);

			// BtnCrearCastell
			this->BtnCrearCastell->BackColor = System::Drawing::Color::FromArgb(0, 123, 255);
			this->BtnCrearCastell->Enabled   = false;
			this->BtnCrearCastell->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnCrearCastell->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->BtnCrearCastell->ForeColor = System::Drawing::Color::White;
			this->BtnCrearCastell->Location  = System::Drawing::Point(175, 524);
			this->BtnCrearCastell->Name      = L"BtnCrearCastell";
			this->BtnCrearCastell->Size      = System::Drawing::Size(180, 40);
			this->BtnCrearCastell->TabIndex  = 2;
			this->BtnCrearCastell->Text      = L"Crear Castell";
			this->BtnCrearCastell->UseVisualStyleBackColor = false;
			this->BtnCrearCastell->Click += gcnew System::EventHandler(this, &CrearCastellForm::BtnCrearCastell_Click);

			// BtnNetejar
			this->BtnNetejar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnNetejar->Location  = System::Drawing::Point(375, 524);
			this->BtnNetejar->Name      = L"BtnNetejar";
			this->BtnNetejar->Size      = System::Drawing::Size(100, 40);
			this->BtnNetejar->TabIndex  = 3;
			this->BtnNetejar->Text      = L"\U0001F504 Netejar";
			this->BtnNetejar->UseVisualStyleBackColor = true;
			this->BtnNetejar->Click += gcnew System::EventHandler(this, &CrearCastellForm::BtnNetejar_Click);

			// LabelMissatge
			this->LabelMissatge->AutoSize  = true;
			this->LabelMissatge->Font      = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->LabelMissatge->Location  = System::Drawing::Point(20, 576);
			this->LabelMissatge->Name      = L"LabelMissatge";
			this->LabelMissatge->Size      = System::Drawing::Size(0, 18);

			// Form
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode       = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor           = System::Drawing::Color::FromArgb(250, 250, 250);
			this->ClientSize          = System::Drawing::Size(700, 610);
			this->Controls->Add(this->LabelMissatge);
			this->Controls->Add(this->BtnNetejar);
			this->Controls->Add(this->BtnCrearCastell);
			this->Controls->Add(this->PanelPrevisualitzacio);
			this->Controls->Add(this->LabelPrevisualitzacio);
			this->Controls->Add(this->LabelInfoNom);
			this->Controls->Add(this->TextBoxNom);
			this->Controls->Add(this->LabelNom);
			this->Controls->Add(this->NumericPisos);
			this->Controls->Add(this->LabelNumPisos);
			this->Controls->Add(this->GroupBoxTipus);
			this->Controls->Add(this->LabelTitol);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox     = false;
			this->Name            = L"CrearCastellForm";
			this->StartPosition   = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text            = L"\U0001F3F0 Crear Nou Castell";

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericPisos))->EndInit();
			this->GroupBoxTipus->ResumeLayout(false);
			this->GroupBoxTipus->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		String^ ObtenirTipusSeleccionat() {
			if (RbtnDos->Checked)    return "2d";
			if (RbtnTres->Checked)   return "3d";
			if (RbtnQuatre->Checked) return "4d";
			if (RbtnPilar->Checked)  return "pilar";
			return nullptr;
		}

		bool TipusSeleccionat() {
			return RbtnDos->Checked || RbtnTres->Checked || RbtnQuatre->Checked || RbtnPilar->Checked;
		}

		int PersonesPerPisBase(String^ tipus) {
			if (tipus == "2d") return 2;
			if (tipus == "3d") return 3;
			if (tipus == "4d") return 4;
			return 1; // pilar
		}

		String^ GenerarNomAuto() {
			String^ tipus = ObtenirTipusSeleccionat();
			if (tipus == nullptr) return "";
			int pisos = (int)NumericPisos->Value;
			if (tipus == "pilar") return "pilar" + pisos;
			return tipus + pisos;
		}

		void ConfigurarValidacions() {
			LabelMissatge->Text      = L"\U0001F4A1 Seleccioneu el tipus i el nombre de pisos del castell";
			LabelMissatge->ForeColor = System::Drawing::Color::FromArgb(0, 123, 255);
			ActualitzarPreview();
			ValidarFormulari();
		}

		void ValidarFormulari() {
			bool tipusValid = TipusSeleccionat();
			bool nomValid   = !String::IsNullOrWhiteSpace(TextBoxNom->Text);
			BtnCrearCastell->Enabled = tipusValid && nomValid;
		}

		// Genera la llista de persones per pis (index 0 = pinya / pis inferior)
		List<int>^ GenerarEstructura(String^ tipus, int pisos) {
			List<int>^ floors = gcnew List<int>();
			if (tipus == "pilar") {
				for (int i = 0; i < pisos; i++) floors->Add(1);
			}
			else {
				int base = PersonesPerPisBase(tipus);
				for (int i = 0; i < pisos - 3; i++) floors->Add(base);
				floors->Add(2); // dosos
				floors->Add(1); // acoxador
				floors->Add(1); // enxaneta
			}
			return floors;
		}

		void ActualitzarPreview() {
			PanelPrevisualitzacio->Controls->Clear();

			if (!TipusSeleccionat()) {
				Label^ hint = gcnew Label();
				hint->AutoSize    = false;
				hint->Size        = System::Drawing::Size(648, 253);
				hint->Location    = System::Drawing::Point(0, 0);
				hint->TextAlign   = System::Drawing::ContentAlignment::MiddleCenter;
				hint->ForeColor   = System::Drawing::Color::Gray;
				hint->Font        = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				hint->Text        = L"Seleccioneu un tipus de castell per veure l'estructura";
				PanelPrevisualitzacio->Controls->Add(hint);
				return;
			}

			String^ tipus = ObtenirTipusSeleccionat();
			int pisos     = (int)NumericPisos->Value;
			List<int>^ floors = GenerarEstructura(tipus, pisos);

			int rowH   = 22;
			int rowGap = 2;
			int panelW = PanelPrevisualitzacio->Width - 4;
			int total  = 0;

			// Mostrar de dalt a baix: enxaneta primer, pinya al final
			for (int i = pisos - 1; i >= 0; i--) {
				int floorNum = i + 1;
				int ppl      = floors[i];
				total += ppl;

				String^ nomPis;
				Color   col;

				if (tipus != "pilar") {
					if      (floorNum == pisos)     { nomPis = "Enxaneta";    col = System::Drawing::Color::FromArgb(34,  139,  34); }
					else if (floorNum == pisos - 1) { nomPis = "Acoxador";       col = System::Drawing::Color::FromArgb(220,  80,   0); }
					else if (floorNum == pisos - 2) { nomPis = "Dosos"; col = System::Drawing::Color::FromArgb(184, 134,  11); }
					else                            { nomPis = "Pis " + floorNum; col = System::Drawing::Color::FromArgb(30, 80, 160); }
				}
				else {
					if (floorNum == pisos) { nomPis = "Enxaneta (Pis " + floorNum + ")"; col = System::Drawing::Color::FromArgb(34, 139, 34); }
					else                   { nomPis = "Pis " + floorNum;             col = System::Drawing::Color::FromArgb(30, 80, 160); }
				}

				String^ dots = "";
				for (int j = 0; j < ppl; j++) dots += (j > 0 ? " ●" : "●");

				Label^ lbl    = gcnew Label();
				lbl->AutoSize = false;
				lbl->Size     = System::Drawing::Size(panelW, rowH);
				lbl->Location = System::Drawing::Point(2, (pisos - 1 - i) * (rowH + rowGap) + 5);
				lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				lbl->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F));
				lbl->ForeColor = col;
				lbl->Text     = nomPis + ":  " + dots + "  (" + ppl + (ppl == 1 ? " persona" : " persones") + ")";
				PanelPrevisualitzacio->Controls->Add(lbl);
			}

			// Resum total
			Label^ lblTotal    = gcnew Label();
			lblTotal->AutoSize = false;
			lblTotal->Size     = System::Drawing::Size(panelW, 22);
			lblTotal->Location = System::Drawing::Point(2, pisos * (rowH + rowGap) + 12);
			lblTotal->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			lblTotal->Font     = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Bold));
			lblTotal->ForeColor = System::Drawing::Color::DimGray;
			lblTotal->Text     = "Total: " + total + " castellers";
			PanelPrevisualitzacio->Controls->Add(lblTotal);
		}

	private: System::Void Tipus_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (RbtnPilar->Checked) {
			NumericPisos->Minimum = System::Decimal(3);
			if (NumericPisos->Value < 3) NumericPisos->Value = System::Decimal(3);
		}
		else {
			NumericPisos->Minimum = System::Decimal(4);
			if (NumericPisos->Value < 4) NumericPisos->Value = System::Decimal(4);
		}
		TextBoxNom->Text = GenerarNomAuto();
		ActualitzarPreview();
		ValidarFormulari();
	}

	private: System::Void NumericPisos_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (TipusSeleccionat()) {
			TextBoxNom->Text = GenerarNomAuto();
		}
		ActualitzarPreview();
		ValidarFormulari();
	}

	private: System::Void TextBoxNom_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		ValidarFormulari();
	}

	private: System::Void BtnCrearCastell_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nom   = TextBoxNom->Text->Trim();
		String^ tipus = ObtenirTipusSeleccionat();
		int pisos     = (int)NumericPisos->Value;

		CastellDTO^ nouCastell = gcnew CastellDTO();
		nouCastell->nom      = nom;
		nouCastell->tipus    = tipus;
		nouCastell->pisos = pisos;

		String^ error;
		bool resultat = CtrlCrearCastell::Crear(nouCastell, error);

		if (resultat) {
			LabelMissatge->Text      = L"Castell creat correctament!";
			LabelMissatge->ForeColor = System::Drawing::Color::Green;

			MessageBox::Show(
				"El castell \"" + nom + "\" s'ha creat amb exit!\n\nID: " + nouCastell->idCastell,
				L"Exit",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else {
			LabelMissatge->Text      = L"Error: " + error;
			LabelMissatge->ForeColor = System::Drawing::Color::Red;

			MessageBox::Show(
				"No s'ha pogut crear el castell:\n\n" + error,
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}

	private: System::Void BtnNetejar_Click(System::Object^ sender, System::EventArgs^ e) {
		RbtnDos->Checked    = false;
		RbtnTres->Checked   = false;
		RbtnQuatre->Checked = false;
		RbtnPilar->Checked  = false;

		NumericPisos->Minimum = System::Decimal(4);
		NumericPisos->Value   = System::Decimal(7);

		TextBoxNom->Clear();

		LabelMissatge->Text      = L"\U0001F504 Formulari netejat. Seleccioneu el tipus de castell";
		LabelMissatge->ForeColor = System::Drawing::Color::FromArgb(0, 123, 255);

		BtnCrearCastell->Enabled = false;
		ActualitzarPreview();
	}
	};
}
