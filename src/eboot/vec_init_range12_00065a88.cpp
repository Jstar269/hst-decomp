/* HSTMATCH module=EBOOT.BIN start=0x00065a88 end=0x00065b08 symbol=FUN_00065a88 lang=c++ */
/* Clone of src/sharing_main/vec_init_range12_00066edc.cpp (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag_00065a88 {};
struct Elem_00065a88 { float a, b, c; };
struct Vec_00065a88 { Elem_00065a88 *data; int size; unsigned capacity; };
extern "C" void FUN_000668a0(Vec_00065a88 *v, unsigned n, Tag_00065a88);
extern "C" void FUN_00065b08(Vec_00065a88 *v, Elem_00065a88 *first, Elem_00065a88 *last, Tag_00065a88);
extern "C" void FUN_00065a88(Vec_00065a88 *v, Elem_00065a88 *first, Elem_00065a88 *last, Tag_00065a88)
{
    int n = last - first;
    if (n != 0) {
        FUN_000668a0(v, n, Tag_00065a88());
        FUN_00065b08(v, first, last, Tag_00065a88());
    }
}
