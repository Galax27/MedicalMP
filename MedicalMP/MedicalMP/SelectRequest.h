#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	template <class T>
	class SelectRequest : public BaseRequest<T>
	{
	private:
		std::function<bool(T)> filter;
		std::set<T>* results;
	
	public:
		SelectRequest(std::set<T>* set, std::function<bool(T)> f) : BaseRequest(set)
		{
			this->filter = f;
			results = new std::set<T>();
		}

		void Execute()
		{
			results->clear();
			std::set<T>::iterator it = Set->begin();
				
			while (it != Set->end())
			{
				it = std::find_if(it, Set->end(), filter);
				if (it != Set->end())
				{
					results->insert(*it);
					it++;
				}
			}
		}

		std::set<T>* GetResults()
		{
			return results;
		}
	};
}