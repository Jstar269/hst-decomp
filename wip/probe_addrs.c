/* HSTMATCH module=EBOOT.BIN start=0x0022060c end=0x00220704 symbol=FUN_0022060c lang=c++ */
/* probe file: which global-load form makes MWCC materialize the symbol address? */
extern "C" {
extern char *DAT_002f0b8c;
extern int DAT_002f0ba4[];
struct Tbl { char *name; int pad[5]; };
}
template <class T> inline const T &Id(const T &a) { return a; }
inline char **Ref(void) { return &DAT_002f0b8c; }

int *FUN_0022060c(int *self)
{
    int sum = 0;

    sum += (int)DAT_002f0b8c;
    {
        char **p = &DAT_002f0b8c;
        sum += (int)*p;
    }
    sum += (int)*(char **)&DAT_002f0b8c;
    sum += (int)Id(DAT_002f0b8c);
    sum += (int)*(&DAT_002f0b8c);
    sum += (int)((char **)&DAT_002f0b8c)[0];
    sum += (int)((struct Tbl *)&DAT_002f0b8c)->name;
    {
        char *&r = DAT_002f0b8c;
        sum += (int)r;
    }
    sum += (int)*Ref();
    {
        char **q = Ref();
        sum += (int)*q;
    }
    sum += (int)Id(((struct Tbl *)&DAT_002f0b8c)->name);
    self[0x17] = sum;
    return self;
}
// near miss from lane ds9 (unreviewed)
