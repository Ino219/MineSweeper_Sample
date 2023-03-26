#include "pch.h"
#include "MyForm.h"

using namespace System::Collections::Generic;
using namespace System::Drawing;

System::Void MineSweeperSample::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	//最初の処理用のフラグ
	first = true;
	//フィールドの設定
	mathList = gcnew List<math^>;

	//行数と列数
	mathNumSet(10);

	for (int i = 0; i < columnsNum; i++) {
		DataGridViewButtonColumn^ buttons = gcnew DataGridViewButtonColumn();
		Field_DGV->Columns->Add(buttons);
		math^ temp = gcnew math();
		temp->x = i;
		temp->y = 0;
		mathList->Add(temp);
	}
	for (int j = 1; j < rowsNum; j++) {
		Field_DGV->Rows->Add();
		for (int j2 = 0; j2 < columnsNum; j2++) {
			math^ temp = gcnew math();
			temp->x = j2;
			temp->y = j;
			mathList->Add(temp);
		}
	}
}


System::Void MineSweeperSample::MyForm::FirstSweep(int x, int y)
{
	//どの範囲までスイープするかを決定
	Random^ Range = gcnew Random();
	//始点座標
	int Xrange = Range->Next(1, columnsNum / 2);
	int Yrange = Range->Next(1, rowsNum / 2);
	//終点座標
	int Xrange_ = Range->Next(1, columnsNum / 2);
	int Yrange_ = Range->Next(1, rowsNum / 2);

	for (int i = x - Xrange_; i < x + Xrange+1; i++) {
		//フィールド範囲外であれば、ループ脱出
		if (i < 0)continue;
		if (i >= columnsNum)continue;
		for (int j = y - Yrange_; j < y + Yrange+1; j++) {
			if (j < 0)continue;
			if (j > rowsNum)continue;

			Field_DGV[i, j]->ReadOnly = true;
			Field_DGV[i, j]->Style->BackColor = Color::Gray;
			SetMark(i, j);
		}
	}
	//ボムをセット
	BombSet(columnsNum,rowsNum);
	//マス表示を更新
	AllUpdateBombNum();

	return System::Void();
}

System::Void MineSweeperSample::MyForm::StandardSweep(int x, int y)
{
	bool continueFlag = false;
	//while (continueFlag == false) {
		if (JudgeBomb(x, y)) {
			//クリックしたセルがボムであれば、ゲームオーバー
			Field_DGV[x, y]->Value = "●";
			MessageBox::Show("GameOver");
		}
		else {
			//ボム回避時の処理
			//周囲に一つ以上のボムがあれば、セル表示更新
			if (int temp = JudgeAround(x, y) > 0) {
				Field_DGV[x, y]->Value = temp;
			}
			else {
				//周囲に一つもボムがなければ、スイープ処理
				for (int i = x - 1; i < x + 1 + 1; i++) {
					if (i < 0)continue;
					if (i >= columnsNum)continue;
					for (int j = y - 1; j < y + 1 + 1; j++) {
						if (j < 0)continue;
						if (j >= rowsNum)continue;

						if (JudgeBomb(i, j)) {
							continueFlag = true;
							continue;
						}
						Field_DGV[i, j]->ReadOnly = true;
						Field_DGV[i, j]->Style->BackColor = Color::Gray;
						SetMark(i, j);
					}
				}
			}
		//}
	}
	AllUpdateBombNum();
	return System::Void();
}

System::Void MineSweeperSample::MyForm::BombSet(int column,int row)
{
	//ボムの設定
	//ボムの数
	int bombNum = 10;

	for (int n = 0; n < bombNum; n++) {
		//乱数を用いた座標の作成
		Random^ rnd = gcnew Random();
		int^ column_num = rnd->Next(0, column - 1);
		int^ row_num = rnd->Next(0, row - 1);

		if (JudgeBomb((int)column_num, (int)row_num)) {
			n -= 1;
			continue;
		}
		if (JudgeMark((int)column_num, (int)row_num)) {
			n -= 1;
			continue;
		}
		SetBomb((int)column_num, (int)row_num);
	}
	return System::Void();
}

