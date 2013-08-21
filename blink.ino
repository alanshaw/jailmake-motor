// Pins
int UP_PIN = 9;
int DN_PIN = 8;
int TOP_SWITCH_PIN = 12;
int BOTTOM_SWITCH_PIN = 13;

// Directions
int DIR_DN = 0;
int DIR_UP = 1;

// Switches
int SWITCH_BOTTOM = 0;
int SWITCH_TOP = 1;

int DELAY = 6000;

// State
int dir = DIR_UP; // The current direction
int lastSwitch = SWITCH_BOTTOM; // Last switch that was pressed

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  
  pinMode(UP_PIN, OUTPUT);
  pinMode(DN_PIN, OUTPUT);
  pinMode(TOP_SWITCH_PIN, INPUT);
  pinMode(BOTTOM_SWITCH_PIN, INPUT);
  
  dir = DIR_UP;
  lastSwitch = SWITCH_BOTTOM;
  
  Serial.print("Setup complete\n");
}

void loop() {
  int top = digitalRead(TOP_SWITCH_PIN);
  int bottom = digitalRead(BOTTOM_SWITCH_PIN);
  
  if (top == 0 && lastSwitch == SWITCH_BOTTOM) {
    Serial.print("DIR changed to DN\n");
    digitalWrite(UP_PIN, LOW);
    dir = DIR_DN;
    lastSwitch = SWITCH_TOP;
    delay(DELAY);
    return;
  } else if (bottom == 0 && lastSwitch == SWITCH_TOP) {
    Serial.print("DIR changed to UP\n");
    digitalWrite(DN_PIN, LOW);
    dir = DIR_UP;
    lastSwitch = SWITCH_BOTTOM;
    delay(DELAY);
    return;
  }
  
  if (dir == DIR_UP) {
    digitalWrite(UP_PIN, HIGH);
  } else {
    digitalWrite(DN_PIN, HIGH);
  }
}
