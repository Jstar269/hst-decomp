/* HSTMATCH module=hstp_trans_main.prx start=0x00056cb4 end=0x00056d24 symbol=FUN_00056cb4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Frees a malloc buffer (FUN_000104e0 = free) and a new[] array of a class with a constructor (16-byte cookie), then clears all four fields. Matching idiom: the buffer pointer is tested by the caller and again inside the inline SafeFree helper (retail tests it twice). */
struct E { E(); int x; };
struct Buf {
    void *data;
    int f4;
    int f8;
    E *items;
};
extern "C" void FUN_000104e0(void *p);

static inline void SafeFree(void *&p)
{
    if (p != 0) {
        FUN_000104e0(p);
        p = 0;
    }
}

extern "C" void FUN_00056cb4(Buf *self)
{
    if (self->data != 0) {
        SafeFree(self->data);
    }
    if (self->items != 0) {
        delete[] self->items;
        self->items = 0;
    }
    self->data = 0;
    self->f4 = 0;
    self->f8 = 0;
    self->items = 0;
}
