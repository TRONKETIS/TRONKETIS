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
	private: System::Void dgvColles_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void txtCercador_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		CercarDB();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
};
}
