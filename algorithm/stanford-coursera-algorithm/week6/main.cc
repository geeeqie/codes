#include <cstdio>
#include <vector>

using namespace std;

#define HASH_MAX 100000001
struct hash_element {
    bool is_hashed;
    long value;
};
hash_element a[HASH_MAX];
vector<long> values;

long hash(long v)
{
    return (unsigned long)v % HASH_MAX;
}
void hash_add(long v)
{
    int h = hash(v);
    while (a[h].is_hashed) {
       h++; 
    }
    a[h].value = v;
    a[h].is_hashed = true;
}
bool hash_lookup(long v)
{
    long h = hash(v);
    while (1) {
        if (!a[h].is_hashed)
            return false;
        if (a[h].value == v)
            return true;
        h++;
    }
}

bool satisfy(long t)
{
    for (vector<long>::iterator it = values.begin(); it != values.end(); it++) {
        long y = t - *it;
        if (hash_lookup(y)) {
            return true;
        }
    }
    return false;
}

int main(void)
{
    long v;

    while(scanf("%ld", &v) != EOF) {
        hash_add(v);
        values.push_back(v);
    }

    long count = 0;

    for (long t = -10000; t <= 10000; t++) {
        printf("%ld\n", t);
        if (satisfy(t)) {
            count++;
        }
    }
    printf("+++COUNT+++\n");
    printf("%ld\n", count);
}
