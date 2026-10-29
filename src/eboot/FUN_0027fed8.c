/* HSTMATCH module=EBOOT.BIN start=0x0027fed8 end=0x0027fef0 symbol=FUN_0027fed8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
typedef struct Source {
  char pad0[4];
  short unk4;   /* 0x04 */
} Source;

typedef struct Cursor {
  Source *source; /* 0x00 */
  short unk4;     /* 0x04 copied from the source */
  int unk8;       /* 0x08 */
  signed char flag; /* 0x0c */
} Cursor;

/* Initializes a cursor over a source object. */
void FUN_0027fed8(Cursor *self,Source *source,signed char flag)
{
  self->source = source;
  self->unk8 = 0;
  self->unk4 = source->unk4;
  self->flag = flag;
  return;
}
