/* HSTMATCH module=EBOOT.BIN start=0x00050d8c end=0x00050dd0 symbol=FUN_00050d8c lang=c99 */
/* Clone of src/sharing_main/FUN_000516a0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_00004f60();
extern void FUN_00049194();
extern void FUN_000491cc();
extern void FUN_00050dd0();
extern void FUN_0005a340();

void FUN_00050d8c(undefined4 param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_00050dd0();
  }
  FUN_00049194();
  FUN_00004f60(0,0);
  FUN_000491cc();
  FUN_0005a340();
  return;
}
