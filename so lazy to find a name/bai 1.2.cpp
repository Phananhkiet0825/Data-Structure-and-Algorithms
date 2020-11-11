#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000
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
void PhatSinh(int a[], int n)
{
	for(int i=0;i<n;i++)  //duyet mang
		a[i]= rand()%99+1; //phat sinh 1 so nguyen tu 1 den 99
}
void XuatMang(int a[], int n)
{
	for(int i=0;i<n;i++)  //duyet mang
		printf("%5d", a[i]);
}
void HoanVi(int &x, int &y)
{
	int t=x; 	x=y; 	y=t;
}
void SelectSort(int a[], int n)
{
	for(int i=0; i<n-1; i++) 
	{
		/* Tim vi tri min*/
		int vt=i;
		for(int j=i+1; j<n; j++)
			if(a[j]<a[vt])
				vt=j;
		/*Hoan vi giua phan tu a[i] voi a[vt]*/
		HoanVi(a[i], a[vt]);
	}
}
void BubbleSort(int a[], int n)
{
	for(int i=0; i<n-1; i++) 
		for(int j=n-1; j>i; j--)  //duyet nguoc tu duoi len
			if(a[j]<a[j-1])
				HoanVi(a[j],a[j-1]);
}
void InterChangeSort(int a[], int n)
{
	for(int i=0; i<n-1; i++) 
		for(int j=i+1;j<n;j++)  //duyet xuoi tu sau i cho den het mang
			if(a[i]>a[j])
				HoanVi(a[i],a[j]);
}
void InsertSort(int a[], int n)
{
	for(int i=1;i<n;i++) //duyet mang ben phai chua duoc sap
	{
		int x=a[i];   //nhac bong bien x len
		int pos=i-1;  //duyet nguoc day vang khe ben trai
		while(pos>=0 && a[pos]>x)  //trong khi chua het mang vang khe ben trai
		{
			a[pos+1]=a[pos];
			//phep gan <- : gan gia tri tu dang sau ra dang truoc
			pos--; //duyet nguoc
		}
		//////////////////////////////////
		a[pos+1]=x;  //ha bien x xuong
	}
}
void ShellSort(int A[], int n, int h[] , int k = 3)
{
	//h[]={5,3,1}
	int step, i, pos, x, len;
	for (step = 0; step < k; step++) 
	{
		len = h[step];
		//viet theo insertionSort 
		for (i = len; i < n; i++)
		{
			x = A[i];
			pos = i - len;
			while (pos >= 0 && x < A[pos]) //???????????
			{
				A[pos + len] = A[pos];
				pos = pos - len;
			}
			A[pos + len] = x;
		
		}
	}
}
void XuatMaTran(int A[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			printf("%4d", A[i][j]);
		printf("\n");
	}
}
void QuickSort(int A[], int left, int right)
{
	int i, j, x;
	x = A[(left+right)/2];
	i = left; j = right;
	do
	{
		while (A[i] < x)i++;
		while (A[j] > x) j--;
		if (i <= j)
		{
			HoanVi(A[i], A[j]);
			i++; j--;
		}
	} while (i<j);
	if (left < j) QuickSort(A, left, j);
	if (right > i) QuickSort(A, i, right);
}

void RadixSort(int A[], int n)
{
	const int MAXDIGIT = 3;
	int coso = 1;
	for (int d = 0; d < MAXDIGIT; d++)
	{
		int B[10][MAX] = { 0 };
		//phân ph?i t? m?ng vào ma tr?n
		for (int cot = 0; cot < n; cot++)
		{
			int dong = A[cot ]/coso % 10;//???????????????
			B[dong][cot] = A[cot];
		}
		XuatMaTran(B, 10, n);
		getch();
		// thu gom theo t?ng dòng
		int itam = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < n; j++)
				if (B[i][j]>0)
					A[itam++] = B[i][j];
		
		coso = coso * 10;
		XuatMang(A, n);
		printf("\n");
		getch();
	}
}
void MergeSort(int A[], int n)
{
	int i, j, k, low1, up1, low2, up2, size;
	int DStam[MAX];
	size = 1;
	while (size < n)
	{
		low1 = 0;
		k = 0;
		while (low1 + size < n)
		{
			low2 = low1 + size;
			up1 = low2 - 1;
			up2 = (low2 + size - 1 < n) ? (low2 + size - 1) : (n - 1);
			for (i = low1, j = low2; i <= up1 && j <= up2; k++)
			if (A[i] <= A[j]) DStam[k] = A[i++];
			else
			DStam[k] = A[j++];
			
			for (; i <= up1; k++)
			DStam[k] = A[i++];
			for (; j <= up2; k++)
			DStam[k] = A[j++];
			low1 = up2 + 1;
		}
		for (i = low1; k < n; i++)
			DStam[k++] = A[i];
		for (i = 0; i < n; i++)
			A[i] = DStam[i];
		size *= 2;
	}
}


int Menu()
{
	printf("\n\t\t\tMENU");
	printf("\n1. BubbleSort");
	printf("\n2. SelectionSort");
	printf("\n3. InterChangeSort");
	printf("\n4. InsertionSort");
	printf("\n5. ShellSort");
	printf("\n6. QuickSort");
	printf("\n7. RadixSort");
	printf("\n8. MergeSort");
	printf("\n9. Quit");
	printf("\nMoi ban chon tu 1 den 9: ");
	int chon;
	scanf("%d", &chon);
	return chon;
}
void CopyMang(int A[], int n, int B[])
{
	for (int i = 0; i < n; i++)
		B[i]=A[i];
}
int main()
{
	srand((unsigned)time(NULL));
	int A[MAX],B[MAX]; int n;
	int h[] = { 5,3,1 };
	n=Nhap();
	PhatSinh(A, n);
	XuatMang(A, n);
	printf("\n");
	do
	{
		int chon = Menu();
		if (chon == 9)
			break; //thoat khoi vong lap do{....}while();
		CopyMang(A, n, B);
		switch (chon)
		{
			case 1: BubbleSort(B, n); printf("\nMang sau khi sap= ");
			
					XuatMang(B, n); break;
			
			case 2: SelectSort(B, n); printf("\nMang sau khi sap= ");
			
					XuatMang(B, n); break;
			
			case 3: InterChangeSort(B, n); printf("\nMang sau khi sap= ");
			
					XuatMang(B, n); break;
			
			case 4: InsertSort(B, n); printf("\nMang sau khi sap= ");
			
					XuatMang(B, n); break;
			
			case 5: ShellSort(B, n,h,3); printf("\nMang sau khi sap= ");
			
					XuatMang(B, n); break;
			
			case 6: QuickSort(B, 0,n-1); printf("\nMang sau khi sap= ");
			
					XuatMang(B, n); break;
			
			case 7: RadixSort(B, n); printf("\nMang sau khi sap= ");
			
					XuatMang(B, n); break;
			
			case 8: MergeSort(B, n); printf("\nMang sau khi sap= ");
			
					XuatMang(B, n); break;
			
			default: printf("\nBan chi chon tu 1 den 9 thoi......");
					break;
		
		}
	} while (true);
	printf("\nBan da thoat khoi chuong trinh.........");
}

