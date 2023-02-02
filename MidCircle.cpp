
#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;

void drawMidCircle(int x_centre, int y_centre, int r)
{
    int x, y, dp;
    initwindow(700, 400, "BAL KRISHNA SHAH'S WINDOW");
    setbkcolor(WHITE);
    cleardevice();
    x = 0;
    y = r;
    dp = 1 - r;
    do
    {
      cout << x_centre + x <<"," << y_centre + y << endl;
      cout <<x_centre + y <<"," << y_centre + x <<endl;
      cout << x_centre - y <<"," << y_centre + x <<endl;
      cout <<  x_centre - x <<"," << y_centre + y <<endl;
      cout << x_centre - x <<"," << y_centre - y <<endl;
      cout << x_centre - y <<"," << y_centre - x <<endl;
      cout << x_centre + y <<"," << y_centre - x <<endl;
      cout << x_centre + x <<"," << y_centre - y <<endl;
      putpixel(x_centre, y_centre, BLACK);
      putpixel(x_centre+x,y_centre+y,BLACK);
      putpixel(x_centre+y,y_centre+x,BLACK);
      putpixel(x_centre-y,y_centre+x,BLACK);
      putpixel(x_centre-x,y_centre+y,BLACK);
      putpixel(x_centre-x,y_centre-y,BLACK);
      putpixel(x_centre-y,y_centre-x,BLACK);
      putpixel(x_centre+y,y_centre-x,BLACK);
      putpixel(x_centre+x,y_centre-y,BLACK); 
      delay(100); 
      if (dp < 0)
      {
        dp = dp + 2*x + 1;
      }
      else
      {
        y = y - 1;
        dp = dp + (2*x) - (2*y) + 1;
      }
      x = x + 1;
    }while (y>x);
}
int main()
{
    int x_centre, y_centre, r;
    
    cout << "\nEnter centre of the circle(h, k): ";
    cin >> x_centre >> y_centre;
    cout << "\nEnter radius of the circle: ";
    cin >> r;
    drawMidCircle(x_centre, y_centre, r);
    getch();
    closegraph();

}