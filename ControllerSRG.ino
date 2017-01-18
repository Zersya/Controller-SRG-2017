//Pin Motor Utama
//H
int m1[] = {2, 3};
int m2[] = {4, 5};
//V
int m3[] = {6, 7};
int m4[] = {8, 9};
//H2
int m5[] = {10, 11};
int m6[] = {12, 13};

int led[7] = {A9, A10, A11, A12, A13, A14, A15};

int kuantiaw = A8;

void setup() {

  Serial.begin(9600);
  Serial1.begin(9600);

  for (int i = 0; i < 2; i++) {
    pinMode(m1[i], OUTPUT);
    pinMode(m2[i], OUTPUT);
    pinMode(m3[i], OUTPUT);
    pinMode(m4[i], OUTPUT);
    pinMode(m5[i], OUTPUT);
    pinMode(m6[i], OUTPUT);
  }

  for (int i = 0; i < 7; i++) {
    pinMode(led[i], OUTPUT);
    pinMode(led[i], HIGH);
  }

  pinMode(kuantiaw, OUTPUT);

  setupEEPROM();

  SetSetpointNT(9);
  SetSetpointMT(0);
  digitalWrite(kuantiaw, HIGH);

Serial1.println("//NT");
Serial1.println(getKpNT());
Serial1.println(getKdNT());
Serial1.println(getSetPointNT());

Serial1.println("//MT");
Serial1.println(getKpMT());
Serial1.println(getKdMT());
Serial1.println(getSetPointMT());
  
  check(255);
  delay(8000);
  check(120);
  delay(2000);
  check(0);
}
char l;

void loop() {
  if (Serial1.available()) {
    l = Serial1.read();
    tambahNT(l);
    tambahMT(l);

    addPwm(l);
    cekKondisi(l);

    if (l == 'A') {
      serongKanan(50);
    }
    else if (l == 'B') {
      serongKiri(150);
    }
    else if (l == 'C') {
      Turun(255);
    }
    else if (l == 'D') {
      Naik(255);
    }
  }
  SerialEvent();
  data();

  //check
  //  kondisiMotor(0, jarak());
  //jarak();

}


