/* HSTMATCH module=hstp_trans_main.prx start=0x001ddcd8 end=0x001ddd68 symbol=FUN_001ddcd8 lang=c++ */
/* Clone of src/eboot/vec_reserve_t_001cf5fc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 80-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_001ddcd8 { int pad[3]; void *err; };
Reent_001ddcd8 *FUN_0000fe3c(void);
int FUN_001d0468(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d1c80[];
}
struct Elem_001ddcd8 { int w[20]; };
struct Alloc_001ddcd8 { Elem_001ddcd8 *allocate(unsigned n) { return (Elem_001ddcd8 *)FUN_00000bcc(n * sizeof(Elem_001ddcd8)); } };
struct Vec_001ddcd8 { Elem_001ddcd8 *data; int size; unsigned capacity; };
extern "C" void FUN_001ddcd8(Vec_001ddcd8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001ddcd8))
        FUN_000043b4();
    Elem_001ddcd8 *p = Alloc_001ddcd8().allocate(n);
    if (p == 0) {
        FUN_001d0468(FUN_0000fe3c()->err, DAT_002d1c80);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
