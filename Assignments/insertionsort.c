#include<stdio.h>
void insertionsort(int a[],int n,int *shifts)
{
	*shifts=0;
	for(int i=1;i<n;i++)
	{
		int key=a[i];
		int j=i-1;
		
		while(j>=0 && key<a[j])
		{
			a[j+1]=a[j];
			j--;
			(*shifts)++;
		}
		a[j+1]=key;
		
		printf("Pass %d: ",i);
		for(int k=0;k<n;k++)
		printf("%d ",a[k]);
		printf("\n");
	}
}
int main()
{
	int n,shifts;
	printf("Enter no.of student marks: \n");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter student marks: \n");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	insertionsort(a,n,&shifts);
	
	printf("Marks in ascending order: \n");
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("Total no.of element shifts: %d",shifts);
	return 0;
}