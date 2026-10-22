/* HSTMATCH module=EBOOT.BIN start=0x0024de20 end=0x0024de88 symbol=FUN_0024de20 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the easing factor is a non-const local float, which keeps the multiply value-first (a literal
   factor is commuted to the front); 0.79999995f is the retail bit pattern 0x3f4ccccc. */
extern "C" float FUN_0024dd8c(float, int);

extern "C" float FUN_0024de20(float value, int mode)
{
    value = FUN_0024dd8c(value, mode);
    if (value <= 0.0f) {
    } else if (!(value >= 1.0f)) {
        float k = 0.79999995f;
        value = value * k + 0.1f;
    }
    return value;
}
