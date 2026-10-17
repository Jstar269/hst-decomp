/* HSTMATCH module=hstp_trans_main.prx start=0x002a4b70 end=0x002a4c68 symbol=FUN_002a4b70 lang=c++ */
/* Clone of src/eboot/init_stream_and_sub_00293564.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
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
extern char DAT_003a8a9c[];
extern char DAT_003a8ab8[];
void *FUN_00000bcc(unsigned);
void FUN_000143b0(char *, const char *, const char *, const char *);
Stream *FUN_00054130(void *, char *, const char *, int, int, int, int);
void FUN_000541d8(Stream *, int);
Sub *FUN_000577ec(void *);
void FUN_00058090(Sub *, int, int, int);
}

extern "C" void FUN_002a4b70(Obj *o, const char *name)
{
    char buf[256];
    FUN_000143b0(buf, DAT_003a8a9c, name, name);
    Stream *s = (Stream *)FUN_00000bcc(0x30);
    if (s) s = FUN_00054130(s, buf, DAT_003a8ab8, 0, 0, 0, 0);
    o->stream = s;
    if (s->f8 == 0 && s != 0) {
        FUN_000541d8(s, 1);
        o->stream = 0;
    }
    Sub *m = (Sub *)FUN_00000bcc(0x1b0);
    if (m) m = FUN_000577ec(m);
    o->sub = m;
    if (o->stream != 0) {
        o->sub->s1(o->stream);
        if (o->f74 != 0) {
            FUN_00058090(o->sub, 0, o->f74, 0);
        }
    }
}
