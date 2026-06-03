

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

    public ref class EditarCollaForm : public System::Windows::Forms::Form
    {
    private:
        int collaId;
        array<Byte>^ logoData;
        String^ rutaLogoTemporal;

    public:
        EditarCollaForm(int id)
        {
            collaId = id;
            logoData = nullptr;
            rutaLogoTemporal = nullptr;
            InitializeComponent();
            LoadCollaData();
        }

    protected:
        ~EditarCollaForm()
        {
            if (rutaLogoTemporal != nullptr && File::Exists(rutaLogoTemporal)) {
                try {
                    File::Delete(rutaLogoTemporal);
                }
                catch (...) {}
            }

            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ NameCollatxt;
        System::Windows::Forms::TextBox^ LocationCollatxt;
        System::Windows::Forms::TextBox^ UniNameCollatxt;
        System::Windows::Forms::Label^ LabelNomColla;
        System::Windows::Forms::Label^ LabelLogoColla;
        System::Windows::Forms::Label^ LabelLocalitzacioColla;
        System::Windows::Forms::Label^ LabelUniversitatColla;
        System::Windows::Forms::Button^ BtnGuardarCanvis;
        System::Windows::Forms::Button^ BtnNetejar;
        System::Windows::Forms::PictureBox^ LogoPictureBox;
        System::Windows::Forms::Button^ BtnPujarLogo;
        System::Windows::Forms::Button^ BtnEliminarLogo;
        System::Windows::Forms::Label^ LabelInfoLogo;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->NameCollatxt = gcnew System::Windows::Forms::TextBox();
            this->LocationCollatxt = gcnew System::Windows::Forms::TextBox();
            this->UniNameCollatxt = gcnew System::Windows::Forms::TextBox();
            this->LabelNomColla = gcnew System::Windows::Forms::Label();
            this->LabelLogoColla = gcnew System::Windows::Forms::Label();
            this->LabelLocalitzacioColla = gcnew System::Windows::Forms::Label();
            this->LabelUniversitatColla = gcnew System::Windows::Forms::Label();
            this->BtnGuardarCanvis = gcnew System::Windows::Forms::Button();
            this->BtnNetejar = gcnew System::Windows::Forms::Button();
            this->LogoPictureBox = gcnew System::Windows::Forms::PictureBox();
            this->BtnPujarLogo = gcnew System::Windows::Forms::Button();
            this->BtnEliminarLogo = gcnew System::Windows::Forms::Button();
            this->LabelInfoLogo = gcnew System::Windows::Forms::Label();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->BeginInit();
            this->SuspendLayout();
            this->NameCollatxt->Location = System::Drawing::Point(280, 70);
            this->NameCollatxt->Name = L"NameCollatxt";
            this->NameCollatxt->Size = System::Drawing::Size(300, 22);
            this->NameCollatxt->TabIndex = 0;
            this->LocationCollatxt->Location = System::Drawing::Point(280, 120);
            this->LocationCollatxt->Name = L"LocationCollatxt";
            this->LocationCollatxt->Size = System::Drawing::Size(300, 22);
            this->LocationCollatxt->TabIndex = 1;
            this->UniNameCollatxt->Location = System::Drawing::Point(280, 170);
            this->UniNameCollatxt->Name = L"UniNameCollatxt";
            this->UniNameCollatxt->Size = System::Drawing::Size(300, 22);
            this->UniNameCollatxt->TabIndex = 2;
            this->LabelNomColla->AutoSize = true;
            this->LabelNomColla->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelNomColla->Location = System::Drawing::Point(80, 73);
            this->LabelNomColla->Name = L"LabelNomColla";
            this->LabelNomColla->Size = System::Drawing::Size(56, 18);
            this->LabelNomColla->TabIndex = 3;
            this->LabelNomColla->Text = L"Nom:*";
            this->LabelLogoColla->AutoSize = true;
            this->LabelLogoColla->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelLogoColla->Location = System::Drawing::Point(80, 220);
            this->LabelLogoColla->Name = L"LabelLogoColla";
            this->LabelLogoColla->Size = System::Drawing::Size(51, 18);
            this->LabelLogoColla->TabIndex = 4;
            this->LabelLogoColla->Text = L"Logo:";
            this->LabelLocalitzacioColla->AutoSize = true;
            this->LabelLocalitzacioColla->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelLocalitzacioColla->Location = System::Drawing::Point(80, 123);
            this->LabelLocalitzacioColla->Name = L"LabelLocalitzacioColla";
            this->LabelLocalitzacioColla->Size = System::Drawing::Size(111, 18);
            this->LabelLocalitzacioColla->TabIndex = 5;
            this->LabelLocalitzacioColla->Text = L"Localització:*";
            this->LabelUniversitatColla->AutoSize = true;
            this->LabelUniversitatColla->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold);
            this->LabelUniversitatColla->Location = System::Drawing::Point(80, 173);
            this->LabelUniversitatColla->Name = L"LabelUniversitatColla";
            this->LabelUniversitatColla->Size = System::Drawing::Size(100, 18);
            this->LabelUniversitatColla->TabIndex = 6;
            this->LabelUniversitatColla->Text = L"Universitat:";
            this->BtnGuardarCanvis->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(123)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->BtnGuardarCanvis->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BtnGuardarCanvis->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold);
            this->BtnGuardarCanvis->ForeColor = System::Drawing::Color::White;
            this->BtnGuardarCanvis->Location = System::Drawing::Point(280, 350);
            this->BtnGuardarCanvis->Name = L"BtnGuardarCanvis";
            this->BtnGuardarCanvis->Size = System::Drawing::Size(180, 40);
            this->BtnGuardarCanvis->TabIndex = 7;
            this->BtnGuardarCanvis->Text = L"Guardar Canvis";
            this->BtnGuardarCanvis->UseVisualStyleBackColor = false;
            this->BtnGuardarCanvis->Click += gcnew System::EventHandler(this, &EditarCollaForm::BtnGuardarCanvis_Click);
            this->BtnNetejar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BtnNetejar->Location = System::Drawing::Point(480, 350);
            this->BtnNetejar->Name = L"BtnNetejar";
            this->BtnNetejar->Size = System::Drawing::Size(100, 40);
            this->BtnNetejar->TabIndex = 8;
            this->BtnNetejar->Text = L"Netejar";
            this->BtnNetejar->UseVisualStyleBackColor = true;
            this->BtnNetejar->Click += gcnew System::EventHandler(this, &EditarCollaForm::BtnNetejar_Click);
            this->LogoPictureBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
            this->LogoPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->LogoPictureBox->Location = System::Drawing::Point(280, 220);
            this->LogoPictureBox->Name = L"LogoPictureBox";
            this->LogoPictureBox->Size = System::Drawing::Size(70, 64);
            this->LogoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->LogoPictureBox->TabIndex = 9;
            this->LogoPictureBox->TabStop = false;
            this->BtnPujarLogo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BtnPujarLogo->Location = System::Drawing::Point(280, 290);
            this->BtnPujarLogo->Name = L"BtnPujarLogo";
            this->BtnPujarLogo->Size = System::Drawing::Size(140, 30);
            this->BtnPujarLogo->TabIndex = 10;
            this->BtnPujarLogo->Text = L"Pujar Logo";
            this->BtnPujarLogo->UseVisualStyleBackColor = true;
            this->BtnPujarLogo->Click += gcnew System::EventHandler(this, &EditarCollaForm::BtnPujarLogo_Click);
            this->BtnEliminarLogo->Enabled = false;
            this->BtnEliminarLogo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BtnEliminarLogo->Location = System::Drawing::Point(440, 290);
            this->BtnEliminarLogo->Name = L"BtnEliminarLogo";
            this->BtnEliminarLogo->Size = System::Drawing::Size(140, 30);
            this->BtnEliminarLogo->TabIndex = 11;
            this->BtnEliminarLogo->Text = L"Eliminar Logo";
            this->BtnEliminarLogo->UseVisualStyleBackColor = true;
            this->BtnEliminarLogo->Click += gcnew System::EventHandler(this, &EditarCollaForm::BtnEliminarLogo_Click);
            this->LabelInfoLogo->AutoSize = true;
            this->LabelInfoLogo->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F);
            this->LabelInfoLogo->ForeColor = System::Drawing::Color::Gray;
            this->LabelInfoLogo->Location = System::Drawing::Point(280, 330);
            this->LabelInfoLogo->Name = L"LabelInfoLogo";
            this->LabelInfoLogo->Size = System::Drawing::Size(219, 16);
            this->LabelInfoLogo->TabIndex = 12;
            this->LabelInfoLogo->Text = L"Formats: JPG, PNG, GIF (Màx. 5MB)";
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->ClientSize = System::Drawing::Size(700, 400);
            this->Controls->Add(this->LabelInfoLogo);
            this->Controls->Add(this->BtnEliminarLogo);
            this->Controls->Add(this->BtnPujarLogo);
            this->Controls->Add(this->LogoPictureBox);
            this->Controls->Add(this->BtnNetejar);
            this->Controls->Add(this->BtnGuardarCanvis);
            this->Controls->Add(this->LabelUniversitatColla);
            this->Controls->Add(this->LabelLocalitzacioColla);
            this->Controls->Add(this->LabelLogoColla);
            this->Controls->Add(this->LabelNomColla);
            this->Controls->Add(this->UniNameCollatxt);
            this->Controls->Add(this->LocationCollatxt);
            this->Controls->Add(this->NameCollatxt);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"EditarCollaForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Editar Colla";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void LoadCollaData()
        {
            CollaDTO^ colla = PasarelaColla::obtenirPerId(collaId);
            if (colla != nullptr) {
                NameCollatxt->Text = colla->nom;
                LocationCollatxt->Text = colla->localitzacio;
                UniNameCollatxt->Text = colla->univ;

                if (colla->logo != nullptr && colla->logo->Length > 0) {
                    MemoryStream^ ms = gcnew MemoryStream(colla->logo);
                    LogoPictureBox->Image = Image::FromStream(ms);
                    BtnEliminarLogo->Enabled = true;
                }
            }
        }

        void BtnPujarLogo_Click(System::Object^ sender, System::EventArgs^ e)
        {
            OpenFileDialog^ ofd = gcnew OpenFileDialog();
            ofd->Title = "Seleccionar Logo de la Colla";
            ofd->Filter = "Fitxers d'imatge|*.jpg;*.jpeg;*.png;*.gif|Tots els fitxers|*.*";
            ofd->FilterIndex = 1;
            ofd->RestoreDirectory = true;

            if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                try {
                    FileInfo^ fileInfo = gcnew FileInfo(ofd->FileName);
                    long midaFitxer = fileInfo->Length;

                    if (midaFitxer > 5 * 1024 * 1024) {
                        MessageBox::Show("El fitxer seleccionat supera els 5MB.");
                        return;
                    }

                    logoData = File::ReadAllBytes(ofd->FileName);
                    rutaLogoTemporal = ofd->FileName;
                    LogoPictureBox->Image = Image::FromFile(ofd->FileName);
                    BtnEliminarLogo->Enabled = true;
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error en carregar el logo: " + ex->Message);
                }
            }
        }

        void BtnEliminarLogo_Click(System::Object^ sender, System::EventArgs^ e)
        {
            logoData = nullptr;
            rutaLogoTemporal = nullptr;

            if (LogoPictureBox->Image != nullptr) {
                delete LogoPictureBox->Image;
                LogoPictureBox->Image = nullptr;
            }

            BtnEliminarLogo->Enabled = false;
        }

        void BtnGuardarCanvis_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ nom = NameCollatxt->Text->Trim();
            String^ localitzacio = LocationCollatxt->Text->Trim();
            String^ univ = UniNameCollatxt->Text->Trim();

            CollaDTO^ colla = gcnew CollaDTO();
            colla->id = collaId;
            colla->nom = nom;
            colla->localitzacio = localitzacio;
            colla->univ = univ;
            colla->logo = logoData;

            String^ error = nullptr;
            if (PasarelaColla::actualitzar(colla, error)) {
                MessageBox::Show("La colla s'ha actualitzat correctament.");
                this->Close();
            }
            else {
                MessageBox::Show("Error en actualitzar la colla: " + error);
            }
        }

        void BtnNetejar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            NameCollatxt->Text = "";
            LocationCollatxt->Text = "";
            UniNameCollatxt->Text = "";
            BtnEliminarLogo_Click(sender, e);
        }
    };
}

