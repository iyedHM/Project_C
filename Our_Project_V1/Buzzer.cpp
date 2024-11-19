/*********************************************************************
 * @file  Buzzer.cpp
 * @author hamrouni iyed hamrouni@insa-toulouse.fr
 * @brief Fichier source du buzzer
 *********************************************************************/
#include "Buzzer.h"


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
 PinMode(pin, OUTPUT);
 if (s) {
  digitalwrite(pin, HIGH);
 }else {
  degitalwrite(pin, LOW);
 }
 
}
void Buzzer::off(void)
{
  digitalwrite(pin, LOW);
  state =false;
}

void Buzzer::on(void)
{
  digitalwrite(pin, HIGH);
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