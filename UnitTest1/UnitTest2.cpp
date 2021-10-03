#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/MyClass.h"
#include <string>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestIsNumber)
	{
	public:

		TEST_METHOD(Test_NormalIntegerInput_Pass)
		{
			string name = "Test";
			char testNumber[] = "200";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isNumber(testNumber));
		}

		TEST_METHOD(Test_NumberWithDot_Fail)
		{
			string name = "Test";
			char testDouble[] = "2.0";
			MyClass mc(name);
			Assert::AreEqual(false, mc.isNumber(testDouble));
		}
		TEST_METHOD(Test_NumberWithExponent_Fail)
		{
			string name = "Test";
			char testDouble[] = "2e0";
			MyClass mc(name);
			Assert::AreEqual(false, mc.isNumber(testDouble));
		}



	};
}
