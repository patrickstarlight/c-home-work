#include <stdio.h>
#include <stdlib.h>
typedef struct polyNode
{
     int coef;
     int expon;
     struct polyNode* link;
 
} Node, *polyPointer;
polyPointer mul(polyPointer a,polyPointer b)
{
	polyPointer tempa = (polyPointer) malloc(sizeof(Node));
	tempa=a;
	int sum=0,mult=0;
	polyPointer c = (polyPointer) malloc(sizeof(Node));
	c->coef=0;
	c->expon=0;
	c->link=NULL;
	for(;b;b=b->link)
	{
		for(a=tempa;a;a=a->link)
		{
			mult=a->coef*b->coef;
			sum=a->expon+b->expon;
			insert(c,mult,sum);
			
		}
	}
	free(tempa);
	return c;
   
}
void insert(polyPointer ptr,int coef,int expon)
{
	if(ptr->coef==0)
	{
		ptr->coef=coef;
		ptr->expon=expon;
		ptr->link=NULL;
		return;
	}
	polyPointer temp = (polyPointer) malloc(sizeof(Node));
	while(ptr!=NULL)
	{
		if(ptr->expon==expon)
		{
			free(temp);
			ptr->coef+=coef;
			break;
		}
		else if(ptr->expon<expon)
		{
			temp->coef=ptr->coef;
			ptr->coef=coef;
			temp->expon=ptr->expon;
			ptr->expon=expon;
			temp->link=ptr->link;
			ptr->link=temp;
			break;
		}
		else if(ptr->link==NULL && ptr->expon>expon)
		{
			temp->coef=coef;
			temp->expon=expon;
			ptr->link=temp;
			temp->link=NULL;
			break;
		}
		else
		{
			ptr=ptr->link;
		}
	}
	return;
	
	
}
void show(polyPointer ptr)
{
	while(ptr)
	{	
		if(ptr->expon!=0)
		{
			printf("%dx^%-2d ",ptr->coef,ptr->expon);
		}
		else
		{
			printf("%d",ptr->coef);
		}
		ptr=ptr->link;
		if(ptr==NULL)
		{
			printf("\n");
			break;
		}
		if(ptr->coef>0)
		{
			printf("+");
		}
	
	}
	return;
}
int main()
{
	polyPointer a1 = (polyPointer) malloc(sizeof(Node));
	polyPointer a2 = (polyPointer) malloc(sizeof(Node));
	polyPointer a3 = (polyPointer) malloc(sizeof(Node));
	polyPointer b1 = (polyPointer) malloc(sizeof(Node));
	polyPointer b2 = (polyPointer) malloc(sizeof(Node));
	polyPointer b3 = (polyPointer) malloc(sizeof(Node));
	a1->coef=3;
	a1->expon=14;
	a1->link=a2;
	a2->coef=2;
	a2->expon=8;
	a2->link=a3;
	a3->coef=1;
	a3->expon=0;
	a3->link=NULL;
	b1->coef=8;
	b1->expon=14;
	b1->link=b2;
	b2->coef=-3;
	b2->expon=10;
	b2->link=b3;
	b3->coef=10;
	b3->expon=6;
	b3->link=NULL;
	show(a1);
	show(b1);
	show(mul(a1,b1));
	//show(add(a1,b1));
	
	
}
