/* HSTMATCH module=hstp_trans_main.prx start=0x0006ee10 end=0x0006eeb8 symbol=FUN_0006ee10 lang=c++ data=0x003772f4 */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x003772f4-0x00377308) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
struct Reent_0006ee10 { int pad[3]; void *err; };
Reent_0006ee10 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc514[];
}
struct Elem_0006ee10 { int w[10]; };
struct Alloc_0006ee10 { Elem_0006ee10 *allocate(unsigned n) { return (Elem_0006ee10 *)FUN_00000bcc(n * sizeof(Elem_0006ee10)); } };
struct Vec_0006ee10 { Elem_0006ee10 *data; int size; unsigned capacity; };
extern "C" void FUN_0006ee10(Vec_0006ee10 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0006ee10)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    Elem_0006ee10 *p = Alloc_0006ee10().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc514);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
