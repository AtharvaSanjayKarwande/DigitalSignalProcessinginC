#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

double calculateVariance(double *signal, double mean, int signalLength){

    double variance=0.0;

    for(int i=0;i<signalLength;i++){
        variance = variance + ((signal[i]-mean)*(signal[i]-mean));
    }

    variance = variance/(double)(signalLength-1);
    return variance;
}

double calculateStandardDeviation(double *signal, double mean, int signalLength){
    double variance = calculateVariance(signal,mean,signalLength);

    return sqrt(variance);
}





int main(void){

    double mean = calculateMean(&InputSignal_f32_1kHz_15kHz[0],SIGNAL_LENGTH);
    printf("Mean = %g\n", mean);

    double variance = calculateVariance(&InputSignal_f32_1kHz_15kHz[0],mean,SIGNAL_LENGTH);
    printf("Variance = %g\n", variance);

    double stdDeviation = calculateStandardDeviation(&InputSignal_f32_1kHz_15kHz[0],mean,SIGNAL_LENGTH);
    printf("Standard deviation = %g",stdDeviation);

    return 0;
}

