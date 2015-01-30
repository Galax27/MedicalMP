#pragma once

// Constants
static unsigned int k_NumThreads(2);
static unsigned int k_MasterThread(0);

// OpenMP
#include <omp.h>

// Standard
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <functional> 
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <unordered_set>
#include <chrono>

// Enums
#include "Disease.h"
#include "Grade.h"

// Models
#include "BaseEntity.h"
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include "MedicalFile.h"
#include "Department.h"

// Database
#include "Context.h"

//Requests
#include "BaseRequest.h"
#include "SelectRequest.h"
#include "DeleteRequest.h"
#include "InsertRequest.h"
#include "RequestsContainer.h"

#include "SampleData.h"
#include "SampleRequests.h"

// Misc
#include "Logger.h"
#include "Utils.h"
#include "System.h"