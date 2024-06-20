///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/wxprec.h>
#include <wx/colordlg.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel1;
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		wxStaticText* m_st_rotation;
		wxCheckBox* m_cb_color;
		wxSlider* m_s_rotation;
		wxSlider* m_s_tilt;

		// Virtual event handlers, override them in your derived class
		virtual void m_panel1OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void m_button1_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button2_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button3_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button4_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_cb_color_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_s_rotation_onscroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_s_tilt_onscroll( wxScrollEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 530,650 ), long style = wxDEFAULT_FRAME_STYLE|wxBORDER_NONE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

