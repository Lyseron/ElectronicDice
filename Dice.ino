// ------------------------------------------- DEFINE & VARIABLE ---------------------------------------------- //

// All LEDs
const uint8_t LED_TOP_LEFT = 2;
const uint8_t LED_TOP_RIGHT = 3;
const uint8_t LED_MIDDLE_LEFT = 4;
const uint8_t LED_MIDDLE_MIDDLE = 5; 
const uint8_t LED_MIDDLE_RIGHT = 6;
const uint8_t LED_BOTTOM_LEFT = 7;
const uint8_t LED_BOTTOM_RIGHT = 8;

// PLAY BUTTON to start the game
const uint8_t BUTTON_PLAY = 9;

// ------------------------------------------- FUNCTION DECLARATION ------------------------------------------- //

void turnOffAllLed(void);
void turnOnLed(uint8_t rand);

// ------------------------------------------- SETUP ---------------------------------------------------------- //

void setup(void) {
  
  // Configurate the PLAY BUTTON as INPUT_PULLUP
  pinMode(BUTTON_PLAY, INPUT_PULLUP);

  // Configurate all LEDs as OUTPUT and put them as LOW to start
  for (uint8_t i = 2; i < 9; i++)
    pinMode(i, OUTPUT);

  randomSeed(analogRead(A0));
}

// ------------------------------------------- LOOP ---------------------------------------------------------- //

void loop(void) {

  uint8_t buttonState = digitalRead(BUTTON_PLAY);
  
  if (buttonState == LOW)
  {
    blinkBeforeResult();
    uint8_t rand = random(1, 7);
    turnOnLed(rand);
    while (digitalRead(BUTTON_PLAY) == LOW)
      delay(10);
    delay(30);
  }
}

// ------------------------------------------- FUNCTION UTILS ------------------------------------------------- //

void turnOffAllLed(void)
{
  for (uint8_t i = 2; i < 9; i++)
    digitalWrite(i, LOW);
}

void turnOneLed(void)
{
  digitalWrite(LED_MIDDLE_MIDDLE, HIGH);
}

void turnTwoLed(void)
{
  digitalWrite(LED_TOP_RIGHT, HIGH);
  digitalWrite(LED_BOTTOM_LEFT, HIGH);
}

void turnThreeLed(void)
{
  digitalWrite(LED_TOP_RIGHT, HIGH);
  digitalWrite(LED_BOTTOM_LEFT, HIGH);
  digitalWrite(LED_MIDDLE_MIDDLE, HIGH);
}

void turnFourLed(void)
{
  digitalWrite(LED_TOP_RIGHT, HIGH);
  digitalWrite(LED_TOP_LEFT, HIGH);
  digitalWrite(LED_BOTTOM_LEFT, HIGH);
  digitalWrite(LED_BOTTOM_RIGHT, HIGH);
}

void turnFiveLed(void)
{
  digitalWrite(LED_TOP_RIGHT, HIGH);
  digitalWrite(LED_TOP_LEFT, HIGH);
  digitalWrite(LED_BOTTOM_LEFT, HIGH);
  digitalWrite(LED_BOTTOM_RIGHT, HIGH);
  digitalWrite(LED_MIDDLE_MIDDLE, HIGH);
}

void turnSixLed(void)
{
  digitalWrite(LED_TOP_RIGHT, HIGH);
  digitalWrite(LED_TOP_LEFT, HIGH);
  digitalWrite(LED_BOTTOM_LEFT, HIGH);
  digitalWrite(LED_BOTTOM_RIGHT, HIGH);
  digitalWrite(LED_MIDDLE_LEFT, HIGH);
  digitalWrite(LED_MIDDLE_RIGHT, HIGH);
}

void turnOnAllLed(void)
{
  digitalWrite(LED_TOP_RIGHT, HIGH);
  digitalWrite(LED_TOP_LEFT, HIGH);
  digitalWrite(LED_BOTTOM_LEFT, HIGH);
  digitalWrite(LED_BOTTOM_RIGHT, HIGH);
  digitalWrite(LED_MIDDLE_LEFT, HIGH);
  digitalWrite(LED_MIDDLE_RIGHT, HIGH);
  digitalWrite(LED_MIDDLE_MIDDLE, HIGH);
}

void blinkBeforeResult(void)
{
  for(uint8_t i = 0; i < 3; i++)
    {
      turnOnAllLed();
      delay(100);
      turnOffAllLed();
      delay(100);
    }
}

void turnOnLed(uint8_t rand)
{
  switch (rand)
    {
      case 1:
        turnOneLed();
        break ;
      case 2:
        turnTwoLed();
        break ;
      case 3:
        turnThreeLed();
        break ;
      case 4:
        turnFourLed();
        break ;
      case 5:
        turnFiveLed();
        break ;
      case 6:
        turnSixLed();
        break ;
      default:
        break ;
    }
}

// ------------------------------------------- NOTES ---------------------------------------------------------- //
