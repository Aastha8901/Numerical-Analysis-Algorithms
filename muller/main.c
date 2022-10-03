#include<stdio.h>
#include<math.h>

float func(float x)
{
    float y;
    y=x*x*x-27;
    return(y);
}

void main()
{
    float x[3];
    FILE* abc=fopen("input.txt","r");
    for ( int i = 0; i <3; i++)
    {
        fscanf(abc,"%f",&x[i]);
    }
    float A=x[0];
    float B=x[1];
    float C=x[2];
    if (x[0]<x[1] && x[0]<x[2])
    {
        if (x[1]<x[2])
        {
            x[2]=A;
            x[0]=B;
            x[1]=C;
           
        }
        else
        {
            x[2]=A;
            x[0]=C;
            x[1]=B;
           
        }
    }
    else if(x[1]<x[2])
    {
        if (x[0]<x[2])
        {
            x[2]=B;
            x[0]=A;
            x[1]=C;
        }
        else
        {
            x[2]=B;
            x[0]=C;
            x[1]=A;
        }
    }
    else
    {
         if (x[0]<x[1])
        {
            x[2]=C;
            x[0]=A;
            x[1]=B;
        }
        else
        {
            x[2]=C;
            x[0]=B;
            x[1]=A;
        }
    }
    float xr;
    do
    {
        float f2=func(x[2]);
        float f0=func(x[0]);
        float f1=func(x[1]);
        float h1,h2,y,a,b,c;
        h1=x[1]-x[0];
        h2=x[0]-x[2];
        y=h2/h1;
        c=f0;
        a=(y*f1-f0*(1+y)+f2)/(y*h1*h1*(1+y));
        b=(f1-f0-a*h1*h1)/h1;
        if(b*b - 4*a*c <= 0){
            printf("ERROR");
            break;
        }
        if (b>0)
        {
            xr=x[0]-2*c/(b+sqrt(b*b-4*a*c));
        }
        else
        {
            xr=x[0]-2*c/(b-sqrt(b*b-4*a*c));
        }
        if (func(xr)<0.08 && func(xr)>-0.08)
        {
            break;
        }
        else
        {     
           if (xr>x[0])
           {
              if(xr>x[1])
              {
                 x[2]=x[0];
                 x[0]=x[1];
                 x[1]=xr;
              }
              else
              {
                 x[2]=x[0];
                 x[0]=xr;
                 x[1]=x[1];
              }
           }
          else
          {
              if(xr>x[2])
              {
                 x[2]=x[2];
                 x[1]=x[0];
                 x[0]=xr;
              }
              else
              {
                 x[1]=x[0];
                 x[0]=x[2];
                 x[2]=xr;
              }
           }
        }
        
    }while(2>1);
    FILE* pqr=fopen("output.txt","w");
    fprintf(pqr,"%f",xr);
    fclose(abc);
    fclose(pqr); 
}