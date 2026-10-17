/* HSTMATCH module=hstp_trans_main.prx start=0x001745b4 end=0x001745f4 symbol=FUN_001745b4 lang=c++ */
/* Clone of src/eboot/store_three_fields_001683f0.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rec {
    float f0;
    float f4;
    int i8;
};

extern "C" void FUN_001745b4(Rec *o, const float *pa, const float *pb, const int *pc)
{
    o->f0 = *pa;
    o->f4 = *pb >= 0.0f ? *pb : 0.01f;
    o->i8 = *pc;
}
