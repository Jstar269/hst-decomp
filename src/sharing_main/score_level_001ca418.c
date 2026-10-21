/* HSTMATCH module=hstp_trans_main.prx start=0x001ca418 end=0x001ca530 symbol=FUN_001ca418 lang=c99 */
/* Clone of src/eboot/score_level_001bc630.c (hstclone.py tag c22rt2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Score bucket 0..10: round(100*score) selects 1100/1000/900/800 bands 0..3; below 800 a raw
   `score >= 700.0f` shortcut returns 4, then 600/500/400/300/200/100 bands 5..9 and the default 10.
   The `float f = RoundI(...); int v = (int)f;` round-trip is source-real: it is what makes the
   int->float->int convert appear once after the rounding join. The trailing `else if (v >= 100) r = 10;`
   is redundant but required: it produces retail's last `slti v1,a0,100` in the branch delay slot. */
static inline int RoundI_001ca418(float x)
{
    if (x > 0.0f)
        return (int)(x + 0.5f);
    return -(int)(0.5f - x);
}

int FUN_001ca418(float score)
{
    float f = RoundI_001ca418(score * 100.0f);
    int v = (int)f;
    int r = 10;
    if (v >= 1100) r = 0;
    else if (v >= 1000) r = 1;
    else if (v >= 900) r = 2;
    else if (v >= 800) r = 3;
    else if (score >= 700.0f) r = 4;
    else if (v >= 600) r = 5;
    else if (v >= 500) r = 6;
    else if (v >= 400) r = 7;
    else if (v >= 300) r = 8;
    else if (v >= 200) r = 9;
    else if (v >= 100) r = 10;
    return r;
}
