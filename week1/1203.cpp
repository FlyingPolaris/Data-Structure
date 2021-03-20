
// 1203.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
using namespace std;
template <class T>
void link(int a, int b)
{
    T* arr1, * arr2,* arr;
    arr1 = new T[a + 1];
    arr2 = new T[b + 1];
    for (int i = 0;i < a;i++) cin >> arr1[i];
    for (int i = 0;i < b;i++) cin >> arr2[i];
    arr1[a] = arr2[b] = '\0';
    arr = new T[a + b + 1];
    for (int i = 0;i < a + b;i++)
    {
        if (i <= a - 1) arr[i] = arr1[i];
        else if(i <= a + b - 1) arr[i] = arr2[i - a];
    }
    arr[a + b] = '\0';
    for (int i = 0;i < a + b;i++)
    {
        cout << arr[i] << ' ';
    }
    delete []arr1;
    delete []arr2;
}
int main()
{
    char type[7];
    cin >> type;
    int lena, lenb;
    cin >> lena >> lenb;
    if (!strcmp(type , "int")) link<int>(lena, lenb);
    else if (!strcmp(type, "double")) link<double>(lena, lenb);
    else if((!strcmp(type, "char"))) link<char>(lena, lenb);
    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
