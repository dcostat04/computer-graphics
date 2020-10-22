#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void main()
{
int gdriver=DETECT,gmode;
int i;

     initgraph(&gdriver,&gmode,"c:\\turboc3\\BGI");
     for(i=0;i<120 ;i++)
     {
     // delay(10);
 cleardevice();
    if(i<90){
       setbkcolor(0);
       setcolor(4);
       setfillstyle(SOLID_FILL,RED);
       circle(320,190-i,20);
       floodfill(320,190-i,RED);
       }
    else{
       setbkcolor(11);
       setcolor(14);
       setfillstyle(SOLID_FILL,YELLOW);
       circle(320,190-i,20);
       floodfill(320,190-i,YELLOW);
       }
       setcolor(2);
	setfillstyle(SOLID_FILL,GREEN);
       line(50,250,100,150);
       line(100,150,200,250);
       line(50,250,200,250);
       floodfill(125,200,GREEN);
       line(200,250,250,150);
       line(250,150,300,250);
       line(200,250,300,250);
       floodfill(250,200,GREEN);
       line(300,250,400,150);
       line(400,150,500,250);
       line(300,250,500,250);
       floodfill(400,200,GREEN);

   delay(100);

     }
     getch();
     }
