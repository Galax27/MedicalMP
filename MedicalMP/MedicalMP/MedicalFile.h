#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class MedicalFile
    {
    private:
        int _id,
            _patientId,
            _doctorId;
        tm _date;
        Disease _diagnostic;

    public:
        MedicalFile(int id, int patientId, int doctorId, tm date, Disease diagnostic);
        ~MedicalFile();

        int getId();
        int getPatientId();
        int getDoctorId();
        tm getDate();

        Disease getDiagnostic();
        void setDiagnostic(Disease diagnostic, int doctorId);
    };
}