/* HSTMATCH module=EBOOT.BIN start=0x002199c8 end=0x00219a50 symbol=FUN_002199c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0391_002199c8_m15.c), then corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/particle_sys.h"

extern void FUN_00051490();
extern void FUN_0005185c();
extern void FUN_0005a770();

/* Draw pass: begins the view (480x272 target), draws every particle, ends the view. */
void FUN_002199c8(ParticleSys *sys)
{
  int i;
  int offset;
  
  FUN_00051490(sys->view,0,0,0x1e0,0x110,0,0);
  i = 0;
  offset = 0;
  do {
    FUN_0005a770(sys->parts + offset,sys->view,0,0);
    i = i + 1;
    offset = offset + PARTICLE_SIZE;
  } while (i < PARTICLE_COUNT);
  FUN_0005185c(sys->view);
}
