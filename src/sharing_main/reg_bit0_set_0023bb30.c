/* HSTMATCH module=hstp_trans_main.prx start=0x0023bb30 end=0x0023bb88 symbol=FUN_0023bb30 lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT sibling src/eboot/reg_bit0_set_0022c07c.c, same instruction shape: the register block pointer is DAT_003ea8e8); matching idiom: the load and the store spell the 0xd504 field differently (member vs flattened cast, see the trailing comment); exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char *DAT_003ea8e8;
struct Regs { unsigned char pad[0xd504]; unsigned short f; };

void FUN_0023bb30(int param_1)
{
  if (param_1 != 0) {
    *(u16 *)(DAT_003ea8e8 + 0xd504) = ((struct Regs *)DAT_003ea8e8)->f | 1;
  }
  else {
    ((struct Regs *)DAT_003ea8e8)->f = *(u16 *)(DAT_003ea8e8 + 0xd504) & 0xfffe;
  }
}
/* A 0xd504 byte offset does not fit a signed 16-bit displacement, so MWCC can either add it in two
 * `addiu`s (what the flattened form does, 18 words) or split it into `lui 0x1; addu` plus a
 * `-11004` displacement (retail, 22). The split appears only when the LOAD and the STORE use
 * different address expressions: writing one side as a struct member (`->f`) and the other as the
 * flattened cast stops MWCC from CSE-ing the single address, and then both sides get their own
 * base+0x10000 computation exactly as retail has it. The branch must also be written
 * `if (param_1 != 0) { set } else { clear }` so the set block falls through into the `beqzl`.
 */
