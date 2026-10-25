/* HSTMATCH module=EBOOT.BIN start=0x00055240 end=0x00055480 symbol=FUN_00055240 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Mat {
    float m[16];
    Mat() {}
    Mat(const Mat &o) {
        m[0] = o.m[0];
        m[1] = o.m[1];
        m[2] = o.m[2];
        m[3] = o.m[3];
        m[4] = o.m[4];
        m[5] = o.m[5];
        m[6] = o.m[6];
        m[7] = o.m[7];
        m[8] = o.m[8];
        m[9] = o.m[9];
        m[10] = o.m[10];
        m[11] = o.m[11];
        m[12] = o.m[12];
        m[13] = o.m[13];
        m[14] = o.m[14];
        m[15] = o.m[15];
    }
};
struct Model {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Mat *Bones();
    char pad[0x88];
    int count;
};
extern Mat DAT_002bc410;
extern "C" {
Mat FUN_000555b4(Model *);
Mat FUN_00022570(const Mat &, const Mat &);
}

extern "C" Mat FUN_00055240(Model *model, int idx)
{
    if (model->count && idx >= 0) {
        Mat b = model->Bones()[idx];
        Mat w = FUN_000555b4(model);
        Mat r = FUN_00022570(w, b);
        return r;
    }
    return DAT_002bc410;
}
