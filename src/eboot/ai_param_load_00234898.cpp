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

/* Array lengths of the AI parameter record. */
enum {
    AI_MOVE_TIME_KINDS = 6,   /* rows of the move-time group */
    AI_VARIATIONS = 3,        /* shot variation lists */
    AI_VARIATION_PARTS = 2,   /* short lists per variation */
    AI_PATTERN_LEN = 15,      /* pattern bytes */
    AI_SERVE_SIDES = 2,
    AI_SERVE_TYPES = 12
};

struct ShotVariation {
    ShortVec v[AI_VARIATION_PARTS];
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
    MoveTime moveTime[AI_MOVE_TIME_KINDS];
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
    ShotVariation variation[AI_VARIATIONS];
    unsigned char pattern[AI_PATTERN_LEN];
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
    float serve[AI_SERVE_SIDES][AI_SERVE_TYPES];
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

/* Short string object (4 words). */
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

/* CSV table reader: loads a file, then looks up cells by row and column name. */
struct CsvTable : Base16 {
    Str a;
    Str b;
    ~CsvTable() { *(char **)this = DAT_003070bc; }
};

struct AiParamTable {
    char pad0[0x14];
    AiParamVec params;
};

/* Load the AI parameter table from a CSV file: one AiParam record per data row, columns found by name. */
extern "C" void FUN_00234898(AiParamTable *self, const char *path)
{
    self->params.shrink(self->params.size, Alloc());
    CsvTable csv;
    if (FUN_000651b8(&csv, path, 0, 1, DAT_002f4a64)) {
        int row_count = FUN_000650e0(&csv);
        if (self->params.cap < (unsigned)(row_count - 1)) {
            FUN_00236e38(&self->params, row_count - 1);
        }
        for (int row = 1; row < row_count; row++) { /* row 0 is the header */
            AiParam param;
            int id_col = FUN_00065364(&csv, DAT_002f4a68);
            if (id_col >= 0) {
                const char *text = FUN_0006517c(&csv, row, id_col);
                if (text != 0) {
                    FUN_000149a8(param.name, text);
                    while (!FUN_0000fe64(*text))
                        text++;
                    param.id = FUN_0000d62c(text);
                } else {
                    param.id = FUN_00065104(&csv, row, id_col);
                }
            } else {
                param.id = 0;
            }
            /* movement columns */
            param.moveForecast = FUN_000655f8(&csv, row, DAT_002f4a6c);
            param.moveForecastSkill = FUN_000655f8(&csv, row, DAT_002f4a7c);
            for (unsigned k = 0; k < AI_MOVE_TIME_KINDS; k++) {
                char key[64];
                FUN_000143b0(key, DAT_002f4a90, DAT_002f4994[k]);
                param.moveTime[k].curve = FUN_000655f8(&csv, row, key);
                FUN_000143b0(key, DAT_002f4aa0, DAT_002f4994[k]);
                param.moveTime[k].fast = FUN_00065554(&csv, row, key);
                FUN_000143b0(key, DAT_002f4ab0, DAT_002f4994[k]);
                param.moveTime[k].late = FUN_00065554(&csv, row, key);
            }
            param.moveGood = FUN_00065554(&csv, row, DAT_002f4ac0);
            param.moveBad = FUN_00065554(&csv, row, DAT_002f4acc);
            param.moveSmash = FUN_000655f8(&csv, row, DAT_002f4ad4);
            param.moveForeAdjust = FUN_00065554(&csv, row, DAT_002f4ae0);
            param.moveError = FUN_000655f8(&csv, row, DAT_002f4af0);
            param.moveErrorSmash = FUN_000655f8(&csv, row, DAT_002f4afc);
            param.moveAdvance = FUN_00065554(&csv, row, DAT_002f4b0c);
            param.moveKeep = FUN_00065554(&csv, row, DAT_002f4b18);
            param.moveServiceline = FUN_00065554(&csv, row, DAT_002f4b24);
            param.moveBaseline = FUN_00065554(&csv, row, DAT_002f4b34);
            param.moveShort = FUN_00065554(&csv, row, DAT_002f4b44);
            param.moveFore = FUN_00065554(&csv, row, DAT_002f4b50);
            param.moveGoodHeight = FUN_00065554(&csv, row, DAT_002f4b5c);
            param.moveHigh = FUN_00065554(&csv, row, DAT_002f4b6c);
            param.moveStrongshot = FUN_00065554(&csv, row, DAT_002f4b78);
            param.moveCertainshotId1 = FUN_000655f8(&csv, row, DAT_002f4b88);
            param.moveCertainshotFrequency1 = FUN_000655f8(&csv, row, DAT_002f4b9c);
            param.moveCertainshotId2 = FUN_000655f8(&csv, row, DAT_002f4bb8);
            param.moveCertainshotFrequency2 = FUN_000655f8(&csv, row, DAT_002f4bcc);
            param.moveOutshot = FUN_000655f8(&csv, row, DAT_002f4be8);
            param.moveOutshotReaction = FUN_00065554(&csv, row, DAT_002f4bf4);
            param.moveSidespinForecast = FUN_000655f8(&csv, row, DAT_002f4c08);
            param.moveSidespinReaction = FUN_000655f8(&csv, row, DAT_002f4c20);
            param.movePursuePattern = FUN_00065554(&csv, row, DAT_002f4c38);
            /* shot columns */
            param.shotSituation = FUN_000655f8(&csv, row, DAT_002f4c4c);
            param.shotAimTimingMin = FUN_000655f8(&csv, row, DAT_002f4c5c);
            param.shotAimTimingMax = FUN_000655f8(&csv, row, DAT_002f4c70);
            param.shotAccuracy = FUN_000655f8(&csv, row, DAT_002f4c84);
            param.shotWidth = FUN_00065554(&csv, row, DAT_002f4c94);
            param.shotWidthNet = FUN_00065554(&csv, row, DAT_002f4ca0);
            param.shotTimingError = FUN_00065554(&csv, row, DAT_002f4cb0);
            param.shotTimingErrorNet = FUN_00065554(&csv, row, DAT_002f4cc0);
            param.shotSwingmissMin = FUN_000655f8(&csv, row, DAT_002f4cd4);
            param.shotSwingmissMax = FUN_000655f8(&csv, row, DAT_002f4ce8);
            param.shotSwingmissMaxP = FUN_000655f8(&csv, row, DAT_002f4cfc);
            param.shotMissA = FUN_00065554(&csv, row, DAT_002f4d10);
            param.shotMissB = FUN_00065554(&csv, row, DAT_002f4d1c);
            param.shotMissC = FUN_00065554(&csv, row, DAT_002f4d28);
            param.shotMissD = FUN_00065554(&csv, row, DAT_002f4d34);
            param.shotMissE = FUN_00065554(&csv, row, DAT_002f4d40);
            param.shotMissF = FUN_00065554(&csv, row, DAT_002f4d4c);
            param.shotMissG = FUN_00065554(&csv, row, DAT_002f4d58);
            param.shotMissH = FUN_00065554(&csv, row, DAT_002f4d64);
            /* shot variation lists: comma-separated numbers per cell */
            for (unsigned k = 0; k < AI_VARIATIONS; k++) {
                for (int j = 0; j < AI_VARIATION_PARTS; j++) {
                    const char *cell = FUN_0006569c(&csv, row, DAT_002f4958[k][j]);
                    if (cell != 0) {
                        char *buf = new char[FUN_00014a40(cell) + 1];
                        FUN_000149a8(buf, cell);
                        for (char *t = FUN_00015ea0(buf, DAT_002c9ee4); t != 0; t = FUN_00015ea0(0, DAT_002c9ee4))
                            param.variation[k].v[j].push_back(FUN_0000d62c(t));
                        if (buf != 0)
                            delete[] buf;
                    }
                }
            }
            /* pattern columns are numbered from 1 */
            for (unsigned k = 0; k < AI_PATTERN_LEN; k++) {
                char key[64];
                FUN_000143b0(key, DAT_002f4d70, k + 1);
                int v = 0;
                int c = FUN_00065364(&csv, key);
                if (c >= 0)
                    v = FUN_00065104(&csv, row, c);
                param.pattern[k] = v;
            }
            /* return columns */
            param.returnTiming = FUN_000655f8(&csv, row, DAT_002f4d80);
            param.returnTimingNet = FUN_000655f8(&csv, row, DAT_002f4d90);
            param.returnError = FUN_000655f8(&csv, row, DAT_002f4da0);
            param.returnStop = FUN_000655f8(&csv, row, DAT_002f4dac);
            param.returnWait = FUN_000655f8(&csv, row, DAT_002f4db8);
            param.returnFront = FUN_000655f8(&csv, row, DAT_002f4dc4);
            param.returnCenter = FUN_000655f8(&csv, row, DAT_002f4dd0);
            param.returnBest = FUN_000655f8(&csv, row, DAT_002f4de0);
            param.returnBackward = FUN_000655f8(&csv, row, DAT_002f4dec);
            param.returnNetdashAll = FUN_000655f8(&csv, row, DAT_002f4dfc);
            param.returnNetdashSlice = FUN_000655f8(&csv, row, DAT_002f4e10);
            param.returnNetdashSnatch = FUN_000655f8(&csv, row, DAT_002f4e24);
            param.returnNetdashTime = FUN_000655f8(&csv, row, DAT_002f4e38);
            param.returnNetdashServe = FUN_000655f8(&csv, row, DAT_002f4e4c);
            param.returnNetdashReceive = FUN_000655f8(&csv, row, DAT_002f4e60);
            param.returnBias = FUN_00065554(&csv, row, DAT_002f4e78);
            param.returnLimitedshot = FUN_00065554(&csv, row, DAT_002f4e84);
            /* serve columns */
            param.serveCare = FUN_000655f8(&csv, row, DAT_002f4e98);
            for (unsigned k = 0; k < AI_SERVE_SIDES; k++) {
                for (unsigned j = 0; j < AI_SERVE_TYPES; j++) {
                    char key[64];
                    FUN_000143b0(key, DAT_002f4ea4, DAT_002f49bc[k], DAT_002f4a34[j]);
                    param.serve[k][j] = FUN_000655f8(&csv, row, key);
                }
            }
            /* serve-receive columns */
            param.serveReceiveForecast = FUN_000655f8(&csv, row, DAT_002f4eb0);
            param.serveReceiveForecastSkill = FUN_000655f8(&csv, row, DAT_002f4ec8);
            param.serveReceiveTimeCurve = FUN_000655f8(&csv, row, DAT_002f4ee4);
            param.serveReceiveTimeFast = FUN_000655f8(&csv, row, DAT_002f4efc);
            param.serveReceiveTimeLate = FUN_000655f8(&csv, row, DAT_002f4f14);
            param.serveReceiveError = FUN_000655f8(&csv, row, DAT_002f4f2c);
            param.serveReceivePositionFirst = FUN_000655f8(&csv, row, DAT_002f4f40);
            param.serveReceiveAdjustFirst = FUN_000655f8(&csv, row, DAT_002f4f5c);
            param.serveReceivePositionSecond = FUN_000655f8(&csv, row, DAT_002f4f74);
            param.serveReceiveAdjustSecond = FUN_000655f8(&csv, row, DAT_002f4f90);
            param.serveReceiveDash = FUN_00065554(&csv, row, DAT_002f4fac);
            /* doubles columns exist only in the doubles tables (by file name) */
            if (FUN_00014d64(path, DAT_002f4fc0) != 0 || FUN_00014d64(path, DAT_002f4fcc) != 0) {
                param.doublesJudgmentA = FUN_000655f8(&csv, row, DAT_002f4fdc);
                param.doublesJudgmentB = FUN_000655f8(&csv, row, DAT_002f4ff0);
                param.doublesJudgmentC = FUN_000655f8(&csv, row, DAT_002f5004);
                param.doublesMoveTimeCurve = FUN_000655f8(&csv, row, DAT_002f5018);
                param.doublesMoveTimeFast = FUN_000655f8(&csv, row, DAT_002f5030);
                param.doublesMoveTimeLate = FUN_000655f8(&csv, row, DAT_002f5044);
                param.doublesMoveError = FUN_000655f8(&csv, row, DAT_002f5058);
                param.doublesTheoryRate = FUN_000655f8(&csv, row, DAT_002f506c);
                param.doublesFreeShot = FUN_000655f8(&csv, row, DAT_002f5080);
                param.doublesReturnTiming = FUN_000655f8(&csv, row, DAT_002f5090);
                param.doublesReturnTimingNet = FUN_000655f8(&csv, row, DAT_002f50a4);
                param.doublesReturnError = FUN_000655f8(&csv, row, DAT_002f50bc);
                param.doublesSnatch = FUN_000655f8(&csv, row, DAT_002f50d0);
                param.doublesFrameshot = FUN_000655f8(&csv, row, DAT_002f50e0);
                param.doublesCircle = FUN_00065554(&csv, row, DAT_002f50f4);
                param.doublesCross = FUN_00065554(&csv, row, DAT_002f5104);
                param.doublesTriangle = FUN_00065554(&csv, row, DAT_002f5114);
                param.doublesFront = FUN_00065554(&csv, row, DAT_002f5124);
                param.doublesHalf = FUN_00065554(&csv, row, DAT_002f5134);
                param.doublesBackward = FUN_00065554(&csv, row, DAT_002f5140);
                param.doublesLeft = FUN_00065554(&csv, row, DAT_002f5150);
                param.doublesCenter = FUN_00065554(&csv, row, DAT_002f515c);
                param.doublesRight = FUN_00065554(&csv, row, DAT_002f516c);
            }
            FUN_0023568c(&self->params, param);
        }
    }
}
