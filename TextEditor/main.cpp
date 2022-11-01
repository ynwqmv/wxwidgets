// For compilers that/ supports precompilation , includes "wx/wx.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class App : public wxApp {
public:
    virtual bool OnInit();
};

class TextFrame : public wxFrame
{
public:

    /** Constructor. Creates a new TextFrame */
    TextFrame();

    /** Processes menu File|Open */
    void OnMenuFileOpen(wxCommandEvent &event);

    /** Processes menu File|Save */
    void OnMenuFileSave(wxCommandEvent &event);

    /** Processes menu File|Quit */
    void OnMenuFileQuit(wxCommandEvent &event);

    /** Processes menu About|Info */
    void OnMenuHelpAbout(wxCommandEvent &event);

protected:

    DECLARE_EVENT_TABLE()

private:

    wxTextCtrl *m_pTextCtrl;
    wxMenuBar *m_pMenuBar;
    wxMenu *m_pFileMenu;
    wxMenu *m_pHelpMenu;
};




TextFrame::TextFrame()
: wxFrame(nullptr,wxID_ANY, "Hello")
{
    m_pTextCtrl = new wxTextCtrl(this, -1, _T("Type some text..."),
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    CreateStatusBar(3);
    SetStatusText(_T("Ready"), 0);

    m_pMenuBar = new wxMenuBar();
    // File menu
    m_pFileMenu = new wxMenu();
    m_pFileMenu->Append(wxID_OPEN, _T("&Open"), _T("Opens an existing file"));
    m_pFileMenu->Append(wxID_SAVE, _T("&Save"), _T("Save the content"));
    m_pFileMenu->AppendSeparator();
    m_pFileMenu->Append(wxID_EXIT, _T("&Quit"), _T("Quit the application"));
    m_pMenuBar->Append(m_pFileMenu, _T("&File"));
     
    // About menu
    m_pHelpMenu = new wxMenu();
    m_pHelpMenu->Append(wxID_ABOUT, _T("&About"), _T("Shows information about the application"));
    m_pMenuBar->Append(m_pHelpMenu, _T("&Info"));
 
    SetMenuBar(m_pMenuBar);
 
    Layout();
}

bool App::OnInit() {

    TextFrame *frame = new TextFrame();
    frame->Show(true);
    return true;
}
// If you're doing an application by inheriting from wxApp
// be sure to change wxFrame to wxApp (or whatever component
// you've inherited your class from).
BEGIN_EVENT_TABLE(TextFrame, wxFrame)
    EVT_MENU(wxID_OPEN, TextFrame::OnMenuFileOpen)
    EVT_MENU(wxID_SAVE, TextFrame::OnMenuFileSave)
    EVT_MENU(wxID_EXIT, TextFrame::OnMenuFileQuit)
    EVT_MENU(wxID_ABOUT, TextFrame::OnMenuHelpAbout)
END_EVENT_TABLE()

void TextFrame::OnMenuFileOpen(wxCommandEvent &event)
{
    wxFileDialog *OpenDialog= new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);
    if ( OpenDialog->ShowModal() == wxID_OK )
    {
        m_pTextCtrl->LoadFile(OpenDialog->GetPath()) ?
            SetStatusText(_T("Loaded")) :
            SetStatusText(_T("Load Failed")) ;
    }
    OpenDialog->Close(); // Or OpenDialog->Destroy() ?
}

void TextFrame::OnMenuFileSave(wxCommandEvent &event)
{
    wxFileDialog *SaveDialog= new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);
    if ( SaveDialog->ShowModal() == wxID_OK )
    {
        m_pTextCtrl->SaveFile(SaveDialog->GetPath()) ?
            SetStatusText(_T("Saved")) :
            SetStatusText(_T("Save Failed"));
    }
    SaveDialog->Close();
}

void TextFrame::OnMenuFileQuit(wxCommandEvent &event)
{
    Close(false);
}

void TextFrame::OnMenuHelpAbout(wxCommandEvent &event)
{
    wxLogMessage(_T("The Simple Text Editor"));
}

wxIMPLEMENT_APP(App);





// /*
    
//     * WXWIDGETS: 3.0.5 
//     * AUTHOR: YNWQMV
//     * USED: CMAKE, CXX-11
// */

// #include <wx/wx.h>
// #include <wx/wxprec.h>

// class App : public wxApp
// {
// public:
//     virtual bool OnInit();
// };

// class Frame: public wxFrame
// {
// public:

//     Frame();

// };


// bool App::OnInit() {
//     Frame *frame = new Frame();
//     frame->Show(true);
//     return true;
// }

// Frame::Frame() : wxFrame(nullptr, wxID_ANY, "YouTube")
// {

// }

// wxIMPLEMENT_APP(App);


















// // // wxWidgets "Hello World" Program
 
// // // For compilers that support precompilation, includes "wx/wx.h".
// // #include <wx/wxprec.h>
 
// // #ifndef WX_PRECOMP
// //     #include <wx/wx.h> // wxApp, wxFrame
// // #endif
 
// // class MyApp : public wxApp
// // {
// // public:
// //     virtual bool OnInit();
// // };
 
// // class MyFrame : public wxFrame
// // {
// // public:
// //     MyFrame();
 
// // private:
// //     void OnHello(wxCommandEvent& event);
// //     void OnExit(wxCommandEvent& event);
// //     void OnAbout(wxCommandEvent& event);
// // };
 
// // enum
// // {
// //     ID_Hello = 1
// // };
 
// // wxIMPLEMENT_APP(MyApp);
 
// // bool MyApp::OnInit()
// // {
// //     MyFrame *frame = new MyFrame();
// //     frame->Show(true);
// //     return true;
// // }
 
// // MyFrame::MyFrame()
// //     : wxFrame(nullptr, wxID_ANY, "Hello, YouTube!")
// // {
// //     wxMenu *menuFile = new wxMenu;
// //     menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
// //                      "Help string shown in status bar for this menu item");
// //     menuFile->AppendSeparator();
// //     menuFile->Append(wxID_EXIT);
 
// //     wxMenu *menuHelp = new wxMenu;
// //     menuHelp->Append(wxID_ABOUT);
 
// //     wxMenuBar *menuBar = new wxMenuBar;
// //     menuBar->Append(menuFile, "&File");
// //     menuBar->Append(menuHelp, "&Help");
 
// //     SetMenuBar( menuBar );
 
// //     CreateStatusBar();
// //     SetStatusText("Welcome to wxWidgets!");
 
// //     Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
// //     Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
// //     Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
// // }
 
// // void MyFrame::OnExit(wxCommandEvent& event)
// // {
// //     Close(true);
// // }
 
// // void MyFrame::OnAbout(wxCommandEvent& event)
// // {
// //     wxMessageBox("This is a wxWidgets Hello World example",
// //                  "About Hello World", wxOK | wxICON_INFORMATION);
// // }
 
// // void MyFrame::OnHello(wxCommandEvent& event)
// // {
// //     wxLogMessage("Hello world from wxWidgets!");
// // }
