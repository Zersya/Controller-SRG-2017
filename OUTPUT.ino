int pwmAdd = 100;
bool ambilJatuh = false;

void kondisiMotor(int Aoutput, int Boutput) {
  //BelokKiriKanan
  if (Aoutput < 0) {
    serongKiri(ComputeMT(Aoutput));
    majuEdit(100, 120);
    Serial.println("keKanan");
  } else if (Aoutput > 0) {
    serongKanan(ComputeMT(Aoutput));
    majuEdit(100, 120);
    Serial.println("keKiri");
  }

  //NaikTurun

  if (Boutput > 0 && Boutput < EEPROM.read(2)) {
    Naik(ComputeNT(Boutput));
    Serial.println("Naik");
    Serial.println("===========");
  }
  else if (Boutput > EEPROM.read(2) && Boutput < 70) {
    Turun(ComputeNT(Boutput));
    Serial.println("Turun");
    Serial.println("===========");
  }


  //KondisiKuantiaw
  setKuantiaw(getAmbil());
}

void maju(double pwm) {
  digitalWrite(led[0], HIGH);
  digitalWrite(led[1], HIGH);
  analogWrite(m5[0], pwm);
  analogWrite(m5[1], 0);
  analogWrite(m6[0], pwm);
  analogWrite(m6[1], 0);
}

void majuEdit(double pwm, double pwm2) {
  digitalWrite(led[0], HIGH);
  digitalWrite(led[1], HIGH);
  analogWrite(m5[0], pwm);
  analogWrite(m5[1], 0);
  analogWrite(m6[0], pwm2);
  analogWrite(m6[1], 0);
}

void mundur(double pwm) {
  analogWrite(m5[1], pwm);
  analogWrite(m5[0], 0);
  analogWrite(m6[1], pwm);
  analogWrite(m6[0], 0);
}
void berhentiMT() {
  analogWrite(m5[1], 0);
  analogWrite(m5[0], 0);
  analogWrite(m6[1], 0);
  analogWrite(m6[0], 0);
  analogWrite(m1[1], 0);
  analogWrite(m1[0], 0);
  analogWrite(m2[1], 0);
  analogWrite(m2[0], 0);
}
void berhentiNT() {
  analogWrite(m3[1], 0);
  analogWrite(m3[0], 0);
  analogWrite(m4[1], 0);
  analogWrite(m4[0], 0);
}
void serongKiri(double pwm) {
  digitalWrite(led[5], HIGH);
  digitalWrite(led[6], HIGH);
  analogWrite(m1[1], 0);
  analogWrite(m1[0], pwm);
  analogWrite(m2[1], 0);
  analogWrite(m2[0], pwm);
}

void serongKanan(double pwm) {
  digitalWrite(led[5], HIGH);
  digitalWrite(led[6], HIGH);
  analogWrite(m1[0], 0);
  analogWrite(m1[1], pwm);
  analogWrite(m2[1], pwm);
  analogWrite(m2[0], 0);
}

void Turun(double pwm) {
  digitalWrite(led[4], HIGH);
  digitalWrite(led[3], HIGH);
  analogWrite(m3[0], pwm);
  analogWrite(m3[1], 0);
  analogWrite(m4[0], 0);
  analogWrite(m4[1], pwm);
}

void Naik(double pwm) {
  digitalWrite(led[4], HIGH);
  digitalWrite(led[3], HIGH);
  analogWrite(m3[0], 0);
  analogWrite(m3[1], pwm);
  analogWrite(m4[0], pwm);
  analogWrite(m4[1], 0);
}

void check(int j) {

  analogWrite(m1[0], 0);
  analogWrite(m1[1], j);
  analogWrite(m2[0], j);
  analogWrite(m2[1], 0);
  analogWrite(m3[0], j);
  analogWrite(m3[1], 0);
  analogWrite(m4[0], j);
  analogWrite(m4[1], 0);
  analogWrite(m5[0], j);
  analogWrite(m5[1], 0);
  analogWrite(m6[0], j);
  analogWrite(m6[1], 0);
}

void waktuTimer() {

  analogWrite(m1[0], 0);
  analogWrite(m1[1], 0);
  analogWrite(m2[0], 0);
  analogWrite(m2[1], 0);
  analogWrite(m3[0], 255);
  analogWrite(m3[1], 0);
  analogWrite(m4[0], 0);
  analogWrite(m4[1], 255);
  analogWrite(m5[0], 0);
  analogWrite(m5[1], 0);
  analogWrite(m6[0], 0);
  analogWrite(m6[1], 0);
}

void setKuantiaw(bool input) {
  if (input) {
    digitalWrite(kuantiaw, HIGH);
    delay(500);
  } else {
    digitalWrite(kuantiaw, LOW);
  }
}

int getPwmAdd() {
  return pwmAdd;
}
void setPwmAdd(int s) {
  pwmAdd = s;
}

void setAmbilJatuh(bool a) {
  ambilJatuh = a;
}


