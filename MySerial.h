#ifndef _MySerial_h
#define _MySerial_h

class MySerial
{
    private :
      
      int SerialSpeed;            // speed USB-Serial console

      void _p(boolean nl, const char *format, va_list args );
      void _p(boolean nl,const __FlashStringHelper *format, va_list args );
      void p(const char *format, ... );
      void p(const __FlashStringHelper *format, ... );

    public  :

      /*
      Default Constructor - without parametr.
      @param - no 
      */
      
      MySerial();       

      /*
      Constructor - with parametr
      @param - Serial speed 
      */
      
      MySerial(int speed);   

      void out(const char *format, ... );
      void out(const __FlashStringHelper *format, ... );
};


#endif
