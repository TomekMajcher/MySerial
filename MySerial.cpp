#include "Arduino.h"
#include "MySerial.h"


// --- default constructor --------------------------------

MySerial::MySerial()
{
    SerialSpeed = 57200;
    Serial.begin(SerialSpeed);
}

// --- main constructor -----------------------------------

MySerial::MySerial(int speed)
{
    SerialSpeed = speed;
    Serial.begin(SerialSpeed);
}

// --- private methods -------------------------------------------------

void MySerial::_p(boolean nl, const char *format, va_list args )
{
    char buf[128];          
    vsnprintf(buf, sizeof(buf), format, args);
    #if SERIAL
        Serial.print(buf);
    #endif
}

void MySerial::_p(boolean nl,const __FlashStringHelper *format, va_list args )
{
    char buf[128]; 
    #ifdef __AVR__
        vsnprintf_P(buf, sizeof(buf), (const char *)format, args);      
    #else
        vsnprintf(buf, sizeof(buf), (const char *)format, args);     
    #endif

    #if SERIAL
        Serial.print(buf);
    #endif
}

void MySerial::p(const char *format, ... )
{
    va_list args;
    va_start(args, format );
    _p(0,format,args);
    va_end(args);
}

void MySerial::p(const __FlashStringHelper *format, ... )
{
    va_list args;
    va_start(args, format );
    _p(0,format,args);
    va_end(args);
}

// --- public methods -------------------------------------------------

void MySerial::out(const char *format, ... )
{
    va_list args;
    va_start (args, format );
    _p(1,format,args);
    va_end(args);
}

void MySerial::out(const __FlashStringHelper *format, ... )
{
    va_list args;
    va_start(args, format );
    _p(1,format,args);
    va_end(args);
}
