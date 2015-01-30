#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Context
    {
    public:
        std::set<Patient*> *Patients;
		std::set<Doctor*> *Doctors;
		std::set<MedicalFile*> *MedicalFiles;
		std::set<Department*> *Departments;

		Context()
		{
			Patients = new  std::set<Patient*>();
			Doctors = new std::set<Doctor*>();
			MedicalFiles = new std::set<MedicalFile*>();
			Departments = new  std::set<Department*>();
		}
		template <class T> std::set<T>* Set()
		{

		}

		template<> std::set<Patient*>* Set()
		{
			return Patients;
		};

		template<> std::set<Doctor*>* Set()
		{
			return Doctors;
		};

		template<> std::set<MedicalFile*>* Set()
		{
			return MedicalFiles;
		};

		template<> std::set<Department*>* Set()
		{
			return Departments;
		};
    };
}
