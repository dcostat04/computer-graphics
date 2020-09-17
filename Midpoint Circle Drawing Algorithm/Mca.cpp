#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
void drawCircle(int x,int y,int xc,int yc);
int main()
{int gd=DETECT,gm;
int r,xc,yc,pk,x,y;
initgraph(&gd,&gm,"C://TurboC3//BGI");
cout<<"Draw a Circle using midpoint circle Algorithm";
cout<<"\nEnter the Center Co-ordinates:\n";
cin>>xc>>yc;
cout<<"\nEnter the Radius\n";
cin>>r;
pk=1-r;
x=0;
y=r;
while(x<y)
{drawCircle(x,y,xc,yc);
++x;
if(pk<0)
{pk=pk+(2*x)+1;
}
else
{
--y;
pk=pk+(2*x)+1-(2*y);
}}
getch();
closegraph();
return 0;
}
void drawCircle(int x, int y,int xc,int yc)
{putpixel(x+xc,y+yc,GREEN);
putpixel(-x+xc,y+yc,GREEN);
putpixel(x+xc,-y+yc,GREEN);
putpixel(-x+xc,-y+yc,GREEN);
putpixel(y+xc,x+yc,GREEN);
putpixel(y+xc,-x+yc,GREEN);
putpixel(-y+xc,x+yc,GREEN);
putpixel(-y+xc,-x+yc,GREEN);
}
