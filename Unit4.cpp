//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// ������� ��� ��������� ������ � ���� ����� �� ������ ��������� ������
void __fastcall TForm4::SetData(TADOTable *Table)
{
    // ������������� ������� �������
	 ADOTable1 = Table;  // ����� ������������� ��������� �� ������� �������
	 if (!ADOTable1->Active)
		{
			ADOTable1->Open();  // ���������, ��� ������� �������
	 }
	ADOTable1->Edit();
	// ��������� ���� ����� ���������� �� ������� ������ �������
	EditFIO->Text = Table->FieldByName("���")->AsString;
	EditPhone->Text = Table->FieldByName("�����_��������")->AsString;
	EditDate->Text = Table->FieldByName("����_��������")->AsString;
	EditPol->Text = Table->FieldByName("���")->AsString;
	EditLog->Text = Table->FieldByName("�����")->AsString;
	EditPassw->Text = Table->FieldByName("������")->AsString;
}
void __fastcall TForm4::Button1Click(TObject *Sender)
{
   try
	{
		if (!ADOTable1->Active)
		{
			ADOTable1->Open();
		}

		// ��������� � ����� ��������������
		ADOTable1->Edit();
		ADOTable1->FieldByName("���")->AsString = EditFIO->Text;
		ADOTable1->FieldByName("�����_��������")->AsString = EditPhone->Text;
		ADOTable1->FieldByName("����_��������")->AsString = EditDate->Text;
		ADOTable1->FieldByName("���")->AsString = EditPol->Text;
		ADOTable1->FieldByName("�����")->AsString = EditLog->Text;
		ADOTable1->FieldByName("������")->AsString = EditPassw->Text;
		
		// ��������� ���������
		ADOTable1->Post();

		ShowMessage("������ ������� ��������.");
		ModalResult = mrOk;
		Form4->Close();
	}
	catch (const Exception &e)
	{
		ShowMessage("������ ��� �������������� ������: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
