/* HSTMATCH module=hstp_trans_main.prx start=0x00247a44 end=0x00247adc symbol=FUN_00247a44 lang=c++ */
/* Clone of src/eboot/vec_reserve_t_0023790c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 560-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00247a44 { int pad[3]; void *err; };
Reent_00247a44 *FUN_0000fe3c(void);
int FUN_002448c4(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002da4fc[];
}
struct Elem_00247a44 { int w[140]; };
struct Alloc_00247a44 { Elem_00247a44 *allocate(unsigned n) { return (Elem_00247a44 *)FUN_00000bcc(n * sizeof(Elem_00247a44)); } };
struct Vec_00247a44 { Elem_00247a44 *data; int size; unsigned capacity; };
extern "C" void FUN_00247a44(Vec_00247a44 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00247a44))
        FUN_000043b4();
    Elem_00247a44 *p = Alloc_00247a44().allocate(n);
    if (p == 0) {
        FUN_002448c4(FUN_0000fe3c()->err, DAT_002da4fc);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
