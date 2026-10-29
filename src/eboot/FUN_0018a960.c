/* HSTMATCH module=EBOOT.BIN start=0x0018a960 end=0x0018a9fc symbol=FUN_0018a960 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/phase_screen.h"

extern u32 * FUN_000114c0();
extern void FUN_0010d4a8();
extern void FUN_0018a9fc();

/* Reset the text buffers and point the last two boxes at the first two of them. */
void FUN_0018a960(PhaseScreen *self,u32 buffer_mode,int reset)
{
  int i;
  char *base;     /* object start moved on by one buffer per step; buffers begin 0x9c in */
  TextBox *box;
  
  if (reset != 0) {
    FUN_0018a9fc(self);
  }
  self->buffer_mode = buffer_mode;
  i = 0;
  base = (char *)self;
  do {
    FUN_000114c0((u32 *)(base + 0x9c),0,PHASE_BUFFER_SIZE);
    i = i + 1;
    base = base + PHASE_BUFFER_SIZE;
  } while (PHASE_BOX_COUNT > i);
  i = 0;
  base = (char *)self;
  do {
    box = *(TextBox **)((char *)self + 0x7c);
    box->buffer = base + 0x9c;
    box->unk138 = 0;
    FUN_0010d4a8(box);
    i = i + 1;
    self = (PhaseScreen *)((char *)self + 4);
    base = base + PHASE_BUFFER_SIZE;
  } while (i < 2);
}
