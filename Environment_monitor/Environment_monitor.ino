#include <DFRobot_MICS.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"  
#include <Thread.h>
#define DHT11_PIN 2
#define DHTTYPE DHT11
#include <ArduinoJson.h>
#include <Arduino.h>
#include "MHZ19.h" 

MHZ19 myMHZ19;

unsigned long previousMillis;
unsigned long previousMillis_2;
unsigned long counts;
unsigned long events;
unsigned long getDataTimer = 0;

//define intervals for radiation detector
#define time_interval 1000
#define time_interval_2 60000
// define tft screen connection
#define TFT_DC 5              
#define TFT_CS 4             
#define TFT_RST 6             
#define TFT_MISO 50           
#define TFT_MOSI 51           
#define TFT_CLK 52 
//define MICS 5524 sensor connection
#define ADC_PIN A0
#define POWER_PIN 9
//define MICS VOC sensor connection
#define VOC_PIN A1
//define MICS 6814 sensor for NO2, CO, NH3
#define CO_PIN A2
#define NH3_PIN A3
#define NO2_PIN A4
//define MQ4-6 sensor connection
#define CH4_PIN A5
#define LPG_PIN A6
#define C3H8_PIN A7

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

//define DF_Robot obj and mics 5524 calibration time
#define CALIBRATION_TIME 0.25
DFRobot_MICS_ADC mics (ADC_PIN, POWER_PIN);

//define variables
float CO2;
float _CH4;
float VOC;
float _CO;
float _NH3;
float _NO2;
float _LPG;
float _C3H8;
float _H2S;

int temperature;

//define temporary comparison variable
int previous_temp;
unsigned long prev_counts;
int prev_NO2;
int prev_CO;
int prev_CO2;
int prev_NH3;
int prev_CH4;
int prev_H2S;
int prev_VOC;
int prev_LPG;
int prev_C3H8;

// define boolian condition
bool temp_Changed = false;
bool counts_Changed = false;
bool NO2_Changed = false;
bool CO_Changed = false;
bool CO2_Changed = false;
bool NH3_Changed = false;
bool CH4_Changed = false;
bool H2S_Changed = false;
bool VOC_Changed = false;
bool LPG_Changed = false;
bool C3H8_Changed = false;

// impulse counter func
void  impulse() {
  counts++;
  events++;
}
//declare threading
Thread ScreenUpLoad = Thread();
Thread SensorsData = Thread();
Thread Send_Data = Thread();

void setup() {
  Serial.begin(9600); 
  Serial1.begin(9600);
  mics.begin();
  uint8_t mode = mics.getPowerState();
  if(mode == SLEEP_MODE){
    mics.wakeUpMode();
    Serial.println("wake up sensor success!");
  }else{
    Serial.println("The sensor is wake up mode");
  }
  while(!mics.warmUpTime(CALIBRATION_TIME)){
    Serial.println("Please wait until the warm-up time is over!");
    delay(1000);
  }
  
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), impulse, FALLING);
  tft.begin();
  myMHZ19.begin(Serial1);
  myMHZ19.autoCalibration();
  
  tft.fillScreen(ILI9341_BLACK); // Clear the screen
   
/*---------title--------------*/
  tft.setCursor(10, 10);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println("Environment_Monitor");

 /*--------temperature--------*/
  //tft.setCursor(10, 50);
  tft.setCursor(180, 200);
  tft.setTextColor(ILI9341_BLUE);
  tft.setTextSize(2);
  tft.print("t: ");

  tft.setCursor(250, 200);
  tft.setTextColor(ILI9341_BLUE);
  tft.setTextSize(2);
  tft.println(" C");
/*-------------CO-------------*/
  // Display Humidity
  tft.setCursor(10, 80);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("CO: ");

  tft.setCursor(100, 80);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println(" %");
/*------------CO2-------------*/
  // Display CO2 value
  tft.setCursor(10, 110);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("CO2: ");

  tft.setCursor(110, 110);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println("%");

/*------------NH3-------------*/
  
  tft.setCursor(10, 140);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("NH3: ");

  tft.setCursor(110, 140);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println("%");

/*------------H2S-------------*/
  
  tft.setCursor(160, 50);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("H2S: ");

  tft.setCursor(260, 50);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println("%");

/*------------VOC-------------*/
  tft.setCursor(160, 80);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("VOC: ");

  tft.setCursor(250, 80);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println(" %");

/*------------CH4-------------*/
  tft.setCursor(10,170);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("CH4: ");

  tft.setCursor(110, 170);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println("%");

