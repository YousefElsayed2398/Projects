/* Yousef Elsayed   G01259710
    CS262, section 215
    P2, sunrise
*/

#include <stdio.h>
#include <stdlib.h>

int formulaCheck(int a, int b, int c, int d, int r)
{
    int numb = 0;
    int tot = 0;
    tot = abs(a - c) + abs(b - d);
    if (tot <= r)
    {
        numb++;
    }
    return numb;
}

int main(int argc, char **argv)
{

    char kin[1000], k;
    int dx = 0, dy = 0, r, n, i, j, max, maxX = 0, maxY = 0, total, a, b,time = 1;
    int xin, yin, kip, lip;
    int z1,z2,z3,z4;

    int Xcord, Ycord;
    FILE *fo;
    char **grid;
    int *rates;

    FILE *fp;

    if (argv[1] == NULL)
    {
        printf("Error! You must specify input filename: ./p2 <input_filename>\n");
        exit(0);
    }
    fp = fopen(argv[1], "r+");
    fo = fopen("Output.out","w+");
    if (fp == NULL)
    {
        printf("Error! The sunrise.txt file can't be opened\n");
        exit(0);
    }



while(!(z1 == 0) || !(z2 == 0) || !(z3 == 0) || !(z4 == 0)){
    fprintf(fo,"Instance: %d\n",time);
    time++;
    fgets(kin, 1000, fp);
    sscanf(kin, "%d %d %d %d[^\n]", &dx, &dy, &n, &r);
    if (dx <= 1 || dx > 100)
    {
        printf("%d", dx);
        printf("The dx is out of range.\n");
        exit(0);
    }

    if (dy <= 1 || dy > 100)
    {
        printf("The dy is out of range.\n");
        exit(0);
    }

    if (r <= 1 || r > 20)
    {
        printf("The r is out of range.\n");
        exit(0);
    }

    if (n < 0 || n > 8000)
    {
        printf("The n is out of range.\n");
        exit(0);
    }

    rates = (int *)calloc(r, sizeof(int));
    grid = (char **)calloc(dy, sizeof(char *));
    for (i = 1; i <= dx; i++)
    {
        *(grid + i) = (char *)calloc(dx, sizeof(char));
    }
    if(rates == NULL){
        printf("Memory can not be allocated\n");
        exit(0);
    }

    if(grid == NULL){
        printf("Memory can not be allocated\n");
        exit(0);
    }
    /* we know we have r and the ratings and n as the locations
    now i shoudl make a matrix of these points*/

    for (i = 1; i <= dx; i++)
    {
        for (j = 1; j <= dy; j++)
        {
            grid[i][j] = '-';
        }
    }

    for (i = 0; i < n; i++)
    {
        fgets(kin, 1000, fp);
        sscanf(kin, "%d %d %[^\n]", &Ycord, &Xcord, &k);

        grid[Ycord][Xcord] = '*';
    }

    /* so what need to happen is that we need to create a way to
    find the optimal points? so we need a counter to keep track of the highest amount of times that a
    certain loaction on the grid is the right distance away from a store */

    for (i = 0; i < r; i++)
    {
        fgets(kin, 100, fp);
        sscanf(kin, "%d", &(rates[i])); /*   ok  now that we have the rate we need to use this to  find the distances */
    }
    /* 1 2 4 */

    for (i = 0; i < r; i++)
{

        max = rates[i];
        total = 0;
        for (xin = 1; xin <= dx; xin++){
            for (yin = 1; yin <= dy; yin++){
                if (grid[yin][xin] == '*'){
                    a = yin;
                    b = xin;
                    for (kip = 1; kip <= dx; kip++){
                        for (lip = 1; lip <= dy; lip++){
                            if (!(grid[lip][kip] == '*')){
                                maxX = lip;
                                maxY = kip;

                                total = formulaCheck(a, b, maxY, maxX, rates[i]);

                                if (total >= max){
                                    
                                    max = total;
                                    maxY = kip;
                                    maxX = lip;
                                }
                            }
                        }
                    }

                    grid[maxX][maxY] = '$';

                   
                }
                else
                    continue;
            }
        }
                    fprintf(fo,"%d(%d,%d)\n",max,maxX,maxY);
    }

    for (i = dx; i > 0; i--)
    {
        for (j = 1; j <= dy; j++)
        {
            fprintf(fo,"%c ", grid[j][i]);
            
        }
        fprintf(fo,"\n");
    }
    fgets(kin,100,fp);
    sscanf(kin,"%d %d %d %d",&z1,&z2,&z3,&z4);


}

    fclose(fo);
    fclose(fp);
    free(grid);
    free(rates);
    return 0;
}