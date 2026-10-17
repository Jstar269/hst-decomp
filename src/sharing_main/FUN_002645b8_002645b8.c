/* HSTMATCH module=hstp_trans_main.prx start=0x002645b8 end=0x00264630 symbol=FUN_002645b8 lang=c99 */
/* Clone of src/eboot/FUN_00254114_00254114.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared the helper integer argument and ordered the counter before the table cursor; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f3acc;
extern undefined DAT_003f468c;
extern void FUN_000006e8();
extern void FUN_00094e8c(int);
extern void FUN_000569f4();

void FUN_002645b8(void)
{
  int iVar2;
  int *piVar1;
  
  iVar2 = 0;
  piVar1 = (int *)&DAT_003f468c;
  do {
    if (*piVar1 != 0) {
      FUN_00094e8c(*piVar1);
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar2 < 4);
  if (DAT_003f3acc != 0) {
    FUN_000006e8(DAT_003f3acc,FUN_000569f4);
    DAT_003f3acc = 0;
  }
  return;
}
