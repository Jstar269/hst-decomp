/* HSTMATCH module=EBOOT.BIN start=0x0022c07c end=0x0022c0d4 symbol=FUN_0022c07c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned short ushort;

extern unsigned char *DAT_003415a8;
struct Regs { unsigned char pad[0xd504]; unsigned short f; };

void FUN_0022c07c(int param_1)
{
  if (param_1 != 0) {
    *(ushort *)(DAT_003415a8 + 0xd504) = ((struct Regs *)DAT_003415a8)->f | 1;
  }
  else {
    ((struct Regs *)DAT_003415a8)->f = *(ushort *)(DAT_003415a8 + 0xd504) & 0xfffe;
  }
  return;
}
/* A 0xd504 byte offset does not fit a signed 16-bit displacement, so MWCC can either add it in two
 * `addiu`s (what the flattened form does, 18 words) or split it into `lui 0x1; addu` plus a
 * `-11004` displacement (retail, 22). The split appears only when the LOAD and the STORE use
 * different address expressions: writing one side as a struct member (`->f`) and the other as the
 * flattened cast stops MWCC from CSE-ing the single address, and then both sides get their own
 * base+0x10000 computation exactly as retail has it. The branch must also be written
 * `if (param_1 != 0) { set } else { clear }` so the set block falls through into the `beqzl`.
 */
