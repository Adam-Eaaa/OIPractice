// P1022
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str, str1, str2, temp = "";
    bool hasu = false, symbol = true;
    char u_name;
    int lef = 0, lconst = 0, ref = 0, rconst = 0;
    cin >> str;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '=') {
            str1 = str.substr(0, i);
            str2 = str.substr(i + 1);
            hasu = true;
        }
    }
    if(!hasu){
        str1 = str;
        str2 = "0";
    }
    hasu = false;
    for(int i=0; i<str1.length(); i++) {
        if(str1[i] <= 'z' && str1[i] >= 'a'){
            u_name = str1[i];
            hasu = true;
            continue;
        }
        if(str1[i] == '+') {
            if(hasu){
                if(temp == "") {
                    temp = "1";
                }
                lef += stoi(temp)*(symbol?1:-1);
                hasu = false;
            }
            else {
                if(temp == "") {
                    temp = "0";
                }
                lconst += stoi(temp)*(symbol?1:-1);
            }
            temp = "";
            symbol = true;
            continue;
        }
        if(str1[i] == '-'){
            if(hasu){
                if(temp == "") {
                    temp = "1";
                }
                lef += stoi(temp)*(symbol?1:-1);
                hasu = false;
            }
            else {
                if(temp == "") {
                    temp = "0";
                }
                lconst += stoi(temp)*(symbol?1:-1);
            }
            temp = "";
            symbol = false;
            continue;
        }
        temp += str1[i];
    }
    if(hasu) {
        if(temp == "") {
            temp = "1";
        }
        lef += stoi(temp)*(symbol?1:-1);
        hasu = false;
    }
    else {
        if(temp == "") {
            temp = "0";
        }
        lconst += stoi(temp)*(symbol?1:-1);
    }

    symbol = true;
    temp = "";
    for(int i=0; i<str2.length(); i++) {
        if(str2[i] <= 'z' && str2[i] >= 'a'){
            u_name = str2[i];
            hasu = true;
            continue;
        }
        if(str2[i] == '+') {
            if(hasu) {
                if(temp == "") {
                    temp = "1";
                }
                ref += stoi(temp)*(symbol?1:-1);
                hasu = false;
            }
            else {
                if(temp == "") {
                    temp = "0";
                }
                rconst += stoi(temp)*(symbol?1:-1);
            }
            temp = "";
            symbol = true;
            continue;
        }
        if(str2[i] == '-') {
            if(hasu) {
                if(temp == "") {
                    temp = "1";
                }
                ref += stoi(temp)*(symbol?1:-1);
                hasu = false;
            }
            else {
                if(temp == "") {
                    temp = "0";
                }
                rconst += stoi(temp)*(symbol?1:-1);
            }
            temp = "";
            symbol = false;
            continue;
        }
        temp += str2[i];
    }
    if(hasu) {
        if(temp == "") {
            temp = "1";
        }
        ref += stoi(temp)*(symbol?1:-1);
        hasu = false;
    }
    else {
        if(temp == "") {
           temp = "0";
        }
        rconst += stoi(temp)*(symbol?1:-1);
    }
    if(rconst == lconst) {
        printf("%c=0.000", u_name);
        return 0;
    }
    printf("%c=%.3f", u_name, float(rconst-lconst)/float(lef-ref));
    return 0;
}