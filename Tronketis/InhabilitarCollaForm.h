#pragma once
#include "CercadorColla.h"
#include "CtrlInhabilitarColla.h"

namespace Tronketis {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace MySql::Data::MySqlClient;

    public ref class InhabilitarCollaForm : public Form
    {
    public:
        InhabilitarCollaForm(void) { InitializeComponent(); }

    protected:
        ~InhabilitarCollaForm() { if (components) delete components; }

    private:
        System::Windows::Forms::ComboBox^ txtNomColla;
        System::Windows::Forms::Button^ btnInhabilitar;
        System::Windows::Forms::Label^ lblResultado;
        System::Windows::Forms::Label^ label1;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->txtNomColla = (gcnew System::Windows::Forms::ComboBox());
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

            // COMBOBOX
            this->txtNomColla->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtNomColla->Location = System::Drawing::Point(50, 65);
            this->txtNomColla->Size = System::Drawing::Size(280, 34);
            this->txtNomColla->TabIndex = 1;
            this->txtNomColla->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDown;

            // BOTON
            this->btnInhabilitar->Location = System::Drawing::Point(50, 115);
            this->btnInhabilitar->Size = System::Drawing::Size(150, 38);
            this->btnInhabilitar->Text = L"Inhabilitar";
            this->btnInhabilitar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnInhabilitar->BackColor = System::Drawing::Color::FromArgb(200, 50, 50);
            this->btnInhabilitar->ForeColor = System::Drawing::Color::White;
            this->btnInhabilitar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnInhabilitar->FlatAppearance->BorderSize = 0;
            this->btnInhabilitar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnInhabilitar->TabIndex = 2;
            this->btnInhabilitar->Click += gcnew System::EventHandler(this, &InhabilitarCollaForm::btnInhabilitar_Click);

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
            this->Name = L"InhabilitarCollaForm";
            this->Text = L"Inhabilitar Colla";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Load += gcnew System::EventHandler(this, &InhabilitarCollaForm::Form_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private: System::Void Form_Load(System::Object^ sender, System::EventArgs^ e)
    {
        CarregarColles();
    }

    private: void CarregarColles()
    {
        List<String^>^ colles = CtrlInhabilitarColla::obtenirCollesActives();
        for each (String ^ nom in colles)
        {
            txtNomColla->Items->Add(nom);
        }
    }

    private: System::Void btnInhabilitar_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ nom = txtNomColla->Text->Trim();
        String^ error = "";

        if (CtrlInhabilitarColla::inhabilitar(nom, error))
        {
            lblResultado->ForeColor = System::Drawing::Color::FromArgb(0, 150, 0);
            lblResultado->Text = "Colla '" + nom + "' inhabilitada correctament.";
            txtNomColla->Items->Remove(nom);
            txtNomColla->Text = "";
        }
        else
        {
            lblResultado->ForeColor = System::Drawing::Color::FromArgb(200, 50, 50);
            lblResultado->Text = error;
        }
    }
    };
}