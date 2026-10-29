/* HSTMATCH module=EBOOT.BIN start=0x001fd060 end=0x001fd0e4 symbol=FUN_001fd060 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00331c30;
extern u32 DAT_0034a13c;  /* the live regulation screen */
extern int FUN_00000bcc();
extern u32 * FUN_001fd180();
extern void FUN_001fd46c();
extern void FUN_001fd7e8();

#define REGULATION_SCREEN_SIZE 0x1350

/* Creates the regulation screen, enables it and loads the record `record_id`. */
void FUN_001fd060(u32 arg,u32 record_id)
{
  int screen;
  
  DAT_00331c30 = 0xbc75c28f;
  screen = FUN_00000bcc(REGULATION_SCREEN_SIZE);
  if (screen != 0) {
    FUN_001fd180(screen,arg);
  }
  FUN_001fd46c(DAT_0034a13c,1,1);
  FUN_001fd7e8(DAT_0034a13c,record_id,0,0);
}
