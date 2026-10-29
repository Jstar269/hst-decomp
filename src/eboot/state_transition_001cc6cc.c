/* HSTMATCH module=EBOOT.BIN start=0x001cc6cc end=0x001cc77c symbol=FUN_001cc6cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the three cases in retail test order with a switch; readability pass; exact match verified; names and types await human review. */

#define STATE_SPECIAL 6 /* state entered by this function; the previous state is remembered */

extern int DAT_0034a2e0;
extern void FUN_001c2498(void *);
extern void FUN_001cd88c(void *, int, int);
extern void FUN_00225c34(int, int, int);

struct StatePanel {
    char pad0[4];
    int state;          /* 0x04 */
    char pad1[169];
    char flag_b1;       /* 0xb1 */
    char pad2[2];
    int prevState;      /* 0xb4 state before STATE_SPECIAL was entered */
    int f_b8;           /* 0xb8 reset to -1 */
    int f_bc;           /* 0xbc reset to -1 */
    int f_c0;           /* 0xc0 reset to -1 */
};

struct StateOwner {
    char pad0[340];
    int f_154;          /* 0x154 reset to -1 */
    char pad1[4];
    struct StatePanel *panel; /* 0x15c */
};

void FUN_001cc6cc(struct StateOwner *self, int code)
{
    struct StatePanel *panel = self->panel;
    if (panel->state != STATE_SPECIAL) {
        panel->prevState = panel->state;
    }
    panel->f_b8 = -1;
    panel->f_bc = -1;
    panel->f_c0 = -1;
    panel->flag_b1 = 1;

    int flag = 0;
    switch (code) {
    case 12:
    case 13:
    case 14:
        flag = 1;
        break;
    }

    FUN_00225c34(DAT_0034a2e0, code, flag);
    FUN_001cd88c(panel, STATE_SPECIAL, 1);
    FUN_001c2498(panel);
    self->f_154 = -1;
}
