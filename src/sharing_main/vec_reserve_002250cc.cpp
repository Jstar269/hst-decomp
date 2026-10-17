/* HSTMATCH module=hstp_trans_main.prx start=0x002250cc end=0x00225168 symbol=FUN_002250cc lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_002250cc { int pad[3]; void *err; };
Reent_002250cc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00397e44[];
extern char DAT_002d9cb8[];
}
struct Elem_002250cc { int w[2]; };
struct Alloc_002250cc { Elem_002250cc *allocate(unsigned n) { return (Elem_002250cc *)FUN_00000bcc(n * sizeof(Elem_002250cc)); } };
struct Vec_002250cc { Elem_002250cc *data; int size; unsigned capacity; };
extern "C" void FUN_002250cc(Vec_002250cc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002250cc)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00397e44);
        FUN_0000d530();
    }
    Elem_002250cc *p = Alloc_002250cc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d9cb8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
