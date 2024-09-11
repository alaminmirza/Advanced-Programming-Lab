void ThreeD_Array_Input(int mk[10][6][4],int sid[10],int std,int sub,int pt)
{


    int i,j,k;
    for(i=1;i<=std;i++)
     {
         printf("\n student %d id =",i);
         scanf("%d",& sid[i]);

         for(j=1;j<=sub;j++)
         {
             printf("\n sub%d:",j);

             for (k=1;k<=pt;k++)
             {
                 scanf("%d",& mk [i][j][k]);
             }
         }
     }
}
void ThreeD_Array_Display(int mk[10][6][4],int sid[10],int std,int sub,int pt)
{

     int i,j,k;
     for(i=1;i<=std;i++)
     {
         printf("\n ID: %d",sid[i]);

         for(j=1; j<=sub;j++)
         {
             printf("\n subject%d:",j);

             for(k=1;k<=pt;k++)
             {
                 printf("%d\t",mk[i][j][k]);
             }
         }
     }
}
