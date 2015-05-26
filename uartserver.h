#ifndef UARTSERVER_H_
#define UARTSERVER_H_

#include "Arduino.h"

class UARTserver {
    public:
        void begin(unsigned long int baudrate);
        char *getCmd();
        void sendMsg(const char *msg);
};

#endif /* UARTSERVER_H_ */
