#pragma once

#include "classes.h"

namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public delegate void RotateDelegate(Proections, int);
	public delegate void RotateAroundDelegate(Vector4^, Vector4^, Vector4^);
	public delegate void RotateAroundParDelegate(Vector4^, double);

	public ref class RotationControll : public System::Windows::Forms::Form
	{
	public:
		RotationControll(void)
		{
			InitializeComponent();
		}

		event RotateDelegate^ Rotate;
		event RotateAroundDelegate^ RotateAround;
		event RotateAroundParDelegate^ RotateAroundPar;

		void setBars(Vector4^ trackPositions)
		{
			trackOX->Value = trackPositions[0];
			trackOY->Value = trackPositions[1];
			trackOZ->Value = trackPositions[2];
		}

	protected:
		~RotationControll()
		{
			if (components)
			{
				delete components;
			}
		}

		System::Windows::Forms::GroupBox^  groupBox7;
		System::Windows::Forms::GroupBox^  groupBox6;
		System::Windows::Forms::NumericUpDown^  pointZ;
		System::Windows::Forms::NumericUpDown^  pointY;
		System::Windows::Forms::NumericUpDown^  pointX;
		System::Windows::Forms::Button^  rotateAroundButton;
		System::Windows::Forms::GroupBox^  groupBox5;
		System::Windows::Forms::TrackBar^  trackOX;
		System::Windows::Forms::TrackBar^  trackOZ;
		System::Windows::Forms::TrackBar^  trackOY;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::NumericUpDown^  vectorZ;
		System::Windows::Forms::NumericUpDown^  vectorY;
		System::Windows::Forms::NumericUpDown^  vectorX;
		System::Windows::Forms::Label^  label5;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::NumericUpDown^  angleY;
		System::Windows::Forms::NumericUpDown^  angleZ;
		System::Windows::Forms::NumericUpDown^  angleX;
		System::Windows::Forms::Label^  label6;
		System::Windows::Forms::GroupBox^  groupBox1;
		System::Windows::Forms::Button^  rotateAroundParButton;

		System::Windows::Forms::NumericUpDown^  anglePar;
		System::Windows::Forms::Label^  label7;
		System::Windows::Forms::Label^  label8;
		System::Windows::Forms::NumericUpDown^  pointParX;
		System::Windows::Forms::NumericUpDown^  pointParZ;
		System::Windows::Forms::NumericUpDown^  pointParY;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->angleY = (gcnew System::Windows::Forms::NumericUpDown());
			this->angleZ = (gcnew System::Windows::Forms::NumericUpDown());
			this->angleX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->rotateAroundButton = (gcnew System::Windows::Forms::Button());
			this->vectorY = (gcnew System::Windows::Forms::NumericUpDown());
			this->vectorZ = (gcnew System::Windows::Forms::NumericUpDown());
			this->vectorX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pointZ = (gcnew System::Windows::Forms::NumericUpDown());
			this->pointY = (gcnew System::Windows::Forms::NumericUpDown());
			this->pointX = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->trackOX = (gcnew System::Windows::Forms::TrackBar());
			this->trackOZ = (gcnew System::Windows::Forms::TrackBar());
			this->trackOY = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pointParZ = (gcnew System::Windows::Forms::NumericUpDown());
			this->pointParY = (gcnew System::Windows::Forms::NumericUpDown());
			this->pointParX = (gcnew System::Windows::Forms::NumericUpDown());
			this->anglePar = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->rotateAroundParButton = (gcnew System::Windows::Forms::Button());
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->angleY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->angleZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->angleX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vectorY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vectorZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vectorX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointX))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackOX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackOZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackOY))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointParZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointParY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointParX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->anglePar))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->groupBox1);
			this->groupBox7->Controls->Add(this->groupBox6);
			this->groupBox7->Controls->Add(this->groupBox5);
			this->groupBox7->Controls->Add(this->label3);
			this->groupBox7->Controls->Add(this->label1);
			this->groupBox7->Controls->Add(this->label2);
			this->groupBox7->Location = System::Drawing::Point(12, 12);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(691, 201);
			this->groupBox7->TabIndex = 17;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Поворот";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->angleY);
			this->groupBox6->Controls->Add(this->angleZ);
			this->groupBox6->Controls->Add(this->angleX);
			this->groupBox6->Controls->Add(this->label6);
			this->groupBox6->Controls->Add(this->label5);
			this->groupBox6->Controls->Add(this->rotateAroundButton);
			this->groupBox6->Controls->Add(this->vectorY);
			this->groupBox6->Controls->Add(this->vectorZ);
			this->groupBox6->Controls->Add(this->vectorX);
			this->groupBox6->Controls->Add(this->label4);
			this->groupBox6->Controls->Add(this->pointZ);
			this->groupBox6->Controls->Add(this->pointY);
			this->groupBox6->Controls->Add(this->pointX);
			this->groupBox6->Location = System::Drawing::Point(169, 19);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(306, 176);
			this->groupBox6->TabIndex = 15;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Локальная система координат";
			// 
			// angleY
			// 
			this->angleY->Location = System::Drawing::Point(209, 81);
			this->angleY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->angleY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, System::Int32::MinValue});
			this->angleY->Name = L"angleY";
			this->angleY->Size = System::Drawing::Size(86, 20);
			this->angleY->TabIndex = 21;
			// 
			// angleZ
			// 
			this->angleZ->Location = System::Drawing::Point(209, 120);
			this->angleZ->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->angleZ->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, System::Int32::MinValue});
			this->angleZ->Name = L"angleZ";
			this->angleZ->Size = System::Drawing::Size(86, 20);
			this->angleZ->TabIndex = 20;
			// 
			// angleX
			// 
			this->angleX->Location = System::Drawing::Point(209, 35);
			this->angleX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->angleX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, System::Int32::MinValue});
			this->angleX->Name = L"angleX";
			this->angleX->Size = System::Drawing::Size(86, 20);
			this->angleX->TabIndex = 22;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(206, 16);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Угол(градусы)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Точка";
			// 
			// rotateAroundButton
			// 
			this->rotateAroundButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->rotateAroundButton->Location = System::Drawing::Point(209, 142);
			this->rotateAroundButton->Name = L"rotateAroundButton";
			this->rotateAroundButton->Size = System::Drawing::Size(86, 24);
			this->rotateAroundButton->TabIndex = 1;
			this->rotateAroundButton->Text = L"Применить";
			this->rotateAroundButton->UseVisualStyleBackColor = true;
			this->rotateAroundButton->Click += gcnew System::EventHandler(this, &RotationControll::rotateAroundButton_Click);
			// 
			// vectorY
			// 
			this->vectorY->Location = System::Drawing::Point(109, 81);
			this->vectorY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->vectorY->Name = L"vectorY";
			this->vectorY->Size = System::Drawing::Size(86, 20);
			this->vectorY->TabIndex = 16;
			// 
			// vectorZ
			// 
			this->vectorZ->Location = System::Drawing::Point(109, 120);
			this->vectorZ->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->vectorZ->Name = L"vectorZ";
			this->vectorZ->Size = System::Drawing::Size(86, 20);
			this->vectorZ->TabIndex = 15;
			// 
			// vectorX
			// 
			this->vectorX->Location = System::Drawing::Point(109, 35);
			this->vectorX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->vectorX->Name = L"vectorX";
			this->vectorX->Size = System::Drawing::Size(86, 20);
			this->vectorX->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(106, 16);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Вектор";
			// 
			// pointZ
			// 
			this->pointZ->Location = System::Drawing::Point(6, 121);
			this->pointZ->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->pointZ->Name = L"pointZ";
			this->pointZ->Size = System::Drawing::Size(86, 20);
			this->pointZ->TabIndex = 14;
			// 
			// pointY
			// 
			this->pointY->Location = System::Drawing::Point(6, 81);
			this->pointY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->pointY->Name = L"pointY";
			this->pointY->Size = System::Drawing::Size(86, 20);
			this->pointY->TabIndex = 14;
			// 
			// pointX
			// 
			this->pointX->Location = System::Drawing::Point(6, 35);
			this->pointX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->pointX->Name = L"pointX";
			this->pointX->Size = System::Drawing::Size(86, 20);
			this->pointX->TabIndex = 14;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->trackOX);
			this->groupBox5->Controls->Add(this->trackOZ);
			this->groupBox5->Controls->Add(this->trackOY);
			this->groupBox5->Location = System::Drawing::Point(37, 19);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(126, 176);
			this->groupBox5->TabIndex = 10;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"По осям";
			// 
			// trackOX
			// 
			this->trackOX->LargeChange = 1;
			this->trackOX->Location = System::Drawing::Point(6, 19);
			this->trackOX->Maximum = 18;
			this->trackOX->Name = L"trackOX";
			this->trackOX->Size = System::Drawing::Size(114, 45);
			this->trackOX->TabIndex = 8;
			this->trackOX->Scroll += gcnew System::EventHandler(this, &RotationControll::trackOX_Scroll);
			// 
			// trackOZ
			// 
			this->trackOZ->LargeChange = 1;
			this->trackOZ->Location = System::Drawing::Point(6, 121);
			this->trackOZ->Maximum = 18;
			this->trackOZ->Name = L"trackOZ";
			this->trackOZ->Size = System::Drawing::Size(114, 45);
			this->trackOZ->TabIndex = 11;
			this->trackOZ->Scroll += gcnew System::EventHandler(this, &RotationControll::trackOZ_Scroll);
			// 
			// trackOY
			// 
			this->trackOY->LargeChange = 1;
			this->trackOY->Location = System::Drawing::Point(6, 70);
			this->trackOY->Maximum = 18;
			this->trackOY->Name = L"trackOY";
			this->trackOY->Size = System::Drawing::Size(114, 45);
			this->trackOY->TabIndex = 9;
			this->trackOY->Scroll += gcnew System::EventHandler(this, &RotationControll::trackOY_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(22, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"OZ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"OX";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"OY";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rotateAroundParButton);
			this->groupBox1->Controls->Add(this->anglePar);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->pointParX);
			this->groupBox1->Controls->Add(this->pointParZ);
			this->groupBox1->Controls->Add(this->pointParY);
			this->groupBox1->Location = System::Drawing::Point(481, 20);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 174);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параллельно оси";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 18);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Точка";
			// 
			// pointParZ
			// 
			this->pointParZ->Location = System::Drawing::Point(6, 120);
			this->pointParZ->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->pointParZ->Name = L"pointParZ";
			this->pointParZ->Size = System::Drawing::Size(86, 20);
			this->pointParZ->TabIndex = 23;
			// 
			// pointParY
			// 
			this->pointParY->Location = System::Drawing::Point(6, 80);
			this->pointParY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->pointParY->Name = L"pointParY";
			this->pointParY->Size = System::Drawing::Size(86, 20);
			this->pointParY->TabIndex = 24;
			// 
			// pointParX
			// 
			this->pointParX->Location = System::Drawing::Point(6, 34);
			this->pointParX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->pointParX->Name = L"pointParX";
			this->pointParX->Size = System::Drawing::Size(86, 20);
			this->pointParX->TabIndex = 25;
			// 
			// anglePar
			// 
			this->anglePar->Location = System::Drawing::Point(105, 34);
			this->anglePar->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->anglePar->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, System::Int32::MinValue});
			this->anglePar->Name = L"anglePar";
			this->anglePar->Size = System::Drawing::Size(86, 20);
			this->anglePar->TabIndex = 24;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(102, 15);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(80, 13);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Угол(градусы)";
			// 
			// rotateAroundParButton
			// 
			this->rotateAroundParButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->rotateAroundParButton->Location = System::Drawing::Point(105, 141);
			this->rotateAroundParButton->Name = L"rotateAroundParButton";
			this->rotateAroundParButton->Size = System::Drawing::Size(86, 24);
			this->rotateAroundParButton->TabIndex = 23;
			this->rotateAroundParButton->Text = L"Применить";
			this->rotateAroundParButton->UseVisualStyleBackColor = true;
			this->rotateAroundParButton->Click += gcnew System::EventHandler(this, &RotationControll::rotateAroundParButton_Click);
			// 
			// RotationControll
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 218);
			this->Controls->Add(this->groupBox7);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"RotationControll";
			this->Text = L"Поворот";
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->angleY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->angleZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->angleX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vectorY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vectorZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vectorX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointX))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackOX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackOZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackOY))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointParZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointParY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pointParX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->anglePar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		void trackOX_Scroll(System::Object^, System::EventArgs^)
		{
			Rotate(X_PR, trackOX->Value);
		}

		void trackOY_Scroll(System::Object^, System::EventArgs^)
		{
			Rotate(Y_PR, trackOY->Value);
		}

		void trackOZ_Scroll(System::Object^, System::EventArgs^)
		{
			Rotate(Z_PR, trackOZ->Value);
		}

		void rotateAroundButton_Click(System::Object^, System::EventArgs^)
		{
			RotateAround(gcnew Vector4(Decimal::ToDouble (pointX->Value),
				Decimal::ToDouble (pointY->Value),
				Decimal::ToDouble (pointZ->Value)),
				gcnew Vector4(Decimal::ToDouble (vectorX->Value),
				Decimal::ToDouble (vectorY->Value),
				Decimal::ToDouble (vectorZ->Value)),
				gcnew Vector4(Decimal::ToDouble (angleX->Value),
				Decimal::ToDouble (angleY->Value),
				Decimal::ToDouble (angleZ->Value))
				);
		}

		void rotateAroundParButton_Click(System::Object^, System::EventArgs^)
		{
			RotateAroundPar(gcnew Vector4(Decimal::ToDouble (pointParX->Value),
				Decimal::ToDouble (pointParY->Value),
				Decimal::ToDouble (pointParZ->Value)),
				Decimal::ToDouble (anglePar->Value));
		}
	};
}
