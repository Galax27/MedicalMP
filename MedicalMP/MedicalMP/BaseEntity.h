#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	class BaseEntity
	{
	private:
		int _id;
	public:
		BaseEntity(int id);
		virtual ~BaseEntity() = 0;
		bool BaseEntity::operator==(const BaseEntity& other);

		int GetId();
	};

	inline BaseEntity::~BaseEntity() {}
}