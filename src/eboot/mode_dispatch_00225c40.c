/* HSTMATCH module=EBOOT.BIN start=0x00225c40 end=0x00225d40 symbol=FUN_00225c40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { char pad[0x60]; float f60; float f64; } Link;
typedef struct { char pad[0x68]; Link *links[2]; char pad70[0xb4 - 0x70]; float fb4; float fb8; } Inner;
typedef struct { char pad[0xc]; void *fc; void *f10; char pad14[4]; Inner *f18; } Sub;
typedef struct { char pad[0x3c]; Sub *p3c; } Self;
extern void FUN_00103480(Inner *);
extern void FUN_0021bf24(void *, int, int);
extern void FUN_0021f7e0(void *, int, Vec4);
extern void FUN_00222bb8(Inner *, int, int);

void FUN_00225c40(Self *self, int mode, int arg, Vec4 v)
{
    if (mode == 0xe) {
        FUN_0021f7e0(self->p3c->f10, arg, v);
    } else if (mode == 0xf) {
        int i = 0;
        Inner *in = self->p3c->f18;
        in->fb4 = -74.0f;
        in->fb8 = 0.0f;
        do {
            if (in->links[i] != 0 && i == 0) {
                in->links[i]->f60 = in->fb4;
                in->links[i]->f64 = in->fb8;
            }
            i++;
        } while (i < 2);
        FUN_00103480(in);
        FUN_00222bb8(self->p3c->f18, arg, 0);
    } else {
        FUN_0021bf24(self->p3c->fc, mode, arg);
    }
}
