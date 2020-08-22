#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton *m_btn1 = nullptr;
	wxButton *m_btn2 = nullptr;
	wxTextCtrl *m_txt1 = nullptr;
	wxTextCtrl *m_txt2 = nullptr;
	wxStaticBox *m_text = nullptr;


	

	void OnButtonClicked(wxCommandEvent &evt);
	wxDECLARE_EVENT_TABLE();
};

