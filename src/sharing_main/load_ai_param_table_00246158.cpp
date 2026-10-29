/* HSTMATCH module=hstp_trans_main.prx start=0x00246158 end=0x002464b8 symbol=FUN_00246158 lang=c++ data=0x0039db3c */
/* Clone of src/eboot/load_ai_param_table_00235ff4.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x0039db3c-0x0039db6d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/table_records_load_001607a4.cpp); exact match verified; names and types await human review. */
/* Loads the table file at 0x39db3c (data/common/parameter/AI/Param_D...) through a local reader object (derived class of the FUN_00065884 base,
   two sub-objects built with FUN_0008d97c and torn down with FUN_0006778c, destructor storing the vptr), first clearing the vector through the
   out-of-line shrink 0x8b1a8, reserving rows-1 elements (0x237138) and appending one 72-byte record per row: an id, 14 floats and 9 bytes read by
   the "Doubles..." column names (the field names below are taken from those strings). Names provisional. */
extern "C" {
extern char DAT_003b0388[];
extern char DAT_0039d364[];
extern char DAT_0039d8dc[];
extern char DAT_0039d8f0[];
extern char DAT_0039d904[];
extern char DAT_0039d918[];
extern char DAT_0039d930[];
extern char DAT_0039d944[];
extern char DAT_0039d958[];
extern char DAT_0039d96c[];
extern char DAT_0039d980[];
extern char DAT_0039d990[];
extern char DAT_0039d9a4[];
extern char DAT_0039d9bc[];
extern char DAT_0039d9d0[];
extern char DAT_0039d9e0[];
extern char DAT_0039d9f4[];
extern char DAT_0039da04[];
extern char DAT_0039da14[];
extern char DAT_0039da24[];
extern char DAT_0039da34[];
extern char DAT_0039da40[];
extern char DAT_0039da50[];
extern char DAT_0039da5c[];
extern char DAT_0039da6c[];
extern void FUN_00065884(void *);
extern void FUN_000658cc(void *, int);
extern void FUN_0008d97c(void *);
extern void FUN_0006778c(void *, int);
extern int FUN_00066260(void *, char *, int, int, char *);
extern int FUN_00065fa4(void *);
extern float FUN_0006682c(void *, int, char *);
extern int FUN_00066700(void *, int, char *);
extern void *FUN_000114c0(void *, int, int);
}

/* Empty marker argument passed by value to the clear helper. */
struct Tag {};

/* One table row; field names follow the column names read below. */
struct Entry {
    int id;
    float judgmentA, judgmentB, judgmentC, moveTimeCurve, moveTimeFast, moveTimeLate, moveError;
    float theoryRate, freeShot, returnTiming, returnTimingNet, returnError, snatch, frameshot;
    unsigned char circle, cross, triangle, front, half, backward, left, center, right;
};

/* Vector of Entry (data, size, capacity). */
struct Vec {
    Entry *data;
    unsigned size;
    unsigned cap;
};

extern "C" void FUN_0008c898(Vec *, int, Tag);
extern "C" void FUN_0024729c(Vec *, unsigned);
extern "C" void FUN_002464b8(Vec *, const Entry &);

struct Str {
    int w[4];
    Str() { FUN_0008d97c(this); }
    ~Str() { FUN_0006778c(this, 0); }
};

struct Base16 {
    int w[4];
    Base16() {
        FUN_00065884(this);
        *(char **)this = DAT_003b0388;
    }
    ~Base16() { FUN_000658cc(this, 0); }
};

struct Res : Base16 {
    Str a;
    Str b;
    ~Res() { *(char **)this = DAT_003b0388; }
};

extern "C" void FUN_00246158(Vec *rows)
{
    /* clear the vector, then append one Entry per CSV row after the header row */
    FUN_0008c898(rows, rows->size, Tag());
    Res csv; /* local CSV reader */
    if (FUN_00066260(&csv, "data/common/parameter/AI_Param_Doubles.csv", 0, 1, DAT_0039d364)) {
        int n = FUN_00065fa4(&csv);
        if (rows->cap < (unsigned)(n - 1)) {
            FUN_0024729c(rows, n - 1);
        }
        for (int i = 1; i < n; i++) {
            Entry e;
            FUN_000114c0(&e, 0, sizeof(Entry));
            e.id = FUN_00066700(&csv, i, "Rank");
            e.judgmentA = FUN_0006682c(&csv, i, DAT_0039d8dc);
            e.judgmentB = FUN_0006682c(&csv, i, DAT_0039d8f0);
            e.judgmentC = FUN_0006682c(&csv, i, DAT_0039d904);
            e.moveTimeCurve = FUN_0006682c(&csv, i, DAT_0039d918);
            e.moveTimeFast = FUN_0006682c(&csv, i, DAT_0039d930);
            e.moveTimeLate = FUN_0006682c(&csv, i, DAT_0039d944);
            e.moveError = FUN_0006682c(&csv, i, DAT_0039d958);
            e.theoryRate = FUN_0006682c(&csv, i, DAT_0039d96c);
            e.freeShot = FUN_0006682c(&csv, i, DAT_0039d980);
            e.returnTiming = FUN_0006682c(&csv, i, DAT_0039d990);
            e.returnTimingNet = FUN_0006682c(&csv, i, DAT_0039d9a4);
            e.returnError = FUN_0006682c(&csv, i, DAT_0039d9bc);
            e.snatch = FUN_0006682c(&csv, i, DAT_0039d9d0);
            e.frameshot = FUN_0006682c(&csv, i, DAT_0039d9e0);
            e.circle = FUN_00066700(&csv, i, DAT_0039d9f4);
            e.cross = FUN_00066700(&csv, i, DAT_0039da04);
            e.triangle = FUN_00066700(&csv, i, DAT_0039da14);
            e.front = FUN_00066700(&csv, i, DAT_0039da24);
            e.half = FUN_00066700(&csv, i, DAT_0039da34);
            e.backward = FUN_00066700(&csv, i, DAT_0039da40);
            e.left = FUN_00066700(&csv, i, DAT_0039da50);
            e.center = FUN_00066700(&csv, i, DAT_0039da5c);
            e.right = FUN_00066700(&csv, i, DAT_0039da6c);
            FUN_002464b8(rows, e);
        }
    }
}
