 /*
    This program is based on the following formula:
    pi = 2 + 1/3 * (2 + 2/5 * (2 + 3/7 * (2 + ...  (2 + k/2k+1 * (2 + ... ))...)))
*/

#include <stdio.h>
#include <stdlib.h>

const int a = 10000;
int b, c, d, e, g, ind = 1, end;
int *f = NULL;
int *res = NULL;

int main()
{

    int i;

    puts("Please input the digits:");
    if(scanf("%d", &c) != 1) return EXIT_FAILURE;

    if(c <= 0) return EXIT_FAILURE;
    puts("\n");
    if(c < 4) c = 4, puts("Fixed to 4 digits");
    else if(c % 4 != 0){
        c += 4 - c % 4;
        printf("Fixed to %d digits\n", c);
    }

    end = c / 4;
    res = (int*) malloc((c + 1) * sizeof(int));
    if(res == NULL) return EXIT_FAILURE;

    c /= 4;
    c *= 14;

    f = (int*) malloc((c + 1) * sizeof(int));
    if(f == NULL) return EXIT_FAILURE;

    for(i = 0; i < c; ++i)  f[i] = 2000;

    while(c != 0) {
            d = 0;
            g = c << 1;
            b = c;

            while(1) {
                    d += f[b] * a;
                    --g;
                    f[b] = d % g;
                    d /= g;
                    --g;
                    --b;

                    if(b == 0) break;

                    d *= b;
            }

            c -= 14;
            res[ind++] = e + d / a;
            e = d % a;
    }

    printf("3.141");

    for(i = 2; i <= end; ++i) printf("%.4d", res[i]);

    free(f);
    free(res);

    return EXIT_SUCCESS;
}
