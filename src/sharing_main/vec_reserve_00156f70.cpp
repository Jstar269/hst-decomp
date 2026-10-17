/* HSTMATCH module=hstp_trans_main.prx start=0x00156f70 end=0x0015700c symbol=FUN_00156f70 lang=c++ */
/* Clone of src/eboot/vec_reserve_00091764.cpp (hstclone.py tag x17): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00156f70 { int pad[3]; void *err; };
Reent_00156f70 *FUN_0000fe3c(void);
int FUN_0014db60(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00383478[];
extern char DAT_002d1bbc[];
}
struct Elem_00156f70 { int w[8]; };
struct Alloc_00156f70 { Elem_00156f70 *allocate(unsigned n) { return (Elem_00156f70 *)FUN_00000bcc(n * sizeof(Elem_00156f70)); } };
struct Vec_00156f70 { Elem_00156f70 *data; int size; unsigned capacity; };
extern "C" void FUN_00156f70(Vec_00156f70 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00156f70)) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_00383478);
        FUN_0000d530();
    }
    Elem_00156f70 *p = Alloc_00156f70().allocate(n);
    if (p == 0) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_002d1bbc);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
