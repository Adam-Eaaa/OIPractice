#include <iostream>
#include <array>
#include <vector>
using namespace std;

struct Node {
    array<int, 64> child{};
    int pass = 0, end_cnt = 0;
};

vector<Node> trie;

int convert(const char& c) {
    return c >= 'a' ? c - 'a' + 37 : c >= 'A' ? c - 'A' + 11 : c - '0';
}

void insert(const string& s) {
    int curr;
    curr = 0;
    for (const auto& i : s) {
        int u = convert(i);
        ++trie[curr].pass;
        if (trie[curr].child[u] == 0) {
            trie.emplace_back();
            trie[curr].child[u] = trie.size() - 1;
        }
        curr = trie[curr].child[u];
    }
    ++trie[curr].pass;
    ++trie[curr].end_cnt;
}

int prefix_of(const string& s) {
    int curr = 0, count = 0;
    for (const auto& i : s) {
        int u = convert(i);
        if (trie[curr].child[u] == 0)
            break;
        curr = trie[curr].child[u];
        count += trie[curr].end_cnt;
    }
    return count;
}

int count_prefix(const string& s) {
    int curr = 0;
    for (const auto& i : s) {
        int u = convert(i);
        if (trie[curr].child[u] == 0)
            return 0;
        curr = trie[curr].child[u];
    }
    return trie[curr].pass;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        trie.clear();
        trie.emplace_back();
        int n, q;
        cin >> n >> q;
        for (int j = 0; j < n; ++j) {
            string input;
            cin >> input;
            insert(input);
        }
        for (int j = 0; j < q; ++j) {
            string query;
            cin >> query;
            cout << count_prefix(query) << endl;
        }
    }
    return 0;
}