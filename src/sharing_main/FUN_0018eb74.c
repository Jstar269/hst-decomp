/* HSTMATCH module=hstp_trans_main.prx start=0x0018eb74 end=0x0018eca0 symbol=FUN_0018eb74 lang=c99 */
/* Clone of src/eboot/FUN_00182480.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/indexed_ctx.h"

typedef struct Screen {
  char pad00[0x285c];
  u32 handle;       /* 0x285c */
} Screen;

extern void FUN_001118ac();
extern void FUN_00111b58();
extern IndexedCtx * FUN_00177e98();
extern void FUN_0018e8a4();
extern void FUN_001920bc();
extern void FUN_001929e8();

/* Run the context callback, set up the screen's handle and forward all arguments; follow up unless the current entry is 4. */
void FUN_0018eb74(Screen *self,u32 a1,u32 a2,u32 a3, u32 a4,u32 a5,u32 a6,u32 a7, u8 a8)
{
  IndexedCtx *ctx;
  u32 result;
  
  ctx = FUN_00177e98();
  result = ctx->callback();
  FUN_0018e8a4(self,result);
  FUN_001118ac(self->handle,0xd,0x11);
  FUN_00111b58(self->handle,a1,0);
  FUN_001920bc(self,a1,a2,a3,a4,a6,a5,1,a7,a8);
  ctx = FUN_00177e98();
  if (ctx->entries[ctx->index] != INDEXED_CTX_ENTRY_NONE) {
    FUN_001929e8(self,a1,a2,a3,a4,0,a6,a7);
  }
}
