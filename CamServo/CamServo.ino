#include <Servo.h> //подключаем библиотеку для работы с сервоприводом
Servo CamServo;
int switchPin = 7;
int servoPin = 9;
int ledPin = 13;

// переменные posClose и  posOpen указывают в какую позицию должен повернуться сервопривод
// максимальный угол поворота сервопривода - 180 градусов

int posClose = 0;
int posOpen = 150;

void setup()
{
    pinMode(switchPin, INPUT); // определяем порт switchPin как входящий
    pinMode(ledPin, OUTPUT);   // определяем порт ledPin как исходящий
    CamServo.attach(servoPin); // определяем порт servoPin как управляющий сервоприводом
}

void loop()
{
    if (digitalRead(switchPin) == HIGH) // если на порт switchPin подается напряжение - логическая 1
    {
        digitalWrite(ledPin, HIGH); // включаем светодиод
        delay(500);
        CamServo.write(posOpen);
    }
    else // иначе
    {
        digitalWrite(ledPin, LOW); // отключаем светодиод
        delay(500);
        CamServo.write(posClose);
    }
}
