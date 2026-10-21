/* HSTMATCH module=hstp_trans_main.prx start=0x001b7810 end=0x001b7870 symbol=FUN_001b7810 lang=c99 */
/* Clone of src/eboot/sync_counter_001aa244.c (hstclone.py tag c21rt3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the switch value is read into a local before the pointer temporary is built (that order gives retail's a1/a0 register split); exact match verified; names and types await human review. */
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

extern undefined4 FUN_001aa91c();

void FUN_001b7810(int param_1)
{
  int iVar1;
  int *pp;
  int mode;

  mode = *(int *)(FUN_001aa91c() + 0x2f4);
  pp = (int *)(param_1 + 0xc0);
  switch (mode) {
    case 0:
      iVar1 = *pp;
      *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
      break;
    case 1:
      iVar1 = *pp;
      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x28) + 1;
      break;
    default:
      break;
  }
  return;
}
