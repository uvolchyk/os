#include <cstdio>
#include <cstring>
 
using namespace std;
 
char strings1[1000][100];
char strings2[1000][100];
 
int main()
{
    char ch;
    char pr;
    int k = 0, m = 0;
    int p = 0, n = 0;
    do
    {
        scanf("%c", &ch);
 
        if (ch == ' ' && pr != ' ')
        {
            k++;
            m = 0;
        }
        else
        {
            strings1[k][m] = ch;
            m++;
        }
 
        pr = ch;
    } while (ch != '\n');
    k++;
 
 
    do
    {
        scanf("%c", &ch);
 
        if (ch == ' ' && pr != ' ')
        {
            p++;
            n = 0;
        }
        else
        {
            strings2[p][n] = ch;
            n++;
        }
 
        pr = ch;
    } while (ch != '\n');
    p++;
 
    printf("In the first line %d words\n", k);
    printf("In the second line %d words\n", p);
 
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (strcmp(strings1[i], strings2[j]) == 0)
            {
                printf("%s ", strings1[i]);
            }
        }
    }
    printf("\n");
    return 0;
}