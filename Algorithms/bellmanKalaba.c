#include <stdio.h>

#define m 20

int main()
{

    int A[m][m];
    int V[m][m];
    int L[m];
    int i, j, n, e, w, k, ch, min, r, startNode, destNode;

    printf("Introdu numarul de virfuri : ");
    scanf("%d", &n);
    printf("Introdu numarul de arce: ");
    scanf("%d", &e);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            A[i][j] = 1000;
        }
    }

    for (i = 0; i < m; i++)
    {
        A[i][i] = 0;
    }

    for (k = 0; k < e; k++)
    {
        scanf("%d%d%d", &i, &j, &w);
        A[i - 1][j - 1] = w;
    }

    printf("introdu virful initial : ");
    scanf("%d", &startNode);
    printf("introdu virful final : ");
    scanf("%d", &destNode);
    startNode--;
    destNode--;

    for (i = 0; i <= destNode; i++)
    {
        V[0][i] = A[i][destNode];
    }

    k = 1;

    do
    {
        ch = 0;
        for (i = 0; i <= destNode; i++)
        {
            min = 1000;
            for (j = 0; j <= destNode; j++)
            {
                if (i == j)
                    continue;
                if (A[i][j] + V[k - 1][j] < min)
                    min = A[i][j] + V[k - 1][j];
            }
            V[k][i] = min;
        }
        V[k][destNode] = 0;
        for (i = 0; i <= destNode; i++)
        {
            if (V[k][i] != V[k - 1][i])
            {
                ch = 1;
                break;
            }
        }
        k++;
    } while (ch == 1);
    k--;

    for (i = 0; i < m; i++)
    {
        L[i] = 0;
    }

    r = 0;
    i = startNode;
    j = 0;
    L[r++] = i + 1;

    for (; i != destNode;)
    {
        if (i == j)
            j++;
        if (V[k][i] - A[i][j] == V[k][j])
        {
            L[r++] = j + 1;
            i = j;
            j = 0;
        }
        else
            j++;
    }

    L[r] = V[k][startNode] - V[k][destNode];

    printf("\nDrumul este : ");
    for (i = 0; L[i + 1] != 0; i++)
    {
        printf("%d", L[i]);
        if (L[i + 2] != 0)
            printf("->");
    }
    printf("\nLungimea drumului : ");
    printf("%d", L[i]);

    return 0;
}
