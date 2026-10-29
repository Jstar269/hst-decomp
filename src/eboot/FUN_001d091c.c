/* HSTMATCH module=EBOOT.BIN start=0x001d091c end=0x001d0950 symbol=FUN_001d091c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct TwoPart {
  int unk0; /* 0x0 */
  int unk4; /* 0x4 */
} TwoPart;

extern void FUN_00269ab0();
extern void FUN_0026bf18();

void FUN_001d091c(TwoPart *self)
{
  FUN_0026bf18(self,1);
  FUN_00269ab0(&self->unk4,2);
}
