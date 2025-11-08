const int analogPin = A0; // Analog output from U1
const int digitalPin = 2; // Digital output from U2

void setup() {
    Serial.begin(9600); //initialize the serial monitor
    pinMode(digitalPin, INPUT); //pin 2 as input    
    Serial.println();
    Serial.println("=== LM358 IR SENSOR DASHBOARD ===");
    Serial.println("Move your hand closer/farther to see changes!");
    Serial.println("-----------------------------------");
}

void loop() {
    int analogValue = analogRead(analogPin); // 0–1023
    int digitalValue = digitalRead(digitalPin); // 0 or 1

    // Convert analog to a bar (0–20 blocks)
    int barLength = map(analogValue, 0, 1023, 0, 20);

    // Print analog bar
    Serial.print("IR Level: ");
    for (int i = 0; i < barLength; i++) Serial.print("#");
    for (int i = barLength; i < 20; i++) Serial.print("-");
    Serial.print(" (");
    Serial.print(analogValue);
    Serial.print(") | ");
    //if bar is 5 blocks IR Level: #####---------(5)|

    // Show comparator status
    if (digitalValue == HIGH) {
        Serial.println("⚡ Object Detected!");
    } else {
        Serial.println("No Object");
    }

    // Optional LED blink on comparator HIGH
    if (digitalValue == HIGH) {
        tone(8, 1000, 100); // short beep on pin 8 if buzzer is connected
    }

    delay(250); // refresh rate
}
