#ifndef _USER_H_
#define _USER_H_

#include <stdint.h>
#include <driverlib/eeprom.h>

struct user {
unsigned int maintainer :1; // 1 if maintainer
unsigned int uidlen     :1; // 1 if 7, otherwise 4
unsigned int status     :1; // 1 if enabled
unsigned int valid      :1; // 0 if valid - by default the eeprom is set to 0xff
unsigned int end        :1; // 1 if after the last valid uid 
unsigned int            :3; // pad to a whole byte
  uint8_t uid[7];
};

// the base address (begining of 2nd block)
#define USERBASE (64)

void dump_user(user * u);
void store_user(user *u);
void list_users(void);

#endif

