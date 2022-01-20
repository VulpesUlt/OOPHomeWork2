#include <iostream>
#include <cstdint>

static uint16_t StudentCount(0);

using namespace std;

// Task 1 =====================================================================

class Person
{
public:
	enum class gender
	{
		MALE, 
		FEMALE,
		NOTSET
	};

protected:
	std::string m_name;
	uint16_t m_age;
	uint16_t m_bodyWeight;
	gender m_gender;

	void getGender()
	{
		switch (m_gender)
		{
		case Person::gender::MALE: cout << "MALE";
			break;
		case Person::gender::FEMALE: cout << "FEMALE";
			break;
		default: cout << "NOTSET";
			break;
		}
	}
public:
	Person()
	{
		m_name = "NAME";
		m_age = 0;
		m_bodyWeight = 0;
		m_gender = gender::MALE;
	}

	void setWeight(uint16_t weight) { m_bodyWeight = weight; }
	void setAge(uint16_t age) { m_age = age; }
	void setName(std::string name) { m_name = name; }

};

class Student : public Person
{
private:
	uint16_t m_studYear;
public:
	Student(std::string name, uint16_t age, gender gen, uint16_t weight, uint16_t year)
	{
		m_name = name;
		m_age = age;
		m_gender = gen;
		m_bodyWeight = weight;
		m_studYear = year;
		StudentCount++;
	}

	~Student() { StudentCount--; }

	void setYear(uint16_t year) { m_studYear = year; }
	void incYear() { m_studYear++; }
	
	void getInfo()
	{
		cout << "Name:" << m_name << endl;
		cout << "Age:" << m_age << endl;
		cout << "Gender:";
		Person::getGender();
		cout << endl << "Weight:" << m_bodyWeight << endl;
		cout << "Year:" << m_studYear << endl << endl;
	
	}
};

// Task 2 =====================================================================

class Fruit
{
protected:
	string m_name;
	string m_color;
public:
	string getName() { return m_name; }
	string getColor() { return m_color; }
};

class Apple : public Fruit
{
public:
	Apple(string color)
	{
		m_name = "apple";
		m_color = color;
	}
};

class Banana : public Fruit
{
public:
	Banana()
	{
		m_name = "banana";
		m_color = "yellow";
	}
};

class GrannySmith : public Apple
{
public:
	GrannySmith() : Apple("green")
	{
		m_name = "GrannySmith apple";
	}
};

// Task 3 =====================================================================

/*
Class game 
Русский текст
*/


int main()
{
	
	// Task 1
	Student Vas("Vasily", 18, Person::gender::MALE, 76, 1);
	Student Petr("Petr", 21, Person::gender::MALE, 82, 3);
	Student Kate("Kate", 20, Person::gender::FEMALE, 53, 2);
	Vas.getInfo();
	Petr.getInfo();
	Kate.getInfo();

	// Task 2
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}