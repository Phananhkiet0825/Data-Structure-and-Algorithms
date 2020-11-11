#include<stdio.h>
int soTT=1000;  //global variable = 0
typedef struct BenhNhan
{
	int stt;
	char hoTen[40+1]; //chuoi = mang ky tu //char gt; //'Y' = nu, 'N' = nam
	int tuoi;
}BN;
int clean_stdin()
{
	for(;getchar()!='\n';);
	return 1;
}
void Nhap(BN &bn)
{
	bn.stt = ++soTT;
	printf("\nMoi nhap ho ten= "); gets(bn.hoTen);
	while(1)
	{
		char kyTu;//ky tu c de nhan phim enter
		do
		{
			printf("\nMoi nhap tuoi (1->140)= "); 
		}while((scanf("%d%c", &bn.tuoi, &kyTu)!=2 || kyTu!='\n')&& clean_stdin());
		if(bn.tuoi>0 && bn.tuoi<=140) break;
		printf("Ban nhap sai, tuoi tu 1 den 140...");
	}
}
void DuongNgangDauTien()
{
	printf("%c", 218);
	for(int i=0; i<10; i++)
		printf("%c", 196);
	printf("%c", 194);
	for(int i=0; i<32; i++)
		printf("%c", 196);
	printf("%c", 194);
	for(int i=0; i<15; i++)
		printf("%c", 196);
	printf("%c", 191);
}
void DuongNgangGiua()
{
	printf("\n%c", 195);
	for(int i=0; i<10; i++)
		printf("%c", 196);
	printf("%c", 197);
	for(int i=0; i<32; i++)
		printf("%c", 196);
	printf("%c", 197);
	for(int i=0; i<15; i++)
		printf("%c", 196);
	printf("%c", 180);
}
void DuongNgangCuoi()
{
	printf("\n%c", 192);
	for(int i=0; i<10; i++)
		printf("%c", 196);
	printf("%c", 193);
	for(int i=0; i<32; i++)
		printf("%c", 196);
	printf("%c", 193);
	for(int i=0; i<15; i++)
		printf("%c", 196);
	printf("%c", 217);
}
void XuatTieuDe()
{
	DuongNgangDauTien();
	printf("\n%c",179);
	printf("%-10s","So TT");
	printf("%c",179);
	printf("\t%-28s","Ho ten");
	printf("%c",179);
	printf("\t%8s","Tuoi");
	printf("    %c",179);
}

void Xuat(BN bn)
{
	printf("\n%c",179);
	printf("%-10d",bn.stt);
	printf("%c",179);
	printf("\t%-28s",bn.hoTen);
	printf("%c",179);
	printf("\t%8d", bn.tuoi);
	printf("    %c",179);
}
void Xuat2(BN bn)
{
	printf("%-10d",bn.stt);
	printf("\t%-28s",bn.hoTen);
	printf("\t%8d", bn.tuoi);
}
/////////////////////////////////
//QUEUE
typedef struct node
{
	BN info;
	struct node* next;
}Node;
typedef struct QUEUE
{
	Node* phead;
	Node* ptail;
}Q;
Node* CreateNode(BN bn)
{
	Node* p= new node;
	p->info = bn;
	p->next = NULL;
	return p;
}
void EnQueue(Q &q, BN bn) //Push
{
	Node* p = CreateNode(bn);
	if(q.phead==NULL) //neu hang doi rong
	{
		q.phead=p;
		q.ptail=p;
	}
	else
	{
		q.ptail->next = p;
		q.ptail = p;
	}
}
BN DeQueue(Q &q)
{
	Node* pDel = q.phead;
	q.phead=q.phead->next; //cap nhat con tro dau danh sach
	BN x= pDel->info; //lay data o dau danh sach ra
	delete pDel;
	return x;
}
void OutPut(Q q)
{
	//DuongNgangDauTien();
	XuatTieuDe();
	DuongNgangGiua();
	while(q.phead)
	{
		Xuat(q.phead->info);
		q.phead=q.phead->next;
	}
	DuongNgangCuoi();
}
void Input(Q &q)
{
	while(1)
	{
		printf("\nMoi nhap benh nhan thu= %d", soTT+1);
		BN bn; Nhap(bn); EnQueue(q,bn);
		char kyTu,c; //'Y': tiep tuc 'N': dung
		printf("\nBan tiep tuc (Y/N)? : ");  scanf("%c%c", &kyTu,&c);
		if(kyTu=='N' || kyTu=='n') break;
	}
}
int main()
{
	int soTT_tam=soTT;
	Q q = {NULL,NULL}; //init - khai bao inline
	Input(q); OutPut(q);
	//cau a trang 23
	printf("\nMoi nhap benh nhan can them= ");
	BN bn; Nhap(bn); EnQueue(q,bn);
	OutPut(q);
	//cau b
	bn = DeQueue(q);
	printf("\nBenh nhan kham tiep theo = \n"); Xuat2(bn);
	printf("\n"); OutPut(q);
	//cau c
	printf("\nSo luong benh nhan da kham= %d", q.phead->info.stt-soTT_tam-1);
	//cau d
	printf("\nSo luong benh nhan chua kham= %d", q.ptail->info.stt- q.phead->info.stt+1);
}
