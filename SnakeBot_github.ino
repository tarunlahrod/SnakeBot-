

/*
 *hey there, this is a code for the working functionality of a SERVO-CONTROLLED SnakeBot.
 *The code is made on Arduino Mega 2560. 
 *
 *The SnakeBot consists of 11 servo motors connected in a trail and 
 *perpendicular to each other. (pictures of the bot has been provided
 *in the link given in PICTURES.TXT).
 *
 *SnakeBot is powered by a LiPo battery (2200mAh).
 */


#include<Servo.h>     //including Servo.h library to use Servo functions
 
 Servo s[11];  //Declaring 11 objects of Servo, a Servo array.

void setup()
{
  
}

//************************************************//
//                 mov function                   //
//    (to give any servo a particular angle)      //
//************************************************//


// this function takes "servo index number", "angle" and "delay" as input parameter.

 void mov(int i,int angle,int del) 
 {
  if(i==0||i==3)               //my SnakeBot had a problem, two of its servo motors were connected 
    angle = 180 - angle;       //in opposite pattern. You can eliminate this if statement.
    
   s[i].attach(i+2);          //attaching the s[i]th servo to the (i+2)th pin on the arduino board.
   s[i].write(angle);         //giving s[i]th servo the input "angle"
   delay(del);              
   s[i].detach();             //detaching the s[i]th servo.
 }

 // Declaring a function "straight()" to straighten the SnakeBot (all angles 90 degree each).
 
void straight()
{
  for(int i=0;i<=10;i++)
  mov(i,90,500); 
}


//given function "loop()", calling "mov()" function again and again to perform the locomotion.
 
void loop() 
{
    straight();
    
    mov(1,150,1000);
    mov(3,30,500);
    mov(5,150,1000);
    mov(7,30,500);
    mov(9,150,1000);
    mov(10,0,1000); 
    mov(10,20,500);
    mov(10,40,200);
    mov(10,90,500);

} // end of loop.

/*
 * for any query, you can contact me at lahrod.tarun46@gmail.com 
 */

