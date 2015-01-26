#pragma once

// Constants
static unsigned int k_NumThreads(10);
static unsigned int k_MasterThread(1001);

// OpenMP
#include <omp.h>

// Standard
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <functional> 
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <iterator>
#include <unordered_set>

// Enums
#include "Disease.h"
#include "Grade.h"

// Models
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include "MedicalFile.h"
#include "Department.h"

// Database
#include "Context.h"
#include "Seed.h"

// Misc
#include "Logger.h"
#include "Utils.h"
#include "System.h"