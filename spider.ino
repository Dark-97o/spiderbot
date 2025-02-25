#include <Servo.h>
#include <SoftwareSerial.h>

// Bluetooth module connected to RX 10 and TX 11
SoftwareSerial BT(10, 11);

// Servos for the legs (3 servos per leg, 12 total)
Servo leg1_hip, leg1_knee, leg1_ankle;
Servo leg2_hip, leg2_knee, leg2_ankle;
Servo leg3_hip, leg3_knee, leg3_ankle;
Servo leg4_hip, leg4_knee, leg4_ankle;

// Servo for the camera direction
Servo camera_servo;

void setup() {
    Serial.begin(9600);
    BT.begin(9600);
    
    // Attach servos to appropriate PWM pins
    leg1_hip.attach(2); leg1_knee.attach(3); leg1_ankle.attach(4);
    leg2_hip.attach(5); leg2_knee.attach(6); leg2_ankle.attach(7);
    leg3_hip.attach(8); leg3_knee.attach(9); leg3_ankle.attach(10);
    leg4_hip.attach(11); leg4_knee.attach(12); leg4_ankle.attach(13);
    camera_servo.attach(A0);
    
    // Set initial positions
    setNeutralPosition();
}

void loop() {
    if (BT.available()) {
        char command = BT.read();
        Serial.println(command);
        executeCommand(command);
    }
}

void setNeutralPosition() {
    // Set all servos to neutral position (adjust as needed)
    leg1_hip.write(90); leg1_knee.write(90); leg1_ankle.write(90);
    leg2_hip.write(90); leg2_knee.write(90); leg2_ankle.write(90);
    leg3_hip.write(90); leg3_knee.write(90); leg3_ankle.write(90);
    leg4_hip.write(90); leg4_knee.write(90); leg4_ankle.write(90);
    camera_servo.write(90);
}

void executeCommand(char command) {
    switch (command) {
        case 'F': moveForward(); break;
        case 'B': moveBackward(); break;
        case 'L': turnLeft(); break;
        case 'R': turnRight(); break;
        case 'C': lookAround(); break;
        case 'S': setNeutralPosition(); break;
        case 'U': camera_servo.write(45); break;
        case 'D': camera_servo.write(135); break;
        case 'N': camera_servo.write(90); break;
        default: break;
    }
}

void moveForward() {
    leg1_hip.write(120); leg2_hip.write(60);
    leg3_hip.write(120); leg4_hip.write(60);
    delay(500);
    setNeutralPosition();
}

void moveBackward() {
    leg1_hip.write(60); leg2_hip.write(120);
    leg3_hip.write(60); leg4_hip.write(120);
    delay(500);
    setNeutralPosition();
}

void turnLeft() {
    leg1_hip.write(120); leg3_hip.write(120);
    delay(500);
    setNeutralPosition();
}

void turnRight() {
    leg2_hip.write(60); leg4_hip.write(60);
    delay(500);
    setNeutralPosition();
}

void lookAround() {
    // This function is now controlled by user commands (U, D, N for Up, Down, Neutral)
}
