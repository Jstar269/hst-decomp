/* HSTMATCH module=hstp_trans_main.prx start=0x0018a3f0 end=0x0018a524 symbol=FUN_0018a3f0 lang=c++ */
/* Clone of src/eboot/wrap_angles_0017dcfc.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Wrap the three angles at +0x30/+0x34/+0x38 (a rotation vector) back into [-pi, pi] by one 2*pi step.
   Names provisional. */
struct Obj_0018a3f0 {
    char pad[0x30];
    float rx, ry, rz;
};
inline void WrapAngle_0018a3f0(float &a)
{
    if (a < -3.1415927f)
        a += 6.2831855f;
    else if (a > 3.1415927f)
        a -= 6.2831855f;
}
extern "C" void FUN_0018a3f0(Obj_0018a3f0 *o)
{
    WrapAngle_0018a3f0(o->rx);
    WrapAngle_0018a3f0(o->ry);
    WrapAngle_0018a3f0(o->rz);
}
