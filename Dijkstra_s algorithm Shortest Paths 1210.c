#include <stdio.h> 
#include <stdlib.h> 
int matrix[6][6]={	{0,50,45,10,0,0},
					{0,0,10,15,0,0},
					{0,0,0,0,30,0},
					{20,0,0,0,15,0},
					{0,20,35,0,0,0},
					{0,0,0,0,3,0}
};
int dist[6]={0};//最短路徑長度 
int visit[6]={0};
int paths[6]={-1};
int root[6]={0}; 
int choose()
{
	int i,min,minpos;
	min=10000;
	minpos=-1;
	for(i=0;i<6;i++)
	{
		if(dist[i]<min && !visit[i] && dist[i]!=0)
		{
			min=dist[i];
			minpos=i;
		}
	}
	return 	minpos;
}
void showpath()
{
	int i,j,n=0,k=2;
	for(i=0;i<6;i++)
	{
		if(dist[i]>0)
			n++;
	}
	for(i=0;i<n;i++)
	{		if(root[paths[k-1]]==0)
			{				
				printf("0 %d ",paths[k-1]);
				printf("Length: %d \n",dist[paths[k-1]]);
				
			}
			else
			{
				for(j=0;j<k;j++)
				{
						printf("%d ",paths[j]);
				}
				printf("Length: %d \n",dist[paths[k-1]]);
			}	
			k++;
		
	}
	
}
void shortestPath()
{
	int i,u,w,m=0,n=0;
	for(i=0;i<6;i++)
	{
		dist[i]=matrix[0][i];
	}
	visit[0]=1;
	dist[0]=0;
	paths[m++]=0;
	for(i=0;i<5;i++)
	{
		u=choose();
		paths[m++]=u;
		visit[u]=1;
		for(w=0;w<6;w++)
		{
			if(!visit[w]&&matrix[u][w]!=0)
			{
				if(dist[u]+matrix[u][w]<dist[w]||dist[w]==0)
				{
					dist[w]=dist[u]+matrix[u][w];
					root[w]=u;
				}
			}
		}
	}
}
int main()
{	
	shortestPath();
	showpath();
	return 0;
}
