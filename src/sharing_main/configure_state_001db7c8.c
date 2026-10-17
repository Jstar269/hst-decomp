/* HSTMATCH module=hstp_trans_main.prx start=0x001db7c8 end=0x001db840 symbol=FUN_001db7c8 lang=c99 */
/* Clone of src/eboot/configure_state_001cd060.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a signed status test and passed the third helper argument through the byte store; exact match verified; names and types await human review. */
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

extern int DAT_003f48d0;
extern void FUN_001d06dc();
extern void FUN_001dbf68();
extern void FUN_002bd0f4();

void FUN_001db7c8(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  FUN_002bd0f4();
  if (DAT_003f48d0 > 0) {
    iVar2 = *(int *)(param_1 + 0x15c);
    *(undefined4 *)(iVar2 + 0xe0) = 0;
    *(undefined1 *)(iVar2 + 0xe4) = 1;
    FUN_001dbf68(iVar2,7,1);
    FUN_001d06dc(iVar2);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x15c);
    FUN_001dbf68(uVar1,0xb,1);
    FUN_001d06dc(uVar1);
  }  return;
}
