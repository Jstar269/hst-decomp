/* HSTMATCH module=hstp_trans_main.prx start=0x00066edc end=0x00066f5c symbol=FUN_00066edc lang=c++ */
/* Clone of src/eboot/vec_init_range12_00246328.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag_00066edc {};
struct Elem_00066edc { float a, b, c; };
struct Vec_00066edc { Elem_00066edc *data; int size; unsigned capacity; };
extern "C" void FUN_00067cf4(Vec_00066edc *v, unsigned n, Tag_00066edc);
extern "C" void FUN_00066f5c(Vec_00066edc *v, Elem_00066edc *first, Elem_00066edc *last, Tag_00066edc);
extern "C" void FUN_00066edc(Vec_00066edc *v, Elem_00066edc *first, Elem_00066edc *last, Tag_00066edc)
{
    int n = last - first;
    if (n != 0) {
        FUN_00067cf4(v, n, Tag_00066edc());
        FUN_00066f5c(v, first, last, Tag_00066edc());
    }
}
