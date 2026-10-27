/* HSTMATCH module=EBOOT.BIN start=0x00234898 end=0x0023568c symbol=FUN_00234898 lang=c++ */
/* Hand-written reconstruction from the disassembly (same reader/record recipe as load_ai_param_table_00235ff4.cpp; field names from the CSV column strings); exact match verified; matching idiom: the vector is emptied through an inline `shrink(n, Alloc)` with an unused by-value empty parameter (its frame slot puts the three spilled values at retail's 52/56/60); ShotVariation's out-of-line ctor/dtor and operator new[] are named in symbols/EBOOT.BIN.txt; names and types await human review. */
struct Tag {};
struct Alloc {};

extern "C" {
extern char DAT_003070bc[];
extern char DAT_002f4a64[];
extern char DAT_002f4a68[];
extern char DAT_002f4a6c[];
extern char DAT_002f4a7c[];
extern char DAT_002f4a90[];
extern char DAT_002f4aa0[];
extern char DAT_002f4ab0[];
extern char DAT_002f4ac0[];
extern char DAT_002f4acc[];
extern char DAT_002f4ad4[];
extern char DAT_002f4ae0[];
extern char DAT_002f4af0[];
extern char DAT_002f4afc[];
extern char DAT_002f4b0c[];
extern char DAT_002f4b18[];
extern char DAT_002f4b24[];
extern char DAT_002f4b34[];
extern char DAT_002f4b44[];
extern char DAT_002f4b50[];
extern char DAT_002f4b5c[];
extern char DAT_002f4b6c[];
extern char DAT_002f4b78[];
extern char DAT_002f4b88[];
extern char DAT_002f4b9c[];
extern char DAT_002f4bb8[];
extern char DAT_002f4bcc[];
extern char DAT_002f4be8[];
extern char DAT_002f4bf4[];
extern char DAT_002f4c08[];
extern char DAT_002f4c20[];
extern char DAT_002f4c38[];
extern char DAT_002f4c4c[];
extern char DAT_002f4c5c[];
extern char DAT_002f4c70[];
extern char DAT_002f4c84[];
extern char DAT_002f4c94[];
extern char DAT_002f4ca0[];
extern char DAT_002f4cb0[];
extern char DAT_002f4cc0[];
extern char DAT_002f4cd4[];
extern char DAT_002f4ce8[];
extern char DAT_002f4cfc[];
extern char DAT_002f4d10[];
extern char DAT_002f4d1c[];
extern char DAT_002f4d28[];
extern char DAT_002f4d34[];
extern char DAT_002f4d40[];
extern char DAT_002f4d4c[];
extern char DAT_002f4d58[];
extern char DAT_002f4d64[];
extern char DAT_002f4d70[];
extern char DAT_002f4d80[];
extern char DAT_002f4d90[];
extern char DAT_002f4da0[];
extern char DAT_002f4dac[];
extern char DAT_002f4db8[];
extern char DAT_002f4dc4[];
extern char DAT_002f4dd0[];
extern char DAT_002f4de0[];
extern char DAT_002f4dec[];
extern char DAT_002f4dfc[];
extern char DAT_002f4e10[];
extern char DAT_002f4e24[];
extern char DAT_002f4e38[];
extern char DAT_002f4e4c[];
extern char DAT_002f4e60[];
extern char DAT_002f4e78[];
extern char DAT_002f4e84[];
extern char DAT_002f4e98[];
extern char DAT_002f4ea4[];
extern char DAT_002f4eb0[];
extern char DAT_002f4ec8[];
extern char DAT_002f4ee4[];
extern char DAT_002f4efc[];
extern char DAT_002f4f14[];
extern char DAT_002f4f2c[];
extern char DAT_002f4f40[];
extern char DAT_002f4f5c[];
extern char DAT_002f4f74[];
extern char DAT_002f4f90[];
extern char DAT_002f4fac[];
extern char DAT_002f4fc0[];
extern char DAT_002f4fcc[];
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
extern const char *DAT_002f4958[3][2];
extern const char *DAT_002f4994[6];
extern const char *DAT_002f49bc[2];
extern const char *DAT_002f4a34[12];
extern char DAT_002c9ee4[];
void FUN_000649c0(void *);
void FUN_00064a08(void *, int);
void FUN_0008c230(void *);
void FUN_00066338(void *, int);
int FUN_000651b8(void *, const char *, int, int, char *);
int FUN_000650e0(void *);
float FUN_000655f8(void *, int, const char *);
int FUN_00065554(void *, int, const char *);
int FUN_00065364(void *, const char *);
const char *FUN_0006517c(void *, int, int);
int FUN_00065104(void *, int, int);
const char *FUN_0006569c(void *, int, const char *);
void FUN_000143b0(char *, const char *, ...);
int FUN_00014a40(const char *);
char *FUN_000149a8(char *, const char *);
int FUN_0000fe64(int);
int FUN_0000d62c(const char *);
char *FUN_00015ea0(char *, const char *);
char *FUN_00014d64(const char *, const char *);
}

