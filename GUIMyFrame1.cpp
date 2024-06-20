#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
    m_panel1->SetDoubleBuffered(true);
    PrepareData(0);
}

void GUIMyFrame1::m_panel1OnPaint( wxPaintEvent& event )
{
   
    double x_in[100], y_in[100];
   
   
    for (int i = 0; i < NoPoints; ++i)
    {
        x_in[i] = FunctionData[i][0] * cos(alpha) - FunctionData[i][1] * sin(alpha);
        y_in[i] = FunctionData[i][0] * sin(alpha) + FunctionData[i][1] * cos(alpha);
    }

    
    // Interpolacja metod¹ Sheparda
    int counter = 0;
    for (double j = 2.5; j >= -2.5; j -= 0.1)
    {
        for (double i = 2.5; i >= -2.5; i -= 0.1)
        {
            x[counter] = i;
            y[counter] = j;
            double licznik = 0;
            double mianownik = 0;
            for (int k = 0; k < NoPoints; ++k)
            {
                double waga = 1 / (pow((i - x_in[k]), 2) + pow((j - y_in[k]), 2));
                mianownik += waga;
                licznik += waga * FunctionData[k][2];
            }
            z[counter] = licznik / mianownik;
            ++counter;
        }
    }

    double min_val = DBL_MAX;
    double max_val = -min_val;

    for (int i = 0; i < 2500; ++i)
    {
        if (z[i] > max_val)
        {
            max_val = z[i];
        }
        if (z[i] < min_val)
        {
            min_val = z[i];
        }
    }
        
    wxBufferedPaintDC dc(m_panel1);
    
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();

    for (int i = 0; i < 2500; ++i)
    {
        if (!color)
        {
            dc.SetBrush(wxBrush(wxColor((z[i] - min_val) / (max_val - min_val) * 255, (z[i] - min_val) / (max_val - min_val) * 255, (z[i] - min_val) / (max_val - min_val) * 255)));
            dc.SetPen(wxPen(wxColor((z[i] - min_val) / (max_val - min_val) * 255, (z[i] - min_val) / (max_val - min_val) * 255, (z[i] - min_val) / (max_val - min_val) * 255)));
        }
        else {
            dc.SetBrush(wxBrush(wxColor((z[i] - min_val) / (max_val - min_val) * 255, 0 ,(max_val - z[i]) / (max_val - min_val) * 255)));
            dc.SetPen(wxPen(wxColor((z[i] - min_val) / (max_val - min_val) * 255, 0  ,(max_val - z[i]) / (max_val - min_val) * 255)));
        }
        dc.DrawRectangle( 1+ (int)((x[i] + 2.5) / 5 * 400 + (y[i] + 2.5) / 5 * 100 / tan(M_PI/18 * 5)), 10-(int)((y[i] + 2.5) / 5 * 100 * tan(theta)) + 250 + 50 * tan(theta), 8,  -20 - (int)((z[i] - min_val) / (max_val - min_val) * 60));
    }


    
    
}

void GUIMyFrame1::m_button1_click( wxCommandEvent& event )
{
    PrepareData(1);
    Refresh();
}

void GUIMyFrame1::m_button2_click( wxCommandEvent& event )
{
    PrepareData(2);
    Refresh();
}

void GUIMyFrame1::m_button3_click( wxCommandEvent& event )
{
    PrepareData(3);
    Refresh();
}

void GUIMyFrame1::m_button4_click( wxCommandEvent& event )
{
    PrepareData(4);
    Refresh();
}

void GUIMyFrame1::m_cb_color_click( wxCommandEvent& event )
{
    if (!color)
    {
        color = true;
    }
    else {
        color = false;
    }
    Refresh();
}

void GUIMyFrame1::m_s_rotation_onscroll( wxScrollEvent& event )
{
    m_st_rotation->SetLabel(wxString::Format("Obrot: %d stopni.",m_s_rotation->GetValue()));
    alpha = -( m_s_rotation->GetValue() * M_PI / 180 +  M_PI/2 );
    Refresh();
}

void GUIMyFrame1::m_s_tilt_onscroll( wxScrollEvent& event )
{
    theta = (m_s_tilt->GetValue() /2 + 25) * M_PI / 180;
    Refresh();
}

void GUIMyFrame1::PrepareData(int fun)
{
    int i;
    float x, y;
    srand(376257);

    switch (fun)
    {
    case 0: NoPoints = 5;
        FunctionData[0][0] = -1.0;	FunctionData[0][1] = 1.0;	FunctionData[0][2] = 0.0;
        FunctionData[1][0] = 1.0;	FunctionData[1][1] = 1.0;	FunctionData[1][2] = 25.0;
        FunctionData[2][0] = 1.0;	FunctionData[2][1] = -1.0;	FunctionData[2][2] = 5.0;
        FunctionData[3][0] = -1.0;	FunctionData[3][1] = -1.0;	FunctionData[3][2] = 25.0;
        FunctionData[4][0] = 0.0;	FunctionData[4][1] = 0.0;	FunctionData[4][2] = 15.0;
        break;
    case 1: NoPoints = 20;
        for (i = 0; i < NoPoints; i++)
        {
            x = 4.8 * (float(rand()) / RAND_MAX) - 2.4;
            y = 4.8 * (float(rand()) / RAND_MAX) - 2.4;
            FunctionData[i][0] = x;
            FunctionData[i][1] = y;
            FunctionData[i][2] = 200 * (float(rand()) / RAND_MAX);
        }
        break;
    case 2: NoPoints = 100;
        for (i = 0; i < NoPoints; i++)
        {
            x = 4.8 * (float(rand()) / RAND_MAX) - 2.4;
            y = 4.8 * (float(rand()) / RAND_MAX) - 2.4;
            FunctionData[i][0] = x;
            FunctionData[i][1] = y;
            FunctionData[i][2] = x * (2 * x - 7) * (2 * y + 1) + 2 * y;
        }
        break;
    case 3: NoPoints = 10;
        for (i = 0; i < NoPoints; i++)
        {
            x = 4.8 * (float(rand()) / RAND_MAX) - 2.4;
            y = 4.8 * (float(rand()) / RAND_MAX) - 2.4;
            FunctionData[i][0] = x;
            FunctionData[i][1] = y;
            FunctionData[i][2] = x * sin(2 * y);
        }
        break;
    case 4: NoPoints = 100;
        for (i = 0; i < NoPoints; i++)
        {
            x = 2 * (float(rand()) / RAND_MAX) - 1;
            y = 2 * (float(rand()) / RAND_MAX) - 1;
            FunctionData[i][0] = x;
            FunctionData[i][1] = y;
            FunctionData[i][2] = sin(8 * (x * x + y * y));
        }
        break;
    }
}