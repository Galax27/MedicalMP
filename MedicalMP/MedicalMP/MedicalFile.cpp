#include "stdafx.h"

namespace MedicalMP
{
	MedicalFile::MedicalFile(int id, int patientId, int doctorId, tm date, Disease diagnostic) 
		:BaseEntity(id)
    {
        _patientId = patientId;
        _doctorId = doctorId;
        _date = date;
        _diagnostic = diagnostic;
    }

    MedicalFile::~MedicalFile()
    {
    }

    int MedicalFile::getPatientId()
    {
        return _patientId;
    }

    int MedicalFile::getDoctorId()
    {
        return _doctorId;
    }

    tm MedicalFile::getDate()
    {
        return _date;
    }

    Disease MedicalFile::getDiagnostic()
    {
        return _diagnostic;
    }

    void MedicalFile::setDiagnostic(Disease diagnostic, int doctorId)
    {
        _diagnostic = diagnostic;
        _doctorId = doctorId;

        time_t timer;
        time(&timer);

        _date = *localtime(&timer);
    }
}