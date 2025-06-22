#ifndef PAYLOADSLIST_H
#define PAYLOADSLIST_H

#include <Arduino.h>

class PAYLOADSLIST
{
public:
    PAYLOADSLIST();
// SERIAL PAYLOADS
    const String CONST_SDCARD = "$PAYLOAD - SDCARD$";
    const String CONST_PULLSCRIPT = "$PAYLOAD - PULLSCRIPT$";
    const String CONST_PULLSCRIPTEXIT = "$PAYLOAD - PULLSCRIPTEXIT$";
// SD PAYLOADS
    const String CONST_SD_FILE = "payload";
    const String CONST_SD_PAYLOAD = "@SD_PAYLOAD - PAYLOAD@";
};

extern PAYLOADSLIST payloadsList;

#endif