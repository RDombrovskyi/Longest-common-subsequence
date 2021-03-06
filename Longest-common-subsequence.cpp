#include<stdio.h>
#include<string.h>
#define N 20

int L[N][N];
char X[N],Y[N],tempX[N],tempY[N]; 

void LCS(int i, int j)
{
	if(i==0||j==0)
		return;
	
	if(X[i]==Y[j])
	{
		LCS(i-1,j-1);
		printf("%c",X[i]);
	}
	else if(L[i][j-1]>=L[i-1][j])
		LCS(i,j-1);
	else 
		LCS(i-1,j);
}

void LCS_LENGTH(int m, int n)
{
	int i,j;
	for(j=0;j<=n;j++)
		L[0][j]=0;
	for(i=1;i<=m;i++)
		L[i][0]=0;
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i]==Y[j])
				L[i][j]=1+L[i-1][j-1];
			else if(L[i][j-1]>=L[i-1][j])
				L[i][j]=L[i][j-1];
			else
				L[i][j]=L[i-1][j];
		}
	}
	printf("\nLongest Common Sub-Sequence of length %d is ",L[m][n]);
	LCS(m,n);
}

int main()
{
	int i,m,n;
	
	printf("Enter 1st String: ");
	gets(tempX);
	m=strlen(tempX);
	
	printf("Enter 2nd String: ");
	gets(tempY);
	n=strlen(tempY);
	
	for(i=1;i<=m;i++)
	{
		X[i]=tempX[i-1];
	}
		
	for(i=1;i<=n;i++)
	{
		Y[i]=tempY[i-1];
	}
	
	LCS_LENGTH(m,n);
	return 0;
}
