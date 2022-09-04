#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int pow(int c, int us)
{
	int i=1,a=1;
	for(i=1;i<=us;i++) a=a*c;
	return a;
}

unsigned long long int digitsno(int x)
{
	int i=0,d;
	while(x>0)
	{
		x/=10;
		i++;
	}
	return i;
}

unsigned long long int reverse_of_number(unsigned long long int num)
{
	unsigned long long int d,a=0;
	
	while(num!=0)
	{
		d=num%10;
		a+=d;
		a*=10;
		num/=10;
	}
	return a;
}

unsigned long long int todecimal(unsigned long long int num,int base)
{
	long long int sonuc=0,d,i=0;
	while(num>0)
	{
		d=num%10;
		sonuc+=pow(base,i)*d;
		num/=10;
		i++;
	}
	return sonuc;
}

unsigned long long int tonewbase(unsigned long long int num,int old_base, int new_base)
{
	unsigned long long int rem2,j=1,son=0,ans=10,rem,in_decimal=todecimal(num, old_base);

		rem2=in_decimal%new_base;
		if(rem2==0) son+=1;
		while(ans>=new_base)
		{
			ans=in_decimal/new_base;
			rem=in_decimal%new_base;
			son+=rem;
			son*=10;
			in_decimal=ans;
			j++;
		}
		
		rem=in_decimal%new_base;
		son+=rem;
		son*=10;
		//for hexadecimal
		if(new_base!=16) son=reverse_of_number(son);
		if(rem2==0)
		{
			son-=1;
			son/=10;
			//son-=1;
		} 

		if(new_base==8&&num%10!=0) son/=10;
		if(new_base==8&&rem2==0&&num%10!=0) son*=10;
		if(new_base==2&&num%2==1) son/=10;
		if(new_base==5&&num%5!=0) son/=10;
		if(new_base==8&&rem2!=0&&num%10==0) son/=10;
	return son;
}

int check(int x,int old_base)
{
	int d,i=0,j=0;
	int dd=digitsno(x);
	for(i=0;i=digitsno(x);i++)
	{
		d=x%10;
		if(d<old_base) j++;
		x/=10;
	}
	//printf("\nj is %d",j);
	if(dd==j) return 1;
	else return 0;
}


int main()
{
printf(" ________________________________\n");
printf("|                                |\n");
printf("|Welcome to Number conversion app|\n");
printf("|         Made by Mohamad        |\n");
printf("|                                |\n");
printf("|________________________________|\n\n");
int s;
for(s=1;s=100;s++)
{

	unsigned long long int to,from;
	unsigned long long int x;
	printf("\n\nEnter number to convert it:"); scanf("%lld",&x);
	printf("from what base you want to convert?:"); scanf("%lld",&from);
	while(check(x,from)==0)
	{
		printf("\nSORRY!!,  %lld IS NOT IN BASE %d,TRY AGAIN... \n\n",x,from);
		printf("enter number to convert it:"); scanf("%lld",&x);
		printf("from what base you want to convert?:"); scanf("%d",&from);
	}
	printf("to what base you want to convert? :"); scanf("%lld",&to);
	

	//if(to==10) printf("%d in decimal is: %d\n\n\n",x,todecimal(x,from));
	switch(to)
	{
		case 10: printf("%lld in decimal is: %llu\n\n\n",x,todecimal(x,from));
		break;
		case 2: printf("%lld in binary  is: %llu\n\n\n",x,tonewbase(x,from,to));
		break;
		case 8: printf("%lld in octal  is: %llu\n\n\n",x,tonewbase(x,from,to));
		break;
		case 16://printf("%lld in hexadecimal is: %llu\n\n\n",x,tohexa(tonewbase(x,from,2)));
		{
			long long int binary=tonewbase(x,from,2);
		    int v[4];
		    int hexadecimal=0;
		    int i=1,j=0;
		    int s,d,g;
		    long long int temp=1;
		    //printf("\n\nEnter the binary number: ");
		    //scanf ("%lld",&binary);
		    while(binary!=0)
		    {
		    	s=0;
		    	temp=1;
		    	i=1;
				for(i=1;i<=4;i++)
				{
					d=binary%10;
					temp+=d;
					temp*=10;
					binary/=10;
				}
				temp/=10;
				temp=reverse_of_number(temp);
				temp-=1;
				//v[j]=temp;
		        //printf("temp = %d\t",temp);
		        temp/=10;
		        if(temp==0) s=0;
		        if(temp==1) s=1;
		        if(temp==10) s=2;
		        if(temp==11) s=3;
		        if(temp==100) s=4;
		        if(temp==101) s=5;
		        if(temp==110) s=6;
		        if(temp==111) s=7;
		        if(temp==1000) s=8;
		        if(temp==1001) s=9;
		        if(temp==1010) s=10;
		        if(temp==1011) s=11;
		        if(temp==1100) s=12;
		        if(temp==1101) s=13;
		        if(temp==1110) s=14;
		        if(temp==1111) s=15;
		        v[j]=s;
		        j++;
			}
		int n=sizeof(v)/sizeof(int);
		//for(i=0;i<=n-1;i++) printf("%d,  ",v[i]);
		printf("\n\n%lld in hexadecimal = ",x);
		int v2;
		for(i=j-1;i>=0;i--) 
		{
		v2=v[i];
		//printf("\n%d\n",v2);
			if(v2==0) printf("0");
			if(v2==1) printf("1");
	     	if(v2==2) printf("2");
		    if(v2==3) printf("3");
		    if(v2==4) printf("4");
		    if(v2==5) printf("5");
		    if(v2==6) printf("6");
		    if(v2==7) printf("7");
		    if(v2==8) printf("8");
		    if(v2==9) printf("9");
		    if(v2==10) printf("A");
		    if(v2==11) printf("B");
		    if(v2==12) printf("C");
		    if(v2==13)printf("D");
		    if(v2==14) printf("E");
			if(v2==15) printf("F");
		}
				break;
		//default: printf("%d in base %lld is: %llu\n\n\n",x,to,tonewbase(x,from,to));
	}
		default: printf("%d in base %lld is: %llu\n\n\n",x,to,tonewbase(x,from,to));
	/*
	getch();
	system("cls");
	main();
	*/
	}
}
}


