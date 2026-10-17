/* HSTMATCH module=hstp_trans_main.prx start=0x0020f564 end=0x0020f5c0 symbol=FUN_0020f564 */
/* Clone of src/eboot/FUN_00200d94.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
class P_0020f564 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
};
struct S_0020f564 { char pad[0x708]; P_0020f564 *p; };
extern "C" void FUN_001118ac(P_0020f564 *p, int a, int b);
extern "C" void FUN_0020f5c0(S_0020f564 *s);
extern "C" void FUN_0020f8e4(S_0020f564 *s);
extern "C" void FUN_0020fca8(S_0020f564 *s);
extern "C" void FUN_0020f564(S_0020f564 *s)
{
    FUN_001118ac(s->p, 0, 1);
    FUN_0020f5c0(s);
    FUN_0020f8e4(s);
    FUN_0020fca8(s);
    s->p->v11();
}
