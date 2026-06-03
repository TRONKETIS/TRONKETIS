#pragma once

#include "UiStyle.h"
#include "CercadorDiada.h"
#include "CercadorCasteller.h"
#include "CtrlRegistrarAssistencia.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class RegistrarAssistenciaForm : public System::Windows::Forms::Form
	{
	private:
		List<DiadaDTO^>^ diades;
		List<CastellerDTO^>^ castellers;
		String^ dniCastellerFix;
		bool modeCasteller;

	public:
		RegistrarAssistenciaForm(void)
		{
			this->dniCastellerFix = "";
			this->modeCasteller = false;
			InitializeComponent();
			CarregarDades();
		}

		RegistrarAssistenciaForm(String^ dniCasteller)
		{
			this->dniCastellerFix = dniCasteller;
			this->modeCasteller = true;
			InitializeComponent();
			CarregarDades();
		}

	protected:
		~RegistrarAssistenciaForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelCard;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblCardTitle;
		System::Windows::Forms::Label^ lblInfo;
		System::Windows::Forms::Label^ lblDiada;
		System::Windows::Forms::ComboBox^ cmbDiades;
		System::Windows::Forms::Label^ lblCasteller;
		System::Windows::Forms::ComboBox^ cmbCastellers;
		System::Windows::Forms::Label^ lblEstat;
		System::Windows::Forms::ComboBox^ cmbEstat;
		System::Windows::Forms::Button^ btnRegistrar;
		System::Windows::Forms::Label^ lblMissatge;
		System::ComponentModel::Container^ components;

		void CarregarDades()
		{
			this->lblMissatge->Text = "";

			diades = CercadorDiada::obtenirTotes();
			for each (DiadaDTO ^ d in diades)
			{
				cmbDiades->Items->Add(d->nom + " - " + d->data.ToShortDateString());
			}

			castellers = CercadorCasteller::obtenirTots();
			int indexCasteller = -1;
			int i = 0;

			for each (CastellerDTO ^ c in castellers)
			{
				cmbCastellers->Items->Add(c->dniCasteller + " - " + c->nomUsuari);

				if (this->modeCasteller && String::Compare(c->dniCasteller, this->dniCastellerFix) == 0)
				{
					indexCasteller = i;
				}

				i++;
			}

			cmbEstat->Items->Add("Apuntat");
			cmbEstat->Items->Add("Confirmat");
			cmbEstat->Items->Add("Cancelat");

			if (cmbDiades->Items->Count > 0)
			{
				cmbDiades->SelectedIndex = 0;
			}

			if (cmbEstat->Items->Count > 0)
			{
				cmbEstat->SelectedIndex = 0;
			}

			if (this->modeCasteller)
			{
				cmbCastellers->Enabled = false;

				if (indexCasteller >= 0)
				{
					cmbCastellers->SelectedIndex = indexCasteller;
					lblInfo->Text = "Registra la teva assistencia a una diada.";
				}
				else
				{
					btnRegistrar->Enabled = false;
					lblMissatge->ForeColor = Color::Red;
					lblMissatge->Text = "No s'ha trobat el casteller a la base de dades.";
				}
			}
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->panelCard = (gcnew System::Windows::Forms::Panel());
			this->lblCardTitle = (gcnew System::Windows::Forms::Label());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->lblDiada = (gcnew System::Windows::Forms::Label());
			this->cmbDiades = (gcnew System::Windows::Forms::ComboBox());
			this->lblCasteller = (gcnew System::Windows::Forms::Label());
			this->cmbCastellers = (gcnew System::Windows::Forms::ComboBox());
			this->lblEstat = (gcnew System::Windows::Forms::Label());
			this->cmbEstat = (gcnew System::Windows::Forms::ComboBox());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->lblMissatge = (gcnew System::Windows::Forms::Label());
			this->panelHeader->SuspendLayout();
			this->panelCard->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 680, 560, L"Registrar Assistencia");
			UiStyle::ApplyHeader(this->panelHeader, this->lblTitulo, this->lblSubtitulo, 680, L"Tronketis", L"Assistencia a diades");
			UiStyle::ApplyCard(this->panelCard, 65, 125, 550, 370);

			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelHeader->Controls->Add(this->lblTitulo);

			UiStyle::ApplyTitle(this->lblCardTitle);
			this->lblCardTitle->Location = System::Drawing::Point(38, 28);
			this->lblCardTitle->Name = L"lblCardTitle";
			this->lblCardTitle->Text = L"Registrar Assistencia";

			UiStyle::ApplyMessage(this->lblInfo, 460);
			this->lblInfo->Location = System::Drawing::Point(41, 65);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Text = L"Selecciona la diada, el casteller i l'estat de participacio.";

			UiStyle::ApplyLabel(this->lblDiada);
			this->lblDiada->Location = System::Drawing::Point(41, 115);
			this->lblDiada->Name = L"lblDiada";
			this->lblDiada->Text = L"Diada";

			UiStyle::ApplyCombo(this->cmbDiades, 300);
			this->cmbDiades->Location = System::Drawing::Point(190, 112);
			this->cmbDiades->Name = L"cmbDiades";
			this->cmbDiades->TabIndex = 0;

			UiStyle::ApplyLabel(this->lblCasteller);
			this->lblCasteller->Location = System::Drawing::Point(41, 164);
			this->lblCasteller->Name = L"lblCasteller";
			this->lblCasteller->Text = L"Casteller";

			UiStyle::ApplyCombo(this->cmbCastellers, 300);
			this->cmbCastellers->Location = System::Drawing::Point(190, 161);
			this->cmbCastellers->Name = L"cmbCastellers";
			this->cmbCastellers->TabIndex = 1;

			UiStyle::ApplyLabel(this->lblEstat);
			this->lblEstat->Location = System::Drawing::Point(41, 213);
			this->lblEstat->Name = L"lblEstat";
			this->lblEstat->Text = L"Estat";

			UiStyle::ApplyCombo(this->cmbEstat, 300);
			this->cmbEstat->Location = System::Drawing::Point(190, 210);
			this->cmbEstat->Name = L"cmbEstat";
			this->cmbEstat->TabIndex = 2;

			UiStyle::ApplyButton(this->btnRegistrar);
			this->btnRegistrar->Location = System::Drawing::Point(190, 267);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(300, 42);
			this->btnRegistrar->TabIndex = 3;
			this->btnRegistrar->Text = L"Registrar";
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &RegistrarAssistenciaForm::btnRegistrar_Click);

			UiStyle::ApplyMessage(this->lblMissatge, 460);
			this->lblMissatge->Location = System::Drawing::Point(41, 326);
			this->lblMissatge->Name = L"lblMissatge";
			this->lblMissatge->Text = L"";

			this->panelCard->Controls->Add(this->lblCardTitle);
			this->panelCard->Controls->Add(this->lblInfo);
			this->panelCard->Controls->Add(this->lblDiada);
			this->panelCard->Controls->Add(this->cmbDiades);
			this->panelCard->Controls->Add(this->lblCasteller);
			this->panelCard->Controls->Add(this->cmbCastellers);
			this->panelCard->Controls->Add(this->lblEstat);
			this->panelCard->Controls->Add(this->cmbEstat);
			this->panelCard->Controls->Add(this->btnRegistrar);
			this->panelCard->Controls->Add(this->lblMissatge);

			this->Controls->Add(this->panelCard);
			this->Controls->Add(this->panelHeader);
			this->Name = L"RegistrarAssistenciaForm";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelCard->ResumeLayout(false);
			this->panelCard->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (cmbDiades->SelectedIndex < 0)
		{
			MessageBox::Show("Selecciona una diada");
			return;
		}

		if (cmbCastellers->SelectedIndex < 0)
		{
			MessageBox::Show("Selecciona un casteller");
			return;
		}

		if (cmbEstat->SelectedIndex < 0)
		{
			MessageBox::Show("Selecciona un estat");
			return;
		}

		DiadaDTO^ diada = diades[cmbDiades->SelectedIndex];
		CastellerDTO^ casteller = castellers[cmbCastellers->SelectedIndex];

		ParticipacioDiadaDTO^ dto = gcnew ParticipacioDiadaDTO();
		dto->diadaName = diada->nom;
		dto->dateDiada = diada->data;
		dto->dni = casteller->dniCasteller;
		dto->estat = cmbEstat->SelectedItem->ToString();

		String^ error;
		bool ok = CtrlRegistrarAssistencia::executar(dto, error);

		if (ok)
		{
			lblMissatge->ForeColor = Color::Green;
			lblMissatge->Text = "Assistencia registrada correctament";
			MessageBox::Show("Operacio correcta");
		}
		else
		{
			lblMissatge->ForeColor = Color::Red;
			lblMissatge->Text = error;
			MessageBox::Show(error);
		}
	}
	};
}
