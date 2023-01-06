#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,c,d,res,t,i,one,two,three,four;
    printf("Enter co-efficient of x^3 :");
    scanf("%d",&a);
    printf("Enter co-efficient of x^2 :");
    scanf("%d",&b);
    printf("Enter co-efficient of x :");
    scanf("%d",&c);
    printf("Enter constant :");
    scanf("%d",&d);
    one=a,two=b,three=c,four=d;
    for(t=-10;t<=10;t++)
    {
        if(t!=0)
        {
            a=a;
            b-=(a*t);
            c-=(b*t);
            d-=(c*t);
            if(d==0)
            {
                printf("%d,(%d,%d,%d)\n",t,a,b,c);
                break;
            }
            else
            {
                a=one,b=two,c=three,d=four;
            }
        }
    }
}
