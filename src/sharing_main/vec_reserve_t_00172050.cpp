/* HSTMATCH module=hstp_trans_main.prx start=0x00172050 end=0x001720e4 symbol=FUN_00172050 lang=c++ */
/* Clone of src/eboot/vec_reserve_t_00165e60.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 556-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00172050 { int pad[3]; void *err; };
Reent_00172050 *FUN_0000fe3c(void);
int FUN_001701e0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d21e8[];
}
struct Elem_00172050 { int w[139]; };
struct Alloc_00172050 { Elem_00172050 *allocate(unsigned n) { return (Elem_00172050 *)FUN_00000bcc(n * sizeof(Elem_00172050)); } };
struct Vec_00172050 { Elem_00172050 *data; int size; unsigned capacity; };
extern "C" void FUN_00172050(Vec_00172050 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00172050))
        FUN_000043b4();
    Elem_00172050 *p = Alloc_00172050().allocate(n);
    if (p == 0) {
        FUN_001701e0(FUN_0000fe3c()->err, DAT_002d21e8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
