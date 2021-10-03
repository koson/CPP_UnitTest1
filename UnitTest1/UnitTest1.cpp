#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/MyClass.h"
#include <string>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestIsDouble)
	{
	public:
		
		TEST_METHOD(Test_NormalIntegerInput_Pass)
		{
			string name = "Test";
			char testDouble[] = "200";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_NormalIntegerNoDot_Pass)
		{
			string name = "Test";
			char testDouble[] = "2000";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_NormalfloatingWithExponent_Pass)
		{
			string name = "Test";
			char testDouble[] = "2e2";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingWithDot_Pass)
		{
			string name = "Test";
			char testDouble[] = "2.0";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingExponentWithDot_Pass)
		{
			string name = "Test";
			char testDouble[] = "2.0e2";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingWithDoubleDot_Fail)
		{
			string name = "Test";
			char testDouble[] = "2..0";
			MyClass mc(name);
			Assert::AreNotEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingWithDoubleExponent_Fail)
		{
			string name = "Test";
			char testDouble[] = "2ee2";
			MyClass mc(name);
			Assert::AreEqual(false, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingStartWithPlusSign_Pass)
		{
			string name = "Test";
			char testDouble[] = "+20";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingStartWithPlusSignAndDot_Pass)
		{
			string name = "Test";
			char testDouble[] = "+20.0";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}
		TEST_METHOD(Test_FloatingStartWithPlusSignAndDotExponent_Pass)
		{
			string name = "Test";
			char testDouble[] = "+20.0e2";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingStartWithMinusSign_Pass)
		{
			string name = "Test";
			char testDouble[] = "-20";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingStartWithMinusSignAndDot_Pass)
		{
			string name = "Test";
			char testDouble[] = "-20.0";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingStartWithMinusSignAndDotExponent_Pass)
		{
			string name = "Test";
			char testDouble[] = "-20.0e2";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingSpaceBeforeNumber_Pass)
		{
			string name = "Test";
			char testDouble[] = "  2.0";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingSpaceBetweenNumber_Fail)
		{
			string name = "Test";
			char testDouble[] = "2 0";
			MyClass mc(name);
			Assert::AreEqual(false, mc.isDouble(testDouble));
		}

		TEST_METHOD(Test_FloatingSpaceAfterNumber_Pass)
		{
			string name = "Test";
			char testDouble[] = "2.0 ";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}

	};
}
