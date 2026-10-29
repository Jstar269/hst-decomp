/* HSTMATCH module=hstp_trans_main.prx start=0x0011fcec end=0x0011fd10 symbol=FUN_0011fcec lang=c99 */
/* Clone of src/eboot/FUN_00114fdc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

typedef struct Span { char pad0[4]; short start; /* 0x4 */ short pad6; short end; /* 0x8 */ } Span;
typedef struct SpanList { char pad0[0x10]; Span **items; /* 0x10 */ } SpanList;

/* Length (end - start) of the index-th entry. */
int FUN_0011fcec(SpanList *self,int index)
{
  Span *entry;
  
  entry = self->items[index];
  return (int)(short)(entry->end - entry->start);
}
