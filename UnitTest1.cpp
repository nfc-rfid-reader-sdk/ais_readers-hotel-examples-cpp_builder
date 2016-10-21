//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <time.h>
#include "UnitTest1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTestAISHotel *frmTestAISHotel;
//---------------------------------------------------------------------------
__fastcall TfrmTestAISHotel::TfrmTestAISHotel(TComponent* Owner)
    : TForm(Owner)
{
    btnPortOpenClick(this);
}
//---------------------------------------------------------------------------

char * wr_status(const char * chPreText, DL_STATUS dl_status)
{
	static char out_str[512] = "STATUS:>> ";

	if (chPreText)
	{
		strcpy(out_str, chPreText);
		strcat(out_str, ": ");
	}

	strcat(out_str, dbg_status2str(dl_status));

    frmTestAISHotel->Memo1->Lines->Add(out_str);


    return out_str;
}

void __fastcall TfrmTestAISHotel::btnPortOpenClick(TObject *Sender)
{
	status = AIS_Hotel_CommunicationOpen();
	wr_status("AIS_Hotel_CommunicationOpen()", status);    
}
//---------------------------------------------------------------------------
void __fastcall TfrmTestAISHotel::btnPortCloseClick(TObject *Sender)
{
	status = AIS_Hotel_CommunicationClose();
	wr_status("AIS_Hotel_CommunicationClose()", status);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestAISHotel::btnGetStatusClick(TObject *Sender)
{
   	unsigned char response[5] = "";
    int i;
    int is_power_on;
    int unreaded_rte;
    
	status = AIS_Hotel_GetStatus(ID->Position, &is_power_on,
        &unreaded_rte, response);
	wr_status("AIS_Hotel_GetStatus()", status);

    if (status)
        return;

    asout.printf("RESPONSE: POWER= %i | unreaded RTE= %i || ",
        is_power_on, unreaded_rte);

    for (i = 0; i < 5; i++)
    {
        as.printf("%02X:", response[i]);
        asout += as;
    }

    Memo1->Lines->Add(asout);
    
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestAISHotel::btnTimeGetClick(TObject *Sender)
{
    struct tm dt;

	status = AIS_Hotel_TimeGet(ID->Position, &dt.tm_year, &dt.tm_mon, &dt.tm_mday,
        &dt.tm_hour, &dt.tm_min, &dt.tm_sec);
	wr_status("AIS_Hotel_TimeGet()", status);

    if (status)
        return;

    dt.tm_year -= 1900;
    dt.tm_mon  -= 1;
    dt.tm_isdst = -1;

    if (mktime(&dt) == -1)
    {
        as = "Greska kod konverzije vremena";
    }
    else
    {
        as = asctime(&dt);
    }

    Memo1->Lines->Add(as);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestAISHotel::btnTimeSetClick(TObject *Sender)
{
    time_t time_now = time(NULL);
    struct tm *dt = localtime(&time_now);
    char password[] = "";

	status = AIS_Hotel_TimeSet(ID->Position, password, dt->tm_year + 1900, dt->tm_mon + 1, dt->tm_mday,
        dt->tm_hour, dt->tm_min, dt->tm_sec);
	wr_status("AIS_Hotel_TimeSet()", status);    
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestAISHotel::btnCardBlockClick(TObject *Sender)
{
    char password[] = "";
    status = AIS_Hotel_CardBlock(ID->Position, password, cardID->Position);
    as.printf("AIS_Hotel_CardBlock(%i, pass=\"%s\", card= %d)", ID->Position, password, cardID->Position);
    wr_status(as.c_str(), status);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestAISHotel::btnCardUnblockClick(TObject *Sender)
{
    char password[] = "";
    status = AIS_Hotel_CardUnblock(ID->Position, password, cardID->Position);
    as.printf("AIS_Hotel_CardUnblock(%i, pass=\"%s\", card= %d)", ID->Position, password, cardID->Position);
    wr_status(as.c_str(), status);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestAISHotel::btnCardUnblockAllClick(TObject *Sender)
{
    char password[] = "";
    status = AIS_Hotel_CardUnblockAll(ID->Position, password);
    as.printf("AIS_Hotel_CardUnblockAll(%i, pass=\"%s\")", ID->Position, password);
    wr_status(as.c_str(), status);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestAISHotel::btnGetOneLogClick(TObject *Sender)
{
	int new_log;
	int action;
	int card_id;
	int system_id;
	struct tm dt;

	status = AIS_Hotel_GetLastRTE(ID->Position, &new_log,
            &action, &card_id, &system_id,
			&dt.tm_year, &dt.tm_mon, &dt.tm_mday,
            &dt.tm_hour, &dt.tm_min, &dt.tm_sec);

	as.printf("AIS_Hotel_GetLastRTE(%i)", ID->Position);
	wr_status(as.c_str(), status);

	if (status)
		return;

	if (new_log)
	{
		as.printf("action= %s | card_id= %5d | system_id= %2d"
                   " | TIME= ",
				dbg_action2str(action), card_id, system_id);

		dt.tm_year -= 1900;
		dt.tm_mon -= 1;
		dt.tm_isdst = -1;
		if (mktime(&dt) == -1)
		{
			as += "Greska kod konverzije vremena";
		}
		else
		{
			as += asctime(&dt);
		}
	}
	else
	{
		as = "NO NEW RTE";
	}

	Memo1->Lines->Add(as);
}
//---------------------------------------------------------------------------

