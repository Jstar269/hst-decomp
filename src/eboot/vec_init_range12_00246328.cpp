/* HSTMATCH module=EBOOT.BIN start=0x00246328 end=0x002463a8 symbol=FUN_00246328 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag_00246328 {};
struct Elem_00246328 { float a, b, c; };
struct Vec_00246328 { Elem_00246328 *data; int size; unsigned capacity; };
extern "C" void FUN_00246484(Vec_00246328 *v, unsigned n, Tag_00246328);
extern "C" void FUN_002463a8(Vec_00246328 *v, Elem_00246328 *first, Elem_00246328 *last, Tag_00246328);
extern "C" void FUN_00246328(Vec_00246328 *v, Elem_00246328 *first, Elem_00246328 *last, Tag_00246328)
{
    int n = last - first;
    if (n != 0) {
        FUN_00246484(v, n, Tag_00246328());
        FUN_002463a8(v, first, last, Tag_00246328());
    }
}
