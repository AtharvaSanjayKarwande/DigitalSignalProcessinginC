#include<stdio.h>
#include<stdlib.h>
#include"waveforms.h"

//Macro to define signal length. Easy to change throughout the code
#define SIGNAL_LENGTH 320

extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGTH];

//double calculateMean(double * signal, int signalLength);

double calculateMean(double * signal, int signalLength){

    // Declare a variable to accumulate
    double mean = 0.0;

    //Looping over the signal to calculate the mean
    for(int i = 0;i<signalLength;i++){
        mean = mean+signal[i];
    }

    mean = mean/(double)signalLength;

    return mean;
}



int main(void){

    double mean = calculateMean(&InputSignal_f32_1kHz_15kHz[0],SIGNAL_LENGTH);

    printf("Mean = %g", mean);

    return 0;
}

