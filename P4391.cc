#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    string pattern;
    int p_candidate = 0;
    int L;
    cin >> L;
    cin >> pattern;
    vector<int> border;
    border.emplace_back(0);
    for (size_t i = 1; i < L; ++i) {
        p_candidate = border.back();
        while (p_candidate > 0 && pattern[i] != pattern[p_candidate])
            p_candidate = border[p_candidate - 1];
        
        if (pattern[i] == pattern[p_candidate])
            ++p_candidate;
        
        border.emplace_back(p_candidate);
    }

    cout << L - border.back();
    return 0;
}