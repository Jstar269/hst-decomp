/* HSTMATCH module=EBOOT.BIN start=0x00148ee8 end=0x00148fd0 symbol=FUN_00148ee8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: passed empty tag objects by value to both calls and retained address-named callees; readability pass; exact match verified; names and types await human review. */

struct EmptyTag {};

#define RECORD_SIZE 0x28 /* bytes per element */

/* Vector header over 0x28-byte records; the buffer it is exchanged with has the same layout. */
struct RecVec {
  char *data;     /* 0x00 */
  int size;       /* 0x04 */
  int capacity;   /* 0x08 */
};

extern "C" void FUN_00148fd0(RecVec *, char *, char *, EmptyTag);
extern "C" void FUN_00149078(RecVec *, char *, char *, EmptyTag);

/* Runs two helper calls on buf for position pos, then swaps the header fields of the two vectors; returns the
   element address matching pos in the swapped-in storage. */
extern "C" char *FUN_00148ee8(RecVec *self,RecVec *buf,char *pos)
{
  int tmp;
  char *old;
  
  old = self->data;
  FUN_00149078(buf,pos,old + self->size * RECORD_SIZE,EmptyTag());
  FUN_00148fd0(buf,self->data,pos,EmptyTag());
  tmp = self->capacity;
  self->capacity = buf->capacity;
  buf->capacity = tmp;
  {
    char *t = self->data;
    self->data = buf->data;
    buf->data = t;
  }
  tmp = self->size;
  self->size = buf->size;
  buf->size = tmp;
  return self->data + ((pos - old) / RECORD_SIZE) * RECORD_SIZE;
}
