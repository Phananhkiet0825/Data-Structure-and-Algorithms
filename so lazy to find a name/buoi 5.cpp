#include<stdio.h>
typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}Node;
typedef Node* NODEPTR;
//bai trang 25
//viet giong trang 27
NODEPTR CreateNode(int x)
{
	NODEPTR p = new node;
	p->info = x;
	p->left = p->right = NULL;
	return p;
}
//ham insert o trang 27
int Insert(NODEPTR &proot, int x)
{
	if(proot)
	{
		if(x==proot->info) return 0; //bi trung
		if(x<proot->info) return Insert(proot->left,x);
		return Insert(proot->right,x);
	}
	else
	{
		proot=CreateNode(x);
		return 1; //da them vao
	}
}
//cau a trang 25
void NLR(NODEPTR proot)
{
	if(proot)
	{
		printf("%4d", proot->info);
		NLR(proot->left);
		NLR(proot->right);
	}
}
void LNR(NODEPTR proot)
{
	if(proot)
	{
		LNR(proot->left);
		printf("%4d", proot->info);
		LNR(proot->right);
	}
}
void LRN(NODEPTR proot)
{
	if(proot)
	{
		LRN(proot->left);
		LRN(proot->right);
		printf("%4d", proot->info);
	}
}
void CreateTree(NODEPTR &proot, int a[], int n)
{
	for(int i=0; i<n ; i++)
		Insert(proot,a[i]);
}
//cau b trang 25
int CountNode(NODEPTR proot)
{
	if(proot==NULL) return 0;
	return 1+CountNode(proot->left)+CountNode(proot->right);
}
//cau c trang 25
int CountNodeLeaf(NODEPTR proot)
{
	if(proot==NULL) return 0;
	if(proot->left==NULL && proot->right==NULL)
		return 1+CountNodeLeaf(proot->left)+CountNodeLeaf(proot->right);
	return CountNodeLeaf(proot->left)+CountNodeLeaf(proot->right);
}
//thao tac xoa trang 27
//trang 28
int Remove(NODEPTR &proot, int x)
{
	if(proot==NULL) return 0;//tim khong thay
	////////////////////////////////////////////////
	if(x<proot->info) return Remove(proot->left,x);
	if(x>proot->info) return Remove(proot->right,x);
	//////tim thay x
	NODEPTR p,f, rp;
	p=proot;
	//TH proot co 1 cay con
	if(proot->left==NULL) //co 1 cay con ben phai
		proot=proot->right;
	else if(proot->right==NULL)//co 1 cay con ben trai
		proot=proot->left;
	else //co 2 con => tim phan tu the mang theo CACH 1
	{
		f=p;
		rp= p->right; //nhanh cay con ben phai
		while(rp->left) //di tim phan tu trai nhat cua cay con ben phai
		{
			f=rp; //luu lai cha cua phan tu the mang
			rp=rp->left; //tim trai nhat
		}//ket thuc khi tim duoc phan tu trai nhat cua cay con ben phan
		p->info=rp->info;
		if(f==p)
			f->right=rp->right;
		else
			f->left=rp->right;
		p=rp;
	}
	delete p;
	////////////////////////////////////////////////
	return 1;
}
int main()
{
	int a[]={7,3,36,1,6,15,40,4,23}; //inline
	int n=9;
	NODEPTR proot=NULL; //Init
	CreateTree(proot,a,n);
	printf("\nDuyet theo thu tu TRUOC NLR: "); NLR(proot);
	printf("\nDuyet theo thu tu GIUA LNR: "); LNR(proot);
	printf("\nDuyet theo thu tu SAU LRN: "); LRN(proot);
	int dem= CountNode(proot);
	printf("\nSo nut tren cay= %d",dem);
	dem= CountNodeLeaf(proot);
	printf("\nSo nut la tren cay= %d",dem);
	int x=36;
	Remove(proot,x);
	printf("\nDuyet theo thu tu TRUOC NLR: "); NLR(proot);
	printf("\nDuyet theo thu tu GIUA LNR: "); LNR(proot);
	printf("\nDuyet theo thu tu SAU LRN: "); LRN(proot);
}

