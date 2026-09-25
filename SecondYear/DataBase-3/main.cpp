// Підключення необхідних бібліотек
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "DHT.h"
#include <ArduinoJson.h>
// Налаштування віртуальної мережі Wokwi
const char* ssid = "Wokwi-GUEST"; // Ім’я мережі
const char* password = ""; // Пароль (порожній для Wokwi-GUEST)
// Налаштування MQTT-брокера
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
// Визначення топіка для публікації даних (залежить від варіанту)
const char* mqtt_topic = "ntudp/bdksa/sribnyi_dmytro/petro_pipe/line_press";
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
// Створення об’єкта для роботи з BMP 085
Adafruit_BMP085 bmp;
// Створення об’єкта для роботи з MQTT
WiFiClient espClient; // WiFi-клієнт для підключення до MQTT-брокера
PubSubClient client(espClient); // MQTT-клієнт для публікації даних
// Змінна для відстеження часу останньої публікації
unsigned long lastMsg = 0;

// Функція для підключення до Wi-Fi
void setup_wifi() {
    delay(10);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password); 
    // Якщо підключення немає, виводимо крапки кожні 0,5 секунди до підключення
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected. IP address: ");
    Serial.println(WiFi.localIP()); // Виведення IP-адреси
}

// Функція для перепідключення до MQTT-брокера
void reconnect() {
    // Коли клієнт не підключений, намагаємося підключитися
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        // Створення унікального ID клієнта
        String clientId = "ESP32Client-";
        clientId += String(random(0xffff), HEX); // random(0xffff) генерує випадкове число
        // c_str() перетворює String на const char* для підключення
        if (client.connect(clientId.c_str())) {
            Serial.println("connected");
        } else {
            // Якщо підключення не вдалося, виводимо код помилки
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

// Функція старта, яка виконується 1 раз
void setup() {
    // Ініціалізація серійного порту для виводу даних
    Serial.begin(115200);
    // Ініціалізація піна для світлодіода як вихідного
    pinMode(LED_PIN, OUTPUT); 
    // Підключення до Wi-Fi та налаштування MQTT
    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
    // Ініціалізація шини I2C на власних пінах GPIO 8 (SDA) та GPIO 9 (SCL)
    Wire.begin(I2C_SDA, I2C_SCL);
    // Ініціалізація DHT22
    dht.begin();
    // Ініціалізація BMP085 із передачею вказаної шини Wire
    if (!bmp.begin(0x77, &Wire)) {
        Serial.println("Error: BMP085 hasn't been found!");
    }
}
// Основний цикл функції, який працює нескінченно
void loop() {
    // Якщо клієнт не підключений, підключаємо
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    // Отримання поточного часу в мілісекундах
    unsigned long now = millis();
    if (now - lastMsg > 5000) { // Передавати дані кожні 5 секунд
        lastMsg = now;
        float temp = dht.readTemperature();
        float hum = dht.readHumidity();
        float press = bmp.readPressure() / 133.322F; // мм рт. ст.
        bool hazard_alert = false;
        // Перевірка коректності зчитування з DHT22
        if (isnan(temp) || isnan(hum)) {
            Serial.println("Failed to read from DHT sensor!");
            delay(2000);
            return;
        }
        // Умова для увімкнення світлодіода при тиску більше 770 мм рт. ст.
        if (press > 770.0) { 
            digitalWrite(LED_PIN, HIGH); // Увімкнути світлodіод
            hazard_alert = true;
        } else {
            digitalWrite(LED_PIN, LOW);  // Вимкнути світлодіод
        }
        // Генерація значення ESG у діапазоні [1.2, 1.3)
        float esg_val = 1.2f + (random(0, 100) / 1000.0f);
        // Формування JSON (використовується JsonDocument для сумісності з ArduinoJson v7)
        JsonDocument doc;
        doc["asset_id"] = 1; // Ідентифікатор активу
        doc["device"] = "ESP32_S3_001"; // Ідентифікатор пристрою
        doc["data"]["temperature"] = temp; // Температура
        doc["data"]["humidity"] = hum; // Вологість
        doc["data"]["pressure"] = press; // Тиск
        doc["data"]["esg_val"] = esg_val; // Значення ESG
        doc["data"]["hazard_alert"] = hazard_alert; // Аварійна тривога
        char buffer[256]; // Буфер для серіалізації JSON
        serializeJson(doc, buffer); // Серіалізація JSON у буфер для публікації
        // Публікація в MQTT
        Serial.print("Publishing message: ");
        Serial.println(buffer);
        client.publish(mqtt_topic, buffer);
    }
} 
