/* HSTMATCH module=hstp_trans_main.prx start=0x001d0330 end=0x001d0468 symbol=FUN_001d0330 lang=c99 */
/* Clone of src/eboot/FUN_001c2118.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Record with a 200-byte base (cleared first), six slots set by FUN_0008ed94 and a default name. */
typedef struct NameRec {
  char base[0xc8];
  unsigned char unkc8;
  unsigned char unkc9;
  char padca;
  unsigned char unkcb;
  signed char name[13];        /* 0xcc default name: four 3-byte UTF-8 characters, then 'P' */
  char paddd[0xed - 0xd9];
  unsigned char unked;
  unsigned char unkee;
  unsigned char unkef;
  unsigned char unkf0;
  int unkf4;
  int unkf8;
  int unkfc;                   /* holds the bit pattern of 5.0f */
  unsigned char unk100;
  unsigned char unk101;
  char pad102[2];
  int unk104;
} NameRec;

extern unsigned int * FUN_000114c0();
extern void FUN_0008ed94();
extern short * FUN_0008ede8();
extern void FUN_000dbb60();

NameRec * FUN_001d0330(NameRec *self)
{
  FUN_0008ede8();
  FUN_000114c0(self,0,200);
  FUN_0008ed94(self,0,0);
  FUN_0008ed94(self,1,0);
  FUN_0008ed94(self,2,0);
  FUN_0008ed94(self,3,0);
  FUN_0008ed94(self,4,0);
  FUN_0008ed94(self,5,0);
  FUN_000dbb60(self);
  self->unkc8 = 0;
  self->unkcb = 0;
  self->unkc9 = 0;
  self->unked = 0;
  self->unkee = 0;
  self->unkef = 0;
  self->unkf0 = 0;
  self->unkf4 = -1;
  self->unkf8 = -1;
  self->unkfc = 0x40a00000;
  self->unk100 = 10;
  self->unk101 = 0;
  self->unk104 = 0;
  self->name[0] = 0xe3;
  self->name[1] = 0x81;
  self->name[2] = 0xbf;
  self->name[3] = 0xe3;
  self->name[4] = 0x82;
  self->name[5] = 0x93;
  self->name[6] = 0xe3;
  self->name[7] = 0x83;
  self->name[8] = 0x86;
  self->name[9] = 0xe3;
  self->name[10] = 0x83;
  self->name[11] = 0x8b;
  self->name[12] = 0x50;
  return self;
}
