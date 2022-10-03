#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    FILE* abc=fopen("input.txt","r");
    float *x,*fx;
    if (abc==NULL)
    {
        printf("The file is empty");
    }
    int n;
    fscanf(abc,"%d",&n);
    x= (float*)calloc(n+1,sizeof(float));
    fx= (float*)calloc(n,sizeof(float));
    for(int i=0; i<n; i++)
    {
        fscanf(abc, "%f %f", &x[i],&fx[i]);
    }
    fscanf(abc, "%f" , &x[n]); 
    float Sum=0,y=x[n];
    
    for (int k = 0; k < n; k++)
    {
        float p=1;
        for (int j = 0; j < n; j++)
        {
            if(k != j)
            {
                p=p*(y-x[j])/(x[k]-x[j]);
            }
        }
        Sum = Sum + p*fx[k];
    }
    FILE *pqr=fopen("output.txt","w");
    fprintf(pqr,"%f",Sum);
    fclose(abc);
    fclose(pqr);
    free(x);
    free(fx);
}
