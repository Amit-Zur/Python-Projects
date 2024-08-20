#include <stdio.h>

// INPUT TEMPERATURE IN DEGREE CELCIUS, CONVERT TO DEGREE FAHRENHEIT

//FUNCTION DECLARATION

float celsius_to_fahrenheit(float celsius);

int main()
{
    float temperature;

    // ASK THE USER FOR THE INPUT TEMPERATURE IN CELSIUS

    printf("Input temperature in degree Celsius: ");
    scanf("%f", &temperature);

    // CALL THE FUNCTION TO CONVERT CELSIUS TO FAHREHNHEIT

    float fahrenheit = celsius_to_fahrenheit(temperature);

    // PRINT THE RESULTS

    printf("Equivalent temperature in degree Fahrenheit is: %f\n", fahrenheit);

    return 0;
}

float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 1.8) + 32;
}
