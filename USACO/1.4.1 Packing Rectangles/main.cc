#include <cstdio>
#include <vector>

using namespace std;

struct rect {
    int width; /* suppose width <= height */
    int height;
};

vector<rect> rects;

int min_area(vector<rect> rects)
{
    
    return 0;
}

int main(int argc, char const *argv[])
{
    int a, b;

    while(scanf("%d%d", a, b) != EOF) {
        rect r;
        r.width = (a < b) ? a : b;
        r.height = (a > b) ? a : b;
        rects.push_back(r);
    }

    printf("%d\n", min_area(rects));

    return 0;
}
