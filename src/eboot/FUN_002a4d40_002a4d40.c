/* HSTMATCH module=EBOOT.BIN start=0x002a4d40 end=0x002a4eb8 symbol=FUN_002a4d40 lang=c99 data=0x003007b4 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte globals and module address, retained the signed result in a ternary, and reversed the final state arms; readability pass; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003007b4-0x003007f2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/savedata_screen.h"

extern unsigned char DAT_0030fbfe;
extern unsigned char DAT_00311029;
extern unsigned char DAT_0030ebf4;
extern void FUN_0001cad0();
extern void FUN_0001cb88();
extern void FUN_002a4eb8();
extern void FUN_002a4f18();
extern int FUN_002b7710();
extern void FUN_002b7888();

#define DEVCTL_MEMSTICK_INSERTED 0x2425823 /* device control code: is a memory stick present */

/* Start the screen: check for a memory stick (showing the loading screen), then pick the first state. */
void FUN_002a4d40(SaveScreen *self)
{
  u32 present;
  int inserted;
  int inserted2;
  
  if (self->state == SAVE_STATE_IDLE) {
    present = FUN_002b7710("fatms0:",DEVCTL_MEMSTICK_INSERTED,0,0,&inserted,4);
    present = ((int)present < 0) ? present : (u32)(inserted == 1);
    if ((int)present < 1) {
      FUN_002a4f18(self,SAVE_STATE_RUN);
    }
    else {
      DAT_00311029 = '\0';
      FUN_0001cad0(&DAT_0030ebf4,1,"common/loading.xb");
      FUN_0001cb88(&DAT_0030ebf4);
      if ((DAT_0030fbfe != '\0') && (DAT_00311029 != '\0')) {
        present = FUN_002b7710("fatms0:",DEVCTL_MEMSTICK_INSERTED,0,0,&inserted2,4);
        present = ((int)present < 0) ? present : (u32)(inserted2 == 1);
        if ((int)present < 1) {
          FUN_002b7888(0x200000);
        }
        FUN_0001cad0(&DAT_0030ebf4,1,"common/loading.xb");
        FUN_0001cb88(&DAT_0030ebf4);
      }
      if (DAT_0030fbfe != 0) {
        FUN_002a4f18(self,SAVE_STATE_MESSAGE);
      }
      else {
        FUN_002a4f18(self,SAVE_STATE_RUN);
      }
    }
  }
  else {
    FUN_002a4eb8("ERROR: Start(): already started.\n");
  }
}
