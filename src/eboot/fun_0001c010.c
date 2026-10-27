/* HSTMATCH module=EBOOT.BIN start=0x0001c010 end=0x0001c0fc symbol=FUN_0001c010 lang=c99 data=0x002cfc10 */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: removed cc=gcc171-Os (retail is MWCC), typed 60.0f float literal for FUN_00062150, reordered *(uchar *)(param_1 + 0x1009) != 0 branch first, and added callback null check; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002cfc10-0x002cfc22) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined4 DAT_0030ebd0;
extern void FUN_0001b918(char *, int);
extern int FUN_0001be84(int, int, int);
extern void FUN_0001c104(int *);
extern int FUN_000464ec(void);
extern void FUN_00062150(float param_1);
extern void FUN_002b78f0(void);
extern void FUN_002b7a78(void);

int FUN_0001c010(int *param_1, int param_2, uchar param_3)
{
  int iVar1;
  
  FUN_002b78f0();
  FUN_0001c104(param_1);
  FUN_0001b918("openBinder(\"%s\")\n", param_2);
  *(uchar *)(param_1 + 0x1009) = param_3;
  if (*(uchar *)(param_1 + 0x1009) != 0) {
    *param_1 = param_2;
    DAT_0030ebd0 = 0x7fffffff;
  }
  else {
    *param_1 = FUN_0001be84(param_2, param_1[6], param_1[7]);
  }
  if ((*param_1 != 0) && ((void (*)(void))param_1[0x100a] != 0)) {
    ((void (*)(void))param_1[0x100a])();
  }
  if (FUN_000464ec() != 0) {
    for (iVar1 = 0; iVar1 < 3; iVar1++) {
      FUN_00062150(60.0f);
      FUN_002b7a78();
    }
  }
  return *param_1 != 0;
}
