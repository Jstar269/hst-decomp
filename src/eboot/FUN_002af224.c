/* HSTMATCH module=EBOOT.BIN start=0x002af224 end=0x002af26c symbol=FUN_002af224 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct TextHolder {
  char pad00[0x1c];
  char text[0x4b];      /* 0x1c */
} TextHolder;

extern u32 * FUN_000114c0();
extern u32 * FUN_000149a8();

/* Clear the text buffer and copy src into it. */
void FUN_002af224(TextHolder *self,u32 src)
{
  FUN_000114c0(self->text,0,sizeof(self->text));
  FUN_000149a8(self->text,src);
}
