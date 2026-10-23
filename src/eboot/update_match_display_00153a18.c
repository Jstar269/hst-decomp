/* HSTMATCH module=EBOOT.BIN start=0x00153a18 end=0x00153aac symbol=FUN_00153a18 lang=c99 */
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

extern void *DAT_0034a114;
extern char DAT_002dc7c8[];
extern void FUN_000143b0(char *, const char *, uint);
extern uint *FUN_0014c384(uint, uint);
extern void FUN_001cc784(void *, void *);
extern int FUN_001cd13c(void *);
extern uint FUN_001cd284(void *);

bool FUN_00153a18(int param_1,undefined4 *param_2)
{
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  char auStack_20 [32];
  
  if (FUN_001cd13c(DAT_0034a114) == 0) {
    uVar4 = *param_2;
    uVar2 = FUN_001cd284(DAT_0034a114) & 0xff;
    puVar3 = (uint *)FUN_0014c384(uVar4,*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
    *puVar3 = uVar2;
    FUN_000143b0(auStack_20,DAT_002dc7c8,*(undefined4 *)(*(int *)(param_1 + 4) + 8));
    FUN_001cc784(DAT_0034a114,auStack_20);
    return true;
  }
  return false;
}
