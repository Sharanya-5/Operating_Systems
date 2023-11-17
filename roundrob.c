#include<stdio.h>
struct Process{
     int at;
     int bt;
     int id;
     int rt;
     int twt;
    int tat;
     };
 struct Process a[10];
int main()
{
   int b[10];
     int n,q,c=0,ct=0;
     float avgwt,avgtat,twt=0,tat=0;
     printf("enter no.of processes:");
     scanf("%d",&n);
     printf("enter time quantum:");
     scanf("%d",&q);
     printf("ID AT BT\n");
     for(int i=0;i<n;i++)
     {
     //a[i].id=i+1;
     scanf("%d %d %d",&a[i].id,&a[i].at,&a[i].bt);
     printf("\n");
     
     a[i].rt=a[i].bt;
     
     }
     
     
     
    
     while(c<n)
     {
        for(int i=0;i<n;i++)
        {
          if(a[i].rt>0)
          {
          
           
          int et=a[i].rt<q?a[i].rt:q;
         
          a[i].rt-=et;
          b[i]=a[i].rt;
          ct=ct+et;
      
          if(a[i].rt==0)
          {
                               
              printf("ct %d\n",ct);
               a[i].tat=ct-a[i].at;
           
               a[i].twt=ct-a[i].bt-a[i].at;
              
               
               c++;
               
           }
          }
          
          
      }
      }     
         
         printf("ID TAT WT\n");
         for(int i=0;i<n;i++)
         {
         
         printf("%d %d %d",i+1,a[i].tat,a[i].twt);
            	  tat=tat+a[i].tat;
       	  twt=twt+a[i].twt;
           printf("\n");
         }  
         avgwt=twt/n;
         avgtat=tat/n;
         printf("avg wt is %.2f\n",avgwt);
         printf("avg tat is %.2f\n",avgtat);
        } 
             
                 
     
         
          
