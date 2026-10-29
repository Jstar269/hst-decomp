/* HSTMATCH module=EBOOT.BIN start=0x001fbfa8 end=0x001fc170 symbol=FUN_001fbfa8 lang=c++ data=0x002eefd8 */
/* Hand-written reconstruction from the disassembly (structure taken from the sibling constructors ctor_two_tables_000f13e8.cpp and ctor_two_tables_000ee6d4.c); readability pass; exact match verified (matching idioms: the re-read of the stored array element uses an (unsigned long) address cast so it is not CSE'd with the (unsigned int) store, the callee FUN_00051398 declares its pointer parameter before the float, and the virtual call goes through the stored slot); names and types await human review. Data: its string literals (2 strings, 0x002eefd8-0x002ef019) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern char DAT_00309550[];
extern float DAT_002eedb8;
extern char *DAT_002eef20[];
/* Lookup table row: which widget to search, the node name, and where its value (word 9) is stored. */
struct Entry {
  int idx;
  int name;
  int out;
};
extern Entry DAT_002eef78[];

extern "C" {
void FUN_00102e38(void *);
void FUN_00104118(void *, char *, int);
void FUN_00103540(void *, float);
int FUN_000143b0(char *, const char *, ...);
void *FUN_00000bcc(unsigned);
void *FUN_00050fc0(void *);
void FUN_000511c4(void *, char *, int);
void FUN_00051398(void *, float);
void FUN_000ffb3c(void *, int);
void *FUN_001039d8(void *, char *, int);
int *FUN_001026b8(void *, int);
}

class Widget {
public:
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5(int v);
};

enum { TUTORIAL_PAGES = 3, TUTORIAL_WIDGETS = 3, TUTORIAL_NODES = 8, PAGE_OBJ_SIZE = 0x48 };

struct Tutorial {
  void *vtable;                       /* 0x00 */
  char pad04[0x50];
  Widget *widget[TUTORIAL_WIDGETS];   /* 0x54 widgets looked up by name */
  int *node[TUTORIAL_NODES];          /* 0x60 nodes looked up inside the widgets */
  void *page[TUTORIAL_PAGES];         /* 0x80 page objects, one per tutorial_%03d layout */
  int unk8c;                          /* 0x8c */
  unsigned char unk90;                /* 0x90 */
};

/* Constructor: loads the tutorial layout, creates the three page objects, looks up the widgets and nodes. */
extern "C" Tutorial *FUN_001fbfa8(Tutorial *self)
{
  char buf[256];
  FUN_00102e38(self);
  self->vtable = DAT_00309550;
  FUN_00104118(self, "data/menu/tutorial/tutorial.lay", 0);
  FUN_00103540(self, DAT_002eedb8);
  self->page[0] = 0;
  self->page[1] = 0;
  self->page[2] = 0;
  int page_index = 0;
  int page_off = 0;
  do {
    FUN_000143b0(buf, "data/menu/tutorial/tutorial_%03d", page_index + 1);
    void *page_obj = FUN_00000bcc(PAGE_OBJ_SIZE);
    if (page_obj != 0)
      page_obj = FUN_00050fc0(page_obj);
    *(void **)((unsigned int)self + page_off + 0x80) = page_obj;
    FUN_000511c4(page_obj, buf, 0);
    FUN_00051398(*(void **)((unsigned long)self + page_off + 0x80), 100.0f + DAT_002eedb8);
    page_index++;
    page_off += 4;
  } while (page_index < TUTORIAL_PAGES);
  int widget_index = 0;
  char **widget_name = DAT_002eef20;
  int widget_off = 0;
  do {
    Widget *w = (Widget *)FUN_001039d8(self, *widget_name, 0);
    *(Widget **)((unsigned int)self + widget_off + 0x54) = w;
    (*(Widget **)((unsigned int)self + widget_off + 0x54))->m5(-2);
    widget_index++;
    widget_name++;
    widget_off += 4;
  } while (widget_index < TUTORIAL_WIDGETS);
  int node_index = 0;
  Entry *e = DAT_002eef78;
  int node_off = 0;
  do {
    int *node = FUN_001026b8(self->widget[e->idx], e->name);
    *(int **)((unsigned int)self + node_off + 0x60) = node;
    if (node != 0)
      e->out = node[9];
    node_index++;
    e++;
    node_off += 4;
  } while (node_index < TUTORIAL_NODES);
  FUN_000ffb3c(self->node[6], 1);
  FUN_000ffb3c(self->node[2], 1);
  FUN_000ffb3c(self->node[5], 1);
  self->unk8c = 0;
  self->unk90 = 1;
  return self;
}
