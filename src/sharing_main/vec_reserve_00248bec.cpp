/* HSTMATCH module=hstp_trans_main.prx start=0x00248bec end=0x00248c94 symbol=FUN_00248bec lang=c++ */
/* Clone of src/eboot/vec_reserve_0005e954.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00248bec { int pad[3]; void *err; };
Reent_00248bec *FUN_0000fe3c(void);
int FUN_002448c4(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0039dc28[];
extern char DAT_002da4a8[];
}
struct Elem_00248bec { int w[3]; };
struct Alloc_00248bec { Elem_00248bec *allocate(unsigned n) { return (Elem_00248bec *)FUN_00000bcc(n * sizeof(Elem_00248bec)); } };
struct Vec_00248bec { Elem_00248bec *data; int size; unsigned capacity; };
extern "C" void FUN_00248bec(Vec_00248bec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00248bec)) {
        FUN_002448c4(FUN_0000fe3c()->err, DAT_0039dc28);
        FUN_0000d530();
    }
    Elem_00248bec *p = Alloc_00248bec().allocate(n);
    if (p == 0) {
        FUN_002448c4(FUN_0000fe3c()->err, DAT_002da4a8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
