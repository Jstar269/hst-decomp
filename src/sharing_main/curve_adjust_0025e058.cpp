/* HSTMATCH module=hstp_trans_main.prx start=0x0025e058 end=0x0025e0c0 symbol=FUN_0025e058 lang=c++ */
/* Clone of src/eboot/curve_adjust_0024de20.cpp (hstclone.py tag c23fbop): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the easing factor is a non-const local float, which keeps the multiply value-first (a literal
   factor is commuted to the front); 0.79999995f is the retail bit pattern 0x3f4ccccc. */
extern "C" float FUN_0025dfc4(float, int);

extern "C" float FUN_0025e058(float value, int mode)
{
    value = FUN_0025dfc4(value, mode);
    if (value <= 0.0f) {
    } else if (!(value >= 1.0f)) {
        float k = 0.79999995f;
        value = value * k + 0.1f;
    }
    return value;
}
