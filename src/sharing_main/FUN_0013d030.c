/* HSTMATCH module=hstp_trans_main.prx start=0x0013d030 end=0x0013d10c symbol=FUN_0013d030 lang=c99 rodata=0x002d19a4 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
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


int FUN_0013d030(int param_1,undefined4 param_2)
{
  int iVar1;
  float *pfVar2;
  float local_4;
  float local_8;
  
  switch(param_2) {
  case 0:
    iVar1 = 0;
    break;
  case 1:
    iVar1 = *(int *)(param_1 + 0xb0);
    if (0x32 < iVar1) {
      iVar1 = 0;
    }
    break;
  case 2:
    iVar1 = *(int *)(*(int *)(param_1 + 0x80) + 0x90);
    break;
  case 3:
    iVar1 = *(int *)(param_1 + 0xb4);
    break;
  case 4:
    iVar1 = *(int *)(param_1 + 0x90);
    break;
  case 5:
    iVar1 = *(int *)(param_1 + 0xd0);
    break;
  case 6:
    local_8 = (float)*(int *)(param_1 + 0xb4) - 8.0f;
    local_4 = (float)*(int *)(param_1 + 0xd0) - 30.0f;
    if (local_8 < local_4) {
      pfVar2 = &local_8;
    }
    else {
      pfVar2 = &local_4;
    }
    iVar1 = (int)*pfVar2;
    break;
  case 7:
    iVar1 = *(int *)(param_1 + 0x100);
    break;
  default:
    iVar1 = 0;
  }
  return iVar1;
}
