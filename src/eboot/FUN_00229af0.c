/* HSTMATCH module=EBOOT.BIN start=0x00229af0 end=0x00229b94 symbol=FUN_00229af0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q2); exact match verified; names and types await human review. */
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

extern undefined1 DAT_002f2b57;
extern undefined1 DAT_002f2b58;
extern undefined4 * FUN_00229bf0();
extern undefined4 * FUN_0022a368();

void FUN_00229af0(int *param_1,undefined4 param_2,uint *param_3)
{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_1;
  undefined1 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_00229bf0(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(uint *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_0022a368(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(undefined1 *)(param_1 + 1) = DAT_002f2b57;
  }
  else {
    *param_1 = local_8;
    *(undefined1 *)(param_1 + 1) = DAT_002f2b58;
  }
  return;
}
