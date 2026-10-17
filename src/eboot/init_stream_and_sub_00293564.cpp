/* HSTMATCH module=EBOOT.BIN start=0x00293564 end=0x0029365c symbol=FUN_00293564 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Stream {
    char pad0[8];
    int f8;
};

struct Sub {
    virtual void s0();
    virtual void s1(Stream *);
};

struct Obj {
    char pad0[0x70];
    Stream *stream;
    int f74;
    Sub *sub;
};

extern "C" {
extern char DAT_002ffb90[];
extern char DAT_002ffbac[];
void *FUN_00000bcc(unsigned);
void FUN_000143b0(char *, const char *, const char *, const char *);
Stream *FUN_00053670(void *, char *, const char *, int, int, int, int);
void FUN_00053718(Stream *, int);
Sub *FUN_00056b98(void *);
void FUN_0005743c(Sub *, int, int, int);
}

extern "C" void FUN_00293564(Obj *o, const char *name)
{
    char buf[256];
    FUN_000143b0(buf, DAT_002ffb90, name, name);
    Stream *s = (Stream *)FUN_00000bcc(0x30);
    if (s) s = FUN_00053670(s, buf, DAT_002ffbac, 0, 0, 0, 0);
    o->stream = s;
    if (s->f8 == 0 && s != 0) {
        FUN_00053718(s, 1);
        o->stream = 0;
    }
    Sub *m = (Sub *)FUN_00000bcc(0x1b0);
    if (m) m = FUN_00056b98(m);
    o->sub = m;
    if (o->stream != 0) {
        o->sub->s1(o->stream);
        if (o->f74 != 0) {
            FUN_0005743c(o->sub, 0, o->f74, 0);
        }
    }
}
