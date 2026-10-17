/* HSTMATCH module=EBOOT.BIN start=0x00062740 end=0x00062780 symbol=FUN_00062740 lang=c99 */
/* Clone of src/sharing_main/FUN_000635c8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_00072160();

void FUN_00062740(int *param_1)
{
  int iVar1;
  
  if ((param_1[1] < 0) && (*param_1 != 0)) {
    iVar1 = FUN_00072160(*param_1,0);
    param_1[1] = iVar1;
  }
  return;
}
