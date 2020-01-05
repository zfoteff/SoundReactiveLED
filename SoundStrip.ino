 #define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9
#define SOUND_PIN 7

int brightness = 256;
int gBright = 0;
int rBright = 0;
int bBright = 0;
int toggle = 1;

void Initialize()
{
  analogWrite(RED_LED, 0);
  analogWrite(GREEN_LED, 155);
  analogWrite(BLUE_LED, 0);
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(SOUND_PIN, INPUT);
  
  Initialize();
}

void loop()
{
  // put your main code here, to run repeatedly:
  boolean soundState = digitalRead(7);
  if (soundState == 1)
  {
    if (toggle == 1)
    {
      analogWrite(RED_LED, 255);
      analogWrite(GREEN_LED, 255);
      analogWrite(BLUE_LED, 90);
      delay(1);
    }

    else if (toggle == -1)
    {
      analogWrite(RED_LED, 0);
      analogWrite(GREEN_LED, 155);
      analogWrite(BLUE_LED, 0);
      delay(1);
    }
    
    delay(5);
    toggle *= -1;
  }

  else
  {
    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 0);
  }
}
