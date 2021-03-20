// 1043.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct mytree
{
	long long leftchild;
	long long rightchild;
};

int N;
mytree binary[1000000];
mytree queue[1000000];
mytree thebinary[1000000];
int tail = 0, head = -1, top = 0;
int numofsons(mytree tmp)
{
	if (tmp.leftchild == -1 && tmp.rightchild == -1) return 0;
	else if (tmp.leftchild != -1 && tmp.rightchild == -1) return 1;
	else if (tmp.leftchild != -1 && tmp.rightchild != -1) return 2;
}
bool check()
{
	bool onlyonce = true;
	bool flag = true;
	int checkbegin = 0;
	int nodenum = 1;
	queue[++head] = binary[0];
	while (true)
	{
		if (numofsons(queue[tail]) != 2 && onlyonce)
		{
			checkbegin = tail;
			onlyonce = false;
		}
		if (queue[tail].leftchild != -1)
		{
			queue[++head] = binary[queue[tail].leftchild];++nodenum;
		}
		if (queue[tail].rightchild != -1)
		{
			queue[++head] = binary[queue[tail].rightchild];++nodenum;
		}
		tail++;
		if (nodenum == N) break;
	}
	checkbegin++;
	while (head >= checkbegin)
	{
		if (numofsons(queue[checkbegin]) != 0) flag = false;
		checkbegin++;
	}
	return flag;
}


int main()
{
	cin >> N;
	int num = 0;
	for (int i = 0;i < 1000000;++i)
	{
		binary[i].leftchild = binary[i].rightchild = -1;
	}
	for (int i = 0;i < N - 1;++i)
	{
		int tmp;
		cin >> tmp;
		if (binary[tmp].leftchild != -1) binary[tmp].rightchild = ++num;
		else binary[tmp].leftchild = ++num;
	}
	if (check()) cout << "true";
	else cout << "false";
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
