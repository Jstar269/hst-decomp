/* HSTMATCH module=hstp_trans_main.prx start=0x001c6a24 end=0x001c6a94 symbol=FUN_001c6a24 lang=c99 */
/* Clone of src/eboot/FUN_001b8d38.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: kept `this` in its own local (s1) and the +0x3c sub-object in a second (s0) so the object survives the calls, passed `this` as the base constructor argument, sub-object access as pointer arithmetic; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern undefined1 DAT_003b258c;
extern void FUN_0001ec44();
extern undefined4 *FUN_001c73f4();
extern void FUN_001c71e4();

undefined4 *FUN_001c6a24(undefined4 *param_1)
{
  undefined1 auStack_4[4];
  undefined4 local_8;
  undefined4 *local_c;
  undefined4 *self = param_1;
  undefined4 *sub;

  FUN_0001ec44(self);
  sub = self + 0xf;
  FUN_001c73f4(sub);
  ((undefined1 *)sub)[12] = 0;
  local_c = sub + 1;
  local_8 = sub[2];
  FUN_001c71e4(auStack_4, sub, &local_8, &local_c);
  *self = (unsigned int)(&DAT_003b258c);
  return self;
}
