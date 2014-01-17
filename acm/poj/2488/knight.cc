/*
 * DFS, 注意要按字典序搜索，搜到结果马上折回。
 * 题目规定面积p*q <= 26，因此，DFS是可行的。
 *
 */
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int n, p, q;
bool board[26][26];

struct node {int x, y;};

bool found;

void search(int x, int y, vector<node>& path)
{
//    printf("search %d %d\n", x, y);
    if (board[x][y] || found) return;

    board[x][y] = true;

    node nd; nd.x = x; nd.y = y;
    path.push_back(nd);

    if (path.size() == p*q) {
        for (int i = 0; i < path.size(); i++) {
            printf("%c%d", path[i].y+'A', path[i].x+1);
        }
        cout<<endl;
        found = true;
        goto end;
    }

    //down
    if (y-2 >= 0) {
        if (x-1 >= 0) search(x-1, y-2, path); //down left
        if (x+1 < p)   search(x+1, y-2, path); //down right
    }
    //left down
    if ((x - 2 >= 0) && (y-1 >= 0)) search(x-2, y-1, path);

    //right down
    if ((x+2 < p) && (y-1 >= 0)) search(x+2, y-1, path);

    //left up
    if ((x - 2 >= 0) && (y+1 < q))  search(x-2, y+1, path);

    //right up
    if ((x+2 < p) && (y+1 < q))  search(x+2, y+1, path);

    // up
    if (y+2 < q) {
        if (x - 1 >= 0) search(x-1, y+2, path); //up left
        if (x+1 < p)    search(x+1, y+2, path); //up right
    }
end:
    board[x][y] = false;
    path.pop_back();
}

int main(void)
{
    scanf("%d", &n);
    vector<node> path;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p, &q);
        printf("Scenario #%d:\n", i+1);
        found = false;
        for (int x = 0; x < p; x++) {
            for (int y = 0; y < q; y++) {
                if (!found)
                    search(x, y, path);
            }
        }
        if (!found) {
            cout<<"impossible"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
