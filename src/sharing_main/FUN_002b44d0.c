/* HSTMATCH module=hstp_trans_main.prx start=0x002b44d0 end=0x002b4648 symbol=FUN_002b44d0 lang=c99 data=0x003a9850 */
/* Hand-written reconstruction (port of src/eboot/FUN_002a4d40_002a4d40.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003a9850-0x003a988e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/savedata_screen.h"

extern unsigned char DAT_003b8ec6;
extern unsigned char DAT_003ba329;
extern unsigned char DAT_003b7ebc;
extern void FUN_0001c684();
extern void FUN_0001c73c();
extern void FUN_002b4648();
extern void FUN_002b46a8();
extern int FUN_002c74f0();
extern void FUN_002c7628();

#define DEVCTL_MEMSTICK_INSERTED 0x2425823 /* device control code: is a memory stick present */

/* Start the screen: check for a memory stick (showing the loading screen), then pick the first state. */
void FUN_002b44d0(SaveScreen *self)
{
  u32 present;
  int inserted;
  int inserted2;
  
  if (self->state == SAVE_STATE_IDLE) {
    present = FUN_002c74f0("fatms0:",DEVCTL_MEMSTICK_INSERTED,0,0,&inserted,4);
    present = ((int)present < 0) ? present : (u32)(inserted == 1);
    if ((int)present < 1) {
      FUN_002b46a8(self,SAVE_STATE_RUN);
    }
    else {
      DAT_003ba329 = '\0';
      FUN_0001c684(&DAT_003b7ebc,1,"common/loading.xb");
      FUN_0001c73c(&DAT_003b7ebc);
      if ((DAT_003b8ec6 != '\0') && (DAT_003ba329 != '\0')) {
        present = FUN_002c74f0("fatms0:",DEVCTL_MEMSTICK_INSERTED,0,0,&inserted2,4);
        present = ((int)present < 0) ? present : (u32)(inserted2 == 1);
        if ((int)present < 1) {
          FUN_002c7628(0x200000);
        }
        FUN_0001c684(&DAT_003b7ebc,1,"common/loading.xb");
        FUN_0001c73c(&DAT_003b7ebc);
      }
      if (DAT_003b8ec6 != 0) {
        FUN_002b46a8(self,SAVE_STATE_MESSAGE);
      }
      else {
        FUN_002b46a8(self,SAVE_STATE_RUN);
      }
    }
  }
  else {
    FUN_002b4648("ERROR: Start(): already started.\n");
  }
}
