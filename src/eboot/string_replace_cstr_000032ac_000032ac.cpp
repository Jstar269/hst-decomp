/* HSTMATCH module=EBOOT.BIN start=0x000032ac end=0x00003314 symbol=FUN_000032ac lang=c++ */
/* Clone of src/sharing_main/string_replace_cstr_000032ac.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* String-library forwarder: replace (pos, n) with a NUL-terminated string through the iterator-range worker
   FUN_00003370 (s, s + length(s), category tag). The never-written `lb t1,44(sp)` sixth argument is an empty tag
   DERIVED from another empty class passed by value; the length helper FUN_000041d0 wraps strlen. Names provisional. */
struct input_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

extern "C" int FUN_000041d0(const char *);
extern "C" void *FUN_00003370(void *self, unsigned pos, unsigned n, const char *first, const char *last,
                              random_access_iterator_tag);

extern "C" void *FUN_000032ac(void *self, unsigned pos, unsigned n, const char *s)
{
  return FUN_00003370(self, pos, n, s, s + FUN_000041d0(s), random_access_iterator_tag());
}
