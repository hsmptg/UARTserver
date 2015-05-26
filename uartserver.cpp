#include "uartserver.h"

void UARTserver::begin(unsigned long int baudrate) {
    Serial.begin(baudrate);
    while(Serial.available());
        Serial.read();
}

#define CMD_SIZE 10

char *UARTserver::getCmd(void) {
    int c;
    int static index;
    char static cmd[CMD_SIZE+1];

    if ((c = Serial.read()) != -1) {
        if (index && ((char) c == '\r')) {
            cmd[index] = '\0';
            index = 0;
            return cmd;
        }
        else {
            if (index < CMD_SIZE)
                cmd[index++] = (char) c;
            return 0;
        }
    }
    return 0;
}

void UARTserver::sendMsg(const char *msg) {
    Serial.println(msg);
}
