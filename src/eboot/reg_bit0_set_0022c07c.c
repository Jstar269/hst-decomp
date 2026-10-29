/* HSTMATCH module=EBOOT.BIN start=0x0022c07c end=0x0022c0d4 symbol=FUN_0022c07c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char *DAT_003415a8;  /* address of the global system block */
struct Regs { unsigned char pad[0xd504]; unsigned short ctrl; };

/* Sets or clears bit 0 of the 16-bit control word. */
void FUN_0022c07c(int enable)
{
  if (enable != 0) {
    *(u16 *)(DAT_003415a8 + 0xd504) = ((struct Regs *)DAT_003415a8)->ctrl | 1;
  }
  else {
    ((struct Regs *)DAT_003415a8)->ctrl = *(u16 *)(DAT_003415a8 + 0xd504) & 0xfffe;
  }
}
/* A 0xd504 byte offset does not fit a signed 16-bit displacement, so MWCC can either add it in two
 * `addiu`s (what the flattened form does, 18 words) or split it into `lui 0x1; addu` plus a
 * `-11004` displacement (retail, 22). The split appears only when the LOAD and the STORE use
 * different address expressions: writing one side as a struct member (`->ctrl`) and the other as the
 * flattened cast stops MWCC from CSE-ing the single address, and then both sides get their own
 * base+0x10000 computation exactly as retail has it. The branch must also be written
 * `if (enable != 0) { set } else { clear }` so the set block falls through into the `beqzl`.
 */
