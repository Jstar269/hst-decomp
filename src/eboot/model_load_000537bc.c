/* HSTMATCH module=EBOOT.BIN start=0x000537bc end=0x00053a38 symbol=FUN_000537bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_00053a38(void *self);
extern void FUN_000149a8(char *dst, const char *src);
extern char *FUN_00014cfc(const char *s, int c);
extern int FUN_00014a40(const char *s);
extern void *FUN_00000a90(unsigned n);
extern int FUN_0004d140(const char *name);
extern void *FUN_0004ecb0(int id);
extern int FUN_0004eac4(void *h);
extern void FUN_0004ecbc(void *h);
extern void FUN_00049194(void);
extern void FUN_000491cc(void);
extern void *FUN_0004cc18(void *h, const char *name, int flag);
extern void FUN_002b79c8(void);
extern void *FUN_0004cad0(const char *name, int a, int b, int c);
extern int FUN_0002fdc8(void *h);
extern void FUN_0004f010(char *tag, int code, char *file, int line, char *expr);
extern void FUN_0004f374(char *tag, void *h, char *base, int p6, int flag);
extern int FUN_0002fe08(void *h);
extern void *FUN_00010184(int a, int size);
extern void FUN_000351c8(void *h, void *buf);
extern void FUN_00034aa4(void *h, void *buf, void *buf2);
extern void *FUN_00000bcc(int n);
extern void *FUN_0004ad98(void *p, int a, void *self, char *base, int a4);

extern char DAT_00311170[];
extern char DAT_002d0ecc[];
extern char DAT_002d0ed8[];

#define PATH_SEPARATOR '/'
#define PATH_BUF_SIZE 256
#define LOAD_FLAG_BIND 0x1    /* passed on to the binding helper as a bool */
#define LOAD_FLAG_ACQUIRE 0x2 /* first acquire a fresh handle for the entry count */
#define ENTRY_SIZE_SHIFT 6    /* each entry owns a 64-byte slot in the buffer */
#define ENTRY_BUF_ALIGN 16
#define HOOK_OBJ_SIZE 12
#define LOAD_ERROR_LINE 202   /* source line reported with a load error */

/* Loaded model: copy of its name, entry count, resource handle, per-entry buffer and optional hook object. */
typedef struct {
    char *name;   /* 0x00 heap copy of the file name */
    int count;    /* 0x04 number of entries reported for the name */
    void *handle; /* 0x08 loaded resource handle */
    void *buf;    /* 0x0c per-entry buffer */
    void *obj;    /* 0x10 optional hook object built from a3 */
} Self;

/* Loads the model called name (resources looked up under base, or under the name's own directory when base is 0).
   Returns 1 on success; on any failure releases everything again and returns 0. */
int FUN_000537bc(Self *self, const char *name, char *base, int a3, int a4, int a5, unsigned flags)
{
    char buf[PATH_BUF_SIZE];
    char *q;
    void *h;
    void *p;
    int n;

    FUN_00053a38(self);
    if (base == 0) {
        FUN_000149a8(buf, name);
        q = FUN_00014cfc(buf, PATH_SEPARATOR);
        if (q != 0) {
            q = q + 1;
        } else {
            q = buf;
        }
        *q = 0; /* keep only the directory part */
        base = buf;
    }
    n = FUN_00014a40(name);
    self->name = (char *)FUN_00000a90(n + 1);
    FUN_000149a8(self->name, name);
    n = FUN_0004d140(name);
    self->count = n;
    if (n > 0) {
        if ((flags & LOAD_FLAG_ACQUIRE) != 0) {
            FUN_00049194();
            h = FUN_0004ecb0(self->count);
            if (h != 0) {
                if (FUN_0004eac4(h) != 0) {
                    self->handle = h;
                } else {
                    FUN_0004ecbc(h);
                }
            }
            FUN_000491cc();
            h = self->handle;
        } else {
            h = self->handle;
        }
        if (h != 0) {
            self->handle = FUN_0004cc18(h, name, 0);
            FUN_002b79c8();
        } else {
            self->handle = FUN_0004cad0(name, 0, 16, 1);
        }
        h = self->handle;
        if (h != 0) {
            FUN_00049194();
            n = FUN_0002fdc8(self->handle);
            FUN_000491cc();
            if (n != 0) {
                FUN_0004f010(DAT_00311170, n, DAT_002d0ecc, LOAD_ERROR_LINE, DAT_002d0ed8);
            } else {
                FUN_0004f374(DAT_00311170, self->handle, base, a5, (flags & LOAD_FLAG_BIND) != 0);
                FUN_00049194();
                n = self->handle != 0 ? FUN_0002fe08(self->handle) : 0;
                self->buf = FUN_00010184(ENTRY_BUF_ALIGN, n << ENTRY_SIZE_SHIFT);
                FUN_000351c8(self->handle, self->buf);
                FUN_00034aa4(self->handle, self->buf, self->buf);
                FUN_000491cc();
                if (a3 != 0) {
                    p = FUN_00000bcc(HOOK_OBJ_SIZE);
                    if (p != 0) {
                        p = FUN_0004ad98(p, a3, self, base, a4);
                    }
                    self->obj = p;
                }
                return 1;
            }
        }
    }
    FUN_00053a38(self);
    return 0;
}
