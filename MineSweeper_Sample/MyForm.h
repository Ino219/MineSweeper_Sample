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
	/// MyForm �̊T�v
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//

			//�ŏ��̏����p�̃t���O
			first = true;
			//�t�B�[���h�̏�����
			mathList = gcnew List<math^>;
			//�}�X�̈�ӂ̒���
			mathLength = 10;
			//�{���̐��w��
			bombNum = 10;
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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
	protected:

	protected:

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->Field_DGV = (gcnew System::Windows::Forms::DataGridView());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->CheckButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field_DGV))->BeginInit();
			this->SuspendLayout();
			// 
			// Field_DGV
			// 
			this->Field_DGV->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->Field_DGV->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->Field_DGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Field_DGV->ColumnHeadersVisible = false;
			this->Field_DGV->Location = System::Drawing::Point(13, 13);
			this->Field_DGV->Name = L"Field_DGV";
			this->Field_DGV->RowHeadersVisible = false;
			this->Field_DGV->RowTemplate->Height = 21;
			this->Field_DGV->Size = System::Drawing::Size(240, 192);
			this->Field_DGV->TabIndex = 0;
			this->Field_DGV->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::Field_DGV_CellMouseClick);
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(13, 226);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(75, 23);
			this->reset->TabIndex = 1;
			this->reset->Text = L"Reset";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &MyForm::reset_Click);
			// 
			// CheckButton
			// 
			this->CheckButton->Location = System::Drawing::Point(167, 226);
			this->CheckButton->Name = L"CheckButton";
			this->CheckButton->Size = System::Drawing::Size(75, 23);
			this->CheckButton->TabIndex = 2;
			this->CheckButton->Text = L"Check";
			this->CheckButton->UseVisualStyleBackColor = true;
			this->CheckButton->Click += gcnew System::EventHandler(this, &MyForm::CheckButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->CheckButton);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->Field_DGV);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field_DGV))->EndInit();
			this->ResumeLayout(false);

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
};
}
