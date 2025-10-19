
void buzzer_clear() {  //==================================================================================== BUZZER CLEAR
  if (digitalRead(Button) != HIGH && digitalRead(Button1) != HIGH) {
    noTone(Buzzer);
  }
}
void LED_clear(){
  digitalWrite(RLED, LOW);
  digitalWrite(BLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(YLED, LOW);
}
void screen() {  //============================================================================================= SELECT GAME WITH POTENTIOMETER
  if (analogRead(A0) < 250) {
    lcd.setCursor(0, 0);
    lcd.print("   Dino Game    ");
    lcd.setCursor(0, 1);
    lcd.print(" Press To Play  ");
  }
  if (analogRead(A0) >= 250 && analogRead(A0) < 500) {
    lcd.setCursor(0, 0);
    lcd.print("  Wack A Mole   ");
    lcd.setCursor(0, 1);
    lcd.print(" Press To Play  ");
  }
  if (analogRead(A0) >= 500 && analogRead(A0) < 750) {
    lcd.setCursor(0, 0);
    lcd.print("   Simon Says   ");
    lcd.setCursor(0, 1);
    lcd.print(" Press To Play  ");
  }
  if (analogRead(A0) >= 750) {
    lcd.setCursor(0, 0);
    lcd.print("   Settings:    ");
    lcd.setCursor(0, 1);
    lcd.print(" Press To Open  ");
  }
}
void button() {  //======================================================================================== START BUTTON
  buttonState = digitalRead(Button);
  if (buttonState == HIGH) {
    if (MainPressed == false){
      MainPressed = true;
      tone(Buzzer, 400);
      if (gamemode == 0) {
        if (analogRead(A0) < 250) {
          gamemode = 1;
        }
        if (analogRead(A0) >= 250 && analogRead(A0) < 500) {
          gamemode = 2;
        }
        if (analogRead(A0) >= 500 && analogRead(A0) < 750) {
          gamemode = 3;
        }
        if (analogRead(A0) >= 750) {
          gamemode = 5;
        }
      } else {
        gamemode = 0;
      }
    } else {
      noTone(Buzzer);
    }
  } else {
    MainPressed = false;
  }
}

void gameButton() {  //======================================================================================== GAME BUTTON:
  light = 0;
  buttonState = digitalRead(Button1);
  if (buttonState == HIGH) {
    //tone(Buzzer,400);
    digitalWrite(RLED, HIGH);
    light = 1;
  }
  buttonState = digitalRead(Button2);
  if (buttonState == HIGH) {
    digitalWrite(BLED, HIGH);
    light = 1;
  }
  buttonState = digitalRead(Button3);
  if (buttonState == HIGH) {
    digitalWrite(GLED, HIGH);
    light = 1;
  }
  buttonState = digitalRead(Button4);
  if (buttonState == HIGH) {
    digitalWrite(YLED, HIGH);
    light = 1;
  }
  if (!light){
    digitalWrite(RLED, LOW);
    digitalWrite(BLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(YLED, LOW);
  }
}
uint8_t anyButtonOn(){
  buttonState = digitalRead(Button1);
  if (buttonState == HIGH) {
    if (!MUSIC && !pushed){tone(Buzzer, 500);}
    pushed = true;
    return buttonState;
  }
  buttonState = digitalRead(Button2);
  if (buttonState == HIGH) {
    if (!MUSIC && !pushed){tone(Buzzer, 500);}
    pushed = true;
    return buttonState;
  }
  buttonState = digitalRead(Button3);
  if (buttonState == HIGH) {
    if (!MUSIC && !pushed){tone(Buzzer, 500);}
    pushed = true;
    return buttonState;
  }
  buttonState = digitalRead(Button4);
  if (buttonState == HIGH) {
    if (!MUSIC && !pushed){tone(Buzzer, 500);}
    pushed = true;
    return buttonState;
  } else {
    pushed = false;
    return buttonState;
  }
}