#include<stdio.h>
typedef struct date{ 
	int dd;
	int mm;
	int yy;
	} Date;
		Date dateInc(Date cd)
		{

		 static Date nd;
		 int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
		 if((cd.yy%400==0) || (cd.yy%100!=0 && cd.yy%4==0))
		 	months[1]=29;
		
		nd.dd=cd.dd;
		nd.mm=cd.mm;
		nd.yy=cd.yy;
		
		if(nd.dd < months[cd.mm-1])
		{
			nd.dd++;
		}
		else
		{
			nd.dd=1;
			nd.mm++;
			if(nd.mm == 13){
			
				nd.mm=1;
				nd.yy++;	
			}
	   }
		  return nd;
		  
	}
void main()
{
 Date d1,newDate;
 printf("\n\nEnter CURRENT DATE (DD/MM/YYYY)	: ");
 scanf("%d/%d/%d",&d1.dd,&d1.mm,&d1.yy);
 newDate=dateInc(d1);
 printf("\n NEW DATE (DD/MM/YYYY)		: %02d/%02d/%04d", newDate.dd, newDate.mm, newDate.yy);
 }