struct ShortVec {
    short *data;
    unsigned size;
    unsigned cap;
    void push_back(const short &x);
};

extern "C" void FUN_00236808(ShortVec *, const short *, Tag);

inline void ShortVec::push_back(const short &x)
{
    if (size < cap) {
        ++size;
        data[size - 1] = x;
    } else {
        FUN_00236808(this, &x, Tag());
    }
}

struct ShotVariation {
    ShortVec v[2];
    ShotVariation();
    ~ShotVariation();
};

struct MoveTime {
    float curve;
    short fast;
    short late;
};

struct AiParam {
    int id;
    char name[16];
    float moveForecast;
    float moveForecastSkill;
    MoveTime moveTime[6];
    short moveGood;
    short moveBad;
    float moveSmash;
    int moveForeAdjust;
    float moveError;
    float moveErrorSmash;
    short moveAdvance;
    short moveKeep;
    short moveServiceline;
    short moveBaseline;
    short moveShort;
    short moveFore;
    short moveGoodHeight;
    short moveHigh;
    short moveStrongshot;
    float moveCertainshotId1;
    float moveCertainshotFrequency1;
    float moveCertainshotId2;
    float moveCertainshotFrequency2;
    float moveOutshot;
    int moveOutshotReaction;
    float moveSidespinForecast;
    float moveSidespinReaction;
    int movePursuePattern;
    float shotSituation;
    float shotAimTimingMin;
    float shotAimTimingMax;
    float shotAccuracy;
    short shotWidth;
    short shotWidthNet;
    short shotTimingError;
    short shotTimingErrorNet;
    float shotSwingmissMin;
    float shotSwingmissMax;
    float shotSwingmissMaxP;
    signed char shotMissA;
    signed char shotMissB;
    signed char shotMissC;
    signed char shotMissD;
    signed char shotMissE;
    signed char shotMissF;
    signed char shotMissG;
    signed char shotMissH;
    ShotVariation variation[3];
    unsigned char pattern[15];
    float returnTiming;
    float returnTimingNet;
    float returnError;
    float returnStop;
    float returnWait;
    float returnFront;
    float returnCenter;
    float returnBest;
    float returnBackward;
    float returnNetdashAll;
    float returnNetdashSlice;
    float returnNetdashSnatch;
    float returnNetdashTime;
    float returnNetdashServe;
    float returnNetdashReceive;
    signed char returnBias;
    signed char returnLimitedshot;
    float serveCare;
    float serve[2][12];
    float serveReceiveForecast;
    float serveReceiveForecastSkill;
    float serveReceiveTimeCurve;
    float serveReceiveTimeFast;
    float serveReceiveTimeLate;
    float serveReceiveError;
    float serveReceivePositionFirst;
    float serveReceiveAdjustFirst;
    float serveReceivePositionSecond;
    float serveReceiveAdjustSecond;
    signed char serveReceiveDash;
    float doublesJudgmentA;
    float doublesJudgmentB;
    float doublesJudgmentC;
    float doublesMoveTimeCurve;
    float doublesMoveTimeFast;
    float doublesMoveTimeLate;
    float doublesMoveError;
    float doublesTheoryRate;
    float doublesFreeShot;
    float doublesReturnTiming;
    float doublesReturnTimingNet;
    float doublesReturnError;
    float doublesSnatch;
    float doublesFrameshot;
    signed char doublesCircle;
    signed char doublesCross;
    signed char doublesTriangle;
    signed char doublesFront;
    signed char doublesHalf;
    signed char doublesBackward;
    signed char doublesLeft;
    signed char doublesCenter;
    signed char doublesRight;
};

