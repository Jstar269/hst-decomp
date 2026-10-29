/* HSTMATCH module=hstp_trans_main.prx start=0x00102320 end=0x00102388 symbol=FUN_00102320 lang=c99 data=0x0037f1a0 */
/* Clone of src/eboot/FUN_000fcbe4.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037f1a0-0x0037f1c8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the propagated default constant undone and the strength-reduced sizes written as multiplies; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

#define DEFAULT_FILE_COUNT 0xa8c
#define INDEX_ENTRY_SIZE 0x14
#define INDEX_HEADER_SIZE 0x18

extern u32 DAT_003e39a4;
extern u32 DAT_003e39ac;
extern int FUN_00000a90();
extern int FUN_000104b0();
extern void FUN_00102388();

void FUN_00102320(int count)
{
  if (count == 0) {
    count = DEFAULT_FILE_COUNT;
  }
  DAT_003e39a4 = FUN_000104b0(count * INDEX_ENTRY_SIZE + INDEX_HEADER_SIZE);
  DAT_003e39ac = FUN_00000a90(count * 4);
  FUN_00102388("GameData::CreateFileTable(): size = %u\n",count);
}
