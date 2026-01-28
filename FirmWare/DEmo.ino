#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo scoopServo;
Servo latchServo;

// Servo pins
#define SCOOP_PIN  14   // D5
#define LATCH_PIN  12   // D6

// Latch positions
#define LATCH_LOCK_POS   0
#define LATCH_UNLOCK_POS 90

// Pill dispense time (24hr format)
int pillHour = 21;   // 2 PM
int pillMinute =23; // 35 minutes

// Scoop position
int scoopAngle = 60;

// To prevent multiple triggers in the same minute
bool alreadyDispensed = false;

void setup() {
  Serial.begin(9600);

  // Init LCD
  lcd.init();
  lcd.backlight();

  // Init RTC
  if (!rtc.begin()) {
    lcd.print("RTC not found!");
    while (1);
  }
  if (rtc.lostPower()) {
    lcd.clear();
    lcd.print("RTC lost power");
    // Set to compile time
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Attach servos
  scoopServo.attach(SCOOP_PIN);
  latchServo.attach(LATCH_PIN);
  latchServo.write(LATCH_LOCK_POS);

  lcd.clear();
  lcd.print("Smart Pill Ready");
  delay(2000);
}

void loop() {
  DateTime now = rtc.now();

  // Display time
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(now.hour() < 10 ? "0" : ""); lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute() < 10 ? "0" : ""); lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second() < 10 ? "0" : ""); lcd.print(now.second());

  lcd.setCursor(0, 1);
  lcd.print("Next: ");
  lcd.print(pillHour); lcd.print(":");
  if (pillMinute < 10) lcd.print("0");
  lcd.print(pillMinute);

  // Check if time matches
  if (now.hour() == pillHour && now.minute() == pillMinute) {
    if (!alreadyDispensed) {
      dispensePill();
      alreadyDispensed = true;
    }
  } else {
    alreadyDispensed = false; // Reset trigger when time moves away
  }

  delay(1000);
}

void dispensePill() {
  Serial.println("Dispensing pill...");

  // Move scoop
  scoopServo.write(scoopAngle);
  delay(1000);

  // Open latch
  latchServo.write(LATCH_UNLOCK_POS);
  delay(2000);

  // Close latch
  latchServo.write(LATCH_LOCK_POS);
}
