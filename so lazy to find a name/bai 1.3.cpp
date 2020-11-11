#include<stdio.h>
#define MAX 100
typedef struct NHANVIEN
{
	char maNV[11]; //kieu chuoi= mang ky tu
	char hoTen[41];
	float luong;
}NV ; //ket thuc khai bao co cham phay
//nhap 1 nhan vien
void Nhap(NV &nv)
{
	printf("\nMoi nhap ma nhan vien= "); gets(nv.maNV);gets(nv.maNV);
	printf("\nMoi nhap ho ten nhan vien= "); gets(nv.hoTen);
	printf("\nMoi nhap luong nhan vien= "); scanf("%f", &nv.luong);
}
void XuatTieuDe()
{
	printf("\n%-20s","Ma nhan vien");
	printf("\t%-30s","Ho ten");
	printf("\t%10s","Luong");
}
void Xuat(NV nv)
{
	printf("\n%-20s",nv.maNV);
	printf("\t%-30s",nv.hoTen);
	printf("\t%10.2f", nv.luong);
}
int Nhap()
{
	int n;
	while(1)
	{
		printf("\nMoi nhap (n>0) n= " ); scanf("%d",&n);
		if(n>0) return n;
		printf("\nBan nhap sai, moi nhap lai...");
	}
}
void NhapDS(NV a[], int n)
{
	for(int i=0; i<n ; i++)
	{
		printf("\nMoi nhap thong tin nhan vien thu %d", i+1);
		Nhap(a[i]);
	}
}
void XuatDS(NV a[], int n)
{
	XuatTieuDe();
	for(int i=0; i<n ; i++)
		Xuat(a[i]);
}
void HoanVi(NV &x, NV &y)  //[1]
{
	NV t=x; 	x=y; 	y=t; //[2]
}
void SelectSort(NV a[], int n) //[3]
{
	for(int i=0; i<n-1; i++) 
	{
		/* Tim vi tri min*/
		int vt=i;
		for(int j=i+1; j<n; j++)
			if(a[j].luong<a[vt].luong) //[4]
				vt=j;
		/*Hoan vi giua phan tu a[i] voi a[vt]*/
		HoanVi(a[i], a[vt]);
	}
}
void InsertSort(NV a[], int n) //[5]
{
	for(int i=1;i<n;i++) //duyet mang ben phai chua duoc sap
	{
		NV x=a[i];   //[6]
		int pos=i-1;  //duyet nguoc day vang khe ben trai
		while(pos>=0 && a[pos].luong>x.luong)  //[7]
		{
			a[pos+1]=a[pos];
			//phep gan <- : gan gia tri tu dang sau ra dang truoc
			pos--; //duyet nguoc
		}
		//////////////////////////////////
		a[pos+1]=x;  //ha bien x xuong
	}
}
int main()
{
	int n=Nhap();
	NV a[MAX]; NhapDS(a,n);
	printf("\n*****Danh sach nhan vien*****\n");
	XuatDS(a,n);
	SelectSort(a,n);
	printf("\n*****Danh sach nhan vien tang dan theo luong CHON*****\n");
	XuatDS(a,n);
	InsertSort(a,n);
	printf("\n*****Danh sach nhan vien tang dan theo luong CHEN*****\n");
	XuatDS(a,n);
}
