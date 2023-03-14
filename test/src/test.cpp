#include<cppstrlib.h>

#pragma comment(lib,"cppStringLiabrary.lib")
using namespace std;
int main()
{
	fstring fstr = _T("Hello");
	cout << CStringlib::fstr2str(fstr) << endl;
	system("pause");
	return 0;
}
