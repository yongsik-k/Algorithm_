#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
string Str;
string findStr; // com과 같이 3글자
string findStr2; // co.kr찾기
int cnt = 0;
void isReal(int start, int idx) {
    int b = Str.find('.', start);
    if ((b - idx) < 3)return;
    findStr = Str.substr(b + 1, 3);
    findStr2 = Str.substr(b + 1, 5);
    if (findStr == "COM" || findStr == "ORG" || findStr == "NET") {
        cnt++;
        return;
    }
    if (findStr2 == "CO.KR") {
        cnt++;
        return;
    }
    return;
}


int main() {
    // FILE * freinput = freopen("input.txt", "rt", stdin);

    cin >> Str;
    for (int i = 0; i < Str.length(); i++) {
        Str[i] = toupper(Str[i]);
    }
    int p = 0;
    int c = 0;
    while (1) {
        int a = Str.find("HTTP://", p);
        if (a == -1)break;
        int bb = Str.find("HTTP://", a + 1);
        int cc = Str.find("HTTPS://", a + 1);
        if ((bb - a) < 8 && (cc - a) < 9)continue;

        p = a + 1;
        isReal(a, a + 7);

    }
    int k = 0;
    int real = 0;
    while (1) {
        int b = Str.find("HTTPS://", k);
        if (b == -1)break;
        int bb = Str.find("HTTP://", b + 1);
        int cc = Str.find("HTTPS://", b + 1);
        k = b + 1;/*
        if (bb > cc) {
            real = bb + 1;
        }
        else {
            real = cc + 1;
        }*/
        if (bb != -1) {
            if ((bb - b) < 9) continue;
        }
        if (cc != -1) {
            if ((cc - b) < 9)continue;
        }


        isReal(b, b + 8);

    }
    cout << cnt << "개";


    return 0;
}