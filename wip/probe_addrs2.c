/* HSTMATCH module=EBOOT.BIN start=0x0022060c end=0x00220704 symbol=FUN_0022060c lang=c++ */
/* Probe: which single-use global-load form makes MWCC materialize the symbol address? */
extern "C" {
extern char *DAT_002f0b80;
extern char *DAT_002f0b84;
extern char *DAT_002f0b88;
extern char *DAT_002f0b90;
extern char *DAT_002f0b94;
extern char *DAT_002f0b98;
extern char *DAT_002f0b9c;
extern char *DAT_002f0ba0;
extern int DAT_002f0ba8;
extern char *DAT_002f0bac[2];
extern char *volatile DAT_002f0bb0;
}
template <class T> inline const T &Id(const T &a) { return a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
static inline char **Ref(void) { return &DAT_002f0b88; }
inline char *&RefRef(void) { return DAT_002f0b88; }

int *FUN_0022060c(int *self)
{
    return self;
}

extern "C" int *p_plain(int *s) { s[1] = (int)DAT_002f0b80; return s; }
extern "C" int *p_addrlocal(int *s) { char **p = &DAT_002f0b84; s[1] = (int)*p; return s; }
extern "C" int *p_tplid(int *s) { s[1] = (int)Id(DAT_002f0b88); return s; }
extern "C" int *p_refret(int *s) { s[1] = (int)*Ref(); return s; }
extern "C" int *p_refref(int *s) { s[1] = (int)RefRef(); return s; }
extern "C" int *p_arr(int *s) { s[1] = (int)DAT_002f0bac[0]; return s; }
extern "C" int *p_vol(int *s) { s[1] = (int)DAT_002f0bb0; return s; }
extern "C" int *p_intcast(int *s) { s[1] = (int)(char *)DAT_002f0ba8; return s; }
extern "C" int *p_min(int *s) { s[1] = (int)Min(DAT_002f0b90, DAT_002f0b90); return s; }
extern "C" int *p_derefaddr(int *s) { s[1] = (int)*(&DAT_002f0b94); return s; }
extern "C" int *p_idxcast(int *s) { s[1] = (int)((char **)&DAT_002f0b98)[0]; return s; }
extern "C" int *p_2level(int *s) { char **q = Ref(); s[1] = (int)*q; return s; }
extern "C" int *p_refparam(int *s) { s[1] = (int)Id(DAT_002f0b9c); return s; }
extern "C" int *p_twouse(int *s) { s[1] = (int)DAT_002f0ba0 + (int)((char **)&DAT_002f0ba0)[0]; return s; }
// near miss from lane ds9 (unreviewed)
