#include "TetrisGame.hpp"
#include "Board.hpp"
#include <wx/menu.h>
#include <wx/aboutdlg.h>

TetrisGame::TetrisGame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(180, 380))
{
    wxStatusBar *statusBar = CreateStatusBar();
    statusBar->SetStatusText(wxT("Score: 0"));

    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* menuHelp = new wxMenu;
    wxMenu* menu = new wxMenu;
    menuHelp->Append(wxID_EXIT);
    menu->Append(wxID_ABOUT);
    menuBar->Append(menuHelp, "&Quit");
    menuBar->Append(menu,"&Help");
    SetMenuBar(menuBar);



    Board* board = new Board(this);
    board->SetFocus();
    board->Start();

    srand(time(NULL));
}

void TetrisGame::OnExit(wxCommandEvent& evt)
{
	Close();

}

void TetrisGame::OnAbout(wxCommandEvent& evt)
{
    // Create the About dialog.
    // On Windows, the wxGenericAboutBox will be used
    // because it is used when an icon, a website or 
    // a license is specified.
    wxAboutDialogInfo info;

    info.SetName(L"About App");
    info.SetVersion(L"v1.3.7");
    info.SetDescription(L"A sample application to demonstrate the Tetris Game");
    info.SetCopyright(L"Copyright (c) 2022 @ynwqmv");
    info.SetWebSite(L"https://github.com/ynwqmv");

    wxArrayString developers;
    developers.Add(L"ynwqmv");
    info.SetDevelopers(developers);

    wxArrayString docWriters;
    docWriters.Add(L"ynwqmv");
    info.SetDocWriters(docWriters);

    info.SetLicence(
        L"Permission is hereby granted, free of charge, \nto any person obtaining a "
        L"copy of this software and associated documentation \nfiles (the \"Software\"), "
        L"to deal in the Software without restriction, \nincluding without limitation "
        L"the rights to use, copy, modify, merge, publish,\n distribute, sublicense, "
        L"and / or sell copies of the Software, and to \npermit persons to whom the "
        L"Software is furnished to do so, subject to the \nfollowing conditions :\n"
        L"\n"
        L"The above copyright notice and this permission \nnotice shall be included in "
        L"all copies or substantial portions of the Software.\n"
        L"\n"
        L"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT \nWARRANTY OF ANY KIND, EXPRESS OR "
        L"IMPLIED, INCLUDING BUT NOT LIMITED TO THE \nWARRANTIES OF MERCHANTABILITY, "
        L"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.\n IN NO EVENT SHALL "
        L"THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,\n DAMAGES OR OTHER "
        L"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR \nOTHERWISE, ARISING "
        L"FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR \nTHE USE OR OTHER DEALINGS "
        L"IN THE SOFTWARE.");
    
    wxAboutBox(info);
}

wxBEGIN_EVENT_TABLE(TetrisGame, wxFrame)
    EVT_MENU(wxID_ABOUT, TetrisGame::OnAbout)
    EVT_MENU(wxID_EXIT, TetrisGame::OnExit)
wxEND_EVENT_TABLE()