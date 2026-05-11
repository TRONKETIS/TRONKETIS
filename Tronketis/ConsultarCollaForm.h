

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

    public ref class ConsultarCollaForm : public System::Windows::Forms::Form
    {
    private:
        int collaId;

    public:
        ConsultarCollaForm(int id)
        {
            collaId = id;
            InitializeComponent();
            LoadCollaData();
        }

    protected:
        ~ConsultarCollaForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ LabelNom;
        System::Windows::Forms::Label^ LabelLocalitzacio;
        System::Windows::Forms::Label^ LabelUniversitat;
        System::Windows::Forms::Label^ LabelNomValue;
        System::Windows::Forms::Label^ LabelLocalitzacioValue;
        System::Windows::Forms::Label^ LabelUniversitatValue;
        System::Windows::Forms::PictureBox^ LogoPictureBox;
        System::ComponentModel::Container^ components;

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
            this->LabelNom->AutoSize = true;
            this->LabelNom->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelNom->Location = System::Drawing::Point(80, 70);
            this->LabelNom->Name = L"LabelNom";
            this->LabelNom->Size = System::Drawing::Size(45, 18);
            this->LabelNom->TabIndex = 0;
            this->LabelNom->Text = L"Nom:";
            this->LabelLocalitzacio->AutoSize = true;
            this->LabelLocalitzacio->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelLocalitzacio->Location = System::Drawing::Point(80, 120);
            this->LabelLocalitzacio->Name = L"LabelLocalitzacio";
            this->LabelLocalitzacio->Size = System::Drawing::Size(100, 18);
            this->LabelLocalitzacio->TabIndex = 1;
            this->LabelLocalitzacio->Text = L"Localització:";
            this->LabelUniversitat->AutoSize = true;
            this->LabelUniversitat->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelUniversitat->Location = System::Drawing::Point(80, 170);
            this->LabelUniversitat->Name = L"LabelUniversitat";
            this->LabelUniversitat->Size = System::Drawing::Size(95, 18);
            this->LabelUniversitat->TabIndex = 2;
            this->LabelUniversitat->Text = L"Universitat:";
            this->LabelNomValue->AutoSize = true;
            this->LabelNomValue->Location = System::Drawing::Point(200, 70);
            this->LabelNomValue->Name = L"LabelNomValue";
            this->LabelNomValue->Size = System::Drawing::Size(0, 16);
            this->LabelNomValue->TabIndex = 3;
            this->LabelLocalitzacioValue->AutoSize = true;
            this->LabelLocalitzacioValue->Location = System::Drawing::Point(200, 120);
            this->LabelLocalitzacioValue->Name = L"LabelLocalitzacioValue";
            this->LabelLocalitzacioValue->Size = System::Drawing::Size(0, 16);
            this->LabelLocalitzacioValue->TabIndex = 4;
            this->LabelUniversitatValue->AutoSize = true;
            this->LabelUniversitatValue->Location = System::Drawing::Point(200, 170);
            this->LabelUniversitatValue->Name = L"LabelUniversitatValue";
            this->LabelUniversitatValue->Size = System::Drawing::Size(0, 16);
            this->LabelUniversitatValue->TabIndex = 5;
            this->LogoPictureBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
            this->LogoPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->LogoPictureBox->Location = System::Drawing::Point(400, 70);
            this->LogoPictureBox->Name = L"LogoPictureBox";
            this->LogoPictureBox->Size = System::Drawing::Size(100, 100);
            this->LogoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->LogoPictureBox->TabIndex = 6;
            this->LogoPictureBox->TabStop = false;
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(600, 300);
            this->Controls->Add(this->LogoPictureBox);
            this->Controls->Add(this->LabelUniversitatValue);
            this->Controls->Add(this->LabelLocalitzacioValue);
            this->Controls->Add(this->LabelNomValue);
            this->Controls->Add(this->LabelUniversitat);
            this->Controls->Add(this->LabelLocalitzacio);
            this->Controls->Add(this->LabelNom);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"ConsultarCollaForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Consultar Colla";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void LoadCollaData()
        {
            CollaDTO^ colla = PasarelaColla::obtenirPerId(collaId);
            if (colla != nullptr) {
                LabelNomValue->Text = colla->nom;
                LabelLocalitzacioValue->Text = colla->localitzacio;
                LabelUniversitatValue->Text = colla->univ;

                if (colla->logo != nullptr && colla->logo->Length > 0) {
                    MemoryStream^ ms = gcnew MemoryStream(colla->logo);
                    LogoPictureBox->Image = Image::FromStream(ms);
                }
            }
        }
    };
}

