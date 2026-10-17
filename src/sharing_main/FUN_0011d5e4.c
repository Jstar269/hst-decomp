/* HSTMATCH module=hstp_trans_main.prx start=0x0011d5e4 end=0x0011d678 symbol=FUN_0011d5e4 lang=c99 */
/* Clone of src/eboot/FUN_001133a8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0a68;
extern undefined DAT_003b100c;
extern undefined DAT_003b101c;
extern void FUN_00000a00();
extern undefined4 * FUN_0010642c();

int * FUN_0011d5e4(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_003b100c;
    *(undefined **)*param_1 = &DAT_003b101c;
    piVar1 = param_1 + 4;
    *(int *)(*param_1 + 0xd0) = (int)piVar1 - *param_1;
    if ((param_2 != 0) && (piVar1 != (int *)0x0)) {
      param_1[4] = (int)&DAT_003b0a68;
      FUN_0010642c(piVar1,0);
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
