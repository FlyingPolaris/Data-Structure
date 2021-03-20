// 4094.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
using namespace std;

char coming[300];
int customer[30] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, bed;
	int leave = 0;
	cin >> t;
	while (t != 0)
	{
		cin >> coming;
		bed = t;
		for (int i = 0; i < strlen(coming); ++i)
		{
			if (customer[coming[i] - 'A'] == 0)
			{
				if (bed > 0)
				{
					customer[coming[i] - 'A'] = 1;
					bed--;
				}
				else
				{
					customer[coming[i] - 'A'] = 2;
					leave++;
				}
			}
			else if(customer[coming[i] - 'A'] == 1)
			{
				bed++;
				customer[coming[i] - 'A'] = 0;
			}
		}
		if (leave == 0) cout << "All customers tanned successfully." << '\n';
		else cout << leave << " customer(s) walked away." << '\n';
		leave = 0;
		memset(coming, 0, sizeof(coming));
		memset(customer, 0, sizeof(customer));
		cin >> t;
	}

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
