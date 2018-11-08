#include <MsTimer2.h>
#include <SimpleTimer.h>
#include <stdio.h>

SimpleTimer timer;

#define PUSH_1 5
#define PUSH_2 4
#define PUSH_3 3
#define PUSH_4 2

#define PUSH_TEST 26
// 이상 푸쉬버튼

#define LED0_0 6 
#define LED1_0 10 
#define LED2_0 14 
#define LED3_0 18 
#define LED4_0 22

#define LED0_1 7 
#define LED1_1 11 
#define LED2_1 15 
#define LED3_1 19 
#define LED4_1 23

#define LED0_2 8 
#define LED1_2 12 
#define LED2_2 16 
#define LED3_2 20 
#define LED4_2 24

#define LED0_3 9 
#define LED1_3 13
#define LED2_3 17 
#define LED3_3 21 
#define LED4_3 25
/*
#define PULL_COLOR_0_R 30
#define PULL_COLOR_0_G 31
#define PULL_COLOR_0_B 32

#define PULL_COLOR_1_R 34
#define PULL_COLOR_1_G 35
#define PULL_COLOR_1_B 36

#define PULL_COLOR_2_R 38
#define PULL_COLOR_2_G 39
#define PULL_COLOR_2_B 40

#define PULL_COLOR_3_R 42
#define PULL_COLOR_3_G 43
#define PULL_COLOR_3_B 44
*/
#define PULL_COLOR_0_R 42
#define PULL_COLOR_0_G 43
#define PULL_COLOR_0_B 44

#define PULL_COLOR_1_R 38
#define PULL_COLOR_1_G 39
#define PULL_COLOR_1_B 40

#define PULL_COLOR_2_R 34
#define PULL_COLOR_2_G 35
#define PULL_COLOR_2_B 36

#define PULL_COLOR_3_R 30
#define PULL_COLOR_3_G 31
#define PULL_COLOR_3_B 32

#define LIFE_LED3 46
#define LIFE_LED2 47
#define LIFE_LED1 48

//-----------------------------------------------------------------------------------//
//이상, LED 기초 설정----------------------------------------------------------------//

#define MAX_LIFE 3
int life = MAX_LIFE;

void setup() {
  Serial.begin(9600);
  
  pinMode(LED0_0, OUTPUT); pinMode(LED0_1, OUTPUT); pinMode(LED0_2, OUTPUT); pinMode(LED0_3, OUTPUT);
  pinMode(LED1_0, OUTPUT); pinMode(LED1_1, OUTPUT); pinMode(LED1_2, OUTPUT); pinMode(LED1_3, OUTPUT);
  pinMode(LED2_0, OUTPUT); pinMode(LED2_1, OUTPUT); pinMode(LED2_2, OUTPUT); pinMode(LED2_3, OUTPUT);
  pinMode(LED3_0, OUTPUT); pinMode(LED3_1, OUTPUT); pinMode(LED3_2, OUTPUT); pinMode(LED3_3, OUTPUT); 
  pinMode(LED4_0, OUTPUT); pinMode(LED4_1, OUTPUT); pinMode(LED4_2, OUTPUT); pinMode(LED4_3, OUTPUT);

  pinMode(PULL_COLOR_0_R, OUTPUT);pinMode(PULL_COLOR_1_R, OUTPUT);pinMode(PULL_COLOR_2_R, OUTPUT);pinMode(PULL_COLOR_3_R, OUTPUT);
  pinMode(PULL_COLOR_0_G, OUTPUT);pinMode(PULL_COLOR_1_G, OUTPUT);pinMode(PULL_COLOR_2_G, OUTPUT);pinMode(PULL_COLOR_3_G, OUTPUT);
  pinMode(PULL_COLOR_0_B, OUTPUT);pinMode(PULL_COLOR_1_B, OUTPUT);pinMode(PULL_COLOR_2_B, OUTPUT);pinMode(PULL_COLOR_3_B, OUTPUT);

  pinMode(LIFE_LED1, OUTPUT);
  pinMode(LIFE_LED2, OUTPUT);
  pinMode(LIFE_LED3, OUTPUT);
  
  pinMode(PUSH_1, INPUT);
  pinMode(PUSH_2, INPUT);
  pinMode(PUSH_3, INPUT);
  pinMode(PUSH_4, INPUT); 

  pinMode(PUSH_TEST, INPUT); 
}
//------------------------------------------------------------------------------//
//이상 pinMode 설정

bool led[5][4];
int colorLed[4];

