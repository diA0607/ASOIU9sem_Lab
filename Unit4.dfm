﻿object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 441
  ClientWidth = 463
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Имя: TLabel
    Left = 34
    Top = 57
    Width = 27
    Height = 15
    Caption = #1060#1048#1054
  end
  object Label1: TLabel
    Left = 34
    Top = 86
    Width = 94
    Height = 15
    Caption = #1053#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1072
  end
  object Label2: TLabel
    Left = 34
    Top = 107
    Width = 83
    Height = 15
    Caption = #1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103
  end
  object Label3: TLabel
    Left = 34
    Top = 139
    Width = 23
    Height = 15
    Caption = #1055#1086#1083
  end
  object Label4: TLabel
    Left = 34
    Top = 171
    Width = 34
    Height = 15
    Caption = #1051#1086#1075#1080#1085
  end
  object Label5: TLabel
    Left = 34
    Top = 203
    Width = 42
    Height = 15
    Caption = #1055#1072#1088#1086#1083#1100
  end
  object Label6: TLabel
    Left = 96
    Top = 22
    Width = 180
    Height = 15
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1076#1072#1085#1085#1099#1093' '#1082#1083#1080#1077#1085#1090#1072
  end
  object EditFIO: TEdit
    Left = 152
    Top = 54
    Width = 241
    Height = 23
    TabOrder = 0
  end
  object EditPhone: TEdit
    Left = 152
    Top = 83
    Width = 241
    Height = 23
    TabOrder = 1
  end
  object EditDate: TEdit
    Left = 152
    Top = 112
    Width = 241
    Height = 23
    TabOrder = 2
  end
  object EditPol: TEdit
    Left = 152
    Top = 141
    Width = 241
    Height = 23
    TabOrder = 3
  end
  object EditLog: TEdit
    Left = 152
    Top = 170
    Width = 241
    Height = 23
    TabOrder = 4
  end
  object EditPassw: TEdit
    Left = 152
    Top = 203
    Width = 241
    Height = 23
    TabOrder = 5
  end
  object Button1: TButton
    Left = 184
    Top = 254
    Width = 153
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 184
    Top = 318
    Width = 153
    Height = 25
    Caption = #1053#1072#1079#1072#1076
    TabOrder = 7
    OnClick = Button2Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=beauty;Data Source=LAPTOP-VEU33095\SQLE' +
      'XPRESS'
    Provider = 'SQLOLEDB.1'
    Left = 240
    Top = 368
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = #1050#1083#1080#1077#1085#1090#1099'3'
    Left = 352
    Top = 360
  end
  object DataSource1: TDataSource
    Left = 136
    Top = 368
  end
end
