#ifndef ATTRIBUTE_HPP_INCLUDE
#define ATTRIBUTE_HPP_INCLUDE

#include <iostream>

class Attribute
{
	public:
		Attribute(int = 10, int = 0);
		Attribute(int, int, int);

		void reset(void);
		void resetBounds(void);
		void resetUpper(void);
		void resetLower(void);

		void toCeil(void);
		void toFloor(void);

		int getValue(void) const;
		int getCeil(void) const;
		int getFloor(void) const;
		int getMax(void) const;
		int getMin(void) const;

		void setValue(int);
		void setCeil(int);
		void setFloor(int);
		void setMax(int);
		void setMin(int);

		void shiftUpperBounds(int = 1);
		void shiftLowerBounds(int);
		
		Attribute operator-(void) const;
		Attribute& operator++(void);
		Attribute operator++(int);
		Attribute& operator--(void);
		Attribute operator--(int);

		Attribute operator+(const int&) const;
		Attribute operator-(const int&) const;
		Attribute operator*(const int&) const;
		Attribute operator/(const int&) const;

		void operator+=(const int&);
		void operator-=(const int&);
		void operator*=(const int&);
		void operator/=(const int&);

		bool operator==(const Attribute&) const;
		bool operator!=(const Attribute&) const;

		bool operator==(const int&) const;
		bool operator!=(const int&) const;
		bool operator<=(const int&) const;
		bool operator>=(const int&) const;
		bool operator<(const int&) const;
		bool operator>(const int&) const;

		friend std::ostream& operator<<(std::ostream& out, const Attribute& a)
		{
			out << a.m_min << '|' << a.m_floor << " : " << a.m_current
				<< " : " << a.m_ceiling << '|' << a.m_max;	
			return out;
		}

	private:
		int m_current;
		int m_ceiling;
		int m_floor;
		int m_max;
		int m_min;

		void bind(void);
};

#endif
