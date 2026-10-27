/* HSTMATCH module=hstp_trans_main.prx start=0x000933fc end=0x00093498 symbol=FUN_000933fc lang=c++ data=0x00378a44 */
/* Clone of src/eboot/vec_reserve_00091764.cpp (hstclone.py tag x17): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00378a44-0x00378a58) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000933fc { int pad[3]; void *err; };
Reent_000933fc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cea90[];
}
struct Elem_000933fc { int w[8]; };
struct Alloc_000933fc { Elem_000933fc *allocate(unsigned n) { return (Elem_000933fc *)FUN_00000bcc(n * sizeof(Elem_000933fc)); } };
struct Vec_000933fc { Elem_000933fc *data; int size; unsigned capacity; };
extern "C" void FUN_000933fc(Vec_000933fc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000933fc)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    Elem_000933fc *p = Alloc_000933fc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cea90);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
