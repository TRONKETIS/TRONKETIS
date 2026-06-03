#pragma once

#include "CtrlGestioMembreColla.h"
#include "CercadorMembre.h"
#include "UiStyle.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class EliminarMembreForm : public System::Windows::Forms::Form
	{
	public:
		EliminarMembreForm(String^ collaName)
		{
			InitializeComponent();
			this->collaName = collaName;
			lblCollaActual->Text = L"Colla: " + collaName;
			CarregarMembres();
		}

	protected:
		~EliminarMembreForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ collaName;

	private: System::Windows::Forms::Panel^ panelHeader;
	private: System::Windows::Forms::Panel^ panelContenido;
	private: System::Windows::Forms::Label^ lblTitol;
	private: System::Windows::Forms::Label^ lblSubtitulo;
	private: System::Windows::Forms::Label^ lblCollaActual;
	private: System::Windows::Forms::Label^ lblMembre;
	private: System::Windows::Forms::ComboBox^ cmbMembres;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnTornar;
	private: System::Windows::Forms::Label^ lblMissatge;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblCollaActual = (gcnew System::Windows::Forms::Label());
			this->lblMembre = (gcnew System::Windows::Forms::Label());
			this->cmbMembres = (gcnew System::Windows::Forms::ComboBox());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnTornar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 560, 440, L"Eliminar Membre");
			UiStyle::ApplyHeader(this->panelHeader, this->lblTitol, this->lblSubtitulo, 560, L"Eliminar Membre", L"Selecciona el membre de la colla");
			UiStyle::ApplyCard(this->panelContenido, 45, 122, 470, 270);

			UiStyle::ApplyValueLabel(this->lblCollaActual);
			this->lblCollaActual->Location = System::Drawing::Point(32, 26);
			this->lblCollaActual->Name = L"lblCollaActual";
			this->lblCollaActual->Text = L"Colla:";

			UiStyle::ApplyLabel(this->lblMembre);
			this->lblMembre->Location = System::Drawing::Point(32, 82);
			this->lblMembre->Name = L"lblMembre";
			this->lblMembre->Text = L"Membre:";

			UiStyle::ApplyCombo(this->cmbMembres, 280);
			this->cmbMembres->Location = System::Drawing::Point(150, 79);
			this->cmbMembres->Name = L"cmbMembres";
			this->cmbMembres->TabIndex = 1;

			UiStyle::ApplyDangerButton(this->btnEliminar);
			this->btnEliminar->Location = System::Drawing::Point(32, 140);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(195, 42);
			this->btnEliminar->TabIndex = 2;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Click += gcnew System::EventHandler(this, &EliminarMembreForm::btnEliminar_Click);

			UiStyle::ApplySecondaryButton(this->btnTornar);
			this->btnTornar->Location = System::Drawing::Point(235, 140);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(195, 42);
			this->btnTornar->TabIndex = 3;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->Click += gcnew System::EventHandler(this, &EliminarMembreForm::btnTornar_Click);

			UiStyle::ApplyMessage(this->lblMissatge, 400);
			this->lblMissatge->Location = System::Drawing::Point(32, 208);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Text = L"";

			this->panelHeader->Controls->Add(this->lblTitol);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelContenido->Controls->Add(this->lblCollaActual);
			this->panelContenido->Controls->Add(this->lblMembre);
			this->panelContenido->Controls->Add(this->cmbMembres);
			this->panelContenido->Controls->Add(this->btnEliminar);
			this->panelContenido->Controls->Add(this->btnTornar);
			this->panelContenido->Controls->Add(this->lblMissatge);
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->panelContenido);
			this->Name = L"EliminarMembreForm";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		void CarregarMembres()
		{
			cmbMembres->Items->Clear();

			List<String^>^ membres = CercadorMembre::obtenirDnisMembresPerColla(this->collaName);
			for each (String ^ dni in membres) {
				cmbMembres->Items->Add(dni);
			}
		}

	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = "";

		if (cmbMembres->SelectedItem != nullptr) {
			dni = cmbMembres->SelectedItem->ToString();
		}

		String^ error = "";
		bool ok = CtrlGestioMembreColla::eliminarMembre(dni, this->collaName, error);

		if (ok) {
			lblMissatge->ForeColor = Color::Green;
			lblMissatge->Text = L"Membre eliminat correctament";
			CarregarMembres();
			cmbMembres->SelectedIndex = -1;
		}
		else {
			lblMissatge->ForeColor = Color::Red;
			lblMissatge->Text = error;
		}
	}

	private: System::Void btnTornar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
