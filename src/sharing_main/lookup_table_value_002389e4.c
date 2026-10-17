/* HSTMATCH module=hstp_trans_main.prx start=0x002389e4 end=0x00238a68 symbol=FUN_002389e4 lang=c99 */
/* Clone of src/eboot/lookup_table_value_00229470.c (hstclone.py tag u5cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reversed the sentinel conditional and indexed through a typed int pointer; exact match verified; names and types await human review. */
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

extern void FUN_00238ddc();

undefined4 FUN_002389e4(int param_1,int param_2,undefined4 param_3)
{
  int iVar2;
  undefined4 local_4;
  int local_c [2];
  
  local_4 = param_3;
  FUN_00238ddc(local_c,param_1,&local_4);
  iVar2 = (local_c[0] != param_1 + 4) ? *(int *)(local_c[0] + 0x10) : -1;
  if ((param_2 != 0) && (iVar2 >= 0)) {
    int offset = iVar2 * 3;
    int *base = *(int **)(param_2 + 0xc);
    return base[offset + 1];
  }
  return 0;
}
