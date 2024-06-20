#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void m_panel1OnPaint( wxPaintEvent& event );
		void m_button1_click( wxCommandEvent& event );
		void m_button2_click( wxCommandEvent& event );
		void m_button3_click( wxCommandEvent& event );
		void m_button4_click( wxCommandEvent& event );
		void m_cb_color_click( wxCommandEvent& event );
		void m_s_rotation_onscroll( wxScrollEvent& event );
		void m_s_tilt_onscroll( wxScrollEvent& event );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members
	protected:
		double alpha = 133 * M_PI / 180;
		double theta = 50 * M_PI / 180;

		float FunctionData[100][3];
		int   NoPoints;

		void PrepareData(int fun);
		double x[2500];
		double y[2500];
		double z[2500];

		bool color = false;


};

#endif // __GUIMyFrame1__
