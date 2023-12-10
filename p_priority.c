#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
struct process{
	int pn;
	int at;
	int bt;
	int real_bt;
	int ct;
	int tat;
	int wt;
	int pri;
	int reached;

};
struct process p[10];
int fnd_min_index(int tempc,int n){
	int ind=-1,min=999;
	for(int i=1;i<=n;i++){
		if(p[i].at<=tempc && p[i].reached==false){
			if(min>p[i].pri ){
				min=p[i].pri;
				ind=i;
			}
			else if(min==p[i].pri){
				if(p[i].at<p[ind].pri){
					min=p[i].pri;
					ind=i;
				}
			}
		}
	}
	return ind;
}
void pp(int n){
	int count=0,tempc=0,min_ind=0;
	for(int i=0;i<n;i++){
		p[i].reached=false;
		
	}
	while(count<n){
		min_ind=fnd_min_index(tempc,n);
		if(min_ind==-1)
		{
			printf("-IDLE-");
			tempc++;
		}
		else{
			p[min_ind].bt--;
			tempc++;
			printf("p%d",p[min_ind].pn);
			if(p[min_ind].bt==0){
				p[min_ind].ct=tempc;
				p[min_ind].tat=p[min_ind].ct-p[min_ind].at;
			    	p[min_ind].wt=p[min_ind].tat-p[min_ind].real_bt;
			    	count++;
			    	p[min_ind].reached=true;
			}
		}
	
	
	}

}

int main(){
	int n;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter the pno,priority,at,bt:");
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&p[i].pn,&p[i].pri,&p[i].at,&p[i].bt);
	}
	for(int i=1;i<=n;i++)
		p[i].real_bt=p[i].bt;
	//pp(n);
	
	
	
	float avg_tat=0,avg_wt=0;
	printf("\npno\t pri\tat\t bt\t ct\t tat\t wt\t \n");
	for(int i=1;i<=n;i++){
		printf("p%d\t %d\t %d\t %d\t %d\t %d\t %d\t",p[i].pn,p[i].pri,p[i].at,p[i].real_bt,p[i].ct,p[i].tat,p[i].wt);
		printf("\n");
		avg_tat+=p[i].tat;avg_wt+=p[i].wt;
	
	}
	avg_tat/=n;avg_wt/=n;
	printf("Avg tat %f \n Avg wt %f", avg_wt,avg_tat);
	

}
/*
1 5 1 4
2 2 2 5
3 6 3 6
4 4 0 1
5 7 4 2
6 8 5 3


*/

/*
1 2 0 4
2 4 1 2
3 6 2 3
4 1 3 5
5 8 4 1
6 3 5 4
7 2 11 6
*
/
