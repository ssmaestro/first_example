#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int val;
struct node *next;
};
void create1();
void create2();
void merge(struct node*,struct node*);
void display(struct node*);
struct node *h1= NULL;
struct node *h2= NULL;
void main()
{
printf("\nCreate the first Linked List");
create1();
printf("\nCreate the second Linked List");
create2();
merge(h1,h2);
printf("\n\n");
display(h1);
getch();
}


void create1()
{
char c;
struct node *ls;
int v;
do
{
printf("\n Enter the element:");
scanf("%d",&v);
if(h1==NULL)
{
h1=(struct node*)malloc(sizeof(struct node));
h1->val=v;
h1->next=NULL;
}
else
{
ls=h1;
while(ls->next!=NULL)
{
ls=ls->next;
}
ls->next=(struct node*)malloc(sizeof(struct node));
ls->next->val=v;
ls->next->next=NULL;
}
printf("\nWant to continue?");
fflush(stdin);
scanf("%c",&c);
}
while(c=='y');
}

void create2()
{
char c;
struct node *ls;
int v;
do
{
printf("\n Enter the element:");
scanf("%d",&v);
if(h2==NULL)
{
h2=(struct node*)malloc(sizeof(struct node));
h2->val=v;
h2->next=NULL;
}
else
{
ls=h2;
while(ls->next!=NULL)
{
ls=ls->next;
}
ls->next=(struct node*)malloc(sizeof(struct node));
ls->next->val=v;
ls->next->next=NULL;
}
printf("\nWant to continue?");
fflush(stdin);
scanf("%c",&c);
}
while(c=='y');
}


void merge(struct node*h1,struct node*h2)
{
struct node*ls;
ls=h1;
if(h1==NULL || h2==NULL)
{
printf("\nOne or both of the linked list is empty\n");
}
else
{
while(ls->next!=NULL)
{
ls=ls->next;
}
ls->next=h2;
}
}

void display(struct node*ls)
{
if(h1==NULL)
{
printf("\nLinked List is empty");
}
else
{
while(ls!=NULL)
{
printf("%d->",ls->val);
ls=ls->next;
}
printf("End");
}
}



