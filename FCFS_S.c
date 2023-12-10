#include<stdio.h>
#include<stdbool.h>
struct process{
	int pno;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	bool r;
	
};
struct process p[10];
int find_ind(int tempct,int n ){
	int ind=-1,min=1000;
	for(int i=0;i<n;i++){
		if(p[i].at<=tempct && p[i].r==false){
			if(min>p[i].at){
				min=p[i].at;
				ind=i;
			}
		}
	}
	return ind;

}

void fcfs(int n){
	int tempct=0,ind=0,count=1;
	while(count<=n){
		ind=find_ind(tempct,n);
		if(ind==-1){
			printf("-IDLE-");
			tempct++;	
		}
		else{
			printf("p%d |",p[ind].pno);
			tempct+=p[ind].bt;
			p[ind].ct=tempct;
			p[ind].r=true;
			p[ind].tat=p[ind].ct-p[ind].at;
			p[ind].wt=p[ind].tat-p[ind].bt;
			count++;
		}
	
	}

}
int main(){
	int n;
	printf("enter n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&p[i].pno,&p[i].at,&p[i].bt);
	fcfs(n);
	printf("\n");
	printf("\npno\t at\t bt\t ct\t tat\t wt\t");
	for(int i=0;i<n;i++){
		printf("\n%d\t %d\t %d\t %d\t %d\t %d\t ",p[i].pno,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	
	}
	


}
/*
1 4 2                                                                       
2 10 1
3 15 2
4 20 3
5 28 8
*/
/*

6
1 5 3
2 8 6
3 3 3 
4 6 1
5 2 2
6 4 5



*/



