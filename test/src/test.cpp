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
	std::string str = ("     D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Deb  ug    ");
	std::string str2 = ("D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Deb  ug");
	std::string str3 = ("         ");
	std::string str4 = ("");

	std::string ret1 = CStringlib::str_StrimLeftA(str3);
	std::string ret2 = CStringlib::str_StrimRightA(str3);
	std::string ret3 = CStringlib::str_StrimAllA(str3);

	wcout << CStringlib::str_StrimLeft(fstr3) << std::endl;
	wcout << CStringlib::str_StrimRight(fstr) << std::endl;
	wcout << CStringlib::str_StrimAll(fstr) << std::endl;
	//cout << CStringlib::path_GetDirA(str) << std::endl;
	system("pause");
	return 0;
}
