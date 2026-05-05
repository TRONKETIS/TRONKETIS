#pragma once
#include "CercadorColla.h"

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form1 : public Form
    {
    public:
        Form1(void) { InitializeComponent(); }

    protected:
        ~Form1() { if (components) delete components; }

    private:
        System::Windows::Forms::TextBox^ txtNomColla;
        System::Windows::Forms::Button^ btnInhabilitar;
        System::Windows::Forms::Label^ lblResultado;
        System::Windows::Forms::Label^ label1;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->txtNomColla = (gcnew System::Windows::Forms::TextBox());
            this->btnInhabilitar = (gcnew System::Windows::Forms::Button());
            this->lblResultado = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();

            // FONDO
            this->BackColor = System::Drawing::Color::FromArgb(245, 245, 250);

            // LABEL
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(50, 40);
            this->label1->Text = L"Nom de la colla:";
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(60, 60, 60);
            this->label1->TabIndex = 0;

            // TEXTBOX
            this->txtNomColla->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtNomColla->Location = System::Drawing::Point(50, 65);
            this->txtNomColla->Size = System::Drawing::Size(280, 34);
            this->txtNomColla->TabIndex = 1;

            // BOTÓN
            this->btnInhabilitar->Location = System::Drawing::Point(50, 115);
            this->btnInhabilitar->Size = System::Drawing::Size(150, 38);
            this->btnInhabilitar->Text = L"🚫 Inhabilitar";
            this->btnInhabilitar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnInhabilitar->BackColor = System::Drawing::Color::FromArgb(200, 50, 50);
            this->btnInhabilitar->ForeColor = System::Drawing::Color::White;
            this->btnInhabilitar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnInhabilitar->FlatAppearance->BorderSize = 0;
            this->btnInhabilitar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnInhabilitar->TabIndex = 2;
            this->btnInhabilitar->Click += gcnew System::EventHandler(this, &Form1::btnInhabilitar_Click);

            // RESULTADO
            this->lblResultado->Location = System::Drawing::Point(50, 175);
            this->lblResultado->Size = System::Drawing::Size(500, 30);
            this->lblResultado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblResultado->TabIndex = 3;

            // FORM
            this->ClientSize = System::Drawing::Size(600, 280);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->txtNomColla);
            this->Controls->Add(this->btnInhabilitar);
            this->Controls->Add(this->lblResultado);
            this->Name = L"Form1";
            this->Text = L"Inhabilitar Colla";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private:
        System::Void btnInhabilitar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ nom = txtNomColla->Text->Trim();

            if (nom == "")
            {
                lblResultado->Text = "Introdueix el nom de la colla.";
                return;
            }

            if (CercadorColla::InhabilitarColla(nom))
            {
                lblResultado->ForeColor = System::Drawing::Color::FromArgb(0, 150, 0);
                lblResultado->Text = "Colla '" + nom + "' inhabilitada correctament.";
            }
            else
            {
                lblResultado->ForeColor = System::Drawing::Color::FromArgb(200, 50, 50);
                lblResultado->Text = "No s'ha trobat cap colla amb aquest nom.";
            }
        }
    };
}