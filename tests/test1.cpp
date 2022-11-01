// Version using dynamic event routing
// Use '''Connect''' instead of event table.
// Robert Roebling, Martin Bernreuther, Lance Zhang, Ryan Norton

#include <wx/wx.h>

class MyApp : public wxApp
{
   virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

class MyFrame : public wxFrame
{
public:
   MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
protected:
   // Do we really need to expose the implementation detail? I guess not.
   void OnQuit(wxCommandEvent& event);
   void OnAbout(wxCommandEvent& event);
private:
   enum {ID_Quit=wxID_HIGHEST + 1, ID_About};
};

bool MyApp::OnInit()
{
   wxFrame *frame = new MyFrame(wxT("Hello World"), wxPoint(50,50),
     wxSize(450,350));
     frame->Show(TRUE);
     SetTopWindow(frame);
     return TRUE;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame((wxFrame*)NULL, -1, title, pos, size)
{
  // create menubar
  wxMenuBar* menuBar = new wxMenuBar;
  // create menu
  wxMenu* menuFile = new wxMenu;
  // append menu entries
  menuFile->Append(ID_About, wxT("&About..."));
  menuFile->AppendSeparator();
  menuFile->Append(ID_Quit, wxT("E&xit"));
  // append menu to menubar
  menuBar->Append(menuFile, "&File");
  // set frame menubar
  SetMenuBar(menuBar);

  // connect event handlers
  Connect(ID_Quit,wxEVT_COMMAND_MENU_SELECTED,
     wxCommandEventHandler(MyFrame::OnQuit));
  Connect(ID_About,wxEVT_COMMAND_MENU_SELECTED,
     wxCommandEventHandler(MyFrame::OnAbout));

  CreateStatusBar();
  SetStatusText(wxT("Welcome to wxWidgets"));
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
   Close(TRUE);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
   wxMessageBox(wxT("wxWidgets Hello World example."),wxT("About Hello World"),
        wxOK|wxICON_INFORMATION, this);
}
