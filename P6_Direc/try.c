#include<stdio.h>

void fun(int *a);
main(){
	int a=3;
	printf("&a:%d\n,a:%d\n,*",&a,a);
	fun(&a);
}

void fun(int *a){
	printf("\na:%d\n*a:%d\n&a:%d\n&&a:%d",a,&*a,&a,*&*a);
	*a=2;
}
