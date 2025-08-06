#include<stdio.h>
#include<conio.h>
void prims(int cost[10][10],int n)
{
 int a,b,i,j,k,min=99,t_c=0,near[10];
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(cost[i][j]<min)
   {
    min=cost[i][j];
     a=i;
     b=j;
   }
  }
 }
     printf("%d - %d\n",a,b);
     t_c=t_c+cost[a][b];
     for(i=1;i<=n;i++)
     {
        if(cost[i][a]<cost[i][b])
        {
           near[i]=a;
        }
        else near[i]=b;
     }
     near[a]=0;
     near[b]=0;
     for(i=2;i<=n-1;i++)
     {
         min=99;   
      for(k=1;k<=n;k++)
      {
        if((near[k]!=0)&&(cost[k][near[k]]<min))
        {
            j=k;
            min=cost[j][near[j]];
        }
        }
        printf("%d - %d\n",j,near[j]);
           t_c=t_c+cost[j][near[j]];
           near[j]=0;
        for(k=1;k<=n;k++)
     {
      if(near[k]!=0)
      {
       if(cost[k][near[k]]>cost[k][j]) near[k]=j;
       }
     }
     }

     printf("total cost : %d",t_c);
}
int main()
{
    int n1,cost[10][10],i,j;
    printf("enter the total no.of vertices:");
    scanf("%d",&n1);
    printf("enter the cost values in matrix:\n");
    for(i=1;i<=n1;i++)
    {
            for(j=1;j<=n1;j++)
            {
                    scanf("%d",&cost[i][j]);
            }
    }
    prims(cost,n1);
    getch();
    return 0;
}
         
