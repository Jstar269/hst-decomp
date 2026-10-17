/* HSTMATCH module=EBOOT.BIN start=0x00200d94 end=0x00200df0 symbol=FUN_00200d94 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
class P_00200d94 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
};
struct S_00200d94 { char pad[0x708]; P_00200d94 *p; };
extern "C" void FUN_0010b6d4(P_00200d94 *p, int a, int b);
extern "C" void FUN_00200df0(S_00200d94 *s);
extern "C" void FUN_00201114(S_00200d94 *s);
extern "C" void FUN_002014d8(S_00200d94 *s);
extern "C" void FUN_00200d94(S_00200d94 *s)
{
    FUN_0010b6d4(s->p, 0, 1);
    FUN_00200df0(s);
    FUN_00201114(s);
    FUN_002014d8(s);
    s->p->v11();
}
