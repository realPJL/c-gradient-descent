#include <stdio.h>
#include "controller.h"

int main() {
    float features[] = {3.5, 3.69, 3.44, 3.43, 4.34, 4.42, 2.37};
    float label[] = {18, 15, 18, 16, 15, 14, 24};
    int numberOfValues;
    float startingWeight;
    float startingBias;
    float learningRate;
    int maxIterations;

    numberOfValues = sizeof(features) / sizeof(features[0]);
    startingWeight = 0;
    startingBias = 0;
    learningRate = 0.01;
    maxIterations = 20;

    printf("Number of Values: %d\n", numberOfValues);
    printf("Starting Weight: %.3f\n", startingWeight);
    printf("Starting Bias: %.3f\n", startingBias);

    controller(features, label, startingWeight, startingBias, numberOfValues, learningRate, maxIterations);
    
    return 0;
}