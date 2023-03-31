#include<cppstrlib.h>

#ifdef _DEBUG
#pragma comment(lib,"cppStringLiabrary-d.lib")
#else
#pragma comment(lib,"cppStringLiabrary.lib")
#endif // _DEBUG

using namespace std;
int main()
{
	fstring fstr = _T("D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Debug");
	std::string str = "D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Debug";
	wcout << CStringlib::path_GetDir(fstr) << std::endl;
	cout << CStringlib::path_GetDirA(str) << std::endl;
	system("pause");
	return 0;
}
