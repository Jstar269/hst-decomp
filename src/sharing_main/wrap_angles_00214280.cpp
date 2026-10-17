/* HSTMATCH module=hstp_trans_main.prx start=0x00214280 end=0x002143b4 symbol=FUN_00214280 lang=c++ */
/* Clone of src/eboot/wrap_angles_0017dcfc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Wrap the three angles at +0x30/+0x34/+0x38 (a rotation vector) back into [-pi, pi] by one 2*pi step.
   Names provisional. */
struct Obj_00214280 {
    char pad[0x30];
    float rx, ry, rz;
};
inline void WrapAngle_00214280(float &a)
{
    if (a < -3.1415927f)
        a += 6.2831855f;
    else if (a > 3.1415927f)
        a -= 6.2831855f;
}
extern "C" void FUN_00214280(Obj_00214280 *o)
{
    WrapAngle_00214280(o->rx);
    WrapAngle_00214280(o->ry);
    WrapAngle_00214280(o->rz);
}
