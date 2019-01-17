#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1005;

int n;
char buff[MAXN], code[10];
map<string, char> id;

int main()
{
    id[".-"] = 'A'; id["-..."] = 'B'; id["-.-."] = 'C';
    id["-.."] = 'D'; id["."] = 'E'; id["..-."] = 'F';
    id["--."] = 'G'; id["...."] = 'H'; id[".."] = 'I';
    id[".---"] = 'J'; id["-.-"] = 'K'; id[".-.."] = 'L';
    id["--"] = 'M'; id["-."] = 'N'; id["---"] = 'O';
    id[".--."] = 'P'; id["--.-"] = 'Q'; id[".-."] = 'R';
    id["..."] = 'S'; id["-"] = 'T'; id["..-"] = 'U';
    id["...-"] = 'V'; id[".--"] = 'W'; id["-..-"] = 'X';
    id["-.--"] = 'Y'; id["--.."] = 'Z';
    while (scanf("%s", buff) == 1) {
        int len = strlen(buff), index = 0, cur = 0;
        while (index < len) {
            if (buff[index] == '/' && buff[index+1] != '/') {
                index++;
                code[cur] = '\0';
                string str(code);
                cout << id[str];
                cur = 0;
                continue;
            }
            if (buff[index] == '/' && buff[index+1] == '/') {
                index+=2;
                code[cur] = '\0';
                string str(code);
                cout << id[str];
                cur = 0;
                printf(" ");
                continue;
            }
            code[cur++] = buff[index];
            if (index == len - 1) {
                code[cur] = '\0';
                string str(code);
                cout << id[str] << endl;
            }
            index++;
        }
    }
    return 0;
}
