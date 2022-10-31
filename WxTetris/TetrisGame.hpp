#include <wx/wx.h>

class TetrisGame : public wxFrame
{
public:
   TetrisGame(const wxString& title);

   void OnAbout(wxCommandEvent& evt);

   void OnExit(wxCommandEvent& evt);

   wxDECLARE_EVENT_TABLE();
};