void effect_floor3(){
  digitalWrite(LED0_0, HIGH);digitalWrite(LED0_1, LOW);digitalWrite(LED0_2, LOW);digitalWrite(LED0_3, LOW);
  delay(150);
  digitalWrite(LED0_0, HIGH);digitalWrite(LED0_1, HIGH);digitalWrite(LED0_2, LOW);digitalWrite(LED0_3, LOW);
  digitalWrite(LED1_0, HIGH);digitalWrite(LED1_1, LOW);digitalWrite(LED1_2, LOW);digitalWrite(LED1_3, LOW);
  delay(150);
  digitalWrite(LED0_0, HIGH);digitalWrite(LED0_1, HIGH);digitalWrite(LED0_2, HIGH);digitalWrite(LED0_3, LOW);
  digitalWrite(LED1_0, HIGH);digitalWrite(LED1_1, HIGH);digitalWrite(LED1_2, LOW);digitalWrite(LED1_3, LOW);
  digitalWrite(LED2_0, HIGH);digitalWrite(LED2_1, LOW);digitalWrite(LED2_2, LOW);digitalWrite(LED2_3, LOW);
  delay(150);
  digitalWrite(LED0_0, HIGH);digitalWrite(LED0_1, HIGH);digitalWrite(LED0_2, HIGH);digitalWrite(LED0_3, HIGH);
  digitalWrite(LED1_0, HIGH);digitalWrite(LED1_1, HIGH);digitalWrite(LED1_2, HIGH);digitalWrite(LED1_3, LOW);
  digitalWrite(LED2_0, HIGH);digitalWrite(LED2_1, HIGH);digitalWrite(LED2_2, LOW);digitalWrite(LED2_3, LOW);
  digitalWrite(LED3_0, HIGH);digitalWrite(LED3_1, LOW);digitalWrite(LED3_2, LOW);digitalWrite(LED3_3, LOW);
  delay(150);
  digitalWrite(LED1_0, HIGH);digitalWrite(LED1_1, HIGH);digitalWrite(LED1_2, HIGH);digitalWrite(LED1_3, HIGH);
  digitalWrite(LED2_0, HIGH);digitalWrite(LED2_1, HIGH);digitalWrite(LED2_2, HIGH);digitalWrite(LED2_3, LOW);
  digitalWrite(LED3_0, HIGH);digitalWrite(LED3_1, HIGH);digitalWrite(LED3_2, LOW);digitalWrite(LED3_3, LOW);
  digitalWrite(LED4_0, HIGH);digitalWrite(LED4_1, LOW);digitalWrite(LED4_2, LOW);digitalWrite(LED4_3, LOW);
  delay(150);
  digitalWrite(LED2_0, HIGH);digitalWrite(LED2_1, HIGH);digitalWrite(LED2_2, HIGH);digitalWrite(LED2_3, HIGH);
  digitalWrite(LED3_0, HIGH);digitalWrite(LED3_1, HIGH);digitalWrite(LED3_2, HIGH);digitalWrite(LED3_3, LOW);
  digitalWrite(LED4_0, HIGH);digitalWrite(LED4_1, HIGH);digitalWrite(LED4_2, LOW);digitalWrite(LED4_3, LOW);
  delay(150);
  digitalWrite(LED3_0, HIGH);digitalWrite(LED3_1, HIGH);digitalWrite(LED3_2, HIGH);digitalWrite(LED3_3, HIGH);
  digitalWrite(LED4_0, HIGH);digitalWrite(LED4_1, HIGH);digitalWrite(LED4_2, HIGH);digitalWrite(LED4_3, LOW);
  delay(150);
  digitalWrite(LED4_0, HIGH);digitalWrite(LED4_1, HIGH);digitalWrite(LED4_2, HIGH);digitalWrite(LED4_3, HIGH);
  delay(500);
  
  digitalWrite(LED0_0, LOW);
  delay(150);
  digitalWrite(LED0_1, LOW);digitalWrite(LED1_0, LOW);
  delay(150);
  digitalWrite(LED2_0, LOW);digitalWrite(LED1_1, LOW);digitalWrite(LED0_2, LOW);
  delay(150);
  digitalWrite(LED0_3, LOW);digitalWrite(LED1_2, LOW);digitalWrite(LED2_1, LOW);digitalWrite(LED3_0, LOW);
  delay(150);
  digitalWrite(LED1_3, LOW);digitalWrite(LED2_2, LOW);digitalWrite(LED3_1, LOW);digitalWrite(LED4_0, LOW);
  delay(150);
  digitalWrite(LED2_3, LOW);digitalWrite(LED3_2, LOW);digitalWrite(LED4_1, LOW);
  delay(150);
  digitalWrite(LED3_3, LOW);digitalWrite(LED4_2, LOW);
  delay(150);
  digitalWrite(LED4_3, LOW);
  delay(500);
  
}

