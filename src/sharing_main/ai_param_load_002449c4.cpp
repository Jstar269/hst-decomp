/* HSTMATCH module=hstp_trans_main.prx start=0x002449c4 end=0x002457b8 symbol=FUN_002449c4 lang=c++ */
/* Clone of src/eboot/ai_param_load_00234898.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (same reader/record recipe as load_ai_param_table_00235ff4.cpp; field names from the CSV column strings); exact match verified; matching idiom: the vector is emptied through an inline `shrink(n, Alloc)` with an unused by-value empty parameter (its frame slot puts the three spilled values at retail's 52/56/60); ShotVariation's out-of-line ctor/dtor and operator new[] are named in symbols/EBOOT.BIN.txt; names and types await human review. */
struct Tag {};
struct Alloc {};

extern "C" {
extern char DAT_003b0388[];
extern char DAT_0039d364[];
extern char DAT_0039d368[];
extern char DAT_0039d36c[];
extern char DAT_0039d37c[];
extern char DAT_0039d390[];
extern char DAT_0039d3a0[];
extern char DAT_0039d3b0[];
extern char DAT_0039d3c0[];
extern char DAT_0039d3cc[];
extern char DAT_0039d3d4[];
extern char DAT_0039d3e0[];
extern char DAT_0039d3f0[];
extern char DAT_0039d3fc[];
extern char DAT_0039d40c[];
extern char DAT_0039d418[];
extern char DAT_0039d424[];
extern char DAT_0039d434[];
extern char DAT_0039d444[];
extern char DAT_0039d450[];
extern char DAT_0039d45c[];
extern char DAT_0039d46c[];
extern char DAT_0039d478[];
extern char DAT_0039d488[];
extern char DAT_0039d49c[];
extern char DAT_0039d4b8[];
extern char DAT_0039d4cc[];
extern char DAT_0039d4e8[];
extern char DAT_0039d4f4[];
extern char DAT_0039d508[];
extern char DAT_0039d520[];
extern char DAT_0039d538[];
extern char DAT_0039d54c[];
extern char DAT_0039d55c[];
extern char DAT_0039d570[];
extern char DAT_0039d584[];
extern char DAT_0039d594[];
extern char DAT_0039d5a0[];
extern char DAT_0039d5b0[];
extern char DAT_0039d5c0[];
extern char DAT_0039d5d4[];
extern char DAT_0039d5e8[];
extern char DAT_0039d5fc[];
extern char DAT_0039d610[];
extern char DAT_0039d61c[];
extern char DAT_0039d628[];
extern char DAT_0039d634[];
extern char DAT_0039d640[];
extern char DAT_0039d64c[];
extern char DAT_0039d658[];
extern char DAT_0039d664[];
extern char DAT_0039d670[];
extern char DAT_0039d680[];
extern char DAT_0039d690[];
extern char DAT_0039d6a0[];
extern char DAT_0039d6ac[];
extern char DAT_0039d6b8[];
extern char DAT_0039d6c4[];
extern char DAT_0039d6d0[];
extern char DAT_0039d6e0[];
extern char DAT_0039d6ec[];
extern char DAT_0039d6fc[];
extern char DAT_0039d710[];
extern char DAT_0039d724[];
extern char DAT_0039d738[];
extern char DAT_0039d74c[];
extern char DAT_0039d760[];
extern char DAT_0039d778[];
extern char DAT_0039d784[];
extern char DAT_0039d798[];
extern char DAT_0039d7a4[];
extern char DAT_0039d7b0[];
extern char DAT_0039d7c8[];
extern char DAT_0039d7e4[];
extern char DAT_0039d7fc[];
extern char DAT_0039d814[];
extern char DAT_0039d82c[];
extern char DAT_0039d840[];
extern char DAT_0039d85c[];
extern char DAT_0039d874[];
extern char DAT_0039d890[];
extern char DAT_0039d8ac[];
extern char DAT_0039d8c0[];
extern char DAT_0039d8cc[];
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
extern const char *DAT_0039d258[3][2];
extern const char *DAT_0039d294[6];
extern const char *DAT_0039d2bc[2];
extern const char *DAT_0039d334[12];
extern char DAT_002da4a4[];
void FUN_00065884(void *);
void FUN_000658cc(void *, int);
void FUN_0008d97c(void *);
void FUN_0006778c(void *, int);
int FUN_00066260(void *, const char *, int, int, char *);
int FUN_00065fa4(void *);
float FUN_0006682c(void *, int, const char *);
int FUN_00066700(void *, int, const char *);
int FUN_00066400(void *, const char *);
const char *FUN_000661a8(void *, int, int);
int FUN_00066038(void *, int, int);
const char *FUN_00066958(void *, int, const char *);
void FUN_000143b0(char *, const char *, ...);
int FUN_00014a40(const char *);
char *FUN_000149a8(char *, const char *);
int FUN_0000fe64(int);
int FUN_0000d644(const char *);
char *FUN_00015ea0(char *, const char *);
char *FUN_00014d64(const char *, const char *);
}

