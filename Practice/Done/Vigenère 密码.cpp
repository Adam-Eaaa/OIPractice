// P1079
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Meanings of variables:
    //  in: input string
    //  key: input key
    //  keyc: temporary variable for key length completion
    //  in_c: the converted input string
    //  key_c: the converted key string
    //  uppercases: all uppercase letter in input string
    //  result: result string
    //  result_c: deciphered code of integers
    string in, key, keyc, result;
    int in_c[1000], key_c[1100], result_c[1000]; 
    bool uppercases[1000] = { };
    cin >> keyc;
    cin >> in;
    // Completion of key
    key = keyc;
    while (key.length() < in.length()) {
        key += keyc;
    }
    // We know that the algorithm is like c = a + b - 1
    // so we can convert the alphabet into integer first 
    // then we can cipher it by adding
    for (int i = 0; i < key.length(); i++) {
        if (key[i] <= 'Z' && key[i] >= 'A') {
            key_c[i] = key[i] - 'A' + 1;
        }
        else {
            key_c[i] = key[i] - 'a' + 1;
        }
    }
    // Same as input
    // Note that the uppercase letters of input affects the result's 
    // letter.
    for (int i = 0; i < in.length(); i++) {
        if (in[i] <= 'Z' && in[i] >= 'A') {
            in_c[i] = in[i] - 'A' + 1;
            uppercases[i] = 1;
        }
        else {
            in_c[i] = in[i] - 'a' + 1;
        }
    }
    // Decipher
    for (int i = 0; i < in.length(); i++) {
        if (in_c[i] < key_c[i]) {
            in_c[i] += 26;
        }
        result_c[i] = in_c[i] - key_c[i] + 1;
        if (uppercases[i]) {
            result += result_c[i] + 'A' - 1;
        }
        else {
            result += result_c[i] + 'a' - 1;
        }
    }
    cout << result;
    return 0;
}