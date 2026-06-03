#pragma once

#include "AppColors.h"
#include "CtrlCrearColla.h"
#include "CollaDTO.h"
#include "UsuariDTO.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	public ref class CrearCollaForm : public System::Windows::Forms::Form
	{
	private:
		int usuariIdActual;
		array<Byte>^ logoData;
		String^ rutaLogoTemporal;

	public:
		CrearCollaForm(int usuariId)
		{
			usuariIdActual = usuariId;
			logoData = nullptr;
			rutaLogoTemporal = nullptr;
			InitializeComponent();
			CarregarCapsDisponibles();
			ConfigurarValidacions();
		}

		CrearCollaForm(void)
		{
			usuariIdActual = 0;
			logoData = nullptr;
			rutaLogoTemporal = nullptr;
			InitializeComponent();
			CarregarCapsDisponibles();
			ConfigurarValidacions();
		}

	protected:
		~CrearCollaForm()
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
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::TextBox^ NameCollatxt;
		System::Windows::Forms::TextBox^ LocationCollatxt;
		System::Windows::Forms::TextBox^ UniNameCollatxt;
		System::Windows::Forms::ComboBox^ ComboCapColla;
		System::Windows::Forms::TextBox^ TelefonCaptxt;
		System::Windows::Forms::Label^ LabelCapColla;
		System::Windows::Forms::Label^ LabelTelefonCap;
		System::Windows::Forms::Label^ LabelNomColla;
		System::Windows::Forms::Label^ LabelLogoColla;
		System::Windows::Forms::Label^ LabelLocalitzacioColla;
		System::Windows::Forms::Label^ LabelUniversitatColla;
		System::Windows::Forms::Button^ BtnCrearColla;
		System::Windows::Forms::Button^ BtnNetejar;
		System::Windows::Forms::Label^ LabelMissatge;
		System::Windows::Forms::PictureBox^ LogoPictureBox;
		System::Windows::Forms::Button^ BtnPujarLogo;
		System::Windows::Forms::Button^ BtnEliminarLogo;
		System::Windows::Forms::Label^ LabelInfoLogo;

		System::ComponentModel::Container^ components;

		void ConfigurarLabel(Label^ lbl)
		{
			lbl->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			lbl->ForeColor = AppColors::Black;
			lbl->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		}

		void ConfigurarTextBox(TextBox^ txt)
		{
			txt->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0F);
			txt->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		}

		void ConfigurarCombo(ComboBox^ combo)
		{
			combo->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0F);
			combo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		}

		void ConfigurarBotonPrincipal(Button^ btn)
		{
			btn->BackColor = AppColors::Yellow;
			btn->ForeColor = AppColors::Black;
			btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			btn->FlatAppearance->BorderSize = 0;
			btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(224, 197, 65);
			btn->FlatAppearance->MouseDownBackColor = AppColors::DarkRed;
			btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0F, System::Drawing::FontStyle::Bold);
			btn->Cursor = System::Windows::Forms::Cursors::Hand;
		}

		void ConfigurarBotonSecundario(Button^ btn)
		{
			btn->BackColor = AppColors::White;
			btn->ForeColor = AppColors::DarkRed;
			btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			btn->FlatAppearance->BorderColor = AppColors::DarkRed;
			btn->FlatAppearance->BorderSize = 1;
			btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Bold);
			btn->Cursor = System::Windows::Forms::Cursors::Hand;
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->NameCollatxt = (gcnew System::Windows::Forms::TextBox());
			this->LocationCollatxt = (gcnew System::Windows::Forms::TextBox());
			this->UniNameCollatxt = (gcnew System::Windows::Forms::TextBox());
			this->ComboCapColla = (gcnew System::Windows::Forms::ComboBox());
			this->TelefonCaptxt = (gcnew System::Windows::Forms::TextBox());
			this->LabelCapColla = (gcnew System::Windows::Forms::Label());
			this->LabelTelefonCap = (gcnew System::Windows::Forms::Label());
			this->LabelNomColla = (gcnew System::Windows::Forms::Label());
			this->LabelLogoColla = (gcnew System::Windows::Forms::Label());
			this->LabelLocalitzacioColla = (gcnew System::Windows::Forms::Label());
			this->LabelUniversitatColla = (gcnew System::Windows::Forms::Label());
			this->BtnCrearColla = (gcnew System::Windows::Forms::Button());
			this->BtnNetejar = (gcnew System::Windows::Forms::Button());
			this->LabelMissatge = (gcnew System::Windows::Forms::Label());
			this->LogoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->BtnPujarLogo = (gcnew System::Windows::Forms::Button());
			this->BtnEliminarLogo = (gcnew System::Windows::Forms::Button());
			this->LabelInfoLogo = (gcnew System::Windows::Forms::Label());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = AppColors::DarkRed;
			this->panelHeader->Controls->Add(this->lblTitulo);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(720, 105);
			this->panelHeader->TabIndex = 0;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.0F, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = AppColors::White;
			this->lblTitulo->Location = System::Drawing::Point(34, 22);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(220, 41);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Crear Colla";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitulo->ForeColor = AppColors::White;
			this->lblSubtitulo->Location = System::Drawing::Point(39, 66);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(360, 17);
			this->lblSubtitulo->TabIndex = 1;
			this->lblSubtitulo->Text = L"Crea una colla y asigna su cap de colla";
			// 
			// panelContenido
			// 
			this->panelContenido->BackColor = AppColors::White;
			this->panelContenido->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelContenido->Controls->Add(this->NameCollatxt);
			this->panelContenido->Controls->Add(this->LocationCollatxt);
			this->panelContenido->Controls->Add(this->UniNameCollatxt);
			this->panelContenido->Controls->Add(this->ComboCapColla);
			this->panelContenido->Controls->Add(this->TelefonCaptxt);
			this->panelContenido->Controls->Add(this->LabelCapColla);
			this->panelContenido->Controls->Add(this->LabelTelefonCap);
			this->panelContenido->Controls->Add(this->LabelNomColla);
			this->panelContenido->Controls->Add(this->LabelLogoColla);
			this->panelContenido->Controls->Add(this->LabelLocalitzacioColla);
			this->panelContenido->Controls->Add(this->LabelUniversitatColla);
			this->panelContenido->Controls->Add(this->BtnCrearColla);
			this->panelContenido->Controls->Add(this->BtnNetejar);
			this->panelContenido->Controls->Add(this->LabelMissatge);
			this->panelContenido->Controls->Add(this->LogoPictureBox);
			this->panelContenido->Controls->Add(this->BtnPujarLogo);
			this->panelContenido->Controls->Add(this->BtnEliminarLogo);
			this->panelContenido->Controls->Add(this->LabelInfoLogo);
			this->panelContenido->Location = System::Drawing::Point(42, 130);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(636, 500);
			this->panelContenido->TabIndex = 1;
			// 
			// labels
			// 
			this->LabelNomColla->Location = System::Drawing::Point(42, 35);
			this->LabelNomColla->Name = L"LabelNomColla";
			this->LabelNomColla->Size = System::Drawing::Size(175, 26);
			this->LabelNomColla->Text = L"Nombre colla *";
			this->LabelLogoColla->Location = System::Drawing::Point(42, 86);
			this->LabelLogoColla->Name = L"LabelLogoColla";
			this->LabelLogoColla->Size = System::Drawing::Size(175, 26);
			this->LabelLogoColla->Text = L"Logo";
			this->LabelLocalitzacioColla->Location = System::Drawing::Point(42, 205);
			this->LabelLocalitzacioColla->Name = L"LabelLocalitzacioColla";
			this->LabelLocalitzacioColla->Size = System::Drawing::Size(175, 26);
			this->LabelLocalitzacioColla->Text = L"Localizacion *";
			this->LabelUniversitatColla->Location = System::Drawing::Point(42, 255);
			this->LabelUniversitatColla->Name = L"LabelUniversitatColla";
			this->LabelUniversitatColla->Size = System::Drawing::Size(175, 26);
			this->LabelUniversitatColla->Text = L"Universidad";
			this->LabelCapColla->Location = System::Drawing::Point(42, 305);
			this->LabelCapColla->Name = L"LabelCapColla";
			this->LabelCapColla->Size = System::Drawing::Size(175, 26);
			this->LabelCapColla->Text = L"Cap de colla *";
			this->LabelTelefonCap->Location = System::Drawing::Point(42, 355);
			this->LabelTelefonCap->Name = L"LabelTelefonCap";
			this->LabelTelefonCap->Size = System::Drawing::Size(175, 26);
			this->LabelTelefonCap->Text = L"Telefono cap *";
			ConfigurarLabel(this->LabelNomColla);
			ConfigurarLabel(this->LabelLogoColla);
			ConfigurarLabel(this->LabelLocalitzacioColla);
			ConfigurarLabel(this->LabelUniversitatColla);
			ConfigurarLabel(this->LabelCapColla);
			ConfigurarLabel(this->LabelTelefonCap);
			// 
			// inputs
			// 
			this->NameCollatxt->Location = System::Drawing::Point(245, 35);
			this->NameCollatxt->Name = L"NameCollatxt";
			this->NameCollatxt->Size = System::Drawing::Size(330, 25);
			this->NameCollatxt->TabIndex = 0;
			this->NameCollatxt->TextChanged += gcnew System::EventHandler(this, &CrearCollaForm::NomColla_TextChanged);
			this->LocationCollatxt->Location = System::Drawing::Point(245, 205);
			this->LocationCollatxt->Name = L"LocationCollatxt";
			this->LocationCollatxt->Size = System::Drawing::Size(330, 25);
			this->LocationCollatxt->TabIndex = 3;
			this->LocationCollatxt->TextChanged += gcnew System::EventHandler(this, &CrearCollaForm::Localitzacio_TextChanged);
			this->UniNameCollatxt->Location = System::Drawing::Point(245, 255);
			this->UniNameCollatxt->Name = L"UniNameCollatxt";
			this->UniNameCollatxt->Size = System::Drawing::Size(330, 25);
			this->UniNameCollatxt->TabIndex = 4;
			this->ComboCapColla->FormattingEnabled = true;
			this->ComboCapColla->Location = System::Drawing::Point(245, 305);
			this->ComboCapColla->Name = L"ComboCapColla";
			this->ComboCapColla->Size = System::Drawing::Size(330, 25);
			this->ComboCapColla->TabIndex = 5;
			this->ComboCapColla->SelectedIndexChanged += gcnew System::EventHandler(this, &CrearCollaForm::CapColla_SelectedIndexChanged);
			this->TelefonCaptxt->Location = System::Drawing::Point(245, 355);
			this->TelefonCaptxt->Name = L"TelefonCaptxt";
			this->TelefonCaptxt->Size = System::Drawing::Size(330, 25);
			this->TelefonCaptxt->TabIndex = 6;
			this->TelefonCaptxt->TextChanged += gcnew System::EventHandler(this, &CrearCollaForm::TelefonCap_TextChanged);
			ConfigurarTextBox(this->NameCollatxt);
			ConfigurarTextBox(this->LocationCollatxt);
			ConfigurarTextBox(this->UniNameCollatxt);
			ConfigurarTextBox(this->TelefonCaptxt);
			ConfigurarCombo(this->ComboCapColla);
			// 
			// logo
			// 
			this->LogoPictureBox->BackColor = System::Drawing::Color::FromArgb(245, 245, 245);
			this->LogoPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LogoPictureBox->Location = System::Drawing::Point(245, 85);
			this->LogoPictureBox->Name = L"LogoPictureBox";
			this->LogoPictureBox->Size = System::Drawing::Size(85, 85);
			this->LogoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->LogoPictureBox->TabIndex = 7;
			this->LogoPictureBox->TabStop = false;
			this->BtnPujarLogo->Location = System::Drawing::Point(350, 85);
			this->BtnPujarLogo->Name = L"BtnPujarLogo";
			this->BtnPujarLogo->Size = System::Drawing::Size(225, 34);
			this->BtnPujarLogo->TabIndex = 1;
			this->BtnPujarLogo->Text = L"Subir logo";
			this->BtnPujarLogo->UseVisualStyleBackColor = false;
			this->BtnPujarLogo->Click += gcnew System::EventHandler(this, &CrearCollaForm::BtnPujarLogo_Click);
			this->BtnEliminarLogo->Enabled = false;
			this->BtnEliminarLogo->Location = System::Drawing::Point(350, 128);
			this->BtnEliminarLogo->Name = L"BtnEliminarLogo";
			this->BtnEliminarLogo->Size = System::Drawing::Size(225, 34);
			this->BtnEliminarLogo->TabIndex = 2;
			this->BtnEliminarLogo->Text = L"Eliminar logo";
			this->BtnEliminarLogo->UseVisualStyleBackColor = false;
			this->BtnEliminarLogo->Click += gcnew System::EventHandler(this, &CrearCollaForm::BtnEliminarLogo_Click);
			ConfigurarBotonSecundario(this->BtnPujarLogo);
			ConfigurarBotonSecundario(this->BtnEliminarLogo);
			this->LabelInfoLogo->AutoSize = true;
			this->LabelInfoLogo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.0F));
			this->LabelInfoLogo->ForeColor = System::Drawing::Color::Gray;
			this->LabelInfoLogo->Location = System::Drawing::Point(245, 176);
			this->LabelInfoLogo->Name = L"LabelInfoLogo";
			this->LabelInfoLogo->Size = System::Drawing::Size(250, 13);
			this->LabelInfoLogo->TabIndex = 8;
			this->LabelInfoLogo->Text = L"Formatos: JPG, PNG, GIF (Max. 5MB)";
			// 
			// buttons
			// 
			this->BtnCrearColla->Enabled = false;
			this->BtnCrearColla->Location = System::Drawing::Point(245, 410);
			this->BtnCrearColla->Name = L"BtnCrearColla";
			this->BtnCrearColla->Size = System::Drawing::Size(205, 42);
			this->BtnCrearColla->TabIndex = 7;
			this->BtnCrearColla->Text = L"Crear Colla";
			this->BtnCrearColla->UseVisualStyleBackColor = false;
			this->BtnCrearColla->Click += gcnew System::EventHandler(this, &CrearCollaForm::BtnCrearColla_Click);
			this->BtnNetejar->Location = System::Drawing::Point(470, 410);
			this->BtnNetejar->Name = L"BtnNetejar";
			this->BtnNetejar->Size = System::Drawing::Size(105, 42);
			this->BtnNetejar->TabIndex = 8;
			this->BtnNetejar->Text = L"Limpiar";
			this->BtnNetejar->UseVisualStyleBackColor = false;
			this->BtnNetejar->Click += gcnew System::EventHandler(this, &CrearCollaForm::BtnNetejar_Click);
			ConfigurarBotonPrincipal(this->BtnCrearColla);
			ConfigurarBotonSecundario(this->BtnNetejar);
			// 
			// LabelMissatge
			// 
			this->LabelMissatge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F));
			this->LabelMissatge->ForeColor = System::Drawing::Color::DimGray;
			this->LabelMissatge->Location = System::Drawing::Point(42, 462);
			this->LabelMissatge->MaximumSize = System::Drawing::Size(545, 0);
			this->LabelMissatge->Name = L"LabelMissatge";
			this->LabelMissatge->Size = System::Drawing::Size(545, 30);
			this->LabelMissatge->TabIndex = 9;
			// 
			// CrearCollaForm
			// 
			this->AcceptButton = this->BtnCrearColla;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = AppColors::Background;
			this->ClientSize = System::Drawing::Size(720, 665);
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelHeader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"CrearCollaForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Crear Colla";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->EndInit();
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void CarregarCapsDisponibles() {
		try {
			List<UsuariDTO^>^ caps = CtrlCrearColla::ObtenirCapsDisponibles();

			ComboCapColla->DataSource = caps;
			ComboCapColla->DisplayMember = "username";
			ComboCapColla->ValueMember = "dni";

			if (caps->Count == 0) {
				ComboCapColla->Enabled = false;
				LabelMissatge->Text = "No hay ningun CapColla disponible. Crea o libera un usuario CapColla antes de crear la colla.";
				LabelMissatge->ForeColor = System::Drawing::Color::OrangeRed;
			}
			else {
				ComboCapColla->SelectedIndex = 0;
			}
		}
		catch (Exception^ ex) {
			ComboCapColla->Enabled = false;
			LabelMissatge->Text = "Error cargando caps de colla: " + ex->Message;
			LabelMissatge->ForeColor = System::Drawing::Color::Red;
		}
	}

	private: System::Void ConfigurarValidacions() {
		if (ComboCapColla->Enabled) {
			LabelMissatge->Text = "Rellena los campos obligatorios (*) y selecciona un cap.";
			LabelMissatge->ForeColor = System::Drawing::Color::DimGray;
		}
		ValidarFormulari();
	}

	private: System::Void NomColla_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		ValidarFormulari();
	}

	private: System::Void Localitzacio_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		ValidarFormulari();
	}

	private: System::Void CapColla_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		ValidarFormulari();
	}

	private: System::Void TelefonCap_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		ValidarFormulari();
	}

	private: System::Void ValidarFormulari() {
		bool nomValid = !String::IsNullOrWhiteSpace(NameCollatxt->Text->Trim());
		bool localitzacioValid = !String::IsNullOrWhiteSpace(LocationCollatxt->Text->Trim());
		bool capValid = (ComboCapColla != nullptr && ComboCapColla->SelectedItem != nullptr);
		bool telefonValid = !String::IsNullOrWhiteSpace(TelefonCaptxt->Text->Trim());

		if (nomValid && NameCollatxt->Text->Trim()->Length > 100) {
			nomValid = false;
		}
		if (localitzacioValid && LocationCollatxt->Text->Trim()->Length > 200) {
			localitzacioValid = false;
		}

		BtnCrearColla->Enabled = nomValid && localitzacioValid && capValid && telefonValid;
	}

	private: System::Void BtnPujarLogo_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Title = "Seleccionar logo de la colla";
		ofd->Filter = "Archivos de imagen|*.jpg;*.jpeg;*.png;*.gif|Todos los archivos|*.*";
		ofd->FilterIndex = 1;
		ofd->RestoreDirectory = true;

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				FileInfo^ fileInfo = gcnew FileInfo(ofd->FileName);
				long midaFitxer = fileInfo->Length;

				if (midaFitxer > 5 * 1024 * 1024) {
					MessageBox::Show(
						"El archivo seleccionado supera los 5MB. Selecciona una imagen mas pequena.",
						"Archivo demasiado grande",
						MessageBoxButtons::OK,
						MessageBoxIcon::Warning
					);
					return;
				}

				logoData = File::ReadAllBytes(ofd->FileName);
				rutaLogoTemporal = ofd->FileName;

				LogoPictureBox->Image = Image::FromFile(ofd->FileName);
				BtnEliminarLogo->Enabled = true;

				LabelInfoLogo->Text = String::Format(
					"{0} ({1:F2} KB)",
					Path::GetFileName(ofd->FileName),
					midaFitxer / 1024.0
				);
				LabelInfoLogo->ForeColor = System::Drawing::Color::Green;

				ValidarFormulari();
			}
			catch (Exception^ ex) {
				MessageBox::Show(
					"Error cargando el logo: " + ex->Message,
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
			}
		}
	}

	private: System::Void BtnEliminarLogo_Click(System::Object^ sender, System::EventArgs^ e) {
		logoData = nullptr;
		rutaLogoTemporal = nullptr;

		if (LogoPictureBox->Image != nullptr) {
			delete LogoPictureBox->Image;
			LogoPictureBox->Image = nullptr;
		}

		BtnEliminarLogo->Enabled = false;
		LabelInfoLogo->Text = "Formatos: JPG, PNG, GIF (Max. 5MB)";
		LabelInfoLogo->ForeColor = System::Drawing::Color::Gray;
	}

	private: System::Void BtnCrearColla_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nom = NameCollatxt->Text->Trim();
		String^ localitzacio = LocationCollatxt->Text->Trim();
		String^ univ = UniNameCollatxt->Text->Trim();

		UsuariDTO^ capSeleccionat = dynamic_cast<UsuariDTO^>(ComboCapColla->SelectedItem);
		if (capSeleccionat == nullptr) {
			MessageBox::Show("Selecciona un cap de colla.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ telefonCap = TelefonCaptxt->Text->Trim();

		CollaDTO^ novaColla = gcnew CollaDTO();
		novaColla->nom = nom;
		novaColla->localitzacio = localitzacio;
		novaColla->univ = String::IsNullOrWhiteSpace(univ) ? nullptr : univ;
		novaColla->actiu = true;
		novaColla->logo = logoData;

		String^ error;
		bool resultat = CtrlCrearColla::CrearAmbCap(usuariIdActual, novaColla, capSeleccionat->dni, telefonCap, error);

		if (resultat) {
			LabelMissatge->Text = "Colla creada correctamente!";
			LabelMissatge->ForeColor = System::Drawing::Color::Green;

			MessageBox::Show(
				"La colla \"" + nom + "\" se ha creado correctamente!\nCap de colla: " + capSeleccionat->username,
				"Exito",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else {
			LabelMissatge->Text = "Error: " + error;
			LabelMissatge->ForeColor = System::Drawing::Color::Red;

			MessageBox::Show(
				"No se ha podido crear la colla:\n\n" + error,
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}

	private: System::Void BtnNetejar_Click(System::Object^ sender, System::EventArgs^ e) {
		NameCollatxt->Clear();
		LocationCollatxt->Clear();
		UniNameCollatxt->Clear();
		TelefonCaptxt->Clear();

		if (ComboCapColla->Items->Count > 0) {
			ComboCapColla->SelectedIndex = 0;
		}

		BtnEliminarLogo_Click(sender, e);

		LabelMissatge->Text = "Formulario limpiado. Rellena los campos y selecciona el cap para crear una nueva colla.";
		LabelMissatge->ForeColor = System::Drawing::Color::DimGray;
		BtnCrearColla->Enabled = false;
		NameCollatxt->Focus();
	}
	};
}
