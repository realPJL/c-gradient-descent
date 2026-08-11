#include <stdio.h>
#include "mseLoss.h"
#include "weightDerivative.h"

int controller(float features[], float label[], float weight, float bias, int numberOfValues) {
    float loss;
    float weightChange;
    int i;
    float predictedValues[numberOfValues];

    // Calculates the predicted values before sending them to mseLoss and weightDerivative
    // Uses y' = b + w * x
    for (i = 0; i < numberOfValues; i++) {
        predictedValues[i] = bias + (weight * features[i]);
        printf("%.3f | ", predictedValues[i]);
    }
    printf("\n");

    // Calculates MSE Loss
    loss = mseLoss(features, label, predictedValues, weight, bias, numberOfValues);
    weightChange = weightDerivative(predictedValues, label, features, numberOfValues);
    
    printf("MSE Loss: %f\n", loss);
    printf("Weight Derivative: %f\n", weightChange);

    return 0;
}