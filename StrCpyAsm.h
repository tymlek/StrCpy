// StrCpyAsm.h

extern "C" {
	long str_length_asm(char* stringPtr);
	void str_cpy_asm(char* sourceBegin, char* sourceEnd, char* targetPtr);
}
