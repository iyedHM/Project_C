/*********************************************************************
 * @file  Buzzer.h
 * @author hamrouni iyed hamrouni@insa-toulouse.fr
 * @brief Fichier header du buzzer
 *********************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_

/**
  * @class Buzzer
  * @brief Classe Buzzer 
*/    
class Buzzer
{
  private : 
  // Variable
  int pin ;
  bool state ; 
  public :
    /**
     * @fn Buzzer();
     * @brief Constructeur par defaut
    */    
    Buzzer();
    /**
     * @fn ~Buzzer();
     * @brief Destructeur
    */    
    ~Buzzer();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation du Buzzer
    */
    void init(int p,bool s);
    /**
     * @fn void on(void)
     * @brief Fonction de lancement du Buzzer
    */
    void on(void);
    /**
     * @fn void off(void)
     * @brief Fonction d'arret du Buzzer
    */
    void off(void);
     /**
     * @fn void on(void)
     * @brief Fonction de lancement du Buzzer avec une frequence specifique
    */
    void Buzzer::setFrequency(int frequency);
     /**
     * @fn void on(void)
     * @brief Fonction de lancement du Buzzer pour une durée specifique 
    */
    void Buzzer::Buzzfor(int duration);

};
#endif