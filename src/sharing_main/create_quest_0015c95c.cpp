/* HSTMATCH module=hstp_trans_main.prx start=0x0015c95c end=0x0015ca90 symbol=FUN_0015c95c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern const char DAT_003838f4[];
extern const char DAT_003838fc[];
extern const unsigned char DAT_003e9630;
extern void *DAT_003f344c;

void *FUN_00157e10(int id, int type);
void FUN_000143b0(void *a0, const char *fmt, void *a2, void *a3);
void FUN_00158b2c(void *p);
void FUN_0015bb68(const char *fmt, void *a1);
void FUN_001d9f6c(void *mgr, void *arg);
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

class C_0015c95c : public C_001583b4 {
public:
    Param1 *p1;
    C_0015c95c(Param1 *p) : p1(p) {}
    virtual ~C_0015c95c() {}
    virtual int method(float param_3, int *param_2);
};

extern "C" C_0015c95c *FUN_0015c95c(Param1 *param_1, int *param_2, float param_3)
{
    int id = *param_2;
    void *res1 = FUN_00157e10(id, 9);
    FUN_000143b0(param_1->f12, DAT_003838f4, param_1->f8, *(void **)res1);

    if (DAT_003e9630 != 0) {
        FUN_00158b2c(param_2);
        FUN_0015bb68(DAT_003838fc, param_1->f12);
    }

    int *res2 = (int *)FUN_00157e10(id, 11);
    *(bool *)((char *)DAT_003f344c + 0xfc) = (*res2 != 0);
    FUN_001d9f6c(DAT_003f344c, param_1->f12);

    C_0015c95c *obj = new C_0015c95c(param_1);
    if (obj->method(param_3, param_2) != 0) {
        if (obj != 0) {
            delete obj;
        }
        return 0;
    }
    return obj;
}
