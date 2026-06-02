#pragma once

#include "UiStyle.h"
#include "CastellDTO.h"
#include "PosicioCastellDTO.h"
#include "PasarelaMuntatgeCastell.h"

namespace Tronketis {

    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class ConsultarEstructuraCastellForm : public System::Windows::Forms::Form
    {
    public:
        ConsultarEstructuraCastellForm(String^ collaName, CastellDTO^ castell)
        {
            this->collaName = collaName;
            this->castell = castell;
            InitializeComponent();
            CarregarEstructura();
        }

    protected:
        ~ConsultarEstructuraCastellForm()
        {
            if (components) {
                delete components;
            }
        }

    private:
        String^ collaName;
        CastellDTO^ castell;

        Panel^ panelHeader;
        Panel^ panelCard;
        Label^ lblTitulo;
        Label^ lblSubtitulo;
        Label^ lblInfo;
        TextBox^ txtEstructura;
        Button^ btnTancar;
        System::ComponentModel::Container^ components;

    private:
        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->panelHeader = gcnew Panel();
            this->panelCard = gcnew Panel();
            this->lblTitulo = gcnew Label();
            this->lblSubtitulo = gcnew Label();
            this->lblInfo = gcnew Label();
            this->txtEstructura = gcnew TextBox();
            this->btnTancar = gcnew Button();

            this->SuspendLayout();

            UiStyle::ApplyBase(this, 720, 590, L"Veure Estructura");
            UiStyle::ApplyHeader(this->panelHeader, this->lblTitulo, this->lblSubtitulo, 720, L"Tronketis", L"Estructura assignada del castell");
            UiStyle::ApplyCard(this->panelCard, 40, 125, 640, 405);

            this->panelHeader->Controls->Add(this->lblTitulo);
            this->panelHeader->Controls->Add(this->lblSubtitulo);

            UiStyle::ApplyValueLabel(this->lblInfo);
            this->lblInfo->Location = Point(30, 24);
            this->lblInfo->Size = Drawing::Size(570, 28);
            this->lblInfo->Text = L"Carregant estructura...";

            this->txtEstructura->Location = Point(30, 65);
            this->txtEstructura->Size = Drawing::Size(580, 250);
            this->txtEstructura->Multiline = true;
            this->txtEstructura->ReadOnly = true;
            this->txtEstructura->ScrollBars = ScrollBars::Vertical;
            this->txtEstructura->Font = gcnew Drawing::Font(L"Consolas", 10, FontStyle::Regular);
            this->txtEstructura->BackColor = Color::FromArgb(248, 248, 248);
            this->txtEstructura->BorderStyle = BorderStyle::FixedSingle;

            UiStyle::ApplySecondaryButton(this->btnTancar);
            this->btnTancar->Location = Point(460, 335);
            this->btnTancar->Size = Drawing::Size(150, 38);
            this->btnTancar->Text = L"Tancar";
            this->btnTancar->Click += gcnew EventHandler(this, &ConsultarEstructuraCastellForm::btnTancar_Click);

            this->panelCard->Controls->Add(this->lblInfo);
            this->panelCard->Controls->Add(this->txtEstructura);
            this->panelCard->Controls->Add(this->btnTancar);

            this->Controls->Add(this->panelCard);
            this->Controls->Add(this->panelHeader);

            this->ResumeLayout(false);
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

        String^ BuscarAssignacio(List<PosicioCastellDTO^>^ assignacions, int numPis, int numPosicio)
        {
            String^ resultat = "(buida)";

            for each (PosicioCastellDTO ^ p in assignacions) {
                if (p->numPis == numPis && p->numPosicio == numPosicio) {
                    if (!String::IsNullOrEmpty(p->castellerNom)) {
                        resultat = p->castellerNom;
                    }
                    else if (!String::IsNullOrEmpty(p->castellerDni)) {
                        resultat = p->castellerDni;
                    }
                    break;
                }
            }

            return resultat;
        }

        void CarregarEstructura()
        {
            if (castell == nullptr) {
                lblInfo->Text = L"No s'ha pogut carregar el castell.";
                txtEstructura->Text = L"";
                return;
            }

            List<PosicioCastellDTO^>^ assignacions = PasarelaMuntatgeCastell::obtenirAssignacions(castell->idCastell, collaName);
            List<int>^ floors = GenerarEstructura(castell->tipus, castell->pisos);

            lblInfo->Text = String::Format(
                "{0} | Tipus: {1} | Pisos: {2} | Colla: {3}",
                castell->nom,
                castell->tipus,
                castell->pisos,
                collaName
            );

            String^ text = "";
            int assignades = 0;
            int total = 0;

            for (int i = castell->pisos - 1; i >= 0; i--) {
                int numPis = i + 1;
                int numPosicions = floors[i];
                total += numPosicions;

                text += NomPis(castell->tipus, numPis, castell->pisos) + ":\r\n";

                for (int pos = 1; pos <= numPosicions; pos++) {
                    String^ nom = BuscarAssignacio(assignacions, numPis, pos);
                    if (nom != "(buida)") {
                        assignades++;
                    }

                    text += "  Posicio " + pos + " -> " + nom + "\r\n";
                }

                text += "\r\n";
            }

            text += "--------------------------------\r\n";
            text += "Assignades: " + assignades + "/" + total + "\r\n";

            txtEstructura->Text = text;
        }

        System::Void btnTancar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }
    };
}
