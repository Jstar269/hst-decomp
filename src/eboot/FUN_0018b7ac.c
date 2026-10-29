/* HSTMATCH module=EBOOT.BIN start=0x0018b7ac end=0x0018b804 symbol=FUN_0018b7ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/render_target.h"

extern RenderTarget *DAT_0034152c;
extern int FUN_00000bcc();
extern u32 * FUN_0018b944();

/* Creates the global instance (width x height) unless it already exists. */
void FUN_0018b7ac(u32 width,u32 height)
{
  int mem;
  
  if ((DAT_0034152c == 0) && (mem = FUN_00000bcc(RENDER_TARGET_SIZE), mem != 0)) {
    FUN_0018b944(mem,width,height);
  }
}
