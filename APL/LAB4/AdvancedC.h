void sub(int sub, char Code[7][10],char Title[7][100], float Cr[7],FILE *fp){
    int i,j;
    for (i=1; i<=sub; i++)
    {
        fscanf(fp,"%[^,],%[^,],%f",Code[i],Title[i],&Cr[i]);
    }
}

void sub_out(int sub, char Code[7][10],char Title[7][100], float Cr[7]){
    int i,j;
    for(j=1; j<=sub; j++)
    {
        printf("%s\t",Code[j]);
        printf("%s\t%.2f\t",Title[j],Cr[j]);
    }
}

void stu(int stu, int s_id[10],char Name[7][100],FILE *fp){
    int i,j;
    for (i=1; i<=stu; i++)
    {
        fscanf(fp,"%d,%[^\n]",&s_id[i],Name[i]);
    }
}

/*void stu_out(int stu, int s_id[10],char Name[7][10]){
    int i,j;
    for(j=1; j<=stu; j++)
    {
        printf("%d\t",s_id[j]);
        printf("%s\n",Name[j]);
    }
}*/














/*void ThreeD_Array_Input(int mk[10][6][4],int sid[10],int std,int sub,int pt,FILE *fp)
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
}*/


