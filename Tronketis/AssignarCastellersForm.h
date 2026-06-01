#pragma once

#include "UiStyle.h"
#include "CtrlAssignarCastellers.h"
#include "PasarelaMuntatgeCastell.h"
#include "CastellDTO.h"
#include "CastellerDTO.h"
#include "PosicioCastellDTO.h"

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
        AssignarCastellersForm(String^ collaName)
        {
            this->collaName = collaName;
            this->castells = gcnew List<CastellDTO^>();
            this->castellers = gcnew List<CastellerDTO^>();
            this->comboBoxes = gcnew List<ComboBox^>();
            this->comboPisos = gcnew List<int>();
            this->comboPosicions = gcnew List<int>();

            InitializeComponent();
            lblCollaValor->Text = collaName;
            CarregarDadesInicials();
        }

    protected:
        ~AssignarCastellersForm()
        {
            if (components) {
                delete components;
            }
        }

    private:
        String^ collaName;
        List<CastellDTO^>^ castells;
        List<CastellerDTO^>^ castellers;
        List<ComboBox^>^ comboBoxes;
        List<int>^ comboPisos;
        List<int>^ comboPosicions;

        Panel^ panelHeader;
        Panel^ panelCard;
        Label^ lblTitulo;
        Label^ lblSubtitulo;
        Label^ lblColla;
        Label^ lblCollaValor;
        Label^ lblCastell;
        ComboBox^ cmbCastell;
        Label^ lblInfo;
        Label^ lblResum;
        Panel^ panelEstructura;
        Button^ btnGuardar;
        Button^ btnCancelar;
        Label^ lblMissatge;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panelHeader = gcnew Panel();
            this->panelCard = gcnew Panel();
            this->lblTitulo = gcnew Label();
            this->lblSubtitulo = gcnew Label();
            this->lblColla = gcnew Label();
            this->lblCollaValor = gcnew Label();
            this->lblCastell = gcnew Label();
            this->cmbCastell = gcnew ComboBox();
            this->lblInfo = gcnew Label();
            this->lblResum = gcnew Label();
            this->panelEstructura = gcnew Panel();
            this->btnGuardar = gcnew Button();
            this->btnCancelar = gcnew Button();
            this->lblMissatge = gcnew Label();

            this->panelHeader->SuspendLayout();
            this->panelCard->SuspendLayout();
            this->SuspendLayout();

            UiStyle::ApplyBase(this, 860, 720, L"Assignar Posicio");
            UiStyle::ApplyHeader(this->panelHeader, this->lblTitulo, this->lblSubtitulo, 860, L"Tronketis", L"Assignar castellers a posicions del castell");
            UiStyle::ApplyCard(this->panelCard, 45, 120, 770, 555);

            this->panelHeader->Controls->Add(this->lblTitulo);
            this->panelHeader->Controls->Add(this->lblSubtitulo);

            UiStyle::ApplyLabel(this->lblColla);
            this->lblColla->Location = Point(30, 24);
            this->lblColla->Text = L"Colla:";

            UiStyle::ApplyValueLabel(this->lblCollaValor);
            this->lblCollaValor->Location = Point(82, 24);
            this->lblCollaValor->Text = L"colla";

            UiStyle::ApplyLabel(this->lblCastell);
            this->lblCastell->Location = Point(30, 68);
            this->lblCastell->Text = L"Castell:";

            UiStyle::ApplyCombo(this->cmbCastell, 360);
            this->cmbCastell->Location = Point(100, 64);
            this->cmbCastell->Name = L"cmbCastell";
            this->cmbCastell->SelectedIndexChanged += gcnew EventHandler(this, &AssignarCastellersForm::cmbCastell_SelectedIndexChanged);

            UiStyle::ApplyMessage(this->lblInfo, 720);
            this->lblInfo->Location = Point(30, 108);
            this->lblInfo->Text = L"Selecciona un castell per carregar la seva estructura.";

            UiStyle::ApplyValueLabel(this->lblResum);
            this->lblResum->Location = Point(30, 135);
            this->lblResum->Text = L"0/0 posicions assignades";

            this->panelEstructura->AutoScroll = true;
            this->panelEstructura->BackColor = Color::FromArgb(248, 248, 248);
            this->panelEstructura->BorderStyle = BorderStyle::FixedSingle;
            this->panelEstructura->Location = Point(30, 166);
            this->panelEstructura->Name = L"panelEstructura";
            this->panelEstructura->Size = Drawing::Size(710, 285);

            UiStyle::ApplyButton(this->btnGuardar);
            this->btnGuardar->Location = Point(430, 470);
            this->btnGuardar->Name = L"btnGuardar";
            this->btnGuardar->Size = Drawing::Size(150, 38);
            this->btnGuardar->Text = L"Guardar";
            this->btnGuardar->Enabled = false;
            this->btnGuardar->Click += gcnew EventHandler(this, &AssignarCastellersForm::btnGuardar_Click);

            UiStyle::ApplySecondaryButton(this->btnCancelar);
            this->btnCancelar->Location = Point(590, 470);
            this->btnCancelar->Name = L"btnCancelar";
            this->btnCancelar->Size = Drawing::Size(150, 38);
            this->btnCancelar->Text = L"Cancelar";
            this->btnCancelar->Click += gcnew EventHandler(this, &AssignarCastellersForm::btnCancelar_Click);

            UiStyle::ApplyMessage(this->lblMissatge, 700);
            this->lblMissatge->Location = Point(30, 522);
            this->lblMissatge->Text = L"";

            this->panelCard->Controls->Add(this->lblColla);
            this->panelCard->Controls->Add(this->lblCollaValor);
            this->panelCard->Controls->Add(this->lblCastell);
            this->panelCard->Controls->Add(this->cmbCastell);
            this->panelCard->Controls->Add(this->lblInfo);
            this->panelCard->Controls->Add(this->lblResum);
            this->panelCard->Controls->Add(this->panelEstructura);
            this->panelCard->Controls->Add(this->btnGuardar);
            this->panelCard->Controls->Add(this->btnCancelar);
            this->panelCard->Controls->Add(this->lblMissatge);

            this->Controls->Add(this->panelCard);
            this->Controls->Add(this->panelHeader);

            this->panelHeader->ResumeLayout(false);
            this->panelHeader->PerformLayout();
            this->panelCard->ResumeLayout(false);
            this->panelCard->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        void CarregarDadesInicials()
        {
            this->castells = CtrlAssignarCastellers::CarregarCastells(this->collaName);
            this->castellers = CtrlAssignarCastellers::CarregarCastellers(this->collaName);

            cmbCastell->Items->Clear();

            for each (CastellDTO ^ c in castells) {
                cmbCastell->Items->Add(c->nom + " (" + c->tipus + c->pisos + ")");
            }

            if (castells->Count == 0) {
                lblMissatge->Text = L"No hi ha castells creats per aquesta colla.";
                lblMissatge->ForeColor = Color::DarkRed;
                btnGuardar->Enabled = false;
                return;
            }

            if (castellers->Count == 0) {
                lblMissatge->Text = L"No hi ha castellers a la colla per assignar.";
                lblMissatge->ForeColor = Color::DarkRed;
                btnGuardar->Enabled = false;
                return;
            }

            cmbCastell->SelectedIndex = 0;
        }

        int PersonesPerPisBase(String^ tipus)
        {
            if (tipus == "2d") return 2;
            if (tipus == "3d") return 3;
            if (tipus == "4d") return 4;
            return 1;
        }

        List<int>^ GenerarEstructura(String^ tipus, int pisos)
        {
            List<int>^ floors = gcnew List<int>();

            if (tipus == "pilar") {
                for (int i = 0; i < pisos; i++) {
                    floors->Add(1);
                }
            }
            else {
                int basePis = PersonesPerPisBase(tipus);

                for (int i = 0; i < pisos - 3; i++) {
                    floors->Add(basePis);
                }

                floors->Add(2);
                floors->Add(1);
                floors->Add(1);
            }

            return floors;
        }

        String^ NomPis(String^ tipus, int numPis, int totalPisos)
        {
            if (tipus != "pilar") {
                if (numPis == totalPisos) return "Enxaneta";
                if (numPis == totalPisos - 1) return "Dosos";
                if (numPis == totalPisos - 2) return "Pom de dalt";
            }
            else {
                if (numPis == totalPisos) return "Cim";
            }

            return "Pis " + numPis;
        }

        Color ColorPis(String^ tipus, int numPis, int totalPisos)
        {
            if (tipus != "pilar") {
                if (numPis == totalPisos) return Color::FromArgb(34, 139, 34);
                if (numPis == totalPisos - 1) return Color::FromArgb(180, 95, 0);
                if (numPis == totalPisos - 2) return Color::FromArgb(150, 110, 0);
            }

            return AppColors::DarkRed;
        }

        void CarregarEstructuraCastell()
        {
            panelEstructura->Controls->Clear();
            comboBoxes->Clear();
            comboPisos->Clear();
            comboPosicions->Clear();
            btnGuardar->Enabled = false;

            if (cmbCastell->SelectedIndex < 0 || cmbCastell->SelectedIndex >= castells->Count) {
                return;
            }

            CastellDTO^ castell = castells[cmbCastell->SelectedIndex];
            List<PosicioCastellDTO^>^ assignacionsExistents =
                PasarelaMuntatgeCastell::obtenirAssignacions(castell->idCastell, this->collaName);

            lblInfo->Text = String::Format(
                "Castell: {0} | Tipus: {1} | Pisos: {2}",
                castell->nom,
                castell->tipus,
                castell->pisos
            );

            List<int>^ floors = GenerarEstructura(castell->tipus, castell->pisos);

            int comboW = 135;
            int comboH = 26;
            int rowH = 44;
            int labelW = 118;
            int gap = 8;
            int panelW = panelEstructura->Width - 22;
            int rowY = 12;

            for (int i = castell->pisos - 1; i >= 0; i--) {
                int numPis = i + 1;
                int numPosicions = floors[i];

                Label^ lblPis = gcnew Label();
                lblPis->AutoSize = false;
                lblPis->Size = Drawing::Size(labelW, comboH);
                lblPis->Location = Point(6, rowY + 1);
                lblPis->Font = gcnew Drawing::Font(L"Segoe UI", 8.5F, FontStyle::Bold);
                lblPis->ForeColor = ColorPis(castell->tipus, numPis, castell->pisos);
                lblPis->TextAlign = ContentAlignment::MiddleRight;
                lblPis->Text = NomPis(castell->tipus, numPis, castell->pisos) + ":";
                panelEstructura->Controls->Add(lblPis);

                int totalComboW = numPosicions * comboW + (numPosicions - 1) * gap;
                int startX = labelW + 12 + ((panelW - labelW - 12) - totalComboW) / 2;

                if (startX < labelW + 12) {
                    startX = labelW + 12;
                }

                for (int pos = 1; pos <= numPosicions; pos++) {
                    ComboBox^ cb = gcnew ComboBox();
                    UiStyle::ApplyCombo(cb, comboW);
                    cb->Height = comboH;
                    cb->Location = Point(startX + (pos - 1) * (comboW + gap), rowY);
                    cb->BackColor = Color::FromArgb(235, 240, 245);
                    cb->Items->Add("(buida)");

                    for each (CastellerDTO ^ casteller in castellers) {
                        cb->Items->Add(casteller->nomUsuari);
                    }

                    cb->SelectedIndex = 0;

                    for each (PosicioCastellDTO ^ ex in assignacionsExistents) {
                        if (ex->numPis == numPis && ex->numPosicio == pos) {
                            for (int c = 0; c < castellers->Count; c++) {
                                if (castellers[c]->dniCasteller == ex->castellerDni) {
                                    cb->SelectedIndex = c + 1;
                                    cb->BackColor = Color::FromArgb(210, 235, 210);
                                    break;
                                }
                            }
                        }
                    }

                    cb->SelectedIndexChanged += gcnew EventHandler(this, &AssignarCastellersForm::comboPosicio_SelectedIndexChanged);

                    panelEstructura->Controls->Add(cb);
                    comboBoxes->Add(cb);
                    comboPisos->Add(numPis);
                    comboPosicions->Add(pos);
                }

                rowY += rowH;
            }

            int total = 0;
            for each (int n in floors) {
                total += n;
            }

            Label^ lblTotal = gcnew Label();
            lblTotal->AutoSize = false;
            lblTotal->Size = Drawing::Size(panelW, 22);
            lblTotal->Location = Point(2, rowY + 8);
            lblTotal->TextAlign = ContentAlignment::MiddleCenter;
            lblTotal->Font = gcnew Drawing::Font(L"Segoe UI", 8.5F, FontStyle::Bold);
            lblTotal->ForeColor = Color::DimGray;
            lblTotal->Text = "Total posicions: " + total;
            panelEstructura->Controls->Add(lblTotal);

            ActualitzarResum();
            btnGuardar->Enabled = true;
        }

        void ActualitzarResum()
        {
            int assignats = 0;

            for each (ComboBox ^ cb in comboBoxes) {
                if (cb->SelectedIndex > 0) {
                    assignats++;
                }
            }

            int total = comboBoxes->Count;
            lblResum->Text = String::Format("{0}/{1} posicions assignades", assignats, total);

            if (assignats == total && total > 0) {
                lblResum->ForeColor = Color::FromArgb(34, 139, 34);
            }
            else {
                lblResum->ForeColor = AppColors::DarkRed;
            }
        }

    private:
        System::Void cmbCastell_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            lblMissatge->Text = L"";
            CarregarEstructuraCastell();
        }

        System::Void comboPosicio_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            ComboBox^ cb = safe_cast<ComboBox^>(sender);

            if (cb->SelectedIndex > 0) {
                cb->BackColor = Color::FromArgb(210, 235, 210);
            }
            else {
                cb->BackColor = Color::FromArgb(235, 240, 245);
            }

            ActualitzarResum();
        }

        System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (cmbCastell->SelectedIndex < 0 || cmbCastell->SelectedIndex >= castells->Count) {
                MessageBox::Show("Selecciona un castell.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            CastellDTO^ castell = castells[cmbCastell->SelectedIndex];
            List<PosicioCastellDTO^>^ posicions = gcnew List<PosicioCastellDTO^>();

            for (int i = 0; i < comboBoxes->Count; i++) {
                PosicioCastellDTO^ p = gcnew PosicioCastellDTO();
                p->numPis = comboPisos[i];
                p->numPosicio = comboPosicions[i];

                int selected = comboBoxes[i]->SelectedIndex;
                if (selected > 0) {
                    p->castellerDni = castellers[selected - 1]->dniCasteller;
                    p->castellerNom = castellers[selected - 1]->nomUsuari;
                }
                else {
                    p->castellerDni = nullptr;
                    p->castellerNom = nullptr;
                }

                posicions->Add(p);
            }

            String^ error = "";
            bool ok = CtrlAssignarCastellers::Assignar(castell->idCastell, this->collaName, posicions, error);

            if (ok) {
                MessageBox::Show("Assignacio guardada correctament.", "Correcte", MessageBoxButtons::OK, MessageBoxIcon::Information);
                lblMissatge->Text = L"Assignacio guardada correctament.";
                lblMissatge->ForeColor = Color::Green;
            }
            else {
                MessageBox::Show("No s'ha pogut guardar:\n\n" + error, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                lblMissatge->Text = L"Error: " + error;
                lblMissatge->ForeColor = Color::DarkRed;
            }
        }

        System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }
    };
}
