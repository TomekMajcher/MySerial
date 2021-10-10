#if defined(ARDUINO) && (ARDUINO >= 100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

      
void _p(boolean nl, const char *format, va_list args )
{
    char buf[128];          
    vsnprintf(buf, sizeof(buf), format, args);
    #if SERIAL
        Serial.print(buf);
    #endif
}
 
void _p(boolean nl,const __FlashStringHelper *format, va_list args )
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
 
void out(const char *format, ... )
{
    va_list args;
    va_start (args, format );
    _p(1,format,args);
    va_end(args);
}
 
void out(const __FlashStringHelper *format, ... )
{
    va_list args;
    va_start(args, format );
    _p(1,format,args);
    va_end(args);
}
 
void p(const char *format, ... )
{
    va_list args;
    va_start(args, format );
    _p(0,format,args);
    va_end(args);
}
 
void p(const __FlashStringHelper *format, ... )
{
    va_list args;
    va_start(args, format );
    _p(0,format,args);
    va_end(args);
}
