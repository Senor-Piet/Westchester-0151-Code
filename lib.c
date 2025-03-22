#include <kipr/wombat.h>
#include "lib.h"

void forward (int ltps, int rtps, int distance)
{ 
    cmpc(0);
    while (gmpc(0) < distance) 
    {
        mav(0, rtps);
        mav(3, ltps);
    }

}

void backward (int ltps, int rtps, int distance)
{ 
    cmpc(0);
    while (gmpc(0) > -distance) 
    {
        mav(0, -rtps);
        mav(3, -ltps);
    }

}

void pright (int distance)
{
    cmpc(0);
    while (gmpc(0) < distance) 
    {
        mav(0, 500);
        mav(3, 0);
    }
}

void pleft (int distance)
{
    cmpc(3);
    while (gmpc(3) < distance) 
    {
        mav(0, 0);
        mav(3, 500);
    }
}

void right (int distance)
{
    cmpc(0);
    while (gmpc(0) < distance) 
    {
        mav(0, 500);
        mav(3, -500);
    }
}

void left (int distance)
{
    cmpc(3);
    while (gmpc(3) < distance) 
    {
        mav(0, -500);
        mav(3, 500);
    }
}

void pause(int time)
{
    mav(0,0);
    mav(3,0);
    msleep(time);
    ao();
}

void slowservo(int startposition, int servonumber, int counterposition, int counterspeed)
{
    int counter = startposition;
    set_servo_position(servonumber, counter);
    enable_servos();
    while(counter < counterposition)
    {
        msleep(100);
        counter = counter + counterspeed;
        set_servo_position(servonumber, counter);
    }
    msleep(100);
    disable_servos();
}

void servototop()
{
    int target_pos = 2000;
    int curr_pos = get_servo_position(0);
    int pos_diff = target_pos - curr_pos;
    /* 50 iterations * 100 ms / iteration = 5 seconds */
    int iters = 50;
    int interval = pos_diff / iters;
    for ( ; curr_pos < target_pos; curr_pos += interval) {
        set_servo_position(0, curr_pos);
        msleep(100);
    }
}

void ssp(int time, int port, int position)
{
    set_servo_position(port, position);
    msleep(time);
}

//square up on the black line - going forward
void forsquare ()
{
    while ((analog(3) < 900) || (analog(5) < 900))
    {
        if ((analog(3) > 900) && (analog(5) < 900))
        {
            motor(0,0);
            motor(3,30);
        }
        else if ((analog(3) < 900) && (analog(5) > 900))
        {
            motor(0,30);
            motor(3,0);
        }
        else
        {
            motor(0,100);
            motor(3,79);
        }
    }
    ao();
    msleep(200);
}

//square up on the black line - going forward
void backsquare ()
{
    while ((analog(3) < 900) || (analog(5) < 900))
    {
        if ((analog(3) > 900) && (analog(5) < 900))
        {
            motor(0,0);
            motor(3,-30);
        }
        else if ((analog(3) < 900) && (analog(5) > 900))
        {
            motor(0,-30);
            motor(3,0);
        }
        else
        {
            motor(0,-100);
            motor(3,-79);
        }
    }
    ao();
    msleep(200);
}

void follow(int distance)
{
    int counter = 0;
    while (counter < distance)
    {
        if (analog(3) > 1000)
        {
            motor(0, 15);
            motor(3, 150);
            counter += 1;
        }
        else
        {
            motor(0, 150);
            motor(3, 15);
            counter += 1;
        }
    }
}

void bfollow(int distance)
{
    int counter = 0;
    while (counter > -distance)
    {
        if (analog(3) > 1000)
        {
            motor(0, -15);
            motor(3, -150);
            counter += 1;
        }
        else
        {
            motor(0, -150);
            motor(3, -15);
            counter += 1;
        }
    }
}

void wfl(int port)
{
    wait_for_light(port);
}

void sdi(int time)
{
    shut_down_in(time);
}
