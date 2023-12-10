#include<stdio.h>
#include <stdbool.h>
struct p_b{
	int id;
	int m;
	bool status;
};

struct p_b p[20];
struct p_b b[20];
void best_fit(int ps,int bs){
	printf("process id\t block no:\n");
	int min=9999,ind;
	for(int i=0;i<ps;i++){
		min=9999;ind=-1;
		for(int j=0;j<bs;j++){
			if(p[i].m<=b[j].m && min>b[j].m && b[j].status==false){
				min=b[j].m;
				ind=j;
				//b[j].m-=p[i].m;
				
			}	
		}
		if(ind!=-1){
			printf("p%d\t\t b%d\n",p[i].id,b[ind].id);
				b[ind].status=true;
				p[i].status=true;	
		}
		if(p[i].status==false ){
			printf("p%d\t\t not allocated\n",p[i].id);
		}
	}
	
	

	
}
int main(){
	
	int bs,ps;
	printf("Enter number of blocks:");
	scanf("%d",&bs);
	printf("enter process number  and size:\n");
	for(int i=0;i<bs;i++){
		scanf("%d %d",&b[i].id,&b[i].m);
	}
	
	printf("Enter number of processes:");
	scanf("%d",&ps);
	printf("enter process number  and memory:\n");
	for(int i=0;i<ps;i++){
		scanf("%d %d",&p[i].id,&p[i].m);
	}
	for(int i=0;i<bs;i++)
		b[i].status=false;
	for(int i=0;i<ps;i++)
		p[i].status=false;
		
	best_fit(ps,bs);

}
/*
1 100
2 500
3 200
4 300
5 600
proce:
1 212
2 417
3 112
4 426

*/





