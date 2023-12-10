#include<stdio.h>
#include<stdbool.h>
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
void fifo_p(int rs[],int frames[],int n,int fs){
	int pageFaults=0,hit=0,ind=0;
	for(int i=0;i<fs;i++){
		if(search(frames,rs,i,fs)){
			hit++;
			print(frames,rs,fs,i);
		}
		else{
			frames[i]=rs[i];
			print(frames,rs,fs,i);
			pageFaults++;
		
		}
		
	}
	for(int i=fs;i<n;i++){
		if(search(frames,rs,i,fs)){
			hit++;
			printf("\n%d |Hit",rs[i]);
		}
		else{
			frames[ind]=rs[i];
			ind=(ind+1)%fs;
			print(frames,rs,fs,i);
			pageFaults++;
		}
		
	
	}
	printf("\nNo. of PageFaults: %d",pageFaults);
	printf("\nNo. of hits: %d",hit);
	

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
		
	
	fifo_p(rs,frames,n,fs);
}
/*
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter the number of frames:3

7 |7	-	-	
0 |7	0	-	
1 |7	0	1	
2 |2	0	1	
0 |Hit
3 |2	3	1	
0 |2	3	0	
4 |4	3	0	
2 |4	2	0	
3 |4	2	3	
0 |0	2	3	
3 |Hit
2 |Hit
1 |0	1	3	
2 |0	1	2	
0 |Hit
1 |Hit
7 |7	1	2	
0 |7	0	2	
1 |7	0	1	
No. of PageFaults: 15
No. of hits: 5



*/

/*
example of pagefaluts and hits same when frames are diff
Enter the length of Reference String:12
Enter the Reference String:0 2 1 6 4 0 1 0 3 1 2 1
Enter the number of frames:3

0 | 0	-	-	
2 | 0	2	-	
1 | 0	2	1	
6 | 6	2	1	
4 | 6	4	1	
0 | 6	4	0	
1 | 1	4	0	
0 |Hit
3 | 1	3	0	
1 |Hit
2 | 1	3	2	
1 |Hit
No. of PageFaults: 9

No. of hits: 3student@student-HP-348-G4:~/Downloads/os/Sharanya$ ./a.out

Enter the length of Reference String:12
Enter the Reference String:0 2 1 6 4 0 1 0 3 1 2 1
Enter the number of frames:4

0 | 0	-	-	-	
2 | 0	2	-	-	
1 | 0	2	1	-	
6 | 0	2	1	6	
4 | 4	2	1	6	
0 | 4	0	1	6	
1 |Hit
0 |Hit
3 | 4	0	3	6	
1 | 4	0	3	1	
2 | 2	0	3	1	
1 |Hit
No. of PageFaults: 9
No. of hits: 3


*/
