// 1188
#include <bits/stdc++.h>
using namespace std;

struct Char
{
    int content;
    Char* next;
};
Char file[100];
int n, k;

void init()
{
    for (int i = 0; i <= n; i++)
    {
        file[i].content = i;
        file[i].next = &file[i+1];
    }
}

Char* index(int id)
{
    Char* curr = &file[0];
    for (int i = 0; i < id; i++)
    {
        curr = curr -> next;
    }
    return curr;
}

void output(int num = 10)
{
    Char* curr = &file[0];
    for (int i = 0; i < num; i++)
    {
        curr = curr -> next;
        printf("%d ", curr -> content);
    }
}

int main()
{
    int a, b, c;
    Char *a_1, *a_, *b_1, *b_, *c_1, *c_;
    cin >> n >> k;
    init();
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c;
        a_1 = index(a-1);
        b_1 = index(b+1);
        c_ = index(c);
        a_ = index(a);
        b_ = index(b);
        c_1 = index(c+1);
        a_1 -> next = b_1;
        c_ -> next = a_;
        b_ -> next = c_;
    }
    output();
    return 0;
}