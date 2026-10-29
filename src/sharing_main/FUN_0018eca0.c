/* HSTMATCH module=hstp_trans_main.prx start=0x0018eca0 end=0x0018edac symbol=FUN_0018eca0 lang=c99 */
/* Clone of src/eboot/FUN_001825ac.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/indexed_ctx.h"

extern IndexedCtx * FUN_00177e98();
extern void FUN_0018e8a4();
extern void FUN_001920bc();
extern void FUN_001929e8();

/* Run the context callback and forward all arguments; follow up unless the current entry is 4. */
void FUN_0018eca0(u32 self,u32 a1,u32 a2,u32 a3, u32 a4,u32 a5,u32 a6,u32 a7, u8 a8)
{
  IndexedCtx *ctx;
  u32 result;
  
  ctx = FUN_00177e98();
  result = ctx->callback();
  FUN_0018e8a4(self,result);
  FUN_001920bc(self,a1,a2,a3,a4,a6,a5,0,a7,a8);
  ctx = FUN_00177e98();
  if (ctx->entries[ctx->index] != INDEXED_CTX_ENTRY_NONE) {
    FUN_001929e8(self,a1,a2,a3,a4,1,a6,a7);
  }
}
