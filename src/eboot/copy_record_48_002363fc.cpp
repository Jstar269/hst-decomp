/* HSTMATCH module=EBOOT.BIN start=0x002363fc end=0x002364cc symbol=FUN_002363fc lang=c++ */
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

extern "C" void FUN_002363fc(int, Rec *dst, const Rec *src)
{
    if (dst != 0) {
        *dst = *src;
    }
}
