#include <stdio.h>
#include "mseLoss.h"
#include "weightDerivative.h"
#include "biasDerivative.h"

void firstCalculation(float features[], float label[], float startingWeight, float startingBias, int numberOfValues, float learningRate);
void nextCalculation(float features[], float label[], float newWeight, float newBias, int numberOfValues, float learningRate);

float loss;
float weightGradient;
float biasGradient;
float weightChange;
float biasChange;
float newWeight;
float newBias;
float predictedValues[7];


int controller(float features[], float label[], float startingWeight, float startingBias, int numberOfValues, float learningRate, int maxIterations) {
    int iteration;

    for (iteration = 0; iteration < maxIterations; iteration++) {
        printf("\n\n---ITERATION: %d---\n\n", iteration);
        
        if (iteration == 0) {
            firstCalculation(features, label, startingWeight, startingBias, numberOfValues, learningRate);
        } else {
            nextCalculation(features, label, newWeight, newBias, numberOfValues, learningRate);
        }

        // if last mse losses are around current mse loss -> break;
    }

    return 0;
}

// Does the first round of calculations using the starting weight/bias. Only executed once each session.
void firstCalculation(float features[], float label[], float startingWeight, float startingBias, int numberOfValues, float learningRate) {
    int i;

    // Calculates the predicted values before sending them to mseLoss(), weightDerivative() and biasDerivative()
    // Uses y' = b + w * x
    for (i = 0; i < numberOfValues; i++) {
        predictedValues[i] = startingBias + (startingWeight * features[i]);
        printf("%.3f | ", predictedValues[i]);
    }
    printf("\n");

    // Calculates MSE Loss
    loss = mseLoss(features, label, predictedValues, startingWeight, startingBias, numberOfValues);
    weightGradient = weightDerivative(predictedValues, label, features, numberOfValues);
    biasGradient = biasDerivative(predictedValues, label, numberOfValues);

    weightChange = weightGradient * learningRate;
    biasChange = biasGradient * learningRate;

    newWeight = startingWeight - weightChange;
    newBias = startingBias - biasChange;

    printf("MSE Loss: %f\n", loss);
    printf("Weight Derivative: %f\n", weightGradient);
    printf("Bias Derivative: %f\n", biasGradient);
    printf("\n");
    printf("\n");
    printf("Bias change: %.3f\n", biasChange);
    printf("Weight change: %.3f\n", weightChange);
    printf("New Weight: %.3f\n", newWeight);
    printf("New Bias: %.3f\n", newBias);
}

// Does rounds 2 - maxIterations of calculations using the calculated/updated weight/bias. Executes multiple times.
void nextCalculation(float features[], float label[], float newWeight, float newBias, int numberOfValues, float learningRate) {
    int i;
    
    // Calculates the predicted values before sending them to mseLoss(), weightDerivative() and biasDerivative()
    // Uses y' = b + w * x
    for (i = 0; i < numberOfValues; i++) {
        predictedValues[i] = newBias + (newWeight * features[i]);
        printf("%.3f | ", predictedValues[i]);
    }
    printf("\n");

    // Calculates MSE Loss
    loss = mseLoss(features, label, predictedValues, newWeight, newBias, numberOfValues);
    weightGradient = weightDerivative(predictedValues, label, features, numberOfValues);
    biasGradient = biasDerivative(predictedValues, label, numberOfValues);

    weightChange = weightGradient * learningRate;
    biasChange = biasGradient * learningRate;

    newWeight = newWeight - weightChange;
    newBias = newBias - biasChange;

    printf("MSE Loss: %f\n", loss);
    printf("Weight Derivative: %f\n", weightGradient);
    printf("Bias Derivative: %f\n", biasGradient);
    printf("\n");
    printf("\n");
    printf("Bias change: %.3f\n", biasChange);
    printf("Weight change: %.3f\n", weightChange);
    printf("New Weight: %.3f\n", newWeight);
    printf("New Bias: %.3f\n", newBias);
}