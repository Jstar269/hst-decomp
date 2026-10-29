/* HSTMATCH module=EBOOT.BIN start=0x001cd8dc end=0x001cd970 symbol=FUN_001cd8dc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the function takes a trailing empty by-value tag parameter that Ghidra omits (it adds 16 bytes of frame); readability pass; exact match verified; names and types await human review. */
struct False {};
extern "C" void *FUN_000111c0(void *, const void *, unsigned int);

/* Vector of words: data pointer (as an address) and element count. */
struct IntVec {
  int data;
  int size;
};

/* Erase [first, last) from the vector by moving the tail down; returns the new position of `first`. */
extern "C" int FUN_001cd8dc(IntVec *vec, int first, int last, False)
{
  int tail_bytes;

  if (first != last) {
    tail_bytes = (vec->data + vec->size * 4) - last;
    FUN_000111c0((void *)first, (const void *)last, (unsigned int)((tail_bytes / 4) << 2));
    last = last - first;
    vec->size = vec->size - (last / 4);
  }
  return first;
}