void effect_flash_out(){
  digitalWrite(LED0_0, LOW);digitalWrite(LED0_1, LOW);digitalWrite(LED0_2, LOW);digitalWrite(LED0_3, LOW);
  digitalWrite(LED1_0, LOW);digitalWrite(LED1_1, LOW);digitalWrite(LED1_2, LOW);digitalWrite(LED1_3, LOW);
  digitalWrite(LED2_0, LOW);digitalWrite(LED2_1, LOW);digitalWrite(LED2_2, LOW);digitalWrite(LED2_3, LOW);
  digitalWrite(LED3_0, LOW);digitalWrite(LED3_1, LOW);digitalWrite(LED3_2, LOW);digitalWrite(LED3_3, LOW);
  digitalWrite(LED4_0, LOW);digitalWrite(LED4_1, LOW);digitalWrite(LED4_2, LOW);digitalWrite(LED4_3, LOW);
}

void effect_flash(int num){
  for(int i = 0; i < num; i ++){
  digitalWrite(LED0_0, HIGH);digitalWrite(LED0_1, HIGH);digitalWrite(LED0_2, HIGH);digitalWrite(LED0_3, HIGH);
  digitalWrite(LED1_0, HIGH);digitalWrite(LED1_1, HIGH);digitalWrite(LED1_2, HIGH);digitalWrite(LED1_3, HIGH);
  digitalWrite(LED2_0, HIGH);digitalWrite(LED2_1, HIGH);digitalWrite(LED2_2, HIGH);digitalWrite(LED2_3, HIGH);
  digitalWrite(LED3_0, HIGH);digitalWrite(LED3_1, HIGH);digitalWrite(LED3_2, HIGH);digitalWrite(LED3_3, HIGH);
  digitalWrite(LED4_0, HIGH);digitalWrite(LED4_1, HIGH);digitalWrite(LED4_2, HIGH);digitalWrite(LED4_3, HIGH);
  
  delay(200);
  
  digitalWrite(LED0_0, LOW);digitalWrite(LED0_1, LOW);digitalWrite(LED0_2, LOW);digitalWrite(LED0_3, LOW);
  digitalWrite(LED1_0, LOW);digitalWrite(LED1_1, LOW);digitalWrite(LED1_2, LOW);digitalWrite(LED1_3, LOW);
  digitalWrite(LED2_0, LOW);digitalWrite(LED2_1, LOW);digitalWrite(LED2_2, LOW);digitalWrite(LED2_3, LOW);
  digitalWrite(LED3_0, LOW);digitalWrite(LED3_1, LOW);digitalWrite(LED3_2, LOW);digitalWrite(LED3_3, LOW);
  digitalWrite(LED4_0, LOW);digitalWrite(LED4_1, LOW);digitalWrite(LED4_2, LOW);digitalWrite(LED4_3, LOW);

  delay(200);
  }
}

void effect_floor(int num){
  for(int i = 0; i < num; i ++){
  digitalWrite(LED0_0, HIGH);digitalWrite(LED0_1, HIGH);digitalWrite(LED0_2, HIGH);digitalWrite(LED0_3, HIGH);
  delay(100);
  digitalWrite(LED1_0, HIGH);digitalWrite(LED1_1, HIGH);digitalWrite(LED1_2, HIGH);digitalWrite(LED1_3, HIGH);
  delay(100);
  digitalWrite(LED2_0, HIGH);digitalWrite(LED2_1, HIGH);digitalWrite(LED2_2, HIGH);digitalWrite(LED2_3, HIGH);
  delay(100);
  digitalWrite(LED3_0, HIGH);digitalWrite(LED3_1, HIGH);digitalWrite(LED3_2, HIGH);digitalWrite(LED3_3, HIGH);
  delay(100);
  digitalWrite(LED4_0, HIGH);digitalWrite(LED4_1, HIGH);digitalWrite(LED4_2, HIGH);digitalWrite(LED4_3, HIGH);
  delay(200);
  
  digitalWrite(LED0_0, LOW);digitalWrite(LED0_1, LOW);digitalWrite(LED0_2, LOW);digitalWrite(LED0_3, LOW);
  delay(100);
  digitalWrite(LED1_0, LOW);digitalWrite(LED1_1, LOW);digitalWrite(LED1_2, LOW);digitalWrite(LED1_3, LOW);
  delay(100);
  digitalWrite(LED2_0, LOW);digitalWrite(LED2_1, LOW);digitalWrite(LED2_2, LOW);digitalWrite(LED2_3, LOW);
  delay(100);
  digitalWrite(LED3_0, LOW);digitalWrite(LED3_1, LOW);digitalWrite(LED3_2, LOW);digitalWrite(LED3_3, LOW);
  delay(100);
  digitalWrite(LED4_0, LOW);digitalWrite(LED4_1, LOW);digitalWrite(LED4_2, LOW);digitalWrite(LED4_3, LOW);
  delay(200);
  }
}

