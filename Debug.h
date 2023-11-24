#pragma once
#include <Windows.h>
#include <stdio.h>

static int VDebugPrintF(const char* format, va_list args)
{
	const UINT32 MAX_CHARS = 1024;
	static char s_buffer[MAX_CHARS];

	 //Use _vsnprintf_s for safer handling
    int charsWritten = _vsnprintf_s(s_buffer, MAX_CHARS, _TRUNCATE, format, args);

    //Ensure null-termination
    s_buffer[MAX_CHARS - 1] = '\0';

    OutputDebugStringA(s_buffer);

	return charsWritten;
}

static int DebugPrintF(const char* format, ...)
{
	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);
	va_end(argList);

	return charsWritten;
}