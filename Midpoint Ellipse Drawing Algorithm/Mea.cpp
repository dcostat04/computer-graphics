#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include<ctype.h>
void main()
{
int gd = DETECT, gm;
int xc,yc,x,y;float p;
long rx,ry;
initgraph(&gd,&gm,"C://TurboC3//BGI");
cleardevice();
cout<<"Enter coordinates of centre : ";
cin>>xc>>yc;
cout<<"Enter rx and ry of ellipse: ";
cin>>rx>>ry;
p=ry*ry-rx*rx*ry+rx*rx/4;
x=0;y=ry;
while(2*ry*ry*x <= 2*rx*rx*y)
{
if(p < 0)
{
x++;
p = p+2*ry*ry*x+ry*ry;
}
else
{
x++;y--;
p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
}
putpixel(xc+x,yc+y,RED);
putpixel(xc+x,yc-y,RED);
putpixel(xc-x,yc+y,RED);
putpixel(xc-x,yc-y,RED);
}
p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
while(y > 0)
{
if(p <= 0)
{
x++;y--;
p = p+2*ry*ry*x-2*rx*rx*y+rx*rx;
}
else
{
y--;
p = p-2*rx*rx*y+rx*rx;
}
putpixel(xc+x,yc+y,RED);
putpixel(xc+x,yc-y,RED);
putpixel(xc-x,yc+y,RED);
putpixel(xc-x,yc-y,RED);
}
getch();
closegraph();
}
