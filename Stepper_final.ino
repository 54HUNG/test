//Z字型
#define X1 4429 
#define Y1 -3952 
#define Z1 2286
#define E1 -3333
#define X2 -2762
#define Y2 1143
#define Z2 1191
#define E2 3524
#define X3 -952
#define Y3 -95
#define Z3 -95
#define E3 905
#define X4 -2524
#define Y4 -524
#define Z4 -381
#define E4 2238
#define X5 2810
#define Y5 -3667 
#define Z5 4572
#define E5 -3619
#define X6 286
#define Y6 3952
#define Z6 -3905
#define E6 810
#define X7 -143
#define Y7 762
#define Z7 -667
#define E7 50
#define X8 -1143
#define Y8 2381
#define Z8 -3000
#define E8 200
//#define C1 4429 // 2到3的啟動條件
#define C2 1667 // 3到4的啟動條件
#define C3 715 // 4到5的啟動條件
#define C4 -1809  // 5到6的啟動條件
#define C5 1001  // 6到7的啟動條件
#define C6 1287 // 7到8的啟動條件
#define C7 1144  // 8到1的啟動條件
#define T 10 // Z字型延遲時間秒
#define V 5 // Z字型速度係數

//正方形
#define X11 3667
#define Y11 -4476 
#define Z11 3619
#define A11 -2095
#define X12 -2667
#define Y12 -2819
#define Z12 3575
#define A12 1810
#define X13 -2810
#define Y13 3667
#define Z13 -4572
#define A13 3619
#define X14 1810
#define Y14 3429
#define Z14 -3000
#define A14 -3013
//#define C11 4381
#define C12 1000
#define C13 -1810
#define T11 500 // 正方形延遲時間秒
#define V11 5 // 正方形速度係數

#define V_MAX 5000 // 設置速度上限
#include <AccelStepper.h>

int analogPin1 = A2;
int analogPin11 = A3;                      
int val1 = 0;
int val11 = 0;
const int xdirPin = 5;     
const int xstepPin = 2;     
const int ydirPin = 6;     
const int ystepPin = 3;
const int zdirPin = 7;     
const int zstepPin = 4;    
const int adirPin = 13;     
const int astepPin = 12;
const int enablePin = 8;

bool state1 = 0;
bool state2 = 0;
bool state3 = 0;
bool state4 = 0;
bool state5 = 0;
bool state6 = 0;
bool state7 = 0;
bool state8 = 0;
int mode1 = 0;

bool state11 = 0;
bool state12 = 0;
bool state13 = 0;
bool state14 = 0;
int mode11 = 0;

AccelStepper stepper1(1,xstepPin,xdirPin);
AccelStepper stepper2(1,ystepPin,ydirPin); 
AccelStepper stepper3(1,zstepPin,zdirPin);
AccelStepper stepper4(1,astepPin,adirPin);

void setup(){
  Serial.begin(9600);
  pinMode(xstepPin,OUTPUT);     
  pinMode(xdirPin,OUTPUT);       
  pinMode(ystepPin,OUTPUT);     
  pinMode(ydirPin,OUTPUT);
  pinMode(zstepPin,OUTPUT);     
  pinMode(zdirPin,OUTPUT);      
  pinMode(astepPin,OUTPUT);     
  pinMode(adirPin,OUTPUT);     
  pinMode(enablePin,OUTPUT);   
  digitalWrite(enablePin,LOW);                             
  stepper1.setMaxSpeed(V_MAX);
  stepper2.setMaxSpeed(V_MAX);
  stepper3.setMaxSpeed(V_MAX);
  stepper4.setMaxSpeed(V_MAX);
  }
void loop(){
  //Serial.println(stepper1.currentPosition());
  //Serial.println(val1);
  //Serial.println(val11);
  runToPos1();
  //runToPos11();
  }

