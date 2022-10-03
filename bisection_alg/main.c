#include<stdio.h>
#include<math.h>
float func(float x)
{
    float y;
    y=sin(x);
    return y;
} 

void main()
{
    float a,b,c;
    FILE* abc=fopen("input.txt","r");
    fscanf(abc,"%f",&a);
    fscanf(abc,"%f",&b);
    FILE* pqr=fopen("output.txt","w");
    if ((func(a)<0 && func(b)>0) || (func(a)>0 && func(b)<0))
    {
        while((b-a)>0.0002 || (b-a)<-0.0002)
        {
            c=(a+b)/2;
            if ((func(a)<0 && func(c)>0) || (func(a)>0 && func(c)<0))
            {
                b=c;
            }
            else if ((func(b)<0 && func(c)>0) || (func(b)>0 && func(c)<0))
            {
                a=c;
            }
            else if (func(c)==0)
            {
                break;
            }
        }
        fprintf(pqr,"The root is %f",c);
    }
    else if (func(a)==0)
    {
        fprintf(pqr,"The root is %f",a);
    }
    else if (func(b)==0)
    {
        fprintf(pqr,"The root is %f",b);
    }
    else
    {fprintf(pqr,"There is no root in the interval");}
}