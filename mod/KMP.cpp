#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    string pattern, text;
    int t_candidate, p_candidate;
    vector<int> border;
    cin >> text >> pattern;

    border.resize(pattern.size());
    border[0] = 0;
    for (auto i = 1; i < pattern.size(); ++i) {
        p_candidate = border[i - 1];

        while (p_candidate > 0 && pattern[p_candidate] != pattern[i]) {
            p_candidate = border[p_candidate - 1];
        }

        if (pattern[p_candidate] == pattern[i]) {
            ++p_candidate;
        }

        border[i] = p_candidate;
    }

    p_candidate = 0;

    for (t_candidate = 0; t_candidate < text.size(); ++t_candidate) {
        while (p_candidate > 0 && pattern[p_candidate] != text[t_candidate]) {
            p_candidate = border[p_candidate - 1];
        }

        if (pattern[p_candidate] == text[t_candidate])
            ++p_candidate;
        
        if (p_candidate == pattern.size()) {
            cout << t_candidate - p_candidate + 2 << endl;
            p_candidate = border.back();
        }
    }

    for (auto& i : border) {
        cout << i << ' ';
    }
    return 0;
}