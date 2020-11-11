#include<stdio.h>
int soTT=1000;
typedef struct BenhNhan
{
	int sott;
	char hoTen[41];
	int tuoi;
}BN;
int clean_stdin()//ham xoa bo dem ban phim
{
	while(getchar()!='\n');
	return 1;
}
void Nhap(BN &bn)
{
	bn.sott= ++soTT;
	clean_stdin(); //ham xoa bo dem ban phim
	printf("\nMoi nhap ho ten= "); gets(bn.hoTen);
	while(1)
	{
		char c;
		do
		{
			printf("\nMoi nhap tuoi (tu 1 den 140)= "); 
		}while((scanf("%d%c", &bn.tuoi,&c)!=2 || c!='\n') && clean_stdin());
		if(bn.tuoi>0 && bn.tuoi<=140) break;
		printf("\nTuoi tu 1 den 140");
	}
}
void Xuat(BN bn)
{
	printf("\nSTT= %d",bn.sott);
	printf("\tHo ten= %s",bn.hoTen);
	printf("\tTuoi= %d", bn.tuoi);
}
//trang 23
typedef struct node
{
	BN info; //[1]****************
	struct node* next;
}Node;
typedef struct QUEUE
{
	Node* phead;
	Node* ptail;
}Q;
Node* CreateNode(BN x)
{
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void EnQueue(Q &q, BN bn)
{
	Node* p= CreateNode(bn);
	if(q.phead==NULL)
		q.phead=q.ptail=p;
	else
	{
		q.ptail->next=p;
		q.ptail=p;
	}
}
BN DeQueue(Q &q)
{
	if(q.phead==NULL)
		printf("\nDanh sach rong");
	else
	{
		Node* pDel= q.phead;
		q.phead=q.phead->next;
		BN x= pDel->info;
		delete pDel;
		return x;
	}
}
void Output(Q q)
{
	while(q.phead) 
	{
		BN bn = q.phead->info;
		Xuat(bn);
		q.phead=q.phead->next;
	}
}
void Input(Q &q)
{
	int n; printf("\nMoi nhap so benh nhan ban dau n= "); scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		printf("\nMoi nhap thong tin benh nhan thu %d= ",i);
		BN x; Nhap(x);
		EnQueue(q,x);
	}
}
int main()
{
	Q q= {NULL,NULL}; //inline = ham init
	int soTT_tam=soTT;
	Input(q);
	//cau a
	printf("\n\nMoi nhap them benh nhan:");
	BN bn; Nhap(bn); EnQueue(q,bn);
	printf("\n*** DANH SACH BENH NHAN ***\n");
	Output(q);
	//cau b;
	bn= DeQueue(q);
	printf("\n\nBenh nhan tiep theo:");
	Xuat(bn);
	//cau c
	printf("\nSo luong benh nhan da kham= %d",q.phead->info.sott-soTT_tam-1);
	//cau d
	printf("\nSo luong benh nhan chua kham= %d",q.ptail->info.sott-q.phead->info.sott+1);
	//cau e
	printf("\n*** DANH SACH BENH NHAN CHO KHAM***\n");
	Output(q);
}