struct AiParamVec;

extern "C" {
void FUN_00236db4(AiParamVec *, unsigned, Tag);
void FUN_00236e38(AiParamVec *, unsigned);
void FUN_0023568c(AiParamVec *, const AiParam &);
}

struct AiParamVec {
    AiParam *data;
    unsigned size;
    unsigned cap;
    void shrink(unsigned n, Alloc) { FUN_00236db4(this, n, Tag()); }
};

struct Str {
    int w[4];
    Str() { FUN_0008c230(this); }
    ~Str() { FUN_00066338(this, 0); }
};

struct Base16 {
    int w[4];
    Base16()
    {
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

struct AiParamTable {
    char pad0[0x14];
    AiParamVec params;
};

extern "C" void FUN_00234898(AiParamTable *self, const char *path)
{
    self->params.shrink(self->params.size, Alloc());
    Res r;
    if (FUN_000651b8(&r, path, 0, 1, DAT_002f4a64)) {
        int n = FUN_000650e0(&r);
        if (self->params.cap < (unsigned)(n - 1)) {
            FUN_00236e38(&self->params, n - 1);
        }
        for (int i = 1; i < n; i++) {
            AiParam rec;
            int col = FUN_00065364(&r, DAT_002f4a68);
            if (col >= 0) {
                const char *s = FUN_0006517c(&r, i, col);
                if (s != 0) {
                    FUN_000149a8(rec.name, s);
                    while (!FUN_0000fe64(*s))
                        s++;
                    rec.id = FUN_0000d62c(s);
                } else {
                    rec.id = FUN_00065104(&r, i, col);
                }
            } else {
                rec.id = 0;
            }
            rec.moveForecast = FUN_000655f8(&r, i, DAT_002f4a6c);
            rec.moveForecastSkill = FUN_000655f8(&r, i, DAT_002f4a7c);
            for (unsigned k = 0; k < 6; k++) {
                char key[64];
                FUN_000143b0(key, DAT_002f4a90, DAT_002f4994[k]);
                rec.moveTime[k].curve = FUN_000655f8(&r, i, key);
                FUN_000143b0(key, DAT_002f4aa0, DAT_002f4994[k]);
                rec.moveTime[k].fast = FUN_00065554(&r, i, key);
                FUN_000143b0(key, DAT_002f4ab0, DAT_002f4994[k]);
                rec.moveTime[k].late = FUN_00065554(&r, i, key);
            }
            rec.moveGood = FUN_00065554(&r, i, DAT_002f4ac0);
            rec.moveBad = FUN_00065554(&r, i, DAT_002f4acc);
            rec.moveSmash = FUN_000655f8(&r, i, DAT_002f4ad4);
            rec.moveForeAdjust = FUN_00065554(&r, i, DAT_002f4ae0);
            rec.moveError = FUN_000655f8(&r, i, DAT_002f4af0);
            rec.moveErrorSmash = FUN_000655f8(&r, i, DAT_002f4afc);
            rec.moveAdvance = FUN_00065554(&r, i, DAT_002f4b0c);
            rec.moveKeep = FUN_00065554(&r, i, DAT_002f4b18);
            rec.moveServiceline = FUN_00065554(&r, i, DAT_002f4b24);
            rec.moveBaseline = FUN_00065554(&r, i, DAT_002f4b34);
            rec.moveShort = FUN_00065554(&r, i, DAT_002f4b44);
            rec.moveFore = FUN_00065554(&r, i, DAT_002f4b50);
            rec.moveGoodHeight = FUN_00065554(&r, i, DAT_002f4b5c);
            rec.moveHigh = FUN_00065554(&r, i, DAT_002f4b6c);
            rec.moveStrongshot = FUN_00065554(&r, i, DAT_002f4b78);
            rec.moveCertainshotId1 = FUN_000655f8(&r, i, DAT_002f4b88);
            rec.moveCertainshotFrequency1 = FUN_000655f8(&r, i, DAT_002f4b9c);
            rec.moveCertainshotId2 = FUN_000655f8(&r, i, DAT_002f4bb8);
            rec.moveCertainshotFrequency2 = FUN_000655f8(&r, i, DAT_002f4bcc);
            rec.moveOutshot = FUN_000655f8(&r, i, DAT_002f4be8);
            rec.moveOutshotReaction = FUN_00065554(&r, i, DAT_002f4bf4);
            rec.moveSidespinForecast = FUN_000655f8(&r, i, DAT_002f4c08);
            rec.moveSidespinReaction = FUN_000655f8(&r, i, DAT_002f4c20);
            rec.movePursuePattern = FUN_00065554(&r, i, DAT_002f4c38);
            rec.shotSituation = FUN_000655f8(&r, i, DAT_002f4c4c);
            rec.shotAimTimingMin = FUN_000655f8(&r, i, DAT_002f4c5c);
            rec.shotAimTimingMax = FUN_000655f8(&r, i, DAT_002f4c70);
            rec.shotAccuracy = FUN_000655f8(&r, i, DAT_002f4c84);
            rec.shotWidth = FUN_00065554(&r, i, DAT_002f4c94);
            rec.shotWidthNet = FUN_00065554(&r, i, DAT_002f4ca0);
            rec.shotTimingError = FUN_00065554(&r, i, DAT_002f4cb0);
            rec.shotTimingErrorNet = FUN_00065554(&r, i, DAT_002f4cc0);
            rec.shotSwingmissMin = FUN_000655f8(&r, i, DAT_002f4cd4);
            rec.shotSwingmissMax = FUN_000655f8(&r, i, DAT_002f4ce8);
            rec.shotSwingmissMaxP = FUN_000655f8(&r, i, DAT_002f4cfc);
            rec.shotMissA = FUN_00065554(&r, i, DAT_002f4d10);
            rec.shotMissB = FUN_00065554(&r, i, DAT_002f4d1c);
            rec.shotMissC = FUN_00065554(&r, i, DAT_002f4d28);
            rec.shotMissD = FUN_00065554(&r, i, DAT_002f4d34);
            rec.shotMissE = FUN_00065554(&r, i, DAT_002f4d40);
            rec.shotMissF = FUN_00065554(&r, i, DAT_002f4d4c);
            rec.shotMissG = FUN_00065554(&r, i, DAT_002f4d58);
            rec.shotMissH = FUN_00065554(&r, i, DAT_002f4d64);
            for (unsigned k = 0; k < 3; k++) {
                for (int j = 0; j < 2; j++) {
                    const char *cell = FUN_0006569c(&r, i, DAT_002f4958[k][j]);
                    if (cell != 0) {
                        char *buf = new char[FUN_00014a40(cell) + 1];
                        FUN_000149a8(buf, cell);
                        for (char *t = FUN_00015ea0(buf, DAT_002c9ee4); t != 0; t = FUN_00015ea0(0, DAT_002c9ee4))
                            rec.variation[k].v[j].push_back(FUN_0000d62c(t));
                        if (buf != 0)
                            delete[] buf;
                    }
                }
            }
            for (unsigned k = 0; k < 15; k++) {
                char key[64];
                FUN_000143b0(key, DAT_002f4d70, k + 1);
                int v = 0;
                int c = FUN_00065364(&r, key);
                if (c >= 0)
                    v = FUN_00065104(&r, i, c);
                rec.pattern[k] = v;
            }
            rec.returnTiming = FUN_000655f8(&r, i, DAT_002f4d80);
            rec.returnTimingNet = FUN_000655f8(&r, i, DAT_002f4d90);
            rec.returnError = FUN_000655f8(&r, i, DAT_002f4da0);
            rec.returnStop = FUN_000655f8(&r, i, DAT_002f4dac);
            rec.returnWait = FUN_000655f8(&r, i, DAT_002f4db8);
            rec.returnFront = FUN_000655f8(&r, i, DAT_002f4dc4);
            rec.returnCenter = FUN_000655f8(&r, i, DAT_002f4dd0);
            rec.returnBest = FUN_000655f8(&r, i, DAT_002f4de0);
            rec.returnBackward = FUN_000655f8(&r, i, DAT_002f4dec);
            rec.returnNetdashAll = FUN_000655f8(&r, i, DAT_002f4dfc);
            rec.returnNetdashSlice = FUN_000655f8(&r, i, DAT_002f4e10);
            rec.returnNetdashSnatch = FUN_000655f8(&r, i, DAT_002f4e24);
            rec.returnNetdashTime = FUN_000655f8(&r, i, DAT_002f4e38);
            rec.returnNetdashServe = FUN_000655f8(&r, i, DAT_002f4e4c);
            rec.returnNetdashReceive = FUN_000655f8(&r, i, DAT_002f4e60);
            rec.returnBias = FUN_00065554(&r, i, DAT_002f4e78);
            rec.returnLimitedshot = FUN_00065554(&r, i, DAT_002f4e84);
            rec.serveCare = FUN_000655f8(&r, i, DAT_002f4e98);
            for (unsigned k = 0; k < 2; k++) {
                for (unsigned j = 0; j < 12; j++) {
                    char key[64];
                    FUN_000143b0(key, DAT_002f4ea4, DAT_002f49bc[k], DAT_002f4a34[j]);
                    rec.serve[k][j] = FUN_000655f8(&r, i, key);
                }
            }
            rec.serveReceiveForecast = FUN_000655f8(&r, i, DAT_002f4eb0);
            rec.serveReceiveForecastSkill = FUN_000655f8(&r, i, DAT_002f4ec8);
            rec.serveReceiveTimeCurve = FUN_000655f8(&r, i, DAT_002f4ee4);
            rec.serveReceiveTimeFast = FUN_000655f8(&r, i, DAT_002f4efc);
            rec.serveReceiveTimeLate = FUN_000655f8(&r, i, DAT_002f4f14);
            rec.serveReceiveError = FUN_000655f8(&r, i, DAT_002f4f2c);
            rec.serveReceivePositionFirst = FUN_000655f8(&r, i, DAT_002f4f40);
            rec.serveReceiveAdjustFirst = FUN_000655f8(&r, i, DAT_002f4f5c);
            rec.serveReceivePositionSecond = FUN_000655f8(&r, i, DAT_002f4f74);
            rec.serveReceiveAdjustSecond = FUN_000655f8(&r, i, DAT_002f4f90);
            rec.serveReceiveDash = FUN_00065554(&r, i, DAT_002f4fac);
            if (FUN_00014d64(path, DAT_002f4fc0) != 0 || FUN_00014d64(path, DAT_002f4fcc) != 0) {
                rec.doublesJudgmentA = FUN_000655f8(&r, i, DAT_002f4fdc);
                rec.doublesJudgmentB = FUN_000655f8(&r, i, DAT_002f4ff0);
                rec.doublesJudgmentC = FUN_000655f8(&r, i, DAT_002f5004);
                rec.doublesMoveTimeCurve = FUN_000655f8(&r, i, DAT_002f5018);
                rec.doublesMoveTimeFast = FUN_000655f8(&r, i, DAT_002f5030);
                rec.doublesMoveTimeLate = FUN_000655f8(&r, i, DAT_002f5044);
                rec.doublesMoveError = FUN_000655f8(&r, i, DAT_002f5058);
                rec.doublesTheoryRate = FUN_000655f8(&r, i, DAT_002f506c);
                rec.doublesFreeShot = FUN_000655f8(&r, i, DAT_002f5080);
                rec.doublesReturnTiming = FUN_000655f8(&r, i, DAT_002f5090);
                rec.doublesReturnTimingNet = FUN_000655f8(&r, i, DAT_002f50a4);
                rec.doublesReturnError = FUN_000655f8(&r, i, DAT_002f50bc);
                rec.doublesSnatch = FUN_000655f8(&r, i, DAT_002f50d0);
                rec.doublesFrameshot = FUN_000655f8(&r, i, DAT_002f50e0);
                rec.doublesCircle = FUN_00065554(&r, i, DAT_002f50f4);
                rec.doublesCross = FUN_00065554(&r, i, DAT_002f5104);
                rec.doublesTriangle = FUN_00065554(&r, i, DAT_002f5114);
                rec.doublesFront = FUN_00065554(&r, i, DAT_002f5124);
                rec.doublesHalf = FUN_00065554(&r, i, DAT_002f5134);
                rec.doublesBackward = FUN_00065554(&r, i, DAT_002f5140);
                rec.doublesLeft = FUN_00065554(&r, i, DAT_002f5150);
                rec.doublesCenter = FUN_00065554(&r, i, DAT_002f515c);
                rec.doublesRight = FUN_00065554(&r, i, DAT_002f516c);
            }
            FUN_0023568c(&self->params, rec);
        }
    }
}
