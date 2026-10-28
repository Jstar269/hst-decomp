/* HSTMATCH module=hstp_trans_main.prx start=0x0005427c end=0x000544f8 symbol=FUN_0005427c lang=c99 */
/* Clone of src/eboot/model_load_000537bc.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_000544f8(void *self);
extern void FUN_000149a8(char *dst, const char *src);
extern char *FUN_00014cfc(const char *s, int c);
extern int FUN_00014a40(const char *s);
extern void *FUN_00000a90(unsigned n);
extern int FUN_0004d4b8(const char *name);
extern void *FUN_0004f3f8(int id);
extern int FUN_0004f17c(void *h);
extern void FUN_0004f404(void *h);
extern void FUN_00048fb8(void);
extern void FUN_00049020(void);
extern void *FUN_0004cee8(void *h, const char *name, int flag);
extern void FUN_002c7768(void);
extern void *FUN_0004cd8c(const char *name, int a, int b, int c);
extern int FUN_0002fdf0(void *h);
extern void FUN_0004f864(char *tag, int code, char *file, int line, char *expr);
extern void FUN_0004fbfc(char *tag, void *h, char *base, int p6, int flag);
extern int FUN_0002fe30(void *h);
extern void *FUN_00010184(int a, int size);
extern void FUN_000351f0(void *h, void *buf);
extern void FUN_00034acc(void *h, void *buf, void *buf2);
extern void *FUN_00000bcc(int n);
extern void *FUN_0004af74(void *p, int a, void *self, char *base, int a4);

extern char DAT_003ba4b0[];
extern char DAT_00376a64[];
extern char DAT_00376a70[];

typedef struct {
    char *name;
    int count;
    void *handle;
    void *buf;
    void *obj;
} Self;

int FUN_0005427c(Self *self, const char *name, char *base, int a3, int a4, int a5, unsigned flags)
{
    char buf[256];
    char *q;
    void *h;
    void *p;
    int n;

    FUN_000544f8(self);
    if (base == 0) {
        FUN_000149a8(buf, name);
        q = FUN_00014cfc(buf, '/');
        if (q != 0) {
            q = q + 1;
        } else {
            q = buf;
        }
        *q = 0;
        base = buf;
    }
    n = FUN_00014a40(name);
    self->name = (char *)FUN_00000a90(n + 1);
    FUN_000149a8(self->name, name);
    n = FUN_0004d4b8(name);
    self->count = n;
    if (n > 0) {
        if ((flags & 2) != 0) {
            FUN_00048fb8();
            h = FUN_0004f3f8(self->count);
            if (h != 0) {
                if (FUN_0004f17c(h) != 0) {
                    self->handle = h;
                } else {
                    FUN_0004f404(h);
                }
            }
            FUN_00049020();
            h = self->handle;
        } else {
            h = self->handle;
        }
        if (h != 0) {
            self->handle = FUN_0004cee8(h, name, 0);
            FUN_002c7768();
        } else {
            self->handle = FUN_0004cd8c(name, 0, 16, 1);
        }
        h = self->handle;
        if (h != 0) {
            FUN_00048fb8();
            n = FUN_0002fdf0(self->handle);
            FUN_00049020();
            if (n != 0) {
                FUN_0004f864(DAT_003ba4b0, n, DAT_00376a64, 202, DAT_00376a70);
            } else {
                FUN_0004fbfc(DAT_003ba4b0, self->handle, base, a5, (flags & 1) != 0);
                FUN_00048fb8();
                n = self->handle != 0 ? FUN_0002fe30(self->handle) : 0;
                self->buf = FUN_00010184(16, n << 6);
                FUN_000351f0(self->handle, self->buf);
                FUN_00034acc(self->handle, self->buf, self->buf);
                FUN_00049020();
                if (a3 != 0) {
                    p = FUN_00000bcc(12);
                    if (p != 0) {
                        p = FUN_0004af74(p, a3, self, base, a4);
                    }
                    self->obj = p;
                }
                return 1;
            }
        }
    }
    FUN_000544f8(self);
    return 0;
}
