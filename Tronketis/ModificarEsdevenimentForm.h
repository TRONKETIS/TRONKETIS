
#pragma once

namespace Tronketis {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ModificarEsdevenimentForm : public System::Windows::Forms::Form {
    public:
        ModificarEsdevenimentForm(void) {
            InitializeComponent();
        }

    protected:
        ~ModificarEsdevenimentForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ labelNom;
        System::Windows::Forms::TextBox^ textBoxNom;
        System::Windows::Forms::Label^ labelData;
        System::Windows::Forms::TextBox^ textBoxData;
        System::Windows::Forms::Button^ buttonGuardar;

        void InitializeComponent(void) {
            this->labelNom = gcnew System::Windows::Forms::Label();
            this->textBoxNom = gcnew System::Windows::Forms::TextBox();
            this->labelData = gcnew System::Windows::Forms::Label();
            this->textBoxData = gcnew System::Windows::Forms::TextBox();
            this->buttonGuardar = gcnew System::Windows::Forms::Button();

            this->SuspendLayout();
            //
            // labelNom
            //
            this->labelNom->AutoSize = true;
            this->labelNom->Location = System::Drawing::Point(20, 20);
            this->labelNom->Name = L"labelNom";
            this->labelNom->Size = System::Drawing::Size(35, 13);
            this->labelNom->TabIndex = 0;
            this->labelNom->Text = L"Nom:";
            //
            // textBoxNom
            //
            this->textBoxNom->Location = System::Drawing::Point(100, 20);
            this->textBoxNom->Name = L"textBoxNom";
            this->textBoxNom->Size = System::Drawing::Size(200, 20);
            this->textBoxNom->TabIndex = 1;
            //
            // labelData
            //
            this->labelData->AutoSize = true;
            this->labelData->Location = System::Drawing::Point(20, 60);
            this->labelData->Name = L"labelData";
            this->labelData->Size = System::Drawing::Size(36, 13);
            this->labelData->TabIndex = 2;
            this->labelData->Text = L"Data:";
            //
            // textBoxData
            //
            this->textBoxData->Location = System::Drawing::Point(100, 60);
            this->textBoxData->Name = L"textBoxData";
            this->textBoxData->Size = System::Drawing::Size(200, 20);
            this->textBoxData->TabIndex = 3;
            //
            // buttonGuardar
            //
            this->buttonGuardar->Location = System::Drawing::Point(150, 100);
            this->buttonGuardar->Name = L"buttonGuardar";
            this->buttonGuardar->Size = System::Drawing::Size(100, 23);
            this->buttonGuardar->TabIndex = 4;
            this->buttonGuardar->Text = L"Guardar";
            this->buttonGuardar->UseVisualStyleBackColor = true;
            this->buttonGuardar->Click += gcnew System::EventHandler(this, &ModificarEsdevenimentForm::buttonGuardar_Click);
            //
            // ModificarEsdevenimentForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(400, 150);
            this->Controls->Add(this->labelNom);
            this->Controls->Add(this->textBoxNom);
            this->Controls->Add(this->labelData);
            this->Controls->Add(this->textBoxData);
            this->Controls->Add(this->buttonGuardar);
            this->Name = L"ModificarEsdevenimentForm";
            this->Text = L"Modificar Esdeveniment";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void buttonGuardar_Click(Object^ sender, EventArgs^ e) {
            // Handle the save button click event
            MessageBox::Show("Esdeveniment modificat amb èxit!", "Informació");
        }
    };
}
