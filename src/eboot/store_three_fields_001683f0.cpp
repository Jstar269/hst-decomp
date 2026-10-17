/* HSTMATCH module=EBOOT.BIN start=0x001683f0 end=0x00168430 symbol=FUN_001683f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rec {
    float f0;
    float f4;
    int i8;
};

extern "C" void FUN_001683f0(Rec *o, const float *pa, const float *pb, const int *pc)
{
    o->f0 = *pa;
    o->f4 = *pb >= 0.0f ? *pb : 0.01f;
    o->i8 = *pc;
}
