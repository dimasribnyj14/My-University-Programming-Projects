// Підключення необхідних бібліотек
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "DHT.h"
#include <ArduinoJson.h>

// Визначення пінів згідно з схемою
#define DHTPIN 10
#define DHTTYPE DHT22
// Обов’язкове вказання пінів I2C
#define I2C_SDA 8
#define I2C_SCL 9
// Додавання піна для червоного світлодіода
#define LED_PIN 2

// Створення об’єктів для роботи з датчиками
DHT dht(DHTPIN, DHTTYPE);
// Створення об’єкта для роботи з BMP085/180
Adafruit_BMP085 bmp;
// Функція старта, яка виконується 1 раз
void setup() {
    // Ініціалізація серійного порту для виводу даних
    Serial.begin(115200);   
    // Ініціалізація піна для світлодіода як вихідного
    pinMode(LED_PIN, OUTPUT); 
    // Ініціалізація шини I2C на власних пінах GPIO 8 (SDA) та GPIO 9 (SCL)
    Wire.begin(I2C_SDA, I2C_SCL);   
    // Ініціалізація DHT22
    dht.begin();
    // Ініціалізація BMP085/180 із передачею вказаної шини Wire
    if (!bmp.begin(0x77, &Wire)) {
        // Якщо датчик у Wokwi або в реальності має адресу 0x76, замініть 0x77 на 0x76
        Serial.println("Помилка: BMP180 не знайдено!");
    }
}
// Основний цикл функції, який працює нескінченно
void loop() {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    float press = bmp.readPressure() / 133.322F; // Переведення Па в мм рт. ст.
    bool alert = false;

    // Перевірка коректності зчитування з DHT22
    if (isnan(temp) || isnan(hum)) {
        Serial.println("Помилка зчитування з DHT22!");
        delay(2000);
        return;
    }

    // Перевірка коректності зчитування з BMP180
    if (isnan(press)) {
        Serial.println("Помилка зчитування з BMP180!");
        delay(2000);
        return;
    }

    // Умова для увімкнення світлодіода при тиску більше 770 мм рт. ст.
    if (press > 770.0) { 
      digitalWrite(LED_PIN, HIGH); // Увімкнути світлодіод
      alert = true;
    } else {
      digitalWrite(LED_PIN, LOW);  // Вимкнути світлодіод
    }

    // Формування JSON (використовується JsonDocument для сумісності з ArduinoJson v7)
    JsonDocument doc;
    doc["device_id"] = "ESP32_S3_001";
    doc["temperature"] = temp;
    doc["humidity"] = hum;
    doc["pressure"] = press;
    doc["alert"] = alert;

    // Вивід JSON у Serial (готовність для відправки через MQTT / HTTP до PostgreSQL)
    serializeJson(doc, Serial);
    Serial.println();
    delay(3000);
} 