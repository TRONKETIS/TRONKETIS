#pragma once
#include "CtrlConsultarAssaig.h"
#include "UiStyle.h"

namespace Tronketis {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class ConsultarAssaigForm : public System::Windows::Forms::Form
    {
    public:
        ConsultarAssaigForm(String^ collaName, String^ collaUniName)
        {
            this->collaName = collaName;
            this->collaUniName = collaUniName;
            InitializeComponent();
            CarregarAssaigs();
        }

    protected:
        ~ConsultarAssaigForm()
        {
            if (components) delete components;
        }

    private:
        String^ collaName;
        String^ collaUniName;
        System::Windows::Forms::Panel^ panelHeader;
        System::Windows::Forms::Panel^ panelContenido;
        System::Windows::Forms::Label^ lblTitol;
        System::Windows::Forms::Label^ lblSubtitulo;
        System::Windows::Forms::DataGridView^ dgvAssaigs;
        System::Windows::Forms::Label^ lblMissatge;
        System::Windows::Forms::Button^ btnTancar;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panelHeader = gcnew System::Windows::Forms::Panel();
            this->panelContenido = gcnew System::Windows::Forms::Panel();
            this->lblTitol = gcnew System::Windows::Forms::Label();
            this->lblSubtitulo = gcnew System::Windows::Forms::Label();
            this->dgvAssaigs = gcnew System::Windows::Forms::DataGridView();
            this->lblMissatge = gcnew System::Windows::Forms::Label();
            this->btnTancar = gcnew System::Windows::Forms::Button();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAssaigs))->BeginInit();
            this->panelHeader->SuspendLayout();
            this->panelContenido->SuspendLayout();
            this->SuspendLayout();

            UiStyle::ApplyBase(this, 700, 560, L"Consultar Assaigs");
            UiStyle::ApplyHeader(this->panelHeader, this->lblTitol, this->lblSubtitulo, 700, L"Consultar Assaigs", L"Llistat d'assaigs de la colla");
            UiStyle::ApplyCard(this->panelContenido, 40, 122, 620, 380);

            this->dgvAssaigs->Location = System::Drawing::Point(28, 28);
            this->dgvAssaigs->Size = System::Drawing::Size(564, 255);
            this->dgvAssaigs->ReadOnly = true;
            this->dgvAssaigs->AllowUserToAddRows = false;
            this->dgvAssaigs->AllowUserToDeleteRows = false;
            this->dgvAssaigs->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvAssaigs->BackgroundColor = AppColors::White;
            this->dgvAssaigs->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->dgvAssaigs->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F);
            this->dgvAssaigs->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Bold);

            UiStyle::ApplyMessage(this->lblMissatge, 420);
            this->lblMissatge->Location = System::Drawing::Point(28, 304);
            this->lblMissatge->Text = L"";

            UiStyle::ApplySecondaryButton(this->btnTancar);
            this->btnTancar->Location = System::Drawing::Point(440, 304);
            this->btnTancar->Size = System::Drawing::Size(150, 38);
            this->btnTancar->Text = L"Tancar";
            this->btnTancar->Click += gcnew System::EventHandler(this, &ConsultarAssaigForm::btnTancar_Click);

            this->panelHeader->Controls->Add(this->lblTitol);
            this->panelHeader->Controls->Add(this->lblSubtitulo);
            this->panelContenido->Controls->Add(this->dgvAssaigs);
            this->panelContenido->Controls->Add(this->lblMissatge);
            this->panelContenido->Controls->Add(this->btnTancar);
            this->Controls->Add(this->panelHeader);
            this->Controls->Add(this->panelContenido);
            this->Name = L"ConsultarAssaigForm";

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAssaigs))->EndInit();
            this->panelHeader->ResumeLayout(false);
            this->panelHeader->PerformLayout();
            this->panelContenido->ResumeLayout(false);
            this->panelContenido->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

        void CarregarAssaigs()
        {
            List<AssaigDTO^>^ assaigs = CtrlConsultarAssaig::ConsultarAssaigs(collaName, collaUniName);

            dgvAssaigs->Rows->Clear();
            dgvAssaigs->Columns->Clear();

            dgvAssaigs->Columns->Add("Id", "ID");
            dgvAssaigs->Columns->Add("DataHora", "Data i Hora");

            if (assaigs->Count == 0)
            {
                lblMissatge->ForeColor = System::Drawing::Color::Red;
                lblMissatge->Text = L"No hi ha assaigs registrats per aquesta colla.";
                return;
            }

            for each (AssaigDTO ^ a in assaigs)
            {
                dgvAssaigs->Rows->Add(a->Id, a->DataHora.ToString("dd/MM/yyyy HH:mm"));
            }

            lblMissatge->ForeColor = System::Drawing::Color::Green;
            lblMissatge->Text = assaigs->Count + " assaig(s) trobat(s).";
        }

        System::Void btnTancar_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }
    };
}
