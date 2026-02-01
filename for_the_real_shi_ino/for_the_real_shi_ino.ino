/*
 * Arduino Serial Keyboard Emulator - Optimized for Speed
 * Fast polling, minimal delays
 */

bool button2_last = HIGH;
bool button3_last = HIGH;
bool button2_hold_sent = false;
bool button3_hold_sent = false;
unsigned long button2_press_time = 0;
unsigned long button3_press_time = 0;

const int HOLD_THRESHOLD = 50; // Reduced for faster hold detection

void setup() {
  Serial.begin(115200);  // Faster baud rate 
  pinMode(2, INPUT_PULLUP);  // Button for 'a' key
  pinMode(3, INPUT_PULLUP);  // Button for 's' key
  
  delay(1000);
  Serial.println("Arduino Serial Keyboard Ready");
}

void loop() {
  bool button2_current = digitalRead(2);
  bool button3_current = digitalRead(3);
  
  // Handle button 2 (a key)
  if (button2_current == LOW && button2_last == HIGH) {
    Serial.println("PRESS:a"); // on the press:a. you can rebind it
    button2_press_time = millis();
    button2_hold_sent = false;
  }
  else if (button2_current == LOW && !button2_hold_sent) {
    if (millis() - button2_press_time > HOLD_THRESHOLD) {
      Serial.println("HOLD:a"); // also this will be changed to you bind you like
      button2_hold_sent = true;
    }
  }
  else if (button2_current == HIGH && button2_last == LOW) {
    Serial.println("RELEASE:a"); // this also
  }
  
  // Handle button 3 (s key)
  if (button3_current == LOW && button3_last == HIGH) {
    Serial.println("PRESS:s"); // and this one will be like the one at the top but i mean the process
    button3_press_time = millis();
    button3_hold_sent = false;
  }
  else if (button3_current == LOW && !button3_hold_sent) {
    if (millis() - button3_press_time > HOLD_THRESHOLD) {
      Serial.println("HOLD:s");
      button3_hold_sent = true;
    }
  }
  else if (button3_current == HIGH && button3_last == LOW) {
    Serial.println("RELEASE:s");
  }
  
  button2_last = button2_current;
  button3_last = button3_current;
  
  // No delay for maximum speed!
}