// First we sum each predicted value minus the actual value 
// and then multiply it by two times the feature value. 
// Then we divide the sum by the number of examples.
// Taken from: https://developers.google.com/machine-learning/crash-course/linear-regression/gradient-descent
#include <stdio.h>
#include "weightDerivative.h"

float weightDerivative(float predictedValue[], float actualValue[], float features[], int numberOfValues) {
    float sum;
    float error[numberOfValues];
    int i;
    float result;
    float errorFeature[numberOfValues];
    float weightDerivative;
    
    sum = 0;

    // Calculates the error via predicted value - actual value
    for (i = 0; i < numberOfValues; i++) {
        error[i] = predictedValue[i] - actualValue[i];
        printf("Error: %.1f \n", error[i]);
    }
    i = 0;
    printf("\n");
    printf("\n");

    // Calculates Error * 2 * Feature
    for (i = 0; i < numberOfValues; i++) {
        errorFeature[i] = error[i] * 2 * features[i];
        printf("Error * 2 * Feature: %.1f\n", errorFeature[i]);
    }
    i = 0;
    printf("\n");

    // Calculates the sum of indexes of errorFeature[]
    for (i = 0; i < numberOfValues; i++) {
        sum = sum + errorFeature[i];
    }
    i = 0;
    printf("Sum: %.1f\n", sum);

    // Calculates the actual weight derivative
    weightDerivative = sum / numberOfValues;
    printf("Weight Derivative: %.1f\n", weightDerivative);

    result = weightDerivative;

    return result;
}