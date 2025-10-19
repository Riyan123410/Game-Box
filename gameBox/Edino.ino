void dino() {  //===========================================================================================  DINO GAME SETUP:
  lcd.clear();
  int jump = 0;
  int bird = 19;
  int cacti = 16;
  int cactus = 23;
  int score = 0;
  int speed = 1000;
  int speedBIRD = 800;
  int summon = 0;
  int size = 0;
  int sizeCheck = 0;
  int size2 = 0;
  int sizeCheck2 = 0;
  int birdY = 0;
  int birdCheck = 0;
  previousTime = currentTime;
  previousTime2 = currentTime;
  previousTime3 = currentTime;
  previousTime4 = currentTime;
  previousTimeBIRD = currentTime;
  previousTimeCACTUS = currentTime;

  //MUSIC
  int STAGE = 0;
  previousTime8 = currentTime;
  int pauseBetweenNotes = 0;
  int note = 0;

  int duration = 1000 / durations[note];

  while (gamemode == 1) {
    //setup
    currentTime = millis();
    if (currentTime - previousTime4 >= 300){
      if (!MUSIC){noTone(Buzzer);}
      previousTime4 = currentTime;
    }
    gameButton();
    button();
    //===================================================================================================== START:
    analogRand = analogRead(A15);
    RANDOM = analogRead(A15) % 2;
    lcd.setCursor(13, 0);
    lcd.print(score);

    if (anyButtonOn() == HIGH) {  //========================================================= JUMPING CODE
      if (jump == 0 && currentTime - previousTime2 >= 500) {
        jump = 1;
        previousTime2 = currentTime;
      }
    } else {
      jump = 0;
      previousTime2 = -500;
      previousTime3 = currentTime;
    }
    if (jump == 1) {  //================================================================== ANIMATION CODE
      lcd.setCursor(0, 0);
      lcd.write(byte(0));
      lcd.setCursor(0, 1);
      lcd.print(" ");
    } else {  //fall down
      lcd.setCursor(0, 1);
      lcd.write(byte(0));
      lcd.setCursor(0, 0);
      lcd.print(" ");
    }
    if (jump == 1 && currentTime - previousTime3 >= 2500 && !FLY) {  // GET DOWN ON TEH GROUND SIRR
      jump = 0;
      previousTime3 = currentTime;
      previousTime2 = currentTime;
    }
    // ====================================================================================== CACTI
    if (summon == 0) {
      if (RANDOM == 1) {
        if (sizeCheck2 == 0) {
          size2 = 1;
          sizeCheck2 = 1;
        }
      } else if (sizeCheck2 == 0) {
        size2 = 0;
        sizeCheck2 = 1;
      }
      lcd.setCursor(cacti, 1);
      lcd.write(byte(2));
      lcd.setCursor(cacti + size, 1);
      lcd.write(byte(2));
      lcd.setCursor(cacti + size + 1, 1);
      lcd.print(" ");
      if (currentTime - previousTime >= speed) {
        if (cacti == -1) {
          if (RANDOM == 1) { summon = 1; }
          cacti = 16;
          lcd.setCursor(cacti, 1);
          lcd.write(byte(2));
          lcd.setCursor(cacti + size2, 1);
          lcd.write(byte(2));
          lcd.setCursor(cactus + size2 + 1, 1);
          lcd.print(" ");
        } else {
          cacti--;
          score++;
          if (speed > 300) { speed -= 10; }
        }
        previousTime = currentTime;
      }
      int size = sizeof(durations) / sizeof(int);

    // MUSIC FROM https://projecthub.arduino.cc/tmekinyan/playing-popular-songs-with-arduino-and-a-buzzer-546f4a 
    if (note < size) {
      //to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int size = sizeof(durations) / sizeof(int);

    if (note < size && MUSIC == true) {
      //to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      if (STAGE == 0){
        previousTime8 = currentTime;
        int duration = 1000 / durations[note];
        tone(Buzzer, melody[note], duration);
        //to distinguish the notes, set a minimum time between them.
        //the note's duration + 30% seems to work well:
        pauseBetweenNotes = duration * 1.30;
        STAGE = 1;
      }
      if (STAGE == 1 && currentTime - previousTime8 >= pauseBetweenNotes){
        //stop the tone playing:
        noTone(Buzzer);

        note++;
        STAGE = 0;
      }
    }
  } else{
    note = 0;
  }
    }
    // ====================================================================================== CACTUS
    if (summon != 2) {
      if (RANDOM == 1) {
        if (sizeCheck == 0) {
          size = 1;
          sizeCheck = 1;
        }
      } else if (sizeCheck == 0) {
        size = 0;
        sizeCheck = 1;
      }
      lcd.setCursor(cactus, 1);
      lcd.write(byte(2));
      lcd.setCursor(cactus + size, 1);
      lcd.write(byte(2));
      lcd.setCursor(cactus + size + 1, 1);
      lcd.print(" ");
      if (currentTime - previousTimeCACTUS >= speed) {
        if (cactus == -1) {
          if (summon == 1) { summon = 2; }
          cactus = analogRand / 5;
          if (cactus > 20) { cactus = 20; }
          sizeCheck = 0;
          lcd.setCursor(0, 1);
          lcd.print(" ");
          lcd.setCursor(size, 1);
          lcd.print(" ");
        } else {
          cactus--;
        }
        previousTimeCACTUS = currentTime;
      }
    }
    //===================================================================================== BIRD
    if (RANDOM == 1 && birdCheck == 0) {
      if (birdCheck == 0) {
        birdY = 1;
        birdCheck = 1;
      }
    } else {
      if (birdCheck == 0) {
        birdY = 0;
        birdCheck = 1;
      }
    }
    if (summon == 2) {
      lcd.setCursor(bird, birdY);
      if (bird % 2 == 0) {
        lcd.write(byte(3));
      } else {
        lcd.write(byte(4));
      }
      lcd.setCursor(bird + 1, birdY);
      lcd.print(" ");
      if (currentTime - previousTimeBIRD >= speedBIRD) {
        if (bird == -1) {
          if (RANDOM == 0) { summon = 0; }
          bird = 23;
          birdCheck = 0;
        } else {
          bird--;
          score--;
          if (speedBIRD > 100) { speedBIRD -= 10; }
        }
        previousTimeBIRD = currentTime;
      }
    }  //========================================================================================= DEATH
    if (jump != birdY && bird == 0 || jump == 0 && cacti == 0 || jump == 0 && cacti == -1 && size2 == 1 || jump == 0 && cactus == 0 || jump == 0 && cactus == -1 && size == 1) {
      lcd.clear();
      buttonState = digitalRead(Button);
      while (buttonState != HIGH) {
        lcd.setCursor(0, 0);
        lcd.print("    You Died!   ");
        lcd.setCursor(0, 1);
        lcd.print("Score:");
        lcd.setCursor(6, 1);
        lcd.print(score);
        //colour(1,0,0,0);
        gamemode = 0;
        buttonState = digitalRead(Button);
      }
    }
  }
}