#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
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
bool search(int frames[],int rs[],int i,int fs){
	for(int j=0;j<fs;j++){
		if(rs[i]==frames[j])
			return true;
	}
	return false;
}
void lru_p(int rs[],int frames[],int n,int fs){
	int pageFaults=0,hit=0,occupied=0;
	for(int i=0;i<n;i++){
		
		if(search(frames,rs,i,fs)){
			hit++;
			printf("\n%d | Hit",rs[i]);
		}
		else if(occupied<fs){
			frames[occupied]=rs[i];
			pageFaults++;
			occupied++;
			print(frames,rs,fs,i);
		}
		else{
			int max=INT_MIN;
			int index;
			int dist[fs];
			for(int j=0;j<fs;j++){
				//max=-1;
				dist[j] = 0;
				for(int k=i-1;k>=0;k--){
					++dist[j];
					if(frames[j]==rs[k])
						break;
				}
				if(max<dist[j]){
					max=dist[j];
					index=j;
				}
			}
			frames[index]=rs[i];
			pageFaults++;
			print(frames,rs,fs,i);
		}
	
	
	}
	printf("\nNo of PF:%d\n No of hits:%d",pageFaults,hit);

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
		
	
	lru_p(rs,frames,n,fs);
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
