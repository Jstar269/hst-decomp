/* HSTMATCH module=EBOOT.BIN start=0x001270d4 end=0x001271dc symbol=FUN_001270d4 lang=c99 helpers=FUN_00126d1c@0x00126d1c-0x00126d48 */
/* Hand-written reconstruction from the disassembly (same-file static log stub FUN_00126d1c placed by helpers=; the first range forwards param_2 with -1/0); exact match verified; names and types await human review. */
/* Ids below MOTION_PLAIN_END are kinds of their own (variant -1); each later range is one kind (6 to 10) whose
   variant is the id's offset inside the range. Out-of-range ids are reported through the log stub. */
enum {
    MOTION_PLAIN_END = 6,
    MOTION_KIND6_END = 0xe,
    MOTION_KIND7_END = 0x14,
    MOTION_KIND8_END = 0x1c,
    MOTION_KIND9_END = 0x26,
    MOTION_KIND10_END = 0x29
};
extern char DAT_002da818[];
static void FUN_00126d1c(...) {}
extern void FUN_0012a254(int, ...);

void FUN_001270d4(int obj, int id)
{
    if (id < 0)
        FUN_00126d1c(DAT_002da818);
    if (id < MOTION_PLAIN_END)
        FUN_0012a254(obj, id, -1, 0);
    else if (id < MOTION_KIND6_END)
        FUN_0012a254(obj, 6, id - MOTION_PLAIN_END, 0);
    else if (id < MOTION_KIND7_END)
        FUN_0012a254(obj, 7, id - MOTION_KIND6_END, 0);
    else if (id < MOTION_KIND8_END)
        FUN_0012a254(obj, 8, id - MOTION_KIND7_END, 0);
    else if (id < MOTION_KIND9_END)
        FUN_0012a254(obj, 9, id - MOTION_KIND8_END, 0);
    else if (id < MOTION_KIND10_END)
        FUN_0012a254(obj, 10, id - MOTION_KIND9_END, 0);
    else
        FUN_00126d1c(DAT_002da818);
}
