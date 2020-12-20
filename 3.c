#include <stdio.h>
#include <stdlib.h>
const int n=3;
int main()
{
    int n, m, i, j, p;
    printf("Convert matrix to array 1, or array to matrix 0.\n");
    scanf("%d", &p);
    printf("Enter the dimensions.\n");
    scanf("%d%d", &n, &m);
   int **a =(int **)malloc(n*sizeof(int*));
   for(int i=0; i<n; i++)
   {
       a[i] =(int *)malloc(m*sizeof(int));
   }

    int *b =(int *)malloc((n*m)*sizeof(int));
    if (p)
    {
        printf("Enter the matrix.\n");
        for(i=0; i<n; i++)
            for(j=0; j<m; j++) scanf("%d", &a[i][j]);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++) b[i*m+j]=a[i][j];
        printf("\n");
        for (i=0; i<n*m; i++) printf("%d ", b[i]);
    }
    else
    {
        printf("Enter an array.\n");
        for (i=0; i<n*m; i++) scanf("%d", &b[i]);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++) a[i][j]=b[i*m+j];
        for(i=0; i<n; i++)
        {
            printf("\n");
            for(j=0; j<m; j++) printf("%4d", a[i][j]);
        }
    }
   for(i=0; i<n; i++)
   {
       free(a[i]);
   }
    free(a);
    free(b);
    return 0;
}
