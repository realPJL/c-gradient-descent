// Taken from Brave Search AI summary
// Cited source: https://stackoverflow.com/questions/13435134/include-other-c-programs

#ifndef CONTROLLER_H
#define CONTROLLER_H

/* Function to act as the controller. Calls mseLoss(), weightDerivative(), biasDerivative() */
int controller(float features[], float label[], float weight, float bias, int numberOfValues);

#endif   