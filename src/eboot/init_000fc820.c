/* HSTMATCH module=EBOOT.BIN start=0x000fc820 end=0x000fc91c symbol=FUN_000fc820 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: sum written as `iVar2 + FUN_00004b74()`, buffer address as &DAT_00338c40 (lui/addiu), the two globals loaded into locals in retail order (DAT_0032b244 before DAT_0032b24c); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272
#define ALIGN_BYTES 0x200

extern u8 DAT_00338c40;
extern u32 DAT_00310fc0;
extern int DAT_0032b244;
extern u32 DAT_0032b248;
extern u32 DAT_0032b24c;
extern int FUN_000045d8();
extern u32 FUN_00004b74();
extern void FUN_00004c3c();
extern void FUN_00004f44();
extern u32 FUN_00004f60();
extern u32 FUN_00004fcc();
extern void FUN_00005104();
extern void FUN_0000515c();
extern void FUN_00005170();
extern void FUN_00005180();
extern void FUN_00005190();
extern void FUN_000051b8();
extern void FUN_0000527c();
extern void FUN_002b78f0();
extern int FUN_002b7a50();
extern void FUN_002b7a78();

void FUN_000fc820(void)
{
  u32 region;
  int total;
  int used;
  
  FUN_002b78f0();
  FUN_00004f60(0,0);
  FUN_002b7a78();
  DAT_0032b248 = DAT_00310fc0;
  total = FUN_002b7a50();
  DAT_00310fc0 = total + FUN_00004b74();
  DAT_0032b244 = DAT_00310fc0;
  FUN_00004fcc(1);
  FUN_000045d8(0,&DAT_00338c40,0x1000);
  total = DAT_0032b244;
  region = DAT_0032b24c;
  used = FUN_002b7a50();
  FUN_00004c3c(region,total - used,ALIGN_BYTES);
  FUN_000051b8(0x710,0x778);
  FUN_0000527c(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
  FUN_00005104(2);
  FUN_0000515c(0);
  FUN_00005180(0);
  FUN_00005170(0);
  FUN_00005190(0x17);
  FUN_00004f44();
}
