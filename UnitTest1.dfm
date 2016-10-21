object frmTestAISHotel: TfrmTestAISHotel
  Left = 192
  Top = 125
  Width = 618
  Height = 572
  Caption = 'frmTestAISHotel'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 62
    Width = 602
    Height = 471
    Align = alClient
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 602
    Height = 33
    ButtonHeight = 28
    ButtonWidth = 8
    Caption = 'ToolBar1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object btnPortOpen: TButton
      Left = 0
      Top = 2
      Width = 80
      Height = 28
      Caption = 'PortOpen'
      TabOrder = 5
      OnClick = btnPortOpenClick
    end
    object btnPortClose: TButton
      Left = 80
      Top = 2
      Width = 80
      Height = 28
      Caption = 'PortClose'
      TabOrder = 6
      OnClick = btnPortCloseClick
    end
    object ToolButton1: TToolButton
      Left = 160
      Top = 2
      Width = 8
      Caption = 'ToolButton1'
      Style = tbsSeparator
    end
    object eID: TEdit
      Left = 168
      Top = 2
      Width = 33
      Height = 28
      TabOrder = 1
      Text = '16'
    end
    object ID: TUpDown
      Left = 201
      Top = 2
      Width = 16
      Height = 28
      Associate = eID
      Min = 0
      Position = 16
      TabOrder = 2
      Wrap = False
    end
    object ToolButton2: TToolButton
      Left = 217
      Top = 2
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 0
      Style = tbsSeparator
    end
    object btnGetStatus: TButton
      Left = 225
      Top = 2
      Width = 112
      Height = 28
      Caption = 'GetStatus'
      TabOrder = 0
      OnClick = btnGetStatusClick
    end
    object ToolButton3: TToolButton
      Left = 337
      Top = 2
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 1
      Style = tbsSeparator
    end
    object btnTimeGet: TButton
      Left = 345
      Top = 2
      Width = 75
      Height = 28
      Caption = 'TimeGet'
      TabOrder = 3
      OnClick = btnTimeGetClick
    end
    object btnTimeSet: TButton
      Left = 420
      Top = 2
      Width = 75
      Height = 28
      Caption = 'TimeSet'
      TabOrder = 4
      OnClick = btnTimeSetClick
    end
  end
  object ToolBar3: TToolBar
    Left = 0
    Top = 33
    Width = 602
    Height = 29
    ButtonHeight = 21
    Caption = 'ToolBar3'
    TabOrder = 2
    object eCardID: TEdit
      Left = 0
      Top = 2
      Width = 41
      Height = 21
      TabOrder = 0
      Text = '1'
    end
    object cardID: TUpDown
      Left = 41
      Top = 2
      Width = 16
      Height = 21
      Associate = eCardID
      Min = 1
      Max = 8000
      Position = 1
      TabOrder = 3
      Wrap = False
    end
    object ToolButton5: TToolButton
      Left = 57
      Top = 2
      Width = 8
      Caption = 'ToolButton5'
      Style = tbsSeparator
    end
    object btnCardBlock: TButton
      Left = 65
      Top = 2
      Width = 100
      Height = 21
      Caption = 'CardBlock'
      TabOrder = 1
      OnClick = btnCardBlockClick
    end
    object btnCardUnblock: TButton
      Left = 165
      Top = 2
      Width = 100
      Height = 21
      Caption = 'CardUnblock'
      TabOrder = 2
      OnClick = btnCardUnblockClick
    end
    object ToolButton4: TToolButton
      Left = 265
      Top = 2
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 0
      Style = tbsSeparator
    end
    object btnCardUnblockAll: TButton
      Left = 273
      Top = 2
      Width = 100
      Height = 21
      Caption = 'CardUnblockAll'
      TabOrder = 4
      OnClick = btnCardUnblockAllClick
    end
    object ToolButton6: TToolButton
      Left = 373
      Top = 2
      Width = 116
      Caption = 'ToolButton6'
      ImageIndex = 1
      Style = tbsSeparator
    end
    object btnGetOneLog: TButton
      Left = 489
      Top = 2
      Width = 75
      Height = 21
      Caption = 'GetOneLog'
      TabOrder = 5
      OnClick = btnGetOneLogClick
    end
  end
end
