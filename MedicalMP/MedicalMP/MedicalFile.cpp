#include "MedicalFile.h"

MedicalFile::MedicalFile(int id, int patientId, int doctorId, tm date, Disease diagnostic)
{
	_id = id;
	_patientId = patientId;
	_doctorId = doctorId;
	_date = date;
	_diagnostic = diagnostic;
}

MedicalFile::~MedicalFile()
{
}

int MedicalFile::getId()
{
	return _id;
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

	_date = * localtime(&timer);
}