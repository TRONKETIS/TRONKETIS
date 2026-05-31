#pragma once

#include "PasarelaColla.h"
#include "CollaDTO.h"

namespace Tronketis {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    public ref class DetallCollaForm : public System::Windows::Forms::Form
    {
    private:
        int collaId;
        System::Windows::Forms::Label^ LabelNom;
        System::Windows::Forms::Label^ LabelLocalitzacio;
        System::Windows::Forms::Label^ LabelUniversitat;
        System::Windows::Forms::Label^ LabelNomValue;
        System::Windows::Forms::Label^ LabelLocalitzacioValue;
        System::Windows::Forms::Label^ LabelUniversitatValue;
        System::Windows::Forms::PictureBox^ LogoPictureBox;
        System::ComponentModel::Container^ components;

    public:
        DetallCollaForm(int id)
        {
            collaId = id;
            this->InitializeComponent();
            this->LoadCollaData();
        }

    protected:
        ~DetallCollaForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        void InitializeComponent(void)
        {
            this->LabelNom = gcnew System::Windows::Forms::Label();
            this->LabelLocalitzacio = gcnew System::Windows::Forms::Label();
            this->LabelUniversitat = gcnew System::Windows::Forms::Label();
            this->LabelNomValue = gcnew System::Windows::Forms::Label();
            this->LabelLocalitzacioValue = gcnew System::Windows::Forms::Label();
            this->LabelUniversitatValue = gcnew System::Windows::Forms::Label();
            this->LogoPictureBox = gcnew System::Windows::Forms::PictureBox();

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->BeginInit();
            this->SuspendLayout();

            // LabelNom
            this->LabelNom->AutoSize = true;
            this->LabelNom->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelNom->Location = System::Drawing::Point(30, 40);
            this->LabelNom->Name = L"LabelNom";
            this->LabelNom->Size = System::Drawing::Size(45, 18);
            this->LabelNom->Text = L"Nom:";

            // LabelLocalitzacio
            this->LabelLocalitzacio->AutoSize = true;
            this->LabelLocalitzacio->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelLocalitzacio->Location = System::Drawing::Point(30, 90);
            this->LabelLocalitzacio->Name = L"LabelLocalitzacio";
            this->LabelLocalitzacio->Size = System::Drawing::Size(100, 18);
            this->LabelLocalitzacio->Text = L"Localització:";

            // LabelUniversitat
            this->LabelUniversitat->AutoSize = true;
            this->LabelUniversitat->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelUniversitat->Location = System::Drawing::Point(30, 140);
            this->LabelUniversitat->Name = L"LabelUniversitat";
            this->LabelUniversitat->Size = System::Drawing::Size(95, 18);
            this->LabelUniversitat->Text = L"Universitat:";

            // LabelNomValue
            this->LabelNomValue->AutoSize = true;
            this->LabelNomValue->Location = System::Drawing::Point(150, 40);
            this->LabelNomValue->Name = L"LabelNomValue";
            this->LabelNomValue->Size = System::Drawing::Size(150, 16);
            this->LabelNomValue->Text = L"Carregant...";

            // LabelLocalitzacioValue
            this->LabelLocalitzacioValue->AutoSize = true;
            this->LabelLocalitzacioValue->Location = System::Drawing::Point(150, 90);
            this->LabelLocalitzacioValue->Name = L"LabelLocalitzacioValue";
            this->LabelLocalitzacioValue->Size = System::Drawing::Size(150, 16);
            this->LabelLocalitzacioValue->Text = L"Carregant...";

            // LabelUniversitatValue
            this->LabelUniversitatValue->AutoSize = true;
            this->LabelUniversitatValue->Location = System::Drawing::Point(150, 140);
            this->LabelUniversitatValue->Name = L"LabelUniversitatValue";
            this->LabelUniversitatValue->Size = System::Drawing::Size(150, 16);
            this->LabelUniversitatValue->Text = L"Carregant...";

            // LogoPictureBox
            this->LogoPictureBox->BackColor = System::Drawing::Color::Gainsboro;
            this->LogoPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->LogoPictureBox->Location = System::Drawing::Point(350, 30);
            this->LogoPictureBox->Name = L"LogoPictureBox";
            this->LogoPictureBox->Size = System::Drawing::Size(120, 120);
            this->LogoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;

            // DetallCollaForm
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(500, 220);
            this->Controls->Add(this->LogoPictureBox);
            this->Controls->Add(this->LabelUniversitatValue);
            this->Controls->Add(this->LabelLocalitzacioValue);
            this->Controls->Add(this->LabelNomValue);
            this->Controls->Add(this->LabelUniversitat);
            this->Controls->Add(this->LabelLocalitzacio);
            this->Controls->Add(this->LabelNom);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"DetallCollaForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Detall de la Colla";

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void LoadCollaData()
        {
            try {
                CollaDTO^ colla = PasarelaColla::obtenirPerId(collaId);
                if (colla != nullptr) {
                    this->LabelNomValue->Text = colla->nom;
                    this->LabelLocalitzacioValue->Text = colla->localitzacio;
                    this->LabelUniversitatValue->Text = colla->univ;

                    if (colla->logo != nullptr && colla->logo->Length > 0) {
                        MemoryStream^ ms = gcnew MemoryStream(colla->logo);
                        this->LogoPictureBox->Image = Image::FromStream(ms);
                    }
                }
                else {
                    this->LabelNomValue->Text = L"No s'ha trobat la colla";
                }
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error al carregar detalls: " + ex->Message);
            }
        }
    };
}