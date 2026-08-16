// https://developers.google.com/machine-learning/crash-course/linear-regression

#include <stdio.h>
#include "mseLoss.h"
#include "weightDerivative.h"

float mseLoss(float label[], float predicted[], int numberOfValues) {
    float mseLoss = 0.0;      // MSE loss
    int i;                  // index
    int j;                  // index
    float temp;             // temp var used for calculating MSE loss
    float interumResult;    // interem result of (actual value - predicted value)^2

    // Calculates the MSE loss using:
    // sum of all (actual value - predicted value)^2 devided by number of values
    for (i = 0; i < numberOfValues; i++) {
        temp = label[i] - predicted[i];
        /* printf("Temp: %d\n", temp); */
        interumResult = temp * temp;
        mseLoss = mseLoss + interumResult;
        /* printf("MSE after: %f\n", mseLoss); */
    }

    mseLoss = mseLoss / numberOfValues;

    return mseLoss;
}