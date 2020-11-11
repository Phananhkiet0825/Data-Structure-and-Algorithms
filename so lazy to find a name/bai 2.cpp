#include<stdio.h>
#include<string.h>//???????????????????????????????
#define MAX 100
struct Sach
{
	char maSach[11];  //[1]***********************
	char tenSach[41]; //mang ky tu = chuoi
	float gia;
};  //ket thuc khai bao 1 cau truc phai co cham phay
//nhap 1 cau truc = nhap 1 cuon sach
void Nhap(Sach &s)
{
	printf("\nMoi nhap ma sach= "); 
	gets(s.maSach);gets(s.maSach); //[2]*******
	printf("\nMoi nhap ten sach= "); gets(s.tenSach);//[3]******
	printf("\nMoi nhap gia= "); scanf("%f", &s.gia);
}
//xuat 1 cau truc = xuat 1 cuon sach
void Xuat(Sach s)
{
	printf("\nMa sach= %s", s.maSach); //[4]*************
	printf("\tTen sach= %s",s.tenSach);
	printf("\tGia= %.2f", s.gia);
}
void NhapSL(int &n)
{
	do
	{
		printf("\nMoi nhap (0<n<=%d) n= ",MAX);
		scanf("%d", &n);
		if(n<=0 || n>MAX)
			printf("\nBan nhap sai, moi nhap lai...");
	}while(n<=0 || n>MAX); //ket thuc co cham phay
}
void NhapDS(Sach a[], int n) 
{
	for( int i=0 ; i<n ; i++ )  //duyet mang XUOI
	{
		printf("\nMoi nhap thong tin cuon sach thu %d=\n", i+1);
		Nhap(a[i]); 
	}
}
void XuatDS(Sach a[], int n) 
{
	for( int i=0 ; i<n ; i++ )  //duyet mang XUOI
	{
		printf("\nThong tin cuon sach thu %d=\n", i+1);
		Xuat(a[i]); 
	}
}
int TimTuyenTinh(Sach a[], int n, char X[])//[5]***************
{
	int i=0; //duyet tu dau danh sach
	while(i<n &&  strcmp(a[i].maSach,X)!=0 ) //[6]****************
		i++; //qua phan tu ke => next
	////////////////////////////////////////////////
	if(i<n) return i;
	return -1;
}
void HoanVi(Sach &x, Sach &y) 
{
	Sach t=x; 	x=y; 	y=t;  
}
void SapXep(Sach a[], int n)
{
	for(int i=0 ;i<n-1 ;i++ ) //XUOI = son tinh
		for(int j=i+1;j<n;j++) 				//thuy tinh
			if(strcmp(a[i].maSach,a[j].maSach)>0) //[7]********************
				HoanVi(a[i],a[j]);
}
int TimNhiPhan(Sach a[], int n, char key[]) //[8]*****************************
{
	int l=0, r=n-1;
	while(l<=r)   //luu y co dau bang
	{
		int m=(l+r)/2;
		if(strcmp (a[m].maSach,key)==0) return m; //[9]****************
		if(strcmp( a[m].maSach,key)<0)	l=m+1;   //[10]*********************
		else			r=m-1;	
	}
	//////////////////////////////////////
	return -1;
}

int main()
{
	int n; NhapSL(n);
	Sach a[MAX]; NhapDS(a,n);
	printf("\n*****DANH SACH CAC CUON SACH*****\n");
	XuatDS(a,n);
	char x[11]; printf("\nMoi nhap ma sach can tim tim x= "); gets(x);gets(x);//[11]**************
	int vt= TimTuyenTinh(a,n,x);
	if(vt == -1)
		printf("\nTim khong thay %s", x);//[12]********************
	else
		printf("\nTim thay %s tai vi tri %d", x, vt);//[13]*************
	SapXep(a,n);
	printf("\n*****DANH SACH CAC CUON SACH SAU KHI SAP*****\n"); 
	XuatDS(a,n); 
	printf("\nMoi nhap ma sach can tim tim x= "); gets(x);//[14]***************
	vt= TimNhiPhan(a,n,x);
	if(vt == -1)
		printf("\nTim khong thay %s", x); //[15]***************
	else
		printf("\nTim thay %s tai vi tri %d", x, vt);//[16]**************
}
