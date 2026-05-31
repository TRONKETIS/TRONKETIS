<<<<<<< HEAD


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
            this->LabelLocalitzacio->Text = L"LocalitzaciÃ³:";
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

=======
#pragma once

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de ConsultarCollaForm
	/// </summary>
	public ref class ConsultarCollaForm : public System::Windows::Forms::Form
	{
	public:
		ConsultarCollaForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			CercarDB();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ConsultarCollaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvColles;
	protected:

	private: System::Windows::Forms::TextBox^ txtCercador;


	private: System::Windows::Forms::Label^ label1;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgvColles = (gcnew System::Windows::Forms::DataGridView());
			this->txtCercador = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvColles))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvColles
			// 
			this->dgvColles->AccessibleName = L"";
			this->dgvColles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvColles->Location = System::Drawing::Point(9, 35);
			this->dgvColles->Margin = System::Windows::Forms::Padding(2);
			this->dgvColles->Name = L"dgvColles";
			this->dgvColles->RowHeadersWidth = 51;
			this->dgvColles->RowTemplate->Height = 24;
			this->dgvColles->Size = System::Drawing::Size(652, 194);
			this->dgvColles->TabIndex = 0;
			this->dgvColles->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ConsultarCollaForm::dgvColles_CellContentClick);
			// 
			// txtCercador
			// 
			this->txtCercador->AccessibleName = L"";
			this->txtCercador->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->txtCercador->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtCercador->Location = System::Drawing::Point(164, 11);
			this->txtCercador->Margin = System::Windows::Forms::Padding(2);
			this->txtCercador->Name = L"txtCercador";
			this->txtCercador->Size = System::Drawing::Size(497, 20);
			this->txtCercador->TabIndex = 1;
			this->txtCercador->TextChanged += gcnew System::EventHandler(this, &ConsultarCollaForm::txtCercador_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 13);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Cercar colla pel nom o localitat";
			this->label1->Click += gcnew System::EventHandler(this, &ConsultarCollaForm::label1_Click);
			// 
			// ConsultarCollaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 240);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtCercador);
			this->Controls->Add(this->dgvColles);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ConsultarCollaForm";
			this->Text = L"ConsultarCollaForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvColles))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void CercarDB() {
		String^ connString = "server=ubiwan.epsevg.upc.edu;database=amep01;uid=amep01;pwd=Ahsheix4Aewua8;";
		MySqlConnection^ conn = gcnew MySqlConnection(connString);

		String^ query = "SELECT name, location, uni_name FROM colla WHERE state = 1 AND (name LIKE @filtre OR location LIKE @filtre)";

		MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@filtre", "%" + this->txtCercador->Text + "%");

		try {
			conn->Open();
			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
			DataTable^ dt = gcnew DataTable();

			adapter->Fill(dt);
			this->dgvColles->DataSource = dt;
			dgvColles->Columns["name"]->HeaderText = "Nom de la Colla";
			dgvColles->Columns["location"]->HeaderText = "Població";
			dgvColles->Columns["uni_name"]->HeaderText = "Universitat";

		}
		catch (Exception^ ex) {
			System::Windows::Forms::MessageBox::Show("Error de connexió: " + ex->Message);
		}
		finally {
			conn->Close();
		}
	}
	private: System::Void txtCercador_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		CercarDB();
	}
	private: System::Void dgvColles_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
};
}
>>>>>>> a2562df4fc6e541d614c2e90aab9075b02bffcc8
