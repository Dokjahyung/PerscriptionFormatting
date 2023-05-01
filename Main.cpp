
#include <wx/wx.h> // main wxWidgets header
#include <wx/textctrl.h> // wxTextCtrl header for text input control
#include <wx/spinctrl.h> // wxSpinCtrl header for spin control
#include <wx/button.h> // wxButton header for button control
#include <iostream> // header for input/output operations
#include "perscription.h" // header for the perscription class

#include <wx/spinctrl.h>
#include "perscription.h"

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        wxStaticText* patientLabel = new wxStaticText(panel, wxID_ANY, "Patient:");
        wxTextCtrl* patientInput = new wxTextCtrl(panel, wxID_ANY, "");
        wxString patientName = patientInput->GetValue();

        wxStaticText* birthLabel = new wxStaticText(panel, wxID_ANY, "Birth:");
        wxTextCtrl* birthInput = new wxTextCtrl(panel, wxID_ANY, "");
        wxString birthDate = birthInput->GetValue();

        wxStaticText* medicationLabel = new wxStaticText(panel, wxID_ANY, "Medication:");
        wxTextCtrl* medicationInput = new wxTextCtrl(panel, wxID_ANY, "");
        wxString medication = medicationInput->GetValue();

        wxStaticText* dosageLabel = new wxStaticText(panel, wxID_ANY, "Dosage:");
        wxSpinCtrlDouble* dosageInput = new wxSpinCtrlDouble(panel, wxID_ANY, "");
        double dosage = dosageInput->GetValue();
        


        wxStaticText* physicianLabel = new wxStaticText(panel, wxID_ANY, "Physician:");
        wxTextCtrl* physicianInput = new wxTextCtrl(panel, wxID_ANY, "");
        wxString physician = physicianInput->GetValue();

        // create a wxStaticText control to display the prescription string
        wxStaticText* perscriptionText = new wxStaticText(panel, wxID_ANY, "");
        wxString labelText = "patient name, birth date, medication, strength, physician";
        perscriptionText->SetLabelText(labelText);

        // set the initial value of the control to the prescription string

                    // Create the submit button
        wxButton* submitButton = new wxButton(panel, wxID_ANY, "Submit", wxPoint(10, 10), wxDefaultSize);

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(patientLabel, 0, wxALIGN_LEFT | wxALL, 5);
        sizer->Add(patientInput, 0, wxEXPAND | wxALL, 5);
        sizer->Add(birthLabel, 0, wxALIGN_LEFT | wxALL, 5);
        sizer->Add(birthInput, 0, wxEXPAND | wxALL, 5);
        sizer->Add(medicationLabel, 0, wxALIGN_LEFT | wxALL, 5);
        sizer->Add(medicationInput, 0, wxEXPAND | wxALL, 5);
        sizer->Add(dosageLabel, 0, wxALIGN_LEFT | wxALL, 5);
        sizer->Add(dosageInput, 0, wxEXPAND | wxALL, 5);
        sizer->Add(physicianLabel, 0, wxALIGN_LEFT | wxALL, 5);
        sizer->Add(physicianInput, 0, wxEXPAND | wxALL, 5);
        sizer->Add(submitButton, 0, wxEXPAND | wxALL, 5);

        wxStaticText* perscriptionLabel = new wxStaticText(panel, wxID_ANY, "Prescription:");
        wxBoxSizer* prescriptionSizer = new wxBoxSizer(wxHORIZONTAL);
        prescriptionSizer->Add(perscriptionLabel, 0, wxALIGN_LEFT | wxALL, 5);
        prescriptionSizer->Add(perscriptionText, 0, wxALIGN_LEFT | wxALL, 5);
        sizer->Add(prescriptionSizer, 0, wxEXPAND | wxALL, 5);
        panel->SetSizer(sizer);


    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame("Input Variables");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
