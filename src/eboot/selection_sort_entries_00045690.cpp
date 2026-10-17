/* HSTMATCH module=EBOOT.BIN start=0x00045690 end=0x00045730 symbol=FUN_00045690 lang=c++ */
/* Clone of src/sharing_main/selection_sort_entries_00045790.cpp (hstclone.py tag s10170158a1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: restructured into an Entry struct with a member-wise operator= and an inline Swap (the temporary lives in a stack slot), min search as an inner loop; exact match verified; names and types await human review. */
struct Entry {
  unsigned short key;
  unsigned short val;
  Entry &operator=(const Entry &o)
  {
    key = o.key;
    val = o.val;
    return *this;
  }
};

inline void Swap(Entry &a, Entry &b)
{
  Entry t = a;
  a = b;
  b = t;
}

extern "C" void FUN_00045690(Entry *first, Entry *last)
{
  Entry *i;
  if (first == last) {
    return;
  }
  for (i = first; i < last - 1; i++) {
    Entry *min = i;
    Entry *j;
    if (i != last) {
      for (j = i + 1; j != last; j++) {
        if (j->key < min->key) {
          min = j;
        }
      }
    }
    if (min != i) {
      Swap(*min, *i);
    }
  }
}
