// C++ code
int dist = 0;
long ultrasonic_read(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return 0.01723 * pulseIn(echoPin, HIGH);
}
void LED_control(bool LED_1, bool LED_2, bool LED_3, bool LED_4)
{
  digitalWrite(2, LED_1);
  digitalWrite(3, LED_2);
  digitalWrite(4, LED_3);
  digitalWrite(5, LED_4);
}
void output(int dist, bool LED_1, bool LED_2, bool LED_3, bool LED_4)
{
  Serial.print(dist);
  Serial.println("cm");
  Serial.print("LED 1: ");
  Serial.println(LED_1);
  Serial.print("LED 2: ");
  Serial.println(LED_2);
  Serial.print("LED 3: ");
  Serial.println(LED_3);
  Serial.print("LED 4: ");
  Serial.println(LED_4);
  Serial.println();
}
void setup()
{
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
}
void loop()
{
  int dist = ultrasonic_read(7, 6);
  if (dist <= 50) 
  {
    LED_control(0, 0, 0, 1);
    output(dist, 1, 0, 0, 0);
  }
  else if (dist <= 100) 
  {
    LED_control(0, 0, 1, 1);
    output(dist, 1, 1, 0, 0);
  }
  else if (dist <= 150) 
  {
    LED_control(0, 1, 1, 1);
    output(dist, 1, 1, 1, 0);
  }
  else if (dist <= 250) 
  {
    LED_control(1, 1, 1, 1);
    output(dist, 1, 1, 1, 1);
  }
  else 
  {
    LED_control(0, 0, 0, 0);
    output(dist, 0, 0, 0, 0);
  }
  delay(500);
}