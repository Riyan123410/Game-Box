
int clear = 0;  //clear screen?
int gamemode;   //wut game we playin?
bool light = 0; // set light off

//RANDOM
int RANDOM = 0;
int analogRand = 0;
//PREVIOUS TIME:
unsigned long currentTime = millis(); // currentTime
unsigned long previousTime = 0;
unsigned long previousTime2 = 0;
unsigned long previousTime3 = 0;
unsigned long previousTime4 = 0;
unsigned long previousTime5 = 0;
unsigned long previousTime6 = 0;
unsigned long previousTime7 = 0;
unsigned long previousTime8 = 0;
unsigned long previousTimeBIRD = 0;
unsigned long previousTimeCACTUS = 0;

bool MainPressed = false;

//MEMORY
bool phase = false;
unsigned long pattern[100];

//MUSIC
bool MUSIC = 0;
bool MOLEDIFF = 0;
bool FLY = 0;
int pushed = false;

void setup() {                //========================================================================================== SETUP:
  //buttons:
  pinMode(Button, INPUT);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Button4, INPUT);
  // LEDs:
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(YLED, OUTPUT);
  
  // buzzer:
  pinMode(Buzzer, OUTPUT);

  //LCD
  lcd.init();                      // initialize the lcd
  lcd.backlight();                 // Turn on the LCD screen backlight
  lcd.createChar(0, customDino);   //dino skin
  lcd.createChar(1, customCacti);  //cacti skin
  lcd.createChar(2, customCacti2);
  lcd.createChar(3, customBird);
  lcd.createChar(4, customBird2);

  randomSeed(analogRead(A15));
}