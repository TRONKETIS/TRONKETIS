#pragma once

#include "CtrlCrearColla.h"
#include "CollaDTO.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Formulari per crear una nova colla castellera amb logo
	/// </summary>
	public ref class CrearCollaForm : public System::Windows::Forms::Form
	{
	private:
		int usuariIdActual;
		array<Byte>^ logoData;  // Emmagatzema les dades del logo
		String^ rutaLogoTemporal;

	public:
		CrearCollaForm(int usuariId)
		{
			usuariIdActual = usuariId;
			logoData = nullptr;
			rutaLogoTemporal = nullptr;
			InitializeComponent();
			ConfigurarValidacions();
		}

		CrearCollaForm(void)
		{
			usuariIdActual = 0;
			logoData = nullptr;
			rutaLogoTemporal = nullptr;
			InitializeComponent();
			ConfigurarValidacions();
		}

	protected:
		~CrearCollaForm()
		{
			// Netejar fitxer temporal si existeix
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
		// 🔹 Controls del formulari
		System::Windows::Forms::TextBox^ NameCollatxt;
		System::Windows::Forms::TextBox^ LocationCollatxt;
		System::Windows::Forms::TextBox^ UniNameCollatxt;
		System::Windows::Forms::Label^ LabelNomColla;
		System::Windows::Forms::Label^ LabelLogoColla;
		System::Windows::Forms::Label^ LabelLocalitzacioColla;
		System::Windows::Forms::Label^ LabelUniversitatColla;
		System::Windows::Forms::Button^ BtnCrearColla;
		System::Windows::Forms::Button^ BtnNetejar;
		System::Windows::Forms::Label^ LabelMissatge;

		// 🖼️ Controls del Logo
		System::Windows::Forms::PictureBox^ LogoPictureBox;
		System::Windows::Forms::Button^ BtnPujarLogo;
		System::Windows::Forms::Button^ BtnEliminarLogo;
		System::Windows::Forms::Label^ LabelInfoLogo;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->NameCollatxt = (gcnew System::Windows::Forms::TextBox());
			this->LocationCollatxt = (gcnew System::Windows::Forms::TextBox());
			this->UniNameCollatxt = (gcnew System::Windows::Forms::TextBox());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// NameCollatxt
			// 
			this->NameCollatxt->Location = System::Drawing::Point(280, 70);
			this->NameCollatxt->Name = L"NameCollatxt";
			this->NameCollatxt->Size = System::Drawing::Size(300, 22);
			this->NameCollatxt->TabIndex = 0;
			this->NameCollatxt->TextChanged += gcnew System::EventHandler(this, &CrearCollaForm::NomColla_TextChanged);
			// 
			// LocationCollatxt
			// 
			this->LocationCollatxt->Location = System::Drawing::Point(280, 180);
			this->LocationCollatxt->Name = L"LocationCollatxt";
			this->LocationCollatxt->Size = System::Drawing::Size(300, 22);
			this->LocationCollatxt->TabIndex = 1;
			this->LocationCollatxt->TextChanged += gcnew System::EventHandler(this, &CrearCollaForm::Localitzacio_TextChanged);
			// 
			// UniNameCollatxt
			// 
			this->UniNameCollatxt->Location = System::Drawing::Point(280, 235);
			this->UniNameCollatxt->Name = L"UniNameCollatxt";
			this->UniNameCollatxt->Size = System::Drawing::Size(300, 22);
			this->UniNameCollatxt->TabIndex = 2;
			// 
			// LabelNomColla
			// 
			this->LabelNomColla->AutoSize = true;
			this->LabelNomColla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->LabelNomColla->Location = System::Drawing::Point(80, 73);
			this->LabelNomColla->Name = L"LabelNomColla";
			this->LabelNomColla->Size = System::Drawing::Size(56, 18);
			this->LabelNomColla->TabIndex = 3;
			this->LabelNomColla->Text = L"Nom:*";
			// 
			// LabelLogoColla
			// 
			this->LabelLogoColla->AutoSize = true;
			this->LabelLogoColla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->LabelLogoColla->Location = System::Drawing::Point(80, 115);
			this->LabelLogoColla->Name = L"LabelLogoColla";
			this->LabelLogoColla->Size = System::Drawing::Size(51, 18);
			this->LabelLogoColla->TabIndex = 4;
			this->LabelLogoColla->Text = L"Logo:";
			// 
			// LabelLocalitzacioColla
			// 
			this->LabelLocalitzacioColla->AutoSize = true;
			this->LabelLocalitzacioColla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->LabelLocalitzacioColla->Location = System::Drawing::Point(80, 183);
			this->LabelLocalitzacioColla->Name = L"LabelLocalitzacioColla";
			this->LabelLocalitzacioColla->Size = System::Drawing::Size(111, 18);
			this->LabelLocalitzacioColla->TabIndex = 5;
			this->LabelLocalitzacioColla->Text = L"Localització:*";
			// 
			// LabelUniversitatColla
			// 
			this->LabelUniversitatColla->AutoSize = true;
			this->LabelUniversitatColla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->LabelUniversitatColla->Location = System::Drawing::Point(80, 238);
			this->LabelUniversitatColla->Name = L"LabelUniversitatColla";
			this->LabelUniversitatColla->Size = System::Drawing::Size(100, 18);
			this->LabelUniversitatColla->TabIndex = 6;
			this->LabelUniversitatColla->Text = L"Universitat:*";
			// 
			// BtnCrearColla
			// 
			this->BtnCrearColla->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BtnCrearColla->Enabled = false;
			this->BtnCrearColla->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnCrearColla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->BtnCrearColla->ForeColor = System::Drawing::Color::White;
			this->BtnCrearColla->Location = System::Drawing::Point(280, 350);
			this->BtnCrearColla->Name = L"BtnCrearColla";
			this->BtnCrearColla->Size = System::Drawing::Size(180, 40);
			this->BtnCrearColla->TabIndex = 7;
			this->BtnCrearColla->Text = L"✅ Crear Colla";
			this->BtnCrearColla->UseVisualStyleBackColor = false;
			this->BtnCrearColla->Click += gcnew System::EventHandler(this, &CrearCollaForm::BtnCrearColla_Click);
			// 
			// BtnNetejar
			// 
			this->BtnNetejar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnNetejar->Location = System::Drawing::Point(480, 350);
			this->BtnNetejar->Name = L"BtnNetejar";
			this->BtnNetejar->Size = System::Drawing::Size(100, 40);
			this->BtnNetejar->TabIndex = 8;
			this->BtnNetejar->Text = L"🔄 Netejar";
			this->BtnNetejar->UseVisualStyleBackColor = true;
			this->BtnNetejar->Click += gcnew System::EventHandler(this, &CrearCollaForm::BtnNetejar_Click);
			// 
			// LabelMissatge
			// 
			this->LabelMissatge->AutoSize = true;
			this->LabelMissatge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->LabelMissatge->Location = System::Drawing::Point(80, 410);
			this->LabelMissatge->Name = L"LabelMissatge";
			this->LabelMissatge->Size = System::Drawing::Size(0, 18);
			this->LabelMissatge->TabIndex = 9;
			// 
			// LogoPictureBox
			// 
			this->LogoPictureBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->LogoPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LogoPictureBox->Location = System::Drawing::Point(280, 110);
			this->LogoPictureBox->Name = L"LogoPictureBox";
			this->LogoPictureBox->Size = System::Drawing::Size(70, 64);
			this->LogoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->LogoPictureBox->TabIndex = 10;
			this->LogoPictureBox->TabStop = false;
			// 
			// BtnPujarLogo
			// 
			this->BtnPujarLogo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnPujarLogo->Location = System::Drawing::Point(280, 275);
			this->BtnPujarLogo->Name = L"BtnPujarLogo";
			this->BtnPujarLogo->Size = System::Drawing::Size(140, 30);
			this->BtnPujarLogo->TabIndex = 11;
			this->BtnPujarLogo->Text = L"📁 Pujar Logo";
			this->BtnPujarLogo->UseVisualStyleBackColor = true;
			this->BtnPujarLogo->Click += gcnew System::EventHandler(this, &CrearCollaForm::BtnPujarLogo_Click);
			// 
			// BtnEliminarLogo
			// 
			this->BtnEliminarLogo->Enabled = false;
			this->BtnEliminarLogo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnEliminarLogo->Location = System::Drawing::Point(440, 275);
			this->BtnEliminarLogo->Name = L"BtnEliminarLogo";
			this->BtnEliminarLogo->Size = System::Drawing::Size(140, 30);
			this->BtnEliminarLogo->TabIndex = 12;
			this->BtnEliminarLogo->Text = L"🗑️ Eliminar Logo";
			this->BtnEliminarLogo->UseVisualStyleBackColor = true;
			this->BtnEliminarLogo->Click += gcnew System::EventHandler(this, &CrearCollaForm::BtnEliminarLogo_Click);
			// 
			// LabelInfoLogo
			// 
			this->LabelInfoLogo->AutoSize = true;
			this->LabelInfoLogo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F));
			this->LabelInfoLogo->ForeColor = System::Drawing::Color::Gray;
			this->LabelInfoLogo->Location = System::Drawing::Point(280, 315);
			this->LabelInfoLogo->Name = L"LabelInfoLogo";
			this->LabelInfoLogo->Size = System::Drawing::Size(219, 16);
			this->LabelInfoLogo->TabIndex = 13;
			this->LabelInfoLogo->Text = L"Formats: JPG, PNG, GIF (Màx. 5MB)";
			// 
			// CrearCollaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->ClientSize = System::Drawing::Size(700, 460);
			this->Controls->Add(this->LabelInfoLogo);
			this->Controls->Add(this->BtnEliminarLogo);
			this->Controls->Add(this->BtnPujarLogo);
			this->Controls->Add(this->LogoPictureBox);
			this->Controls->Add(this->LabelMissatge);
			this->Controls->Add(this->BtnNetejar);
			this->Controls->Add(this->BtnCrearColla);
			this->Controls->Add(this->LabelUniversitatColla);
			this->Controls->Add(this->LabelLocalitzacioColla);
			this->Controls->Add(this->LabelLogoColla);
			this->Controls->Add(this->LabelNomColla);
			this->Controls->Add(this->UniNameCollatxt);
			this->Controls->Add(this->LocationCollatxt);
			this->Controls->Add(this->NameCollatxt);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"CrearCollaForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"🏗️ Crear Nova Colla";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// 🔹 Mètode per configurar validacions en temps real
	private: System::Void ConfigurarValidacions() {
		LabelMissatge->Text = "💡 Ompli els camps obligatoris (*) per habilitar el botó";
		LabelMissatge->ForeColor = System::Drawing::Color::FromArgb(0, 123, 255);
		ValidarFormulari();
	}

		   // 🔹 Validació en temps real del nom
	private: System::Void NomColla_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		ValidarFormulari();
	}

		   // 🔹 Validació en temps real de la localització
	private: System::Void Localitzacio_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		ValidarFormulari();
	}

		   // 🔹 Validació completa del formulari
	private: System::Void ValidarFormulari() {
		bool nomValid = !String::IsNullOrWhiteSpace(NameCollatxt->Text->Trim());
		bool localitzacioValid = !String::IsNullOrWhiteSpace(LocationCollatxt->Text->Trim());

		// Validar longituds
		if (nomValid && NameCollatxt->Text->Trim()->Length > 100) {
			nomValid = false;
		}
		if (localitzacioValid && LocationCollatxt->Text->Trim()->Length > 200) {
			localitzacioValid = false;
		}

		BtnCrearColla->Enabled = nomValid && localitzacioValid;
	}

		   // 🔹 Event: Pujar Logo 📁
	private: System::Void BtnPujarLogo_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Title = "Seleccionar Logo de la Colla";
		ofd->Filter = "Fitxers d'imatge|*.jpg;*.jpeg;*.png;*.gif|Tots els fitxers|*.*";
		ofd->FilterIndex = 1;
		ofd->RestoreDirectory = true;

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				// 🔹 Validar mida del fitxer (5MB màxim)
				FileInfo^ fileInfo = gcnew FileInfo(ofd->FileName);
				long midaFitxer = fileInfo->Length;

				if (midaFitxer > 5 * 1024 * 1024) {  // 5MB
					MessageBox::Show(
						"El fitxer seleccionat supera els 5MB. Si us plau, seleccioni una imatge més petita.",
						"Mida de fitxer massa gran",
						MessageBoxButtons::OK,
						MessageBoxIcon::Warning
					);
					return;
				}

				// 🔹 Llegir el fitxer i convertir-lo a bytes
				logoData = File::ReadAllBytes(ofd->FileName);
				rutaLogoTemporal = ofd->FileName;

				// 🔹 Mostrar preview al PictureBox
				LogoPictureBox->Image = Image::FromFile(ofd->FileName);

				// 🔹 Habilitar botó d'eliminar
				BtnEliminarLogo->Enabled = true;

				// 🔹 Mostrar informació del fitxer
				LabelInfoLogo->Text = String::Format(
					"✅ {0} ({1:F2} KB)",
					Path::GetFileName(ofd->FileName),
					midaFitxer / 1024.0
				);
				LabelInfoLogo->ForeColor = System::Drawing::Color::Green;

				// 🔹 Validar formulari de nou (el logo és opcional però ja està carregat)
				ValidarFormulari();
			}
			catch (Exception^ ex) {
				MessageBox::Show(
					"Error en carregar el logo: " + ex->Message,
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
			}
		}
	}

		   // 🔹 Event: Eliminar Logo 🗑️
	private: System::Void BtnEliminarLogo_Click(System::Object^ sender, System::EventArgs^ e) {
		logoData = nullptr;
		rutaLogoTemporal = nullptr;

		// 🔹 Netejar PictureBox
		if (LogoPictureBox->Image != nullptr) {
			delete LogoPictureBox->Image;
			LogoPictureBox->Image = nullptr;
		}

		// 🔹 Deshabilitar botó d'eliminar
		BtnEliminarLogo->Enabled = false;

		// 🔹 Restaurar text informatiu
		LabelInfoLogo->Text = "Formats: JPG, PNG, GIF (Màx. 5MB)";
		LabelInfoLogo->ForeColor = System::Drawing::Color::Gray;
	}

		   // 🔹 Event: Crear Colla ✅
	private: System::Void BtnCrearColla_Click(System::Object^ sender, System::EventArgs^ e) {

		// 🔹 1. Recollir dades del formulari
		String^ nom = NameCollatxt->Text->Trim();
		String^ localitzacio = LocationCollatxt->Text->Trim();
		String^ univ = UniNameCollatxt->Text->Trim();

		// 🔹 2. Crear DTO amb les dades
		CollaDTO^ novaColla = gcnew CollaDTO();
		novaColla->nom = nom;
		novaColla->localitzacio = localitzacio;
		novaColla->univ = String::IsNullOrWhiteSpace(univ) ? nullptr : univ;
		novaColla->actiu = true;
		novaColla->logo = logoData;  // 🔹 Assignar logo (pot ser nullptr si no s'ha pujat)

		// 🔹 3. Cridar al controlador per crear la colla
		String^ error;
		bool resultat = CtrlCrearColla::Crear(usuariIdActual, novaColla, error);

		// 🔹 4. Mostrar feedback a l'usuari
		if (resultat) {
			LabelMissatge->Text = "✅ Colla creada correctament!";
			LabelMissatge->ForeColor = System::Drawing::Color::Green;

			MessageBox::Show(
				"La colla \"" + nom + "\" s'ha creat amb èxit!\n\nID: " + novaColla->id,
				"Èxit",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			// 🔹 Tancar el formulari
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else {
			LabelMissatge->Text = "❌ Error: " + error;
			LabelMissatge->ForeColor = System::Drawing::Color::Red;

			MessageBox::Show(
				"No s'ha pogut crear la colla:\n\n" + error,
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}

		   // 🔹 Event: Netejar Formulari 🔄
	private: System::Void BtnNetejar_Click(System::Object^ sender, System::EventArgs^ e) {
		// 🔹 Netejar textboxes
		NameCollatxt->Clear();
		LocationCollatxt->Clear();
		UniNameCollatxt->Clear();

		// 🔹 Netejar logo
		BtnEliminarLogo_Click(sender, e);

		// 🔹 Netejar missatges
		LabelMissatge->Text = "💡 Formulari netejat. Ompli els camps per crear una nova colla";
		LabelMissatge->ForeColor = System::Drawing::Color::FromArgb(0, 123, 255);

		// 🔹 Deshabilitar botó crear
		BtnCrearColla->Enabled = false;

		// 🔹 Posar focus al primer camp
		NameCollatxt->Focus();
	}
	};
}