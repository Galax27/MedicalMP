#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	template <class T>
	class BaseRequest
	{
		protected:
			std::set<T>* Set;
		public:
			BaseRequest(std::set<T> *set)
			{
				this->Set = set;
			}

			virtual void Execute() = 0;
			
			virtual std::set<T>* GetResults()
			{
				return Set;
			};
	};
}