/*-----------NO2---------------*/
  tft.setCursor(10, 50);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("NO2: ");

  tft.setCursor(110, 50);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println("%");
  
/*------------LPG-------------*/
  tft.setCursor(160, 110);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("LPG: ");

  tft.setCursor(250, 110);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println(" %");

/*------------C3H8-------------*/
  tft.setCursor(160, 140);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.print("C3H8: ");

  tft.setCursor(260, 140);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.println(" %");
  
/*------------Radiation-------------*/
  tft.setCursor(10, 200);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  tft.print("Rad dose: ");


/*----------------------------*/

  
  SensorsData.onRun(ReadSensorData);
  SensorsData.setInterval(1000);

  ScreenUpLoad.onRun(ScreenUpdate);
  ScreenUpLoad.setInterval(1500);
  
  Send_Data.onRun(SendData);
  Send_Data.setInterval(1000);
  delay(100);
}

void loop() {
  if(SensorsData.shouldRun()){
    SensorsData.run();
    }
  if(ScreenUpLoad.shouldRun()){
    ScreenUpLoad.run();
    }
  if(Send_Data.shouldRun()){
    Send_Data.run();
    }
}

void ReadSensorData(){
  read_CO2_sensor();
  read_H2S_sensor();
  read_VOC_sensor();
  read_MICs_6814();
  read_MQ4();
  read_MQ5();
  read_MQ6();
  }
 
void ScreenUpdate(){
  if(temp_Changed){
    updateTemperature(temperature);
    }
  if(CO2_Changed){
    updateCO2(CO2);
    }
  if(CH4_Changed){
  updateCH4(_CH4);
  }
  if(VOC_Changed){
  updateVOC(VOC);
  }
  if(CO_Changed){
  updateCO(_CO);
  }
  if(NH3_Changed){
  updateNH3(_NH3);
  }
  if(NO2_Changed){
  updateNO2(_NO2);
  }
  if(H2S_Changed){
  updateH2S(_H2S);
  }
  if(LPG_Changed){
    updateLPG(_LPG);
  }
  if(C3H8_Changed ){
  updateC3H8(_C3H8);
  }
  if (counts_Changed){
    updateRad();
    }
  }

void SendData(){
  StaticJsonDocument<256> doc; 
  String output; 
  unsigned long rad_currentMillis = millis();
    if (rad_currentMillis - previousMillis > time_interval) {
      previousMillis = rad_currentMillis;
      doc["temperature"] = temperature;
      doc["CO2"] = CO2;
      doc["NH3"] = _NH3;
      doc["CH4"] = _CH4;
      doc["VOC"] = VOC;
      doc["CO"] = _CO;
      doc["NO2"] = _NO2;
      doc["H2S"] = _H2S;
      doc["LPG"] = _LPG;
      doc["C3H8"] = _C3H8;
      doc["DRAP"] = counts;
      serializeJson(doc, output);
      Serial.println(output);
      
      if (counts != prev_counts){
        counts_Changed = true;
        prev_counts = counts; 
        } 
      else {
        counts_Changed = false;
      }
      
      counts = 0;

      
  }
  }

float read_CO2_sensor() {
  if (millis() - getDataTimer >= 2000){
        CO2 = myMHZ19.getCO2();                             
        temperature = myMHZ19.getTemperature();                     
        getDataTimer = millis();
        //Serial.print(CO2,1);
        //Serial.println(" PPM");
    }
  
  if (CO2 != prev_CO2) {
    CO2_Changed = true;
    prev_CO2 = CO2; 
  } else {
    CO2_Changed = false;
  } 
  if (temperature != previous_temp) {
    temp_Changed = true;
    previous_temp = temperature;  
  } else {
    temp_Changed = false;
  }   
}

float read_H2S_sensor(){ 
  //_H2S = mics.getGasData(H2S);
  float val_H2S = analogRead(ADC_PIN);
  _H2S = map(val_H2S, 0, 1023, 0, 700);

  if (_H2S != prev_H2S) {
    H2S_Changed = true;
    prev_H2S = _H2S;  
  } else {
    H2S_Changed = false;
  }  
  }

float read_VOC_sensor(){

  float get_voc = analogRead(VOC_PIN);
  VOC = map(get_voc, 0, 1023, 0, 500);
  //Serial.println(VOC);
  if (VOC != prev_VOC) {
    VOC_Changed = true;
    prev_VOC = VOC;  
  } else {
    VOC_Changed = false;
  }  
  }

