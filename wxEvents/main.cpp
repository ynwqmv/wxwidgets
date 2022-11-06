// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/button.h>

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
    void OnEnter(wxCommandEvent& event);
    void OnButtonClicked(wxCommandEvent& event);
    void OnTextChanged(wxCommandEvent& event);
    void OnSliderChanged(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1,
    ID_ENTER = 1,
    ID_BUTTON = 2,
    ID_TEXT = 1,
    ID_SLIDER = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(ID_ENTER, MyFrame::OnAbout)
    EVT_BUTTON(ID_BUTTON, MyFrame::OnButtonClicked)
    EVT_TEXT(ID_TEXT, MyFrame::OnTextChanged)
    EVT_SLIDER(ID_SLIDER, MyFrame::OnSliderChanged)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{

    MyFrame *frame = new MyFrame( "Hello World", wxPoint(100, 100), wxSize(450, 340) );
    frame->Show( true );
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{	
	// Panel
	wxPanel* panel = new wxPanel(this);
	 
    wxButton* button = new wxButton(panel, ID_BUTTON, "Tap on me", wxPoint(300,275), wxSize(200,50));
    wxSlider* slider = new wxSlider(panel, ID_SLIDER, 0,0,100,wxPoint(300,200), wxSize(200,-1));
    wxTextCtrl* text = new wxTextCtrl(panel, ID_TEXT, "", wxPoint(300,375), wxSize(200,-1));

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
void MyFrame::OnEnter(wxCommandEvent& event)
{
    wxLogMessage("DZETKA TI LUBISH RVANNIE JINSI");
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnButtonClicked(wxCommandEvent& event){
	wxLogStatus("Button Clicked");
	wxMessageBox( "Button was clicked",
                  "Button Event", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnTextChanged(wxCommandEvent& event)
{
	wxString str = wxString::Format("Text: %s", event.GetString());
	wxLogStatus(str);
}

void MyFrame::OnSliderChanged(wxCommandEvent& event)
{
	wxString str = wxString::Format("Slider Value: %d",event.GetInt());
	wxLogStatus(str);
}





/*

  FOR APP BUILDING, PLEASE ,USE CMAKE!
  CMAKE EXAMPLES U CAN FIND IN MY REPOSITORY!
  
  THANKS!
  

*/
