/* HSTMATCH module=EBOOT.BIN start=0x00116ecc end=0x00116f98 symbol=FUN_00116ecc lang=c99 */
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

extern undefined DAT_00307fa8;
extern char DAT_002d9384[];
extern char DAT_002d93a4[];
extern char DAT_002d93c4[];
extern uint * FUN_000114c0();
extern undefined4 * FUN_0001f06c();
extern void FUN_00116f98();
extern void FUN_00117020();

undefined4 * FUN_00116ecc(undefined4 *param_1)
{
  undefined4 *puVar1;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00307fa8);
  param_1[0xf] = 4;
  *(undefined1 *)(param_1 + 0x10) = 0;
  puVar1 = param_1 + 0x20;
  do {
    puVar1[0xb] = 1;
    FUN_000114c0(puVar1,0,0x40);
    puVar1[0x10] = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    puVar1[0x16] = 0;
    puVar1[0x17] = 0;
    *(undefined1 *)(puVar1 + 0x18) = 0;
    *(undefined1 *)((int)puVar1 + 0x61) = 0;
    puVar1 = puVar1 + 0x1c;
  } while (puVar1 < param_1 + 0x11c);
  FUN_00116f98(DAT_002d9384,0x3f0);
  FUN_00116f98(DAT_002d93a4,0x90);
  FUN_00116f98(DAT_002d93c4,0x24);
  FUN_00117020(param_1);
  return param_1;
}
