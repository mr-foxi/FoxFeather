#ifndef BLUE_H
#define BLUE_H

#include "Arduino.h"
#include "ArduinoBLE.h"

class BLUE
{
public:
    BLUE();
    void up();
    void poll();
};
extern BLUE blue;

#endif 