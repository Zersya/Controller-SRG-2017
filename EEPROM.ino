#include <EEPROM.h>

int NT[3] = {35, 4, 10};
int MT[3] = {25, 1, 0};
int ambilBatas = 0;
int naikPwm = 0;

void setupEEPROM() {
  //KP += 0.5
  //  EEPROM.write(0, 35);
  //  EEPROM.write(1, 0.5);
  //  EEPROM.write(3, 10);
  //
  //  EEPROM.write(4, 25);
  //  EEPROM.write(5, 1);
  //  EEPROM.write(6, 0);

  //  EEPROM.write(7, 100);
  //  EEPROM.write(8, 0);
  //  EEPROM.write(9, 0);
  //  EEPROM.write(10, 0);


  //clear
  //  for (int i = 0; i < EEPROM.length(); i++) {
  //     EEPROM.write(i, 0);
  //  }
  //  digitalWrite(13, HIGH);

}
void tambahNT(char L) {

  NT[0] = EEPROM.read(0);
  NT[1] = EEPROM.read(1);
  NT[2] = EEPROM.read(2);
  if (L == 'Q') {
    SetKpNT(NT[0] += 1);
    EEPROM.write(0, NT[0]);
    Serial1.print("KP NT: " );
    Serial1.println(getKpNT());
  }
  if (L == 'A') {
    SetKpNT(NT[0] -= 1);
    EEPROM.write(0, NT[0]);
    Serial1.print("KP NT: " );
    Serial1.println(getKpNT());
  }
  if (L == 'W') {
    SetKdNT(NT[1] += 1);
    EEPROM.write(1, NT[1]);
    Serial1.print("KD NT: " );
    Serial1.println(getKdNT());
  }
  if (L == 'S') {
    SetKdNT(NT[1] -= 1);
    EEPROM.write(1, NT[1]);
    Serial1.print("KD NT: " );
    Serial1.println(getKdNT());
  }
  if (L == 'E') {
    SetSetpointNT(NT[2] += 1);
    EEPROM.write(2, NT[2]);
    Serial1.print("SET NT: " );
    Serial1.println(getSetPointNT());
  }
  if (L == 'D') {
    SetSetpointNT(NT[2] -= 1);
    EEPROM.write(2, NT[2]);
    Serial1.print("SET NT: " );
    Serial1.println(getSetPointNT());
  }
}




void tambahMT(char L) {

  MT[0] = EEPROM.read(4);
  MT[1] = EEPROM.read(5);
  MT[2] = EEPROM.read(6);
  if (L == 'P') {
    SetKpMT(MT[0] += 1);
    EEPROM.write(4, MT[0]);
    Serial1.print("KP MT: " );
    Serial1.println(getKpMT());
  }
  if (L == 'L') {
    SetKpMT(MT[0] -= 1);
    EEPROM.write(4, MT[0]);
    Serial1.print("KP MT: " );
    Serial1.println(getKpMT());
  }
  if (L == 'O') {
    SetKdMT(MT[1] += 1);
    EEPROM.write(5, MT[1]);
    Serial1.print("KD MT: " );
    Serial1.println(getKdMT());
  }
  if (L == 'K') {
    SetKdMT(MT[1] -= 1);
    EEPROM.write(5, MT[1]);
    Serial1.print("KD MT: " );
    Serial1.println(getKdMT());
  }
  if (L == 'I') {
    SetSetpointMT(MT[2] += 1);
    EEPROM.write(6, MT[2]);
    Serial1.print("SET MT: " );
    Serial1.println(getSetPointMT());
  }
  if (L == 'J') {
    SetSetpointMT(MT[2] -= 1);
    EEPROM.write(6, MT[2]);
    Serial1.print("SET MT: " );
    Serial1.println(getSetPointMT());
  }

}

void addPwm(char L) {
  naikPwm = EEPROM.read(7);
  if (L == '=') {
    setPwmAdd(naikPwm += 1);
    EEPROM.write(7, naikPwm);
    Serial1.print("PWM Maju naik : ");
    Serial1.println(naikPwm);
  }
  if (L == '-') {
    setPwmAdd(naikPwm -= 1);
    EEPROM.write(7, naikPwm);
    Serial1.print("PWM Maju turun : ");
    Serial1.println(naikPwm);
  }
}

void cekKondisi(char L) {
  if (L == 'G') {
    Serial1.println("//Naik Turun");
    for (int i = 0; i < 3; i++) {
      Serial1.println(NT[i]);
    }

    Serial1.println("//Maju Mundur");
    for (int i = 0; i < 3; i++) {
      Serial1.println(MT[i]);
    }

    Serial1.println("//PWMAddKanan");
    Serial1.println(naikPwm);
  }
}


