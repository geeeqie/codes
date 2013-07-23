/*
 * calf flac
 *
 * @author Qiu Ying <qiuying@mail.nwpu.edu.cn>
 * @date 2013/06/23
 * @description
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

enum {
    LINEMAX = 20001,
};

char line[LINEMAX];
char lines[LINEMAX];
char lines1[LINEMAX]; /* only a-zA-Z is reserved */
int len;
int origin_pos[LINEMAX];

typedef struct region {
    int start;
    int end;
} region;

int find_max_palindrome_at_center(char *seq, int l, int center, region &r)
{
    int count1 = -1;
    int count2 = 0;
    region r1;
    region r2;

    for (int i = 0; center-i >= 0 && center+i < l; i++) {
        if (seq[center-i] != seq[center+i])
            break;
        count1 += 2;
        r1.start = center - i;
        r1.end = center + i;
    }

    for (int i = 0; center-i >= 0 && center+i+1 < l; i++) {
        if (seq[center-i] != seq[center+i+1])
            break;
        count2 += 2;
        r2.start = center - i;
        r2.end = center + i + 1;
    }

    int count;
    if (count1>count2) {
        count = count1;
        r = r1;
    } else {
        count = count2;
        r = r2;
    }
    return count;
}

int find_max_palindrome(char *seq, int l, region &max_r)
{
    int max = 0;

    for (int i = 0; i < l; i++) {
        region r;
        int pl = find_max_palindrome_at_center(seq, l, i, r);
        if (pl > max) {
            max = pl;
            max_r = r;
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    while(fgets(line, LINEMAX, stdin)) {
        strcat(lines, line);
    }

    for (int i = 0; i < LINEMAX; i++) {
        if (isalpha(lines[i])) {
            origin_pos[len] = i;
            lines1[len++] = tolower(lines[i]);
        }
    }
    lines1[len] = 0;
    region r;
    printf("%d\n", find_max_palindrome(lines1, len, r));
    lines[origin_pos[r.end] + 1] = 0;
    printf("%s\n", lines + origin_pos[r.start]);

    return 0;
}