//Z字型速度(不用動)
void Pos1Speed(){
  stepper1.setSpeed(X1/V);
  stepper2.setSpeed(Y1/V);
  stepper3.setSpeed(Z1/V);
  stepper4.setSpeed(E1/V);
  }
void Pos2Speed(){
  stepper1.setSpeed(X2/V);
  stepper2.setSpeed(Y2/V);
  stepper3.setSpeed(Z2/V);
  stepper4.setSpeed(E2/V);
  }
void Pos3Speed(){
  stepper1.setSpeed(X3/V);
  stepper2.setSpeed(Y3/V);
  stepper3.setSpeed(Z3/V);
  stepper4.setSpeed(E3/V);
  }
void Pos4Speed(){
  stepper1.setSpeed(X4/V);
  stepper2.setSpeed(Y4/V);
  stepper3.setSpeed(Z4/V);
  stepper4.setSpeed(E4/V);
  }
void Pos5Speed(){
  stepper1.setSpeed(X5/V);
  stepper2.setSpeed(Y5/V);
  stepper3.setSpeed(Z5/V);
  stepper4.setSpeed(E5/V);
  }
void Pos6Speed(){
  stepper1.setSpeed(X6/V);
  stepper2.setSpeed(Y6/V);
  stepper3.setSpeed(Z6/V);
  stepper4.setSpeed(E6/V);
  }
void Pos7Speed(){
  stepper1.setSpeed(X7/V);
  stepper2.setSpeed(Y7/V);
  stepper3.setSpeed(Z7/V);
  stepper4.setSpeed(E7/V);
  }
void Pos8Speed(){
  stepper1.setSpeed(X8/V);
  stepper2.setSpeed(Y8/V);
  stepper3.setSpeed(Z8/V);
  stepper4.setSpeed(E8/V);
  }
//正方形速度(不用動)

void Pos11Speed(){
  stepper1.setSpeed(X11/V11);
  stepper2.setSpeed(Y11/V11);
  stepper3.setSpeed(Z11/V11);
  stepper4.setSpeed(A11/V11);
}
void Pos12Speed(){
  stepper1.setSpeed(X12/V11);
  stepper2.setSpeed(Y12/V11);
  stepper3.setSpeed(Z12/V11);
  stepper4.setSpeed(A12/V11);
}
void Pos13Speed(){
  stepper1.setSpeed(X13/V11);
  stepper2.setSpeed(Y13/V11);
  stepper3.setSpeed(Z13/V11);
  stepper4.setSpeed(A13/V11);
}
void Pos14Speed(){
  stepper1.setSpeed(X14/V11);
  stepper2.setSpeed(Y14/V11);
  stepper3.setSpeed(Z14/V11);
  stepper4.setSpeed(A14/V11);
}

