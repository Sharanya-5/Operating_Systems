#include<stdio.h>
//#include<limits.h>
struct process{
	int pn;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int reached; 

};
struct process p[10];

int min_bt(int temp_ct,int n){
	int ind=-1,count_p=1,min_bt=1000;
	for(int i=1;i<=n;i++){
		if(p[i].reached!=1&& p[i].at<=temp_ct){
			if(min_bt>p[i].bt){
				min_bt=p[i].bt;
				ind=i;
			}
			else if(min_bt==p[i].bt){
				if(p[ind].at>p[i].at){
					min_bt=p[i].bt;
					ind=i;
				}
			}
		
		}
	
	}
	return ind;
	
	

}
void sjf(int n){
	int temp_ct=0,count=1,min_ind;
	for(int i=1;i<=n;i++)
		p[i].reached=0;
	while(count<=n){
		min_ind=min_bt(temp_ct,n);
		if(min_ind==-1){
			printf("-IDLE-");
			temp_ct++;
			printf("%d",temp_ct);
		
		}
		else{
			printf("-p%d",p[min_ind].pn);
			p[min_ind].ct=temp_ct+p[min_ind].bt;
			temp_ct=p[min_ind].ct;
			count++;
			p[min_ind].reached=1;
			p[min_ind].tat=p[min_ind].ct-p[min_ind].at;
			p[min_ind].wt=p[min_ind].tat-p[min_ind].bt;
			printf("\n%d",temp_ct);
		
		}
	
	
	}



}

int main(){
	int n;
	printf("Enter the number of processors:");
	scanf("%d",&n);
	printf("Enter the pno,at,bt:");
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&p[i].pn,&p[i].at,&p[i].bt);
	}
	sjf(n);
	float avg_tat=0,avg_wt=0;
	printf("\npno\t at\t bt\t ct\t tat\t wt\t \n");
	for(int i=1;i<=n;i++){
		printf("p%d\t %d\t %d\t %d\t %d\t %d\t",p[i].pn,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
		printf("\n");
		avg_tat+=p[i].tat;avg_wt+=p[i].wt;
	
	}
	avg_tat/=n;avg_wt/=n;
	printf("Avg tat %f \n Avg wt %f", avg_wt,avg_tat);
	
	
	
	
	




}

/*
1 8 2
2 3 2
3 6 2
4 2 8
5 5 3
6 4 1
7 2 6


*/




