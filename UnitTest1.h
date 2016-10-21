//---------------------------------------------------------------------------

#ifndef UnitTest1H
#define UnitTest1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "../src/ais_hotel.h"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmTestAISHotel : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo1;
    TToolBar *ToolBar1;
    TButton *btnGetStatus;
    TToolButton *ToolButton1;
    TEdit *eID;
    TUpDown *ID;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TButton *btnTimeGet;
    TButton *btnTimeSet;
    TToolBar *ToolBar3;
    TButton *btnPortOpen;
    TButton *btnPortClose;
    TEdit *eCardID;
    TButton *btnCardBlock;
    TToolButton *ToolButton5;
    TButton *btnCardUnblock;
    TUpDown *cardID;
    TToolButton *ToolButton4;
    TButton *btnCardUnblockAll;
    TToolButton *ToolButton6;
    TButton *btnGetOneLog;
    void __fastcall btnPortOpenClick(TObject *Sender);
    void __fastcall btnPortCloseClick(TObject *Sender);
    void __fastcall btnGetStatusClick(TObject *Sender);
    void __fastcall btnTimeGetClick(TObject *Sender);
    void __fastcall btnTimeSetClick(TObject *Sender);
    void __fastcall btnCardBlockClick(TObject *Sender);
    void __fastcall btnCardUnblockClick(TObject *Sender);
    void __fastcall btnCardUnblockAllClick(TObject *Sender);
    void __fastcall btnGetOneLogClick(TObject *Sender);
private:	// User declarations
    DL_STATUS status;
    AnsiString asout, as;

public:		// User declarations
    __fastcall TfrmTestAISHotel(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTestAISHotel *frmTestAISHotel;
//---------------------------------------------------------------------------
#endif
