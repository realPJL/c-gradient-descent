#include <stdio.h>
#include "mseLoss.h"
#include "weightDerivative.h"

int controller(float features[], float label[], float weight, float bias, int numberOfValues) {
    float loss;
    
    // Calculates MSE Loss
    loss = mseLoss(features, label, weight, bias, numberOfValues);
    printf("MSE Loss: %f", loss);

    return 0;
}