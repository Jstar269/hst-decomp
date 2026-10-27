/* HSTMATCH module=hstp_trans_main.prx start=0x000026d8 end=0x00002774 symbol=FUN_000026d8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Runtime support next to __throw (0x260c): finds the entry of the 16-slot pair table DAT_003b3310 (filled by
   FUN_00002774) whose range [a->start, b->start + (b->size & ~1)) contains addr and copies the pair into
   info+0xc/+0x10 (returns 1), else returns 0. Same code as EBOOT 0x000026d8 (table 0x0030a040).
   `i = 0` before the table pointer schedules `move t0,zero` between its lui/addiu; `start <= addr` (not
   `addr >= start`) gives retail's `sltu at`. Names provisional. */
typedef struct { unsigned start; unsigned size; } Range;
typedef struct { Range *a; Range *b; } Frag;
typedef struct { char pad[0xc]; Range *a; Range *b; } Info;

extern Frag DAT_003b3310[16];

int FUN_000026d8(Info *info, unsigned addr)
{
    int i;
    Frag *f;
    for (i = 0, f = DAT_003b3310; i < 16; i++, f++) {
        if (f->a != 0 && f->a->start <= addr && addr < f->b->start + (f->b->size & ~1)) {
            info->a = DAT_003b3310[i].a;
            info->b = DAT_003b3310[i].b;
            return 1;
        }
    }
    return 0;
}
