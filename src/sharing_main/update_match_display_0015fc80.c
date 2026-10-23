/* HSTMATCH module=hstp_trans_main.prx start=0x0015fc80 end=0x0015fd14 symbol=FUN_0015fc80 lang=c99 */
/* Clone of src/eboot/update_match_display_00153a18.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: keep status as int and put success work inside the zero-status arm. */
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

extern void *DAT_003f344c;
extern char DAT_00383cb0[];
extern void FUN_000143b0(char *, const char *, uint);
extern uint *FUN_00157e10(uint, uint);
extern void FUN_001daeb8(void *, void *);
extern int FUN_001db8a4(void *);
extern uint FUN_001db960(void *);

bool FUN_0015fc80(int param_1,undefined4 *param_2)
{
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  char auStack_20 [32];
  
  if (FUN_001db8a4(DAT_003f344c) == 0) {
    uVar4 = *param_2;
    uVar2 = FUN_001db960(DAT_003f344c) & 0xff;
    puVar3 = (uint *)FUN_00157e10(uVar4,*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
    *puVar3 = uVar2;
    FUN_000143b0(auStack_20,DAT_00383cb0,*(undefined4 *)(*(int *)(param_1 + 4) + 8));
    FUN_001daeb8(DAT_003f344c,auStack_20);
    return true;
  }
  return false;
}
