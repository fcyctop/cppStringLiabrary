#include<cppstrlib.h>
#include<Windows.h>
#include<string>

fstring CStringlib::str2fstr(const std::string& str)
{
#ifdef UNICODE
	int len = ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	WCHAR* buffer = new WCHAR[len];
	::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, buffer, len);
	fstring result(buffer);
	delete[] buffer;
	return result;
#else
	return str;
#endif // UNICODE
}

std::string CStringlib::fstr2str(const fstring& fstr)
{
#ifdef UNICODE
	int len = ::WideCharToMultiByte(CP_UTF8, 0, fstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	CHAR* buffer = new CHAR[len];
	::WideCharToMultiByte(CP_UTF8, 0, fstr.c_str(), -1, buffer, len, nullptr, nullptr);
	std::string result(buffer);
	delete[] buffer;
	return result;
#else
	return fstr;
#endif // UNICODE
}
