#include "base.h"

bool Chacking_the_number(ary::dynamic_array<float>& value)
{
	for (size_t i = 0; i < value.size(); i++) {
		if (value[i] > Pi) {}
		else
			return false;
	}
	return true;
}