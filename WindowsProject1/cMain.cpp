#include "cMain.h"
#include "iostream"
#include "regex"
#include "node.h"
#include "vector"

using namespace std;

wxBEGIN_EVENT_TABLE(cMain,wxFrame)
	EVT_BUTTON(10001,OnButtonClicked)
	EVT_BUTTON(10002, OnButtonClicked)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr,wxID_ANY,"Title",wxPoint(30,30),wxSize(800,600))
{
	m_btn1 = new wxButton(this, 10001, "+", wxPoint(10, 210), wxSize(50, 50));
	m_btn2 = new wxButton(this, 10002, "-", wxPoint(70, 210), wxSize(50, 50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_txt2 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 140), wxSize(300, 30));
	m_text = new wxStaticBox(this,wxID_ANY, "", wxPoint(10,300), wxSize(300,30),0,"RESULT!");
	m_text->Show(false);
	m_txt1->SetHint("Polynomial 1:");
	m_txt2->SetHint("Polynomial 2:");
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent & evt)
{
	string poly1 = m_txt1->GetValue().ToStdString();
	string poly2 = m_txt2->GetValue().ToStdString();
	if (poly1 == "" || poly2 == "") {
		m_text->SetLabel("ERROR!");
		m_text->Show(true);
		evt.Skip();
		return;
	}

	std::smatch matches;
	std::regex reg("([+-]?[0-9]*x{1}['^']{1}[0-9]*)");

	Node *nodeObject = new Node();

	// first -> 5x^2 + 3x + 1
	vector<int> power1 = { 2,1,0 };
	vector<int> coff1 = { 5,3,1 };
	
	// second ->  4x + 4x^4+ 1
	vector<int> power2 = { 1,4,0 };
	vector<int> coff2 = { 4,4,1 };

	// get data into these vectors

	
	
	Node *polynomial_1 = nodeObject->CreatePolynomialList(power1, coff1);
	Node *polynomial_2 = nodeObject->CreatePolynomialList(power2, coff2);
	Node *result = nodeObject->AddPolynomials(polynomial_1,polynomial_2) ;
	string output = nodeObject->Display(result);

	m_text->SetLabel(output);
	m_text->Show(true);
	evt.Skip();
}
