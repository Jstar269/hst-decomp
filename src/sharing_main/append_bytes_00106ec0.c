/* HSTMATCH module=hstp_trans_main.prx start=0x00106ec0 end=0x00106f68 symbol=FUN_00106ec0 lang=c99 */
/* Clone of src/eboot/append_bytes_001014e8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used indexed input access and typed the reserve and append helper parameters; exact match verified; names and types await human review. */
extern void FUN_0010cf34(void *, unsigned int);
extern void FUN_00107170(void *, unsigned int, int, int, int, int, unsigned int);
typedef struct { char pad[0x14]; unsigned int size; } Obj;
void FUN_00106ec0(Obj *self, const unsigned char *input, unsigned int count) {
  if (self->size == 0 && *(unsigned int *)((char *)self + 0x18) < count)
    FUN_0010cf34((char *)self + 0x10, count);
  for (int i = 0; i < (int)count; ++i)
    FUN_00107170(self, input[i], -1, 0, 0, -1, 0x80808080);
}
