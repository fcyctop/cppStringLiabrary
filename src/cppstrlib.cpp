#include<cppstrlib.h>
#include<Windows.h>
#include<string>
#include<regex>
#include<sys/types.h>
#include<sys/stat.h>
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

fstring CStringlib::path_SystemSlashFormat(const fstring& fstr, OSType type)
{
	if (OSType::OS_MIN < type && type < OSType::OS_MAX){
		fstring from = (OSType::OS_WIN == type) ? _T("/") : _T("\\\\");
		fstring to = (OSType::OS_WIN == type) ? _T("\\") : _T("/");
		return str_Replace(fstr, from, to);
	}

#ifdef UNICODE
	fstring from(_T("/"));
	fstring to{ _T("\\") };
#else
	fstring re("\\\\");
	fstring to{ "/" };
#endif // UNICODE
	return str_Replace(fstr, from, to);
}

std::string CStringlib::path_SystemSlashFormatA(const std::string& fstr, OSType type)
{
	if (OSType::OS_MIN < type && type < OSType::OS_MAX) {
		std::string from = (OSType::OS_WIN == type) ? "/" : "\\\\";
		std::string to = (OSType::OS_WIN == type) ? "\\" : "/";
		return str_ReplaceA(fstr, from, to);
	}

#ifdef UNICODE
	std::string from("/");
	std::string to{ "\\" };
#else
	std::string re("\\\\");
	std::string to{ "/" };
#endif // UNICODE
	return str_ReplaceA(fstr, from, to);
}

bool CStringlib::path_IsDirectoryExists(const fstring& path)
{
	struct _stat info;
	return (0 == _wstat(path.c_str(), &info) && (S_IFDIR & info.st_mode));
}

bool CStringlib::path_IsDirectoryExistsA(const std::string& path)
{
	struct stat info;
	return (0 == stat(path.c_str(), &info) && (S_IFDIR & info.st_mode));
}

fstring CStringlib::path_GetDir(const fstring& path)
{
	auto pos = path.find_last_of(_T('\\'));
	if (fstring::npos == pos) pos = path.find_last_of(_T('/'));
	if (fstring::npos == pos) return _T("");
	fstring ret = path.substr(0, pos + 1);
	return ret;
}

std::string CStringlib::path_GetDirA(const std::string& path)
{
	auto pos = path.find_last_of('\\');
	if (std::string::npos == pos) pos = path.find_last_of('/');
	if (std::string::npos == pos) return "";
	std::string ret = path.substr(0, pos + 1);
	return ret;
}

bool CStringlib::file_OpenFile(FILE** obj, const fstring& file, const fstring& mode)
{
	return _wfopen_s(obj, file.c_str(), mode.c_str());
}

bool CStringlib::file_OpenFileA(FILE** obj, const std::string& file, const std::string& mode)
{
	return fopen_s(obj, file.c_str(), mode.c_str());
}

size_t CStringlib::file_GetSize(const fstring& file)
{
	struct _stat info;
	if (0 == _wstat(file.c_str(), &info)) {
		return info.st_size;
	}
	return 0;
}

size_t CStringlib::file_GetSizeA(const std::string& file)
{
	struct stat info;
	if (0 == stat(file.c_str(), &info)) {
		return info.st_size;
	}
	return 0;
}

time_t CStringlib::file_GetCreateTime(const fstring& file)
{
	struct _stat info;
	if (0 == _wstat(file.c_str(), &info)) {
		return info.st_ctime;
	}
	return 0;
}

time_t CStringlib::fiel_GetCreateTimeA(const std::string& file)
{
	struct stat info;
	if (0 == stat(file.c_str(), &info)) {
		return info.st_ctime;
	}
	return 0;
}

time_t CStringlib::file_GetModifyTime(const fstring& file)
{
	struct _stat info;
	if (0 == _wstat(file.c_str(), &info)) {
		return info.st_mtime;
	}
	return 0;
}

time_t CStringlib::file_GetModifyTimeA(const std::string& file)
{
	struct stat info;
	if (0 == stat(file.c_str(), &info)) {
		return info.st_mtime;
	}
	return 0;
}

fstring CStringlib::str_Replace(const fstring& search, const fstring& from, const fstring& to)
{
#ifdef UNICODE
	std::wregex re(from);
#else
	std::regex re(from);
#endif // UNICODE
	return std::regex_replace(search, re, to);
}

std::string CStringlib::str_ReplaceA(const std::string& search, const std::string& from, const std::string& to)
{
	return std::regex_replace(search, std::regex(from), to);
}

fstring CStringlib::str_StrimLeft(const fstring& fstr)
{
	if (fstr.empty()) return fstr;
	auto&& len = fstr.size();
	size_t index = 0;
	while (index < len && _T(' ') == fstr[index]) {
		++index;
	}
	return fstr.substr(index);
}

fstring CStringlib::str_StrimRight(const fstring& fstr)
{
	if (fstr.empty()) return fstr;
	auto&& len = fstr.size() - 1;
	auto index = len;
	while (fstring::npos != index && _T(' ') == fstr[index]) {
		--index;
	}
	return (len == index) ? fstr : fstr.substr(0, index + 1);
}

fstring CStringlib::str_StrimAll(const fstring& fstr)
{
	if (fstr.empty()) return fstr;
	auto&& len = fstr.size();
	size_t index = 0;
	while (index < len && _T(' ') == fstr[index]) {
		++index;
	}
	fstring ret = fstr.substr(index);

	if (ret.empty()) return ret;
	len = ret.size() - 1;
	index = len;
	while (fstring::npos != index && _T(' ') == ret[index]) {
		--index;
	}
	return (len == index) ? ret : ret.substr(0, index + 1);
}

std::string CStringlib::str_StrimLeftA(const std::string& str)
{
	if (str.empty()) return str;
	auto&& len = str.size();
	size_t index = 0;
	while (index < len && ' ' == str[index]) {
		++index;
	}
	return str.substr(index);
}

std::string CStringlib::str_StrimRightA(const std::string& str)
{
	if (str.empty()) return str;
	auto&& len = str.size() - 1;
	auto index = len;
	while (std::string::npos != index && ' ' == str[index]) {
		--index;
	}
	return (len == index) ? str : str.substr(0, index + 1);
}

std::string CStringlib::str_StrimAllA(const std::string& str)
{
	if (str.empty()) return str;
	auto&& len = str.size();
	size_t index = 0;
	while (index < len && ' ' == str[index]) {
		++index;
	}
	std::string ret = str.substr(index);

	if (ret.empty()) return ret;
	len = ret.size() - 1;
	index = len;
	while (std::string::npos != index && ' ' == ret[index]) {
		--index;
	}
	return (len == index) ? ret : ret.substr(0, index + 1);
}
