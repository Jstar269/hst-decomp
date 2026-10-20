/* HSTMATCH module=hstp_trans_main.prx start=0x002984ac end=0x00298504 symbol=FUN_002984ac lang=c++ */
/* Clone of src/eboot/set_flag_notify_00286db0.cpp (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
class Base {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    unsigned char pad[0x51];
    unsigned char flag;
};

extern "C" {
extern void *DAT_003f344c;
extern void FUN_001dafb4(void *);
extern void FUN_001dbab4(void *);
}

extern "C" void FUN_002984ac(Base *self, int on)
{
    self->flag = on;
    FUN_001dafb4(DAT_003f344c);
    if (self->flag != 0)
        FUN_001dbab4(DAT_003f344c);
    self->v16();
}
