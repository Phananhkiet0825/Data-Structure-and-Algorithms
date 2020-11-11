#include<stdio.h>
typedef struct node
{
	int info;
	struct node* next;
}Node;
typedef Node* STACK; // NODEPTR;
STACK CreateNode(int x)
{
	STACK p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}
void Push(STACK &s, int x) //InsertFirst
{
	STACK p = CreateNode(x);
	p->next = s;
	s = p;
}
int Pop(STACK &s)
{
	STACK pDel = s;
	s= s->next; //cap nhat con tro dau danh sach
	int x= pDel->info;
	delete pDel;
	return x;
}
//trang 22
void Convert(int n, STACK &s, int coSo)
{
	while(n>0)
	{
		int du = n%coSo;
		Push(s,du);
		n=n/coSo;
	}
}
void Output(STACK s)
{
	while(s) //stack van con
	{
		int x= Pop(s);
		if(x<10)
			printf("%d",x);
		else
			printf("%c",(x-10)+'A');//????????????????????????????*******************************
	}
}
void DuongNgangDauTien()
{
	printf("%c", 218);
	for(int i=0; i<20; i++)
		printf("%c", 196);
	printf("%c", 191);
}
void DuongNgangGiua()
{
	printf("\n%c", 195);
	for(int i=0; i<20; i++)
		printf("%c", 196);
	printf("%c", 180);
}
void DuongNgangCuoi()
{
	printf("\n%c", 192);
	for(int i=0; i<20; i++)
		printf("%c", 196);
	printf("%c", 217);
}
int Menu()
{
	DuongNgangDauTien();
	printf("\n%c********MENU********%c",179,179);
	DuongNgangGiua();
	printf("\n%c1. Nhi Phan         %c",179,179);
	DuongNgangGiua();
	printf("\n%c2. Bat Phan         %c",179,179);
	DuongNgangGiua();
	printf("\n%c3. Thap Luc Phan    %c",179,179);
	DuongNgangCuoi();
	printf("\nMoi ban chon chuc nang= ");
	int chon; scanf("%d", &chon);
	return chon;
}
int main()
{
	STACK s=NULL; //stack rong
	int n; printf("\nMoi nhap so thap phan can doi n= "); scanf("%d",&n);
	int chon = Menu();
	switch(chon)
	{
		case 1: Convert(n,s,2);
				printf("\n%d doi sang nhi phan= ",n); 
				Output(s);
				break;
		case 2: Convert(n,s,8);
				printf("\n%d doi sang bat phan= ",n); 
				Output(s);
				break;
		case 3: Convert(n,s,16);
				printf("\n%d doi sang thap luc phan= ",n); 
				Output(s);
				break;
		default:
			printf("\nBan nhap sai...");
	}
	
}
