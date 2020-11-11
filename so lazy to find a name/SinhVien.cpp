#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct sinhvien
{
	char mssv[10];
	char hoten[40];
	float dtb;
};
typedef struct sinhvien sv;

typedef struct Node
{
	sv info;
	struct Node* next;
}Node;

typedef struct list 
{
	Node* phead;
	Node* ptail;
}list; 

void Init(list &l)
{
	l.phead=l.ptail=NULL;
}

Node* TaoNode(sv x)
{
	Node* p=new Node;
	if(p==NULL)
	{
		printf(" Het bo nho !!! ");
		exit(0);
	}
	p->info=x;
	p->next=NULL;
	return p;
}

void Nhap1SV(sv &x)
{
	printf(" Nhap ma so sinh vien : "); fflush(stdin); gets(x.mssv);
	printf(" Nhap ho va ten sinh vien : "); fflush(stdin); gets(x.hoten);
	printf(" Nhap diem trung binh : "); float t; scanf("%f",&t); x.dtb=t;
}

void Xuat1SV(sv x)
{
	printf(" Ma so sinh vien : "); puts(x.mssv);
	printf(" Ho va ten sinh vien : "); puts(x.hoten);
	printf(" Diem trung binh : %f ",x.dtb);
}

void InserAfter(list &l,Node* p)
{
	if(l.phead==NULL)
	{
		l.phead=l.ptail=p;
		return ;
	}
	l.ptail->next=p;
	l.ptail=p;
}

void InserFirst(list &l,Node* p)
{
	if(l.phead==NULL)
	{
		l.phead=l.ptail=p;
		return ;
	}
	p->next=l.phead;
	l.phead=p;
}

void NhapDSSV(list &l,sv &a)
{
	int n;
	Init(l);
	printf(" ***** Nhap So luong sinh vien ***** : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf(" Nhap sinh vien %d \n",i+1);
		Nhap1SV(a);
		Node* p=TaoNode(a);
	//	InserAfter(l,p);
		InserFirst(l,p);
	}
}

void XuatDSSV(list l,sv a)
{
	int s=0;
	for(Node* i=l.phead;i!=NULL;i=i->next)
	{
		printf("\n ***** Thong tin sinh vien thu %d la : ***** \n",s);
		Xuat1SV(i->info);
		s++;
	}
}

int main()
{
	list l; 
	sv a;
	NhapDSSV(l,a);
	printf("\n\n _*_*_*_*_ Danh sach sinh vien vua nhap la : _*_*_*_*_ \n\n ");
	XuatDSSV(l,a);
	return 0;
}
