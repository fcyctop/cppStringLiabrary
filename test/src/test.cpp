#include<cppstrlib.h>

#ifdef _DEBUG
#pragma comment(lib,"cppStringLiabrary-d.lib")
#else
#pragma comment(lib,"cppStringLiabrary.lib")
#endif // _DEBUG

using namespace std;
int main()
{
	fstring fstr = _T("     D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Deb  ug    ");
	fstring fstr2 = _T("D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Deb  ug");
	fstring fstr3 = _T("         ");
	fstring fstr4 = _T("");	
	fstring fstr5 = _T("D:\\TestSapce2");
	fstring fstr6 = _T("D:\\TestSapce3\\");
	std::string str = ("     D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Deb  ug    ");
	std::string str2 = ("D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Deb  ug");
	std::string str3 = ("         ");
	std::string str4 = ("");
	std::string str5 = "D:\\TestSapce3";
	std::string str6 = "D:\\TestSapce4\\";

	auto ret = CStringlib::path_IsDirectoryExists(fstr5);
	auto ret1 = CStringlib::path_IsDirectoryExists(fstr6);
	auto ret2 = CStringlib::path_IsDirectoryExistsA(str5);
	auto ret3 = CStringlib::path_IsDirectoryExistsA(str6);
	system("pause");

	return 0;
}
