/* HSTMATCH module=hstp_trans_main.prx start=0x001dcb1c end=0x001dcb9c symbol=FUN_001dcb1c lang=c++ */
/* Clone of src/eboot/vec_init_range80_001ce440.cpp (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Tag_001dcb1c {};
struct Elem_001dcb1c { char b[80]; };
struct Vec_001dcb1c { Elem_001dcb1c *data; int size; unsigned capacity; };

extern "C" void FUN_001ddcd8(Vec_001dcb1c *v, unsigned n, Tag_001dcb1c);
extern "C" void FUN_001dcb9c(Vec_001dcb1c *v, Elem_001dcb1c *first, Elem_001dcb1c *last, Tag_001dcb1c);

extern "C" void FUN_001dcb1c(Vec_001dcb1c *v, Elem_001dcb1c *first, Elem_001dcb1c *last, Tag_001dcb1c)
{
    int n = last - first;
    if (n != 0) {
        FUN_001ddcd8(v, n, Tag_001dcb1c());
        FUN_001dcb9c(v, first, last, Tag_001dcb1c());
    }
}
