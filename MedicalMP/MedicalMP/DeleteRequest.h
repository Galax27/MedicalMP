#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	template <class T>
	class DeleteRequest : public BaseRequest<T>
	{
	private:
		std::function<bool(T)> filter;

	public:
		DeleteRequest(std::set<T>* set, std::function<bool(T)> f) : BaseRequest(set)
		{
			this->filter = f;
		}

		void Execute()
		{
			std::set<T>::iterator it = Set->begin();

			while (it != Set->end())
			{
				it = std::find_if(it, Set->end(), filter);
				if (it != Set->end())
				{
					it = Set->erase(it);
				}
			}
		}
	};
}