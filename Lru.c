#include<stdio.h>
#include<limits.h>

int checkHit(int rs, int frame[], int occupied){
    
    for(int i = 0; i < occupied; i++){
        if(rs == frame[i])
            return 1;
    }
    
    return 0;
}

void printFrame(int frame[], int occupied)
{
    for(int i = 0; i < occupied; i++)
        printf("%d\t\t\t",frame[i]);
}

int main()
{
  
    int n,frames; 
    printf("enter the size of reference string:\n");
    scanf("%d",&n);
    printf("enter the no.of frames:\n");
    	scanf("%d",&frames);
    int rs[n];
    printf("enter the reference string:\n");
    for(int i=0;i<n;i++)
    	scanf("%d",&rs[i]);
    
    int frame[n];
    int distance[n];
    int occupied = 0;
    int pagefault = 0;
    
    printf("Page\t Frame1 \t Frame2 \t Frame3\n");
    
    for(int i = 0;i < n; i++)
    {
        printf("%d:  \t\t",rs[i]);
        
        if(checkHit(rs[i], frame, occupied)){
            printFrame(frame, occupied);
        }
        
    
        else if(occupied < frames){
            frame[occupied] = rs[i];
            pagefault++;
            occupied++;
            
            printFrame(frame, occupied);
        }
        else{
            
            int max = INT_MIN;
            int index;
            for (int j = 0; j < frames; j++)
            {
                distance[j] = 0;
                for(int k = i - 1; k >= 0; k--)
                {
                    ++distance[j];

                    if(frame[j] == rs[k])
                        break;
                }
                
                
                if(distance[j] > max){
                    max = distance[j];
                    index = j;
                }
            }
            frame[index] = rs[i];
            printFrame(frame, occupied);
            pagefault++;
        }
        
        printf("\n");
    }
    
    printf("Page Fault: %d",pagefault);
    
    return 0;
}
