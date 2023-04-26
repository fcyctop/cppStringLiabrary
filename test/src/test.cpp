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

    auto b = CStringlib::path_IsDirectoryExists(str);
    cout<<(b?"true":"false")<<endl;
	system("pause");


	return 0;
}
