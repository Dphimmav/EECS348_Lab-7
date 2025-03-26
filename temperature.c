#include "temperature.h"

float celsius_to_fahrenheit(float celsius)
{
    float result = (celsius * 9.0 / 5.0);
    result += 32;
    return result;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    float result = (fahrenheit - 32) * 5.0 / 9.0;
    return result;
}

float celsius_to_kelvin(float celsius)
{
    float result = celsius + 273.15;
    return result;
}

float kelvin_to_celsius(float kelvin)
{
    float result = kelvin - 273.15;
    return result;
}