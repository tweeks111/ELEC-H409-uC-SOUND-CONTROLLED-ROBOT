#include <xc.h>


void adcPollingInit(void)
{
    AD1CON1bits.AD12B = 1;  // Convertisseur sur 12 bits
    AD1CON3bits.ADCS = 5;   // Clock de l'adc
    AD1CON1bits.ASAM = 1;   // auto sample activ�
    AD1CSSLbits.CSS0 = 1;   // Le convertisseur doit scanner la patte AN0
    AD1PCFGLbits.PCFG0 = 0; // AN0 en mode analogique
    AD1CON1bits.SSRC = 0;   // 0 = ADC activ� manuellement (en software)   => 2 = on le met en mode timer !
    AD1CON1bits.ADON = 1;   // l'ADC est actif
}

void adcTimerInit(void)
{
        AD1CON1bits.AD12B = 1;  // Convertisseur sur 12 bits
        AD1CON3bits.ADCS = 5;   // Diviseur d'horloge de l'adc
        AD1CON1bits.ASAM = 1;   // auto sample activ�
        AD1CSSLbits.CSS0 = 1;   // Le convertisseur doit scanner la patte AN0
        AD1PCFGLbits.PCFG0 = 0; // AN0 en mode analogique
        AD1CON1bits.SSRC = 2;   // ADC activ� par le debordement du TIMER3 (en hardware))
        AD1CON1bits.ADON = 1;   // l'ADC est actif
    
}
void adcPollingStart(void)
{
    AD1CON1bits.SAMP = 0;
}


int adcPollingConversionFinished(void)
{
    return (AD1CON1bits.DONE);
}



int adcPollingRead(void)
{
    if (AD1CON1bits.DONE) {
        return ADC1BUF0;
    } else {
        return (-32678);
    }
}
