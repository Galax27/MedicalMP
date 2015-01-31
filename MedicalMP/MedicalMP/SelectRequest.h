#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	template <class T>
	class SelectRequest : public BaseRequest<T>
	{
	private:
		std::function<bool(T)> _filter;
		std::set<T>* _results;
	
		void OnExecute()
		{
			_results->clear();
			std::set<T>::iterator it = Set->begin();

			while (it != Set->end())
			{
				it = std::find_if(it, Set->end(), _filter);
				if (it != Set->end())
				{
					_results->insert(*it);
					it++;
				}
			}
		}

	public:
		SelectRequest(std::set<T>* set, std::function<bool(T)> f) : BaseRequest(set)
		{
			_filter = f;
			_results = new std::set<T>();
		}

		std::set<T>* GetResults()
		{
			return _results;
		}
	};
}