#pragma once
#include "CtrlAdminMenu.h"
#include "CollaDTO.h"
#include "UsuariDTO.h"

namespace Tronketis {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class AsignarCapForm : public System::Windows::Forms::Form
    {
    public:
        AsignarCapForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~AsignarCapForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::ComboBox^ cbCollas;
    private: System::Windows::Forms::ComboBox^ cbUsuarios;
    private: System::Windows::Forms::TextBox^ txtTelefon;
    private: System::Windows::Forms::Button^ btnAsignar;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->cbCollas = (gcnew System::Windows::Forms::ComboBox());
            this->cbUsuarios = (gcnew System::Windows::Forms::ComboBox());
            this->txtTelefon = (gcnew System::Windows::Forms::TextBox());
            this->btnAsignar = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 40);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(100, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Selecciona la Colla:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(12, 100);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(113, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Selecciona el Usuario:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(12, 160);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(119, 13);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Teléfono del cap:";
            // 
            // cbCollas
            // 
            this->cbCollas->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cbCollas->FormattingEnabled = true;
            this->cbCollas->Location = System::Drawing::Point(150, 37);
            this->cbCollas->Name = L"cbCollas";
            this->cbCollas->Size = System::Drawing::Size(180, 21);
            this->cbCollas->TabIndex = 2;
            // 
            // cbUsuarios
            // 
            this->cbUsuarios->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cbUsuarios->FormattingEnabled = true;
            this->cbUsuarios->Location = System::Drawing::Point(150, 97);
            this->cbUsuarios->Name = L"cbUsuarios";
            this->cbUsuarios->Size = System::Drawing::Size(180, 21);
            this->cbUsuarios->TabIndex = 3;
            // 
            // txtTelefon
            // 
            this->txtTelefon->Location = System::Drawing::Point(150, 157);
            this->txtTelefon->Name = L"txtTelefon";
            this->txtTelefon->Size = System::Drawing::Size(180, 20);
            this->txtTelefon->TabIndex = 4;
            // 
            // btnAsignar
            // 
            this->btnAsignar->Location = System::Drawing::Point(90, 225);
            this->btnAsignar->Name = L"btnAsignar";
            this->btnAsignar->Size = System::Drawing::Size(180, 28);
            this->btnAsignar->TabIndex = 6;
            this->btnAsignar->Text = L"Asignar Cap de Colla";
            this->btnAsignar->UseVisualStyleBackColor = true;
            this->btnAsignar->Click += gcnew System::EventHandler(this, &AsignarCapForm::button1_Click);
            // 
            // AsignarCapForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(360, 285);
            this->Controls->Add(this->btnAsignar);
            this->Controls->Add(this->txtTelefon);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->cbUsuarios);
            this->Controls->Add(this->cbCollas);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"AsignarCapForm";
            this->Text = L"Asignar Cap de Colla";
            this->Load += gcnew System::EventHandler(this, &AsignarCapForm::AsignarCapForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->cbCollas->SelectedIndex == -1 || this->cbUsuarios->SelectedIndex == -1) {
            MessageBox::Show("Por favor, selecciona una Colla y un Usuario.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        String^ nombreCollaSel = safe_cast<String^>(this->cbCollas->SelectedValue);
        String^ dniUsuarioSel = safe_cast<String^>(this->cbUsuarios->SelectedValue);
        String^ telefon = this->txtTelefon->Text;
        String^ error = "";

        try {
            if (CtrlAdminMenu::AsignarCapDeColla(nombreCollaSel, dniUsuarioSel, telefon, error)) {
                MessageBox::Show("Cap de Colla asignado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->Close();
            }
            else {
                MessageBox::Show(error, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ocurrió un error de sistema: " + ex->Message, "Error Fatal", MessageBoxButtons::OK, MessageBoxIcon::Stop);
        }
    }

    private: System::Void AsignarCapForm_Load(System::Object^ sender, System::EventArgs^ e) {
        try {
            List<CollaDTO^>^ listaCollas = CtrlAdminMenu::ObtenerListaCollas();
            this->cbCollas->DataSource = listaCollas;
            this->cbCollas->DisplayMember = "nom";
            this->cbCollas->ValueMember = "nom";
            this->cbCollas->SelectedIndex = -1;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error cargando collas: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        try {
            List<UsuariDTO^>^ listaUsuarios = CtrlAdminMenu::ObtenerListaUsuarios();
            this->cbUsuarios->DataSource = listaUsuarios;
            this->cbUsuarios->DisplayMember = "username";
            this->cbUsuarios->ValueMember = "dni";
            this->cbUsuarios->SelectedIndex = -1;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error cargando usuarios: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    };
}
