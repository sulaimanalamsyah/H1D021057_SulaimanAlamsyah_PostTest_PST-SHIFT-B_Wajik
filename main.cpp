//Inisialisasi Library Servo dan LiquidCrystal_I2C diinisialisasi untuk mengontrol servo dan LCD.
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD dengan alamat I2C 0x27, dan ukuran 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Inisialisasi servo
Servo myservo;
int servoPin = 9;

//Pada fungsi setup(), servo disambungkan ke pin yang ditentukan dan LCD diinisialisasi.
void setup() {
  // Mengatur pin servo
  myservo.attach(servoPin);
  // Mengatur LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  // Menggerakkan servo dari 0 hingga 180 derajat
  for (int pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15); // Menunggu servo bergerak
    //Selama pergerakan servo, fungsi scrollMessage dipanggil untuk menampilkan pesan bergerak di LCD.
    scrollMessage("Servo Bergerak!");
  }
  
  // Menggerakkan servo kembali dari 180 hingga 0 derajat
  for (int pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15); // Menunggu servo bergerak
    //Selama pergerakan servo, fungsi scrollMessage dipanggil untuk menampilkan pesan bergerak di LCD.
    scrollMessage("Servo Bergerak!");
  }

  // Mematikan servo dan LCD setelah gerakan selesai
  myservo.detach();
  lcd.noBacklight();
  delay(5000); // Menunggu 5 detik sebelum mengulangi
  lcd.backlight();
  myservo.attach(servoPin);
}

// Fungsi untuk menampilkan pesan bergerak pada LCD
void scrollMessage(String message) {
  static int scrollPos = 0;
  lcd.clear();
  lcd.setCursor(scrollPos, 1);
  lcd.print(message);
  scrollPos++;
  if (scrollPos > 16) {
    scrollPos = 0;
  }
}
