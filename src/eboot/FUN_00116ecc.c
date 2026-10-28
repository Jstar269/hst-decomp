/* HSTMATCH module=EBOOT.BIN start=0x00116ecc end=0x00116f98 symbol=FUN_00116ecc lang=c99 data=0x002d9384 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002d9384-0x002d93e1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_00307fa8;
extern u32 * FUN_000114c0();
extern u32 * FUN_0001f06c();
extern void FUN_00116f98();
extern void FUN_00117020();

u32 * FUN_00116ecc(u32 *param_1)
{
  u32 *puVar1;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00307fa8);
  param_1[0xf] = 4;
  *(u8 *)(param_1 + 0x10) = 0;
  puVar1 = param_1 + 0x20;
  do {
    puVar1[0xb] = 1;
    FUN_000114c0(puVar1,0,0x40);
    puVar1[0x10] = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    puVar1[0x16] = 0;
    puVar1[0x17] = 0;
    *(u8 *)(puVar1 + 0x18) = 0;
    *(u8 *)((int)puVar1 + 0x61) = 0;
    puVar1 = puVar1 + 0x1c;
  } while (puVar1 < param_1 + 0x11c);
  FUN_00116f98("Replay sizeof(m_Shot)   %7d\n",0x3f0);
  FUN_00116f98("Replay sizeof(m_Player) %7d\n",0x90);
  FUN_00116f98("Replay sizeof(m_Common) %7d\n",0x24);
  FUN_00117020(param_1);
  return param_1;
}
