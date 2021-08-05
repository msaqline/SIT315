// C++ code
const int button_pin = 2;
const int LED_pin = 5;
int LED_2 = 0;
int button = 0;
void output(int LED_2)
{  
  Serial.println("Button pressed");
  Serial.print("LED: ");
  Serial.println(LED_2);
  Serial.println();
}
void setup()
{
  Serial.begin(9600);
  pinMode(button_pin, INPUT);
  pinMode(LED_pin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(button_pin), button_ISR, RISING);
}
void loop()
{
  delay(5000);
}

void button_ISR()
{ 
  LED_2 = not LED_2;
  digitalWrite(LED_pin, LED_2);
  output(LED_2);
}