#include "stdafx.h"

namespace MedicalMP
{
	void SampleData::Seed(Context* context)
	{
		SeedDepartments(context);
		SeedDoctors(context);
		SeedPatients(context);
		SeedMedicalFiles(context);
	}


	void SampleData::SeedDepartments(Context* context)
	{
		context->Departments->insert(new Department(1, "Plastic Surgery"));
		context->Departments->insert(new Department(2, "Scientific"));
		context->Departments->insert(new Department(3, "Innuendo"));
		context->Departments->insert(new Department(4, "Second floor"));
		context->Departments->insert(new Department(5, "Michigan Emergency"));
		context->Departments->insert(new Department(6, "First floor"));
		context->Departments->insert(new Department(7, "Third floor"));
		context->Departments->insert(new Department(8, "Fourth floor"));
		context->Departments->insert(new Department(9, "Fifth floor"));
		context->Departments->insert(new Department(10, "Illinois Mental"));

		context->Departments->insert(new Department(1, "Chirurgie"));
		context->Departments->insert(new Department(2, "Cardiologie"));
		context->Departments->insert(new Department(3, "Hematologie"));
		context->Departments->insert(new Department(4, "Neurologie"));
		context->Departments->insert(new Department(5, "Ortopedie"));
		context->Departments->insert(new Department(6, "Oftalmologie"));
	}

	void SampleData::SeedDoctors(Context* context)
	{
		context->Doctors->insert(new Doctor(1, 1, 33, Grade::Junior, "Remus", "Nicusor"));
		context->Doctors->insert(new Doctor(2, 2, 35, Grade::Junior, "Horia", "Octavian"));
		context->Doctors->insert(new Doctor(3, 2, 36, Grade::Middle, "Ilie", "Cristi"));
		context->Doctors->insert(new Doctor(4, 2, 38, Grade::Junior, "Ciprian", "Matei"));
		context->Doctors->insert(new Doctor(5, 1, 25, Grade::Entry, "Aurel", "Cristi"));
		context->Doctors->insert(new Doctor(6, 3, 44, Grade::Middle, "Cezar", "David"));
		context->Doctors->insert(new Doctor(7, 3, 40, Grade::Middle, "Dorin", "Stan"));
		context->Doctors->insert(new Doctor(8, 1, 41, Grade::Middle, "Iuliu", "Iosif"));
		context->Doctors->insert(new Doctor(9, 4, 57, Grade::Senior, "Mitica", "Costache"));
		context->Doctors->insert(new Doctor(10, 4, 30, Grade::Junior, "Costin", "Costica"));

		context->Doctors->insert(new Doctor(11, 4, 63, Grade::Senior, "Pompiliu", "Petre"));
		context->Doctors->insert(new Doctor(12, 4, 65, Grade::Senior, "Remus", "Ion"));
		context->Doctors->insert(new Doctor(13, 5, 56, Grade::Senior, "Andrei", "Iuliu"));
		context->Doctors->insert(new Doctor(14, 5, 58, Grade::Senior, "Serafim", "Eduard"));
		context->Doctors->insert(new Doctor(15, 6, 55, Grade::Senior, "Cristian", "Emilian"));
		context->Doctors->insert(new Doctor(16, 6, 54, Grade::Middle, "Pompiliu", "Constantin"));
		context->Doctors->insert(new Doctor(17, 6, 30, Grade::Junior, "Tiberiu", "Timotei"));
		context->Doctors->insert(new Doctor(18, 7, 31, Grade::Junior, "Paul", "Costache"));
		context->Doctors->insert(new Doctor(19, 7, 37, Grade::Junior, "Octavian", "Adrian"));
		context->Doctors->insert(new Doctor(20, 7, 30, Grade::Junior, "Atanase", "Dan"));

		context->Doctors->insert(new Doctor(100, 3, 47, Middle, "Augustin", "Cimbru"));
		context->Doctors->insert(new Doctor(101, 5, 39, Middle, "Remus", "Petala"));
		context->Doctors->insert(new Doctor(102, 1, 50, Middle, "Stefan", "Petrescu"));
		context->Doctors->insert(new Doctor(103, 2, 60, Senior, "Marcela", "Horia"));
		context->Doctors->insert(new Doctor(104, 6, 32, Junior, "Anton", "Balauta"));
		context->Doctors->insert(new Doctor(105, 4, 55, Senior, "Neli", "Spataru"));
	}

