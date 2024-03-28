#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(SortEmployeesAlphabetically)
        {
           
            vector<string> surnames = { "Smith", "Johnson", "Williams", "Brown", "Jones" };
            vector<string> initials = { "J.D.", "R.A.", "A.L.", "T.M.", "M.B." };
            vector<string> positions = { "Software Engineer", "Accountant", "Salesperson", "Manager", "Designer" };
            vector<int> hire_years = { 2018, 2015, 2020, 2012, 2019 };
            vector<double> salaries = { 50000, 60000, 45000, 75000, 55000 };

            
            sortEmployees();

           
            Assert::AreEqual<string>(surnames[0], "Smith");
            Assert::AreEqual<string>(surnames[1], "Johnson");
            Assert::AreEqual<string>(surnames[2], "Williams");
            Assert::AreEqual<string>(surnames[3], "Brown");
            Assert::AreEqual<string>(surnames[4], "Jones");
        }
    
	};
}
