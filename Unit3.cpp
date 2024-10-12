//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm3::SetData(TADOTable *table)
{
    ADOTable1 = table; // Сохраняем ссылку на таблицу
    LoadData(); // Загружаем данные в поля
}

void TForm3::LoadData()
{
    if (ADOTable1->Active && !ADOTable1->IsEmpty())
    {
        EditFIO->Text = ADOTable1->FieldByName("ФИО")->AsString;
        EditPhone->Text = ADOTable1->FieldByName("Номер_телефона")->AsString;
        EditDate->Text = ADOTable1->FieldByName("Дата_рождения")->AsString;
        EditPol->Text = ADOTable1->FieldByName("Пол")->AsString;
        EditLog->Text = ADOTable1->FieldByName("Логин")->AsString;
        EditPassw->Text = IntToStr(ADOTable1->FieldByName("Пароль")->AsInteger);
    }
}

void __fastcall TForm3::Button1Click(TObject *Sender)
{
    try
	{
		if (!ADOTable1->Active)
		{
			ADOTable1->Open();
		}

		// Редактируем текущую запись
		ADOTable1->Edit();

		// Обновление
        ADOTable1->FieldByName("ФИО")->AsString = EditFIO->Text;
        ADOTable1->FieldByName("Номер_телефона")->AsString = EditPhone->Text;
        ADOTable1->FieldByName("Дата_рождения")->AsString = EditDate->Text;
        ADOTable1->FieldByName("Пол")->AsString = EditPol->Text;
        ADOTable1->FieldByName("Логин")->AsString = EditLog->Text;
        ADOTable1->FieldByName("Пароль")->AsInteger = StrToInt(EditPassw->Text);

        ADOTable1->Post(); // Сохраняем изменения

        ShowMessage("Данные клиента успешно обновлены.");
        ModalResult = mrOk; // Закрываем форму с результатом
        Close();
    }
    catch (const Exception &e)
	{
		ShowMessage("Ошибка при обновлении данных: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Close(); // Закрываем форму без сохранения
}
//---------------------------------------------------------------------------
