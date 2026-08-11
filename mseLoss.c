// https://developers.google.com/machine-learning/crash-course/linear-regression

#include <stdio.h>
#include "mseLoss.h"
#include "weightDerivative.h"

float mseLoss(float features[], float label[], float weight, float bias, int numberOfValues) {
    float predicted[7] = {}; // predicted value using y' = b + w * x
    float mseLoss = -1;     // MSE loss
    int i;                  // index
    int j;                  // index
    int temp;               // temp var used for calculating MSE loss
    int interumResult;      // interem result of (actual value - predicted value)^2

    // Calculates the predicted values using the current weights and biases passed to mseLoss as arguments
    for (j = 0; j < numberOfValues; j++) {
        predicted[j] = bias + (weight * features[j]);
        printf("%.3f | ", predicted[j]);
    }
    printf("\n");

    // Calculates the MSE loss using:
    // sum of all (actual value - predicted value)^2 devided by number of values
    for (i = 0; i < numberOfValues; i++) {
        temp = label[i] - predicted[i];
        printf("Temp: %d\n", temp);
        interumResult = temp * temp;
        mseLoss = mseLoss + interumResult;
        printf("MSE after: %f\n", mseLoss);
    }

    mseLoss = mseLoss / numberOfValues;

    weightDerivative(predicted, label, features, numberOfValues);

    return mseLoss;
}