/* HSTMATCH module=EBOOT.BIN start=0x00150924 end=0x00150a58 symbol=FUN_00150924 lang=c++ data=0x002dc40c */
/* Hand-written reconstruction (port of src/sharing_main/create_quest_0015c95c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002dc40c-0x002dc423) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

extern "C" {
extern const unsigned char DAT_003402f0;
extern void *DAT_0034a114;

void *FUN_0014c384(int id, int type);
void FUN_000143b0(void *a0, const char *fmt, void *a2, void *a3);
void FUN_0014d044(void *p);
void FUN_0014fd94(const char *fmt, void *a1);
void FUN_001cb700(void *mgr, void *arg);
void *__nw__FUi(unsigned int size);
}

struct Param1 {
    char pad[8];
    void *f8;
    void *f12;
};

class C_001583b4 {
public:
    virtual ~C_001583b4() {}
    virtual int method(float param_3, int *param_2);
};

class C_00150924 : public C_001583b4 {
public:
    Param1 *p1;
    C_00150924(Param1 *p) : p1(p) {}
    virtual ~C_00150924() {}
    virtual int method(float param_3, int *param_2);
};

extern "C" C_00150924 *FUN_00150924(Param1 *param_1, int *param_2, float param_3)
{
    int id = *param_2;
    void *res1 = FUN_0014c384(id, 9);
    FUN_000143b0(param_1->f12, "%s_%03d", param_1->f8, *(void **)res1);

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94("MatchQuest %s\n", param_1->f12);
    }

    int *res2 = (int *)FUN_0014c384(id, 11);
    *(bool *)((char *)DAT_0034a114 + 0xfc) = (*res2 != 0);
    FUN_001cb700(DAT_0034a114, param_1->f12);

    C_00150924 *obj = new C_00150924(param_1);
    if (obj->method(param_3, param_2) != 0) {
        if (obj != 0) {
            delete obj;
        }
        return 0;
    }
    return obj;
}
