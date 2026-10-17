/* HSTMATCH module=EBOOT.BIN start=0x001c7d30 end=0x001c7df0 symbol=FUN_001c7d30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted readiness guards and typed float/pointer helper arguments; exact match verified; names and types await human review. */
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

extern undefined * DAT_0033b574;
extern char DAT_002eaa14[];
extern char DAT_0034179c[];
extern char * FUN_00014d64();
extern void FUN_001b4848(float,void *);
extern void FUN_001b359c(float,void *);
extern undefined4 FUN_00287418();
extern undefined4 FUN_00287460();

void FUN_001c7d30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined1 param_5)
{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0xd4) = param_2;
  *(undefined4 *)(param_1 + 0xd8) = param_3;
  *(undefined4 *)(param_1 + 0xdc) = param_4;
  *(undefined1 *)(param_1 + 0xe2) = param_5;
  if (DAT_0033b574 != 0) {
    iVar1 = FUN_00287418(DAT_0033b574 + 0x1320);
    if (iVar1 != 0) {
      iVar1 = FUN_00287460(DAT_0033b574 + 0x1320);
      if (iVar1 != 0) {
        iVar1 = (int)(FUN_00014d64(iVar1,DAT_002eaa14));
        *(bool *)(param_1 + 0xe0) = iVar1 != 0;
      }
    } else {
      *(undefined1 *)(param_1 + 0xe0) = 0;
    }
  } else {
    *(undefined1 *)(param_1 + 0xe0) = 0;
  }
  FUN_001b4848(0.2f,DAT_0034179c);
  FUN_001b359c(0.2f,DAT_0034179c);
  *(undefined4 *)(param_1 + 0xc4) = 3;
  *(undefined4 *)(param_1 + 200) = 0;
  return;
}
