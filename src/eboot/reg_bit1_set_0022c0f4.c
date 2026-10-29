/* HSTMATCH module=EBOOT.BIN start=0x0022c0f4 end=0x0022c15c symbol=FUN_0022c0f4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char *DAT_003415a8;  /* address of the global system block */
struct Regs { unsigned char pad[0xd504]; unsigned short ctrl; };

/* Sets or clears bit 1 of the 16-bit control word, then stores `value` at the word before it. */
void FUN_0022c0f4(int enable,int value)
{
  if (enable != 0) {
    *(unsigned short *)(DAT_003415a8 + 0xd504) = ((struct Regs *)DAT_003415a8)->ctrl | 2;
  }
  else {
    ((struct Regs *)DAT_003415a8)->ctrl = *(unsigned short *)(DAT_003415a8 + 0xd504) & 0xfffd;
  }
  *(int *)(DAT_003415a8 + 0xd4e0) = value;
}
/* Sibling of 0x0022c07c: same trick (one side a struct member, the other the flattened cast, so the
 * 0xd504 address is computed twice as `lui 0x1; addu` + `-11004` displacement) plus the trailing
 * `*(int *)(DAT + 0xd4e0) = value`, whose single `addu` already matched.
 */