int MineSweeperSample::MyForm::JudgeAround(int x, int y)
{
	//指定したマスの周囲のボム数を判定し、表示
	int around = 1;
	int count;

	for (int i = x - around; i < x + around + 1; i++) {
		if (i < 0)continue;
		if (i >= columnsNum)continue;
		for (int j = y - around; j < y + around + 1; j++) {
			if (j < 0)continue;
			if (i >= rowsNum)continue;
			for each (math^ var in mathList)
			{
				if ((var->x == i) && (var->y == j) && var->bomb == true) {
					count++;
					break;
				}
			}
		}
	}
	return count;
}

bool MineSweeperSample::MyForm::JudgeBomb(int x, int y)
{
	//指定したマスのボムの有無を判定
	for each (math^ var in mathList)
	{
		if ((var->x == x) && (var->y == y)) {
			return var->bomb;
		}
	}
	//見つからない場合はfalse
	return false;
}

bool MineSweeperSample::MyForm::JudgeMark(int x, int y)
{
	for each (math^ var in mathList)
	{
		if ((var->x == x) && (var->y == y)) {
			return var->mark;
		}
	}
	return false;
}

bool MineSweeperSample::MyForm::JudgeCheck(int x, int y)
{
	for each (math^ var in mathList)
	{
		if ((var->x == x) && (var->y == y)) {
			return var->check;
		}
	}
	return false;
}

System::Void MineSweeperSample::MyForm::mathNumSet(int num)
{
	//フィールドのマス数をセット
	columnsNum = num;
	rowsNum = num;
}

System::Void MineSweeperSample::MyForm::SetMark(int x, int y)
{
	//指定したマスがスイープされたかどうかのフラグをセットする
	for each (math^ var in mathList)
	{
		if ((var->x == x) && (var->y == y)) {
			var->mark = true;
		}
	}
	
}

System::Void MineSweeperSample::MyForm::SetBomb(int x, int y)
{
	for each (math^ var in mathList)
	{
		if ((var->x == x) && (var->y == y)) {
			var->bomb = true;
		}
	}
	return System::Void();
}

System::Void MineSweeperSample::MyForm::SetCheck(int x, int y,bool inout)
{
	for each (math^ var in mathList)
	{
		if ((var->x == x) && (var->y == y)) {
			var->check = inout;
		}
	}
	return System::Void();
}

System::Void MineSweeperSample::MyForm::AllUpdateBombNum()
{
	for each (math^ var in mathList)
	{
		if (var->mark == true) {
			Field_DGV[var->x, var->y]->Value = JudgeAround(var->x, var->y);
		}
	}
	return System::Void();
}

System::Void MineSweeperSample::MyForm::reset_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	
	MyForm^ myForm_New = gcnew MyForm();
	
	return System::Void();
}

System::Void MineSweeperSample::MyForm::Field_DGV_CellMouseClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs ^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		if (JudgeCheck(e->ColumnIndex, e->RowIndex)) {
			Field_DGV[e->ColumnIndex, e->RowIndex]->Value = "";
			SetCheck(e->ColumnIndex, e->RowIndex,false);
		}
		else {
			Field_DGV[e->ColumnIndex, e->RowIndex]->Value = "×";
			SetCheck(e->ColumnIndex, e->RowIndex, true);
		}
	}
	else {
		//押したマスを潰す
		Field_DGV[e->ColumnIndex, e->RowIndex]->ReadOnly = true;
		Field_DGV[e->ColumnIndex, e->RowIndex]->Style->BackColor = Color::Gray;
		SetMark(e->ColumnIndex, e->RowIndex);

		if (first == true) {
			//最初のスイープは絶対にボムに当たらない
			FirstSweep(e->ColumnIndex, e->RowIndex);
			first = false;
		}
		else {
			for each (math^ var in mathList)
			{
				if (JudgeBomb(e->ColumnIndex, e->RowIndex)) {
					Field_DGV[e->ColumnIndex, e->RowIndex]->Value = "●";
					MessageBox::Show("GameOver");
					break;
				}
				else {
					StandardSweep(e->ColumnIndex, e->RowIndex);
				}
			}
		}
	}
	return System::Void();
}

System::Void MineSweeperSample::MyForm::CheckButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool missFlag = false;
	for each (math^ var in mathList)
	{
		if (var->check==false&&var->mark==false) {
			missFlag = true;
			break;
		}
		if (var->check == true && var->bomb == false) {
			missFlag == true;
			break;
		}
	}
	if (missFlag) {
		MessageBox::Show("GAME OVER");
	}
	else {
		MessageBox::Show("GAME CLEAR");
	}

	return System::Void();
}





