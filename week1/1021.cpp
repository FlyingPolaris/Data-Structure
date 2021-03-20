#include <iostream>
using namespace std;

void goright(int**,int,int,int,int);
void godown(int**, int, int, int, int);
void goleft(int**, int, int, int, int);
void goup(int**, int, int, int, int);
int main(int**, int, int, int, int)
{
    int N;
    cin >> N;
    int** arr = new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }
    goright(arr, 0, 0, 1, N);
    int m = 0, n = N - 1, num = N;
    for (int length = N - 1;length > 0;length--)
    {
        godown(arr, m + 1, n, num + 1, length);
        m += length;num += length;
        goleft(arr, m, n - 1, num + 1, length);
        n -= length;num += length;
        length--;
        if (length == 0)break;
        goup(arr, m - 1, n, num + 1, length);
        m -= length;num += length;
        goright(arr, m, n + 1, num + 1, length);
        n += length;num += length;
    }
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
      

    for (int i = 0; i < N; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
    return 0;
}

void goright(int** a,int x,int y,int begin,int len)
{
    for (int i = 0;i < len;i++)
    {
        a[x][y + i] = begin + i;
    }
}
void godown(int** a, int x, int y, int begin, int len)
{
    for (int i = 0;i < len;i++)
    {
        a[x + i][y] = begin + i;
    }
}
void goleft(int** a, int x, int y, int begin, int len)
{
    for (int i = 0;i < len;i++)
    {
        a[x][y - i] = begin + i;
    }
}
void goup(int** a, int x, int y, int begin, int len)
{
    for (int i = 0;i < len;i++)
    {
        a[x - i][y] = begin + i;
    }
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
