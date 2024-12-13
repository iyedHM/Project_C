/*********************************************************************
 * @file  Buzzer.cpp
 * @author hamrouni iyed hamrouni@insa-toulouse.fr
 * @brief Fichier source du buzzer
 *********************************************************************/
#include "Buzzer.h"
#include <Arduino.h>


Buzzer::Buzzer()
{
  this->pin =0;
  this->state = false ;
}
  
Buzzer::~Buzzer()
{
}  

void Buzzer::init(int p , bool s)
{
  this->pin=p;
  this->state=s;
 pinMode(pin, OUTPUT);
 if (s) {
  digitalWrite(pin, HIGH);
 }else {
  digitalWrite(pin, LOW);
 }
 
}
void Buzzer::off(void)
{
  digitalWrite(pin, LOW);
  state =false;
}

void Buzzer::on(void)
{
  digitalWrite(pin, HIGH);
  state =true;
}
void Buzzer::toggle(void)
{
   if (this->state) {
  this->on();
 }else {
  this->off();
 }

}
void Buzzer::setFrequency(int frequency) {
    if (frequency > 0) {
        tone(pin, frequency); 
        state = true;        
    } else {
        off(); 
    }
}
void Buzzer::Buzzfor(int duration){
  this->on() ;
  delay(duration);
  this->off();

}