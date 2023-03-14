#pragma once
#include<iostream>
#include<tchar.h>

#ifdef UNICODE
using fstring = std::wstring;
#else
using fstring = std::string;
#endif // UNICODE

#define DLLEXPORT __declspec(dllexport)

class DLLEXPORT CStringlib final 
{
public:
	static fstring str2fstr(const std::string& str);
	static std::string fstr2str(const fstring& fstr);

public:
	CStringlib() = delete;
	CStringlib& operator=(const CStringlib&) = delete;
	CStringlib(const CStringlib&) = delete;
	~CStringlib() = delete;
};
