#pragma once

namespace MineSweeperSample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//

			//最初の処理用のフラグ
			first = true;
			//フィールドの初期化
			mathList = gcnew List<math^>;
			//マスの一辺の長さ
			mathLength = 10;
			//ボムの数指定
			bombNum = 10;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  Field_DGV;
	private: System::Windows::Forms::Button^  reset;
	private: System::Windows::Forms::Button^  CheckButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  mathNum;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  bomb;

	private: System::Windows::Forms::Button^  SetButton;
	protected:

	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->Field_DGV = (gcnew System::Windows::Forms::DataGridView());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->CheckButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mathNum = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bomb = (gcnew System::Windows::Forms::TextBox());
			this->SetButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field_DGV))->BeginInit();
			this->SuspendLayout();
			// 
			// Field_DGV
			// 
			this->Field_DGV->AllowUserToResizeColumns = false;
			this->Field_DGV->AllowUserToResizeRows = false;
			this->Field_DGV->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->Field_DGV->ColumnHeadersVisible = false;
			this->Field_DGV->Location = System::Drawing::Point(13, 12);
			this->Field_DGV->Name = L"Field_DGV";
			this->Field_DGV->RowHeadersVisible = false;
			this->Field_DGV->RowTemplate->Height = 21;
			this->Field_DGV->Size = System::Drawing::Size(240, 240);
			this->Field_DGV->TabIndex = 0;
			this->Field_DGV->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::Field_DGV_CellMouseClick);
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(283, 12);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(75, 23);
			this->reset->TabIndex = 1;
			this->reset->Text = L"Reset";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &MyForm::reset_Click);
			// 
			// CheckButton
			// 
			this->CheckButton->Location = System::Drawing::Point(283, 41);
			this->CheckButton->Name = L"CheckButton";
			this->CheckButton->Size = System::Drawing::Size(75, 23);
			this->CheckButton->TabIndex = 2;
			this->CheckButton->Text = L"Check";
			this->CheckButton->UseVisualStyleBackColor = true;
			this->CheckButton->Click += gcnew System::EventHandler(this, &MyForm::CheckButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(283, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"マス数(一辺)";
			// 
			// mathNum
			// 
			this->mathNum->Location = System::Drawing::Point(283, 102);
			this->mathNum->Name = L"mathNum";
			this->mathNum->Size = System::Drawing::Size(75, 19);
			this->mathNum->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(283, 142);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 12);
			this->label2->TabIndex = 5;
			this->label2->Text = L"ボム数";
			// 
			// bomb
			// 
			this->bomb->Location = System::Drawing::Point(283, 158);
			this->bomb->Name = L"bomb";
			this->bomb->Size = System::Drawing::Size(75, 19);
			this->bomb->TabIndex = 6;
			// 
			// SetButton
			// 
			this->SetButton->Location = System::Drawing::Point(283, 198);
			this->SetButton->Name = L"SetButton";
			this->SetButton->Size = System::Drawing::Size(75, 23);
			this->SetButton->TabIndex = 7;
			this->SetButton->Text = L"Set";
			this->SetButton->UseVisualStyleBackColor = true;
			this->SetButton->Click += gcnew System::EventHandler(this, &MyForm::SetButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 310);
			this->Controls->Add(this->SetButton);
			this->Controls->Add(this->bomb);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->mathNum);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CheckButton);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->Field_DGV);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field_DGV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		ref struct math {
			int x;
			int y;
			bool bomb;
			bool mark;
			bool check;
		};
		bool first;
		int mathLength;
		List<math^>^ mathList;
		int columnsNum;
		int rowsNum;
		int bombNum;
		
		
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);

	private: System::Void FirstSweep(int x,int y);
	private: System::Void StandardSweep(int x, int y);
	private: System::Void BombSet(int column,int row);
	private: int JudgeAround(int x,int y);
	private: bool JudgeBomb(int x,int y);
	private: bool JudgeMark(int x, int y);
	private: bool JudgeCheck(int x, int y);
	private: System::Void mathNumSet(int num);
	private: System::Void SetMark(int x, int y);
	private: System::Void SetBomb(int x, int y);
	private: System::Void SetCheck(int x, int y,bool InOut);

	private: System::Void AllUpdateBombNum();
	private: System::Void reset_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Field_DGV_CellMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e);
	private: System::Void CheckButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void mathList_init();
	private: System::Void SetButton_Click(System::Object^  sender, System::EventArgs^  e);
};
}
