//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm2::Button2Click(TObject *Sender)
{
   Form1->Show();
   Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button1Click(TObject *Sender)
{
  try
  {
		if (!ADOTable1->Active)
		{
			ADOTable1->Open();
		}
		ADOTable1->Append();
		ADOTable1->FieldByName("ФИО")->AsString = EditFIO->Text;
		ADOTable1->FieldByName("Номер_телефона")->AsString = EditPhone->Text;
		ADOTable1->FieldByName("Дата_рождения")->AsString =  EditDate->Text;
		ADOTable1->FieldByName("Пол")->AsString = EditPol->Text;
		ADOTable1->FieldByName("Логин")->AsString = EditLog->Text;
		ADOTable1->FieldByName("Пароль")->AsString = EditPassw->Text;
		ADOTable1->Edit();
		ADOTable1->Post();

		ShowMessage("Клиент успешно добавлен.");
        EditFIO->Text = "";
		EditPhone->Text = "";
		EditDate->Text = "";
		EditPol->Text = "";
		EditLog->Text = "";
		EditPassw->Text = "";

		ModalResult = mrOk;
		Form2->Close();

  }
  catch (const Exception &e)
  {
	ShowMessage("Ошибка при добавлении клиента: " + e.Message);
  }
}
//---------------------------------------------------------------------------



