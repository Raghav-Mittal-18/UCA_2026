#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long e1 = 2;
    long long e2 = 8;
    long long sum = 0;

    while (e1 <= n) {
        sum += e1;

        long long next = 4 * e2 + e1;
        e1 = e2;
        e2 = next;
    }

    printf("%lld\n", sum);

    return 0;
}
