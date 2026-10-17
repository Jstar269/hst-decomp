/* HSTMATCH module=hstp_trans_main.prx start=0x001070cc end=0x00107170 symbol=FUN_001070cc lang=c99 */
/* Clone of src/eboot/FUN_001016f4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00107170();
extern void FUN_0010cf34();

void FUN_001070cc(int param_1,undefined4 *param_2,uint param_3)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(uint *)(param_1 + 0x18) < param_3)) {
    FUN_0010cf34(param_1 + 0x10,param_3);
  }
  iVar1 = 0;
  if (0 < (int)param_3) {
    do {
      FUN_00107170(param_1,*param_2,param_2[2],0,0,0xffffffff,0x80808080);
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 3;
    } while (iVar1 < (int)param_3);
  }
  return;
}
