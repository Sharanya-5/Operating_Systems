#include<stdio.h>

int main()
{
	int n,m,i;
	printf("enter no.of process");
	scanf("%d",&n);
	printf("enter no.of blocks");
	scanf("%d",&m);
	int p[n],b[m];
	printf("processes:");
	for(i=0;i<n;i++)
	{
	scanf("%d",&p[i]);
	}
	printf("blocks:");
	for(i=0;i<m;i++)
	{
	scanf("%d",&b[i]);
	}
	
	int allocate[n];
    //int occupied[m];
    
 
  /*  for(int i = 0; i < n; i++){
        allocate[i] = -1;
    }
    
    for(int i = 0; i < m; i++){
        occupied[i] = 0;
    }
    for(int i=0;i<n;i++)
    {  
    int index=-1;
    	for(int j=0;j<m;j++)
    	{
    	if (b[j] >= p[i] && occupied[j]!=0)
            {
                if (index== -1)
                    index= j;
                    
                
                else if (b[j] < b[index])
                    index= j;
            }
        }
 
        if (index!= -1)
        {
            
            allocate[i] = index;
            
            
            occupied[index] = 1;
        }
    }*/
    for(int i=0;i<n;i++)
    {  
    int index=-1;
    	for(int j=0;j<m;j++)
    	{
    	if(b[j]>=p[i])
    	{
    	if(index==-1 ||b[j]<b[index])
    	{
    	index=j;
    	}
    	}
    	}
    	if(index!=-1)
    	allocate[i]=index;
    	else
    	allocate[i]=-1;
    	}
    
 printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, p[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
	
}
