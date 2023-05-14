#include <stdio.h>

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

int main(void) {

    int lower = -100;
    int upper = 100;
    int step = 10;

    convertRange(lower, upper, step, 'f');
    convertRange(lower, upper, step, 'c');
    return 0;
} 
