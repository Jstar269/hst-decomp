/* HSTMATCH module=EBOOT.BIN start=0x001a4824 end=0x001a48a4 symbol=FUN_001a4824 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the range check made unsigned; exact match verified; names and types await human review. */
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

extern undefined4 FUN_0016b110();
extern int FUN_0016b55c();

undefined4 FUN_001a4824(undefined4 param_1,int param_2)
{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar1 = FUN_0016b110();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if ((iVar3 == param_2) && (pbVar2 = (byte *)FUN_0016b55c(iVar3), (unsigned int)(*pbVar2 - 4) < 2)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return 0;
}
