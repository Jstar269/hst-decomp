/* Shop item records loaded from the shop Item.csv, grouped into one vector per item category. */
#ifndef HST_SHOP_ITEMS_H
#define HST_SHOP_ITEMS_H

#define SHOP_REC_EMPTY (-1)   /* col[0] value of an unused record */
#define SHOP_VEC_COUNT 8      /* vectors in a ShopItemSet */

/* Category index = the CSV row-name prefix that selects the vector. */
enum {
  SHOP_ITEM_CAM = 0,          /* "Item_Cam" */
  SHOP_ITEM_CD = 1,           /* "Item_CD" */
  SHOP_ITEM_VOICE = 2,        /* "Item_Voice" */
  SHOP_ITEM_JUDGE_VOICE = 3,  /* "Item_JudgeVoice" */
  SHOP_ITEM_WALLPAPER = 4,    /* "Item_Wallpaper" */
  SHOP_ITEM_TICKETS = 5,      /* "Item_Tickets" */
  SHOP_ITEM_JUDGE = 6         /* "Judge_" */
};

typedef struct ShopRec {      /* size 10 */
  short col[5];               /* CSV columns 1..5 */
} ShopRec;

typedef struct ShopVec {      /* size 0xc */
  ShopRec *data;              /* 0x0 */
  unsigned size;              /* 0x4 */
  unsigned cap;               /* 0x8 */
} ShopVec;

typedef struct ShopItemSet {
  ShopVec vecs[SHOP_VEC_COUNT];
} ShopItemSet;

#endif