struct ShortVec {
    short *data;
    unsigned size;
    unsigned cap;
    void push_back(const short &x);
};

extern "C" void FUN_0024696c(ShortVec *, const short *, Tag);

inline void ShortVec::push_back(const short &x)
{
    if (size < cap) {
        ++size;
        data[size - 1] = x;
    } else {
        FUN_0024696c(this, &x, Tag());
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
void FUN_00246f18(AiParamVec *, unsigned, Tag);
void FUN_00246f9c(AiParamVec *, unsigned);
void FUN_002457b8(AiParamVec *, const AiParam &);
}

struct AiParamVec {
    AiParam *data;
    unsigned size;
    unsigned cap;
    void shrink(unsigned n, Alloc) { FUN_00246f18(this, n, Tag()); }
};

struct Str {
    int w[4];
    Str() { FUN_0008d97c(this); }
    ~Str() { FUN_0006778c(this, 0); }
};

struct Base16 {
    int w[4];
    Base16()
    {
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

struct AiParamTable {
    char pad0[0x14];
    AiParamVec params;
};

extern "C" void FUN_002449c4(AiParamTable *self, const char *path)
{
    self->params.shrink(self->params.size, Alloc());
    Res r;
    if (FUN_00066260(&r, path, 0, 1, DAT_0039d364)) {
        int n = FUN_00065fa4(&r);
        if (self->params.cap < (unsigned)(n - 1)) {
            FUN_00246f9c(&self->params, n - 1);
        }
        for (int i = 1; i < n; i++) {
            AiParam rec;
            int col = FUN_00066400(&r, DAT_0039d368);
            if (col >= 0) {
                const char *s = FUN_000661a8(&r, i, col);
                if (s != 0) {
                    FUN_000149a8(rec.name, s);
                    while (!FUN_0000fe64(*s))
                        s++;
                    rec.id = FUN_0000d644(s);
                } else {
                    rec.id = FUN_00066038(&r, i, col);
                }
            } else {
                rec.id = 0;
            }
            rec.moveForecast = FUN_0006682c(&r, i, DAT_0039d36c);
            rec.moveForecastSkill = FUN_0006682c(&r, i, DAT_0039d37c);
            for (unsigned k = 0; k < 6; k++) {
                char key[64];
                FUN_000143b0(key, DAT_0039d390, DAT_0039d294[k]);
                rec.moveTime[k].curve = FUN_0006682c(&r, i, key);
                FUN_000143b0(key, DAT_0039d3a0, DAT_0039d294[k]);
                rec.moveTime[k].fast = FUN_00066700(&r, i, key);
                FUN_000143b0(key, DAT_0039d3b0, DAT_0039d294[k]);
                rec.moveTime[k].late = FUN_00066700(&r, i, key);
            }
            rec.moveGood = FUN_00066700(&r, i, DAT_0039d3c0);
            rec.moveBad = FUN_00066700(&r, i, DAT_0039d3cc);
            rec.moveSmash = FUN_0006682c(&r, i, DAT_0039d3d4);
            rec.moveForeAdjust = FUN_00066700(&r, i, DAT_0039d3e0);
            rec.moveError = FUN_0006682c(&r, i, DAT_0039d3f0);
            rec.moveErrorSmash = FUN_0006682c(&r, i, DAT_0039d3fc);
            rec.moveAdvance = FUN_00066700(&r, i, DAT_0039d40c);
            rec.moveKeep = FUN_00066700(&r, i, DAT_0039d418);
            rec.moveServiceline = FUN_00066700(&r, i, DAT_0039d424);
            rec.moveBaseline = FUN_00066700(&r, i, DAT_0039d434);
            rec.moveShort = FUN_00066700(&r, i, DAT_0039d444);
            rec.moveFore = FUN_00066700(&r, i, DAT_0039d450);
            rec.moveGoodHeight = FUN_00066700(&r, i, DAT_0039d45c);
            rec.moveHigh = FUN_00066700(&r, i, DAT_0039d46c);
            rec.moveStrongshot = FUN_00066700(&r, i, DAT_0039d478);
            rec.moveCertainshotId1 = FUN_0006682c(&r, i, DAT_0039d488);
            rec.moveCertainshotFrequency1 = FUN_0006682c(&r, i, DAT_0039d49c);
            rec.moveCertainshotId2 = FUN_0006682c(&r, i, DAT_0039d4b8);
            rec.moveCertainshotFrequency2 = FUN_0006682c(&r, i, DAT_0039d4cc);
            rec.moveOutshot = FUN_0006682c(&r, i, DAT_0039d4e8);
            rec.moveOutshotReaction = FUN_00066700(&r, i, DAT_0039d4f4);
            rec.moveSidespinForecast = FUN_0006682c(&r, i, DAT_0039d508);
            rec.moveSidespinReaction = FUN_0006682c(&r, i, DAT_0039d520);
            rec.movePursuePattern = FUN_00066700(&r, i, DAT_0039d538);
            rec.shotSituation = FUN_0006682c(&r, i, DAT_0039d54c);
            rec.shotAimTimingMin = FUN_0006682c(&r, i, DAT_0039d55c);
            rec.shotAimTimingMax = FUN_0006682c(&r, i, DAT_0039d570);
            rec.shotAccuracy = FUN_0006682c(&r, i, DAT_0039d584);
            rec.shotWidth = FUN_00066700(&r, i, DAT_0039d594);
            rec.shotWidthNet = FUN_00066700(&r, i, DAT_0039d5a0);
            rec.shotTimingError = FUN_00066700(&r, i, DAT_0039d5b0);
            rec.shotTimingErrorNet = FUN_00066700(&r, i, DAT_0039d5c0);
            rec.shotSwingmissMin = FUN_0006682c(&r, i, DAT_0039d5d4);
            rec.shotSwingmissMax = FUN_0006682c(&r, i, DAT_0039d5e8);
            rec.shotSwingmissMaxP = FUN_0006682c(&r, i, DAT_0039d5fc);
            rec.shotMissA = FUN_00066700(&r, i, DAT_0039d610);
            rec.shotMissB = FUN_00066700(&r, i, DAT_0039d61c);
            rec.shotMissC = FUN_00066700(&r, i, DAT_0039d628);
            rec.shotMissD = FUN_00066700(&r, i, DAT_0039d634);
            rec.shotMissE = FUN_00066700(&r, i, DAT_0039d640);
            rec.shotMissF = FUN_00066700(&r, i, DAT_0039d64c);
            rec.shotMissG = FUN_00066700(&r, i, DAT_0039d658);
            rec.shotMissH = FUN_00066700(&r, i, DAT_0039d664);
            for (unsigned k = 0; k < 3; k++) {
                for (int j = 0; j < 2; j++) {
                    const char *cell = FUN_00066958(&r, i, DAT_0039d258[k][j]);
                    if (cell != 0) {
                        char *buf = new char[FUN_00014a40(cell) + 1];
                        FUN_000149a8(buf, cell);
                        for (char *t = FUN_00015ea0(buf, DAT_002da4a4); t != 0; t = FUN_00015ea0(0, DAT_002da4a4))
                            rec.variation[k].v[j].push_back(FUN_0000d644(t));
                        if (buf != 0)
                            delete[] buf;
                    }
                }
            }
            for (unsigned k = 0; k < 15; k++) {
                char key[64];
                FUN_000143b0(key, DAT_0039d670, k + 1);
                int v = 0;
                int c = FUN_00066400(&r, key);
                if (c >= 0)
                    v = FUN_00066038(&r, i, c);
                rec.pattern[k] = v;
            }
            rec.returnTiming = FUN_0006682c(&r, i, DAT_0039d680);
            rec.returnTimingNet = FUN_0006682c(&r, i, DAT_0039d690);
            rec.returnError = FUN_0006682c(&r, i, DAT_0039d6a0);
            rec.returnStop = FUN_0006682c(&r, i, DAT_0039d6ac);
            rec.returnWait = FUN_0006682c(&r, i, DAT_0039d6b8);
            rec.returnFront = FUN_0006682c(&r, i, DAT_0039d6c4);
            rec.returnCenter = FUN_0006682c(&r, i, DAT_0039d6d0);
            rec.returnBest = FUN_0006682c(&r, i, DAT_0039d6e0);
            rec.returnBackward = FUN_0006682c(&r, i, DAT_0039d6ec);
            rec.returnNetdashAll = FUN_0006682c(&r, i, DAT_0039d6fc);
            rec.returnNetdashSlice = FUN_0006682c(&r, i, DAT_0039d710);
            rec.returnNetdashSnatch = FUN_0006682c(&r, i, DAT_0039d724);
            rec.returnNetdashTime = FUN_0006682c(&r, i, DAT_0039d738);
            rec.returnNetdashServe = FUN_0006682c(&r, i, DAT_0039d74c);
            rec.returnNetdashReceive = FUN_0006682c(&r, i, DAT_0039d760);
            rec.returnBias = FUN_00066700(&r, i, DAT_0039d778);
            rec.returnLimitedshot = FUN_00066700(&r, i, DAT_0039d784);
            rec.serveCare = FUN_0006682c(&r, i, DAT_0039d798);
            for (unsigned k = 0; k < 2; k++) {
                for (unsigned j = 0; j < 12; j++) {
                    char key[64];
                    FUN_000143b0(key, DAT_0039d7a4, DAT_0039d2bc[k], DAT_0039d334[j]);
                    rec.serve[k][j] = FUN_0006682c(&r, i, key);
                }
            }
            rec.serveReceiveForecast = FUN_0006682c(&r, i, DAT_0039d7b0);
            rec.serveReceiveForecastSkill = FUN_0006682c(&r, i, DAT_0039d7c8);
            rec.serveReceiveTimeCurve = FUN_0006682c(&r, i, DAT_0039d7e4);
            rec.serveReceiveTimeFast = FUN_0006682c(&r, i, DAT_0039d7fc);
            rec.serveReceiveTimeLate = FUN_0006682c(&r, i, DAT_0039d814);
            rec.serveReceiveError = FUN_0006682c(&r, i, DAT_0039d82c);
            rec.serveReceivePositionFirst = FUN_0006682c(&r, i, DAT_0039d840);
            rec.serveReceiveAdjustFirst = FUN_0006682c(&r, i, DAT_0039d85c);
            rec.serveReceivePositionSecond = FUN_0006682c(&r, i, DAT_0039d874);
            rec.serveReceiveAdjustSecond = FUN_0006682c(&r, i, DAT_0039d890);
            rec.serveReceiveDash = FUN_00066700(&r, i, DAT_0039d8ac);
            if (FUN_00014d64(path, DAT_0039d8c0) != 0 || FUN_00014d64(path, DAT_0039d8cc) != 0) {
                rec.doublesJudgmentA = FUN_0006682c(&r, i, DAT_0039d8dc);
                rec.doublesJudgmentB = FUN_0006682c(&r, i, DAT_0039d8f0);
                rec.doublesJudgmentC = FUN_0006682c(&r, i, DAT_0039d904);
                rec.doublesMoveTimeCurve = FUN_0006682c(&r, i, DAT_0039d918);
                rec.doublesMoveTimeFast = FUN_0006682c(&r, i, DAT_0039d930);
                rec.doublesMoveTimeLate = FUN_0006682c(&r, i, DAT_0039d944);
                rec.doublesMoveError = FUN_0006682c(&r, i, DAT_0039d958);
                rec.doublesTheoryRate = FUN_0006682c(&r, i, DAT_0039d96c);
                rec.doublesFreeShot = FUN_0006682c(&r, i, DAT_0039d980);
                rec.doublesReturnTiming = FUN_0006682c(&r, i, DAT_0039d990);
                rec.doublesReturnTimingNet = FUN_0006682c(&r, i, DAT_0039d9a4);
                rec.doublesReturnError = FUN_0006682c(&r, i, DAT_0039d9bc);
                rec.doublesSnatch = FUN_0006682c(&r, i, DAT_0039d9d0);
                rec.doublesFrameshot = FUN_0006682c(&r, i, DAT_0039d9e0);
                rec.doublesCircle = FUN_00066700(&r, i, DAT_0039d9f4);
                rec.doublesCross = FUN_00066700(&r, i, DAT_0039da04);
                rec.doublesTriangle = FUN_00066700(&r, i, DAT_0039da14);
                rec.doublesFront = FUN_00066700(&r, i, DAT_0039da24);
                rec.doublesHalf = FUN_00066700(&r, i, DAT_0039da34);
                rec.doublesBackward = FUN_00066700(&r, i, DAT_0039da40);
                rec.doublesLeft = FUN_00066700(&r, i, DAT_0039da50);
                rec.doublesCenter = FUN_00066700(&r, i, DAT_0039da5c);
                rec.doublesRight = FUN_00066700(&r, i, DAT_0039da6c);
            }
            FUN_002457b8(&self->params, rec);
        }
    }
}
