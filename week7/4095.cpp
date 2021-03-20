
// 4095.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "iostream"
#include "cstdio"
using namespace std;

bool check[100009] = { 0 };

int main() {
	int N, M;
	cin >> N >> M;

	auto cnt = N, pos = 0;

	for (int left = 0, right = cnt; cnt > 1; --cnt) {
		left = cnt - right;
		//计算最后一步的位移
		auto step = M % (2 * cnt - 2);
		if (step == 0)
			step = cnt * 2 - 2;
		if (step <= right) {
			//移动
			for (int i = 0; i < step; )
				if (!check[++pos])
					++i;
			right -= step;
		}
		else if (step < right * 2) {
			//移动
			for (int i = 0; i < right * 2 - step;)
				if (!check[++pos])
					++i;
			right = step - right;
		}
		else if (step < right * 2 + left - 1) {
			//移动
			for (int i = 0; i < step - right * 2 + 1;)
				if (!check[--pos])
					++i;
			right = step - right;
		}
		else {
			//移动
			for (int i = 0; i < cnt * 2 - 1 - step;)
				if (!check[--pos])
					++i;
			right += cnt * 2 - 2 - step;
		}
		check[pos] = true;
	}

	printf("%d", pos);

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
