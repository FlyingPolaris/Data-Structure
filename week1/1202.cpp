// 1202.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
struct linknode
{
    int num;
    linknode* next;
};
int main()
{
    char x;
    linknode* head1,* head2,* headsum, * p, * q, * rear;
    head1 = rear = new linknode;
    while (true)
    {
        x = cin.get();
        if (x == '\n') break;
        p = new linknode;
        p->num = x - '0';
        p->next = head1;
        head1 = p;
    }
    rear->next = NULL;
  

    head2 = rear  = new linknode;
    while (true)
    {
      
        x = cin.get();
        if (x == '\n') break;
        p = new linknode;
        p->num = x - '0';
        p->next = head2;
        head2 = p;
    }
    rear->next = NULL;

    linknode* m, * n;
    m = head1;n = head2;
    int sum = 0, up = 0, mod = 0;
    headsum = rear = new linknode;

    while (true)
    {
        p = new linknode;
        if (m->next != NULL && n->next != NULL)
        {
            sum = m->num + n->num + up;
            mod = sum % 10;
            p->num = mod;
            up = sum / 10;
            m = m->next;
            n = n->next;
        }
        else if (m->next == NULL && n->next != NULL)
        {
            sum = n->num + up;
            mod = sum % 10;
            p->num = mod;
            up = sum / 10;
            n = n->next;
        }
        else if (m->next != NULL && n->next == NULL)
        {
            sum = m->num + up;
            mod = sum % 10;
            p->num = mod;
            up = sum / 10;
            m = m->next;

        }
        else if (m->next == NULL && n->next == NULL && up !=0)
        {
            p->num = 1;
            up = 0;
        }
        else break;
        p->next = headsum;
        headsum = p;
    }
    rear->next = NULL;
    p = headsum;
    while (p->next != NULL)
    {
        cout << p->num;
        p = p->next;
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
