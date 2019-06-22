#include "Attribute.hpp"

Attribute::Attribute(int max, int min)
{
	if (max < min) { throw std::invalid_argument("min must be less than max"); }
	m_current = max;
	m_ceiling = max;
	m_max = max;
	m_floor = min;
	m_min = min;
}
Attribute::Attribute(int value, int max, int min)
{
	if (max < min) { throw std::invalid_argument("min must be less than max"); }
	m_current = value;
	m_ceiling = max;
	m_max = max;
	m_floor = min;
	m_min = min;
	bind();
}
void Attribute::reset()
{
	m_current = m_max;
	m_ceiling = m_max;
	m_floor = m_min;
}
void Attribute::resetBounds()
{
	m_ceiling = m_max;
	m_floor = m_min;
}
void Attribute::resetUpper() { m_ceiling = m_max; }
void Attribute::resetLower() { m_floor = m_min; }

void Attribute::toCeil() { m_current = m_ceiling; }
void Attribute::toFloor() { m_current = m_floor; }

int Attribute::getValue() { return m_current; }
int Attribute::getCeil() { return m_ceiling; }
int Attribute::getFloor() { return m_floor; }
int Attribute::getMax() { return m_max; }
int Attribute::getMin() { return m_min; }

void Attribute::setValue(int value) { m_current = value; bind(); }
void Attribute::setCeil(int ceil)
{
	if (ceil < m_floor) {
		throw std::invalid_argument("ceiling must be greater than floor"); }
	m_ceiling = ceil;
}
void Attribute::setFloor(int floor)
{
	if (floor > m_ceiling) {
		throw std::invalid_argument("floor must be less than ceiling"); }
	m_floor = floor;
}
void Attribute::setMax(int max)
{
	if (max < m_min) {
		throw std::invalid_argument("max must be greater than min"); }
	m_max = max;
}
void Attribute::setMin(int min)
{
	if (min > m_max) {
		throw std::invalid_argument("min must be less than max"); }
	m_min = min;
}

void Attribute::shiftUpperBounds(int amount)
{
	if (m_ceiling + amount < m_floor) {
		throw std::invalid_argument("ceiling must be greater than floor"); }
	if (m_max + amount < m_min) {
		throw std::invalid_argument("max must be greater than min"); }
	m_ceiling += amount;
	m_max += amount;
}
void Attribute::shiftLowerBounds(int amount)
{
	if (m_floor + amount > m_ceiling) {
		throw std::invalid_argument("floor must be less than ceiling"); }
	if (m_min + amount > m_max) {
		throw std::invalid_argument("min must be less than max"); }
	m_floor += amount;
	m_min += amount;
}

Attribute Attribute::operator-()
{
	Attribute temp = *this;
	std::swap(temp.m_floor, temp.m_ceiling);
	std::swap(temp.m_min, temp.m_max);
	temp.m_current = -temp.m_current;
	temp.m_ceiling = -temp.m_ceiling;
	temp.m_floor = -temp.m_floor;
	temp.m_max = -temp.m_max;
	temp.m_min = -temp.m_min;
	return temp;
}

Attribute& Attribute::operator++(void)
{
	++m_current;
	bind();
	return *this;
}
Attribute Attribute::operator++(int)
{
	Attribute temp = *this;
	++*this;
	return temp;
}
Attribute& Attribute::operator--(void)
{
	--m_current;
	bind();
	return *this;
}
Attribute Attribute::operator--(int)
{
	Attribute temp = *this;
	--*this;
	return temp;
}

Attribute Attribute::operator+(const int& num)
{
	Attribute temp = *this;
	temp.m_current += num;
	temp.bind();
	return temp;
}
Attribute Attribute::operator-(const int& num)
{
	return *this + -num;
}
Attribute Attribute::operator*(const int& num)
{
	Attribute temp = *this;
	temp.m_current *= num;
	temp.bind();
	return temp;
}
Attribute Attribute::operator/(const int& num)
{
	Attribute temp = *this;
	temp.m_current /= num;
	temp.bind();
	return temp;
}

void Attribute::operator+=(const int& other)
{
	m_current += other;
	bind();
}
void Attribute::operator-=(const int& other)
{
	m_current -= other;
	bind();
}
void Attribute::operator*=(const int& other)
{
	m_current *= other;
	bind();
}
void Attribute::operator/=(const int& other)
{
	m_current /= other;
	bind();
}

Attribute& Attribute::operator=(const int& other)
{
	m_current = other;
	bind();
	return *this;
}

bool Attribute::operator==(const Attribute& a)
{
	return m_current == a.m_current && m_ceiling == a.m_ceiling;
}
bool Attribute::operator!=(const Attribute& a)
{
	return m_current != a.m_current || m_ceiling != a.m_ceiling;
}

bool Attribute::operator==(const int& other) { return m_current == other; }
bool Attribute::operator!=(const int& other) { return m_current != other; }
bool Attribute::operator<=(const int& other) { return m_current <= other; }
bool Attribute::operator>=(const int& other) { return m_current >= other; }
bool Attribute::operator<(const int& other) { return m_current < other; }
bool Attribute::operator>(const int& other) { return m_current > other; }

void Attribute::bind()
{
	if (m_current > m_ceiling) { m_current = m_ceiling; }
	if (m_current < m_floor) { m_current = m_floor; }
}
