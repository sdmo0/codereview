// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
	static void BarSeparatorTest() {
		TypingMachine tm;
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}

	static void HomeKeyTest() {
		TypingMachine tm;
		std::string str("1234567");
		std::string ans("|1234567");

		for (int i = 0; i < static_cast<int> (str.size()); i++) {
			tm.TypeKey(str[i]);
		}

		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), ans);
	}

	static void EndKeyTest() {
		TypingMachine tm;
		std::string str("1234567");
		std::string ans("1234567|");

		for (int i = 0; i < static_cast<int> (str.size()); i++) {
			tm.TypeKey(str[i]);
		}

		tm.HomeKey();
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), ans);
	}

	static void LeftKeyTest() {
		TypingMachine tm;
		std::string str("1234567");
		std::string ans1("123456|7");
		std::string ans2("|1234567");

		for (int i = 0; i < static_cast<int> (str.size()); i++) {
			tm.TypeKey(str[i]);
		}

		tm.EndKey();
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), ans1);

		tm.HomeKey();
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), ans2);
	}

	static void RightKeyTest() {
		TypingMachine tm;
		std::string str("1234567");
		std::string ans1("1|234567");
		std::string ans2("1234567|");

		for (int i = 0; i < static_cast<int> (str.size()); i++) {
			tm.TypeKey(str[i]);
		}

		tm.HomeKey();
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), ans1);

		tm.EndKey();
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), ans2);
	}

	static void TypeKeyTest() {
		TypingMachine tm;
		std::string str("1234567");
		std::string ans("1234567");

		for (int i = 0; i < static_cast<int> (str.size()); i++) {
			tm.TypeKey(str[i]);
		}

		ASSERT_EQ(tm.Print(0), ans);

		ASSERT_EQ(tm.TypeKey(0x1F), false);
		ASSERT_EQ(tm.TypeKey(0x80), false);

		for (int i = 0; i < 100; i++) {
			tm.TypeKey('@');
		}
		ASSERT_EQ(tm.TypeKey('@'), false);
	}

	static void EraseKeyTest() {
		TypingMachine tm;
		std::string str("1234567");
		std::string ans("1234|7");

		for (int i = 0; i < static_cast<int> (str.size()); i++) {
			tm.TypeKey(str[i]);
		}

		tm.EndKey();
		tm.LeftKey();
		tm.EraseKey();
		tm.EraseKey();

		ASSERT_EQ(tm.Print('|'), ans);

		tm.HomeKey();
		ASSERT_EQ(tm.EraseKey(), false);
	}


public:
	static void RunTest() {
		BarSeparatorTest();
		HomeKeyTest();
		EndKeyTest();
		LeftKeyTest();
		RightKeyTest();
		TypeKeyTest();
		EraseKeyTest();
	}
};

class SomeOtherTestSuite
{
private:

public:
	static void RunTest() {
		// add more..
	}
};

void TypingMachineTest() {
	TmConstructorTestSuite::RunTest();
	// add more..
}
