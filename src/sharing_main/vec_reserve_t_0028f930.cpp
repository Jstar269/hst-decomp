/* HSTMATCH module=hstp_trans_main.prx start=0x0028f930 end=0x0028f9c8 symbol=FUN_0028f930 lang=c++ */
/* Clone of src/eboot/vec_reserve_t_0027e4c0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 104-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0028f930 { int pad[3]; void *err; };
Reent_0028f930 *FUN_0000fe3c(void);
int FUN_0028f3ac(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dafe0[];
}
struct Elem_0028f930 { int w[26]; };
struct Alloc_0028f930 { Elem_0028f930 *allocate(unsigned n) { return (Elem_0028f930 *)FUN_00000bcc(n * sizeof(Elem_0028f930)); } };
struct Vec_0028f930 { Elem_0028f930 *data; int size; unsigned capacity; };
extern "C" void FUN_0028f930(Vec_0028f930 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0028f930))
        FUN_000043b4();
    Elem_0028f930 *p = Alloc_0028f930().allocate(n);
    if (p == 0) {
        FUN_0028f3ac(FUN_0000fe3c()->err, DAT_002dafe0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
