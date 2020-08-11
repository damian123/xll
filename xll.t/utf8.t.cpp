﻿// utf8.t.cpp test utf8.h
#include <cassert>
#include <memory>
#include "../xll/utf8.h"

using std::unique_ptr;
using utf8::mbstowcs;
using utf8::wcstombs;

int test_utf8 = []() {
	{
		char s[] = "abc";
		unique_ptr<wchar_t> ws(mbstowcs(s));
		assert(0 == wcsncmp(ws.get() + 1, L"abc", 3));
	}
	{
		char s[] = "abc";
		unique_ptr<wchar_t> ws(mbstowcs(s));
		assert(ws.get()[0] == 3);
		assert(0 == wcsncmp(ws.get() + 1, L"abc", 3));
	}
	/*
	{
		char s[] = "哈"; // ha
		wchar_t ha[] = L"哈";
		assert(3 == strlen(s));
		wchar_t* ws = mbstowcs(s); // unique_ptr!!!
		assert(0 == wcsncmp(ws, ha, 1));
		free(ws);
	}
	*/
	{
		wchar_t ws[] = L"abc";
		unique_ptr<char> s(wcstombs(ws));
		assert(0 == strncmp(s.get() + 1, "abc", 3));
	}
	{
		wchar_t ws[] = L"哈";
		auto s = wcstombs(ws);
		assert(3 == s[0]);
		assert(0 == strncmp(s + 1, "哈", 3));
		free(s);
	}

	return 0;
}();
