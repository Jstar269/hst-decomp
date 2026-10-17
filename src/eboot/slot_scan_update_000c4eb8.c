/* HSTMATCH module=EBOOT.BIN start=0x000c4eb8 end=0x000c5014 symbol=FUN_000c4eb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: typed 7-byte entry array and 0x120-byte table, for-loop with signed bound and index declared first, int-returning callees, early return before the counter bump; exact match verified; names and types await human review. */
typedef struct Ent { char pad[6]; unsigned char on; } Ent;
typedef struct Obj { char pad0[0x58]; Ent ent[4]; char pad1[0x178 - 0x58 - 28]; unsigned char m178; char pad2[0x198 - 0x179]; int cur; } Obj;
typedef struct Tab { unsigned char first; char pad1[0xdf]; unsigned char flag; char pad2[3]; char x[0x120 - 0xe4]; } Tab;
typedef struct Self { char pad0[0x780]; int m780; void *m784; } Self;

extern Obj *DAT_00338ac4;
extern Tab DAT_003417b8[];
extern int FUN_00285f3c(void *);
extern void FUN_0028637c(void *, int, int, void *);
extern void FUN_000bb190(Obj *);
extern void FUN_000bb0f4(Obj *, Ent *);
extern void FUN_000bd6a4(Obj *, int);
extern int FUN_000bd8e0(Obj *, int);
extern int FUN_000bd8f8(Obj *, int);

void FUN_000c4eb8(Self *self)
{
    if (DAT_00338ac4 != 0) {
        int cur;
        int n;
        int i;
        if (FUN_00285f3c(self->m784) == 0)
            return;
        FUN_000bb190(DAT_00338ac4);
        cur = DAT_00338ac4->cur;
        if (DAT_003417b8[0].first == 0) {
            n = 2;
        } else {
            n = 4;
        }
        for (i = 0; i < n; i++) {
            Obj *g = DAT_00338ac4;
            if (g->ent[i].on != 0) {
                if (i != cur)
                    FUN_000bd6a4(g, i);
            } else if (DAT_003417b8[i].flag == 0) {
                int a = FUN_000bd8e0(g, i);
                int b = FUN_000bd8f8(g, i);
                FUN_0028637c(self->m784, a, b, DAT_003417b8[i].x);
                if (DAT_00338ac4->m178 != 0)
                    FUN_000bb0f4(DAT_00338ac4, &DAT_00338ac4->ent[i]);
            }
        }
    }
    self->m780 = self->m780 + 1;
}
