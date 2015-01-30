#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	template <class T>
	class InsertRequest: public BaseRequest<T>
	{
	private:
		BaseEntity* element;

	public:
		InsertRequest(std::set<T>* set, T element) : BaseRequest<T>(set)
		{
			this->element = element;
		}

		void Execute()
		{
			Set->insert(element);
		}
	};
}