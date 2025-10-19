void simoneSays(){
  lcd.clear();
  int phase = 0;
  int i = 0;
  int j = 0;
  bool press1 = false;
  bool press2 = false;
  bool press3 = false;
  bool press4 = false;

  previousTime = currentTime;
  int STAGE = 0;
  int note = 0;
  int pauseBetweenNotes = 0;

  previousTime2 = currentTime;

  while(gamemode == 3){
    currentTime = millis();
    button();

    if (!MUSIC){
      buzzer_clear();
    }
   // buzzer_clear();
    if (phase == 0) {
      button();
      //buzzer_clear();
      RANDOM = random(1, 5);
      if (RANDOM == 1){pattern[i] = 1;}
      if (RANDOM == 2){pattern[i] = 2;}
      if (RANDOM == 3){pattern[i] = 3;}
      if (RANDOM == 4){pattern[i] = 4;}

      i++;
      if (i == 100){
        phase = 1;
        i = 0;
        j = 1;
      }
      lcd.setCursor(0, 0);
      lcd.print("    LOADING     ");
    }
    if (phase == 1){
      lcd.setCursor(0, 0);
      lcd.print("    Memorize:   ");
      if (i < j){
        button();
        if (pattern[i] == 1){
          digitalWrite(RLED, HIGH);
        }
        if (pattern[i] == 2){
          digitalWrite(BLED, HIGH);
        }
        if (pattern[i] == 3){
          digitalWrite(GLED, HIGH);
        }
        if (pattern[i] == 4){
          digitalWrite(YLED, HIGH);
        }
        if (!MUSIC){
          tone(Buzzer, 300);
          delay(250);
          buzzer_clear();
        } else{
          delay(250);
        }
        
        delay(250);
        buzzer_clear();
        digitalWrite(RLED, LOW);
        digitalWrite(BLED, LOW);
        digitalWrite(GLED, LOW);
        digitalWrite(YLED, LOW);
        delay(500);
        i++;
      } else {
        phase = 2;
        i = 0;
      }
    }
    if (phase == 2){
      lcd.setCursor(0,0);
      lcd.print("     RECITE:    ");
      if (i < j){
        buttonState = digitalRead(Button1);
        if (buttonState == HIGH){
          digitalWrite(RLED, HIGH);
          tone(Buzzer, 500);
          buzzer_clear();
          delay(100);
          if (press1 == false){
            press1 = true;
            if (pattern[i] == 1){
              i++;
            } else{
              phase = -1;
            }
          }
        } else {
          press1 = false;
          digitalWrite(RLED, LOW);
        }
        buttonState = digitalRead(Button2);
        if (buttonState == HIGH){
          digitalWrite(BLED, HIGH);
          tone(Buzzer, 500);
          delay(100);
          buzzer_clear();
          if (press2 == false){
            press2 = true;
            if (pattern[i] == 2){
              i++;
            } else{
              phase = -1;
            }
          }
        } else {
          press2 = false;
          digitalWrite(BLED, LOW);
        }
        buttonState = digitalRead(Button3);
        if (buttonState == HIGH){
          digitalWrite(GLED, HIGH);
          tone(Buzzer, 500);
          delay(100);
          buzzer_clear();
          if (press3 == false){
            press3 = true;
            if (pattern[i] == 3){
              i++;
            } else{
              phase = -1;
            }
          }
        } else {
          press3 = false;
          digitalWrite(GLED, LOW);
        }
        buttonState = digitalRead(Button4);
        if (buttonState == HIGH){
          digitalWrite(YLED, HIGH);
          tone(Buzzer, 500);
          delay(100);
          buzzer_clear();
          if (press4 == false){
            press4 = true;
            if (pattern[i] == 4){
              i++;
            } else{
              phase = -1;
            }
          }
        } else {
          press4 = false;
          digitalWrite(YLED, LOW);
        }
      } 
      if (i == j) {
        i = 0;
        j++;
        phase = 1;
        LED_clear();
        delay(1000);
      }
    }
    if (phase == -1){
      lcd.clear();
      LED_clear();
      lcd.setCursor(0, 0);
      lcd.print("     WRONG!     ");
      tone(Buzzer,800);
      delay(200);
      buzzer_clear();
      while(gamemode != 0){
        buttonState = digitalRead(Button);
        if (buttonState == HIGH){
          gamemode = 0;
          tone(Buzzer,400);
        }
      }
    }
    int size = sizeof(durations) / sizeof(int);

    if (note < size && MUSIC == true) {
      //to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      if (STAGE == 0){
        previousTime = currentTime;
        int duration = 1000 / durations3[note];
        tone(Buzzer, melody3[note], duration);
        //to distinguish the notes, set a minimum time between them.
        //the note's duration + 30% seems to work well:
        pauseBetweenNotes = duration * 1.30;
        STAGE = 1;
      }
      if (STAGE == 1 && currentTime - previousTime >= pauseBetweenNotes){
        //stop the tone playing:
        noTone(Buzzer);
        note++;
        STAGE = 0;
      }
    } else {
      note = 0;
    }
  }
}