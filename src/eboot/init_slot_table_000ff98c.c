/* HSTMATCH module=EBOOT.BIN start=0x000ff98c end=0x000ffa60 symbol=FUN_000ff98c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

#define SLOT_TABLE_COUNT 0x32  /* entries in the handle table */
#define SLOT_NAME_SIZE 0x41    /* bytes per stored name */

extern u8 DAT_002d8a28;
extern u8 DAT_0033b394;
extern u32 DAT_0033b45c;
extern char DAT_0033a6e0[];
extern u32 * FUN_000114c0();
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();

/* Registers a name and a handle in the first free entry of the slot table (clearing the table first when it is empty). */
void FUN_000ff98c(u32 name,u32 handle)
{
  int *entry;
  u32 i;
  int dst;
  
  if (DAT_0033b45c == 0) {
    FUN_000114c0(&DAT_0033b394,0,SLOT_TABLE_COUNT * 4);
  }
  i = 0;
  entry = (int *)&DAT_0033b394;
  do {
    if (*entry == 0) {
      dst = (int)(DAT_0033a6e0 + i * SLOT_NAME_SIZE);
      FUN_000149a8(dst,name);
      FUN_00014788(dst,&DAT_002d8a28);
      *(u32 *)(&DAT_0033b394 + i * 4) = handle;
      DAT_0033b45c = DAT_0033b45c + 1;
      return;
    }
    i = i + 1;
    entry = entry + 1;
  } while (i < SLOT_TABLE_COUNT);
}
