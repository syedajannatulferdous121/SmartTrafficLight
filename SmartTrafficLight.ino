// Define pin numbers for traffic light signals and sensors
const int redPin = 2;
const int yellowPin = 3;
const int greenPin = 4;
const int pedestrianSensorPin = 5;

// Define traffic light timings (in milliseconds)
const int greenTime = 5000; // 5 seconds
const int yellowTime = 2000; // 2 seconds
const int redTime = 5000; // 5 seconds
const int pedestrianSignalTime = 5000; // 5 seconds

// Variables to track the traffic light state
enum TrafficLightState { GREEN, YELLOW, RED };
TrafficLightState trafficLightState = GREEN;

void setup() {
  // Initialize traffic light pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Initialize pedestrian sensor pin as INPUT
  pinMode(pedestrianSensorPin, INPUT);
}

void loop() {
  switch (trafficLightState) {
    case GREEN:
      // Green signal
      digitalWrite(greenPin, HIGH);
      delay(greenTime);

      // Transition to yellow
      trafficLightState = YELLOW;
      break;

    case YELLOW:
      // Yellow signal
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      delay(yellowTime);

      // Check for pedestrian signal request
      if (digitalRead(pedestrianSensorPin) == HIGH) {
        // Transition to pedestrian signal
        trafficLightState = RED;
        break;
      }

      // Transition to red
      trafficLightState = RED;
      break;

    case RED:
      // Red signal
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);
      delay(redTime);

      // Check for pedestrian signal request
      if (digitalRead(pedestrianSensorPin) == HIGH) {
        // Activate pedestrian signal
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, HIGH);
        delay(pedestrianSignalTime);
        digitalWrite(yellowPin, LOW);
        digitalWrite(redPin, HIGH);
      }

      // Transition to green
      trafficLightState = GREEN;
      break;
  }
}
