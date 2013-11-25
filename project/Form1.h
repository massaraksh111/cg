#pragma once

#include <algorithm>
#include "Filler.h"
#include "classes.h"
#include "RotationControll.h"

namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		Brush^ brush; // кисть для рисования точек
		Pen^ linePen; // для рисования линий
		Pen^ circlePen; // для рисования кругов
		Color lineColor; // цвет линий
		Color circleColor; // цвет кругов

		Filler^ filler;

		Figure^ figure;
		Figure^ figure1;
		Figure^ figure2;

		RotationControll^ controll;

		System::Windows::Forms::Button^  button4;
		System::Windows::Forms::Button^  button5;
		System::Windows::Forms::GroupBox^  groupBox1;
		System::Windows::Forms::Button^  button2;
		System::Windows::Forms::Button^  button3;
		System::Windows::Forms::PictureBox^  pictureBox1;
		System::Windows::Forms::GroupBox^  groupBox3;
		System::Windows::Forms::GroupBox^  groupBox4;
		System::Windows::Forms::GroupBox^  groupBox2;
		System::Windows::Forms::ComboBox^  comboBox1;
		System::Windows::Forms::Button^  rotateWindow;
		System::Windows::Forms::Button^  button6;
		System::Windows::Forms::Button^  button1;

	public:
		Form1(void)
		{
			InitializeComponent();

			lineColor = Color::DeepSkyBlue;
			circleColor = Color::DarkGreen;

			linePen = gcnew Pen(lineColor);
			circlePen = gcnew Pen(circleColor);

			brush = gcnew SolidBrush(lineColor);

			fillFigure1();
			fillFigure2();

			comboBox1->SelectedIndex = 0;
			figure = figure1;

			comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboClicked);			
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

		// seminar 3

		Drawing::Graphics^ canvas();
		void clearCanvas(); // очищает холст
		void drawLine(int x1, int y1, int x2, int y2); // рисует линию
		void drawPoint(int x, int y); // рисует точку
		void drawLines(); // рисует много линий
		void drawCircle(int R, int shiftX, int shiftY); // рисует круг
		void fill1(); // заполняет прямоугольник кроме круга в нём

		void linesClicked(System::Object^, System::EventArgs^);
		void clearAll(System::Object^, System::EventArgs^);
		void circleClicked(System::Object^, System::EventArgs^);
		void Fill1(System::Object^, System::EventArgs^);
		void Fill2(System::Object^, System::EventArgs^);
		// --------------

		// seminar 4

		void createRorationWindow();
		void fillFigure1();
		void fillFigure2();
		void rotateAround(Vector4^ point, Vector4^ vector, Vector4^);
		void rotate(Proections pr, int val);
		void rotatePar(Vector4^, double);
		void drawFigure(System::Object^, System::EventArgs^);
		void comboClicked(System::Object^, System::EventArgs^);
		void RotationControll_Closing(Object^, System::Windows::Forms::FormClosingEventArgs^);
		void rotateWindow_Click(System::Object^, System::EventArgs^);
		// ------------

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->rotateWindow = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Отрезки";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::linesClicked);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->Location = System::Drawing::Point(371, 483);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Очистить окно";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::clearAll);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 48);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(88, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Окружности";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::circleClicked);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(575, 385);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(6, 19);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(88, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Самописная";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::Fill1);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(7, 48);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(87, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Библиотечная";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::Fill2);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Location = System::Drawing::Point(112, 20);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(100, 79);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Закраска";
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->Controls->Add(this->groupBox1);
			this->groupBox3->Location = System::Drawing::Point(12, 403);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(221, 103);
			this->groupBox3->TabIndex = 9;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Семинар 3";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button3);
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Location = System::Drawing::Point(6, 19);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(100, 80);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Фигуры";
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->groupBox2->Controls->Add(this->button6);
			this->groupBox2->Controls->Add(this->rotateWindow);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Location = System::Drawing::Point(239, 403);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(126, 103);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Семинар 4";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(6, 47);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(111, 23);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Показать";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::drawFigure);
			// 
			// rotateWindow
			// 
			this->rotateWindow->Location = System::Drawing::Point(6, 74);
			this->rotateWindow->Name = L"rotateWindow";
			this->rotateWindow->Size = System::Drawing::Size(111, 23);
			this->rotateWindow->TabIndex = 11;
			this->rotateWindow->Text = L"Повернуть...";
			this->rotateWindow->UseVisualStyleBackColor = true;
			this->rotateWindow->Click += gcnew System::EventHandler(this, &Form1::rotateWindow_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Фигура 1", L"Фигура 2"});
			this->comboBox1->Location = System::Drawing::Point(6, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(111, 21);
			this->comboBox1->TabIndex = 13;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 518);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Компьютерная графика";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

