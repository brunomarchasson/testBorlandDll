//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "TestDllMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

#pragma comment(lib, "CalDevLib")
#include "CalDevLib.h"

TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
//this->caldev = getCalDev(2,3);
}

// ---------------------------------------------------------------------------
// Method used to enable the buttons when the library is loaded
void __fastcall TForm1::EnableButtons() {
//		PushButton->Enabled = true;
//		PopButton->Enabled = true;
//		IsEmptyButton->Enabled = true;
//		TopButton->Enabled = true;
}

// ---------------------------------------------------------------------------
// OnClick event handler for LoadButton
void __fastcall TForm1::LoadButtonClick(TObject *Sender) {
		// Dynamically loads the library
//		HINSTANCE load = LoadLibrary(library);
//        if (load) {
//                ShowMessage("Library loaded!");
//				EnableButtons();
//
//                VoidReturnFunc myFunc;
//
//                // GetProcAddress returns a pointer to the loaded method
//                myFunc = (VoidReturnFunc)GetProcAddress(load, "GetClassInstance");
//
//                // Invoke GetClassInstance method
//				stack = (BaseStack*) myFunc();
//
//                // Note:
//                // The BaseStack methods are pure virtual methods, but myFunc() returns an instance of the Stack class.
//                // Wherever we call stack->methodName() later, we are actually calling Stack::methodName(), not
//                // BaseStack::methodName().
//        }
//        else {
//                ShowMessage("Library not loaded!");
//        }
}

// ---------------------------------------------------------------------------
// OnCLick event handler for PushButton
void __fastcall TForm1::InitButtonClick(TObject *Sender) {

init(Edit1->Text.c_str())   ;
}


// ---------------------------------------------------------------------------
// OnClick event handler for PopButton
void __fastcall TForm1::HiButtonClick(TObject *Sender) {
	 ShowMessage(hi());
}

// ---------------------------------------------------------------------------
