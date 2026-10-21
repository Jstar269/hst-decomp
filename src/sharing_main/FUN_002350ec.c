/* HSTMATCH module=hstp_trans_main.prx start=0x002350ec end=0x002351a8 symbol=FUN_002350ec lang=c99 rodata=0x002d9fc4 */
/* Clone of src/eboot/FUN_00225b78.c (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003eaad8;
extern char DAT_0039964c[];
extern char DAT_0039965c[];
extern char DAT_0039966c[];
extern char DAT_0039967c[];
extern char DAT_0039968c[];
extern void FUN_001c0984();

void FUN_002350ec(undefined4 param_1,undefined4 param_2)
{
  switch(param_2) {
  case 0:
  case 2:
  case 3:
  case 9:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039964c);
    break;
  case 1:
  case 4:
  case 5:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039965c);
    break;
  case 6:
  case 7:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039966c);
    break;
  case 8:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039967c);
    break;
  case 10:
    FUN_001c0984((int)&DAT_003eaad8,DAT_0039968c);
  }
  return;
}
