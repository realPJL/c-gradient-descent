#include <stdio.h>
#include "mseLoss.h"
#include "weightDerivative.h"
#include "biasDerivative.h"

float calculateGradientDescent(float features[], float label[], float *weight, float *bias, int numberOfValues, float learningRate);

int controller(float features[], float label[], float startingWeight, float startingBias, int numberOfValues, float learningRate, int maxIterations) {
    int iteration;
    float weight;
    float bias;
    float currentLoss;
    int i;
    float losses[maxIterations];
    float lossGoal;

    weight = startingWeight;
    bias = startingBias;
    lossGoal = 0.3;


    for (iteration = 0; iteration < maxIterations; iteration++) {
        printf("\n\n---ITERATION: %d---\n\n", iteration);
        
        currentLoss = calculateGradientDescent(features, label, &weight, &bias, numberOfValues, learningRate);

        if (currentLoss <= lossGoal) {
            break;
        }

    }

    return 0;
}

// Calculates weight and bias resulting in the smallest loss. Executes multiple times.
float calculateGradientDescent(float features[], float label[], float *weight, float *bias, int numberOfValues, float learningRate) {
    int i;
    float predictedValues[numberOfValues];
    float loss;
    float weightGradient;
    float biasGradient;
    float weightChange;
    float biasChange;
    
    // Calculates the predicted values before sending them to mseLoss(), weightDerivative() and biasDerivative()
    // Uses y' = b + w * x
    for (i = 0; i < numberOfValues; i++) {
        predictedValues[i] = *bias + (*weight * features[i]);
        /* printf("%.3f | ", predictedValues[i]); */
    }
    printf("\n");

    // Calculates MSE Loss
    loss = mseLoss(label, predictedValues, numberOfValues);
    weightGradient = weightDerivative(predictedValues, label, features, numberOfValues);
    biasGradient = biasDerivative(predictedValues, label, numberOfValues);

    weightChange = weightGradient * learningRate;
    biasChange = biasGradient * learningRate;

    *weight = *weight - weightChange;
    *bias = *bias - biasChange;

    printf("MSE Loss: %f\n", loss);
    printf("Weight Derivative: %f\n", weightGradient);
    printf("Bias Derivative: %f\n", biasGradient);
    printf("\n");
    printf("\n");
    printf("Bias change: %.3f\n", biasChange);
    printf("Weight change: %.3f\n", weightChange);
    printf("New Weight: %.3f\n", *weight);
    printf("New Bias: %.3f\n", *bias);

    return loss;
}