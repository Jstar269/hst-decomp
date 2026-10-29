/* HSTMATCH module=EBOOT.BIN start=0x001b37f4 end=0x001b38dc symbol=FUN_001b37f4 lang=c99 data=0x002e950c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the two module addresses written as &DAT_0030ab9c / &DAT_0030ebf4 (lui/addiu, not lui/ori); readability pass; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002e950c-0x002e9543) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern u8 DAT_0030ab9c;
extern u8 DAT_0030ebf4;
extern u8 DAT_002e58d4;
extern u8 DAT_002e58d8;
extern int FUN_00010184();
extern void FUN_000104e0();
extern void FUN_0001bfb4();
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern int FUN_0001cbfc();
extern u32 FUN_0001cc54();
extern void FUN_001b06d4();

#define SCRATCH_SIZE 0x100000
#define SCRATCH_ALIGN 0x40

/* Load the two menu sound banks through a temporary 1 MiB scratch buffer, then give the buffer back. */
void FUN_001b37f4(SlotTable **ref)
{
  u32 scratch;
  u32 prev_size;
  u32 table;
  u32 prev_buf;

  table = (u32)*ref;
  scratch = FUN_00010184(SCRATCH_ALIGN,SCRATCH_SIZE);
  FUN_0001bfb4(&DAT_0030ab9c,scratch,SCRATCH_SIZE);
  FUN_0001ca58(&DAT_0030ebf4,"sound/menu/000_common_0.xb");
  FUN_001b06d4(table,&DAT_002e58d4,1,0);
  FUN_0001cb88(&DAT_0030ebf4);
  FUN_0001ca58(&DAT_0030ebf4,"sound/menu/000_common_1.xb");
  FUN_001b06d4(table,&DAT_002e58d8,3,0);
  FUN_0001cb88(&DAT_0030ebf4);
  prev_buf = FUN_0001cbfc();
  prev_size = FUN_0001cc54();
  FUN_0001bfb4(&DAT_0030ab9c,prev_buf,prev_size);
  FUN_000104e0(scratch);
}
