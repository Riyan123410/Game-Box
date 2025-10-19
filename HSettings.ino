void settings(){
  int stage = 0;
  bool pushy = 0;
  bool pushy2 = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("R:RED   B:BLUE  ");
  lcd.setCursor(0, 1);
  lcd.print("G:GREEN Y:YELLOW  ");
  delay(250);
  buzzer_clear();
  while (anyButtonOn() != HIGH){
    int stage = 0;
    button();
  }
  lcd.clear();
  previousTime = currentTime;
  while (gamemode == 5){
    currentTime = millis();
    button();
    if (currentTime - previousTime >= 500){
      noTone(Buzzer);
    }

    buttonState = digitalRead(Button4);
    if (buttonState == HIGH && !pushy){
      pushy = true;
      stage++;
      if (stage == 3){
        stage = 0;
      }
    } else if (buttonState != HIGH){
      pushy = false;
    }
    buttonState = digitalRead(Button1);
    if (buttonState == HIGH && !pushy2){
      pushy2 = true;
      stage--;
      if (stage == -1){
        stage = 2;
      }
    } else if (buttonState != HIGH){
      pushy2 = false;
    }
    if (stage == 0){
      if (MUSIC){
        lcd.setCursor(0, 0);
        lcd.print("    MUSIC: ON   ");
        lcd.setCursor(0, 1);
        lcd.print(" R:<-|B:OFF|Y:->");
      } else{
        lcd.setCursor(0, 0);
        lcd.print("    MUSIC: OFF  ");
        lcd.setCursor(0, 1);
        lcd.print(" R:<-|G:ON|Y:-> ");
      }
      buttonState = digitalRead(Button2);
      if (buttonState == HIGH){

        MUSIC = false;
      }
      buttonState = digitalRead(Button3);
      if (buttonState == HIGH){
        MUSIC = true;
      }
    }
    if (stage == 1){
      if (!MOLEDIFF){
        lcd.setCursor(0, 0);
        lcd.print("Difficulty: EASY");
        lcd.setCursor(0, 1);
        lcd.print("R:<-|G:HARD|Y:->");
      } else{
        lcd.setCursor(0, 0);
        lcd.print("Difficulty: HARD");
        lcd.setCursor(0, 1);
        lcd.print("R:<-|B:EASY|Y:->");
      }
      buttonState = digitalRead(Button2);
      if (buttonState == HIGH){
        MOLEDIFF = false;
      }
      buttonState = digitalRead(Button3);
      if (buttonState == HIGH){
        MOLEDIFF = true;
      }
    }
    if (stage == 2){
      if (FLY){
        lcd.setCursor(0, 0);
        lcd.print(" DINOGAME:CANFLY");
        lcd.setCursor(0, 1);
        lcd.print("R:<-|B:CANT|Y:->");
      } else{
        lcd.setCursor(0, 0);
        lcd.print("DINOGAME:CANTFLY");
        lcd.setCursor(0, 1);
        lcd.print("R:<-|G:CAN|Y:-> ");
      }
      buttonState = digitalRead(Button2);
      if (buttonState == HIGH){
        FLY = false;
      }
      buttonState = digitalRead(Button3);
      if (buttonState == HIGH){
        FLY = true;
      }
    }
  }
}