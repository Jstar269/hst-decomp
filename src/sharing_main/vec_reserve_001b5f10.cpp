/* HSTMATCH module=hstp_trans_main.prx start=0x001b5f10 end=0x001b5fb8 symbol=FUN_001b5f10 lang=c++ */
/* Clone of src/eboot/vec_reserve_0014b2b0.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 48-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_001b5f10 { int pad[3]; void *err; };
Reent_001b5f10 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003895e0[];
extern char DAT_002d3408[];
}
struct Elem_001b5f10 { int w[12]; };
struct Alloc_001b5f10 { Elem_001b5f10 *allocate(unsigned n) { return (Elem_001b5f10 *)FUN_00000bcc(n * sizeof(Elem_001b5f10)); } };
struct Vec_001b5f10 { Elem_001b5f10 *data; int size; unsigned capacity; };
extern "C" void FUN_001b5f10(Vec_001b5f10 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001b5f10)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003895e0);
        FUN_0000d530();
    }
    Elem_001b5f10 *p = Alloc_001b5f10().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d3408);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
