/* HSTMATCH module=hstp_trans_main.prx start=0x001b1a18 end=0x001b1a70 symbol=FUN_001b1a18 lang=c99 */
/* Clone of src/eboot/set_current_id_001a444c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: FUN_00177c64 takes an int first parameter (no seh, the short cast dropped); exact match verified; names and types await human review. */
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

extern int FUN_001776f8(void);
extern void FUN_00177c64(int param_1,undefined1 param_2);

void FUN_001b1a18(int param_1)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = **(int **)(*(int *)(param_1 + 900) + *(int *)(param_1 + 0x300) * 4);
  bVar1 = iVar2 == -1;
  if (bVar1) {
    iVar2 = FUN_001776f8();
  }
  FUN_00177c64(iVar2,(undefined1)(bVar1));
  return;
}
