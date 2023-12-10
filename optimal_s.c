#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
int count=0;
void print(int frames[],int rs[],int fs,int index){
	printf("\n%d | ",rs[index]);
	for(int i=0;i<fs;i++){
		
		if(frames[i]==-1)
			printf("-\t");
		else
			printf("%d\t",frames[i]);
	}
	//printf("\t\t");
}
bool search_in_frames(int frames[],int rs[],int i,int fs){
	for(int j=0;j<fs;j++){
		if(rs[i]==frames[j])
			return true;
	}
	return false;
}
int search_in_string(int frames[],int rs[],int n,int start,int val){
	int i;
	
	for(i=start;i<n;i++){
		if(rs[i]==val)
		{	
			printf("\n%di",i);
			return i;
			
			}
	}
	return 999;
	if(i==n){
		for(int i=n-1;i>=0;i--){
			if(rs[i]==val){
				count=1;
				return n+i;
				
			}
		}
	}


}
void optimal(int rs[],int frames[],int n,int fs){
	int pf=0,hit=0,occp=0;
	for(int i=0;i<n;i++){
		if(search_in_frames(frames,rs,i,fs)){
			hit++;
			printf("\n%d |Hit",rs[i]);
		}
		else if(occp<fs){
			frames[occp]=rs[i];
			pf++;
			occp++;
			print(frames,rs,fs,i);
		}
		else{
			int max=INT_MIN,index,min=INT_MAX;
			int dst[fs];
			for(int j=0;j<fs;j++){
				dst[j]=0;
				dst[j]=search_in_string(frames,rs,n,i,frames[j]);
				printf("\ncount %d",count);
				
				 /*if(count==1){
					count=0;
					if(min>dst[j]){
						index=j;
						min=dst[j];
					}	
				
				}
				else if(dst[index]<dst[j]){
					max=dst[j];
					printf("max %d",max);
					index=j;
				}*/
				 if(max<dst[j]){
					max=dst[j];
					//printf("max %d",max);
					index=j;
				}
				//printf("index %d,min %d",index,min);	
			}
			frames[index]=rs[i];
			pf++;
			print(frames,rs,fs,i);
			
		}
		
	
	}
	printf("\n no of pf:%d\n no of hit:%d",pf,hit);

}
int main(){
	int n,fs;
	printf("Enter the length of Reference String:");
	scanf("%d",&n);
	int rs[n];
	printf("Enter the Reference String:");
	for(int i=0;i<n;i++)
		scanf("%d",&rs[i]);
	
	printf("Enter the number of frames:");
	scanf("%d",&fs);
	int frames[fs];
	for(int i=0;i<fs;i++)
		frames[i]=-1;
		
	
	optimal(rs,frames,n,fs);
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
//1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

//6 1 1 2 0 3 4 6 0 2 1 2 1 2 0 3 2 1 4 0 -tie ???
