#include<stdio.h>

#include<math.h>

int power(int base,int exp){

	if(exp==0){

		return 1;

	}

	return base*power(base,exp-1);

}

int countDigits(int num){

	if(num==0){

		return 0;

	}

	return 1+countDigits(num/10);

}

int isArmstrong(int num,int count){

	if(num==0){

		return 0;

	}

	return power(num%10,count)+isArmstrong(num/10,count);

}

int main(){

	int num,count;

	printf("enter a number: ");

	scanf("%d",&num);

	count=countDigits(num);

	if(num==isArmstrong(num,count)){

		printf("%d is an Armstrong number.\n",num);

		

	}else{

		printf("%d is not an Armstrong number.\n",num);

	}

	return 0;

}
