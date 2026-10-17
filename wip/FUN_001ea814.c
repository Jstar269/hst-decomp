/* HSTMATCH module=EBOOT.BIN start=0x001ea814 end=0x001ea854 symbol=FUN_001ea814 lang=c99 */
extern void *FUN_00000bcc(unsigned int);
extern void *FUN_001e84e0(void *);
void **FUN_001ea814(void **out)
{
  void *object = FUN_00000bcc(0x444);
  *out = object;
  *out = object != 0 ? FUN_001e84e0(object) : object;
  return out;
}
// Near miss: only +0x18 differs (beqz versus retail beqzl). Early-return, if/else, ternary, and placement-new C++ forms did not change that opcode while preserving the matching surrounding words.
// near miss from lane u6cr3-0 (unreviewed)
