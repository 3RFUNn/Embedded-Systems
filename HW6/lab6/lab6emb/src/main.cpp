#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>


// Tasks Signature
void TaskFan(void *pvParameters);
void TaskDrive(void *pvParameters);
void TaskSenseGas(void *pvParameters);
void TaskDistance(void *pvParameters);

// sensor functions
int senseGas();
long getDistance();

// motor function
void moveMotor(int EN, int IN1, int IN2, int isForward, int isStop, int speed);

// helper funcs
bool safeCond();
void giveInteruptToMotors();


// Ports
const int EN_DRIVE = 10;
const int IN1_DRIVE = 8;
const int IN2_DRIVE = 9;
const int EN_FAN = 11;
const int IN1_FAN = 12;
const int IN2_FAN = 13;
const int ULTRASONIC_TRIGGER = 7;
const int ULTRASONIC_ECHO = 6;
const int GAS_INPUT = 0;


int maxMotorSpeed = 255;
int gasValue;
long distance;

// semaphores
SemaphoreHandle_t fanSema;
SemaphoreHandle_t driveSema;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  while (!Serial) {
    // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

  // Wire ports
  pinMode(EN_DRIVE, OUTPUT);
  pinMode(IN1_DRIVE, OUTPUT);
  pinMode(IN2_DRIVE, OUTPUT);
  pinMode(EN_FAN, OUTPUT);
  pinMode(IN1_FAN, OUTPUT);
  pinMode(IN2_FAN, OUTPUT);
  pinMode(ULTRASONIC_TRIGGER, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);
  pinMode(GAS_INPUT, INPUT);

  // setup semaphores
  fanSema = xSemaphoreCreateBinary();
  driveSema = xSemaphoreCreateBinary();

  giveInteruptToMotors();

  // Initial values
  gasValue = senseGas();
  distance = getDistance();  

  // Making the tasks
  xTaskCreate(TaskFan, "Fan", 128, NULL, 3, NULL);
  xTaskCreate(TaskDrive, "Drive", 128, NULL, 3, NULL);
  xTaskCreate(TaskSenseGas, "Gas", 128, NULL, 2, NULL);
  xTaskCreate(TaskDistance, "Distance", 128, NULL, 2, NULL);
}

void loop() {
  // it is task driven, hence here's empty
}

void TaskFan(void *pvParameters) {
  while(1) {
    if (xSemaphoreTake(fanSema, portMAX_DELAY) == pdPASS) {
      // Convert gas (0, 512) value to speed (0, 255)
      int motorSpeed = (gasValue * 255.0) / 512.0;
      // stop moving if not sfae otherwise move
      moveMotor(EN_FAN, IN1_FAN, IN2_FAN, true, !safeCond(), motorSpeed);
      taskYIELD();
    }
  }
}

void TaskDrive(void *pvParameters) {
  while (1) {
    if (xSemaphoreTake(driveSema, portMAX_DELAY) == pdPASS) {
      // move backwards if not safe
      moveMotor(EN_DRIVE, IN1_DRIVE, IN2_DRIVE, safeCond(), 0, maxMotorSpeed);
      taskYIELD();
    }
  }
}

void TaskSenseGas(void *pvParameters) {
  while (1) {
    bool lastState = safeCond();
    int lastGasDensity = gasValue;
    gasValue = senseGas();    
    if ((safeCond() != lastState) || (gasValue != lastGasDensity)) {
      giveInteruptToMotors();
    }
    taskYIELD();
  }
}

void TaskDistance(void *pvParameters) {
  while (1) {
    bool lastState = safeCond();
    distance = getDistance();    
    if (safeCond() != lastState) {
        giveInteruptToMotors();
    }
    taskYIELD();
  }
}

void giveInteruptToMotors() {
  xSemaphoreGive(fanSema);
  xSemaphoreGive(driveSema);
}

bool safeCond() {
  return (gasValue <= 512) && (distance >= 100);
}

int senseGas() {
  int gasDensity = analogRead(GAS_INPUT);
  return gasDensity;
}

long getDistance() {
  digitalWrite(ULTRASONIC_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIGGER, LOW);
  long duration = pulseIn(ULTRASONIC_ECHO, HIGH);
  long distanceSensorValue = duration * 0.0344 / 2;
  return distanceSensorValue;
}

void moveMotor(int EN, int IN1, int IN2, int isForward, int isStop, int speed) {
  analogWrite(EN, speed);
  if (isStop == 1)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
  else if (isForward == 1)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  else
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
}

