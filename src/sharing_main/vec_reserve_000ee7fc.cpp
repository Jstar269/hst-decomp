/* HSTMATCH module=hstp_trans_main.prx start=0x000ee7fc end=0x000ee898 symbol=FUN_000ee7fc lang=c++ */
/* Clone of src/eboot/vec_reserve_00091764.cpp (hstclone.py tag x17): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000ee7fc { int pad[3]; void *err; };
Reent_000ee7fc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d948[];
extern char DAT_002d0980[];
}
struct Elem_000ee7fc { int w[8]; };
struct Alloc_000ee7fc { Elem_000ee7fc *allocate(unsigned n) { return (Elem_000ee7fc *)FUN_00000bcc(n * sizeof(Elem_000ee7fc)); } };
struct Vec_000ee7fc { Elem_000ee7fc *data; int size; unsigned capacity; };
extern "C" void FUN_000ee7fc(Vec_000ee7fc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000ee7fc)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037d948);
        FUN_0000d530();
    }
    Elem_000ee7fc *p = Alloc_000ee7fc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d0980);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
