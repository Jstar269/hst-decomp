/* HSTMATCH module=hstp_trans_main.prx start=0x00246560 end=0x00246630 symbol=FUN_00246560 lang=c++ */
/* Clone of src/eboot/copy_record_48_002363fc.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Byte3 {
    unsigned char a, b, c;
};

struct Rec {
    int f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    Byte3 f3c;
    Byte3 f3f;
    Byte3 f42;
};

extern "C" void FUN_00246560(int, Rec *dst, const Rec *src)
{
    if (dst != 0) {
        *dst = *src;
    }
}
