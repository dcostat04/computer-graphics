#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
void main()
{
clrscr();
int gd=DETECT,gm;
//cleardevice();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setbkcolor(0);
rectangle(0,0,getmaxx(),getmaxy());
setfillstyle(SOLID_FILL,BLUE);
line(0,200,getmaxx(),200);
floodfill(10,150,WHITE);
setfillstyle(SOLID_FILL,BROWN);
line(0,200,150,100);
line(150,100,300,200);
floodfill(50,175,WHITE);
setfillstyle(SOLID_FILL,BROWN);
line(300,200,375,150);
line(375,150,450,200);
floodfill(375,160,WHITE);
setfillstyle(SOLID_FILL,BROWN);
line(450,200,600,100);
line(600,100,750,200);
floodfill(600,150,WHITE);
int i,j;
for(i=0;i<420;i=i+10,j++)
{
//cleardevice();
setviewport(0,200,getmaxx(),getmaxy(),0);
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
rectangle(50+i,275-200,150+i,400-200);
floodfill(60+i,300-200,RED);
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
rectangle(150+i,350-200,200+i,400-200);
floodfill(160+i,360-200,YELLOW);
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
circle(75+i,410-200,10);
floodfill(75+i,410-200,WHITE);
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
circle(175+i,410-200,10);
floodfill(175+i,410-200,WHITE);
//setcolor(j);
delay(100);
clearviewport();
if(i==420)
    break;

}

delay(100);
getch();
closegraph();




}
