#include<stdio.h>
int main()
{
    int n,i,low,high,found=0,id,mid;
    int count=0;
    printf("Enter no. of employee IDs:");
    scanf("%d",&n);
    int a[n];
    printf("Enter employee IDs in ascending order:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the required employee ID:");
    scanf("%d",&id);
    low=0;
    high=n-1;
    while(low<high)
    {
        mid=(low+high)/2;
        count++;
        if(a[mid]==id)
        {
            found=1;
            break;
        }
        else if(a[mid]<id)
        low=mid+1;
        else
        high=mid-1;
    }
    if(found)
    printf("Employee ID %d is found at %d position.",id,mid+1);
    else
    printf("Employee ID %d is absent.",id);
    printf("The total number of comparisions:%d",count);
}
