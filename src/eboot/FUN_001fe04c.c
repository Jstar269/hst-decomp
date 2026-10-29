/* HSTMATCH module=EBOOT.BIN start=0x001fe04c end=0x001fe080 symbol=FUN_001fe04c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Owner {
  char pad0[200];
  char unkC8[0xcd0 - 200];  /* 0xc8 */
  char unkCD0[0x1250 - 0xcd0];  /* 0xcd0 */
  char unk1250[1];          /* 0x1250 */
} Owner;

extern void FUN_002019cc();
extern void FUN_0020212c();

void FUN_001fe04c(Owner *self)
{
  FUN_002019cc(self->unkC8);
  FUN_0020212c(self->unk1250,self->unkCD0);
}
