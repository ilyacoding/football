//---------------------------------------------------------------------------

#ifndef UnitAuthH
#define UnitAuthH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFormAuth : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonLogin;
	TButton *ButtonRegister;
	TEdit *EditUsername;
	TLabel *LabelUsername;
	TLabel *Label1;
	void __fastcall ButtonLoginClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonRegisterClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAuth(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAuth *FormAuth;
//---------------------------------------------------------------------------
#endif
