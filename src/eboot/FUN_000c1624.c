/* HSTMATCH module=EBOOT.BIN start=0x000c1624 end=0x000c16ac symbol=FUN_000c1624 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern undefined DAT_002c00e8;
extern undefined DAT_002d5a5c;
extern undefined DAT_002d5a6c;
extern undefined DAT_002d5a74;
extern char DAT_002d5a64[];
extern undefined4 * FUN_00011090();
extern uint * FUN_000114c0();

void FUN_000c1624(int param_1)
{
  if (param_1 != 0) {
    FUN_000114c0(param_1,0,0x4c);
    FUN_00011090(param_1 + 0x20,&DAT_002c00e8,0x10);
    *(undefined **)(param_1 + 0x30) = &DAT_002d5a5c;
    *(char **)(param_1 + 0x34) = DAT_002d5a64;
    *(undefined **)(param_1 + 0x38) = &DAT_002d5a6c;
    *(undefined **)(param_1 + 0x3c) = &DAT_002d5a74;
    *(undefined **)(param_1 + 0x40) = &DAT_002d5a74;
    *(undefined4 *)(param_1 + 0x44) = 1;
    *(undefined1 *)(param_1 + 0x48) = 1;
  }
  return;
}
