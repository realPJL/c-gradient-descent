// https://developers.google.com/machine-learning/crash-course/linear-regression

#include <stdio.h>
#include "mseLoss.h"

float mseLoss(float weight, float bias) {
    float features[] = {3.5, 3.69, 3.44, 3.43, 4.34, 4.42, 2.37};
    float label[] = {18, 15, 18, 16, 15, 14, 24};

    float y;                // predicted value (label)
    float b;                // bias
    float w = weight;       // weight
    float x = bias;         // feature
    float mseLoss;          // MSE loss
    float predictedValue;   // predicted value using y' = b + w * x
    int numberOfValues;     // Length of the array
    int i;                  // index
    int temp;               // temp var used for calculating MSE loss
    int interumResult;      // interem result of (actual value - predicted value)^2

    /* numberOfValues = sizeof(features) / sizeof(features[0]); */
    numberOfValues = 7;
    printf("Number of values before: %d\n", numberOfValues);

    // First run: y' = 0 + 0 * x
    predictedValue = 0;

    for (i = 0; i < numberOfValues; i++) {
        temp = label[i] - predictedValue;
        printf("Temp: %d\n", temp);
        interumResult = temp * temp;
        mseLoss = mseLoss + interumResult;
        printf("MSE after: %f\n", mseLoss);
    }

    mseLoss = mseLoss / numberOfValues;

    return mseLoss;
}