void effect_floor2(int num){
  for(int i = 0; i < num; i ++){
  digitalWrite(LED0_0, HIGH);digitalWrite(LED0_1, HIGH);digitalWrite(LED0_2, HIGH);digitalWrite(LED0_3, HIGH);
  delay(100);
  digitalWrite(LED1_0, HIGH);digitalWrite(LED1_1, HIGH);digitalWrite(LED1_2, HIGH);digitalWrite(LED1_3, HIGH);
  delay(100);
  digitalWrite(LED2_0, HIGH);digitalWrite(LED2_1, HIGH);digitalWrite(LED2_2, HIGH);digitalWrite(LED2_3, HIGH);
  delay(100);
  digitalWrite(LED3_0, HIGH);digitalWrite(LED3_1, HIGH);digitalWrite(LED3_2, HIGH);digitalWrite(LED3_3, HIGH);
  delay(100);
  digitalWrite(LED4_0, HIGH);digitalWrite(LED4_1, HIGH);digitalWrite(LED4_2, HIGH);digitalWrite(LED4_3, HIGH);
  delay(400);

  digitalWrite(LED4_0, LOW);digitalWrite(LED4_1, LOW);digitalWrite(LED4_2, LOW);digitalWrite(LED4_3, LOW);
  delay(100);
  digitalWrite(LED3_0, LOW);digitalWrite(LED3_1, LOW);digitalWrite(LED3_2, LOW);digitalWrite(LED3_3, LOW);
  delay(100);
  digitalWrite(LED2_0, LOW);digitalWrite(LED2_1, LOW);digitalWrite(LED2_2, LOW);digitalWrite(LED2_3, LOW);
  delay(100);
  digitalWrite(LED1_0, LOW);digitalWrite(LED1_1, LOW);digitalWrite(LED1_2, LOW);digitalWrite(LED1_3, LOW);
  delay(100);
  digitalWrite(LED0_0, LOW);digitalWrite(LED0_1, LOW);digitalWrite(LED0_2, LOW);digitalWrite(LED0_3, LOW);
  delay(400);
  }
}

