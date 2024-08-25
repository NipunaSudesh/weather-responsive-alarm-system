Q)03

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define pins for sensors and buzzer
const int ldrPin = A0; // Analog pin for LDR
const int rainPin = 2; // Digital pin for raindrop sensor
const int buzzerPin = 3; // Digital pin for buzzer

// Create an LCD object with I2C address 0x27 (adjust to your LCD's specifications)
LiquidCrystal_I2C lcd(0x27, 20, 4); 

// Define thresholds
const int lightThreshold = 500; // LDR value threshold to determine light or dark

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize the LCD
  lcd.init(); // Initialize the LCD with the lcd.begin() method from the successful example
  lcd.backlight(); // Turn on the backlight
  
  // Set pin modes
  pinMode(rainPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Print welcome message
  lcd.setCursor(0, 0);
  lcd.print("Weather System");
  delay(2000);
}

void loop() {
  // Read the LDR value
  int ldrValue = analogRead(ldrPin);
  
  // Read the raindrop sensor value
  int rainValue = digitalRead(rainPin);
  
  // Determine light status
  String lightStatus = (ldrValue < lightThreshold) ? "Light" : "Dark";
  
  // Determine rain status
  String rainStatus = (rainValue == HIGH) ? "Dry" : "Rain";
  
  // Display status on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Intensity: ");
  lcd.print(lightStatus);
  
  lcd.setCursor(0, 1);
  lcd.print("Cli: ");
  lcd.print(rainStatus);
  
  // Sound the alarm if it is dark, raining, or both
  if (lightStatus == "Dark" || rainStatus == "Rain") {
    // Activate the buzzer with a pulsing effect
    tone(buzzerPin, 1000); // Generate a 1kHz tone
    delay(500); // Buzzer on for 500ms
    noTone(buzzerPin); // Stop the tone
    delay(500); // Buzzer off for 500ms
  }
  else if (lightStatus == "Dark"){
        tone(buzzerPin, 1000); // Generate a 1kHz tone
    delay(500); // Buzzer on for 500ms
    noTone(buzzerPin); // Stop the tone
    delay(500); // Buzzer off for 500ms
  }
    else if (lightStatus == "Rain"){
        tone(buzzerPin, 1000); // Generate a 1kHz tone
    delay(500); // Buzzer on for 500ms
    noTone(buzzerPin); // Stop the tone
    delay(500); // Buzzer off for 500ms
  }
  else {
    noTone(buzzerPin); // Ensure the buzzer is off when not triggered
  }
  
  // Print to Serial Monitor for debugging
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" - Light Status: ");
  Serial.println(lightStatus);
  Serial.print("Rain Status: ");
  Serial.println(rainStatus);
  
  // Delay before next reading
  delay(1000);
}
