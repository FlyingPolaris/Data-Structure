// 1530.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
using namespace std;


char op1[10], op2[10];
int n;

void encode1(char* s, int t, int n);
void encode2(char* s, int t, int n);
void encode3(char* s, int t, int n);
void decode1(char* s, int t, int n, int &x, char* tmp);
void decode2(char* s, int t, int n, int &x, char* tmp);
void decode3(char* s, int t, int n, int &x, char* tmp);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    while (N--)
    {
        memset(op1, 0, sizeof(char) * 10);
        memset(op2, 0, sizeof(char) * 10);
        cin >> n >> op1 >> op2;
        char* s = new char[n + 1];
        memset(s, 0, sizeof(char) * (n + 1));
        cin >> s;
        if (op1[4] == 'R' && op2[0] == 'E') encode1(s, 0, n);
        if (op1[4] == 'D' && op2[0] == 'E') encode2(s, 0, n);
        if (op1[4] == 'O' && op2[0] == 'E') encode3(s, 0, n);
        if (op1[4] == 'R' && op2[0] == 'D')
        {
            char* tmp = new char[n + 1];
            memset(tmp, 0, sizeof(char) * (n + 1));
            int num = 0;
            decode1(s, 0, n, num, tmp);cout << tmp;
        }
        if (op1[4] == 'D' && op2[0] == 'D')
        {
            char* tmp = new char[n + 1];
            memset(tmp, 0, sizeof(char) * (n + 1));
            int num = 0;
            decode2(s, 0, n, num, tmp);cout << tmp;
        }
        if (op1[4] == 'O' && op2[0] == 'D') 
        {
            char* tmp = new char[n + 1];
            memset(tmp, 0, sizeof(char) * (n + 1));
            int num = 0;
            decode3(s, 0, n, num, tmp);cout << tmp;
        }
        cout << '\n';
        delete[] s;
    }

    return 0;
}

void encode1(char* s, int t, int n)
{
    if (t >= n) return;
    cout << s[t];
    encode1(s, 2 * t + 1, n);
    encode1(s, 2 * t + 2, n);
}

void encode2(char* s, int t, int n)
{
    if (t >= n) return;
    encode2(s, 2 * t + 1, n);
    cout << s[t];
    encode2(s, 2 * t + 2, n);
}

void encode3(char* s, int t, int n)
{
    if (t >= n) return;
    encode3(s, 2 * t + 1, n);
    encode3(s, 2 * t + 2, n);
    cout << s[t];
}

void decode1(char* s, int t, int n, int &x, char* tmp)
{
    if (t >= n) return;
    tmp[t] = s[x++];
    decode1(s, 2 * t + 1, n, x, tmp);
    decode1(s, 2 * t + 2, n, x, tmp);
}

void decode2(char* s, int t, int n, int &x, char* tmp)
{
    if (t >= n) return;
    decode2(s, 2 * t + 1, n, x, tmp);
    tmp[t] = s[x++];
    decode2(s, 2 * t + 2, n, x, tmp);
}

void decode3(char* s, int t, int n, int &x, char* tmp)
{
    if (t >= n) return;
    decode3(s, 2 * t + 1, n, x, tmp);
    decode3(s, 2 * t + 2, n, x, tmp);
    tmp[t] = s[x++];
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
