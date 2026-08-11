#include <stdio.h>
#include "predictedValues.h"

float predictedValues(int numberOfValues, float bias, float weight, float features[]) {
    int i;
    float predictedValues[numberOfValues];

    for (i = 0; i < numberOfValues; i++) {
        predictedValues[i] = bias + (weight * features[i]);
        printf("%.3f | ", predictedValues[i]);
    }
}