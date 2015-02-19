// StrCpyC.cpp

#include "StrCpyC.h"

// Calculates string's lenght and returns the result
long str_length_c(char* stringPtr)
{
	long strSize = 0;
	long offset = 0;

	while (*(stringPtr + offset) != '\0')
	{
		++strSize;
		++offset;
	}

	return strSize;
}

// Copies a string from source to target.
void str_cpy_c(char* sourceBegin, char* sourceEnd, char* targetPtr)
{
	unsigned offset = 0; 
	for (char* p = sourceBegin; p != sourceEnd; ++p) {
		*(targetPtr + offset) = *p;
		++offset; 
	}
}
