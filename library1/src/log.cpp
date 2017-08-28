#include "library1/log.h"
#include <iostream>

namespace library1
{
	void Log::write(const std::string& text)
	{
		std::cout << text << std::endl;
	}
}