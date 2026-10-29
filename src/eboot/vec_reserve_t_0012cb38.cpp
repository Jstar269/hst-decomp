/* HSTMATCH module=EBOOT.BIN start=0x0012cb38 end=0x0012cbbc symbol=FUN_0012cb38 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent { int pad[3]; void *err; };
Reent *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c0788[];
}
struct Elem16 { int w[4]; };
struct Alloc16 { Elem16 *allocate(unsigned n) { return (Elem16 *)FUN_00000bcc(n * sizeof(Elem16)); } };
struct Vec16 { Elem16 *data; int size; unsigned capacity; }; /* data, number in use, capacity */
/* Reserves room for n elements in an empty vector. */
extern "C" void FUN_0012cb38(Vec16 *buf, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem16))
        FUN_000043b4();
    Elem16 *p = Alloc16().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0788);
        FUN_0000d518();
    }
    buf->data = p;
    buf->capacity = n;
}
