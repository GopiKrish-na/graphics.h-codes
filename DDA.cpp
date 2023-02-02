#include <graphics.h> 
#include <conio.h> 
#include <iostream> 
using namespace std; 
int main()
{ 
    //create window of resolution 720x480 
    initwindow(100, 74, "BAL KRISHNA'S WINDOW"); 
    //Declaring all required variables 
    float x, y, dx, dy, steps; 
    int x0, y0, x1, i, y1; 
    //initializing starting and ending coordinates 
    x0 = 0; y0 = 0; x1 = 100; y1= 74; 
    dx = (float)(x1-x0); 
    dy = (float)(y1-y0); 
    //if abs(dx) if greater than and equal to abs(dy) //total steps is equal to dx 
    if (dx>=dy) 
    steps = dx; 
    else 
    steps = dy; 
    dx = dx/steps;
    dy = dy/steps; 
    x = x0; 
    y = y0; 
    i = 1; 
    while (i<=steps){
         //plotting pixels in the incremented coordinates from start to end 
         putpixel(x, y, WHITE); 
         cout << x <<"," << y <<"\n"; 
         x = x + dx; 
         y = y+ dy; 
         i= i+1; //delay for visualization of DDA algorithm 
         delay(100); }
         getch(); 
         closegraph(); 
    }