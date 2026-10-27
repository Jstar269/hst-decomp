/* HSTMATCH module=EBOOT.BIN start=0x0015389c end=0x001539bc symbol=FUN_0015389c lang=c++ data=0x002dc7d4 */
/* Hand-written reconstruction (port of src/sharing_main/create_quest_0015fb04.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc7d4-0x002dc7e8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

extern "C" {
extern const char DAT_002dc7c8[];
extern const unsigned char DAT_003402f0;
extern void *DAT_0034a114;

void FUN_000143b0(void *buf, const char *fmt, void *arg);
void FUN_0014d044(void *p);
void FUN_0014fd94(const char *fmt, void *buf);
void *FUN_0014c384(int id, int type);
void FUN_001cb700(void *mgr, void *buf);
void *__nw__FUi(unsigned int size);
}

struct Param1 {
    char pad[8];
    void *f8;
};

class C_001583b4 {
public:
    virtual ~C_001583b4();
    virtual int method(float param_3, int *param_2);
};

class C_0015389c : public C_001583b4 {
public:
    Param1 *p1;
    C_0015389c(Param1 *p) : p1(p) {}
    virtual ~C_0015389c();
    virtual int method(float param_3, int *param_2);
};

extern "C" C_0015389c *FUN_0015389c(Param1 *param_1, int *param_2, float param_3)
{
    char buf[32];
    FUN_000143b0(buf, DAT_002dc7c8, param_1->f8);

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94("EventMatchQuest %s\n", buf);
    }

    int *res = (int *)FUN_0014c384(*param_2, 11);
    *(bool *)((char *)DAT_0034a114 + 0xfc) = (*res != 0);
    FUN_001cb700(DAT_0034a114, buf);

    C_0015389c *obj = new C_0015389c(param_1);
    if (obj->method(param_3, param_2) != 0) {
        if (obj != 0) {
            delete obj;
        }
        return 0;
    }
    return obj;
}
