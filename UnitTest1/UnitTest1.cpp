#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.2/master.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:

		TEST_METHOD(TestA_func_n1)
		{
			double t = A_func(0.5, 1, 0.5);
			Assert::AreEqual(0.5 / 24, t, 1e-12);
		}

		TEST_METHOD(TestA_func_n2)
		{
			double a1 = 0.5 * 0.5 * 0.5 / 6;
			double t = A_func(0.5, 2, a1);
			Assert::AreEqual(3 * pow(0.5, 5) / 40, t, 1e-12);
		}

		TEST_METHOD(TestA_void_n1)
		{
			double a = 0.5;
			A_void(0.5, 1, a);
			Assert::AreEqual(0.5 / 24, a, 1e-12);
		}

		TEST_METHOD(TestS_func_asin)
		{
			int n = 0;
			double t = S_func(0.5, 1e-10, n);
			Assert::AreEqual(asin(0.5), t, 1e-8);
			Assert::AreEqual(13, n);
		}

		TEST_METHOD(TestS_void_asin)
		{
			int n = 0;
			double s = 0;
			S_void(0.5, 1e-10, n, s);
			Assert::AreEqual(asin(0.5), s, 1e-8);
			Assert::AreEqual(13, n);
		}

	};
}