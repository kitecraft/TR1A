// Author is Kitecraft
// Purpose is TR1A robot code. 
// Location is https://github.com/kitecraft/TR1A
// Entertainment level is unknown at this time
// Possibility of igniting a global thermonuclear war is low (Just don't ask it to play tic-tac-toe).


#include <Sabertooth.h>
#include <Servo.h>


#define PING_PIN 7
#define SERVO_PIN 9

const int servoAngleMin = 11;
const int servoAngleMax = 165;
const int serverCenterAngle = 89;

Servo pingServo;
Sabertooth ST(128);

void setup()
{
	Serial.begin(57600);
    SabertoothTXPinSerial.begin(9600);


    pingServo.attach(SERVO_PIN);
    pingServo.write(serverCenterAngle);
    
    ST.setRamping(21);
    ST.drive(0);
    ST.turn(0);
}

void loop()
{
    Serial.print(Ping());
    Serial.println(" cm");


    delay(100);
}


int Ping()
{
    long duration;
    pinMode(PING_PIN, OUTPUT);
    digitalWrite(PING_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(PING_PIN, HIGH);
    delayMicroseconds(5);
    digitalWrite(PING_PIN, LOW);

    // The same pin is used to read the signal from the PING))): a HIGH pulse
    // whose duration is the time (in microseconds) from the sending of the ping
    // to the reception of its echo off of an object.
    pinMode(PING_PIN, INPUT);
    duration = pulseIn(PING_PIN, HIGH);

    return microsecondsToCentimeters(duration);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}