#include <stdio.h>
#include "mseLoss.h"
#include "weightDerivative.h"
#include "biasDerivative.h"

int controller(float features[], float label[], float weight, float bias, int numberOfValues, float learningRate, int maxIterations) {
    float loss;
    float weightGradient;
    float biasGradient;
    float weightChange;
    float biasChange;
    float newWeight;
    float newBias;
    int i;
    float predictedValues[numberOfValues];
    int iteration;

    for (iteration = 0; iteration < maxIterations; iteration++) {
        printf("\n\n---ITERATION: %d---\n\n", iteration);

        // Calculates the predicted values before sending them to mseLoss(), weightDerivative() and biasDerivative()
        // Uses y' = b + w * x
        for (i = 0; i < numberOfValues; i++) {
            predictedValues[i] = bias + (weight * features[i]);
            printf("%.3f | ", predictedValues[i]);
        }
        printf("\n");

        // Calculates MSE Loss
        loss = mseLoss(features, label, predictedValues, weight, bias, numberOfValues);
        weightGradient = weightDerivative(predictedValues, label, features, numberOfValues);
        biasGradient = biasDerivative(predictedValues, label, numberOfValues);

        weightChange = weightGradient * learningRate;
        biasChange = biasGradient * learningRate;

        newWeight = weight - weightChange;
        newBias = bias - biasChange;

        printf("MSE Loss: %f\n", loss);
        printf("Weight Derivative: %f\n", weightGradient);
        printf("Bias Derivative: %f\n", biasGradient);
        printf("\n");
        printf("\n");
        printf("Bias change: %.3f\n", biasChange);
        printf("Weight change: %.3f\n", weightChange);
        printf("New Weight: %.3f\n", newWeight);
        printf("New Bias: %.3f\n", newBias);

        // if last mse losses are around current mse loss -> break;
    }

    return 0;
}