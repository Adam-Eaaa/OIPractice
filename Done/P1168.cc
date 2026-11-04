#include <iostream>
#include <vector>
using namespace std;

int N, pa, pb;
vector<int> a, b;

void push_a(int val) {
    a[++pa] = val;
    int curr = pa;
    while (curr / 2 > 0) {
        if (a[curr] > a[curr / 2]) {
            swap(a[curr], a[curr / 2]);
            curr /= 2;
        }
        else {
            break;
        }
    }
}

void update_a(int index) {
    if (index * 2 > pa)
        return;
    if (index * 2 + 1 > pa) {
        if (a[index] < a[index * 2])
            swap(a[index], a[index * 2]);
        return;
    }
    int c1 = index * 2, c2 = index * 2 + 1;
    if (a[c1] < a[c2])
        c1 = c2;
    if (a[c1] > a[index]) {
        swap(a[c1], a[index]);
        update_a(c1);
    }
}

void push_b(int val) {
    b[++pb] = val;
    int curr = pb;
    while (curr / 2 > 0) {
        if (b[curr] < b[curr / 2]) {
            swap(b[curr], b[curr / 2]);
            curr /= 2;
        }
        else {
            break;
        }
    }
}

void update_b(int index) {
    if (index * 2 > pb)
        return;
    if (index * 2 + 1 > pb) {
        if (b[index] > b[index * 2])
            swap(b[index], b[index * 2]);
        return;
    }
    int c1 = index * 2, c2 = c1 + 1;
    if (b[c1] > b[c2])
        c1 = c2;
    if (b[c1] < b[index]) {
        swap(b[c1], b[index]);
        update_b(c1);
    }
}

int main(void) {
    cin >> N;
    a.resize(N + 1);
    b.resize(N + 1);
    pa = 0;
    pb = 0;
    for (int i = 1; i <= N; ++i) {
        int M;
        cin >> M;
        if (pa == 0 || M <= a[1]) {
            push_a(M);
        }
        else {
            push_b(M);
        }

        while (pa > pb + 1) {
            push_b(a[1]);
            swap(a[1], a[pa--]);
            update_a(1);
        }
        while (pb > pa) {
            push_a(b[1]);
            swap(b[1], b[pb--]);
            update_b(1);
        }

        if (i & 1) {
            cout << a[1] << endl;
        }
    }
    return 0;
}