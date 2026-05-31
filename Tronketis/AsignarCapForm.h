#pragma once
#include "CtrlAdminMenu.h"
#include "CollaDTO.h"
#include "UsuariDTO.h"

namespace Tronketis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AsignarCapForm
	/// </summary>
	public ref class AsignarCapForm : public System::Windows::Forms::Form
	{
	public:
		AsignarCapForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AsignarCapForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cbCollas;
	private: System::Windows::Forms::ComboBox^ cbUsuarios;
	private: System::Windows::Forms::Button^ btnAsignar;





	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cbCollas = (gcnew System::Windows::Forms::ComboBox());
			this->cbUsuarios = (gcnew System::Windows::Forms::ComboBox());
			this->btnAsignar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Selecciona la Colla:";
			this->label1->Click += gcnew System::EventHandler(this, &AsignarCapForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Selecciona el Usuario:\r\n";
			// 
			// cbCollas
			// 
			this->cbCollas->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbCollas->FormattingEnabled = true;
			this->cbCollas->Location = System::Drawing::Point(131, 37);
			this->cbCollas->Name = L"cbCollas";
			this->cbCollas->Size = System::Drawing::Size(121, 21);
			this->cbCollas->TabIndex = 2;
			this->cbCollas->SelectedIndexChanged += gcnew System::EventHandler(this, &AsignarCapForm::comboBox1_SelectedIndexChanged);
			// 
			// cbUsuarios
			// 
			this->cbUsuarios->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbUsuarios->FormattingEnabled = true;
			this->cbUsuarios->Location = System::Drawing::Point(131, 97);
			this->cbUsuarios->Name = L"cbUsuarios";
			this->cbUsuarios->Size = System::Drawing::Size(121, 21);
			this->cbUsuarios->TabIndex = 3;
			// 
			// btnAsignar
			// 
			this->btnAsignar->Location = System::Drawing::Point(61, 201);
			this->btnAsignar->Name = L"btnAsignar";
			this->btnAsignar->Size = System::Drawing::Size(152, 23);
			this->btnAsignar->TabIndex = 4;
			this->btnAsignar->Text = L"Asignar Cap de Colla";
			this->btnAsignar->UseVisualStyleBackColor = true;
			this->btnAsignar->Click += gcnew System::EventHandler(this, &AsignarCapForm::button1_Click);
			// 
			// AsignarCapForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnAsignar);
			this->Controls->Add(this->cbUsuarios);
			this->Controls->Add(this->cbCollas);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AsignarCapForm";
			this->Text = L"AsignarCapForm";
			this->Load += gcnew System::EventHandler(this, &AsignarCapForm::AsignarCapForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->cbCollas->SelectedIndex == -1 || this->cbUsuarios->SelectedIndex == -1) {
		MessageBox::Show("Por favor, selecciona una Colla y un Usuario.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	// 2. Obtener los valores seleccionados (AHORA LOS DOS SON STRING)
	String^ nombreCollaSel = safe_cast<String^>(this->cbCollas->SelectedValue);
	String^ dniUsuarioSel = safe_cast<String^>(this->cbUsuarios->SelectedValue);

	// 3. Llamar al controlador para guardar en la base de datos
	try {
		if (CtrlAdminMenu::AsignarCapDeColla(nombreCollaSel, dniUsuarioSel)) {
			MessageBox::Show("Cap de Colla asignado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close(); // Cerramos este formulario
		}
		else {
			MessageBox::Show("No se pudo realizar la asignación en la base de datos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ocurrió un error de sistema: " + ex->Message, "Error Fatal", MessageBoxButtons::OK, MessageBoxIcon::Stop);
	}
}
private: System::Void AsignarCapForm_Load(System::Object^ sender, System::EventArgs^ e) {
	// Rellenar el ComboBox de Collas
	try {
		// Obtenemos la lista desde el controlador que creamos antes
		System::Collections::Generic::List<CollaDTO^>^ listaCollas = CtrlAdminMenu::ObtenerListaCollas();

		// Configuramos el ComboBox
		this->cbCollas->DataSource = listaCollas;
		this->cbCollas->DisplayMember = "nom"; // Qué propiedad del DTO se muestra (Nombre de la colla)
		this->cbCollas->ValueMember = "nom";    // Qué propiedad se guarda internamente (ID)

		// Opcional: Que empiece sin nada seleccionado
		this->cbCollas->SelectedIndex = -1;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando collas: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	// Rellenar el ComboBox de Usuarios
	try {
		System::Collections::Generic::List<UsuariDTO^>^ listaUsuarios = CtrlAdminMenu::ObtenerListaUsuarios();

		this->cbUsuarios->DataSource = listaUsuarios;
		this->cbUsuarios->DisplayMember = "username"; // O la propiedad que tengas para el nombre de usuario
		this->cbUsuarios->ValueMember = "dni";        // Usamos el DNI como valor interno

		this->cbUsuarios->SelectedIndex = -1;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando usuarios: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
