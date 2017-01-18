

int MaxPwmMT = 80;
int robotSpeedMT = 50;
float lastErrorMT = 0;

double kpMT = EEPROM.read(4);         
double kdMT = EEPROM.read(5);          
double SetpointMT = EEPROM.read(6);     

double ComputeMT(double input)
{
  double error;
  if(input <0) {error = SetpointMT + input;}
  else {error = SetpointMT - input;}
  double rate = (input - lastErrorMT);
  double output = (kpMT * error) + (kdMT * rate);
  output += robotSpeedMT;
  if (output > MaxPwmMT) output = MaxPwmMT;
  else if (output < -MaxPwmMT) output = -MaxPwmMT;
  if(output < 0){ output *= -1; }

  lastErrorMT = input;
//  Serial1.print("PWM A : ");
//  Serial1.println(output);
  return output;
}

void SetSetpointMT(double d) {
  SetpointMT = d;
}
void SetKpMT(double a){
  kpMT = a;
}
void SetKdMT(double a){
  kdMT = a;
}
double getKpMT(){
  return kpMT;
}
double getKdMT(){
  return kdMT;
}
double getSetPointMT(){
  return SetpointMT;
}



