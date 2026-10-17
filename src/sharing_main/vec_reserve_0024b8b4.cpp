/* HSTMATCH module=hstp_trans_main.prx start=0x0024b8b4 end=0x0024b950 symbol=FUN_0024b8b4 lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0024b8b4 { int pad[3]; void *err; };
Reent_0024b8b4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0039dd78[];
extern char DAT_002da540[];
}
struct Elem_0024b8b4 { int w[2]; };
struct Alloc_0024b8b4 { Elem_0024b8b4 *allocate(unsigned n) { return (Elem_0024b8b4 *)FUN_00000bcc(n * sizeof(Elem_0024b8b4)); } };
struct Vec_0024b8b4 { Elem_0024b8b4 *data; int size; unsigned capacity; };
extern "C" void FUN_0024b8b4(Vec_0024b8b4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0024b8b4)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0039dd78);
        FUN_0000d530();
    }
    Elem_0024b8b4 *p = Alloc_0024b8b4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da540);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
