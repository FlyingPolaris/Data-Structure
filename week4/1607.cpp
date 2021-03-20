// 1607.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int peo[2000001];

class group
{
public:
    int id;
    int* member;
    int tail = -1;
    int head = 0;
    int nowsize = 2;
    group* next;
    group()
    {
        member = new int[2];
    }
    ~group()
    {
        delete[] member;
    }
    void doublespace()
    {
        nowsize *= 2;
        int* newmember = new int[nowsize];
        for (int i = 0;i < tail;++i)
        {
            newmember[i] = member[i];
        }
        delete member;
        member = newmember;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0;i < n;++i)
        cin >> peo[i];
    int q;
    cin >> q;
    group* head=new group;
    head->id = -1;
    head->next = NULL;
    int peoplein = 0;
 

    for (int i = 1;i <= q;++i)
    {
        int op;
        cin >> op;
        if (op)
        {
            if (head->next == NULL) cout << "-1" << '\n';
            else
            {
                group* tmp = head->next;
                cout << head->next->member[head->next->head] << '\n';
                if (head->next->head < head->next->tail) head->next->head++;
                else head->next = head->next->next;
            }
        }
        else
        {
            peoplein++;
            bool flag = false;
            group* p = head;
            group* q = head->next;
            while (q != NULL)
            {
                if (p->id == peo[peoplein - 1])
                {
                    flag = true;
                    break;
                }
                else flag = false;
                p = p->next;
                q = q->next;
            }
            if (p->id == peo[peoplein - 1])
            {
                flag = true;
            }
            else flag = false;

            if (flag)
            {
                (p->tail)++;
                if (p->tail >= p->nowsize - 1) p->doublespace();
                p->member[p->tail] = peoplein;
            }
            else
            {
                group* newgroup = new group;
                newgroup->id = peo[peoplein - 1];
                (newgroup->tail)++;
                newgroup->member[newgroup->tail] = peoplein;
                p->next = newgroup;
                newgroup->next = NULL;
            }
        }
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
