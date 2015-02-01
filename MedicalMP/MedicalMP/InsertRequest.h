#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	template <class T>
	class InsertRequest: public BaseRequest<T>
	{
	private:
		BaseEntity* _element;
		
		void OnExecute()
		{
			Set->insert(_element);
		}

	public:
		InsertRequest(std::set<T>* set, T element) : BaseRequest<T>(set)
		{
			_element = element;
		}
	};
}