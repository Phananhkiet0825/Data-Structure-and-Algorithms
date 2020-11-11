#include<stdio.h>
typedef struct node
{
	int info;
	struct node* next;
}Node;
typedef Node* STACK;
STACK CreateNode(int x)
{
	STACK p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void Push(STACK &s, int x)
{
	STACK p = CreateNode(x);
	p->next = s;
	s = p;
}
int Pop(STACK &s)
{
	STACK pDel = s;
	s = s->next;
	int x= pDel->info;//[1]**********
	delete pDel;
	return x;//[2]**********
}
//trang 22-doi so thap phan sang nhi phan va dua vao stack
void Convert(int n, STACK &s) 
{
	while(n>0)
	{
		int du=n%2;
		Push(s,du);
		n=n/2; //giam di 1/2 cua n
	}
}
void Output(STACK s)
{
	while(s) 
	{
		int x= Pop(s);
		printf("%d",x);
	}
}
int main()
{
	STACK s=NULL; //???????????????????????
	int n; printf("\nMoi nhap so thap phan n can doi= "); scanf("%d",&n);
	Convert(n,s);
	printf("%d doi sang nhi phan= ",n); Output(s);
}
