/* HSTMATCH module=hstp_trans_main.prx start=0x000c55c4 end=0x000c566c symbol=FUN_000c55c4 lang=c++ data=0x0037c3c8 */
/* Container reserve for a 80-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x0037c3c8-0x0037c3dc) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
struct Reent_000c55c4 { int pad[3]; void *err; };
Reent_000c55c4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d03c8[];
}
struct Elem_000c55c4 { int w[20]; };
struct Alloc_000c55c4 { Elem_000c55c4 *allocate(unsigned n) { return (Elem_000c55c4 *)FUN_00000bcc(n * sizeof(Elem_000c55c4)); } };
struct Vec_000c55c4 { Elem_000c55c4 *data; int size; unsigned capacity; };
extern "C" void FUN_000c55c4(Vec_000c55c4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000c55c4)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    Elem_000c55c4 *p = Alloc_000c55c4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d03c8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
