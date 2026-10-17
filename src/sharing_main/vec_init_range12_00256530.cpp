/* HSTMATCH module=hstp_trans_main.prx start=0x00256530 end=0x002565b0 symbol=FUN_00256530 lang=c++ */
/* Clone of src/eboot/vec_init_range12_00065a88.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag_00256530 {};
struct Elem_00256530 { float a, b, c; };
struct Vec_00256530 { Elem_00256530 *data; int size; unsigned capacity; };
extern "C" void FUN_0025668c(Vec_00256530 *v, unsigned n, Tag_00256530);
extern "C" void FUN_002565b0(Vec_00256530 *v, Elem_00256530 *first, Elem_00256530 *last, Tag_00256530);
extern "C" void FUN_00256530(Vec_00256530 *v, Elem_00256530 *first, Elem_00256530 *last, Tag_00256530)
{
    int n = last - first;
    if (n != 0) {
        FUN_0025668c(v, n, Tag_00256530());
        FUN_002565b0(v, first, last, Tag_00256530());
    }
}
