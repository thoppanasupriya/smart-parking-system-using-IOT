#include <ESP8266WiFi.h>
#include <Servo.h>

// WiFi credentials
const char* ssid = "santhosh";
const char* password = "@1211345";

// Servo motor pin
const int servoPin = D3; // You can change this pin according to your wiring

// Create a servo object
Servo parkingServo;

// Variables to track parking slot status
bool slot1Occupied = false;
bool slot2Occupied = false;
bool slot3Occupied = false;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize servo motor
  parkingServo.attach(servoPin);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your main code logic goes here
  // For demonstration purposes, let's assume slot 1 is occupied and the rest are free
  
  if (!slot1Occupied) {
    // If slot 1 is free, open it
    openParkingSlot(1);
    slot1Occupied = true;
  } else {
    // If slot 1 is occupied, close it
    closeParkingSlot(1);
    slot1Occupied = false;
  }
  
  // Delay for demonstration purposes
  delay(5000);
}

// Function to open a parking slot
void openParkingSlot(int slotNumber) {
  Serial.print("Opening Slot ");
  Serial.println(slotNumber);
  
  // Rotate servo to open the slot
  parkingServo.write(90); // Adjust the angle according to your setup
  delay(1000); // Adjust delay if needed
}

// Function to close a parking slot
void closeParkingSlot(int slotNumber) {
  Serial.print("Closing Slot ");
  Serial.println(slotNumber);
  
  // Rotate servo to close the slot
  parkingServo.write(0); // Adjust the angle according to your setup
  delay(1000); // Adjust delay if needed
}
