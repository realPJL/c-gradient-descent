#include <stdio.h>
#include "mseLoss.h"

int main() {
    
    float loss = mseLoss(0, 0);

    printf("MSE Loss: %f", loss);
    
    return 0;
}