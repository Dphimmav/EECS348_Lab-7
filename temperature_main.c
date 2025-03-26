#include "temperature.h"
#include <stdio.h>

void categorize_temperature(float celsius);

int main(int argc, char *argv[])
{
    float temperature = 0.0;
    int scale1 = 0, scale2 = 0;
    float converted_temperature = 0.0;
    while (1)
    {
        printf("Enter the temperature: ");
        if (scanf("%f", &temperature) != 1)
        {
            printf("Invalid input.\n");
        }
        else
        {
            printf("Enter the source scale (1. Celsius, 2. Fahrenheit, 3. Kelvin): ");
            scanf("%d", &scale1);
            printf("Enter the target scale (1. Celsius, 2. Fahrenheit, 3. Kelvin): ");
            scanf("%d", &scale2);

            if (scale1 < 1 || scale1 > 3 || scale2 < 1 || scale2 > 3)
            {
                printf("Invalid conversion choice.\n");
            }

            if ((scale1 == 3 && temperature < 0) || scale2 == scale1)
            {
                if (scale1 == 3 && temperature < 0)
                {
                    printf("Error: Negative Kelvin values\n");
                }
                if (scale2 == scale1)
                {
                    printf("Error: Converting between the same scales is not valid.\n");
                }
            }
            else
            {
                    if (scale1 == 1)
                    {
                        if (scale2 == 2)
                        {
                            converted_temperature = fahrenheit_to_celsius(temperature);
                        }
                        else if (scale2 == 3)
                        {
                            float result = fahrenheit_to_celsius(temperature);
                            converted_temperature = celsius_to_kelvin(result);
                        }
                    }
                    else if (scale1 == 2)
                    {
                        if (scale2 == 1)
                        {
                            converted_temperature = celsius_to_fahrenheit(temperature);
                        }
                        else if (scale2 == 3)
                        {
                            converted_temperature = celsius_to_kelvin(temperature);
                        }
                    }
                    else if (scale1 == 3)
                    {
                        if (scale2 == 1)
                        {
                            float result  = kelvin_to_celsius(temperature);
                            converted_temperature = celsius_to_fahrenheit(result);
                        }
                        else if (scale2 == 2)
                        {
                            converted_temperature = kelvin_to_celsius(temperature);
                        }
                    }
                    printf("Converted temperature: %.2f\n", converted_temperature);
                    if (scale2 == 2)
                    {
                        categorize_temperature(converted_temperature);
                    }
                    else
                    {
                        float result = fahrenheit_to_celsius(converted_temperature);
                        categorize_temperature(result);
                    }
                break;
            }
        }
    }
    return 0;
}
void categorize_temperature(float celsius)
{
    if (celsius < 0)
    {
        printf("Freezing: Wear a jacket.\n");
    }
    else if (celsius < 10)
    {
        printf("Cold: Consider wearing a light jacket.\n");
    }
    else if (celsius < 25)
    {
        printf("Comfortable: Enjoy the day!\n");
    }
    else if (celsius < 35)
    {
        printf("Hot: Stay hydrated and avoid prolonged sun exposure.\n");
    }
    else
    {
        printf("Extreme Heat: Avoid going outside during peak hours.\n");
    }
}
