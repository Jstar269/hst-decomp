/* HSTMATCH module=hstp_trans_main.prx start=0x0015bdf8 end=0x0015bef4 symbol=FUN_0015bdf8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: FUN_00158b2c(arg, arg) passes a second int that the callee ignores (keeps a1 live at the first call, which moves the home copy of arg into the beqz delay slot), as in the EBOOT twin src/eboot/create_scene_obj_0014fdc0.cpp. */
/* Adapted from the EBOOT twin (same instruction shape, immediates differ): debug trace when DAT_003e9630 is set,
   bail out when DAT_003e9734 is set, then build the object (inlined base/derived ctors store the two vtables
   0x3b1698/0x3b2298) and run it; on failure it is deleted through its virtual destructor (slot 0, a1 = 1;
   `if (obj) delete obj;` gives retail's beqzl/beqz pair). Names provisional. */
extern "C" {
extern unsigned char DAT_003e9630;
extern unsigned char DAT_003e9734;
extern int DAT_003f344c;
extern char DAT_00383868[];
extern int DAT_003b1698;
extern int DAT_003b2298;
extern void FUN_00158b2c(int, int);
extern void FUN_0015bb68(char *, int, int);
extern void FUN_001da030(int, int, int, int);
extern void *FUN_00000bcc(int);
}

struct Desc {
    int pad0;
    int pad4;
    int a;
    int b;
};

struct VC_1 {
    virtual ~VC_1();
    virtual int run(float, int);
};

extern "C" VC_1 *FUN_0015bdf8(Desc *desc, int arg, float t)
{
    VC_1 *obj;

    if (DAT_003e9630 != 0) {
        FUN_00158b2c(arg, arg);
        FUN_0015bb68(DAT_00383868, desc->a, desc->b);
    }
    if (DAT_003e9734 != 0)
        return 0;
    FUN_001da030(DAT_003f344c, desc->a, desc->b, -1);
    if ((obj = (VC_1 *)FUN_00000bcc(4)) != 0) {
        *(int *)obj = (int)&DAT_003b1698;
        *(int *)obj = (int)&DAT_003b2298;
    }
    if (obj->run(t, arg) != 0) {
        if (obj != 0)
            delete obj;
        return 0;
    }
    return obj;
}
