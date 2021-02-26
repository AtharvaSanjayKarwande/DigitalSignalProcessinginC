#include<stdio.h>
#include<stdlib.h>

#include"signalAndImpulseResponse.h"


/* The input signal */
#define SIGNAL_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGTH];
 

/* The impulse response (Low Pass Filter)*/
#define IMPULSE_RESPONSE_LENGTH 29
extern double  Impulse_response[IMPULSE_RESPONSE_LENGTH];

/* Create an output signal array globally*/
double convolutedSignal[SIGNAL_LENGTH+IMPULSE_RESPONSE_LENGTH];

/* Function to convolute the signal with impulse response*/
void calculateConvolution(double *inputSignal, double *impulseResponse, double *convolutedSignal, int signalLength, int impulseResponseLength){
    for(int i=0;i<signalLength;i++){
        for(int j=0;j<impulseResponseLength;j++){
            convolutedSignal[i+j] = convolutedSignal[i+j] + (inputSignal[i]*impulseResponse[j]);
        }
    }
}


int main(void){

    calculateConvolution((double *) &InputSignal_f32_1kHz_15kHz[0],(double *) &Impulse_response,(double *) &convolutedSignal, SIGNAL_LENGTH, IMPULSE_RESPONSE_LENGTH);

    /* Saving the files in .dat format to plot in gnuplots */
    FILE *inputSignalfptr, *impulseResponsefptr, *convolutedSignalfptr;

    inputSignalfptr = fopen("inputSignal.dat","w");
    impulseResponsefptr = fopen("impulseResponse.dat","w");
    convolutedSignalfptr = fopen("convolutedSignal.dat","w");

    /* For gnuplot, the data must be in a coulms format.
    Hence the \n */

    for(int i=0; i<SIGNAL_LENGTH;i++){
        fprintf(inputSignalfptr,"\n%f",InputSignal_f32_1kHz_15kHz[i]);
    }

    for(int i=0;i<IMPULSE_RESPONSE_LENGTH;i++){
        fprintf(impulseResponsefptr,"\n%f",Impulse_response[i]);
    }

    for(int i=0;i<IMPULSE_RESPONSE_LENGTH+SIGNAL_LENGTH;i++){
        fprintf(convolutedSignalfptr,"\n%f",convolutedSignal[i]);
    }

    /*  Closing the file */
    fclose(inputSignalfptr);
    fclose(impulseResponsefptr);
    fclose(convolutedSignalfptr);   

    return 0; 

}



