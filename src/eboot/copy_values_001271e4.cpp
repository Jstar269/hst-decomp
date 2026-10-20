/* HSTMATCH module=EBOOT.BIN start=0x001271e4 end=0x00127240 symbol=FUN_001271e4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
class Unit {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual int Check();

    unsigned char pad[0xfc];
    float values[4];
};

extern "C" char *FUN_00093818(Unit *);

extern "C" void FUN_001271e4(Unit *self)
{
    if (self->Check() != 0) return;
    float *src = (float *)(FUN_00093818(self) + 0x20);

    self->values[0] = src[0];
    self->values[1] = src[1];
    self->values[2] = src[2];
    self->values[3] = src[3];
}
