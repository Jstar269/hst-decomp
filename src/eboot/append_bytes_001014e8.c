/* HSTMATCH module=EBOOT.BIN start=0x001014e8 end=0x00101590 symbol=FUN_001014e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used indexed input access and typed the reserve and append helper parameters; exact match verified; names and types await human review. */
extern void FUN_00107174(void *, unsigned int);
extern void FUN_00101798(void *, unsigned int, int, int, int, int, unsigned int);
typedef struct { char pad[0x14]; unsigned int size; } Obj;
void FUN_001014e8(Obj *self, const unsigned char *input, unsigned int count) {
  if (self->size == 0 && *(unsigned int *)((char *)self + 0x18) < count)
    FUN_00107174((char *)self + 0x10, count);
  for (int i = 0; i < (int)count; ++i)
    FUN_00101798(self, input[i], -1, 0, 0, -1, 0x80808080);
}
