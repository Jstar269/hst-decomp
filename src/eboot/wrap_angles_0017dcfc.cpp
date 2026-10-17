/* HSTMATCH module=EBOOT.BIN start=0x0017dcfc end=0x0017de30 symbol=FUN_0017dcfc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Wrap the three angles at +0x30/+0x34/+0x38 (a rotation vector) back into [-pi, pi] by one 2*pi step.
   Names provisional. */
struct Obj_0017dcfc {
    char pad[0x30];
    float rx, ry, rz;
};
inline void WrapAngle_0017dcfc(float &a)
{
    if (a < -3.1415927f)
        a += 6.2831855f;
    else if (a > 3.1415927f)
        a -= 6.2831855f;
}
extern "C" void FUN_0017dcfc(Obj_0017dcfc *o)
{
    WrapAngle_0017dcfc(o->rx);
    WrapAngle_0017dcfc(o->ry);
    WrapAngle_0017dcfc(o->rz);
}
