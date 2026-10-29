/* HSTMATCH module=EBOOT.BIN start=0x0015088c end=0x00150924 symbol=FUN_0015088c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Object with a vtable and two heap buffers released by its destructor. */
struct BufHolder {
    void *vptr;
    int unk04;
    void *buf_a;  /* 0x08 */
    void *buf_b;  /* 0x0c, released first */
};
extern "C" {
extern char DAT_0030840c;
extern char DAT_00308ec4;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(void *);
}

/* Deleting destructor: free both buffers, restore the base vtable, free the object when delete_flag is positive. */
extern "C" BufHolder *FUN_0015088c(BufHolder *self, short delete_flag)
{
    if (self != 0) {
        self->vptr = &DAT_00308ec4;
        if (self->buf_b != 0) {
            FUN_000009e4(self->buf_b);
            self->buf_b = 0;
        }
        if (self->buf_a != 0) {
            FUN_000009e4(self->buf_a);
            self->buf_a = 0;
        }
        if (self != 0) {
            self->vptr = &DAT_0030840c;
        }
        if (0 < delete_flag) {
            FUN_00000a00(self);
        }
    }
    return self;
}
