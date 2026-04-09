#pragma once
#include "AppColors.h"
namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuAdminForm
	/// </summary>
	public ref class MenuAdminForm : public System::Windows::Forms::Form
	{
	public:
		MenuAdminForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			/*go to reg button begg*/
			this->btnGoToRegUser->BackColor = AppColors::DarkRed;
			//this->btnGoToRegUser->ForeColor = AppColors::White;

			this->btnGoToRegUser->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
			this->btnGoToRegUser->FlatAppearance->MouseDownBackColor = AppColors::Black;

			this->btnGoToRegUser->MouseEnter += gcnew EventHandler(this, &MenuAdminForm::OnHoverEnter);
			this->btnGoToRegUser->MouseLeave += gcnew EventHandler(this, &MenuAdminForm::OnHoverLeave);
			/*go to reg button end*/

			/*delete user button begg*/
			this->btnGoToDelUser->BackColor = AppColors::DarkRed;
			//this->btnGoToRegUser->ForeColor = AppColors::White;

			this->btnGoToDelUser->FlatAppearance->MouseOverBackColor = AppColors::Yellow;
			this->btnGoToDelUser->FlatAppearance->MouseDownBackColor = AppColors::Black;

			this->btnGoToDelUser->MouseEnter += gcnew EventHandler(this, &MenuAdminForm::OnHoverEnter);
			this->btnGoToDelUser->MouseLeave += gcnew EventHandler(this, &MenuAdminForm::OnHoverLeave);
			/*delete user button end*/
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuAdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblWelcom;
	protected:
	private: System::Windows::Forms::Label^ lblAdminName;
	private: System::Windows::Forms::Button^ btnGoToRegUser;
	private: System::Windows::Forms::Button^ btnGoToDelUser;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuAdminForm::typeid));
			this->lblWelcom = (gcnew System::Windows::Forms::Label());
			this->lblAdminName = (gcnew System::Windows::Forms::Label());
			this->btnGoToRegUser = (gcnew System::Windows::Forms::Button());
			this->btnGoToDelUser = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblWelcom
			// 
			this->lblWelcom->AutoSize = true;
			this->lblWelcom->Location = System::Drawing::Point(184, 69);
			this->lblWelcom->Name = L"lblWelcom";
			this->lblWelcom->Size = System::Drawing::Size(124, 16);
			this->lblWelcom->TabIndex = 0;
			this->lblWelcom->Text = L"Bienvenid@ admin ";
			// 
			// lblAdminName
			// 
			this->lblAdminName->AutoSize = true;
			this->lblAdminName->Location = System::Drawing::Point(308, 69);
			this->lblAdminName->Name = L"lblAdminName";
			this->lblAdminName->Size = System::Drawing::Size(85, 16);
			this->lblAdminName->TabIndex = 1;
			this->lblAdminName->Text = L"admin_name";
			// 
			// btnGoToRegUser
			// 
			this->btnGoToRegUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGoToRegUser->Location = System::Drawing::Point(187, 123);
			this->btnGoToRegUser->Name = L"btnGoToRegUser";
			this->btnGoToRegUser->Size = System::Drawing::Size(206, 36);
			this->btnGoToRegUser->TabIndex = 2;
			this->btnGoToRegUser->Text = L"Registrar Usuario";
			this->btnGoToRegUser->UseVisualStyleBackColor = false;
			this->btnGoToRegUser->Click += gcnew System::EventHandler(this, &MenuAdminForm::btnGoToRegUser_Click);
			// 
			// btnGoToDelUser
			// 
			this->btnGoToDelUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnGoToDelUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGoToDelUser->Location = System::Drawing::Point(187, 178);
			this->btnGoToDelUser->Name = L"btnGoToDelUser";
			this->btnGoToDelUser->Size = System::Drawing::Size(206, 36);
			this->btnGoToDelUser->TabIndex = 3;
			this->btnGoToDelUser->Text = L"Borrar Usuario";
			this->btnGoToDelUser->UseVisualStyleBackColor = false;
			// 
			// MenuAdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 443);
			this->Controls->Add(this->btnGoToDelUser);
			this->Controls->Add(this->btnGoToRegUser);
			this->Controls->Add(this->lblAdminName);
			this->Controls->Add(this->lblWelcom);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MenuAdminForm";
			this->Text = L"MenuAdminForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OnHoverEnter(System::Object^ sender, System::EventArgs^ e)
	{
		btnGoToRegUser->ForeColor = AppColors::Black;
		btnGoToDelUser->ForeColor = AppColors::Black;

	}
	private: System::Void OnHoverLeave(System::Object^ sender, System::EventArgs^ e)
	{
		btnGoToRegUser->ForeColor = AppColors::White;
		btnGoToDelUser->ForeColor = AppColors::Black;
	}
	
	
		   // button click event handlers
	private: System::Void btnGoToRegUser_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
};
}
