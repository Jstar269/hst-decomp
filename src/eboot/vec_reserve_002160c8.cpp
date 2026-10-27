/* HSTMATCH module=EBOOT.BIN start=0x002160c8 end=0x00216164 symbol=FUN_002160c8 lang=c++ data=0x002efb00 */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag c17): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002efb00-0x002efb14) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_002160c8 { int pad[3]; void *err; };
Reent_002160c8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c9820[];
}
struct Elem_002160c8 { int w[2]; };
struct Alloc_002160c8 { Elem_002160c8 *allocate(unsigned n) { return (Elem_002160c8 *)FUN_00000bcc(n * sizeof(Elem_002160c8)); } };
struct Vec_002160c8 { Elem_002160c8 *data; int size; unsigned capacity; };
extern "C" void FUN_002160c8(Vec_002160c8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002160c8)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem_002160c8 *p = Alloc_002160c8().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c9820);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
