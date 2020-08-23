#include "cMain.h"
#include "iostream"
#include "node.h"
#include "vector"

using namespace std;

wxBEGIN_EVENT_TABLE(cMain,wxFrame)
	EVT_BUTTON(10001,OnButtonClicked)
	EVT_BUTTON(10002, OnButtonClicked)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr,wxID_ANY,"Polynomial - Arithmetic",wxPoint(30,30),wxSize(800,600))
{
	// initalizing two buttons of wxButton class
	m_btn1 = new wxButton(this, 10001, "+", wxPoint(10, 210), wxSize(50, 50));
	m_btn2 = new wxButton(this, 10002, "-", wxPoint(70, 210), wxSize(50, 50));

	// initalizing two textbox for polynomials input from user of wxTextCtrl class 
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_txt2 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 140), wxSize(300, 30));
	
	// creating a textbox  of wxStaticBox for displaying output
	m_text = new wxStaticBox(this,wxID_ANY, "", wxPoint(10,300), wxSize(300,30),0,"RESULT!");

	// initially hiding the m_text 
	m_text->Show(false);

	// setting placeholders 
	m_txt1->SetHint("Polynomial 1:");
	m_txt2->SetHint("Polynomial 2:");
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent & evt)
{
	// retrieving both poylnomials as string 
	string poly1 = m_txt1->GetValue().ToStdString();
	string poly2 = m_txt2->GetValue().ToStdString();

	// checking any one of the polynomial is missing or not 
	if (poly1 == "" || poly2 == "") {
		m_text->SetLabel("ERROR!");
		m_text->Show(true);
		evt.Skip();
		return;
	}
	
	// creating object of node class
	Node *nodeObject = new Node();

	// creating temprary vectors to extract data 
	vector<int> power1 , power2;
	vector<int> coff1 , coff2;

	// get data into these vectors
	nodeObject->retriveValues(poly1, power1, coff1);
	nodeObject->retriveValues(poly2, power2, coff2);
	
	// creating two linklist out of there vectors
	Node *polynomial_1 = nodeObject->CreatePolynomialList(power1,coff1);
	Node *polynomial_2 = nodeObject->CreatePolynomialList(power2,coff2);

	 //adding both linklist to perform a result polynomial linklist
	Node *result = nodeObject->AddPolynomials(polynomial_1,polynomial_2) ;

	 //displaying the result [resturn a string to display using m_text wxwidget]
	string output = nodeObject->Display(result);

	//displaying the result 
	m_text->SetLabel(output);

	 //seting m_text visible
	m_text->Show(true);

	// ending the event of OnButtonClicked  
	evt.Skip();
}
