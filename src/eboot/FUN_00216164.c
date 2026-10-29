/* HSTMATCH module=EBOOT.BIN start=0x00216164 end=0x00216174 symbol=FUN_00216164 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
typedef struct Obj {
  int unk00;
  int unk04;
} Obj;

/* Subtract `amount` from the word at offset 4. */
void FUN_00216164(Obj *self,int amount)
{
  self->unk04 = self->unk04 - amount;
}
