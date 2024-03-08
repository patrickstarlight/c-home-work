#include <stdio.h> 
#include <stdlib.h> 
#define LEN 10
int matrix[LEN][LEN];
int visit[LEN];
void uni(int i,int j)
{
	matrix[i][j]=1;	
	matrix[j][i]=1;
}
void DFS(int n,int i)
{
	printf("%d ",i);
    visit[i] = 1;
 	int j;
    for (j=0; j<n; j++)
    {
        if (matrix[i][j]==1 && visit[j]==0)
        {
            DFS(n,j);
    	}
	}
}
void print(int n)
{
	int i,j,k;
	k=1;
	for(i=0;i<n;i++)
	{	
		if(visit[i]==0)
		{
			printf("\n¶°¦X%-2d : ",k);
			DFS(n,i);
			k++;
		}
		
	}
}
int main() 
{ 
	int i,j,k;
	for(i=0;i<LEN;i++)
	{
		for(j=0;j<LEN;j++)
		{
				matrix[i][j]=0;
		}
		visit[i]=0;
	}
	printf("Enter a pair of numbers < 10 (-1 -1 :exit) :");
	scanf("%d %d",&i,&j);
	for(k=0;k<LEN && i>=0;k++)
	{
		uni(i,j);
		printf("Enter a pair of numbers < 10 (-1 -1 :exit) :");
		scanf("%d %d",&i,&j);
	}
	print(LEN);

    return 0; 
}
