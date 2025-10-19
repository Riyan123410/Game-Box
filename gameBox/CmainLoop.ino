
void loop() {  //============================================================================================== LOOP:
  buzzer_clear();
  if (gamemode == 0) {
    screen();
  }
  button();
  //buzzer_clear();//silence buzzer
  if (gamemode == 1) {
    dino();
  }
  if (gamemode == 2) {
    wackAmole();
  }
  if (gamemode == 3){
    simoneSays();
  }
  if (gamemode == 5){
    settings();
  }
  LED_clear();
}
