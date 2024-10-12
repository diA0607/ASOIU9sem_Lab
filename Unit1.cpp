
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   Form2->ShowModal();
   ADOTable1->Requery();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::�����Click(TObject *Sender)
{
    Close(); // ��������� �����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   if(!ADOTable1->IsEmpty())
	{
		if(MessageDlg("�� ����� ������ ������� ��� ������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			ADOTable1->Delete();
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (ADOTable1->RecordCount > 0 && ADOTable1->Active)
		{

			Form4->SetData(ADOTable1); // �������� ������� ������� � Form3
            Form4->ShowModal();
			 // ��������� ������ � ������� ����� ��������������
			ADOTable1->Refresh();
		}
		else
		{
			ShowMessage("��� ������� ��� ��������������.");
		}
}
//---------------------------------------------------------------------------

