#include <stdio.h>
#include "mseLoss.h"
#include "weightDerivative.h"
#include "biasDerivative.h"

int controller(float features[], float label[], float weight, float bias, int numberOfValues) {
    float loss;
    float weightDeri;
    float biasDeri;
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
    weightDeri = weightDerivative(predictedValues, label, features, numberOfValues);
    biasDeri = biasDerivative(predictedValues, label, numberOfValues);
    
    printf("MSE Loss: %f\n", loss);
    printf("Weight Derivative: %f\n", weightDeri);
    printf("Bias Derivative: %f\n", biasDeri);

    return 0;
}