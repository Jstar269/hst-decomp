/* HSTMATCH module=EBOOT.BIN start=0x00047620 end=0x00047698 symbol=FUN_00047620 lang=c99 */
/* Clone of src/sharing_main/FUN_00047aa4_00047aa4.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: reversed the zero/nonzero call arms and typed the byte global; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_002d0220;
extern unsigned char DAT_00311054;
extern undefined DAT_003386b8;
extern void FUN_002b7d40();

void FUN_00047620(int param_1)
{
  if ((DAT_002d0220 == 1) && (DAT_003386b8 != '\0')) {
    param_1 = 0;
  }
  if (param_1 != 0) {
    FUN_002b7d40(0x14d,0x14d,0xa6);
  }
  else {
    FUN_002b7d40(0xde,0xde,0x6f);
  }
  DAT_00311054 = (char)param_1;
  return;
}
