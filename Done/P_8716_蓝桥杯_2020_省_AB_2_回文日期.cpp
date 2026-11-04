#include <bits/stdc++.h>
using namespace std;

bool leap(int year);
bool assert_day(int date, int type);
bool assert_(int date, int year);
bool assert_abab(string x);

int main()
{
    int date, in;
    int year;
    string temp;

    cin >> in;         // Input date
    date = in;
    year = date / 10000; // Only nec to acc year and check leg of date

    while (true)
    {
        year++;
        temp = to_string(year);
        reverse(temp.begin(), temp.end()); // Reversed year => date
        date = stoi(temp);
        if (assert_(date, year))
        {
            break;
        }
    }
    temp = to_string(year);
    reverse(temp.begin(), temp.end());
    cout << year << temp << endl;

    date = in;
    year = date / 10000;
    while (true)
    {
        year++;
        if (assert_abab(to_string(year)))
        {
            temp = to_string(year);
            reverse(temp.begin(), temp.end()); // Reversed year => date
            date = stoi(temp);
            if (assert_(date, year))
            {
                break;
            }
        }
    }
    temp = to_string(year);
    reverse(temp.begin(), temp.end());
    cout << year << temp;

    return 0;
}

bool leap(int year)
{
    if (year % 4 != 0)
        return false;
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return true;
}

bool assert_(int date, int year)
{
    // Legallity
    if (date / 100 == 0 || date / 100 > 12)
        return false;
    if (date % 100 == 0 || date % 100 > 31)
        return false;
    switch(date / 100)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return assert_day(date % 100, 1);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return assert_day(date % 100, 2);
        default:
            if (leap(year))
                return assert_day(date % 100, 3);
            else
                return assert_day(date % 100, 4);
    }
}

bool assert_day(int day, int type)
{
    if (type == 1)
    {
        if (day <= 31 && day >= 1)
            return true;
        return false;
    }

    if (type == 2)
    {
        if (day <= 30 && day >= 1)
            return true;
        return false;
    }

    if (type == 3)
    {
        if (day <= 29 && day >= 1)
            return true;
        return false;
    }

    if (day <= 28 && day >= 1)
        return true;
    return false;
}

bool assert_abab(string x)
{
    if (x[0] == x[2] && x[1] == x[3])
        return true;
    return false;
}
