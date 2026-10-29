/* HSTMATCH module=EBOOT.BIN start=0x001825ac end=0x001826b8 symbol=FUN_001825ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/indexed_ctx.h"

extern IndexedCtx * FUN_0016bc70();
extern void FUN_001821b0();
extern void FUN_00185970();
extern void FUN_0018629c();

/* Run the context callback and forward all arguments; follow up unless the current entry is 4. */
void FUN_001825ac(u32 self,u32 a1,u32 a2,u32 a3, u32 a4,u32 a5,u32 a6,u32 a7, u8 a8)
{
  IndexedCtx *ctx;
  u32 result;
  
  ctx = FUN_0016bc70();
  result = ctx->callback();
  FUN_001821b0(self,result);
  FUN_00185970(self,a1,a2,a3,a4,a6,a5,0,a7,a8);
  ctx = FUN_0016bc70();
  if (ctx->entries[ctx->index] != INDEXED_CTX_ENTRY_NONE) {
    FUN_0018629c(self,a1,a2,a3,a4,1,a6,a7);
  }
}