//Z字型模式
void runToPos1() {
  //前進到狀態2

  val1 = analogRead(analogPin1);
  if(val1 > 500 && mode11 == 0 ){
    mode1 = 1;
    }
  if(mode1 == 1 && state8 == 0){ 
    Pos1Speed();
    state1 = 1;
    stepper1.move(X1);
    stepper2.move(Y1);
    stepper3.move(Z1);
    stepper4.move(E1);
    }
/*  
  if(digitalRead(enablePin) == LOW && state8 == 0){ 
    Pos1Speed();
    state1 = 1;
    stepper1.move(X1);
    stepper2.move(Y1);
    stepper3.move(Z1);
    stepper4.move(A1);
    }
*/
  //前進到狀態3 
  if(stepper1.currentPosition() == X1 && state1 == 1){ 
    state2 = 1;
    state8 = 1;
    delay(T); 
    Pos2Speed();
    stepper1.move(X2);
    stepper2.move(Y2);
    stepper3.move(Z2);
    stepper4.move(E2);
    Serial.println('5');
    }
  //前進到狀態4  
  if(stepper1.currentPosition() == C2 && state2 == 1){ 
    delay(T);
    state1 = 0;
    Pos3Speed();
    stepper1.move(X3);
    stepper2.move(Y3);
    stepper3.move(Z3);
    stepper4.move(E3);
    state3 = 1;
    Serial.println('6');
    }
  //前進到狀態5  
  if(stepper1.currentPosition() == C3 && state3 == 1){ 
    delay(T);
    state2 = 0;
    Pos4Speed();
    stepper1.move(X4);
    stepper2.move(Y4);
    stepper3.move(Z4);
    stepper4.move(E4);
    state4 = 1;
    Serial.println('7');
    }
  //前進到狀態6    
  if(stepper1.currentPosition() == C4 && state4 == 1){ 
    delay(T);
    state3 = 0;
    Pos5Speed();
    stepper1.move(X5);
    stepper2.move(Y5);
    stepper3.move(Z5);
    stepper4.move(E5);
    state5 = 1;
    Serial.println('8');  
    }
  //前進到狀態7  
  if(stepper1.currentPosition() == C5 && state5 == 1){ 
    delay(T);
    state4 = 0;
    Pos6Speed();
    stepper1.move(X6);
    stepper2.move(Y6);
    stepper3.move(Z6);
    stepper4.move(E6);
    state6 = 1;
    Serial.println('9');
    }
  //前進到狀態8
  if(stepper1.currentPosition() == C6 && state6 == 1){
    delay(T);
    state5 = 0;
    Pos7Speed();
    stepper1.move(X7);
    stepper2.move(Y7);
    stepper3.move(Z7);
    stepper4.move(E7);
    state7 = 1;
    Serial.println('A');
    }
  //前進到狀態1
  if(stepper1.currentPosition() == C7 && state7 == 1){ 
    delay(T);
    state6 = 0;
    //mode1 = 0;
    //state8 = 0;
    Pos8Speed();
    stepper1.move(X8);
    stepper2.move(Y8);
    stepper3.move(Z8);
    stepper4.move(E8);
    Serial.println('B');
    }

  val11 = analogRead(analogPin11);
  if(val11 > 500 && mode1 == 0){
    mode11 = 1;
    }
  if(mode11 == 1 && state14 == 0){ 
    Pos11Speed();
    state11 = 1;
    stepper1.move(X11);
    stepper2.move(Y11);
    stepper3.move(Z11);
    stepper4.move(A11);
    }

/*
  if(digitalRead(enablePin) == LOW && state14 == 0){ 
    Pos11Speed();
    stepper1.move(X11);
    stepper2.move(Y11);
    stepper3.move(Z11);
    stepper4.move(A11);
    state11 = 1;
    
    }
*/
  //前進到狀態3      
  if(stepper1.currentPosition() == X11 && state11 == 1){ 
    state14 = 1;
    state12 = 1;
    delay(T11); 
    Pos12Speed();
    stepper1.move(X12);
    stepper2.move(Y12);
    stepper3.move(Z12);
    stepper4.move(A12);
    Serial.println('2');  
    }
  //前進到狀態4  
  if(stepper1.currentPosition() == C12 && state12 == 1){ 
    delay(T11);
    state11 = 0;
    Pos13Speed();
    stepper1.move(X13);
    stepper2.move(Y13);
    stepper3.move(Z13);
    stepper4.move(A13);
    state13 = 1;
    Serial.println('3');
    }
  //前進到狀態1  
  if(stepper1.currentPosition() == C13 && state13 == 1){ 
    delay(T11);
    state12 = 0;
    //state14 = 0;
    Pos14Speed();
    stepper1.move(X14);
    stepper2.move(Y14);
    stepper3.move(Z14);
    stepper4.move(A14);
    Serial.println('4');   
    }
     
  stepper1.runSpeedToPosition();
  stepper2.runSpeedToPosition();
  stepper3.runSpeedToPosition();
  stepper4.runSpeedToPosition();
  }




  
