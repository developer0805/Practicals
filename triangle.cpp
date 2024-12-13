#include<iostream>
#include<graphics.h>
using namespace std;
void plotline(float x1,float y1,float x2,float y2)
{
    float m =(y2-y1)/(x2-x1);
    if(x1>x2)
    {  
       int temp=x1;
       x1=x2;
       x2=temp;
       
       temp=y1;
       y1=y2;
       y2=temp;
    }
while(x1<=x2)
{
            delay(10);
		putpixel(x1,y1,BLACK);
		
		if(m<1)
		{
			x1++;
			y1 = y1 + m;
		}
		else if(m==1)
		{
			x1++;
			y1++;
		}
            else
		{
			y1++;
			x1 = x1 + 1/m;
		}
	}
}
void plotcircle(int xc, int yc, int Radius)
{
	static int i = 0;
	int d = 3 - 2*Radius;
	int x = 0, y = Radius;
while(x<=y)
	{
	if(i == 0)
	{
			delay(10);
			putpixel(xc+x, yc+y, BLACK);
			putpixel(xc+x, yc-y, BLACK);
			putpixel(xc-x, yc+y, BLACK);
			putpixel(xc-x, yc-y, BLACK);
			putpixel(xc+y, yc+x,MAGENTA);
			putpixel(xc+y, yc-x,MAGENTA);
			putpixel(xc-y, yc+x,MAGENTA);
			putpixel(xc-y, yc-x, MAGENTA);
	 }
       else
	 {
			delay(10);
			putpixel(xc+x, yc+y, MAGENTA);
			putpixel(xc+x, yc-y, MAGENTA);
			putpixel(xc-x, yc+y, MAGENTA);
			putpixel(xc-x, yc-y, MAGENTA);
			putpixel(xc+y, yc+x,BLACK);
			putpixel(xc+y, yc-x, BLACK);
			putpixel(xc-y, yc+x, BLACK);
			putpixel(xc-y, yc-x, BLACK);
	 }
       if(d<0)
        {
			d = d  + 4*x +6;
	  }
	else
	 {
			d = d + 4*(x-y) + 10;
			y--;
	 }
	x++;
}
i++;
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	setbkcolor(WHITE);
	plotline(200,50,28,350);
	plotline(28,350,372,350);	
	plotline(372,350,200,50);
	
	plotcircle(200,250,100);
	plotcircle(200,250,200);
	
	getch();
	closegraph();
	return 0;
}
	
 
   
