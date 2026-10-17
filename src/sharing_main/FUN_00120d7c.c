/* HSTMATCH module=hstp_trans_main.prx start=0x00120d7c end=0x00120e40 symbol=FUN_00120d7c lang=c99 */
/* Clone of src/eboot/FUN_00115e60.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined DAT_003b11d0;
extern undefined DAT_003b11e4;
extern undefined DAT_003b122c;
extern void FUN_00000a00();
extern undefined4 * FUN_0010642c();
extern int * FUN_0010d2d4();

int * FUN_00120d7c(int *param_1,int param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    param_1[1] = (int)&DAT_003b11d0;
    *(undefined **)*param_1 = &DAT_003b11e4;
    *(int *)(*param_1 + 0x130) = (int)(param_1 + 0x1c) - *param_1;
    if ((param_2 != 0) && (param_1 + 0x1c != (int *)0x0)) {
      piVar1 = param_1 + 100;
      param_1[0x1c] = (int)&DAT_003b122c;
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_0010d2d4(piVar1,0);
      }
      if (param_1 + 0x1c != (int *)0x0) {
        param_1[0x1c] = (int)&DAT_003b0a68;
        FUN_0010642c(param_1 + 0x1c,0);
      }
    }
    if (0 < (short)param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
