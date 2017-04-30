#include<stdio.h>
#include<malloc.h>
struct node
{
    struct bt *left;
    char data;
    struct bt *right;
};
struct node *root=NULL ;
void insert(int);
struct node *delet_node(struct node *n);
struct node *search(struct node*r,int d);
void inorder(struct node *r);
void del(int no);
int main(void)
{
    char ch;
    int a,b,c,d,e,f;
	printf("\n\t BINARY TREE\n");
	do
	{
	    printf("\nChoose One\n");
        printf("1. Insert\n2. Traverse\n3. Search\n4. Delete\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:     printf("Enter the number of data to be inserted\n");
                        scanf("%d",&c);
                        printf("Enter the data to be inserted\n");
                        while(c!=0)
                        {
                            scanf("%d",&b);
                            insert(b);
                            c--;
                        }
                        break;

            case 2:     inorder(root);
                        break;

            case 3:     printf("Enter the number to be searched\n");
                        scanf("%d",&d);
                        e=search(root,d);
                        if(e>0)
                            printf("FOUND!!");
                        else
                            printf("NOT FOUND!!");
                        break;

            case 4:     printf("Enter the number to be deleted\n");
                        scanf("%d",&f);
                        del(f);
                        break;
        }
        printf("\nDo you wish to continue\n");
        while((ch=getchar())!='\n');
        ch=getchar();
	}while(ch=='Y' || ch=='y');
    return 0;
}

void insert(int num)
{
    struct node *p,*n;
    n=(struct node *)malloc(sizeof(struct node));
    n->left=n->right=NULL;
    n->data=num;

    if(root==NULL)
    {
        root=n;
        return;
    }
    p=root;
    while(p)
    {
        if(n->data<p->data)
        {
            if(p->left!=NULL)
                p=p->left;
            else
            {
                p->left=n;
                return;
            }
        }
        else
        {
            if(p->right!=NULL)
                p=p->right;
            else
            {
                p->right=n;
                return;
            }
        }
    }
}
struct node *search(struct node*r,int d)
{
    if(r)
    {
        if(r->data==d)
            return r;
        if(d<r->data)
            return search(r->left,d);
        else
            return search(r->right,d);
    }
}
void inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d\t",r->data);
        inorder(r->right);
    }
}
void del(int no)
{
    struct node *p,*n;
    n=search(root,no);
    if(root==NULL)
        printf("\nThe Tree is empty\n");
    if(n==root)
    {
        root=delet_node(n);
        free(n);
        return;
    }
    p=root;
    while((p)&&(p->left!=n)&&(p->right!=n))
    {
        if(n->data<p->data)
            p=p->left;
        else
            p=p->right;
    }
    if(p)
        if(p->left==n)
        p->left=delet_node(n);
    else
        p->right=delet_node(n);
    free(n);
}
struct node *delet_node(struct node *n)
{
    struct node *t;
    if((n->left==NULL)&&(n->right==NULL))
        return NULL;
    if(n->left==NULL) return n->right;
    if(n->right==NULL) return n->left;
    t=n->right;
    while(t->left) t=t->left;
    t->left=n->left;
    return n->right;
}
