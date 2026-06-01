#pragma once

#include "DB.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;
using namespace System::Data;

public ref class CrearDiadaForm : public System::Windows::Forms::Form
{
public:
	CrearDiadaForm(void)
	{
		InitializeComponent();
	}

protected:
	~CrearDiadaForm()
	{
		if (components)
		{
			delete components;
		}
	}

private:
	System::ComponentModel::Container^ components;

	Panel^ panelHeader;
	Panel^ panelCard;

	Label^ lblTitulo;
	Label^ lblSubtitulo;

	Label^ lblNom;
	Label^ lblData;
	Label^ lblUbicacio;
	Label^ lblDescripcio;

	TextBox^ txtNom;
	DateTimePicker^ dtpData;
	TextBox^ txtUbicacio;
	TextBox^ txtDescripcio;

	Button^ btnCrear;
	Button^ btnCancelar;

private:
	void InitializeComponent(void)
	{
		this->components = gcnew System::ComponentModel::Container();

		this->panelHeader = gcnew Panel();
		this->panelCard = gcnew Panel();

		this->lblTitulo = gcnew Label();
		this->lblSubtitulo = gcnew Label();

		this->lblNom = gcnew Label();
		this->lblData = gcnew Label();
		this->lblUbicacio = gcnew Label();
		this->lblDescripcio = gcnew Label();

		this->txtNom = gcnew TextBox();
		this->dtpData = gcnew DateTimePicker();
		this->txtUbicacio = gcnew TextBox();
		this->txtDescripcio = gcnew TextBox();

		this->btnCrear = gcnew Button();
		this->btnCancelar = gcnew Button();

		this->SuspendLayout();

		// Form
		this->Text = L"Crear Diada";
		this->ClientSize = System::Drawing::Size(620, 560);
		this->StartPosition = FormStartPosition::CenterScreen;
		this->BackColor = Color::FromArgb(245, 245, 245);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->MaximizeBox = false;

		// Header
		this->panelHeader->BackColor = Color::FromArgb(130, 24, 48);
		this->panelHeader->Dock = DockStyle::Top;
		this->panelHeader->Height = 115;

		this->lblTitulo->Text = L"Tronketis";
		this->lblTitulo->Font = gcnew Drawing::Font(L"Segoe UI", 25, FontStyle::Bold);
		this->lblTitulo->ForeColor = Color::White;
		this->lblTitulo->AutoSize = true;
		this->lblTitulo->Location = Point(35, 25);

		this->lblSubtitulo->Text = L"Crear nova diada";
		this->lblSubtitulo->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Regular);
		this->lblSubtitulo->ForeColor = Color::White;
		this->lblSubtitulo->AutoSize = true;
		this->lblSubtitulo->Location = Point(39, 72);

		this->panelHeader->Controls->Add(this->lblTitulo);
		this->panelHeader->Controls->Add(this->lblSubtitulo);

		// Card
		this->panelCard->BackColor = Color::White;
		this->panelCard->BorderStyle = BorderStyle::FixedSingle;
		this->panelCard->Location = Point(55, 145);
		this->panelCard->Size = Drawing::Size(510, 360);

		// Labels
		this->lblNom->Text = L"Nom:";
		this->lblNom->Font = gcnew Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
		this->lblNom->ForeColor = Color::FromArgb(130, 24, 48);
		this->lblNom->Location = Point(45, 35);
		this->lblNom->Size = Drawing::Size(130, 25);

		this->lblData->Text = L"Data i hora:";
		this->lblData->Font = gcnew Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
		this->lblData->ForeColor = Color::FromArgb(130, 24, 48);
		this->lblData->Location = Point(45, 90);
		this->lblData->Size = Drawing::Size(130, 25);

		this->lblUbicacio->Text = L"Ubicacio:";
		this->lblUbicacio->Font = gcnew Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
		this->lblUbicacio->ForeColor = Color::FromArgb(130, 24, 48);
		this->lblUbicacio->Location = Point(45, 145);
		this->lblUbicacio->Size = Drawing::Size(130, 25);

		this->lblDescripcio->Text = L"Descripcio:";
		this->lblDescripcio->Font = gcnew Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
		this->lblDescripcio->ForeColor = Color::FromArgb(130, 24, 48);
		this->lblDescripcio->Location = Point(45, 200);
		this->lblDescripcio->Size = Drawing::Size(130, 25);

		// Inputs
		this->txtNom->Location = Point(180, 32);
		this->txtNom->Size = Drawing::Size(270, 27);
		this->txtNom->Font = gcnew Drawing::Font(L"Segoe UI", 10);

		this->dtpData->Location = Point(180, 87);
		this->dtpData->Size = Drawing::Size(270, 27);
		this->dtpData->Font = gcnew Drawing::Font(L"Segoe UI", 10);
		this->dtpData->Format = DateTimePickerFormat::Custom;
		this->dtpData->CustomFormat = L"yyyy-MM-dd HH:mm:ss";

		this->txtUbicacio->Location = Point(180, 142);
		this->txtUbicacio->Size = Drawing::Size(270, 27);
		this->txtUbicacio->Font = gcnew Drawing::Font(L"Segoe UI", 10);

		this->txtDescripcio->Location = Point(180, 197);
		this->txtDescripcio->Size = Drawing::Size(270, 70);
		this->txtDescripcio->Font = gcnew Drawing::Font(L"Segoe UI", 10);
		this->txtDescripcio->Multiline = true;

		// Boton crear
		this->btnCrear->Text = L"Crear Diada";
		this->btnCrear->Font = gcnew Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
		this->btnCrear->BackColor = Color::FromArgb(211, 184, 35);
		this->btnCrear->ForeColor = Color::Black;
		this->btnCrear->FlatStyle = FlatStyle::Flat;
		this->btnCrear->Location = Point(180, 295);
		this->btnCrear->Size = Drawing::Size(130, 38);
		this->btnCrear->Click += gcnew EventHandler(this, &CrearDiadaForm::btnCrear_Click);

		// Boton cancelar
		this->btnCancelar->Text = L"Cancelar";
		this->btnCancelar->Font = gcnew Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
		this->btnCancelar->BackColor = Color::FromArgb(130, 24, 48);
		this->btnCancelar->ForeColor = Color::White;
		this->btnCancelar->FlatStyle = FlatStyle::Flat;
		this->btnCancelar->Location = Point(320, 295);
		this->btnCancelar->Size = Drawing::Size(130, 38);
		this->btnCancelar->Click += gcnew EventHandler(this, &CrearDiadaForm::btnCancelar_Click);

		// Add controls card
		this->panelCard->Controls->Add(this->lblNom);
		this->panelCard->Controls->Add(this->lblData);
		this->panelCard->Controls->Add(this->lblUbicacio);
		this->panelCard->Controls->Add(this->lblDescripcio);

		this->panelCard->Controls->Add(this->txtNom);
		this->panelCard->Controls->Add(this->dtpData);
		this->panelCard->Controls->Add(this->txtUbicacio);
		this->panelCard->Controls->Add(this->txtDescripcio);

		this->panelCard->Controls->Add(this->btnCrear);
		this->panelCard->Controls->Add(this->btnCancelar);

		// Add controls form
		this->Controls->Add(this->panelCard);
		this->Controls->Add(this->panelHeader);

		this->ResumeLayout(false);
	}

