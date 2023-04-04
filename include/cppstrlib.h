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
		check directory exixts
	*/
	static bool path_IsDirectoryExists(const fstring& path);
	static bool path_IsDirectoryExistsA(const std::string& path);

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
	//Some functions about modification
	static fstring str_Replace(const fstring& search, const fstring& from, const fstring& to);
	static std::string str_ReplaceA(const std::string& search, const std::string& from, const std::string& to);

	static fstring str_StrimLeft(const fstring& fstr);
	static fstring str_StrimRight(const fstring& fstr);
	static fstring str_StrimAll(const fstring& fstr);

	static std::string str_StrimLeftA(const std::string& str);
	static std::string str_StrimRightA(const std::string& str);
	static std::string str_StrimAllA(const std::string& str);
public:
	//Some define
	
public:
	CStringlib() = delete;
	CStringlib& operator=(const CStringlib&) = delete;
	CStringlib(const CStringlib&) = delete;
	~CStringlib() = delete;
};
