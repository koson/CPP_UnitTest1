#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/MyClass.h"
#include <string>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string name = "Test";
			char testDouble[] = "2.2";
			MyClass mc(name);
			Assert::AreEqual(true, mc.isDouble(testDouble));
		}
	};
}
