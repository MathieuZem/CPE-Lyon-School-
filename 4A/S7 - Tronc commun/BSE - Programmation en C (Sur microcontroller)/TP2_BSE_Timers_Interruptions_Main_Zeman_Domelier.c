//-----------------------------------------------------------------------------
// TP2_BSE.c
//-----------------------------------------------------------------------------
// AUTH: 
// DATE: 
//
// Target: C8051F02x
// Tool chain: KEIL Microvision5
//
//-----------------------------------------------------------------------------
// Fichiers d'entête
#include "intrins.h"
#include<c8051F020.h>
#include<c8051F020_SFR16.h>
#include<TP2_BSE_Lib_Config_Globale.h>
#include<TP2_BSE_Lib_Divers.h>
#include<TP2_BSE_Main.h>
//-----------------------------------------------------------------------------
// Déclaration des MACROS
#define LED_ON 1
#define LED_OFF 0
#define LED_BLINK 0
#define BP_ON 0
#define BP_OFF 1
#define TO_BE_PROCESSED 1
#define PROCESSED 0

#define RPRT_BTN_ON 1
#define RPRT_BTN_OFF 0

//-----------------------------------------------------------------------------
// Déclarations Registres et Bits de l'espace SFR
sbit LED = P1^6;  // LED
sbit BP =P3^7;    // Bouton Poussoir
sbit DECL_EXTRN = P3^6; //Déclenchement externe du signal
sbit report_btn = P2^4; // rapport des interruption du bouton
report_decl_extrn = 0x86 ; // rapport des interruption du signal de déclenchement

//-----------------------------------------------------------------------------
// Variable globale
Event = PROCESSED;

// Configuration des fonctions(hors .h)
void Config_INT6 (void);

//-----------------------------------------------------------------------------
// MAIN Routine
//-----------------------------------------------------------------------------
void main (void) {
	
bit STATE_LED = LED_BLINK;

 	   // Configurations globales
	      Init_Device();
	   // Configurations  spécifiques  
	      Config_INT6(); // Configuration de INT6
				Config_INT7(); // Configuration de INT7
	
				P74OUT |= (1<<5);
				P2MDOUT |= (1<<4);
	   // Fin des configurations
	      
	      EA = 1;  // Validation globale des interruptions
	
// Boucle infinie	
        while(1)
        {  
					   if (Event == TO_BE_PROCESSED)
						 {
							 Event = PROCESSED;
							 STATE_LED =  !STATE_LED;	
						 }
   
            if (STATE_LED == LED_BLINK)
						{
							LED = LED_ON;
							Software_Delay(2);
					   LED = LED_OFF;
					   Software_Delay(10);
						}
						else LED = LED_OFF;						
        }						               	
			}
//******************************************************************************
void Config_INT7(void)
{
	P3IF &= ~(1<<7); // IE7 mis à 0 pending flag de INT7 effacé
	P3IF &= ~(1<<3); // IE7CF mis à 0 - sensibilité int7 front descendant	
	
	EIP2 &= ~(1<<5);  // PX7 mis à 0 - INT7 priorité basse
	EIE2 |= (1<<5);  // EX7 mis à 1 - INT7 autorisée
}

void Config_INT6(void)
{
	P3IF &= ~(1<<6); // IE7 mis à 0 pending flag de INT6 effacé
	P3IF &= ~(1<<2); // IE7CF mis à 0 - sensibilité int6 front descendant	
	
	
	EIP2 &= ~(1<<4);  // PX7 mis à 0 - INT6 priorité basse
	EIE2 |= (1<<4);  // EX7 mis à 1 - INT6 autorisée
}

//******************************************************************************
void ISR_INT7 (void) interrupt 19
{
	P2 |= (1<<4);
	P3IF &= ~(1<<7); // IE7 mis à 0 - remise à zéro du pending flag de INT7 effacé
	Event = TO_BE_PROCESSED;
	P2 &= ~(1<<4);
}	

void ISR_INT6 (void) interrupt 18
{
	P6 |= (1<<4); // P6.4 mis à 1
	P3IF &= ~(1<<6); // IE7 mis à 0 - remise à zéro du pending flag de INT6 effacé
	Event = TO_BE_PROCESSED;
	P6 &= ~(1<<4); // P6.4 mis à 0
	
	if((P3IF &(1<<2)) == (1<<2)){
		P3IF &=  ~(1<<2);	
	
	}else{
		P3IF |= (1<<2);

	}
}

//*****************************************************************************	 

void Config_Timer2 (void)
{
	//config auto reload
	T2CON |= (1<<2); //config TR2 à 1
	T2CON &= ~(1<<5); //config RCLK0 à 0
	T2CON &= ~(1<<4); //config TCLK0 à 0
	T2CON &= ~(1<<0); //config CP/RL2 à 0
	
	//
	CKCON &= ~(1<<5); //config RCLK0 à 0
	
	//Priorité haute
	IP |= ~(1<<5);
	
	
	
	
	
	
}





