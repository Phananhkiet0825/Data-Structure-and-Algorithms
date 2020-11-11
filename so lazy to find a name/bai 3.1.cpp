#include<stdio.h>
#include<string.h>
typedef struct SinhVien
{
	char maSV[11];
	char hoTen[41];
	float diemTB;
}SV;
//nhap 1 sinh vien
void Nhap(SV &sv)
{
	printf("\nMoi nhap ma sinh vien= "); gets(sv.maSV);gets(sv.maSV);
	printf("\nMoi nhap ho ten sinh vien= "); gets(sv.hoTen);
	printf("\nMoi nhap diem trung binh= "); scanf("%f", &sv.diemTB);
}
//xuat 1 sinh vien
void Xuat(SV sv)
{
	printf("\nMa sinh vien= %s",sv.maSV);
	printf("\tHo ten sinh vien= %s",sv.hoTen);
	printf("\tDiem trung binh= %.2f", sv.diemTB);
}

typedef struct node
{
	SV info;   //[1]**************
	struct node* next;
}Node;
typedef Node* NODEPTR;
NODEPTR CreateNode(SV x) //[2]********************
{
	NODEPTR p=new node;
	p->info = x;   //a[i] = p->info
	p->next = NULL;
	return p;
}
void InsertFirst(NODEPTR &phead, SV x) //[3]*******************
{
	NODEPTR p = CreateNode(x);
	p->next = phead;
	phead = p; //cap nhat lai con tro dau danh sach
}
void InsertLast(NODEPTR &phead, SV x) //[4]*****************
{
	NODEPTR p = CreateNode(x);
	if(phead==NULL)
		phead=p;
	else
	{
		NODEPTR ptail=phead;
		while(ptail->next) //trong chua phai la duoi
			ptail=ptail->next;
		//////////////////////////////
		ptail->next = p;
	}
}
void InputList(NODEPTR &phead)
{
	phead=NULL;
	int n; printf("\nMoi nhap so phan tu n= "); scanf("%d", &n);
	for( int i=1 ; i<=n ; i++ ) //duyet trong pham vi tu 1 den n
	{
		printf("\nMoi nhap thong tin sinh vien tu thu %d= ", i);
		SV x; Nhap(x);
		//InsertFirst(phead,x);
		InsertLast(phead,x);
	}
}
/*void InputList(NODEPTR &phead)
{
	phead=NULL;
	while(1) //moi bat dau
	{
		printf("\nMoi nhap gia tri phan tu (thoat:0)= ");
		SV x; Nhap(x);//[5]***************
		if(strcmp(x.maSV,"0")==0) break;
		//InsertFirst(phead,x);
		InsertLast(phead,x);
	} 
}*/
/*void ShowList(NODEPTR phead)
{
	for(NODEPTR p=phead /*int i=0; p /*i<n;p=p->next /*i++)
		printf("%5d", p->info /*a[i]);//process
}*/
void ShowList(NODEPTR phead)
{
	NODEPTR p=phead;//start
	while(p /*stop*/)
	{
		Xuat( p->info );//[6]*********************
		p=p->next;//step
	}
}
//cau c trang 13
NODEPTR Search(NODEPTR phead, char x[]) //[7]*******************
{
	NODEPTR p=phead;//start
	while(p && strcmp(p->info.maSV,x)!=0) //[8]*******************
		p=p->next;//step
	return p;
}
void InsertAfter(NODEPTR p, SV y) //[9]******************
{
	NODEPTR q= CreateNode(y);
	q->next = p->next;
	p->next = q;
}
//theo yeu cau cua sinh vien
void InsertAll(NODEPTR &phead, SV x, SV y) //[10]***************
{
	NODEPTR p=phead;//start
	while(p) //trong khi chua het danh sach va chua tim thay x
	{
		if(strcmp(p->info.maSV,x.maSV)==0)
		{
			InsertAfter(p,y);
			p=p->next;
		}	
		p=p->next;//step
	}
}
//cau d trang 13
int CountNode(NODEPTR phead)
{
	int dem=0;
	NODEPTR p=phead;//start
	while(p ) //trong khi chua het danh sach
	{
		dem++;
		p=p->next;//step
	}
	return dem;
}
//cau e trang 13
SV ValueK(NODEPTR phead, int k) //[11]*************
{
	int i=0;
	NODEPTR p=phead;//start
	while(p && i<k) //trong khi chua het danh sach
	{
		i++;
		p=p->next;//step
	}
	if(p) //k nam trong pham vi cua danh sach
		return p->info;
	return SV{"0","0",0.0}; //[12]************
}
//cau f
SV FindMax(NODEPTR phead)
{
	NODEPTR pM=phead;
	NODEPTR p=phead;//start
	while(p) //trong khi chua het danh sach
	{
		if(p->info.diemTB > pM->info.diemTB)//[13]******************
			pM=p;
		p=p->next;//step
	}
	return pM->info;
}
SV FindMin(NODEPTR phead)
{
	NODEPTR pM=phead;
	NODEPTR p=phead;//start
	while(p) //trong khi chua het danh sach
	{
		if( p->info.diemTB < pM->info.diemTB)
			pM=p;
		p=p->next;//step
	}
	return pM->info;
}
//cau g
void DeleteHead(NODEPTR &phead)
{
	NODEPTR pDel = phead;
	phead= phead->next; //cap nhat con tro dau danh sach
	delete pDel;
}
NODEPTR SearchBefore(NODEPTR phead, char x[])//[14]**************
{
	NODEPTR p=phead;//start
	while(p->next && strcmp(p->next->info.maSV,x)!=0) //[15]****************
		p=p->next;//step
	return p;
}
void DeleteX(NODEPTR &phead,char x[])//[16]*************
{
	if(strcmp(phead->info.maSV,x)==0)
		DeleteHead(phead);
	else
	{
		NODEPTR pPre= SearchBefore(phead,x);
		NODEPTR pDel= pPre->next;
		pPre->next = pDel->next;
		delete pDel;
	}
}
void HoanVi(SV &x, SV &y)//[17]***************
{
	SV t=x; x=y; y=t;//[18]*****************
}

void InterChangeSort(NODEPTR phead)
{
	for(NODEPTR p=phead;p->next;p=p->next)
		for(NODEPTR q=p->next;q;q=q->next)
			if(strcmp(p->info.maSV,q->info.maSV) >0) //[19]*******************
				HoanVi(p->info,q->info);
}
void ShowListDTBLonHon5(NODEPTR phead)
{
	NODEPTR p=phead;//start
	while(p /*stop*/)
	{
		if(p->info.diemTB>5)
			Xuat( p->info );//[6]*********************
		p=p->next;//step
	}
}
int main()
{
	NODEPTR phead=NULL;
	InputList(phead);
	ShowList(phead);
	printf("\nDanh sach DTB>5 \n");
	ShowListDTBLonHon5(phead);
	//InterChangeSort(phead);
	//printf("\nSau khi sap= ");	ShowList(phead);
}
