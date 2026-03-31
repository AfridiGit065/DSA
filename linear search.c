#include<stdio.h>
int B(int ar[],int n,int key){
for  (int i=0;i<n;i++){
     if (ar[i]==key){
          return i;
}
}
return -1;
}
int main()
{
    int a[7]={3,3,3,3,7,8,9};
	int key ;
	int save = -1;

	printf("Enter the key = ");
	scanf("%d",&key);

	/*for(int i = 0; i < 7; i++)
	{
		if(a[i]==key)
		{
			printf("%d found in index %d",key,i);
			break;
			save = i;
		}
	}*/
	if (B(a,7,key)!=-1){

	printf("Last %d found in index %d",key,save);}
	else printf ("Not found");
	return 0;
}
