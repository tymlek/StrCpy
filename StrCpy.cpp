// StrCpy.cpp

#include <iostream>
#include <chrono>
#include <stdexcept>
#include "StrCpyAsm.h"
#include "StrCpyC.h"

//-----------------------------------------------------------------------------

int main()
{
	char* sourceStr = "This is an orginal text.";
	const long strSize = 24;
	const unsigned loopSize = 1000000;
	char targetStr1[strSize + 1];
	char targetStr2[strSize + 1];
	auto t0 = std::chrono::steady_clock::now();
	auto t1 = std::chrono::steady_clock::now();

	try {
		// Test the Assembly language functions
		std::cout<<"Please wait...\n";

		t0 = std::chrono::steady_clock::now();

		for (auto i = 0; i != loopSize; ++i)
			str_cpy_asm(sourceStr,(sourceStr + str_length_asm(sourceStr) + 1),targetStr1);

		t1 = std::chrono::steady_clock::now();

		std::cout<<"Elpased ASM time: "
				<<std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
				<<"ms.\n"
				<<targetStr1<<std::endl;

		// Test the C++ language functions
		std::cout<<"Please wait...\n";

		t0 = std::chrono::steady_clock::now();

		for (auto i = 0; i != loopSize; ++i)
			str_cpy_c(sourceStr,(sourceStr + str_length_c(sourceStr) + 1),targetStr2);

		t1 = std::chrono::steady_clock::now();

		std::cout<<"Elpased C++ time: "
				<<std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
				<<"ms.\n"
				<<targetStr2<<std::endl;
	}
	catch (std::exception& e) {
		std::cerr<<"Error:\n"
				<<e.what();
		return 1;
	}
	catch (...) {
		std::cerr<<"Error";
		return 2;
	}

	return 0;
}
