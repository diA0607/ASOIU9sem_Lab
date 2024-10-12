//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Имя;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *EditFIO;
	TEdit *EditPhone;
	TEdit *EditDate;
	TEdit *EditPol;
	TEdit *EditLog;
	TEdit *EditPassw;
	TButton *Button1;
	TButton *Button2;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	 void LoadData(); // Метод для загрузки данных
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	void SetData(TADOTable *table); // Метод для установки данных
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
