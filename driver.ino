#include <Servo.h>
#include "buildProject.h"


//All motor pins will be digital until we figure out how to use analog outputs
void moveForward() {
	digitalWrite(LEFT,HIGH);
	digitalWrite(RIGHT,HIGH);
	//analogWrite(LEFT,255);
	//analogWrite(RIGHT,255);
}

void turnLeft() {
	digitalWrite(RIGHT,HIGH);
	//analogWrite(RIGHT,255);
}

void turnRight() {
  digitalWrite(LEFT,HIGH);
	//analogWrite(LEFT,255);
}

//Flag waving will have one speed but we can vary it to match robot speed.
void waveFlag() {
	digitalWrite(FLAG,HIGH);
	//analogWrite(FLAG, 255);
}

void stopFlag() {
	digitalWrite(FLAG,LOW);
	//analogWrite(FLAG, 0);
}

void stop() {
	digitalWrite(LEFT,LOW);
	digitalWrite(RIGHT,LOW);
	//If we decide to switch to analog
	//analogWrite(LEFT, 0);
	//analogWrite(RIGHT, 0);
}

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	// set up pins to be output
	pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
	pinMode(FLAG, OUTPUT);
}

void loop() {
	// put your main code here, to run repeatedly:
	if(Serial.available() > 0){
		//Serial.read() will be the input from the bluetooth
		int received = Serial.read();

		switch(received){
			case MOVE_FORWARD:
				moveForward();
				break;
			case MOVE_BACKWARD:
				moveBackward();
				break;
			case MOVE_RIGHT:
				turnRight();
				break;
			case MOVE_LEFT:
				turnLeft();
				break;
			case MOVE_STOP:
				stop();
				break;
		}
	}
}
