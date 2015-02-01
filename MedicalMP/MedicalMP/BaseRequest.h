#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	template <class T>
	class BaseRequest
	{
		
		private:
			double _elapsedTime;
		
		protected:
			std::set<T>* Set;
			virtual void OnExecute() = 0;
		
		public:
			BaseRequest(std::set<T> *set)
			{
				this->Set = set;
			}

			void Execute()
			{
				auto timeStart = clock();

				OnExecute();

				auto timeStop = clock();
				Utils::GetElapsedTime(timeStart, timeStop, _elapsedTime);
			}
			
			virtual std::set<T>* GetResults()
			{
				return Set;
			};

			double GetElapsedTime()
			{
				return _elapsedTime;
			}
	};
}