#include<stdio.h>
struct process
{
    int wt,at,bt,tat,pt;
};

struct process a[10];

int main()
{
    int n,temp[10],t,count=0,s;
    
    float twt=0,tat=0,avgwt,avgtat;
    
    printf("Enter the number of the process");
    
    scanf("%d",&n);
    
    printf("Enter the arrival time , burst time and priority of the process\n");
   
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&a[i].at,&a[i].bt,&a[i].pt);
        
        
        temp[i]=a[i].bt;
    }
    a[9].pt=1000;
    for(t=0;count!=n;t++)
    {
        s=9;
        for(int i=0;i<n;i++)
        {
            if(a[s].pt>a[i].pt && a[i].at<=t && a[i].bt>0)
            {
                s=i;
            }
        }
        a[s].bt=a[s].bt-1;
        
        
        if(a[s].bt==0)
        {
            count++;
            a[s].wt=t+1-a[s].at-temp[s];
            a[s].tat=t+1-a[s].at;
            twt=twt+a[s].wt;
            tat=tat+a[s].tat;
            
        }
    }
    avgwt=twt/n;
    avgtat=tat/n;
  
    printf("id wt tat\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %d %d\n",i+1,a[i].wt,a[i].tat);
    }
    
    printf("average waiting time %f\n",avgwt);
    printf("avearge turn around time %f\n",avgtat);
    
    }
    
     
