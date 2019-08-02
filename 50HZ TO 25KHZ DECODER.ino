/*   This is the code for controlling any R/C car with an airplane transmitter written by Vishnu Chaitanya Karpuram & MR KAMRUZZAMAN PRESDENT IUBAT ROBOTICS CLUB   */
int motor1Left = 5;// defines pin 5 as connected to the motor
int motor1Right= 6;// defines pin 6 as connected to the motor
int motor2Left = 7;// defines pin 7 as connected to the motor
int motor2Right = 8;// defines pin 8 as connected to the motor

int channel1 = 9; // defines the channels that are connected
int channel2 = 10;// to pins 9 and 10 of arduino respectively

int Channel1 ; // Used later to 
int Channel2 ; // store values

void  setup ()
{
   pinMode (motor1Left, OUTPUT);// initialises the motor pins
   pinMode (motor1Right, OUTPUT);
   pinMode (motor2Left, OUTPUT);
   pinMode (motor2Right, OUTPUT);// as outputs
   pinMode (channel1, INPUT);// initialises the channels
   pinMode (channel2, INPUT);// as inputs
   Serial.begin (9600); // Sets the baud rate to 9600 bps
}

void  loop ()
{
  Channel1 = (pulseIn (channel1, HIGH)); // Checks the value of channel1
  Serial.println (Channel1); //Prints the channels value on the serial monitor
  
  Channel2 = (pulseIn (channel2, HIGH)); // Checks the value of channel1
  Serial.println (Channel2); //Prints the channels value value on the serial monitor
 
  if (Channel1 > 1300 && Channel1 < 1500 && Channel2 > 1300 && Channel2 < 1500 ) /*If these conditions are true, do the following. These are the values that I got from my transmitter, which you may customize according to your transmitter values */
  {
    idle();
  Serial.println ("idle");
  }
 
  if (Channel1 < 1300 && Channel2 > 1300 && Channel2 < 1500 ) // Checks if Channel1 is lesser than 1300
  {
    backward();
  Serial.println ("backward");
  }
  if (Channel1 > 1500 && Channel2 > 1300 && Channel2< 1500) // Checks if Channel1 is greater than 1500
  {
    forward();
  Serial.println ("forward");
  }
 

 
  if (Channel2 < 1300 && Channel1 > 1300 && Channel1 < 1500) // Checks if Channel2 is lesser than 1300
  {
    right();
  Serial.println ("right");
  }
  if (Channel2 > 1500 && Channel1 > 1300 && Channel1 < 1500) // Checks if Channel2 is greater than 1500
  {
    left();
  Serial.println ("left");
  }
  }
void forward() {
  digitalWrite(motor1Left,HIGH);
  digitalWrite(motor1Right,LOW);
  digitalWrite(motor2Left,HIGH);
  digitalWrite(motor2Right,LOW);
}
void backward() {
  digitalWrite(motor1Left,LOW);
  digitalWrite(motor1Right,HIGH);
  digitalWrite(motor2Left,LOW);
  digitalWrite(motor2Right,HIGH);
}
void left() {
  digitalWrite(motor1Left,LOW);
  digitalWrite(motor1Right,HIGH);
  digitalWrite(motor2Left,HIGH);
  digitalWrite(motor2Right,LOW);
}
void right() {
  digitalWrite(motor1Left,HIGH);
  digitalWrite(motor1Right,LOW);
  digitalWrite(motor2Left,LOW);
  digitalWrite(motor2Right,HIGH);
}
void idle() {
  digitalWrite(motor1Left,LOW);
  digitalWrite(motor1Right,LOW);
  digitalWrite(motor2Left,LOW);
  digitalWrite(motor2Right,LOW);
}
