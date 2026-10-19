/* HSTMATCH module=hstp_trans_main.prx start=0x002a2ff0 end=0x002a308c symbol=FUN_002a2ff0 lang=c++ */
/* Clone of src/eboot/FUN_002919e4.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-written from the disassembly; exact match verified. Names and types await human review. */
/* Matching idiom: a 12-byte `V3 v = *src;` local stages the record through sp+20..28 before the
   memberwise stores; the error case is the fall-through (`if (r < 0) { ... return 0; } return 1;`),
   and keeping the result in a local `r` leaves it in v0 for both the field store and the error call. */
struct V3 {
    float x, y, z;
};

struct Self {
    char pad0[4];
    int f4;         /* 0x04 */
    float fx;       /* 0x08 */
    float fy;       /* 0x0c */
    float fz;       /* 0x10 */
    int f14;        /* 0x14 */
    int f18;        /* 0x18 */
};

extern "C" {
    extern void LAB_002a2fe0();
    extern char DAT_003a8910;
    extern int FUN_002c76c0(int, void *, int, int, int, int);
    extern void FUN_002a130c(void *, int);
}

extern "C" int FUN_002a2ff0(Self *p, int b, int c, const V3 *src, int e5, int e6, int e7)
{
    V3 v = *src;        /* 12-byte local -> the sp+20 float staging MWCC emits */
    p->f4 = c;
    p->fx = v.x;
    p->fy = v.y;
    p->fz = v.z;
    p->f18 = b;
    int r = FUN_002c76c0(b, &LAB_002a2fe0, e5, e6, e7, 0);
    p->f14 = r;
    if (r < 0) {
        FUN_002a130c(&DAT_003a8910, r);
        return 0;
    }
    return 1;
}