void life_led(){
  if (life == 3){
    digitalWrite(LIFE_LED3, HIGH);
    digitalWrite(LIFE_LED2, HIGH);
    digitalWrite(LIFE_LED1, HIGH);
  }
  else if (life == 2){
    digitalWrite(LIFE_LED3, LOW);
    digitalWrite(LIFE_LED2, HIGH);
    digitalWrite(LIFE_LED1, HIGH);
  }
  else if (life == 1){
    digitalWrite(LIFE_LED3, LOW);
    digitalWrite(LIFE_LED2, LOW);
    digitalWrite(LIFE_LED1, HIGH);
  }
  else if (life <= 0){
    digitalWrite(LIFE_LED3, LOW);
    digitalWrite(LIFE_LED2, LOW);
    digitalWrite(LIFE_LED1, LOW);
  }
}
void print_color(char color, int button){
  //빨간색 r, 초록색 g, 파란색 b, 하얀색 w
  //하늘색 s, 노란색 y, 보라색 p, 꺼짐 o
  int pin[3];
  //---------------------------------------
  //이하 핀 설정
  if(button == 0){pin[0] = PULL_COLOR_0_R;pin[1] = PULL_COLOR_0_G;pin[2] = PULL_COLOR_0_B;}
  if(button == 1){pin[0] = PULL_COLOR_1_R;pin[1] = PULL_COLOR_1_G;pin[2] = PULL_COLOR_1_B;}
  if(button == 2){pin[0] = PULL_COLOR_2_R;pin[1] = PULL_COLOR_2_G;pin[2] = PULL_COLOR_2_B;}
  if(button == 3){pin[0] = PULL_COLOR_3_R;pin[1] = PULL_COLOR_3_G;pin[2] = PULL_COLOR_3_B;}
  //빨간색 r, 초록색 g, 파란색 b, 하얀색 w
  //하늘색 s, 노란색 y, 보라색 p
  //------------------------------------
  //이하 색상 출력
  if(color == 'o'){
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
  }
  if(color == 'r'){
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
  }
  if(color == 'g'){
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
  }
  if(color == 'b'){
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
  }
  if(color == 's'){
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], HIGH);
  }
  if(color == 'y'){
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
  }
  if(color == 'p'){
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
  }
  if(color == 'w'){
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], HIGH);
  }
}
void print_matrix(){      //현재의 매트릭스 상태를 출력한다( 상황 출력 )
  // 1행
  if (led[0][0] == true) digitalWrite(LED0_0, HIGH);
  else digitalWrite(LED0_0, LOW);
  if (led[0][1] == true) digitalWrite(LED0_1, HIGH);
  else digitalWrite(LED0_1, LOW);
  if (led[0][2] == true) digitalWrite(LED0_2, HIGH);
  else digitalWrite(LED0_2, LOW);
  if (led[0][3] == true) digitalWrite(LED0_3, HIGH);
  else digitalWrite(LED0_3, LOW);
  // 2행
  if (led[1][0] == true) digitalWrite(LED1_0, HIGH);
  else digitalWrite(LED1_0, LOW);
  if (led[1][1] == true) digitalWrite(LED1_1, HIGH);
  else digitalWrite(LED1_1, LOW);
  if (led[1][2] == true) digitalWrite(LED1_2, HIGH);
  else digitalWrite(LED1_2, LOW);
  if (led[1][3] == true) digitalWrite(LED1_3, HIGH);
  else digitalWrite(LED1_3, LOW);
  // 3행
  if (led[2][0] == true) digitalWrite(LED2_0, HIGH);
  else digitalWrite(LED2_0, LOW);
  if (led[2][1] == true) digitalWrite(LED2_1, HIGH);
  else digitalWrite(LED2_1, LOW);
  if (led[2][2] == true) digitalWrite(LED2_2, HIGH);
  else digitalWrite(LED2_2, LOW);
  if (led[2][3] == true) digitalWrite(LED2_3, HIGH);
  else digitalWrite(LED2_3, LOW);
  // 4행
  if (led[3][0] == true) digitalWrite(LED3_0, HIGH);
  else digitalWrite(LED3_0, LOW);
  if (led[3][1] == true) digitalWrite(LED3_1, HIGH);
  else digitalWrite(LED3_1, LOW);
  if (led[3][2] == true) digitalWrite(LED3_2, HIGH);
  else digitalWrite(LED3_2, LOW);
  if (led[3][3] == true) digitalWrite(LED3_3, HIGH);
  else digitalWrite(LED3_3, LOW);
  // 5행
  if (led[4][0] == true) digitalWrite(LED4_0, HIGH);
  else digitalWrite(LED4_0, LOW);
  if (led[4][1] == true) digitalWrite(LED4_1, HIGH);
  else digitalWrite(LED4_1, LOW);
  if (led[4][2] == true) digitalWrite(LED4_2, HIGH);
  else digitalWrite(LED4_2, LOW);
  if (led[4][3] == true) digitalWrite(LED4_3, HIGH);
  else digitalWrite(LED4_3, LOW);
}
//---------------------------------------------------------------------------------------//
//이상 매트릭스 출력

#define X_MAX 4
#define Y_MAX 5
#define MAX_BAR 4       //바의 개수

//---------------------------------------------------------------------------------------//
double MAX_TIME = 10;   //최대 시간
int MAX_LEVEL = 20;    //최대 난이도

int INIT_SPEED = 1000;     //처음 스피드
int FINAL_SPEED = 500;     //최종 스피드

double BAR_MIN_LEVEL_VALUE[MAX_BAR + 1] = {50, 50, 0, 0, 0};   //0개 동시 생성 ~ 5개 동시 생성
double BAR_MAX_LEVEL_VALUE[MAX_BAR + 1] = {20, 30, 20, 17.5, 12.5};

//--------------------------------------------------------------------------------------//
//난이도 조절창

//TIME_PER_LEVEL (MAX_TIME * 1000 / MAX_LEVEL) // 난이도 1이 증가할 때 까지의 시간.

#define GOOD 3
#define PERFECT 4

//{25, 15.5, 14, 17.5, 28};
//-----------------------------------------------------------------------------------//
//이상 게임 기본 세팅

