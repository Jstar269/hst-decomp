/* HSTMATCH module=hstp_trans_main.prx start=0x000f3ec0 end=0x000f3f28 symbol=FUN_000f3ec0 lang=c99 */
/* Clone of src/eboot/set_slot_limits_then_chain_000ee7f8.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: FUN_00109024 call regained its dropped second argument (0); exact match verified; names and types await human review. */
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

extern void FUN_000f3f58();
extern void FUN_00108dac();
extern void FUN_00109024();

void FUN_000f3ec0(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(uchar *)(param_1 + 0x54) != '\0') {
    iVar3 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 100);
    iVar1 = *(int *)(param_1 + 0x68);
    *(undefined4 *)(*(int *)(param_1 + 0x5c) + 100) = 0xc1c00000;
    *(undefined4 *)(iVar3 + 100) = 0x41c00000;
    *(undefined4 *)(iVar2 + 100) = 0xc1c00000;
    *(undefined4 *)(iVar1 + 100) = 0x41c00000;
    FUN_00108dac(param_1);
  }
  FUN_000f3f58(param_1);
  FUN_00109024(param_1, 0);
  return;
}
