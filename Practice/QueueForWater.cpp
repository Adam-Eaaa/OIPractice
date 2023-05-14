#include <iostream>
#include <algorithm>
using namespace std;

struct Person 
{
    int number;
    int time;
};

bool cmpPerson(Person a, Person b)
{
    if (a.time == b.time)
    {
        return a.number <= b.number;
    }
    return a.time < b.time;
}

int main()
{
    int n;
    double all;
    Person *a;
    cin >> n;
    a = new Person[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i].number = i;
        cin >> a[i].time;
    }
    sort(a + 1, a + n + 1, cmpPerson);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i].number);
        all += (n - i) * a[i].time;
    }
    printf("\n%.2f", all / n);
    return 0;
}