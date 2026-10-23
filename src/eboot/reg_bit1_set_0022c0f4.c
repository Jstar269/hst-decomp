/* HSTMATCH module=EBOOT.BIN start=0x0022c0f4 end=0x0022c15c symbol=FUN_0022c0f4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char *DAT_003415a8;
struct Regs { unsigned char pad[0xd504]; unsigned short f; };

void FUN_0022c0f4(int param_1,int param_2)
{
  if (param_1 != 0) {
    *(unsigned short *)(DAT_003415a8 + 0xd504) = ((struct Regs *)DAT_003415a8)->f | 2;
  }
  else {
    ((struct Regs *)DAT_003415a8)->f = *(unsigned short *)(DAT_003415a8 + 0xd504) & 0xfffd;
  }
  *(int *)(DAT_003415a8 + 0xd4e0) = param_2;
}
/* Sibling of 0x0022c07c: same trick (one side a struct member, the other the flattened cast, so the
 * 0xd504 address is computed twice as `lui 0x1; addu` + `-11004` displacement) plus the trailing
 * `*(int *)(DAT + 0xd4e0) = param_2`, whose single `addu` already matched.
 */
