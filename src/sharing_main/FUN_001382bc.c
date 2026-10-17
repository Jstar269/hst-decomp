/* HSTMATCH module=hstp_trans_main.prx start=0x001382bc end=0x0013830c symbol=FUN_001382bc lang=c99 */
/* Clone of src/eboot/FUN_0012ce50.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003da704;
extern undefined4 DAT_003e1a54;
extern int FUN_0005c700();
extern void FUN_0014c118();
extern void FUN_0015142c();

void FUN_001382bc(undefined4 param_1)
{
  if (DAT_003e1a54 != 0) {
    FUN_0005c700(DAT_003e1a54,DAT_003da704);
  }
  FUN_0014c118(param_1);
  FUN_0015142c(param_1);
  return;
}
