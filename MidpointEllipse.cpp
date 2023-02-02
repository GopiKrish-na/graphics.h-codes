/******************************************************************************************************
Title: Midpoint Ellipse Drawing Algorithm
Author: Bal Krishna Shah (THA077BEI010)
filename: MidpointEllipse.cpp
Date: 2023-01-20
*******************************************************************************************************/
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;


void DrawMidEllipse(int xc, int yc, int rx, int ry)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
    //Innitial decision parameter
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;
    //decision parameter for region 1
    while (dx<dy)
    {
        //plotting the pixel at the start of the loop to avoid any missing plot
        putpixel (x+xc, y+yc, BLACK);
        putpixel (-x+xc, y+yc, BLACK);
        putpixel (x+xc, -y+yc, BLACK);
        putpixel (-x+xc, -y+yc, BLACK);
        delay(50);
        
        //printing the obtained coordinates
        cout << x+xc << "," << y + yc << endl;
        cout << -x+xc << "," << y + yc << endl;
        cout << x+xc << "," << -y + yc << endl;
        cout << -x+xc << "," << -y + yc << endl;
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);

        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
        }
    
    
    }
    //Decision Parameter for region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +((rx * rx) * ((y - 1) * (y - 1))) -(rx * rx * ry * ry);
    while (y>=0)
    {
        putpixel (x+xc, y+yc, BLACK);
        putpixel (-x+xc, y+yc, BLACK);
        putpixel (x+xc, -y+yc, BLACK);
        putpixel (-x+xc, -y+yc, BLACK);
        delay(50);
        cout << x+xc << "," << y + yc << endl;
        cout << -x+xc << "," << y + yc << endl;
        cout << x+xc << "," << -y + yc << endl;
        cout << -x+xc << "," << -y + yc << endl;
        if (d2>0)
        {
            y--;
            dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            x++;
            y--;
          	dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
        }
    }
}
// coordinates entry and window creation in main function
int main()
{
 int x_centre, y_centre, x_radius, y_radius;   
 cout << "\nEnter the centre of the ellipse: ";
 cin >> x_centre >> y_centre;
 cout << "\nEntre the x and y radius of the ellipse: ";
 cin >> x_radius >> y_radius;
 initwindow (700, 400, "BAL KRISHNA'S WINDOW!!");
 setbkcolor(WHITE);
 cleardevice();
 DrawMidEllipse(x_centre, y_centre, x_radius, y_radius);
 getch();
 closegraph();
}