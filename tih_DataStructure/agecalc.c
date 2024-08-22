#include<stdio.h>
#include<conio.h>
typedef struct date{ 
	int dd;
	int mm;
	int yy;
	} Date;
		Date age(Date cd,Date bd)
		{
		 Date diff;
		 if(bd.dd>cd.dd)
		  {
		   diff.dd = cd.dd+30-bd.dd;
		   cd.mm--;
		   }
		  else
		   diff.dd = cd.dd-bd.dd;
		 if(bd.mm>cd.mm)
		  {
		   diff.mm = cd.mm+12-bd.mm;
		   cd.yy--;
		   }
		  else
		   diff.mm = cd.mm-bd.mm;
		   diff.yy=cd.yy-bd.yy;
		  
		  	return diff;
		  }
void main()
{
 Date d1,d2,p_age;
 printf("\n\nEnter Current Date (DD/MM/YYYY)	: ");
 scanf("%02d/%02d/%4d",&d1.dd,&d1.mm,&d1.yy);
 printf("\nEnter Date of Birth (DD/MM/YYYY)    	: ");
 scanf("%02d/%02d/%4d",&d2.dd,&d2.mm,&d2.yy);
 p_age=age(d1,d2);
 printf("Your age is: %d years %d months %d days", p_age.yy, p_age.mm, p_age.yy);
 }
