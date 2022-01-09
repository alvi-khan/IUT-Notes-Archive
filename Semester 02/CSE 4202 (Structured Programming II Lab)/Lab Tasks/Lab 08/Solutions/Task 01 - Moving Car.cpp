#include<stdio.h>
#include<conio.h>
#include<graphics.h>

//using namespace std;
//include the above line only if there are errors

int main()
{
    int gdriver=DETECT, gmode;
    //gdriver specifies which graphics driver to use; DETECT means the graphics driver is automatically detected
    initgraph(&gdriver, &gmode, NULL);
    //initgraph(*graphicsDriver, *graphicsMode, *driverDirectory);
    //this loads the graphics driver; since gdriver is set to autodetect, gmode will be set to the highest resolution available
    //these lines will be difficult to understand for now, so for now, just include them when working with graphics

    int i;

    //the loop changes the x-axis values. dimensions must be adjusted according to requirements so that objects do not go outside the visible area

    for (i=0; i<=300; i=i+20)
    {
        rectangle(50+i, 100, 150+i, 200);       //creates a rectangle with top left and bottom right x and y coordinates
        rectangle(50+i, 200, 250+i, 300);
        circle(100+i, 340, 40);                 //creates a circle with x and y coordinates of the center, and the radius
        circle(200+i, 340, 40);
        delay(100);                             //waits 100ms
        cleardevice();                          //clears the board
    }
    closegraph();                               //closes the graph
}
