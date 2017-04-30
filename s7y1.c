#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL, *last;

struct node* makenode(int);
void traverse();
void add(struct node *q);
void search(int);
void count();
int y=0;

int main(void)
{
	int a,b,q;
	char ch;
	struct node *n;
	printf("\nLinked List\n");
	do
	{
			printf("\nSelect Option\n");
			printf("1. MakeNode\n");
			printf("2. Traverse\n");
			printf("3. Searching\n");
			printf("4. Count\n");
			scanf("%d",&a);
			switch(a)
			{
				case 1: 	printf("Enter the data\n");
							scanf("%d",&b);
							n=makenode(b);
							add(n);
							y++;
							break;

				case 2:		printf("The list is:-\n");
							traverse();
							printf("\n");
							break;

				case 3:		printf("Enter the number to be searched\n");
							scanf("%d",&q);
							search(q);
							break;

				case 4:     count();
							break;
			}
			printf("Do you wish to continue\n");
			while((ch=getchar())!='\n');
			ch=getchar();
	}while(ch=='Y' || ch=='y');
	return 0;
}

struct node* makenode(int d)
{
	struct node *x;
	x=(struct node *)malloc(sizeof(struct node));
	x->data=d;
	x->next=NULL;
	return x;
}

void add(struct node *q)
{
	q->next=start;
	start=q;
}

void traverse()
{
	struct node *t;
	for(t=start;t!=NULL;t=t->next)
		printf(" %d ", t->data);
}

void search(int c)
{
	struct node *f;
	int p=0;
	for(f=start;f!=NULL;f=f->next)
	{
		if(c==f->data)
			p++;
	}
	if(p>0)
		printf("Found!\n");
	else
		printf("Not Found!\n");
}

void count()
{
	printf("The total number of nodes are:\t%d\n",y);
}
