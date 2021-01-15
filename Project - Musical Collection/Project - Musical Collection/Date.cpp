#include "Date.h"
#include <string>

Date::Date()
{
	this->year = 0;
	this->month = 0;
	this->day = 0;
}

Date::Date(int newYear, int newMonth, int newDay)
{
	this->year = newYear;
	this->month = newMonth;
	this->day = newDay;
}

Date& Date::operator=(const Date& other)
{
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;

	return *this;
}

bool Date::operator==(const Date& other)
{
	return (this->year == other.year
		&& this->month == other.month
		&& this->day == other.day);
}

bool Date::operator<(const Date& other)
{
	if (this->year > other.year) return false;
	if (this->month > other.month) return false;
	if (this->day > other.day) return false;
	return true;
}

bool Date::operator>(const Date& other)
{
	if (this->year < other.year) return false;
	if (this->month < other.month) return false;
	if (this->day < other.day) return false;
	return true;
}

std::ostream& operator<<(std::ostream& out, const Date& current)
{
	out << current.year << "-" << current.month << "-" << current.day;
	return out;
}

std::istream& operator>>(std::istream& in, Date& current)
{
	bool correct = false;
	int _year, _month, _day;
	do
	{
		_year = 0;
		_month = 0;
		_day = 0;
		std::string date;
		std::cout << "YY-MM-DD: ";
		
		std::getline(in, date);

		std::string year, month, day;
		int index = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = index; j < date.length(); j++)
			{
				if (date[j] == '-')
				{
					index = j + 1;
					break;
				}
				if (i == 0) year = year + date[j];
				else if (i == 1) month = month + date[j];
				else day = day + date[j];
			}
		}

		if (year.length() == 4 &&
			(month.length() == 2 || month.length() == 1) &&
			(day.length() == 1 || day.length() == 2))
		{
			for (int i = 0; i < year.length(); i++) _year = _year * 10 + (year[i] - '0');
			for (int i = 0; i < month.length(); i++) _month = _month * 10 + (month[i] - '0');
			for (int i = 0; i < day.length(); i++) _day = _day * 10 + (day[i] - '0');
		}

		if (_year > 999 && _year < 10000 &&
			_month > 0 && _month < 13 &&
			_day > 0 && _day < 32) correct = true;
		else std::cout << "Wrong format." << std::endl;

	} while (!correct);

	current.year = _year;
	current.month = _month;
	current.day = _day;

	return in;
}

bool operator==(const Date& left, const Date& right)
{
	if (left.year == right.year
		&& left.month == right.month
		&& left.day == right.day)
	{
		return true;
	}
	return false;
}

bool operator<(const Date& curr, const Date& other)
{
	if (curr.year > other.year) return false;
	if (curr.month > other.month) return false;
	if (curr.day > other.day) return false;
	return true;
}