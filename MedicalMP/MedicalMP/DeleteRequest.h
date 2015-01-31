#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	template <class T>
	class DeleteRequest : public BaseRequest<T>
	{
	private:
		std::function<bool(T)> _filter;

		void OnExecute()
		{
			std::set<T>::iterator it = Set->begin();

			while (it != Set->end())
			{
				it = std::find_if(it, Set->end(), _filter);
				if (it != Set->end())
				{
					it = Set->erase(it);
				}
			}
		}

	public:
		DeleteRequest(std::set<T>* set, std::function<bool(T)> f) : BaseRequest(set)
		{
			_filter = f;
		}
	};
}