int currentLevel = 0;               //현재 난이도
double barCreatePer[MAX_BAR + 1];   //바 생성 확률
double conditionValue;                    //바 확률 기준치
double randomValue;                       //랜덤 값 저장
double barTime = 1;
bool timerBook = false;                   //타이머 예약

bool state[4] = {false};

//-----------------------------------------------------------------------------------//
double TIME_PER_LEVEL = (MAX_TIME / MAX_LEVEL); // 난이도 1이 증가할 때 까지의 시간.
double currentTime = 0;
double conditionTime = TIME_PER_LEVEL;
//이상 타이머 수정 대비한 변수
//-----------------------------------------------------------------------------------//
int score = 0;
int scoreScore = 0;
#define scoreClear 580
//이상 점수 관련 변수
//-----------------------------------------------------------------------------------//
//이상 게임 기본 변수 세팅

class Game{
  public:
  void levelSetup(){  //-----------------------------------------현재 레벨 조정 함수
    if(TIME_PER_LEVEL < 0.1) TIME_PER_LEVEL = 0.1;
    currentTime = (double)millis() / 1000;
    conditionTime = int(conditionTime * 10) / 10;   //round();
    
    if(currentLevel >= MAX_LEVEL) return;
    if(currentTime >= conditionTime){
      currentLevel++;
      conditionTime += TIME_PER_LEVEL;
      }
  }
  
  void barCreateSetup(){//-------------------------------------현재 bCP[]의 값을 지정해줌
    levelSetup();
    for(int i = 0; i < MAX_BAR + 1; i ++){
       barCreatePer[i] = BAR_MIN_LEVEL_VALUE[i] + (BAR_MAX_LEVEL_VALUE[i] - BAR_MIN_LEVEL_VALUE[i]) / MAX_LEVEL * currentLevel;
       //현재 값 = 최소 난이도 값 + (최대 난이도 값 - 최소 난이도 값) / 최대 난이도 * 현재 난이도
    }
  }
  double randomReturn(int num){//-------------------------------랜덤값 반환
    randomSeed(analogRead(A0));
    return random(num);
  }

  int barCreateNums(){//---------------------------------------동시 생성 설정
    conditionValue = 0;
    randomValue = randomReturn(100) / 100;
    for(int i = 0; i < MAX_BAR + 1; i ++){
       conditionValue += barCreatePer[i] / 100;   //기준치를 점점 높임. bCP[0]부터.
       if (randomValue <= conditionValue){
          return i;
       }
    }
  }
  void randomBar(){ //-------------------------------------------바의 위치 형성
      barCreateSetup();
      int maxCreateBar = barCreateNums();   //바 몇개 생성할건지 대입
      for(int i = 0; i < maxCreateBar; i++){
        int x_bar = randomReturn(MAX_BAR);
        if(led[0][x_bar] == false) {
          led[0][x_bar] = true;
          }
        else {
          i --;
          continue;
        }
      }
    }

    void barMaxDown(){
      for(int x = 0; x < X_MAX; x++){
        if(led[Y_MAX][x] == true){
          life--;
          break;
        }
      }
    }
    
    void barDown(){//-------------------------------------바의 내려감.
      for(int y = Y_MAX; y > 0; y--)
        for(int x = 0; x < X_MAX; x++){
          if (y == 0)
            led[y][x] = false;
            else{
              led[y][x] = led[y - 1][x];
              led[y-1][x] = false;
            }
        }
   }
   //-----------------------------------------------------------------------
   //이상 바 관련 함수
   void hitTiming(int xLine){//----------------------------------점수 판단 여부
     if (led[PERFECT][xLine] == true) {
      print_color('g', xLine);
      score += 2;//------------------------------PERPECT점수
      led[PERFECT][xLine] = false;
     }
     else if (led[GOOD][xLine] == true) {
      print_color('b', xLine);
      score += 1;
      led[GOOD][xLine] = false; 
     }
     else {
      print_color('w', xLine);
      life--;
     }
     print_matrix();
   }
   void button(){//------------------------------------버튼 터치여부
    //PUSH는 1번부터 있다!
    
    if (digitalRead(PUSH_1) != LOW && state[0] == false) {
      hitTiming(0);
      delay(20);
      state[0] = true;
    }
    if(digitalRead(PUSH_1) != HIGH && state[0] == true){
      delay(20);
      state[0] = false;
    }
    if (digitalRead(PUSH_2) == LOW && state[1] == false) {
      hitTiming(1);
      delay(20);
      state[1] = true;
    }
    if(digitalRead(PUSH_2) == HIGH && state[1] == true){
      delay(20);
      state[1] = false;
    }
    if (digitalRead(PUSH_3) == LOW && state[2] == false) {
      hitTiming(2);
      delay(20);
      state[2] = true;
    }
    if(digitalRead(PUSH_3) == HIGH && state[2] == true){
      delay(20);
      state[2] = false;
    }
    if (digitalRead(PUSH_4) == LOW && state[3] == false) {
      hitTiming(3);
      delay(20);
      state[3] = true;
    }
    if(digitalRead(PUSH_4) == HIGH && state[3] == true){
      delay(20);
      state[3] = false;
    }
   }
   
};
//-------------------------------------------------------------------------------------------//
//이상 게임 진행사항에 관한 class

