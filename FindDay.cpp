#include<stdio.h>
#include<conio.h>
#include<time.h>
int res; //global declaration of variable
int fcorrect(int yr)
{
int ycode;
/*calculated in the range of 1500-2299*/
if(yr>=1500 && yr<1599){
ycode=0;
}
if(yr>=1600 && yr<1699){
ycode=6;
}
if(yr>=1700 && yr<1799){
ycode=4;
}
if(yr>=1800 && yr<1899){
ycode=2;
}
if(yr>=1900 && yr<1999){
ycode=0;
}
if(yr>=2000 && yr<2099){
ycode=6;
}
if(yr>=2100 && yr<2199){
ycode=4;
}
if(yr>=2200 && yr<2299){
ycode=2;
}
return ycode;
}
int calday(int day, int mon,int yr)
{ int quot,mcode,sum,res,yc;
/*code to find the last two digits of yr*/

int year,r1,r2,newyr;
newyr=yr;
r1=yr%10;
yr=yr/10;
r2=yr%10;
year=10*r2+r1;

quot=year/4; //to find the quotient of yr divides 4
/*Code to assign month codes*/
switch(mon)
{
case 1: mcode=0;break;
case 2: mcode=3;break;

case 3: mcode=3;break;
case 4: mcode=6;break;
case 5: mcode=1;break;
case 6: mcode=4;break;
case 7: mcode=6;break;
case 8: mcode=2;break;
case 9: mcode=5;break;
case 10: mcode=0;break;
case 11: mcode=3;break;
case 12: mcode=5;break;
}

/*main calculation*/
yc = fcorrect(newyr);
sum=day+quot+mcode+year+yc;
res=sum%7;

// to rectify the ans. in accordance with century code
return res;
}

void tellday(int res)
{
printf("The day is\n");

if(res==0)
printf("Sunday");
if(res==1)
printf("Monday");
if(res==2)
printf("Tuesday");
if(res==3)
printf("Wednesday");
if(res==4)
printf("Thursday");
if(res==5)
printf("Friday");
if(res==6)
printf("Saturday");
}

int main(){
 int day,mon,yr;

time_t t; // not a primitive datatype
time(&t); //print system date and time

printf("\nSystem Date and time:-\n %s", ctime(&t));
printf("Program to find the day for any date\n");
printf("\nEnter Day\n");
scanf("%d",&day);
printf("Enter Month\n");
scanf("%d",&mon);
printf("Enter year\n");
scanf("%d",&yr);
int res=calday(day,mon,yr);
tellday(res);
getch();
}
