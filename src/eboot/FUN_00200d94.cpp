/* HSTMATCH module=EBOOT.BIN start=0x00200d94 end=0x00200df0 symbol=FUN_00200d94 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
class Part {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
};
struct Screen { char pad[0x708]; Part *part; /* 0x708 */ };
extern "C" void FUN_0010b6d4(Part *part, int a, int b);
extern "C" void FUN_00200df0(Screen *screen);
extern "C" void FUN_00201114(Screen *screen);
extern "C" void FUN_002014d8(Screen *screen);
extern "C" void FUN_00200d94(Screen *screen)
{
    FUN_0010b6d4(screen->part, 0, 1);
    FUN_00200df0(screen);
    FUN_00201114(screen);
    FUN_002014d8(screen);
    screen->part->v11();
}