#define DEC_SPEED (INIT_SPEED - FINAL_SPEED) / MAX_TIME    //시간당 감소율

int barSpeed = INIT_SPEED;

int gameSpeed(){              //--------------------------- 게임의 스피드를 조절
  if (barSpeed > FINAL_SPEED) barSpeed -= DEC_SPEED;
}

Game game;
//bool timerbook = false;

void keyLedOff(){
    print_color('o', 0);print_color('o', 1);print_color('o', 2);print_color('o', 3);
}

void allOff(){
  for(int y = 0; y < Y_MAX; y++)
    for(int x = 0; x < X_MAX; x++)
      led[y][x] = false;
}
int scoreColor = 0;
int scoreLed = 0;

void scorePrint(){//----------------------------점수출력
  for(int y = Y_MAX - 1; y >= 0; y--)
     for(int x = 0; x < X_MAX; x++){
      if(score >= 1){
        led[y][x] = true;
        print_matrix();
        score --;
        delay(40);
        if(y == 0 && x == X_MAX - 1 && 
           score > 0){
           allOff();
           x = 0; x--; y = Y_MAX - 1;
             if (scoreColor == 0) print_color('w', scoreLed);
             if (scoreColor == 1) print_color('y', scoreLed);
             if (scoreColor == 2) print_color('g', scoreLed);
             if (scoreColor == 3) print_color('s', scoreLed);
             if (scoreColor == 4) print_color('b', scoreLed);
             if (scoreColor == 5) print_color('p', scoreLed);
             if (scoreColor == 6) print_color('r', scoreLed);
           scoreLed++;
           if (scoreLed > 3){
            scoreLed = 0;
            scoreColor++;
           }
        }
      }
      else {
        scoreLed = 0;
        scoreColor = 0;
        break;
      }
     }
  effect_flash_out();
  delay(500);
  print_matrix();
  delay(500);
  effect_flash_out();
  delay(500);
  print_matrix();
  delay(500);
  effect_flash_out();
  delay(500);
  print_matrix();
  
}

