#include<stdio.h>
#include<limits.h>
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
int find_min_index(int temp_ct,int n){	
	int ind=-1,min=1000;
	for(int i=1;i<=n;i++){
		if(p[i].reached!=1 && p[i].at<=temp_ct){
			if(min>p[i].bt){
				min=p[i].bt;
				ind=i;
			}
			else if(min==p[i].bt){
				if(p[ind].at>p[i].at){
					min=p[i].bt;
					ind=i;
				}
			}
		
		}
	
	}
	//printf("ind %d",ind);
	return ind;
	


}

void srtf(int n){
	int temp_ct=0,min_ind,count=1;
	for(int i=1;i<=n;i++)	
		p[i].reached=0;
	while(count<=n){
		min_ind=find_min_index(temp_ct,n);
		if(min_ind==-1){
			printf("-IDLE-");
			temp_ct++;
		}
		else{
			printf("-p%d",p[min_ind].pn);
			/*if(temp_ct>p[min_ind].bt){
				
				p[min_ind].ct=temp_ct+p[min_ind].bt;
				temp_ct=p[min_ind].ct;
				p[min_ind].bt=p[min_ind].bt-p[min_ind].bt;
				
			}*/
			{
				p[min_ind].ct=temp_ct+1;
				temp_ct=p[min_ind].ct;
				p[min_ind].bt-=1;
			}
			if(p[min_ind].bt==0){	
				p[min_ind].reached=1;	
				count++;
				p[min_ind].tat=p[min_ind].ct-p[min_ind].at;
				p[min_ind].wt=p[min_ind].tat-p[min_ind].bt;
			}	
		
		}		
		//count++;

	}
	
}
int main(){
	int n;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter the pno,at,bt:");
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&p[i].pn,&p[i].at,&p[i].bt);
	}
	srtf(n);
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
