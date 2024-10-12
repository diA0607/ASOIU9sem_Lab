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
// Функция для установки данных в поля формы на основе выбранной записи
void __fastcall TForm4::SetData(TADOTable *Table)
{
    // Устанавливаем текущую таблицу
	 ADOTable1 = Table;  // Здесь устанавливаем указатель на текущую таблицу
	 if (!ADOTable1->Active)
		{
			ADOTable1->Open();  // Убедитесь, что таблица открыта
	 }
	ADOTable1->Edit();
	// Заполняем поля формы значениями из текущей записи таблицы
	EditFIO->Text = Table->FieldByName("ФИО")->AsString;
	EditPhone->Text = Table->FieldByName("Номер_телефона")->AsString;
	EditDate->Text = Table->FieldByName("Дата_рождения")->AsString;
	EditPol->Text = Table->FieldByName("Пол")->AsString;
	EditLog->Text = Table->FieldByName("Логин")->AsString;
	EditPassw->Text = Table->FieldByName("Пароль")->AsString;
}
void __fastcall TForm4::Button1Click(TObject *Sender)
{
   try
	{
		if (!ADOTable1->Active)
		{
			ADOTable1->Open();
		}

		// Переходим в режим редактирования
		ADOTable1->Edit();
		ADOTable1->FieldByName("ФИО")->AsString = EditFIO->Text;
		ADOTable1->FieldByName("Номер_телефона")->AsString = EditPhone->Text;
		ADOTable1->FieldByName("Дата_рождения")->AsString = EditDate->Text;
		ADOTable1->FieldByName("Пол")->AsString = EditPol->Text;
		ADOTable1->FieldByName("Логин")->AsString = EditLog->Text;
		ADOTable1->FieldByName("Пароль")->AsString = EditPassw->Text;
		
		// Сохраняем изменения
		ADOTable1->Post();

		ShowMessage("Запись успешно изменена.");
		ModalResult = mrOk;
		Form4->Close();
	}
	catch (const Exception &e)
	{
		ShowMessage("Ошибка при редактировании записи: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
