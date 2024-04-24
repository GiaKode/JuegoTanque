#pragma once
#include"Controlador.h"

namespace PC2SinErrores {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		//Inicializacion de clase:
		Controlador* controladora;


		//Buffer:
		Graphics^ g;
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ space;

		//Bitmap:
		Bitmap^ bmpTanque;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpMapa;
	private: System::Windows::Forms::Label^ label1;
		   Bitmap^ bmpBala;

	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//Buffer:
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap:
			bmpTanque = gcnew Bitmap("tanque.png");
			bmpEnemigo = gcnew Bitmap("enemigo.png");
			bmpMapa = gcnew Bitmap("mapa.png");
			bmpBala = gcnew Bitmap("bala.png");

			//Clases:
			controladora = new Controlador(bmpTanque, bmpEnemigo,bmpBala);
			Tanque* tanque;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(1, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1090, 683);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(695, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Mountros matados: ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1089, 679);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		buffer->Graphics->Clear(Color::WhiteSmoke);

		controladora->moverTODO(buffer->Graphics);

		controladora->collisiones(buffer->Graphics);

		buffer->Graphics->DrawImage(bmpMapa, 0, 0, panel1->Width, panel1->Height);
		controladora->dibujarTODO(buffer->Graphics, bmpTanque, bmpEnemigo,bmpBala);
		label1->Text = "Mounstros muertos: " + controladora->getContador();

		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			controladora->getTanque()->movimientos(buffer->Graphics, 'A'); break;
		case Keys::D:
			controladora->getTanque()->movimientos(buffer->Graphics, 'D'); break;
		case Keys::W:
			controladora->getTanque()->movimientos(buffer->Graphics, 'W'); break;
		case Keys::S:
			controladora->getTanque()->movimientos(buffer->Graphics, 'S'); break;
		case Keys::M:
			controladora->crearEnemigo(bmpEnemigo); break;
		case Keys::Space:
			this->timer1->Enabled = false;
			MessageBox::Show("Mounstros matados: " + controladora->getContador() ); break;
		case Keys::J:
			controladora->agregarBalas(bmpBala); 
			break;
			
			

		}
	}
};
}
