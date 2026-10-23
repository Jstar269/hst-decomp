/* HSTMATCH module=EBOOT.BIN start=0x002876a0 end=0x002878cc symbol=FUN_002876a0 lang=c++ */
class Actor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void *getPos();
    virtual void setPos(void *);
};

extern "C" {
void *FUN_00289544(void *, void *, void *, void *);
void FUN_001caee4(int, int, void *, void *);
void FUN_00022418(void *, void *, void *);
void *FUN_001c6f70(int, int, int);
void *FUN_001c70c0(int, int);
float FUN_0000bc34(float);
float FUN_0000bf34(float);
extern int DAT_0034a114;
extern int DAT_0034a118;
extern float DAT_002bc440;
extern float DAT_002bc444;
extern float DAT_002bc448;
extern float DAT_002bc44c;
}

extern "C" void FUN_002876a0(Actor *p, int mode, int id, int count)
{
    float rot[4];
    float pos[4];
    float out[4];
    char tmp[16];
    Actor *obj;
    int *rec;
    void *v;
    int idx;
    int type;

    if (count <= 0) {
    out[0] = DAT_002bc440;
    out[1] = DAT_002bc444;
    out[2] = DAT_002bc448;
    out[3] = DAT_002bc44c;
    if (mode == 0) {
        FUN_001caee4(DAT_0034a114, id, out, tmp);
        type = *(int *)p;
    } else if (mode == 1) {
        if (id == -1) {
            if (DAT_0034a118 != 0)
                obj = (Actor *)(DAT_0034a118 + 0xe0);
            else
                obj = 0;
        } else if (id >= 0) {
            if (id < 100)
                obj = *(Actor **)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
            else if (id < 1000)
                obj = (Actor *)FUN_001c6f70(DAT_0034a114, id, 0);
            else
                obj = (Actor *)FUN_001c70c0(DAT_0034a114, id);
        } else {
            obj = p;
        }
        v = obj->getPos();
        out[0] = *(float *)v;
        out[1] = *((float *)v + 1);
        out[2] = *((float *)v + 2);
        out[3] = *((float *)v + 3);
    } else if (mode == 2) {
        rot[0] = FUN_0000bf34((float)id * 0.017453292f);
        rot[1] = 0.0f;
        rot[2] = FUN_0000bc34((float)id * 0.017453292f);
        rot[3] = 0.0f;
        v = p->getPos();
        FUN_00022418(pos, v, rot);
        out[0] = pos[0];
        out[1] = pos[1];
        out[2] = pos[2];
        out[3] = pos[3];
    }
    p->setPos(out);
    } else {
        int *slot = (int *)p + 0x1a;
        int info[4];

        info[0] = 0x39;
        info[1] = count;
        info[2] = mode;
        info[3] = id;
        FUN_00289544(&info[0], (int *)p + 0x19, &slot, info);
        return;
    }
}

// 132/139 words, 107 differ. C++ virtual class with six dummy virtuals then getPos
// (+0x20) / setPos (+0x24) gives retail s `lw t9,0(a0); lw t9,0x20(t9); jalr t9`.
// The early `count > 0` arm must be written as `if (count <= 0) {main} else {early}`
// to get retail s `bgtz a3 -> out of line at 0x287888`. 7 words short: the id == -1
// null path (retail still dereferences the null pointer for the vptr instead of
// yielding 0) and the mode==1 id<100/1000/else chain layout.
// near miss from lane fm8 (unreviewed)
