
void wackAmole(){//===================================================================================================== WACK A MOLE
  lcd.clear();
  int moleScore = 0;
  buzzer_clear();

  randomSeed(analogRead(15));
  int mole1TIME = random(100,1000);
  int mole2TIME = random(100,1000);
  int mole3TIME = random(100,1000);
  int mole4TIME = random(100,1000);

  bool mole1 = 0;
  bool mole2 = 0;
  bool mole3 = 0;
  bool mole4 = 0;
  double moleSpeed = 5.0;
  bool molePressed1 = false;
  bool molePressed2 = false;
  bool molePressed3 = false;
  bool molePressed4 = false;
  previousTime = currentTime;
  previousTime2 = currentTime;
  previousTime3 = currentTime;
  previousTime4 = currentTime;
  previousTime5 = currentTime;
  previousTime6 = currentTime;
  previousTime7 = currentTime;
  previousTime8 = currentTime;
  //MUSIC
  int note = 0;
  previousTimeBIRD = currentTime;
  previousTimeCACTUS = currentTime;
  int STAGE = 0;
  int pauseBetweenNotes = 0;

  unsigned long TIMER = currentTime;

  while (gamemode == 2){
    currentTime = millis();
    randomSeed(analogRead(15));
    //buzzer_clear();
    button();
    lcd.setCursor(4, 0);
    lcd.print("Score:");
    lcd.setCursor(11, 0);
    lcd.print(moleScore);
    if (moleScore < 10 && moleScore >= 0) {
      lcd.setCursor(12,0); 
      lcd.print("     ");
    } else if (moleScore >= 10 && moleScore < 100) {
      lcd.setCursor(13,0); 
      lcd.print("      ");
    } else if (moleScore >= 100){
      lcd.setCursor(14,0); 
      lcd.print("      ");
    }

    if (!MUSIC){
      buzzer_clear();
    }

    if (currentTime - previousTime >= mole2TIME * moleSpeed * 2) {
      if (mole2 == false){
        mole2 = true;
        tone(Buzzer, 400);
        digitalWrite(BLED, HIGH);
        previousTime = currentTime;
      }
    }
    if (mole2 == true){
      if (currentTime - previousTime2 >= mole2TIME * moleSpeed){
        mole2 = false;
        tone(Buzzer, 800);
        digitalWrite(BLED, LOW);
        previousTime2 = currentTime;
        randomSeed(analogRead(15));
        mole2TIME = random(100,1000);
        if (MOLEDIFF){moleScore--;}
      }
    } else {
      previousTime2 = currentTime;
    }
    buttonState = digitalRead(Button2);
    if (buttonState == HIGH && molePressed1 == false){
      molePressed1 = true;
      if (mole2 == true){
        mole2 = false;
        tone(Buzzer, 200);
        digitalWrite(BLED, LOW);
        moleScore++;
        randomSeed(analogRead(15));
        mole2TIME = random(100,1000);
        moleSpeed = moleSpeed - 0.1;
      } else {
        moleScore--;
        tone(Buzzer, 800);
      }
    }
    if (buttonState != HIGH){
      molePressed1 = false;
    }
    // ===================================================================================================
    if (currentTime - previousTime3 >= mole3TIME * moleSpeed * 2) {
      if (mole3 == false){
        mole3 = true;
        tone(Buzzer, 400);
        digitalWrite(GLED, HIGH);
        previousTime3 = currentTime;
      }
    }
    if (mole3 == true){
      if (currentTime - previousTime4 >= mole3TIME * moleSpeed){
        mole3 = false;
        tone(Buzzer, 800);
        digitalWrite(GLED, LOW);
        previousTime4 = currentTime;
        randomSeed(analogRead(13));
        mole3TIME = random(100,1000);
        if (MOLEDIFF){moleScore--;}
      }
    } else {
      previousTime4 = currentTime;
    }
    buttonState = digitalRead(Button3);
    if (buttonState == HIGH && molePressed2 == false){
      molePressed2 = true;
      if (mole3 == true){
        mole3 = false;
        tone(Buzzer, 200);
        digitalWrite(GLED, LOW);
        moleScore++;
        randomSeed(analogRead(13));
        mole3TIME = random(100,1000);
        moleSpeed = moleSpeed - 0.1;
      } else {
        moleScore--;
        tone(Buzzer, 800);
      }
    }
    if (buttonState != HIGH){
      molePressed2 = false;
    }
    //=============================================================================================================
    if (currentTime - previousTime5 >= mole4TIME * moleSpeed * 2) {
      if (mole4 == false){
        mole4 = true;
        tone(Buzzer, 400);
        digitalWrite(YLED, HIGH);
        previousTime5 = currentTime;
      }
    }
    if (mole4 == true){
      if (currentTime - previousTime6 >= mole4TIME * moleSpeed){
        mole4 = false;
        tone(Buzzer, 800);
        digitalWrite(YLED, LOW);
        previousTime6 = currentTime;
        randomSeed(analogRead(11));
        mole4TIME = random(100,1000);
        if (MOLEDIFF){moleScore--;}
      }
    } else {
      previousTime6 = currentTime;
    }
    buttonState = digitalRead(Button4);
    if (buttonState == HIGH && molePressed3 == false){
      molePressed3 = true;
      if (mole4 == true){
        mole4 = false;
        tone(Buzzer, 200);
        digitalWrite(YLED, LOW);
        moleScore++;
        moleSpeed = moleSpeed - 0.1;
        randomSeed(analogRead(11));
        mole4TIME = random(100,1000);
      } else {
        moleScore--;
        tone(Buzzer, 800);
      }
    }
    if (buttonState != HIGH){
      molePressed3 = false;
    }
    //=============================================================================================================
    if (currentTime - previousTime7 >= mole1TIME * moleSpeed * 2) {
      if (mole1 == false){
        mole1 = true;
        tone(Buzzer, 400);
        digitalWrite(RLED, HIGH);
        previousTime7 = currentTime;
      }
    }
    if (mole1 == true){
      if (currentTime - previousTime8 >= mole1TIME * moleSpeed){
        mole1 = false;
        tone(Buzzer, 800);
        digitalWrite(RLED, LOW);
        previousTime8 = currentTime;
        randomSeed(analogRead(9));
        mole4TIME = random(100,1000);
        if (MOLEDIFF){moleScore--;}
      }
    } else {
      previousTime8 = currentTime;
    }
    int size = sizeof(durations) / sizeof(int);

    // MUSIC FROM https://projecthub.arduino.cc/tmekinyan/playing-popular-songs-with-arduino-and-a-buzzer-546f4a 
    if (note < size && MUSIC == true) {
      //to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      if (STAGE == 0){
        previousTimeBIRD = currentTime;
        int duration = 1000 / durations2[note];
        tone(Buzzer, melody2[note], duration);
        //to distinguish the notes, set a minimum time between them.
        //the note's duration + 30% seems to work well:
        pauseBetweenNotes = duration * 1.30;
        STAGE = 1;
      }
      if (STAGE == 1 && currentTime - previousTimeBIRD >= pauseBetweenNotes){
        //stop the tone playing:
        noTone(Buzzer);
        note++;
        STAGE = 0;
      }
    } else {
      note = 0;
    }
    buttonState = digitalRead(Button1);
    if (buttonState == HIGH && molePressed4 == false){
      molePressed4 = true;
      if (mole1 == true){
        mole1 = false;
        tone(Buzzer, 200);
        digitalWrite(RLED, LOW);
        moleScore++;
        randomSeed(analogRead(9));
        mole4TIME = random(100,1000);
        moleSpeed = moleSpeed - 0.1;
      } else {
        moleScore--;
        tone(Buzzer, 800);
      }
    }
    if (buttonState != HIGH){
      molePressed4 = false;
    }
    lcd.setCursor(4, 1);
    lcd.print("Time:");
    double timeLeft = currentTime - TIMER;
    lcd.print(45 - timeLeft/1000);
    lcd.setCursor(14, 1);
    lcd.print(" ");
    if (currentTime - TIMER >= 45000){
      lcd.clear();
      LED_clear();
      lcd.setCursor(0, 0);
      lcd.print("    Time Out!   ");
      lcd.setCursor(0, 1);
      lcd.print("    Score:");
      lcd.setCursor(10, 1);
      lcd.print(moleScore);
      tone(Buzzer, 800);
      delay(200);
      buzzer_clear();
      while (gamemode == 2){
        buttonState = digitalRead(Button);
        if (buttonState == HIGH){
          gamemode = 0;
          TIMER = currentTime;
        }
      }
    }
  }
}