#include<stdio.h>
#include<stdlib.h>

#include"waveforms.h"

#define SIGNAL_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGTH];

double outputAccumulatedSignal[SIGNAL_LENGTH];

void calculateRunningSum(double *inputSignal, double *outputSignal, int inputSignalLength){

    /*Set first element to 0 as there are no points before 0*/
    outputSignal[0]=0;
    for(int i=0;i<inputSignalLength;i++){
        outputSignal[i] = outputSignal[i-1] + inputSignal[i];
    }

}

int main(void){

    calculateRunningSum((double *) &InputSignal_f32_1kHz_15kHz[0], (double *) &outputAccumulatedSignal[0], SIGNAL_LENGTH);

    /*Files to generate for gnuplot*/
    FILE *inputSignalfptr, *outputSignalfptr;

    inputSignalfptr = fopen("inputSignal.dat","w");
    outputSignalfptr = fopen("outputSignal.dat","w");

    for(int i=0;i<SIGNAL_LENGTH;i++){
        fprintf(inputSignalfptr,"\n%f",InputSignal_f32_1kHz_15kHz[i]);
        fprintf(outputSignalfptr,"\n%f", outputAccumulatedSignal[i]);
    }

    fclose(inputSignalfptr);
    fclose(outputSignalfptr);

}

