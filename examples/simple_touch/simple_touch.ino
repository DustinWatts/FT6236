/* 
Title: FT6236 Simple touch example.
By: Dustin Watts
Date: October 18th 2020

Description: 

This sketch checks if the screen is touched and if so, prints the coordinates
to the serial output.
*/

#include <FT6236.h>

FT6236 ts = FT6236();

void setup(void)
{
    Serial.begin(9600);

    //begin(40, SDA, SCL) for custom pins
    if (!ts.begin(40)) //40 in this case represents the sensitivity. Try higer or lower for better response. 
    {
        Serial.println("Unable to start the capacitive touchscreen.");
    }
}

void loop(void)
{

    if (ts.touched())
    {
        // Retrieve a point
        TS_Point p = ts.getPoint();

        // Print coordinates to the serial output
        Serial.print("X Coordinate: ");
        Serial.println(p.x);
        Serial.print("Y Coordinate: ");
        Serial.println(p.y);
    }

    //Debouncing. To avoid returning the same touch multiple times you can play with this delay.
    delay(50);
}
