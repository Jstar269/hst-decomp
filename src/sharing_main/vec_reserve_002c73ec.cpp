/* HSTMATCH module=hstp_trans_main.prx start=0x002c73ec end=0x002c7488 symbol=FUN_002c73ec lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_002c73ec { int pad[3]; void *err; };
Reent_002c73ec *FUN_0000fe3c(void);
int FUN_002c6f80(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003ac41c[];
extern char DAT_002dc824[];
}
struct Elem_002c73ec { int w[2]; };
struct Alloc_002c73ec { Elem_002c73ec *allocate(unsigned n) { return (Elem_002c73ec *)FUN_00000bcc(n * sizeof(Elem_002c73ec)); } };
struct Vec_002c73ec { Elem_002c73ec *data; int size; unsigned capacity; };
extern "C" void FUN_002c73ec(Vec_002c73ec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002c73ec)) {
        FUN_002c6f80(FUN_0000fe3c()->err, DAT_003ac41c);
        FUN_0000d530();
    }
    Elem_002c73ec *p = Alloc_002c73ec().allocate(n);
    if (p == 0) {
        FUN_002c6f80(FUN_0000fe3c()->err, DAT_002dc824);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