float read_MICs_6814(){
  int CO_val = analogRead(CO_PIN);
  _CO = map(CO_val, 0, 1023, 0, 1000);
  if (_CO != prev_CO) {
    CO_Changed = true;
    prev_CO = _CO;  
  } else {
    CO_Changed = false;
  }  
  int NH3_val = analogRead(NH3_PIN);
  _NH3 = map(NH3_val, 0, 1023, 0, 500);
  if (_NH3 != prev_NH3) {
    NH3_Changed = true;
    prev_NH3 = _NH3; 
  } else {
    NH3_Changed = false;
  }  
  int NO2_val = analogRead(NO2_PIN);
  _NO2 = map(NO2_val, 0, 1023, 0, 10);
  if (_NO2 != prev_NO2) {
    NO2_Changed = true;
    prev_NO2 = _NO2; 
  } else {
    NO2_Changed = false;
  }  
   
  }

float read_MQ4(){
  int CH4_val = analogRead(CH4_PIN);
  _CH4 = map(CH4_val, 0, 1023, 0, 10000);
  if (_CH4 != prev_CH4) {
    CH4_Changed = true;
    prev_CH4 = _CH4; 
  } else {
    CH4_Changed = false;
  }  
  }
  
float read_MQ5(){
  int LPG_val = analogRead(LPG_PIN);
  _LPG = map(LPG_val, 0, 1023, 0, 10000);
  if (_LPG != prev_LPG) {
    LPG_Changed = true;
    prev_LPG = _LPG; 
  } else {
    LPG_Changed = false;
  }  
  }
  
float read_MQ6(){
  int C3H8_val = analogRead(C3H8_PIN);
  _C3H8 = map(C3H8_val, 0, 1023, 0, 10000);
  if (_C3H8 != prev_C3H8) {
    C3H8_Changed = true;
    prev_C3H8 = _C3H8; 
  } else {
    C3H8_Changed = false;
  }  
  }

void updateTemperature(float temp) {
    tft.setTextColor(ILI9341_BLUE, ILI9341_BLACK); 
    tft.setCursor(210, 200);
    tft.setTextSize(2);
    tft.print(temp, 1);                      
}

void updateCO2(int CO2) {
  
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(60, 110);                        
  float CO2_value = CO2/10000.0;
  tft.print(CO2_value, 2);                                
}

void updateCH4(float _CH4) {
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(60, 170);                        
  float CH4_value = _CH4/10000.0;
  tft.print(CH4_value, 2);                                 
}

void updateVOC(float VOC) {
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(210, 80);
  float VOC_value = VOC/10000.0;                       
  tft.print(VOC_value, 2);                                 
}

void updateCO(float _CO) {
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(60, 80);
  float CO_value = _CO/10000.0;                    
  tft.print(CO_value, 2);                                 
}

void updateNH3(float _NH3) {
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(60, 140);     
  float NH3_value = _NH3/10000.0;                     
  tft.print(NH3_value, 2);                                 
}

void updateNO2(float _NO2) {
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(60, 50); 
  float NO2_value = _NO2/10000.0;                        
  tft.print(NO2_value, 2);                                 
}

void updateH2S(float _H2S) {
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(210, 50); 
  float H2S_value = _H2S/1000000.0;                 
  tft.print(H2S_value, 2); 
  }

void updateLPG(float _LPG) {
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(210, 110); 
  float LPG_value = _LPG/10000.0;                       
  tft.print(LPG_value, 2); 
  }

void updateC3H8(float _C3H8) {
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);   
  tft.setCursor(220, 140); 
  float C3H8_value = _C3H8/10000.0;                       
  tft.print(C3H8_value, 2); 
  }

void updateRad(){
    int x = 120;
    int y = 200;
    int width = 70;  
    int height = 20;
    unsigned long rad_currentMillis = millis();
  
    if (rad_currentMillis - previousMillis_2 > time_interval_2) {
      previousMillis_2 = rad_currentMillis;
      tft.setCursor(x, y);
      tft.setTextSize(2);
      if(events < 60){ 
        tft.setTextColor(ILI9341_GREEN, ILI9341_BLACK);
        }
      else if (events>60 && events < 300){
        tft.setTextColor(ILI9341_YELLOW, ILI9341_BLACK);      
        }
      else if(events>300){
        tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
        }
      //Serial.print("Rad dose: ");
       float mSv_h = events/264.0;
      //Serial.println(mSv_h);
      tft.print(mSv_h);
      events = 0;
    }
}
