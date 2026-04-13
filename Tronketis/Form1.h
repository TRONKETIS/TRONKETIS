#pragma once
#include "CercadorUsuari.h"

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form1 : public Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
                delete components;
        }

    private:
        TextBox^ txtUsername;
        Button^ btnBuscar;
        Label^ lblResultado;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->txtUsername = gcnew TextBox();
            this->btnBuscar = gcnew Button();
            this->lblResultado = gcnew Label();

            this->SuspendLayout();

            // txtUsername
            this->txtUsername->Location = System::Drawing::Point(50, 50);
            this->txtUsername->Size = System::Drawing::Size(200, 26);

            // btnBuscar
            this->btnBuscar->Location = System::Drawing::Point(50, 100);
            this->btnBuscar->Text = "Buscar";
            this->btnBuscar->Click += gcnew EventHandler(this, &Form1::btnBuscar_Click);

            // lblResultado
            this->lblResultado->Location = System::Drawing::Point(50, 150);
            this->lblResultado->Size = System::Drawing::Size(500, 30);

            // Form
            this->Controls->Add(this->txtUsername);
            this->Controls->Add(this->btnBuscar);
            this->Controls->Add(this->lblResultado);

            this->Text = "Buscar Usuario";
            this->ClientSize = System::Drawing::Size(600, 300);

            this->ResumeLayout(false);
        }

    private:
        System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ username = txtUsername->Text;

            String^ dni;
            String^ password;
            String^ rol;

            // 🔥 ORDEN CORRECTO
            if (CercadorUsuari::CercaPerUsername(username, dni, password, rol))
            {
                lblResultado->Text = "DNI: " + dni + " | Password: " + password + " | Rol: " + rol;
            }
            else
            {
                lblResultado->Text = "Usuario no encontrado";
            }
        }
    };
}