void gameOver(){//------------------------------------------------게임의 끝
  allOff();
  effect_flash(4);
  allOff();
  scorePrint();
  while(1) {
  Serial.println(digitalRead(PUSH_2));
  Serial.println(digitalRead(PUSH_1));
  Serial.println(digitalRead(PUSH_3));
  Serial.println(digitalRead(PUSH_4));
    if (digitalRead(PUSH_1) != LOW ||digitalRead(PUSH_2) == LOW|| digitalRead(PUSH_3) == LOW|| digitalRead(PUSH_4) == LOW ){
      allOff();
      init__();
      return;
    }
  }
}
bool gameSet(){
  Serial.println(digitalRead(PUSH_2));
  Serial.println(digitalRead(PUSH_1));
  Serial.println(digitalRead(PUSH_3));
  Serial.println(digitalRead(PUSH_4));
  if (digitalRead(PUSH_1) != LOW){
    MAX_TIME = 100; MAX_LEVEL = 100; INIT_SPEED = 1000; FINAL_SPEED = 800;
    BAR_MIN_LEVEL_VALUE[0] = 50;BAR_MIN_LEVEL_VALUE[1] = 50;BAR_MIN_LEVEL_VALUE[2] = 0;
    BAR_MIN_LEVEL_VALUE[3] = 0;BAR_MIN_LEVEL_VALUE[4] = 0;
    BAR_MAX_LEVEL_VALUE[0] = 30;BAR_MAX_LEVEL_VALUE[1] = 30;BAR_MAX_LEVEL_VALUE[2] = 20;
    BAR_MAX_LEVEL_VALUE[3] = 20;BAR_MAX_LEVEL_VALUE[4] = 0;
    barSpeed = INIT_SPEED;
    return true;
  }
  if (digitalRead(PUSH_2) == LOW){
    MAX_TIME = 50; MAX_LEVEL = 50; INIT_SPEED = 800; FINAL_SPEED = 500;
    BAR_MIN_LEVEL_VALUE[0] = 40;BAR_MIN_LEVEL_VALUE[1] = 40;BAR_MIN_LEVEL_VALUE[2] = 20;
    BAR_MIN_LEVEL_VALUE[3] = 0;BAR_MIN_LEVEL_VALUE[4] = 0;
    BAR_MAX_LEVEL_VALUE[0] = 30;BAR_MAX_LEVEL_VALUE[1] = 20;BAR_MAX_LEVEL_VALUE[2] = 20;
    BAR_MAX_LEVEL_VALUE[3] = 20;BAR_MAX_LEVEL_VALUE[4] = 10;
    barSpeed = INIT_SPEED;
    return true;
  }
  if (digitalRead(PUSH_3) == LOW){
    MAX_TIME = 50; MAX_LEVEL = 100; INIT_SPEED = 700; FINAL_SPEED = 400;
    BAR_MIN_LEVEL_VALUE[0] = 25;BAR_MIN_LEVEL_VALUE[1] = 25;BAR_MIN_LEVEL_VALUE[2] = 30;
    BAR_MIN_LEVEL_VALUE[3] = 20;BAR_MIN_LEVEL_VALUE[4] = 0;
    BAR_MAX_LEVEL_VALUE[0] = 20;BAR_MAX_LEVEL_VALUE[1] = 20;BAR_MAX_LEVEL_VALUE[2] = 30;
    BAR_MAX_LEVEL_VALUE[3] = 15;BAR_MAX_LEVEL_VALUE[4] = 15;
    barSpeed = INIT_SPEED;
    return true;
  }
  if (digitalRead(PUSH_4) == LOW){
    MAX_TIME = 30; MAX_LEVEL = 100; INIT_SPEED = 500; FINAL_SPEED = 250;
    BAR_MIN_LEVEL_VALUE[0] = 20;BAR_MIN_LEVEL_VALUE[1] = 20;BAR_MIN_LEVEL_VALUE[2] = 20;
    BAR_MIN_LEVEL_VALUE[3] = 20;BAR_MIN_LEVEL_VALUE[4] = 20;
    BAR_MAX_LEVEL_VALUE[0] = 10;BAR_MAX_LEVEL_VALUE[1] = 20;BAR_MAX_LEVEL_VALUE[2] = 30;
    BAR_MAX_LEVEL_VALUE[3] = 25;BAR_MAX_LEVEL_VALUE[4] = 15;
    barSpeed = INIT_SPEED;
    return true;
  }
  return false;
}


void init__(){//--------------------------------게임의 시작
  life = 3;
  score = 0;
  effect_floor3();
  print_color('g', 0);print_color('y', 1);print_color('p', 2);print_color('r', 3);
  while(1){
  if (gameSet() == true) {
    keyLedOff();
    delay(200);
    print_color('g', 0);print_color('y', 1);print_color('p', 2);print_color('r', 3);
    delay(200);
    keyLedOff();
    delay(200);
    print_color('g', 0);print_color('y', 1);print_color('p', 2);print_color('r', 3);
    delay(200);
    effect_floor2(1);
    break;
  }
  }
}

void gameClear(){
   effect_flash_out();
   delay(250);
   print_matrix();
   delay(250);
   effect_flash_out();
   delay(250);
   print_matrix();
   delay(250);
   effect_flash_out();
   delay(250);
   print_matrix();
   delay(250);
   effect_floor3();
   gameOver();
   
}

void gamestart(){//-----------------------------게임의 메인함수
  Serial.println(digitalRead(PUSH_2));
  Serial.println(digitalRead(PUSH_1));
  Serial.println(digitalRead(PUSH_3));
  Serial.println(digitalRead(PUSH_4));
  keyLedOff();
  game.barDown();
  game.barMaxDown();
  game.randomBar();
  print_matrix();
  life_led();
  gameSpeed();
  delay(10);
  if(score > scoreClear) {
    score = scoreClear;
    gameClear();
  }
  if(life <= 0) gameOver();
  timerBook = false;
}
bool startInit = false;

void loop() {
  if (startInit == false){
    init__();
    startInit = true;
  }
  
  if(timerBook == false) {
    timer.setTimeout(barSpeed, gamestart);
    timerBook = true;
  }
  game.button();
  timer.run();
  //Serial.println(digitalRead(PUSH_1));
}
