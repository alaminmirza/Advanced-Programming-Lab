void ThreeD_Array_Input(int mk[10][6][4],int sid[10],int std,int sub,int pt,FILE *fp)
{
    int i,j,k;
    for(i=1;i<=std;i++)
    {
        fscanf(fp,"%d",&sid[i]);
        for(j=1;j<=sub;j++)
        {
            for(k=1;k<=pt;k++)
            {
                fscanf(fp,"%d",&mk[i][j][k]);
            }
        }
    }
}
void ThreeD_Array_Display(int mk[10][6][4],int sid[10],int std,int sub,int pt)
{
    int i,j,k;
    for(i=1;i<=std;i++)
    {
        printf("\n\nId:  %d",sid[i]);
        for(j=1;j<=sub;j++)
        {
            printf("\nSub%d:\t",j);
            for(k=1;k<=pt;k++)
            {
                printf("%d\t",mk[i][j][k]);
            }
        }
    }
}

