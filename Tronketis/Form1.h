#pragma once
#include "CercadorUsuari.h"

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form1 : public Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
                delete components;
        }

    private:
        System::Windows::Forms::TextBox^ txtMail;
        System::Windows::Forms::Button^ btnBuscar;
        System::Windows::Forms::Label^ lblResultado;
        System::Windows::Forms::Label^ label1;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->txtMail = (gcnew System::Windows::Forms::TextBox());
            this->btnBuscar = (gcnew System::Windows::Forms::Button());
            this->lblResultado = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();

            // === FONDO DEL FORM ===
            this->BackColor = System::Drawing::Color::FromArgb(245, 245, 250);

            // === LABEL ===
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(50, 40);
            this->label1->Text = L"Correu electrònic:";
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(60, 60, 60);
            this->label1->TabIndex = 3;

            // === TEXTBOX ===
            this->txtMail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtMail->ForeColor = System::Drawing::Color::Gray;
            this->txtMail->BackColor = System::Drawing::Color::White;
            this->txtMail->Location = System::Drawing::Point(50, 65);
            this->txtMail->Size = System::Drawing::Size(280, 34);
            this->txtMail->Text = L"exemple@gmail.com";
            this->txtMail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txtMail->TabIndex = 0;
            this->txtMail->Enter += gcnew System::EventHandler(this, &Form1::txtMail_Enter);
            this->txtMail->Leave += gcnew System::EventHandler(this, &Form1::txtMail_Leave);

            // === BOTÓN ===
            this->btnBuscar->Location = System::Drawing::Point(50, 115);
            this->btnBuscar->Size = System::Drawing::Size(120, 38);
            this->btnBuscar->Text = L"🔍 Buscar";
            this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnBuscar->BackColor = System::Drawing::Color::FromArgb(0, 120, 215);
            this->btnBuscar->ForeColor = System::Drawing::Color::White;
            this->btnBuscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnBuscar->FlatAppearance->BorderSize = 0;
            this->btnBuscar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnBuscar->TabIndex = 1;
            this->btnBuscar->Click += gcnew System::EventHandler(this, &Form1::btnBuscar_Click);

            // === LABEL RESULTADO ===
            this->lblResultado->Location = System::Drawing::Point(50, 175);
            this->lblResultado->Size = System::Drawing::Size(500, 60);
            this->lblResultado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblResultado->ForeColor = System::Drawing::Color::FromArgb(30, 30, 30);
            this->lblResultado->TabIndex = 2;

            // === FORM ===
            this->ClientSize = System::Drawing::Size(600, 300);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->txtMail);
            this->Controls->Add(this->btnBuscar);
            this->Controls->Add(this->lblResultado);
            this->Name = L"Form1";
            this->Text = L"Buscar Usuari";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private:
        System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ mail = txtMail->Text;

            if (mail == "exemple@gmail.com" || mail == "")
            {
                lblResultado->Text = "Introdueix un correu electrònic.";
                return;
            }

            String^ dni;
            String^ username;
            String^ password;
            String^ rol;

            if (CercadorUsuari::CercaPerEmail(mail, dni, username, password, rol))
            {
                lblResultado->Text = "Mail: " + mail + " | DNI: " + dni + " | Usuari: " + username + " | Rol: " + rol;
            }
            else
            {
                lblResultado->Text = "Usuari no trobat.";
            }
        }

    private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) { }

    private: System::Void txtMail_Enter(System::Object^ sender, System::EventArgs^ e) {
        if (this->txtMail->Text == "exemple@gmail.com") {
            this->txtMail->Text = "";
            this->txtMail->ForeColor = System::Drawing::Color::Black;
        }
    }

    private: System::Void txtMail_Leave(System::Object^ sender, System::EventArgs^ e) {
        if (this->txtMail->Text == "") {
            this->txtMail->Text = "exemple@gmail.com";
            this->txtMail->ForeColor = System::Drawing::Color::Gray;
        }
    }

    };
}