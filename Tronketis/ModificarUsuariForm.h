#pragma once
#include "AppColors.h"
#include "CtrlModificarUsuari.h"
#include "CercadorUsuari.h"
#include "UsuariDTO.h"

namespace Tronketis {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ModificarUsuariForm : public System::Windows::Forms::Form
    {
    public:
        ModificarUsuariForm(void)
        {
            InitializeComponent();
            ctrl = gcnew CtrlModificarUsuari();
            this->CargarListaDNIs();
        }

    protected:
        ~ModificarUsuariForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        CtrlModificarUsuari^ ctrl;

        System::Windows::Forms::Panel^ panelHeader;
        System::Windows::Forms::Panel^ panelContenido;
        System::Windows::Forms::Label^ lblTitulo;
        System::Windows::Forms::Label^ lblSubtitulo;
        System::Windows::Forms::Label^ lblDNI;
        System::Windows::Forms::ComboBox^ comboDNI;
        System::Windows::Forms::Label^ lblUsername;
        System::Windows::Forms::TextBox^ txtUsername;
        System::Windows::Forms::Label^ lblEmail;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::Label^ lblPassword;
        System::Windows::Forms::TextBox^ txtPassword;
        System::Windows::Forms::Label^ lblRol;
        System::Windows::Forms::ComboBox^ comboRol;
        System::Windows::Forms::Button^ btnGuardar;

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

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panelHeader = (gcnew System::Windows::Forms::Panel());
            this->lblTitulo = (gcnew System::Windows::Forms::Label());
            this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
            this->panelContenido = (gcnew System::Windows::Forms::Panel());
            this->lblDNI = (gcnew System::Windows::Forms::Label());
            this->comboDNI = (gcnew System::Windows::Forms::ComboBox());
            this->lblUsername = (gcnew System::Windows::Forms::Label());
            this->txtUsername = (gcnew System::Windows::Forms::TextBox());
            this->lblEmail = (gcnew System::Windows::Forms::Label());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->lblPassword = (gcnew System::Windows::Forms::Label());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->lblRol = (gcnew System::Windows::Forms::Label());
            this->comboRol = (gcnew System::Windows::Forms::ComboBox());
            this->btnGuardar = (gcnew System::Windows::Forms::Button());
            this->panelHeader->SuspendLayout();
            this->panelContenido->SuspendLayout();
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
            this->panelHeader->Size = System::Drawing::Size(620, 105);
            this->panelHeader->TabIndex = 0;
            // 
            // lblTitulo
            // 
            this->lblTitulo->AutoSize = true;
            this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.0F, System::Drawing::FontStyle::Bold));
            this->lblTitulo->ForeColor = AppColors::White;
            this->lblTitulo->Location = System::Drawing::Point(34, 22);
            this->lblTitulo->Name = L"lblTitulo";
            this->lblTitulo->Size = System::Drawing::Size(270, 41);
            this->lblTitulo->TabIndex = 0;
            this->lblTitulo->Text = L"Modificar usuario";
            // 
            // lblSubtitulo
            // 
            this->lblSubtitulo->AutoSize = true;
            this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
            this->lblSubtitulo->ForeColor = AppColors::White;
            this->lblSubtitulo->Location = System::Drawing::Point(39, 66);
            this->lblSubtitulo->Name = L"lblSubtitulo";
            this->lblSubtitulo->Size = System::Drawing::Size(230, 17);
            this->lblSubtitulo->TabIndex = 1;
            this->lblSubtitulo->Text = L"Edita los datos de un usuario";
            // 
            // panelContenido
            // 
            this->panelContenido->BackColor = AppColors::White;
            this->panelContenido->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelContenido->Controls->Add(this->lblDNI);
            this->panelContenido->Controls->Add(this->comboDNI);
            this->panelContenido->Controls->Add(this->lblUsername);
            this->panelContenido->Controls->Add(this->txtUsername);
            this->panelContenido->Controls->Add(this->lblEmail);
            this->panelContenido->Controls->Add(this->txtEmail);
            this->panelContenido->Controls->Add(this->lblPassword);
            this->panelContenido->Controls->Add(this->txtPassword);
            this->panelContenido->Controls->Add(this->lblRol);
            this->panelContenido->Controls->Add(this->comboRol);
            this->panelContenido->Controls->Add(this->btnGuardar);
            this->panelContenido->Location = System::Drawing::Point(42, 130);
            this->panelContenido->Name = L"panelContenido";
            this->panelContenido->Size = System::Drawing::Size(536, 370);
            this->panelContenido->TabIndex = 1;
            // 
            // labels
            // 
            this->lblDNI->Location = System::Drawing::Point(46, 40);
            this->lblDNI->Name = L"lblDNI";
            this->lblDNI->Size = System::Drawing::Size(170, 26);
            this->lblDNI->Text = L"Seleccionar DNI";
            this->lblUsername->Location = System::Drawing::Point(46, 92);
            this->lblUsername->Name = L"lblUsername";
            this->lblUsername->Size = System::Drawing::Size(170, 26);
            this->lblUsername->Text = L"Nombre de usuario";
            this->lblEmail->Location = System::Drawing::Point(46, 144);
            this->lblEmail->Name = L"lblEmail";
            this->lblEmail->Size = System::Drawing::Size(170, 26);
            this->lblEmail->Text = L"Email";
            this->lblPassword->Location = System::Drawing::Point(46, 196);
            this->lblPassword->Name = L"lblPassword";
            this->lblPassword->Size = System::Drawing::Size(170, 26);
            this->lblPassword->Text = L"Contrasena";
            this->lblRol->Location = System::Drawing::Point(46, 248);
            this->lblRol->Name = L"lblRol";
            this->lblRol->Size = System::Drawing::Size(170, 26);
            this->lblRol->Text = L"Rol";
            ConfigurarLabel(this->lblDNI);
            ConfigurarLabel(this->lblUsername);
            ConfigurarLabel(this->lblEmail);
            ConfigurarLabel(this->lblPassword);
            ConfigurarLabel(this->lblRol);
            // 
            // inputs
            // 
            this->comboDNI->Location = System::Drawing::Point(245, 40);
            this->comboDNI->Name = L"comboDNI";
            this->comboDNI->Size = System::Drawing::Size(240, 25);
            this->comboDNI->TabIndex = 0;
            this->comboDNI->SelectedIndexChanged += gcnew System::EventHandler(this, &ModificarUsuariForm::comboDNI_SelectedIndexChanged);
            ConfigurarCombo(this->comboDNI);
            this->txtUsername->Location = System::Drawing::Point(245, 92);
            this->txtUsername->Name = L"txtUsername";
            this->txtUsername->Size = System::Drawing::Size(240, 25);
            this->txtUsername->TabIndex = 1;
            this->txtEmail->Location = System::Drawing::Point(245, 144);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(240, 25);
            this->txtEmail->TabIndex = 2;
            this->txtPassword->Location = System::Drawing::Point(245, 196);
            this->txtPassword->Name = L"txtPassword";
            this->txtPassword->Size = System::Drawing::Size(240, 25);
            this->txtPassword->TabIndex = 3;
            ConfigurarTextBox(this->txtUsername);
            ConfigurarTextBox(this->txtEmail);
            ConfigurarTextBox(this->txtPassword);
            this->comboRol->FormattingEnabled = true;
            this->comboRol->Items->AddRange(gcnew cli::array<Object^> { L"Casteller", L"Administrador", L"CapColla" });
            this->comboRol->Location = System::Drawing::Point(245, 248);
            this->comboRol->Name = L"comboRol";
            this->comboRol->Size = System::Drawing::Size(240, 25);
            this->comboRol->TabIndex = 4;
            ConfigurarCombo(this->comboRol);
            // 
            // btnGuardar
            // 
            this->btnGuardar->Location = System::Drawing::Point(245, 305);
            this->btnGuardar->Name = L"btnGuardar";
            this->btnGuardar->Size = System::Drawing::Size(240, 42);
            this->btnGuardar->TabIndex = 5;
            this->btnGuardar->Text = L"Guardar cambios";
            this->btnGuardar->UseVisualStyleBackColor = false;
            this->btnGuardar->Click += gcnew System::EventHandler(this, &ModificarUsuariForm::btnGuardar_Click);
            ConfigurarBotonPrincipal(this->btnGuardar);
            // 
            // ModificarUsuariForm
            // 
            this->AcceptButton = this->btnGuardar;
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = AppColors::Background;
            this->ClientSize = System::Drawing::Size(620, 535);
            this->Controls->Add(this->panelContenido);
            this->Controls->Add(this->panelHeader);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"ModificarUsuariForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Modificar usuario";
            this->panelHeader->ResumeLayout(false);
            this->panelHeader->PerformLayout();
            this->panelContenido->ResumeLayout(false);
            this->panelContenido->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        void CargarListaDNIs() {
            try {
                List<String^>^ lista = CercadorUsuari::obtenerTodosLosDnis();
                comboDNI->Items->Clear();
                for each(String ^ dni in lista) {
                    comboDNI->Items->Add(dni);
                }
            }
            catch (Exception^ e) {
                MessageBox::Show("Error cargando DNIs: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void comboDNI_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            if (comboDNI->SelectedItem != nullptr) {
                String^ dni = comboDNI->SelectedItem->ToString();
                UsuariDTO^ u = CercadorUsuari::buscaPorDNI(dni);
                if (u != nullptr) {
                    txtUsername->Text = u->username;
                    txtEmail->Text = u->email;
                    txtPassword->Text = u->password;
                    comboRol->SelectedItem = u->rol;
                }
            }
        }

        System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (comboDNI->SelectedItem == nullptr) {
                MessageBox::Show("Selecciona un DNI.", "Dato obligatorio", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            UsuariDTO^ u = gcnew UsuariDTO();
            u->dni = comboDNI->SelectedItem->ToString();
            u->username = txtUsername->Text;
            u->email = txtEmail->Text;
            u->password = txtPassword->Text;
            u->rol = comboRol->SelectedItem != nullptr ? comboRol->SelectedItem->ToString() : "";

            String^ error;
            bool ok = ctrl->modificar(u, error);

            if (ok) {
                MessageBox::Show("Usuario modificado correctamente", "Cambios guardados", MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->Close();
            }
            else {
                MessageBox::Show(error, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    };
}
