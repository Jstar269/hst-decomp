/* HSTMATCH module=hstp_trans_main.prx start=0x00224fb8 end=0x0022503c symbol=FUN_00224fb8 lang=c++ */
/* Clone of src/eboot/vec_reserve_t_00215fb4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00224fb8 { int pad[3]; void *err; };
Reent_00224fb8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d9cb8[];
}
struct Elem_00224fb8 { int w[2]; };
struct Alloc_00224fb8 { Elem_00224fb8 *allocate(unsigned n) { return (Elem_00224fb8 *)FUN_00000bcc(n * sizeof(Elem_00224fb8)); } };
struct Vec_00224fb8 { Elem_00224fb8 *data; int size; unsigned capacity; };
extern "C" void FUN_00224fb8(Vec_00224fb8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00224fb8))
        FUN_000043b4();
    Elem_00224fb8 *p = Alloc_00224fb8().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d9cb8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
