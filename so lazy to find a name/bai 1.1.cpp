#include<stdio.h>
#define MAX 100
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
void NhapMang(int a[], int n)
{
	for( int i=0 ; i<n ; i++ )  //duyet mang XUOI
	{
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n)
{
	for( int i=0 ; i<n ; i++ )  //duyet mang XUOI
		printf("%5d", a[i]);
}
int TimTuyenTinh(int a[], int n, int X)
{
	a[n]=X;  //dat linh canh vao cuoi danh sach //[1]
	int i=0; //duyet tu dau danh sach
	while(a[i]!=X ) //[2]
		i++; //qua phan tu ke => next
	////////////////////////////////////////////////
	if(i<n) return i;
	return -1;
}

int main()
{
	int n; NhapSL(n);
	int a[MAX]; NhapMang(a,n);
	printf("\nMang sau khi nhap= "); XuatMang(a,n);
	int x; printf("\nMoi nhap gia tri can tim tim x= "); scanf("%d", &x);
	int vt= TimTuyenTinh(a,n,x);
	if(vt == -1)
		printf("\nTim khong thay %d", x);
	else
		printf("\nTim thay %d tai vi tri %d", x, vt);
}
