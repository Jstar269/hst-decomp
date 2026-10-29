/* HSTMATCH module=EBOOT.BIN start=0x00182480 end=0x001825ac symbol=FUN_00182480 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/indexed_ctx.h"

typedef struct Screen {
  char pad00[0x285c];
  u32 handle;       /* 0x285c */
} Screen;

extern void FUN_0010b6d4();
extern void FUN_0010b980();
extern IndexedCtx * FUN_0016bc70();
extern void FUN_001821b0();
extern void FUN_00185970();
extern void FUN_0018629c();

/* Run the context callback, set up the screen's handle and forward all arguments; follow up unless the current entry is 4. */
void FUN_00182480(Screen *self,u32 a1,u32 a2,u32 a3, u32 a4,u32 a5,u32 a6,u32 a7, u8 a8)
{
  IndexedCtx *ctx;
  u32 result;
  
  ctx = FUN_0016bc70();
  result = ctx->callback();
  FUN_001821b0(self,result);
  FUN_0010b6d4(self->handle,0xd,0x11);
  FUN_0010b980(self->handle,a1,0);
  FUN_00185970(self,a1,a2,a3,a4,a6,a5,1,a7,a8);
  ctx = FUN_0016bc70();
  if (ctx->entries[ctx->index] != INDEXED_CTX_ENTRY_NONE) {
    FUN_0018629c(self,a1,a2,a3,a4,0,a6,a7);
  }
}
