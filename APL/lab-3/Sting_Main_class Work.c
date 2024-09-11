#include <stdio.h>
int main()
{
    int subject,n[7],i;
    char code[7][10],title[7][100],rem[7][50];
    float cr[7];
    FILE *input;
    input=fopen("data.txt","r");
    if(input==NULL)
    {
        printf("File could not be opened\n\n");
        return 0;
    }
    fscanf(input,"%d",&subject);
    for(i=1; i<=subject; i++)
    {
      fscanf(input,"%d,%[^,],%[^,],%f,%[^\n]",&n[i],code[i],title[i],&cr[i],rem[i]);
    }

    for(i=1;i<=subject;i++)
    {
     printf("%d %s\t%.2f\t%s\t%s\n",n[i],code[i],cr[i],rem[i],title[i]);
    //printf("%d\t%s\t",n[i],code[i]);
    //printf("%s\t%f\t",title[i],cr[i]);
    //printf("%s\n",rem[i]);
    }
    fclose(input);
}
