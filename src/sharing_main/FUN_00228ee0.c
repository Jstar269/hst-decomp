/* HSTMATCH module=hstp_trans_main.prx start=0x00228ee0 end=0x00228f68 symbol=FUN_00228ee0 lang=c99 */
/* Clone of src/eboot/FUN_002199c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/particle_sys.h"

extern void FUN_00051e30();
extern void FUN_000522c0();
extern void FUN_0005b540();

/* Draw pass: begins the view (480x272 target), draws every particle, ends the view. */
void FUN_00228ee0(ParticleSys *sys)
{
  int i;
  int offset;
  
  FUN_00051e30(sys->view,0,0,0x1e0,0x110,0,0);
  i = 0;
  offset = 0;
  do {
    FUN_0005b540(sys->parts + offset,sys->view,0,0);
    i = i + 1;
    offset = offset + PARTICLE_SIZE;
  } while (i < PARTICLE_COUNT);
  FUN_000522c0(sys->view);
}
