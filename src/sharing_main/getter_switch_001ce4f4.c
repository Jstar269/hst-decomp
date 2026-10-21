/* HSTMATCH module=hstp_trans_main.prx start=0x001ce4f4 end=0x001ce840 symbol=FUN_001ce4f4 lang=c99 rodata=0x002d67f8 */
/* Clone of src/eboot/getter_switch_001c02e0.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: kinds 0..6 are inline byte getters (`static inline` with `unsigned char r = 0; ... if (p != 0) r = *p; return r;`, called as `return Gk(self, idx)`), which is what leaves their branch delay slots unfilled in retail (`lbu v0,0(v1); b END; nop`); kinds 7.. are written directly in the switch (`r = *p; break;`, delay slot filled). The jump table sits at rodata 0x2d67f8. */
static inline unsigned char G0(char *self, int idx)
{
    unsigned char *p;
    unsigned char r = 0;
    if (idx >= 0 && idx < 15) {
        p = (unsigned char *)(self + idx * 0x38 + 4);
    } else {
        p = 0;
    }
    if (p != 0) r = *p;
    return r;
}
static inline unsigned char G1(char *self, int idx)
{
    unsigned char *p;
    unsigned char r = 0;
    if (idx >= 0 && idx < 640) {
        p = (unsigned char *)(self + idx + 0x84c);
    } else {
        p = 0;
    }
    if (p != 0) r = *p;
    return r;
}
static inline unsigned char G2(char *self, int idx)
{
    unsigned char *p;
    unsigned char r = 0;
    if (idx >= 0 && idx < 640) {
        p = (unsigned char *)(self + idx + 0xacc);
    } else {
        p = 0;
    }
    if (p != 0) r = *p;
    return r;
}
static inline unsigned char G3(char *self, int idx)
{
    unsigned char *p;
    unsigned char r = 0;
    if (idx >= 0 && idx < 640) {
        p = (unsigned char *)(self + idx + 0xd4c);
    } else {
        p = 0;
    }
    if (p != 0) r = *p;
    return r;
}
static inline unsigned char G4(char *self, int idx)
{
    unsigned char *p;
    unsigned char r = 0;
    if (idx >= 0 && idx < 640) {
        p = (unsigned char *)(self + idx * 2 + 0x34c);
    } else {
        p = 0;
    }
    if (p != 0) r = *p;
    return r;
}
static inline unsigned char G5(char *self, int idx)
{
    unsigned char *p;
    unsigned char r = 0;
    if (idx >= 0 && idx < 21) {
        p = (unsigned char *)(self + idx + 0xfcc);
    } else {
        p = 0;
    }
    if (p != 0) r = *p;
    return r;
}
static inline unsigned char G6(char *self, int idx)
{
    unsigned char *p;
    unsigned char r = 0;
    if (idx >= 0 && idx < 8) {
        p = (unsigned char *)(self + idx + 0xfe1);
    } else {
        p = 0;
    }
    if (p != 0) r = *p;
    return r;
}
unsigned char FUN_001ce4f4(char *self, unsigned kind, int idx)
{
    unsigned char r = 0;
    unsigned char *p;
    switch (kind) {
    case 0:
        return G0(self, idx);
    case 1:
        return G1(self, idx);
    case 2:
        return G2(self, idx);
    case 3:
        return G3(self, idx);
    case 4:
        return G4(self, idx);
    case 5:
        return G5(self, idx);
    case 6:
        return G6(self, idx);
    case 7:
        if (idx >= 0 && idx < 10) {
            p = (unsigned char *)(self + idx + 0xfe9);
        } else {
            p = 0;
        }
        if (p != 0) {
            r = *p;
        }
        break;
    case 8:
        if (idx >= 0 && idx < 10) {
            p = (unsigned char *)(self + idx + 0xff3);
        } else {
            p = 0;
        }
        if (p != 0) {
            r = *p;
        }
        break;
    case 9:
        if (idx >= 0 && idx < 15) {
            p = (unsigned char *)(self + idx + 0xffd);
        } else {
            p = 0;
        }
        if (p != 0) {
            r = *p;
        }
        break;
    case 10:
        if (idx >= 0 && idx < 10) {
            p = (unsigned char *)(self + idx + 0x100c);
        } else {
            p = 0;
        }
        if (p != 0) {
            r = *p;
        }
        break;
    case 11:
        if (idx >= 0 && idx < 10) {
            p = (unsigned char *)(self + idx + 0x1016);
        } else {
            p = 0;
        }
        if (p != 0) {
            r = *p;
        }
        break;
    case 12:
        r = *(unsigned char *)(self + 0x1024);
        break;
    case 13:
        if (idx >= 0 && idx < 12) {
            p = (unsigned char *)(self + idx * 5 + 0x3444);
        } else {
            p = 0;
        }
        if (p != 0) {
            r = *p;
        }
        break;
    case 15:
        if (idx >= 0 && idx < 40) {
            p = (unsigned char *)(self + idx * 0x14 + 0x1058);
        } else {
            p = 0;
        }
        if (p != 0) {
            r = *p;
        }
        break;
    }
    return r;
}
