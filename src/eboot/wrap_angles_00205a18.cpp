/* HSTMATCH module=EBOOT.BIN start=0x00205a18 end=0x00205b4c symbol=FUN_00205a18 lang=c++ */
/* Clone of src/sharing_main/wrap_angles_0018a3f0.cpp (hstclone.py tag c224720): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Wrap the three angles at +0x30/+0x34/+0x38 (a rotation vector) back into [-pi, pi] by one 2*pi step.
   Names provisional. */
struct Obj_00205a18 {
    char pad[0x30];
    float rx, ry, rz;
};
inline void WrapAngle_00205a18(float &a)
{
    if (a < -3.1415927f)
        a += 6.2831855f;
    else if (a > 3.1415927f)
        a -= 6.2831855f;
}
extern "C" void FUN_00205a18(Obj_00205a18 *o)
{
    WrapAngle_00205a18(o->rx);
    WrapAngle_00205a18(o->ry);
    WrapAngle_00205a18(o->rz);
}
