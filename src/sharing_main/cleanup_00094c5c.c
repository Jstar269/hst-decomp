/* HSTMATCH module=hstp_trans_main.prx start=0x00094c5c end=0x00094cb0 symbol=FUN_00094c5c lang=c99 */
/* Clone of src/eboot/cleanup_00092dc8.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: test the first field directly before loading the second; exact match verified; names and types await human review. */
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

extern int FUN_000569f4();
extern void FUN_00057fa0();

void FUN_00094c5c(int param_1)
{
  int iVar1;

  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00057fa0(*(int *)(param_1 + 0x58));
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 != 0) {
    FUN_000569f4(iVar1,1);
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  return;
}
