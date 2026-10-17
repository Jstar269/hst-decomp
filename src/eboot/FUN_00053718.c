/* HSTMATCH module=EBOOT.BIN start=0x00053718 end=0x000537a0 symbol=FUN_00053718 lang=c99 */
/* Clone of src/sharing_main/FUN_000541d8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00000a00();
extern void FUN_00053a38();
extern int * FUN_00054554();
extern int * FUN_00054600();

int FUN_00053718(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_00053a38();
    iVar1 = param_1 + 0x24;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_00054600(iVar1,0);
    }
    iVar1 = param_1 + 0x18;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_00054554(iVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
