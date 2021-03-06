#ifndef PSXACT_GPU_CORE_HPP
#define PSXACT_GPU_CORE_HPP

#include <cstdint>
#include <queue>
#include "../utility.hpp"

namespace gpu {
  struct state_t {
    uint32_t status = 0x14802000;
    uint32_t texture_window_mask_x;
    uint32_t texture_window_mask_y;
    uint32_t texture_window_offset_x;
    uint32_t texture_window_offset_y;
    uint32_t drawing_area_x1;
    uint32_t drawing_area_y1;
    uint32_t drawing_area_x2;
    uint32_t drawing_area_y2;
    uint32_t x_offset;
    uint32_t y_offset;
    uint32_t display_area_x;
    uint32_t display_area_y;
    uint32_t display_area_x1;
    uint32_t display_area_y1;
    uint32_t display_area_x2;
    uint32_t display_area_y2;
    bool textured_rectangle_x_flip;
    bool textured_rectangle_y_flip;

    struct {
      uint32_t buffer[16];
      int wr;
      int rd;
    } fifo;

    struct {
      struct {
        int x;
        int y;
        int w;
        int h;
      } reg;

      struct {
        bool active;
        int x;
        int y;
      } run;
    } cpu_to_gpu_transfer;

    struct {
      struct {
        int x;
        int y;
        int w;
        int h;
      } reg;

      struct {
        bool active;
        int x;
        int y;
      } run;
    } gpu_to_cpu_transfer;
  };

  extern state_t state;

  uint32_t bus_read(int width, uint32_t address);

  void bus_write(int width, uint32_t address, uint32_t data);

  uint32_t data();

  uint32_t stat();

  void gp0(uint32_t data);

  void gp1(uint32_t data);

  void vram_transfer(uint16_t data);

  uint16_t vram_transfer();

  struct color_t {
    int r;
    int g;
    int b;
  };

  struct point_t {
    int x;
    int y;
  };

  void draw_point(int x, int y, int r, int g, int b);

  namespace gouraud {
    struct pixel_t {
      point_t point;
      color_t color;
    };

    template<int size>
    struct polygon_t {
      pixel_t v[size];
    };

    void draw_poly3(const gpu::gouraud::polygon_t<3> &p);

    void draw_poly4(const gpu::gouraud::polygon_t<4> &p);
  }

  namespace texture {
    struct pixel_t {
      point_t point;
      color_t color;
      int u;
      int v;
    };

    template<int size>
    struct polygon_t {
      pixel_t v[size];
      int clut_x;
      int clut_y;
      int base_u;
      int base_v;
      int depth;
    };

    void draw_poly3(const polygon_t<3> &p);

    void draw_poly4(const polygon_t<4> &p);
  }
}

#endif //PSXACT_GPU_CORE_HPP
