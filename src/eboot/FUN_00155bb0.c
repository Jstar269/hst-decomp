/* HSTMATCH module=EBOOT.BIN start=0x00155bb0 end=0x00155bf8 symbol=FUN_00155bb0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the flag global typed as a byte and the object address Ghidra dropped from the call restored; exact match verified; names and types await human review. */
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

extern undefined DAT_003402f0;
extern undefined DAT_002dcb78;
extern undefined DAT_0034179c;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001b46bc();

undefined4 FUN_00155bb0(undefined4 param_1,int param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94(&DAT_002dcb78);
  }
  FUN_001b46bc((int *)&DAT_0034179c);
  return 0;
}
