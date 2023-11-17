#include <stdio.h>
#include <stdbool.h>
struct process {
	int pn;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	bool x;
};

struct process p[10];

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int find_min_bt(int n,int tempct)
{
	int min=100,i,index=-1;
	for(i=0;i<n;i++)
	{
            if(p[i].x!=true && p[i].at<=tempct)
            {
		      if(p[i].bt<min)
		      {
		        min=p[i].bt;
		        index=i;
		      }
		    }
	}

	return index;
}

void sjf(int n)
{
	int count=0;
	int tempct=0,ind;
	while(count!=n)
	{
		ind=find_min_bt(n,tempct);
		
		if(ind==-1)
		{
			printf("-Idle-");
			tempct++;
		}
		else
		{
			printf("P%d ",p[ind].pn);
			count++;
			p[ind].x=true;
			p[ind].ct=p[ind].bt+tempct;
			tempct=p[ind].ct;
			
			p[ind].tat=p[ind].ct-p[ind].at;
			p[ind].wt=p[ind].tat-p[ind].bt;
		}
	}
	printf("\n");
}
int main()
{
	int i,n;
	printf("Enter the no. of processes:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		p[i].x=false;
	}
	
	printf("Enter the pno.,arrival time,burst time:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&p[i].pn,&p[i].at,&p[i].bt);
	}
	
	//sort(n);
	sjf(n);
	
	for(i=0;i<n;i++)
	{
		printf("P%d %d %d %d %d %d\n",p[i].pn,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	float avgAT=0,avgWT=0;
	for(i=0;i<n;i++)
	{
		avgAT=avgAT+p[i].tat;
		avgWT=avgWT+p[i].wt;
	}
	avgAT=avgAT/n;
	avgWT=avgWT/n;
	printf("AVG Turn around time:%0.3f\n",avgAT);
	printf("AVG Waiting timw:%0.3f",avgWT);
}

/*
1 4 4
2 8 2
3 6 3
4 5 3
5 2 1
6 7 7
*/

/*
1 3	4
2 5	3
3 0	2
4 5	1
5 4	3
*/
