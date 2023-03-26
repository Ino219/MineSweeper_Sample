#include "pch.h"
#include "MyForm.h"

using namespace MineSweeperSample;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<System::String ^> ^args)
{
	Application::Run(gcnew MyForm());
    return 0;
}