	void SampleData::SeedPatients(Context* context)
	{
		for (int i = 1; i < 500; i++)
		{
			context->Patients->insert(PatientGenerator::Generate(i));
		}
	}

	void SampleData::SeedMedicalFiles(Context* context)
	{
		tm time;

		time.tm_year = 2000;
		time.tm_mon = 5;
		time.tm_mday = 30;
		context->MedicalFiles->insert(new MedicalFile(1, 1, 1, time, Disease::Acne));

		time.tm_year = 2001;
		time.tm_mon = 9;
		time.tm_mday = 10;
		context->MedicalFiles->insert(new MedicalFile(2, 2, 1, time, Disease::BoneCancer));

		time.tm_year = 2005;
		time.tm_mon = 6;
		time.tm_mday = 22;
		context->MedicalFiles->insert(new MedicalFile(3, 12, 5, time, Disease::RenalFatigue));

		time.tm_year = 2010;
		time.tm_mon = 8;
		time.tm_mday = 14;
		context->MedicalFiles->insert(new MedicalFile(4, 4, 5, time, Disease::Deafness));

		time.tm_year = 2004;
		time.tm_mon = 3;
		time.tm_mday = 3;
		context->MedicalFiles->insert(new MedicalFile(5, 4, 5, time, Disease::Depression));

		time.tm_year = 2001;
		time.tm_mon = 5;
		time.tm_mday = 5;
		context->MedicalFiles->insert(new MedicalFile(6, 5, 6, time, Disease::DrugAbuse));

		time.tm_year = 2002;
		time.tm_mon = 11;
		time.tm_mday = 30;
		context->MedicalFiles->insert(new MedicalFile(7, 6, 5, time, Disease::EatingDisorder));

		time.tm_year = 2002;
		time.tm_mon = 11;
		time.tm_mday = 29;
		context->MedicalFiles->insert(new MedicalFile(8, 7, 2, time, Disease::Allergy));

		time.tm_year = 2003;
		time.tm_mon = 7;
		time.tm_mday = 15;
		context->MedicalFiles->insert(new MedicalFile(9, 7, 10, time, Disease::BackPain));

		time.tm_year = 2003;
		time.tm_mon = 7;
		time.tm_mday = 15;
		context->MedicalFiles->insert(new MedicalFile(10, 7, 19, time, Disease::Allzheimer));

		time.tm_year = 2005;
		time.tm_mon = 9;
		time.tm_mday = 16;
		context->MedicalFiles->insert(new MedicalFile(11, 10, 4, time, Disease::Allzheimer));

		time.tm_year = 2009;
		time.tm_mon = 10;
		time.tm_mday = 23;
		context->MedicalFiles->insert(new MedicalFile(12, 10, 5, time, Disease::EatingDisorder));

		time.tm_year = 2005;
		time.tm_mon = 10;
		time.tm_mday = 18;
		context->MedicalFiles->insert(new MedicalFile(13, 10, 11, time, Disease::Allergy));

		time.tm_year = 2007;
		time.tm_mon = 10;
		time.tm_mday = 13;
		context->MedicalFiles->insert(new MedicalFile(14, 11, 6, time, Disease::Scabies));

		time.tm_year = 2001;
		time.tm_mon = 4;
		time.tm_mday = 13;
		context->MedicalFiles->insert(new MedicalFile(15, 17, 7, time, Disease::Smallpox));

		time.tm_year = 2001;
		time.tm_mon = 4;
		time.tm_mday = 12;
		context->MedicalFiles->insert(new MedicalFile(16, 21, 8, time, Disease::Allergy));

		time.tm_year = 2000;
		time.tm_mon = 5;
		time.tm_mday = 5;
		context->MedicalFiles->insert(new MedicalFile(17, 11, 4, time, Disease::Tuberculosis));

		time.tm_year = 2005;
		time.tm_mon = 9;
		time.tm_mday = 4;
		context->MedicalFiles->insert(new MedicalFile(18, 13, 4, time, Disease::Tuberculosis));

		time.tm_year = 2005;
		time.tm_mon = 9;
		time.tm_mday = 6;
		context->MedicalFiles->insert(new MedicalFile(19, 15, 1, time, Disease::Obesity));

		time.tm_year = 2010;
		time.tm_mon = 12;
		time.tm_mday = 22;
		context->MedicalFiles->insert(new MedicalFile(20, 16, 3, time, Disease::Leukemia));

		time.tm_year = 2010;
		time.tm_mon = 12;
		time.tm_mday = 20;
		context->MedicalFiles->insert(new MedicalFile(21, 16, 3, time, Disease::Headache));

		time.tm_year = 2009;
		time.tm_mon = 4;
		time.tm_mday = 17;
		context->MedicalFiles->insert(new MedicalFile(22, 19, 12, time, Disease::HeelPain));

		time.tm_year = 2010;
		time.tm_mon = 8;
		time.tm_mday = 5;
		context->MedicalFiles->insert(new MedicalFile(23, 14, 12, time, Disease::Vertigo));

		time.tm_year = 2010;
		time.tm_mon = 5;
		time.tm_mday = 5;
		context->MedicalFiles->insert(new MedicalFile(24, 14, 12, time, Disease::Allergy));

		time.tm_year = 2010;
		time.tm_mon = 4;
		time.tm_mday = 1;
		context->MedicalFiles->insert(new MedicalFile(25, 12, 12, time, Disease::Gonorrhea));

		time.tm_year = 2003; time.tm_mon = 10; time.tm_mday = 25;
		context->MedicalFiles->insert(new MedicalFile(100, 100, 1, time, Cholesterol));
		time.tm_year = 2007; time.tm_mon = 11; time.tm_mday = 12;
		context->MedicalFiles->insert(new MedicalFile(101, 101, 1, time, EatingDisorder));
		time.tm_year = 2004; time.tm_mon = 5; time.tm_mday = 16;
		context->MedicalFiles->insert(new MedicalFile(102, 102, 1, time, Headache));
		time.tm_year = 2000; time.tm_mon = 8; time.tm_mday = 21;
		context->MedicalFiles->insert(new MedicalFile(103, 103, 1, time, Tuberculosis));
		time.tm_year = 2008; time.tm_mon = 3; time.tm_mday = 15;
		context->MedicalFiles->insert(new MedicalFile(104, 104, 1, time, Infertility));
		time.tm_year = 2011; time.tm_mon = 11; time.tm_mday = 12;
		context->MedicalFiles->insert(new MedicalFile(105, 105, 1, time, Allergy));
		time.tm_year = 2012; time.tm_mon = 4; time.tm_mday = 7;
		context->MedicalFiles->insert(new MedicalFile(106, 106, 1, time, Pneumonia));
		time.tm_year = 2004; time.tm_mon = 6; time.tm_mday = 8;
		context->MedicalFiles->insert(new MedicalFile(107, 107, 1, time, Obesity));
		time.tm_year = 2006; time.tm_mon = 3; time.tm_mday = 27;
		context->MedicalFiles->insert(new MedicalFile(108, 108, 1, time, LungCancer));
		time.tm_year = 2003; time.tm_mon = 10; time.tm_mday = 19;
		context->MedicalFiles->insert(new MedicalFile(109, 109, 1, time, Migraine));
		time.tm_year = 2008; time.tm_mon = 5; time.tm_mday = 12;
		context->MedicalFiles->insert(new MedicalFile(110, 101, 1, time, EarProblems));
	}
}