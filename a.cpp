#include<stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int n[17];
    n[0] = 56;
    n[1] = 56;
    n[2] = 57;
    n[3] = 48;
    n[4] = 48;
    n[5] = 48;
    n[6] = 49;
    n[7] = 72;
    n[8] = 49;
    n[9] = 53;
    n[10] = 83;
    n[11] = 49;
    n[12] = 80;
    n[13] = 72;
    n[14] = 71;
    n[15] = 77;
    n[16] = 76;

    char ch[17];

    for(int i = 0; i < 17; i++)
    {
        ch[i] = (char)n[16 -i];
        cout << ch[i];
    }
    cout << endl;

    return 0;
}