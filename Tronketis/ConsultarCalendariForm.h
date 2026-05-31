#pragma once
#include "CtrlConsultarCalendari.h"

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

			// Actualizamos el primer dia por defecto
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

		System::Windows::Forms::MonthCalendar^ monthCalendar1;
		System::Windows::Forms::ListBox^ lstActivitat;
		System::Windows::Forms::Label^ lblTitol;
		System::Windows::Forms::Label^ lblDetalls;
		System::Windows::Forms::Button^ btnTornar;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->lstActivitat = (gcnew System::Windows::Forms::ListBox());
			this->lblTitol = (gcnew System::Windows::Forms::Label());
			this->lblDetalls = (gcnew System::Windows::Forms::Label());
			this->btnTornar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(30, 70);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 0;
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &ConsultarCalendariForm::monthCalendar1_DateSelected);
			// 
			// lstActivitat
			// 
			this->lstActivitat->FormattingEnabled = true;
			this->lstActivitat->ItemHeight = 16;
			this->lstActivitat->Location = System::Drawing::Point(380, 70);
			this->lstActivitat->Name = L"lstActivitat";
			this->lstActivitat->Size = System::Drawing::Size(300, 212);
			this->lstActivitat->TabIndex = 1;
			// 
			// lblTitol
			// 
			this->lblTitol->AutoSize = true;
			this->lblTitol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->lblTitol->Location = System::Drawing::Point(220, 20);
			this->lblTitol->Name = L"lblTitol";
			this->lblTitol->Size = System::Drawing::Size(248, 29);
			this->lblTitol->TabIndex = 2;
			this->lblTitol->Text = L"Consultar Calendari";
			// 
			// lblDetalls
			// 
			this->lblDetalls->AutoSize = true;
			this->lblDetalls->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->lblDetalls->Location = System::Drawing::Point(377, 45);
			this->lblDetalls->Name = L"lblDetalls";
			this->lblDetalls->Size = System::Drawing::Size(130, 18);
			this->lblDetalls->TabIndex = 3;
			this->lblDetalls->Text = L"Activitats del dia:";
			// 
			// btnTornar
			// 
			this->btnTornar->Location = System::Drawing::Point(30, 300);
			this->btnTornar->Name = L"btnTornar";
			this->btnTornar->Size = System::Drawing::Size(120, 35);
			this->btnTornar->TabIndex = 4;
			this->btnTornar->Text = L"Tornar";
			this->btnTornar->UseVisualStyleBackColor = true;
			this->btnTornar->Click += gcnew System::EventHandler(this, &ConsultarCalendariForm::btnTornar_Click);
			// 
			// ConsultarCalendariForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(720, 360);
			this->Controls->Add(this->btnTornar);
			this->Controls->Add(this->lblDetalls);
			this->Controls->Add(this->lblTitol);
			this->Controls->Add(this->lstActivitat);
			this->Controls->Add(this->monthCalendar1);
			this->Name = L"ConsultarCalendariForm";
			this->Text = L"Consultar Calendari";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

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