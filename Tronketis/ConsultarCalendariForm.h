#pragma once
#include "CtrlConsultarCalendari.h"
#include "UiStyle.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ConsultarCalendariForm : public System::Windows::Forms::Form
	{
	public:
		ConsultarCalendariForm(String^ rol, String^ collaName)
		{
			this->rolUsuario = rol;
			this->collaName = collaName;
			InitializeComponent();

			ActualizarEventos(monthCalendar1->SelectionStart);
		}

	protected:
		~ConsultarCalendariForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ rolUsuario;
		String^ collaName;

		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::MonthCalendar^ monthCalendar1;
		System::Windows::Forms::ListBox^ lstActivitat;
		System::Windows::Forms::Label^ lblTitol;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblDetalls;
		System::Windows::Forms::Button^ btnTornar;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->lstActivitat = (gcnew System::Windows::Forms::ListBox());
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblDetalls = (gcnew System::Windows::Forms::Label());
			this->btnTornar = (gcnew System::Windows::Forms::Button());
			this->panelHeader->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->SuspendLayout();

			UiStyle::ApplyBase(this, 780, 520, L"Consultar Calendari");
			UiStyle::ApplyHeader(this->panelHeader, this->lblTitol, this->lblSubtitulo, 780, L"Consultar Calendari", L"Consulta activitats per dia");
			UiStyle::ApplyCard(this->panelContenido, 45, 122, 690, 340);

			this->monthCalendar1->Location = System::Drawing::Point(32, 38);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 0;
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &ConsultarCalendariForm::monthCalendar1_DateSelected);

			UiStyle::ApplySection(this->lblDetalls);
			this->lblDetalls->Location = System::Drawing::Point(338, 36);
			this->lblDetalls->Name = L"lblDetalls";
			this->lblDetalls->Text = L"Activitats del dia";

			this->lstActivitat->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F);
			this->lstActivitat->FormattingEnabled = true;
			this->lstActivitat->ItemHeight = 15;
			this->lstActivitat->Location = System::Drawing::Point(340, 68);
			this->lstActivitat->Name = L"lstActivitat";
			this->lstActivitat->Size = System::Drawing::Size(310, 184);
			this->lstActivitat->TabIndex = 1;

			UiStyle::ApplySecondaryButton(this->btnTornar);
			this->btnTornar->Location = System::Drawing::Point(340, 268);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(310, 38);
			this->btnTornar->TabIndex = 2;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->Click += gcnew System::EventHandler(this, &ConsultarCalendariForm::btnTornar_Click);

			this->panelHeader->Controls->Add(this->lblTitol);
			this->panelHeader->Controls->Add(this->lblSubtitulo);
			this->panelContenido->Controls->Add(this->monthCalendar1);
			this->panelContenido->Controls->Add(this->lblDetalls);
			this->panelContenido->Controls->Add(this->lstActivitat);
			this->panelContenido->Controls->Add(this->btnTornar);
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->panelContenido);
			this->Name = L"ConsultarCalendariForm";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelContenido->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

		void ActualizarEventos(DateTime date)
		{
			List<String^>^ activitats = CtrlConsultarCalendari::obtenirActivitatsDelDia(date, rolUsuario, collaName);
			lstActivitat->Items->Clear();

			if (activitats->Count == 0)
			{
				lstActivitat->Items->Add("No hi ha cap activitat aquest dia.");
			}
			else
			{
				for each (String ^ a in activitats)
				{
					lstActivitat->Items->Add(a);
				}
			}
		}

		System::Void monthCalendar1_DateSelected(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
			ActualizarEventos(e->Start);
		}

		System::Void btnTornar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
