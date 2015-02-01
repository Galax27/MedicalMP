#include "stdafx.h"

namespace MedicalMP
{
	BaseEntity::BaseEntity(int id)
	{
		_id = id;
	}

	bool BaseEntity::operator==(const BaseEntity& other) {
		return this->_id == other._id;
	}
}