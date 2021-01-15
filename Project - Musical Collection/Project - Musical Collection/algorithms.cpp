#include "algorithms.h"
#include <string>
#include <algorithm>

int validateStringToInt(std::string str)
{
	int result = 0;
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it >= '0' && *it <= '9')
		{
			result = result * 10 + *it - '0';
		}
		else return -1;
	}
	return result;
}
std::string toLower(const std::string& str)
{
	std::string lower = str;
	std::transform(lower.begin(), lower.end(), lower.begin(),
		[](unsigned char c) { return std::tolower(c); });

	return lower;
}

void clearScreen()
{
	system("CLS");
}
