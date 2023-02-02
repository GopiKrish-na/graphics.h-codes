/***************************************************************************************************
 Title: 2D-Transformation (Translation, Rotation, Scaling)
 file name: 2Dtransformation.cpp
 Author: Bal Krishna Shah (THA077BEI010)
 Date: 31-01-2023
***************************************************************************************************/
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
void draw();
void translate();
void rotate();
void scale();
int n, tx, ty, i, option;
float x[100], y[100], sfx, sfy;
double s, c, angle;
int main()
{

    initwindow(700, 400, "BAL KRISHNA's WINDOW");
    setbkcolor(WHITE);
    cleardevice();
    cout << "Enter the number of vertices of the polygon: ";
    cin >> n;
    cout << "\nEnter the (x, y) coordinates for each vertices: ";
    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    setcolor(BROWN);
    draw();
    while (1)
    {
        cout << "\n1. Translate\n2. Rotate\n3. Scale\n4. exit\n";
        cout << "Enter the 2D transformation operation you want to do: ";
        cin >> option;
        switch (option)
        {
        case 1:
            translate();
            setcolor(BLACK);
            draw();
            break;
        case 2:
            rotate();
            setcolor(BLACK);
            draw();
            break;
        case 3:
            scale();
            setcolor(BLACK);
            draw();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Choose correct option!!";
            break;
        }
    }
    getch();

    return 0;
}
void translate()
{
    cout << "\nEnter the translation factor tx and ty: ";
    cin >> tx >> ty;
    for (i = 0; i < n; i++)
    {
        x[i] += tx;
        y[i] += ty;
    }
}
void rotate()
{
    cout << "\nEnter the rotation angle (radian): ";
    cin >> angle;
    c = cos(angle * 3.14 / 180);
    s = sin(angle * 3.14 / 180);
    for (i = 0; i < n; i++)
    {
        x[i] = floor(x[2] + ((x[i] - x[2]) * c - (y[i] - y[2]) * s));
        y[i] = floor(y[2] + ((x[i] - x[2]) * s + (y[i] - y[2]) * c));
    }
}
void scale()
{
    cout << "\nEnter scaling factors sfx and sfy: ";
    cin >> sfx >> sfy;
    for (i = 0; i < n; i++)
    {
        x[i] = x[0] + (int)((float)(x[i] - x[0]) * sfx);
        y[i] = y[0] + (int)((float)(y[i] - y[0]) * sfy);
    }
}
void draw()
{
    for (i = 0; i < n; i++)
    {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}