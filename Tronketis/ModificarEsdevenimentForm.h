
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
        System::Windows::Forms::Label^ labelLocation;
        System::Windows::Forms::TextBox^ textBoxLocation;
        System::Windows::Forms::Label^ labelAproxMem;
        System::Windows::Forms::NumericUpDown^ numericUpDownAproxMem;
        System::Windows::Forms::Button^ buttonGuardar;

        void InitializeComponent(void) {
            this->labelNom = gcnew System::Windows::Forms::Label();
            this->textBoxNom = gcnew System::Windows::Forms::TextBox();
            this->labelData = gcnew System::Windows::Forms::Label();
            this->textBoxData = gcnew System::Windows::Forms::TextBox();
            this->labelNom = gcnew System::Windows::Forms::Label();
            this->textBoxNom = gcnew System::Windows::Forms::TextBox();
            this->labelData = gcnew System::Windows::Forms::Label();
            this->textBoxData = gcnew System::Windows::Forms::TextBox();
            this->labelLocation = gcnew System::Windows::Forms::Label();
            this->textBoxLocation = gcnew System::Windows::Forms::TextBox();
            this->labelAproxMem = gcnew System::Windows::Forms::Label();
            this->numericUpDownAproxMem = gcnew System::Windows::Forms::NumericUpDown();
            this->buttonGuardar = gcnew System::Windows::Forms::Button();

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownAproxMem))->BeginInit();

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
            // labelLocation
            //
            this->labelLocation->AutoSize = true;
            this->labelLocation->Location = System::Drawing::Point(20, 100);
            this->labelLocation->Name = L"labelLocation";
            this->labelLocation->Size = System::Drawing::Size(51, 13);
            this->labelLocation->TabIndex = 4;
            this->labelLocation->Text = L"Ubicació:";
            //
            // textBoxLocation
            //
            this->textBoxLocation->Location = System::Drawing::Point(100, 100);
            this->textBoxLocation->Name = L"textBoxLocation";
            this->textBoxLocation->Size = System::Drawing::Size(200, 20);
            this->textBoxLocation->TabIndex = 5;
            //
            // labelAproxMem
            //
            this->labelAproxMem->AutoSize = true;
            this->labelAproxMem->Location = System::Drawing::Point(20, 140);
            this->labelAproxMem->Name = L"labelAproxMem";
            this->labelAproxMem->Size = System::Drawing::Size(103, 13);
            this->labelAproxMem->TabIndex = 6;
            this->labelAproxMem->Text = L"Membres Aproximats:";
            //
            // numericUpDownAproxMem
            //
            this->numericUpDownAproxMem->Location = System::Drawing::Point(130, 140);
            this->numericUpDownAproxMem->Name = L"numericUpDownAproxMem";
            this->numericUpDownAproxMem->Size = System::Drawing::Size(170, 20);
            this->numericUpDownAproxMem->TabIndex = 7;
            //
            // buttonGuardar
            //
            this->buttonGuardar->Location = System::Drawing::Point(150, 180);
            this->buttonGuardar->Name = L"buttonGuardar";
            this->buttonGuardar->Size = System::Drawing::Size(100, 23);
            this->buttonGuardar->TabIndex = 8;
            this->buttonGuardar->Text = L"Guardar";
            this->buttonGuardar->UseVisualStyleBackColor = true;
            this->buttonGuardar->Click += gcnew System::EventHandler(this, &ModificarEsdevenimentForm::buttonGuardar_Click);
            //
            // ModificarEsdevenimentForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(400, 220);
            this->Controls->Add(this->labelNom);
            this->Controls->Add(this->textBoxNom);
            this->Controls->Add(this->labelData);
            this->Controls->Add(this->textBoxData);
            this->Controls->Add(this->labelLocation);
            this->Controls->Add(this->textBoxLocation);
            this->Controls->Add(this->labelAproxMem);
            this->Controls->Add(this->numericUpDownAproxMem);
            this->Controls->Add(this->buttonGuardar);
            this->Name = L"ModificarEsdevenimentForm";
            this->Text = L"Modificar Esdeveniment";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownAproxMem))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void buttonGuardar_Click(Object^ sender, EventArgs^ e) {
            MySql::Data::MySqlClient::MySqlConnection^ conn = nullptr;
            try {
                String^ connectionString = "server=ubiwan.epsevg.upc.edu;database=amep01;uid=amep01;pwd=Ahsheix4Aewua8;";
                conn = gcnew MySql::Data::MySqlClient::MySqlConnection(connectionString);
                conn->Open();

                String^ query = "UPDATE evento SET ev_date = @ev_date, location = @location, aprox_mem = @aprox_mem WHERE ev_name = @ev_name";

                MySql::Data::MySqlClient::MySqlCommand^ cmd = gcnew MySql::Data::MySqlClient::MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@ev_name", this->textBoxNom->Text);
                cmd->Parameters->AddWithValue("@ev_date", this->textBoxData->Text);
                cmd->Parameters->AddWithValue("@location", this->textBoxLocation->Text);
                cmd->Parameters->AddWithValue("@aprox_mem", this->numericUpDownAproxMem->Value);

                int result = cmd->ExecuteNonQuery();

                if (result > 0) {
                    MessageBox::Show("Esdeveniment modificat amb èxit!", "Informació");
                }
                else {
                    MessageBox::Show("No s'ha trobat l'esdeveniment amb aquest nom.", "Error");
                }
            }

            catch (MySql::Data::MySqlClient::MySqlException^ ex) {
                MessageBox::Show("Error de base de dades: " + ex->Message, "Error");
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message, "Error");
            }
            finally {
                if (conn != nullptr && conn->State == ConnectionState::Open) {
                    conn->Close();
                }
            }
        }
};
}