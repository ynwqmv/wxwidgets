// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/button.h>
#include <wx/spinctrl.h>
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Hello World", wxPoint(150, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{	
	// Panel
	wxPanel* panel = new wxPanel(this);
	// Button
	wxButton* button = new wxButton(panel,wxID_ANY,"Button", wxPoint(150,50), wxSize(100,35));
    // CheckBox
    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550,55), wxSize(100,35));
    // StaticText
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY,"StaticText **NOT EDITABLE**",wxPoint(120,150));
    // TextCtrl
   	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500,145), wxSize(200,-1));
    // Slider
    wxSlider* slider = new wxSlider(panel,wxID_ANY, 25,0,100, wxPoint(100,250), wxSize(200,-1));
    // Gauge
    wxGauge* gauge = new wxGauge(panel,wxID_ANY, 100,wxPoint(500,255), wxSize(200,-1));
    gauge->SetValue(100);

    // ArrayString | Choices
    wxArrayString choices;
    // Adding Choices
    choices.Add("CPU System-Cooler5");
    choices.Add("CPU AirCool G55U");
    choices.Add("CPU DeepCool UN900 PRO");

    // Choice
    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150,375),wxSize(200,-1),choices);
    choice->Select(1);
    
    // SpinCtrl
    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel,wxID_ANY,"",wxPoint(550,375),wxSize(170,-1));
    // ListBox
    wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150,475),wxSize(190,50),choices);
    // RadioBox
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Cooler Settings", wxPoint(485,475), wxDefaultSize,choices);

    //
    wxMenu *menuFile = new wxMenu;	
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
