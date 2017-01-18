//Lib sensor
#include <SharpIR.h>
SharpIR sensor(GP2YA41SK0F, A0);

//SerialEvent
String _dataMasuk = "";
String tampung;
String inA = "", inB = "";
int a, b;
boolean pemisah = false;
bool dataMasuk;
bool ambil = false;
int distance;

int counter = 0, counterb = 0, counterc = 0;

void SerialEvent() {

  _dataMasuk = "";

  while (Serial.available() > 0) {

    char dataIn = Serial.read();

    if (dataIn == ':') {
      pemisah = true;
    }
    else if (!pemisah) {
      inA += dataIn;
    }
    else if (pemisah) {
      inB += dataIn;
    }

    if (dataIn == '\n') {

      counterb++;
      a = inA.toInt();
      b = inB.toInt();
      pemisah = false;
      dataMasuk = true;
      inA = "";
      inB = "";
      if (b == 9999) {
        counterc++;
        if (counterc == 1) {
          waktuTimer();
          delay(2000);
          Naik(255);
          delay(1000);
        }
      } else {
        b = jarak();
        counterc = 0;
      }
      if (counterb == 20) {
        Serial1.print("A : ");
        Serial1.println(a);
        Serial1.print("B : ");
        Serial1.println(b);
        counterb = 0;
      }
    }
  }
}

void data() {
  if (dataMasuk) {

    kondisiMotor(a, b);
    dataMasuk = false;

    _dataMasuk = "";
  }
}


int jarak() {
  counter += 1;

  distance = sensor.getDistance();
  if (counter == 20) {
    //    Serial1.print("Jarak :");
    //    Serial1.println(distance);
    counter = 0;
  }

  return distance;
}

int getB() {
  return b;
}
boolean getAmbil() {
  return ambil;
}
void setAmbil(bool s) {
  ambil = s;
}

