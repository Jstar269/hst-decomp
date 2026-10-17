/* HSTMATCH module=hstp_trans_main.prx start=0x00097064 end=0x000970ec symbol=FUN_00097064 lang=c99 */
/* Clone of src/eboot/FUN_00095058.c (hstclone.py tag u3r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: keep the two return blocks in the order ret1,ret0 (declare ret1 first) and end the function with an explicit `goto ret0` as the false-path fall-through; param_5 and the compared byte are unsigned char (andi/lbu). */
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

extern int FUN_000970ec();

int FUN_00097064(int param_1,int param_2,int param_3,unsigned int param_4,unsigned char param_5)
{
  int iVar1;

  if (*(int *)(param_1 + 0x1b0) == param_2) {
    if (*(int *)(param_1 + 0x1b4) == param_3) {
      iVar1 = FUN_000970ec(param_1,param_4);
      if (iVar1 != 0) {
        if (*(unsigned char *)(param_1 + 0x1ba) == param_5) {
          goto ret1;
        }
        if (*(int *)(param_1 + 0x1b0) == 0) {
          goto ret1;
        }
        if (*(int *)(param_1 + 0x1b0) != 5) {
          goto ret0;
        }
        goto ret1;
      }
    }
  }
  goto ret0;
ret1:
  return 1;
ret0:
  return 0;
}
