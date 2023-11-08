#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//********** Specification of replace **********
void replace(char s[], char x[], char y[]);
/* Precondition: s, x and y are three strings,
                and s has enough memory to store modified string
   Postcondition: replace all substring x with y in string s
*/

int find(char s[], char x[], int beg)
{
    int slen = strlen(s), xlen = strlen(x);
    if (xlen > slen - beg) {
        return -1;
    }
    else {
        for (int i = beg; i <= slen - xlen; i++) {
            int j{ 0 }, k{ i };
            for (; j < xlen && s[k] == x[j]; k++, j++);
            if (j == xlen) return i;
        }
        return -1;
    }
}

void replace(char s[], char x[], char y[])
{ //TODO: your function definition
    int slen = strlen(s), xlen = strlen(x), ylen = strlen(y);
    int dx = ylen - xlen;
    for (int i = slen; i < 241; i++) {
        s[i] = 0;
    }

    for (int i = 0; i < slen; i++) {
        int idx{ find(s, x, i) };
        if (idx != -1) {
            if (dx == 0) {
                for (int j = idx; j < xlen + idx; j++) {
                    s[j] = y[j - idx];
                }
            }
            else if (dx > 0) {
                for (int j = slen + dx - 1; j >= idx + xlen; j--) {
                    s[j] = s[j - dx];
                }
                for (int j = idx; j < idx + ylen; j++) {
                    s[j] = y[j - idx];
                }
            }
            else {
                for (int j = idx + xlen + dx; j < slen + dx; j++) {
                    s[j] = s[j - dx];
                }
                for (int j = idx; j < idx + ylen; j++) {
                    s[j] = y[j - idx];
                }
            }
            slen += dx;
            i = idx;
            i += ylen - 1;
        }
    }
    s[slen] = 0;
}

#define N 80

int main()
{
    char s[3 * N + 1], x[N + 1], y[N + 1];
    scanf("%s%s%s", s, x, y);
    replace(s, x, y);
    printf("%s\n", s);
    return 0;
}
