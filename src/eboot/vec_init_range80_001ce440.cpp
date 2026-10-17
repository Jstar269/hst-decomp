/* HSTMATCH module=EBOOT.BIN start=0x001ce440 end=0x001ce4c0 symbol=FUN_001ce440 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Tag_001ce440 {};
struct Elem_001ce440 { char b[80]; };
struct Vec_001ce440 { Elem_001ce440 *data; int size; unsigned capacity; };

extern "C" void FUN_001cf5fc(Vec_001ce440 *v, unsigned n, Tag_001ce440);
extern "C" void FUN_001ce4c0(Vec_001ce440 *v, Elem_001ce440 *first, Elem_001ce440 *last, Tag_001ce440);

extern "C" void FUN_001ce440(Vec_001ce440 *v, Elem_001ce440 *first, Elem_001ce440 *last, Tag_001ce440)
{
    int n = last - first;
    if (n != 0) {
        FUN_001cf5fc(v, n, Tag_001ce440());
        FUN_001ce4c0(v, first, last, Tag_001ce440());
    }
}
