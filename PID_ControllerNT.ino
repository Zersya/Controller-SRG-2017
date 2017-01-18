

int MaxPwmNT = 255;
int robotSpeedNT = 150;
float lastErrorNT = 0;

double kpNT = 20;
double kdNT = 1;
double SetpointNT = 0;

double ComputeNT(double input)
{
  double error = SetpointNT - input;
  double rate = (input - lastErrorNT);
  double output = (kpNT * error) + (kdNT * rate);
  output += robotSpeedNT;
  if (output > MaxPwmNT) output = MaxPwmNT;
  else if (output < -MaxPwmNT) output = -MaxPwmNT;
  if (output < 0) {
    output *= -1;
  }
  lastErrorNT = input;
//  Serial1.print("PWM B : ");
//  Serial1.println(output);
  return output;
}

void SetSetpointNT(double d) {

  SetpointNT = d;
}

void SetKpNT(double a){
  kpNT = a;
}
void SetKdNT(double a){
  kdNT = a;
}
double getKpNT(){
  return kpNT;
}
double getKdNT(){
  return kdNT;
}
double getSetPointNT(){
  return SetpointNT;
}



