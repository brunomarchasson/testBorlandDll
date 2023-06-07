//---------------------------------------------------------------------------

#ifndef TestDllMainH
#define TestDllMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TButton *InitButton;
	TButton *HiButton;
	TEdit *Edit1;
	void __fastcall LoadButtonClick(TObject *Sender);
	void __fastcall InitButtonClick(TObject *Sender);

	void __fastcall HiButtonClick(TObject *Sender);
private:	// D�clarations utilisateur
void __fastcall EnableButtons();
public:		// D�clarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
