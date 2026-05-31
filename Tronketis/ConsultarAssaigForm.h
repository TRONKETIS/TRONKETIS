#pragma once
#include "CtrlConsultarAssaig.h"

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
        System::Windows::Forms::Label^ lblTitol;
        System::Windows::Forms::DataGridView^ dgvAssaigs;
        System::Windows::Forms::Label^ lblMissatge;
        System::Windows::Forms::Button^ btnTancar;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblTitol = gcnew System::Windows::Forms::Label();
            this->dgvAssaigs = gcnew System::Windows::Forms::DataGridView();
            this->lblMissatge = gcnew System::Windows::Forms::Label();
            this->btnTancar = gcnew System::Windows::Forms::Button();
            this->SuspendLayout();
            //
            // lblTitol
            //
            this->lblTitol->AutoSize = true;
            this->lblTitol->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold);
            this->lblTitol->Location = System::Drawing::Point(100, 20);
            this->lblTitol->Text = L"Consultar Assaigs";
            //
            // dgvAssaigs
            //
            this->dgvAssaigs->Location = System::Drawing::Point(20, 70);
            this->dgvAssaigs->Size = System::Drawing::Size(560, 300);
            this->dgvAssaigs->ReadOnly = true;
            this->dgvAssaigs->AllowUserToAddRows = false;
            this->dgvAssaigs->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            //
            // lblMissatge
            //
            this->lblMissatge->AutoSize = true;
            this->lblMissatge->Location = System::Drawing::Point(20, 385);
            this->lblMissatge->Text = L"";
            //
            // btnTancar
            //
            this->btnTancar->Location = System::Drawing::Point(240, 410);
            this->btnTancar->Size = System::Drawing::Size(100, 35);
            this->btnTancar->Text = L"Tancar";
            this->btnTancar->Click += gcnew System::EventHandler(this, &ConsultarAssaigForm::btnTancar_Click);
            //
            // ConsultarAssaigForm
            //
            this->ClientSize = System::Drawing::Size(620, 470);
            this->Controls->Add(this->lblTitol);
            this->Controls->Add(this->dgvAssaigs);
            this->Controls->Add(this->lblMissatge);
            this->Controls->Add(this->btnTancar);
            this->Text = L"Consultar Assaigs";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->ResumeLayout(false);
            this->PerformLayout();
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