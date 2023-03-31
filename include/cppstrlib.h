#pragma once
#include<iostream>
#include<tchar.h>

#ifdef UNICODE
using fstring = std::wstring;
#else
using fstring = std::string;
#endif // UNICODE

enum class OSType {
	OS_MIN = 0,		//never use
	OS_WIN = 1,
	OS_UNIX,
	OS_LINUX,
	OS_MAC,
	OS_ANDROID,
	OS_FREEBSD,
	OS_MAX,		//never use
};

#define DLLEXPORT __declspec(dllexport)

class DLLEXPORT CStringlib final 
{
public:
	//Some functions about conversion
	static fstring str2fstr(const std::string& str);
	static std::string fstr2str(const fstring& fstr);

public:
	//Some functions about paths

	/* 
		'a\\b\\c' -> 'a/b/c'
		'a/b/c' -> 'a\\b\\c'
	*/
	static fstring path_SystemSlashFormat(const fstring& fstr, OSType type = OSType::OS_MIN);
	static std::string path_SystemSlashFormatA(const std::string& str, OSType type = OSType::OS_MIN);
	
	/*
		'a/b/c' -> 'a/b/'
	*/
	static fstring path_GetDir(const fstring& path);
	static std::string path_GetDirA(const std::string& path);

public:
	//Some functions about files

public:
	//Some functions about math

public:
	//Some basic functions
	static fstring str_Replace(const fstring& search, const fstring& from, const fstring& to);
	static std::string str_ReplaceA(const std::string& search, const std::string& from, const std::string& to);
	
public:
	//Some define
	
public:
	CStringlib() = delete;
	CStringlib& operator=(const CStringlib&) = delete;
	CStringlib(const CStringlib&) = delete;
	~CStringlib() = delete;
};
