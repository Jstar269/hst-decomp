/* HSTMATCH module=hstp_trans_main.prx start=0x002092cc end=0x00209384 symbol=FUN_002092cc lang=c99 */
/* Clone of src/eboot/find_or_add_entry_001fabb4.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Looks for an entry of the table at +0x12e0 (ten 12-byte records of two ints and one byte) whose first
   two fields equal the second and the third parameter; when no record matches, the record at index
   self->count is filled with the parameters and self->count is incremented. The table is left alone
   when the count is negative or not below 10.
   Matching idioms: the count test is written as "count >= 0 && count < 10" (the ">-1" spelling makes the
   compiler emit slti/bnez instead of the retail bltz), the scan is a for loop (a do/while with an
   explicit guard moves the retail bltz next to the found-flag initialisation), the record access has to
   go through the member array (the raw "count*12 + base + 0x12e0" arithmetic puts the base first in the
   addu), and the count is read again from the object for the second and third store (the store into the
   table may alias the count, so the compiler has to reload it). */
typedef unsigned char undefined1;

typedef struct {
  int f0;
  int f1;
  char f2;
} Entry;

typedef struct {
  char pad[0x12e0];
  Entry items[10];
  int count;
} Obj;

void FUN_002092cc(Obj *self, int a, int b, undefined1 c)
{
  int count;
  int found;
  int i;

  count = self->count;
  if (count >= 0 && count < 10) {
    found = 0;
    for (i = 0; i <= count; i++) {
      if ((self->items[i].f0 == a) && (self->items[i].f1 == b)) {
        found = 1;
      }
    }
    if (!found) {
      self->items[count].f0 = a;
      self->items[self->count].f1 = b;
      self->items[self->count].f2 = c;
      self->count = self->count + 1;
    }
  }
}
