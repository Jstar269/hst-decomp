/* HSTMATCH module=hstp_trans_main.prx start=0x001b1df0 end=0x001b1e70 symbol=FUN_001b1df0 lang=c99 */
/* Clone of src/eboot/FUN_001a4824.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_001772d4();
extern int FUN_00177720();

undefined4 FUN_001b1df0(undefined4 param_1,int param_2)
{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar1 = FUN_001772d4();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if ((iVar3 == param_2) && (pbVar2 = (byte *)FUN_00177720(iVar3), (unsigned int)(*pbVar2 - 4) < 2)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return 0;
}
