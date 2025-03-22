#include <kipr/wombat.h>
#include "lib.h"


int main()
{

   //for the setting up of the robot we will use the pencil sharpener and on the left side and place the robot as far back as possible.

    
    enable_servos();

    int open3 = 2040;
    int open0 = 545;
    
    ///
   
    //wfl(7);
    sdi(120);
    
    
    //Get aligned with kitchen floor center line
    forsquare();
    
    ssp(500, 2,1560);
    ssp(500, 1,1380);
    
    forward(1000, 1000, 2000);
    //the square and forward will get the robot to line up with the edge of the start box
    
    right(1400);
    //turn onto the main line
    
    backward(1145, 950, 200);
    //back up to square up on back pvc
    
    set_servo_position(0, open0);
    msleep(1000);
    set_servo_position(3, open3);
    msleep(1000);
    pause(500);
    //set the servoposition to the most open
    ////
    
    
    ////
    forsquare();
    //square up witht the line infrom of hte start bok
    
    forward(1145, 959, 500);
    //Go forward to get to the lne that needs to be followed 
    
    follow(6000);
    //follow the center line all the way down to the perpendicular center lne
    forsquare();
    //squre up against perpendculr center line
    
    pause(500);
    
    cmpc(2);
    while (gmpc(2) > -725) 
    {
        mav(2, -100);
    }
    //raise the bottle device to prepare for grabbing
    
    pause(500);
    //
    backward(1145, 1145, 940);
    //back up to get the the positon for hte bottles
    
    left(1510);
    //turn left to line up with the bottles
    
    forward(1145, 1145, 850);
    ///forward ot tget tto the bottles
    
    pause(1000);

    cmpc(2);
    while (gmpc(2) < 865) 
    {
        mav(2, 100);
        mav(0, 60);
        mav(3, 60);
    }
    //lower the bottle device and go backwards ot grabe six bottles
    
    pause(500);
    set_servo_position(0, 1200);
    msleep(1000);
    //close side one
    
    set_servo_position(3,1200);
    msleep(1000);
    //close side two
    
   pause(500);
    
    cmpc(2);
    while (gmpc(2) > -725) 
    {
        mav(2, -100);
        mav(0, -110);
        mav(3, -110);
    }
    //raise the bottle device and go backwards
    
    pause(500);
    
    backsquare();
    //back up to square on center line of the board still infrotnt of where bottles were
    
    forward(1000, 1000, 800);
    //forward to move into position
    
    left(1510);
    //left to travel down kitchen floow

    forward(1000, 1000, 2000);
    left(1510);
    forward(1000, 1000, 850);
    //travel down kitchen floor and tunr to the drinks station to serve package
   
    pause(500);
    
    cmpc(2);
    while (gmpc(2) < 785) 
    {
        mav(2, 100);
        mav(0, -60);
        mav(3, -60);
    }
    //lower the six bottles and bakc up to play them in the serving station for drinks
    
    pause(500);
    
    set_servo_position(0, 545);
    msleep(1000);
    //release sid eone 
    set_servo_position(3,1950);
    msleep(1000);
    //release side two
    pause(500);
    
    cmpc(2);
    while (gmpc(2) > -730) 
    {
        mav(2, -100);
    }
    //rase bottle device
    
    pause(500);
    
    backsquare();
    //back up to line up on center ktichen floor line
    
    pause(500);
    
    left(1510);
    follow(3000);
    forward(1145,1145,1000);
    follow(3000);
    right(1510);
    //turn left dow onto the kitchen floor and then go forward to the tomato and turn righ tto face the fruit side
    
    backsquare();
    //back up on center kitchen line for accuracy
    
        pause(500);

    backward(1000, 1000, 900);
    //foirward to the tomat
    
        pause(500);

    ssp(500, 2,248);
    ssp(500, 1,397);
    //lower claw and grab tomato
    
     pause(500);
    
    //raise claw
    ssp(500,2,1000);
    
    //back up to center kitchen line and get close to trays
    forsquare();
    forward(1000, 1000, 2000);
    
    //turn araound (rotate to platter)
    left(3020);
    
    //forward to platter
    backward(1145, 1145, 200);
    
    pause(500);
    //lower and drop tomato
    ssp(500, 2,248);
    ssp(500, 1,1180);
    //lower claw and place tomato
    pause(500);

    
    disable_servos();
    
    ao();
    return 0;
}
