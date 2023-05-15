// The C Programming Language
// Excercise 1-3, 1-4, 1-5
// Author: Jacob Christensen

#include <stdio.h>
#include <stdbool.h>

#define LOWER -100
#define UPPER 100
#define STEP 10

float f2c(float temperatureF) {
    // Convert Fahrenheit to Celsius
    // Takes temp in Celsius, returns temp in Fahrenheit
    // In this expression, 32 is automatically converted to a float
    // Best practices say to write 32 as 32.0,  but this demonstrantes that it will be converted
    return (temperatureF - 32) / 1.8;  
}

float c2f(float temperatureC) {
    // Convert Celcius to Fahrenheit
    return temperatureC * 1.8 + 32.0;
}

void convertRange(int lower, int upper, int step, char from) {
    // This is ugly because I wanted type casting examples

    float temperatureFrom;
    float temperatureTo;
    temperatureFrom = (float) lower;

    if (from == 'f') {
        printf("Fahrenheit\tCelsius\n");
    }
    else {
        printf("Celsius\t\tFahrenheit\n");
    }

    while (temperatureFrom <= (float) upper) {
        if (from == 'f') {
            temperatureTo = f2c(temperatureFrom);
        }
        else {
            temperatureTo = c2f(temperatureFrom);
        }
        printf("%7.2f\t\t%7.2f\n", temperatureFrom, temperatureTo);
        temperatureFrom = temperatureFrom + (float) step;
    }
}

void convertRangeFor(int lower, int upper, int step, char from, bool reverse) {
    // This is ugly because I wanted type casting examples
    // Exercise 1-5

    float temperatureFrom;
    float temperatureTo;
    if (from == 'f') {
        printf("Fahrenheit\tCelsius\n");
    }
    else {
        printf("Celsius\t\tFahrenheit\n");
    }

    if (reverse == true) {
        temperatureFrom = (float) upper;
        for (;temperatureFrom >= lower; temperatureFrom -= step) {
            if (from == 'f') {
                temperatureTo = f2c(temperatureFrom);
            }
            else {
                temperatureTo = c2f(temperatureFrom);
            }
            printf("%7.2f\t\t%7.2f\n", temperatureFrom, temperatureTo);
        } 
    }
    else {
        temperatureFrom = (float) lower;
        for (;temperatureFrom <= upper; temperatureFrom += step) {
            if (from == 'f') {
                temperatureTo = f2c(temperatureFrom);
            }
            else {
                temperatureTo = c2f(temperatureFrom);
            }
            printf("%7.2f\t\t%7.2f\n", temperatureFrom, temperatureTo);
        }
    }
}

int main(void) {

    convertRange(LOWER, UPPER, STEP, 'f');
    convertRange(LOWER, UPPER, STEP, 'c');
    convertRangeFor(LOWER, UPPER, STEP, 'f', true);
    return 0;
} 
