/* HSTMATCH module=hstp_trans_main.prx start=0x002351b4 end=0x002352b4 symbol=FUN_002351b4 lang=c99 */
/* Clone of src/eboot/mode_dispatch_00225c40.c (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { char pad[0x60]; float f60; float f64; } Link;
typedef struct { char pad[0x68]; Link *links[2]; char pad70[0xb4 - 0x70]; float fb4; float fb8; } Inner;
typedef struct { char pad[0xc]; void *fc; void *f10; char pad14[4]; Inner *f18; } Sub;
typedef struct { char pad[0x3c]; Sub *p3c; } Self;
extern void FUN_00108dac(Inner *);
extern void FUN_0022b498(void *, int, int);
extern void FUN_0022ed54(void *, int, Vec4);
extern void FUN_0023212c(Inner *, int, int);

void FUN_002351b4(Self *self, int mode, int arg, Vec4 v)
{
    if (mode == 0xe) {
        FUN_0022ed54(self->p3c->f10, arg, v);
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
        FUN_00108dac(in);
        FUN_0023212c(self->p3c->f18, arg, 0);
    } else {
        FUN_0022b498(self->p3c->fc, mode, arg);
    }
}
