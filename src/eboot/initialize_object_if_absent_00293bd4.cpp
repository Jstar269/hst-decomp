/* HSTMATCH module=EBOOT.BIN start=0x00293bd4 end=0x00293c6c symbol=FUN_00293bd4 lang=c++ */
/* ShopItem_PreloadCsv: data/menu/shop/Item.csv; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Csv {
  virtual ~Csv();
};

extern Csv *DAT_0034a84c;
extern char DAT_002ffbe4;
extern const char DAT_002ffbcc[];
extern "C" void *FUN_00000bcc(int);
extern "C" Csv *FUN_000649c0(void *);
extern "C" int FUN_00064bf4(Csv *, const char *, int, void *);

/* Loads the shop item table the first time it is needed; drops it again if the load fails. */
extern "C" void FUN_00293bd4(void)
{
  if (DAT_0034a84c == 0) {
    Csv *csv = (Csv *)FUN_00000bcc(0x10);
    if (csv != 0)
      csv = FUN_000649c0(csv);
    DAT_0034a84c = csv;

    int loaded = FUN_00064bf4(csv, DAT_002ffbcc, 1, &DAT_002ffbe4);
    if (loaded == 0 && DAT_0034a84c != 0) {
      delete DAT_0034a84c;
      DAT_0034a84c = 0;
    }
  }
}
