#include<cppstrlib.h>

#ifdef _DEBUG
#pragma comment(lib,"cppStringLiabrary-d.lib")
#else
#pragma comment(lib,"cppStringLiabrary.lib")
#endif // _DEBUG

using namespace std;
int main()
{
	std::string str = ("/Users/xuyw/Desktop/TestSpace");

    auto ret = CStringlib::str_Replace(str, "/xuyw", "\\slsc");
    cout<<ret<<endl;
	return 0;
}
