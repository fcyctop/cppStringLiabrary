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
	fstring fstr5 = _T("D:\\TestSapce\\testblod3");
	fstring fstr6 = _T("D:\\TestSapce3\\");
	std::string str = ("     D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Deb  ug    ");
	std::string str2 = ("D:/lsc/gitHub/cppStringLiabrary/bin/v143/x64Deb  ug");
	std::string str3 = ("         ");
	std::string str4 = ("");
	std::string str5 = "D:\\TestSapce\\testblod3";
	std::string str6 = "D:\\TestSapce4\\";

	struct stat info;
	if (0 == stat(str5.c_str(), &info))
	{
		cout << "st_atime��" << info.st_atime << endl;
		cout << "st_ctime��" << info.st_ctime<< endl;	//creat time
		cout << "st_dev��" << info.st_dev << endl;
		cout << "st_dev��" << info.st_dev << endl;
		cout << "st_ino��" << info.st_ino << endl;
		cout << "st_mode��" << info.st_mode << endl;
		cout << "st_mtime��" << info.st_mtime << endl;	//modify time
		cout << "st_nlink��" << info.st_nlink << endl;
		cout << "st_rdev��" << info.st_rdev << endl;
		cout << "st_size��" << info.st_size << endl;
		cout << "st_uid��" << info.st_uid << endl;

	}

	system("pause");


	return 0;
}
