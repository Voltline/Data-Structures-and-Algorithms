#define M 100
//********** Specification of SortLines**********
void SortLines(int(*p)[M], int n, int m);
/* PreCondition:
p points to a two-dimensional array with n lines and
m integers in each line
PostCondition:
array is sorted satisfying to the specification
*/

/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
#define N 100
int calc_sum(int* p, int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += p[i];
    }
    return sum;
}

void swap_line(int* p1, int* p2, int m)
{
    for (int i = 0; i < m; i++) {
        int tmp = p1[i];
        p1[i] = p2[i];
        p2[i] = tmp;
    }
}
//********** Specification of SortLines **********
void SortLines(int(*p)[M], int n, int m)
/* PreCondition:
p points to a two-dimensional array with n lines and
m integers in each line
PostCondition:
array is sorted satisfying to the specification
*/
{   //TODO: your function definition
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum1 = calc_sum(p[i], m), sum2 = calc_sum(p[j], m);
            if (sum1 > sum2) {
                swap_line(p[i], p[j], m);
            }
            else if (sum1 == sum2) {
                int k = 0;
                while (k < m && p[i][k] == p[j][k]) {
                    k++;
                }
                if (k < m && p[i][k] > p[j][k]) {
                    swap_line(p[i], p[j], m);
                }
            }
        }

    }
}
/***************************************************************/
int main()
{
    int a[N][M];
    int n, m, i, j;
    int t, cas;
    scanf("%d", &cas);
    for (t = 0; t < cas; t++)
    {
        memset(a, 0, sizeof(a));
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        /***** function SortLines is called here *****/
        SortLines(a, n, m);
        /****************************************/
        printf("case #%d:\n", t);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                printf("%d%c", a[i][j], j < m - 1 ? ' ' : '\n');
    }
    return 0;
}
