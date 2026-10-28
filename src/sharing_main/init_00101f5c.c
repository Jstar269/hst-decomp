/* HSTMATCH module=hstp_trans_main.prx start=0x00101f5c end=0x00102058 symbol=FUN_00101f5c lang=c99 */
/* Clone of src/eboot/init_000fc820.c (hstclone.py tag c41): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: sum written as `iVar2 + FUN_00004b74()`, buffer address as &DAT_003e1f80 (lui/addiu), the two globals loaded into locals in retail order (DAT_003d4584 before DAT_003d458c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003e1f80;
extern u32 DAT_003ba2c0;
extern int DAT_003d4584;
extern u32 DAT_003d4588;
extern u32 DAT_003d458c;
extern int FUN_000045d8();
extern u32 FUN_00004b74();
extern void FUN_00004c3c();
extern void FUN_00004f44();
extern u32 FUN_00004f78();
extern u32 FUN_00004fe4();
extern void FUN_0000511c();
extern void FUN_00005174();
extern void FUN_00005188();
extern void FUN_00005198();
extern void FUN_000051a8();
extern void FUN_000051d0();
extern void FUN_00005294();
extern void FUN_002c7690();
extern int FUN_002c77f0();
extern void FUN_002c7818();

void FUN_00101f5c(void)
{
  u32 uVar1;
  int iVar2;
  int iVar3;
  
  FUN_002c7690();
  FUN_00004f78(0,0);
  FUN_002c7818();
  DAT_003d4588 = DAT_003ba2c0;
  iVar2 = FUN_002c77f0();
  DAT_003ba2c0 = iVar2 + FUN_00004b74();
  DAT_003d4584 = DAT_003ba2c0;
  FUN_00004fe4(1);
  FUN_000045d8(0,&DAT_003e1f80,0x1000);
  iVar2 = DAT_003d4584;
  uVar1 = DAT_003d458c;
  iVar3 = FUN_002c77f0();
  FUN_00004c3c(uVar1,iVar2 - iVar3,0x200);
  FUN_000051d0(0x710,0x778);
  FUN_00005294(0,0,0x1e0,0x110);
  FUN_0000511c(2);
  FUN_00005174(0);
  FUN_00005198(0);
  FUN_00005188(0);
  FUN_000051a8(0x17);
  FUN_00004f44();
}
