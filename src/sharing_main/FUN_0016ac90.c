/* HSTMATCH module=hstp_trans_main.prx start=0x0016ac90 end=0x0016acf0 symbol=FUN_0016ac90 lang=c99 */
/* Clone of src/eboot/FUN_0015e704.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003751d4;
extern void FUN_0001e7ac();
extern void FUN_0001eb84();
extern bool FUN_0001eb98();
extern void FUN_0016acf0();

void FUN_0016ac90(undefined4 param_1)
{
  uchar cVar1;
  
  cVar1 = FUN_0001eb98();
  if (cVar1 != '\0') {
    FUN_0001eb84();
  }
  FUN_0016acf0(param_1,DAT_003751d4);
  if (cVar1 != '\0') {
    FUN_0001e7ac();
  }
  return;
}
