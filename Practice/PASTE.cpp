// P1188
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    node *after;
};

node chart[100000];

node *index(int id)
{
    node *temp;
    temp = &chart[0];
    for (int i = 0; i < id; i++) 
    {
        temp = temp->after;
    }
    return temp;
}

int main()
{
    int N, K;
    int A, B, C;
    node *tmp[6], *temp;
    cin >> N >> K;
    chart[0].value = 0;
    for (int i = 0; i <= N; i++)
    {
        chart[i].value = i;
        chart[i].after = &chart[i + 1];
    }
    for (int i = 0; i < K; i++)
    {
        cin >> A >> B >> C;
        // Every time paste:
        // chart[A-1]->chart[B+1]
        // chart[C]->chart[A]
        // chart[B]->chart[C+1]
        tmp[0] = index(A-1);
        tmp[1] = index(B+1);
        tmp[2] = index(C);
        tmp[3] = index(A);
        tmp[4] = index(B);
        tmp[5] = index(C+1);
        tmp[0]->after = tmp[1];
        tmp[2]->after = tmp[3];
        tmp[4]->after = tmp[5];
    }
    temp = &chart[0];
    for (int i = 0; i < 10; i++)
    {
        temp = temp->after;
        printf("%d\n", temp->value);
    }
    return 0;
}