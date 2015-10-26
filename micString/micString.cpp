#include <graphics.h>
#include <conio.h>
#include <math.h>

void microdrawLine(int x0, int y0, int x1, int y1, COLORREF scolor)
{
	float dx, dy, k, y, x;
	dx=x1-x0; dy=y1-y0; 
	k=abs(dy/dx);

	if (k<=1)
	{
		k=dy/dx;
		if (x0<x1)
		{
			y=y0;
			for (x=x0; x<=x1; x++)
			{
				putpixel(x, (int)(y+0.5), scolor);
				y=y+k;
			}
		}else{
			y=y1;
			for (x=x1; x<=x0; x++)
			{
				putpixel(x, (int)(y+0.5), scolor);
				y=y+k;
			}
		}
	}else{
		k=dx/dy;
		if (y0<y1)
		{
			x=x0;
			for (y=y0; y<=y1; y++)
			{
				putpixel((int)(x+0.5), y, scolor);
				x=x+k;
			}
		}else{
			x=x1;
			for (y=y1; y<=y0; y++)
			{
				putpixel((int)(x+0.5), y, scolor);
				x=x+k;
			}
		}
	}
	return;
}

void midString(int x0, int y0, int x1, int y1, COLORREF scolor)
{
	int a, b, del1, del2, d, x, y, flag;
	float k;
	a=y0-y1; b=x1-x0;
	del1=2*a; del2=2*(a+b);
	x=x0; y=y0;
	k=(y1-y0)/(x1-x0);
	if (0<=k<=1)
	{
		putpixel(x, y, scolor);
		d=2*a+b;
		while(x<x1){
			if (d<0)
			{
				x++; y++;
				d+=del2;
				putpixel(x, y, scolor);
			}else{
				x++; d+=del1;
				putpixel(x, y, scolor);
			}
		}
	}else if (-1<=k<0)//有问题
	{
		putpixel(x, y, scolor);
		del2=2*(a-b);
		d=2*a-b;
		while(x<x1){
			if (d<0)
			{
				x++; d+=del1;
				putpixel(x, y, scolor);
			}else{
				x++; y--; d+=del2;
				putpixel(x, y, scolor);
			}
		}
	}else if (k>1)
	{
		putpixel(x, y, scolor);
		del1=2*b;
		d=a+2*b;
		while(y<y1){
			if (d>0)
			{
				x++; y++;
				d+=del2;
				putpixel(x, y, scolor);
			}else{
				y++;
				d+=del1;
				putpixel(x, y, scolor);
			}
		}
	}else{
		x=x1, y=y1;
		putpixel(x, y, scolor);
		d=-a+2*b;
		del1=2*b; del2=2*(b-a);
		while(y<y0){
			if (d<0)
			{
				y++; d+=del1;
				putpixel(x, y, scolor);
			}else{
				y++; x--; d+=del2;
				putpixel(x, y, scolor);
			}
		}
	}
	return;
}

int main()
{
	initgraph(480, 600);
	char xydot[20], buffer[5];
	InputBox(xydot, 20, "请输入线端点");
	//setbkmode(TRANSPARENT);
	//printf("请输入线端点: ");
	int i, x0, y0, x1, y1, flag=1, t=0;
	COLORREF scolor;
	for (i=0; i<20; i++)
	{
		if (xydot[i]!=' '&&xydot[i]!=NULL)
		{
			buffer[t++]=xydot[i];
		}
		if (xydot[i]==' ' || xydot[i]==NULL)
		{
			switch(flag){
			case 1: x0=atoi(buffer); break;
			case 2:y0=atoi(buffer); break;
			case 3:x1=atoi(buffer); break;
			case 4:y1=atoi(buffer); break;
		}
			flag++; t=0;
			memset(buffer, NULL, sizeof(buffer));
	}
}
	memset(xydot, 0, sizeof(xydot));
	//InputBox(xydot, 20, "请输入颜色");
	scolor = WHITE;
	microdrawLine(x0, y0, x1, y1, scolor);
	//midString(x0, y0, x1, y1, scolor);
	if (getch())
	{
		closegraph();
	}
	return 0;
}