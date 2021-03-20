#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//void checkinstack(char a[], int top);
bool checkmatch(char ch1, char ch2);

struct mystack
{
    char data[1000002];
    int top;
};
bool ok[1000002] = { false };

int main()
{
    int n;
    scanf("%d", &n);
    mystack s;
    s.top = 0;
    mystack p;
    p.top = 0;

    for (int i = 0;i < n;++i)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            char x;
            scanf(" %c", &x);
            s.data[s.top++] = x;
            if (x == '(' || x == '[' || x == '{')
            {
                p.data[p.top++] = x;
                ok[s.top - 1] = true;
            }
            else if (p.top >= 1 && checkmatch(p.data[p.top - 1], x))
                {
                    p.top--;
                    ok[s.top - 1] = true;
                }
            else
            {
                p.data[p.top++] = x;
                ok[s.top - 1] = false;
            }
            break;
        case 2:
            if (s.top > 0)
            {
                switch (s.data[s.top - 1])
                {
                case '(':case'[':case'{':
                    p.top--;
                    break;
                case ')':
                    if (ok[s.top - 1])
                    {
                        p.data[p.top++] = '(';
                    }
                    else p.top--;
                    break;
                case']':
                    if (ok[s.top - 1])
                    {
                        p.data[p.top++] = '[';
                    }
                    else p.top--;
                    break;
                case'}':
                    if (ok[s.top - 1])
                    {
                        p.data[p.top++] = '{';
                    }
                    else p.top--;
                    break;
                }
            }

            if (s.top > 0)
            {
                s.top--;
            }

            break;
        case 3:
            if (s.top > 0)
            {
                printf("%c\n", s.data[s.top - 1]); 
            }
            break;
        case 4:
            if (p.top != 0) printf("NO\n");
            else printf("YES\n");
            break;
        default:
            break;
        }
    }
    return 0;
}


bool checkmatch(char ch1, char ch2)
{
    if (ch1 == '(' && ch2 == ')' || ch1 == '[' && ch2 == ']' || ch1 == '{' && ch2 == '}')
        return true;
    else return false;
}