private:
	void btnCrear_Click(Object^ sender, EventArgs^ e)
	{
		String^ nom = txtNom->Text->Trim();
		String^ ubicacio = txtUbicacio->Text->Trim();
		String^ descripcio = txtDescripcio->Text->Trim();
		DateTime dataDiada = dtpData->Value;

		if (nom == "" || ubicacio == "" || descripcio == "")
		{
			MessageBox::Show(
				"Omple tots els camps.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
			return;
		}

		MySqlConnection^ conn = DB::GetConnection();

		try
		{
			conn->Open();

			String^ sqlComprovar =
				"SELECT COUNT(*) FROM diada "
				"WHERE name = @name AND date_diada = @date_diada";

			MySqlCommand^ cmdComprovar = gcnew MySqlCommand(sqlComprovar, conn);
			cmdComprovar->Parameters->AddWithValue("@name", nom);
			cmdComprovar->Parameters->AddWithValue("@date_diada", dataDiada);

			int existeix = Convert::ToInt32(cmdComprovar->ExecuteScalar());

			if (existeix > 0)
			{
				MessageBox::Show(
					"Ja existeix una diada amb aquest nom i data.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				conn->Close();
				return;
			}

			String^ sqlInsert =
				"INSERT INTO diada (name, date_diada, location, descrip) "
				"VALUES (@name, @date_diada, @location, @descrip)";

			MySqlCommand^ cmdInsert = gcnew MySqlCommand(sqlInsert, conn);
			cmdInsert->Parameters->AddWithValue("@name", nom);
			cmdInsert->Parameters->AddWithValue("@date_diada", dataDiada);
			cmdInsert->Parameters->AddWithValue("@location", ubicacio);
			cmdInsert->Parameters->AddWithValue("@descrip", descripcio);

			cmdInsert->ExecuteNonQuery();

			conn->Close();

			MessageBox::Show(
				"Diada creada correctament.",
				"Correcte",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			this->Close();
		}
		catch (Exception^ ex)
		{
			if (conn->State == ConnectionState::Open)
			{
				conn->Close();
			}

			MessageBox::Show(
				"No s'ha pogut crear la diada:\n\n" + ex->Message,
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}

private:
	void btnCancelar_Click(Object^ sender, EventArgs^ e)
	{
		this->Close();
	}
};