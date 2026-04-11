#pragma once
#include "CtrlModificarUsuari.h"
#include "UsuariDTO.h"

namespace Tronketis {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
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
        }

        // Método para cargar los datos del usuario seleccionado
        void cargarUsuario(UsuariDTO^ u)
        {
            txtDNI->Text = u->dni;
            txtUsername->Text = u->username;
            txtEmail->Text = u->email;
            txtPassword->Text = u->password;
            comboRol->SelectedItem = u->rol;
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

        System::Windows::Forms::Label^ lblDNI;
        System::Windows::Forms::TextBox^ txtDNI;
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

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblDNI = (gcnew System::Windows::Forms::Label());
            this->txtDNI = (gcnew System::Windows::Forms::TextBox());
            this->lblUsername = (gcnew System::Windows::Forms::Label());
            this->txtUsername = (gcnew System::Windows::Forms::TextBox());
            this->lblEmail = (gcnew System::Windows::Forms::Label());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->lblPassword = (gcnew System::Windows::Forms::Label());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->lblRol = (gcnew System::Windows::Forms::Label());
            this->comboRol = (gcnew System::Windows::Forms::ComboBox());
            this->btnGuardar = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // lblDNI
            this->lblDNI->Location = System::Drawing::Point(40, 40);
            this->lblDNI->Text = L"DNI";

            // txtDNI
            this->txtDNI->Location = System::Drawing::Point(180, 40);
            this->txtDNI->ReadOnly = false;

            // lblUsername
            this->lblUsername->Location = System::Drawing::Point(40, 90);
            this->lblUsername->Text = L"Nom d'usuari";

            // txtUsername
            this->txtUsername->Location = System::Drawing::Point(180, 90);

            // lblEmail
            this->lblEmail->Location = System::Drawing::Point(40, 140);
            this->lblEmail->Text = L"Email";

            // txtEmail
            this->txtEmail->Location = System::Drawing::Point(180, 140);

            // lblPassword
            this->lblPassword->Location = System::Drawing::Point(40, 190);
            this->lblPassword->Text = L"Contrasenya";

            // txtPassword
            this->txtPassword->Location = System::Drawing::Point(180, 190);

            // lblRol
            this->lblRol->Location = System::Drawing::Point(40, 240);
            this->lblRol->Text = L"Rol";

            // comboRol
            this->comboRol->Location = System::Drawing::Point(180, 240);
            this->comboRol->Items->AddRange(gcnew cli::array<Object^> { L"Casteller", L"Administrador", L"CapColla" });

            // btnGuardar
            this->btnGuardar->Location = System::Drawing::Point(180, 300);
            this->btnGuardar->Text = L"Guardar";
            this->btnGuardar->Click += gcnew System::EventHandler(this, &ModificarUsuariForm::btnGuardar_Click);

            // Form
            this->ClientSize = System::Drawing::Size(450, 380);
            this->Controls->Add(this->lblDNI);
            this->Controls->Add(this->txtDNI);
            this->Controls->Add(this->lblUsername);
            this->Controls->Add(this->txtUsername);
            this->Controls->Add(this->lblEmail);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->lblPassword);
            this->Controls->Add(this->txtPassword);
            this->Controls->Add(this->lblRol);
            this->Controls->Add(this->comboRol);
            this->Controls->Add(this->btnGuardar);
            this->Text = L"Modificar Usuari";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {

            UsuariDTO^ u = gcnew UsuariDTO();
            u->dni = txtDNI->Text;
            u->username = txtUsername->Text;
            u->email = txtEmail->Text;
            u->password = txtPassword->Text;
            u->rol = comboRol->SelectedItem != nullptr ? comboRol->SelectedItem->ToString() : "";

            String^ error;
            bool ok = ctrl->modificar(u, error);

            if (ok) {
                MessageBox::Show("Usuari modificat correctament");
                this->Close();
            }
            else {
                MessageBox::Show(error);
            }
        }
    };
}
