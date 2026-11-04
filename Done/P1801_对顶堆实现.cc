// 这是题目 P1801 黑匣子的对顶堆实现
#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<int> a, b;
int pa, pb;

void update_a(int index) {
    if (index * 2 > pa) {
        return;
    }
    int c;
    if (index * 2 >= pa) {
        c = index << 1;
    }
    else {
        if (a[index * 2] > a[index * 2 + 1])
            c = index << 1;
        else
            c = index * 2 + 1;
    }
    if (a[c] > a[index]) {
        swap(a[c], a[index]);
        update_a(c);
    }
}

void update_b(int index) {
    if (index * 2 > pb) {
        return;
    }
    int c;
    if (index * 2 >= pb) {
        c = index << 1;
    }
    else {
        if (b[index * 2] < b[index * 2 + 1])
            c = index << 1;
        else
            c = index * 2 + 1;
    }
    if (b[c] < b[index]) {
        swap(b[c], b[index]);
        update_b(c);
    }
}

void push_a(int val) {
    a[++pa] = val;
    int curr = pa;
    while (curr / 2 > 0) {
        if (a[curr / 2] > a[curr])
            break;
        swap(a[curr / 2], a[curr]);
        curr /= 2;
    }
}

void push_b(int val) {
    b[++pb] = val;
    int curr = pb;
    while (curr / 2 > 0) {
        if (b[curr / 2] < b[curr])
            break;
        swap(b[curr / 2], b[curr]);
        curr /= 2;
    }
}

int main(void) {
    cin >> m >> n;
    a.resize(m + 1);
    b.resize(m + 1);
    pa = 0;
    pb = 0;
    vector<int> add_op(m), get_op(n);
    for (auto& i : add_op)
        cin >> i;
    for (auto& i : get_op)
        cin >> i;
    auto ptr = get_op.begin();
    int k = 0;
    for (int i = 0; i < m; ++i) {
        if (pa == 0 || add_op[i] > a[1])
            push_b(add_op[i]);
        else 
            push_a(add_op[i]);
        while (pa < k) {
            push_a(b[1]);
            swap(b[1], b[pb--]);
            update_b(1);
        }
        while (pa > k) {
            push_b(a[1]);
            swap(a[1], a[pa--]);
            update_a(1);
        }
        while (ptr < get_op.end() && *ptr <= i + 1) {
            ++k;
            while (pa < k) {
                push_a(b[1]);
                swap(b[1], b[pb--]);
                update_b(1);
            }
            while (pa > k) {
                push_b(a[1]);
                swap(a[1], a[pa--]);
                update_a(1);
            }
            cout << a[1] << endl;
            ++ptr;
        }
    }
    return 0;
}