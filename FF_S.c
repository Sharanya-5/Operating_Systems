#include<stdio.h>
#include <stdbool.h>
struct p_b{
	int id;
	int m;
	bool status;
};

struct p_b p[20];
struct p_b b[20];
void first_fit(int ps,int bs){
	printf("process id\t bolck no:\n");
	for(int i=0;i<ps;i++){
		for(int j=0;j<bs;j++){
			if(p[i].m<=b[j].m && b[j].status==false){
				printf("p%d\t\t b%d\n",p[i].id,b[j].id);
				b[j].status=true;
				p[i].status=true;
				break; //if break not mentioned then mention cnd in if case (p[i].status==false
			}
		}
		if(p[i].status==false){
			printf("p%d\t not allocated\n",p[i].id);
		}
	}

	
}
int main(){
	
	int bs,ps;
	printf("Enter number of blocks:");
	scanf("%d",&bs);
	printf("enter process id/number  and size:\n");
	for(int i=0;i<bs;i++){
		scanf("%d %d",&b[i].id,&b[i].m);
	}
	
	printf("Enter number of processes:");
	scanf("%d",&ps);
	printf("enter process id/number  and memory:\n");
	for(int i=0;i<ps;i++){
		scanf("%d %d",&p[i].id,&p[i].m);
	}
	for(int i=0;i<bs;i++)
		b[i].status=false;
	for(int i=0;i<ps;i++)
		p[i].status=false;
		
	first_fit(ps,bs);

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





