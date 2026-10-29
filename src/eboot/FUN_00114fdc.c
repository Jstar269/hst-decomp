/* HSTMATCH module=EBOOT.BIN start=0x00114fdc end=0x00115000 symbol=FUN_00114fdc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Span { char pad0[4]; short start; /* 0x4 */ short pad6; short end; /* 0x8 */ } Span;
typedef struct SpanList { char pad0[0x10]; Span **items; /* 0x10 */ } SpanList;

/* Length (end - start) of the index-th entry. */
int FUN_00114fdc(SpanList *self,int index)
{
  Span *entry;
  
  entry = self->items[index];
  return (int)(short)(entry->end - entry->start);
}
