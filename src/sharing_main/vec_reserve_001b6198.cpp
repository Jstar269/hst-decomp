/* HSTMATCH module=hstp_trans_main.prx start=0x001b6198 end=0x001b6240 symbol=FUN_001b6198 lang=c++ */
/* Clone of src/eboot/vec_reserve_0005e954.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001b6198 { int pad[3]; void *err; };
Reent_001b6198 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003895e0[];
extern char DAT_002d3398[];
}
struct Elem_001b6198 { int w[3]; };
struct Alloc_001b6198 { Elem_001b6198 *allocate(unsigned n) { return (Elem_001b6198 *)FUN_00000bcc(n * sizeof(Elem_001b6198)); } };
struct Vec_001b6198 { Elem_001b6198 *data; int size; unsigned capacity; };
extern "C" void FUN_001b6198(Vec_001b6198 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001b6198)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003895e0);
        FUN_0000d530();
    }
    Elem_001b6198 *p = Alloc_001b6198().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d3398);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
