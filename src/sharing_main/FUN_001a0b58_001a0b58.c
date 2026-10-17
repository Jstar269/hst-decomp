/* HSTMATCH module=hstp_trans_main.prx start=0x001a0b58 end=0x001a0bbc symbol=FUN_001a0b58 lang=c99 */
/* Clone of src/eboot/FUN_00194348_00194348.c (hstclone.py tag u4r1-3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern undefined4 DAT_003eaa70;
extern undefined4 DAT_003eaa74;
extern undefined4 DAT_003eaa78;
extern undefined4 DAT_003eaa7c;
extern undefined4 DAT_003eaa80;

undefined4 FUN_001a0b58(void)
{
  if (DAT_003eaa74 == 0) goto zero;
  if (DAT_003eaa70 == 0) goto zero;
  if (DAT_003eaa80 == 0) goto zero;
  if (DAT_003eaa7c == 0) goto zero;
  if (DAT_003eaa78 == 0) goto zero;
  return 1;
zero:
  return 0;
}
