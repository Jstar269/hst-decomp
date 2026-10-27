/* HSTMATCH module=EBOOT.BIN start=0x00235ff4 end=0x00236354 symbol=FUN_00235ff4 lang=c++ data=0x002f5214 */
/* LoadAiParamDoubles: data/common/parameter/AI_Param_Doubles.csv; see docs/DATA-TABLES.md Data: its string literals (2 strings, 0x002f5214-0x002f5245) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/table_records_load_001607a4.cpp); exact match verified; names and types await human review. */
/* Loads the table file at 0x2f5214 (data/common/parameter/AI/Param_D...) through a local reader object (derived class of the FUN_000649c0 base,
   two sub-objects built with FUN_0008c230 and torn down with FUN_00066338, destructor storing the vptr), first clearing the vector through the
   out-of-line shrink 0x8b1a8, reserving rows-1 elements (0x237138) and appending one 72-byte record per row: an id, 14 floats and 9 bytes read by
   the "Doubles..." column names (the field names below are taken from those strings). Names provisional. */
extern "C" {
extern char DAT_003070bc[];
extern char DAT_002f4a64[];
extern char DAT_002f4fdc[];
extern char DAT_002f4ff0[];
extern char DAT_002f5004[];
extern char DAT_002f5018[];
extern char DAT_002f5030[];
extern char DAT_002f5044[];
extern char DAT_002f5058[];
extern char DAT_002f506c[];
extern char DAT_002f5080[];
extern char DAT_002f5090[];
extern char DAT_002f50a4[];
extern char DAT_002f50bc[];
extern char DAT_002f50d0[];
extern char DAT_002f50e0[];
extern char DAT_002f50f4[];
extern char DAT_002f5104[];
extern char DAT_002f5114[];
extern char DAT_002f5124[];
extern char DAT_002f5134[];
extern char DAT_002f5140[];
extern char DAT_002f5150[];
extern char DAT_002f515c[];
extern char DAT_002f516c[];
extern void FUN_000649c0(void *);
extern void FUN_00064a08(void *, int);
extern void FUN_0008c230(void *);
extern void FUN_00066338(void *, int);
extern int FUN_000651b8(void *, char *, int, int, char *);
extern int FUN_000650e0(void *);
extern float FUN_000655f8(void *, int, char *);
extern int FUN_00065554(void *, int, char *);
extern void *FUN_000114c0(void *, int, int);
}

struct Tag {};

struct Entry {
    int id;
    float judgmentA, judgmentB, judgmentC, moveTimeCurve, moveTimeFast, moveTimeLate, moveError;
    float theoryRate, freeShot, returnTiming, returnTimingNet, returnError, snatch, frameshot;
    unsigned char circle, cross, triangle, front, half, backward, left, center, right;
};

struct Vec {
    Entry *data;
    unsigned size;
    unsigned cap;
};

extern "C" void FUN_0008b1a8(Vec *, int, Tag);
extern "C" void FUN_00237138(Vec *, unsigned);
extern "C" void FUN_00236354(Vec *, const Entry &);

struct Str {
    int w[4];
    Str() { FUN_0008c230(this); }
    ~Str() { FUN_00066338(this, 0); }
};

struct Base16 {
    int w[4];
    Base16() {
        FUN_000649c0(this);
        *(char **)this = DAT_003070bc;
    }
    ~Base16() { FUN_00064a08(this, 0); }
};

struct Res : Base16 {
    Str a;
    Str b;
    ~Res() { *(char **)this = DAT_003070bc; }
};

extern "C" void FUN_00235ff4(Vec *v)
{
    FUN_0008b1a8(v, v->size, Tag());
    Res r;
    if (FUN_000651b8(&r, "data/common/parameter/AI_Param_Doubles.csv", 0, 1, DAT_002f4a64)) {
        int n = FUN_000650e0(&r);
        if (v->cap < (unsigned)(n - 1)) {
            FUN_00237138(v, n - 1);
        }
        for (int i = 1; i < n; i++) {
            Entry e;
            FUN_000114c0(&e, 0, sizeof(Entry));
            e.id = FUN_00065554(&r, i, "Rank");
            e.judgmentA = FUN_000655f8(&r, i, DAT_002f4fdc);
            e.judgmentB = FUN_000655f8(&r, i, DAT_002f4ff0);
            e.judgmentC = FUN_000655f8(&r, i, DAT_002f5004);
            e.moveTimeCurve = FUN_000655f8(&r, i, DAT_002f5018);
            e.moveTimeFast = FUN_000655f8(&r, i, DAT_002f5030);
            e.moveTimeLate = FUN_000655f8(&r, i, DAT_002f5044);
            e.moveError = FUN_000655f8(&r, i, DAT_002f5058);
            e.theoryRate = FUN_000655f8(&r, i, DAT_002f506c);
            e.freeShot = FUN_000655f8(&r, i, DAT_002f5080);
            e.returnTiming = FUN_000655f8(&r, i, DAT_002f5090);
            e.returnTimingNet = FUN_000655f8(&r, i, DAT_002f50a4);
            e.returnError = FUN_000655f8(&r, i, DAT_002f50bc);
            e.snatch = FUN_000655f8(&r, i, DAT_002f50d0);
            e.frameshot = FUN_000655f8(&r, i, DAT_002f50e0);
            e.circle = FUN_00065554(&r, i, DAT_002f50f4);
            e.cross = FUN_00065554(&r, i, DAT_002f5104);
            e.triangle = FUN_00065554(&r, i, DAT_002f5114);
            e.front = FUN_00065554(&r, i, DAT_002f5124);
            e.half = FUN_00065554(&r, i, DAT_002f5134);
            e.backward = FUN_00065554(&r, i, DAT_002f5140);
            e.left = FUN_00065554(&r, i, DAT_002f5150);
            e.center = FUN_00065554(&r, i, DAT_002f515c);
            e.right = FUN_00065554(&r, i, DAT_002f516c);
            FUN_00236354(v, e);
        }
    }
}
