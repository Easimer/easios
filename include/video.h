#ifndef H_VIDEO
#define H_VIDEO

struct VBEModeInfoBlock {
  uint16_t attributes;
  uint8_t winA,winB;
  uint16_t granularity;
  uint16_t winsize;
  uint16_t segmentA, segmentB;
  void* realFctPtr;
  uint16_t pitch; // bytes per scanline

  uint16_t Xres, Yres;
  uint8_t Wchar, Ychar, planes, bpp, banks;
  uint8_t memory_model, bank_size, image_pages;
  uint8_t reserved0;

  uint8_t red_mask, red_position;
  uint8_t green_mask, green_position;
  uint8_t blue_mask, blue_position;
  uint8_t rsv_mask, rsv_position;
  uint8_t directcolor_attributes;

  uint32_t physbase;  // your LFB (Linear Framebuffer) address ;)
  uint32_t reserved1;
  uint16_t reserved2;
} __attribute__((packed));

void vinit(size_t width, size_t height, size_t bpp, size_t pitch, uint64_t addr);
void vplot(size_t x, size_t y, uint8_t r, uint8_t g, uint8_t b);
#endif