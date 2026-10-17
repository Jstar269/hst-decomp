/* HSTMATCH module=EBOOT.BIN start=0x00229470 end=0x002294f4 symbol=FUN_00229470 lang=c99 */
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

extern void FUN_00229868();

undefined4 FUN_00229470(int param_1,int param_2,undefined4 param_3)
{
  int iVar2;
  undefined4 local_4;
  int local_c [2];
  
  local_4 = param_3;
  FUN_00229868(local_c,param_1,&local_4);
  iVar2 = (local_c[0] != param_1 + 4) ? *(int *)(local_c[0] + 0x10) : -1;
  if ((param_2 != 0) && (iVar2 >= 0)) {
    int offset = iVar2 * 3;
    int *base = *(int **)(param_2 + 0xc);
    return base[offset + 1];
  }
  return 0;
}
