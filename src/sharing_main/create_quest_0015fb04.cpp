/* HSTMATCH module=hstp_trans_main.prx start=0x0015fb04 end=0x0015fc24 symbol=FUN_0015fb04 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern const char DAT_00383cb0[];
extern const char DAT_00383cbc[];
extern const unsigned char DAT_003e9630;
extern void *DAT_003f344c;

void FUN_000143b0(void *buf, const char *fmt, void *arg);
void FUN_00158b2c(void *p);
void FUN_0015bb68(const char *fmt, void *buf);
void *FUN_00157e10(int id, int type);
void FUN_001d9f6c(void *mgr, void *buf);
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

class C_0015fb04 : public C_001583b4 {
public:
    Param1 *p1;
    C_0015fb04(Param1 *p) : p1(p) {}
    virtual ~C_0015fb04();
    virtual int method(float param_3, int *param_2);
};

extern "C" C_0015fb04 *FUN_0015fb04(Param1 *param_1, int *param_2, float param_3)
{
    char buf[32];
    FUN_000143b0(buf, DAT_00383cb0, param_1->f8);

    if (DAT_003e9630 != 0) {
        FUN_00158b2c(param_2);
        FUN_0015bb68(DAT_00383cbc, buf);
    }

    int *res = (int *)FUN_00157e10(*param_2, 11);
    *(bool *)((char *)DAT_003f344c + 0xfc) = (*res != 0);
    FUN_001d9f6c(DAT_003f344c, buf);

    C_0015fb04 *obj = new C_0015fb04(param_1);
    if (obj->method(param_3, param_2) != 0) {
        if (obj != 0) {
            delete obj;
        }
        return 0;
    }
    return obj;
}
