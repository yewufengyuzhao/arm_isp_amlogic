/*
*
* SPDX-License-Identifier: GPL-2.0
*
* Copyright (C) 2011-2018 ARM or its affiliates
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; version 2.
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*/

#if !defined(__ISP_SENSOR_H__)
#define __ISP_SENSOR_H__


/*-----------------------------------------------------------------------------
Initialization sequence - do not edit
-----------------------------------------------------------------------------*/

#include "sensor_init.h"

static acam_reg_t linear[] = {
    { 0x18f98, 0x20000L, 0x70007,4 },
    { 0x18eac, 0x30L, 0x30,1 },
    { 0x1937c, 0x0L, 0xffffff,4 },
    { 0x18e8c, 0x0L, 0x3000000,4 },
    { 0x1aa3c, 0x40L, 0xffffff,4 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};


static acam_reg_t settings[] = {
    { 0x80, 0x2L, 0x19fdf0f,4 },
    { 0x84, 0x1000700L, 0xf0f1f03,4 },
    { 0x88, 0xffffL, 0x0,4 },
    { 0x8c, 0x0L, 0x0,4 },
    { 0x10, 0x0L, 0x1,1 },
    { 0x94, 0x0L, 0x0,4 },
    { 0x18, 0x200020L, 0x0,4 },
    { 0x9c, 0x1L, 0x87,1 },
    { 0x20, 0x0L, 0x103,2 },
    { 0x24, 0x4L, 0x7,1 },
    { 0x30, 0xffffffffL, 0x0,4 },
    { 0x34, 0xffffffffL, 0x0,4 },
    //{ 0x3c, 0x1L, 0x1,1 },
    { 0x40, 0x0L, 0x1,1 },
    { 0x44, 0x0L, 0x0,4 },
    { 0x50, 0x3L, 0xf,1 },
    { 0x54, 0x1L, 0xfff,2 },
    { 0x58, 0x0L, 0x3,1 },
    { 0x90, 0xffff0000L, 0x0,4 },
    { 0x64, 0x0L, 0x20,1 },
    { 0x6c, 0x1L, 0x101,2 },
    { 0x14, 0x20L, 0x0,2 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};


static acam_reg_t fpga_fs_lin[] = {
    { 0x209650, 0x50000L, 0x70007,4 },
    { 0x209654, 0x0L, 0x3,1 },
    { 0x209398, 0x2L, 0x3,1 },
    { 0x20964c, 0x40305L, 0x70707,4 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};


static acam_reg_t fs_lin_2exp[] = {
    { 0x18ed4, 0x3010200L, 0x3030303,4 },
    { 0x18eac, 0x0L, 0x30,1 },
    { 0x18f98, 0x10007L, 0x70007,4 },
    { 0x18e8c, 0x1000000L, 0x3000000,4 },
    { 0x18fe4, 0x1L, 0x3,1 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};


static acam_reg_t fs_lin_3exp[] = {
    { 0x18ed4, 0x3010200L, 0x3030303,4 },
    { 0x18eac, 0x0L, 0x30,1 },
    { 0x18f98, 0x10007L, 0x70007,4 },
    { 0x18e8c, 0x1000000L, 0x3000000,4 },
    { 0x18fe4, 0x2L, 0x3,1 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};


static acam_reg_t settings_fpga[] = {
    { 0x209000, 0x1L, 0x0,1 },
    { 0x209800, 0x284L, 0x0,4 },
    { 0x209004, 0x1L, 0x0,1 },
    { 0x209008, 0x1L, 0x0,1 },
    { 0x20900c, 0x1L, 0x0,1 },
    { 0x209010, 0x1L, 0x0,1 },
    { 0x209014, 0x1L, 0x0,1 },
    { 0x209018, 0x1L, 0x0,1 },
    { 0x209804, 0xfe40L, 0x0,4 },
    { 0x20981c, 0xffffL, 0x0,2 },
    { 0x209020, 0x1L, 0x0,1 },
    { 0x209024, 0x1L, 0x0,1 },
    { 0x209028, 0x1L, 0x0,1 },
    { 0x20902c, 0x1L, 0x0,1 },
    { 0x209830, 0x8fffL, 0x0,2 },
    { 0x209808, 0xee9eL, 0x0,4 },
    { 0x209034, 0x1L, 0x0,1 },
    { 0x209038, 0x0L, 0x1,1 },
    { 0x20903c, 0x0L, 0x1,1 },
    { 0x209040, 0x2L, 0x0,1 },
    { 0x209844, 0x1L, 0x3fff,2 },
    { 0x20980c, 0x6L, 0x0,4 },
    { 0x20904c, 0x0L, 0x11,1 },
    { 0x209050, 0x5000000L, 0x0,4 },
    { 0x209054, 0x1e00L, 0x0,4 },
    { 0x209058, 0x1L, 0x1,1 },
    { 0x20985c, 0x438L, 0x0,2 },
    { 0x209060, 0x0L, 0x0,4 },
    { 0x209064, 0x0L, 0x0,4 },
    { 0x209068, 0x780L, 0x0,2 },
    { 0x20906c, 0x438L, 0x0,2 },
    { 0x209870, 0x0L, 0x0,4 },
    { 0x209874, 0x0L, 0xf,1 },
    { 0x209878, 0xf00L, 0x0,4 },
    { 0x209814, 0x0L, 0x7,1 },
    { 0x20987c, 0x2L, 0x3,1 },
    { 0x209080, 0x0L, 0x0,1 },
    { 0x209884, 0x0L, 0x7,1 },
    { 0x209888, 0x3000000L, 0x0,4 },
    { 0x20988c, 0x3000000L, 0x0,4 },
    { 0x209090, 0x0L, 0x11,1 },
    { 0x209818, 0x4L, 0x0,1 },
    { 0x209894, 0x2494L, 0x0,2 },
    { 0x209098, 0x1000L, 0x0,4 },
    { 0x20909c, 0x0L, 0x1,1 },
    { 0x2090a0, 0x0L, 0x0,4 },
    { 0x2098a4, 0x0L, 0x0,1 },
    { 0x2098a8, 0x70L, 0x0,1 },
    { 0x20901c, 0x1L, 0x0,1 },
    { 0x2090ac, 0x438L, 0x0,2 },
    { 0x2098b0, 0x0L, 0x0,4 },
    { 0x2098b4, 0x0L, 0x0,4 },
    { 0x2098b8, 0xfL, 0x19fdf0f,4 },
    { 0x2098bc, 0x1000700L, 0xf0f1f03,4 },
    { 0x2098c0, 0xffffL, 0x0,2 },
    { 0x209820, 0xffffL, 0x0,2 },
    { 0x2098c4, 0x0L, 0x0,2 },
    { 0x2098c8, 0x0L, 0x0,2 },
    { 0x2098cc, 0x0L, 0x0,2 },
    { 0x2098d0, 0x0L, 0x0,2 },
    { 0x2098d4, 0xffffL, 0x0,2 },
    { 0x2098d8, 0x0L, 0x0,2 },
    { 0x209824, 0xffffL, 0x0,2 },
    { 0x2098dc, 0x0L, 0x0,2 },
    { 0x2098e0, 0x780L, 0x0,2 },
    { 0x2098e4, 0x438L, 0x0,2 },
    { 0x2098e8, 0x1L, 0x87,1 },
    { 0x2098ec, 0x1L, 0x7,1 },
    { 0x2098f0, 0x0L, 0x1,1 },
    { 0x209828, 0x8fffL, 0x0,2 },
    { 0x2098f4, 0x0L, 0x1,1 },
    { 0x209900, 0x26L, 0x0,4 },
    { 0x209904, 0xb90L, 0x0,4 },
    { 0x209908, 0x8154L, 0x0,4 },
    { 0x20982c, 0x8fffL, 0x0,2 },
    { 0x20990c, 0x12L, 0x0,4 },
    { 0x209910, 0x0L, 0x0,4 },
    { 0x209914, 0x820L, 0x0,4 },
    { 0x209918, 0x82e7L, 0x0,4 },
    { 0x20991c, 0x20L, 0x0,4 },
    { 0x209920, 0x8L, 0x0,4 },
    { 0x209030, 0x1L, 0x0,1 },
    { 0x209924, 0xfa9dL, 0x0,4 },
    { 0x209928, 0x828cL, 0x0,4 },
    { 0x20992c, 0xfL, 0x0,4 },
    { 0x209930, 0x284L, 0x0,4 },
    { 0x209934, 0xfe40L, 0x0,4 },
    { 0x209938, 0x9e6eL, 0x0,4 },
    { 0x209834, 0x3caaL, 0x0,2 },
    { 0x20993c, 0x1L, 0x0,4 },
    { 0x209944, 0x0L, 0x7,1 },
    { 0x209948, 0x3L, 0x0,1 },
    { 0x20994c, 0xffffL, 0x0,2 },
    { 0x209950, 0xffffL, 0x0,2 },
    { 0x209838, 0x0L, 0x0,2 },
    { 0x209954, 0xffffL, 0x0,2 },
    { 0x209958, 0x8fffL, 0x0,2 },
    { 0x20995c, 0x8fffL, 0x0,2 },
    { 0x209960, 0x8fffL, 0x0,2 },
    { 0x209964, 0x3caaL, 0x0,2 },
    { 0x209968, 0x0L, 0x0,2 },
    { 0x20983c, 0x1L, 0x3fff,2 },
    { 0x20996c, 0x1L, 0x3fff,2 },
    { 0x209970, 0x100L, 0x3fff,2 },
    { 0x209974, 0x1L, 0x3fff,2 },
    { 0x20997c, 0x100L, 0x3fff,2 },
    { 0x209980, 0x6L, 0xcf,1 },
    { 0x209840, 0x100L, 0x3fff,2 },
    { 0x209984, 0x0L, 0xf,1 },
    { 0x209988, 0x780L, 0x0,2 },
    { 0x20998c, 0x438L, 0x0,2 },
    { 0x209990, 0x4000000L, 0x0,4 },
    { 0x209994, 0x0L, 0x0,4 },
    { 0x209998, 0x0L, 0x0,4 },
    { 0x20999c, 0x0L, 0x0,4 },
    { 0x2099a0, 0x0L, 0x0,4 },
    { 0x2099a4, 0x0L, 0xf,1 },
    { 0x2099a8, 0xf00L, 0x0,4 },
    { 0x2099ac, 0x2L, 0x3,1 },
    { 0x2099b0, 0x0L, 0x3f,1 },
    { 0x2099b4, 0x0L, 0x7,1 },
    { 0x2099b8, 0x4000000L, 0x0,4 },
    { 0x2099bc, 0x4000000L, 0x0,4 },
    { 0x2099c0, 0xf9c0L, 0x0,2 },
    { 0x2099c4, 0x23bdL, 0x0,2 },
    { 0x2099c8, 0x0L, 0xf,1 },
    { 0x20984c, 0x100L, 0x3fff,2 },
    { 0x2099cc, 0x0L, 0x0,1 },
    { 0x2099d0, 0x0L, 0x0,1 },
    { 0x2099d4, 0x0L, 0x0,1 },
    { 0x2099d8, 0x70L, 0x0,1 },
    { 0x2099dc, 0x1L, 0x3,1 },
    { 0x2099e0, 0x0L, 0x0,4 },
    { 0x209850, 0x6L, 0xcf,1 },
    { 0x2099e4, 0x0L, 0x0,4 },
    { 0x209854, 0x0L, 0xf,1 },
    { 0x209200, 0x12aL, 0x0,2 },
    { 0x209204, 0x0L, 0x0,2 },
    { 0x209208, 0x1d2L, 0x0,2 },
    { 0x20920c, 0x12aL, 0x0,2 },
    { 0x209210, 0x0L, 0x0,2 },
    { 0x209858, 0x780L, 0x0,2 },
    { 0x209214, 0x8088L, 0x0,2 },
    { 0x209218, 0x12aL, 0x0,2 },
    { 0x20921c, 0x21dL, 0x0,2 },
    { 0x209220, 0x0L, 0x0,2 },
    { 0x209224, 0x420L, 0x7ff,2 },
    { 0x209228, 0x134L, 0x7ff,2 },
    { 0x20922c, 0x401L, 0x7ff,2 },
    { 0x209230, 0x1L, 0xf,1 },
    { 0x209238, 0x3ff0000L, 0x3ff03ff,4 },
    { 0x20923c, 0x3ff0000L, 0x3ff03ff,4 },
    { 0x209860, 0x3000000L, 0x0,4 },
    { 0x209244, 0x0L, 0x17,1 },
    { 0x209258, 0x3ff03ffL, 0x3ff03ff,4 },
    { 0x209864, 0x13c6800L, 0x0,4 },
    { 0x20925c, 0x3ffL, 0x3ff,2 },
    { 0x209264, 0xfL, 0x19fdf0f,4 },
    { 0x209268, 0x1000700L, 0xf0f1f03,4 },
    { 0x20926c, 0xffffL, 0x0,2 },
    { 0x209270, 0x0L, 0x0,2 },
    { 0x209868, 0x1fa4000L, 0x0,4 },
    { 0x209274, 0x780L, 0x0,2 },
    { 0x209278, 0x0L, 0x0,2 },
    { 0x20927c, 0x780L, 0x0,2 },
    { 0x209280, 0xffffL, 0x0,2 },
    { 0x209284, 0x1L, 0x0,2 },
    { 0x209288, 0x438L, 0x0,2 },
    { 0x20986c, 0x0L, 0x0,4 },
    { 0x20928c, 0x780L, 0x0,2 },
    { 0x209290, 0x438L, 0x0,2 },
    { 0x209294, 0x1L, 0x87,1 },
    { 0x209298, 0x1L, 0x7,1 },
    { 0x20929c, 0x0L, 0x1,1 },
    { 0x2092a0, 0x0L, 0x1,1 },
    { 0x2092ac, 0x26L, 0x0,4 },
    { 0x2092b0, 0x780L, 0x0,4 },
    { 0x2092b4, 0x8156L, 0x0,4 },
    { 0x2092b8, 0x12L, 0x0,4 },
    { 0x2092bc, 0x0L, 0x0,4 },
    { 0x2092c0, 0x439L, 0x0,4 },
    { 0x2092c4, 0x82e6L, 0x0,4 },
    { 0x2092c8, 0x20L, 0x0,4 },
    { 0x2092cc, 0x8L, 0x0,4 },
    { 0x2092d0, 0xfa9dL, 0x0,4 },
    { 0x2092d4, 0x828cL, 0x0,4 },
    { 0x2092d8, 0xfL, 0x0,4 },
    { 0x2092dc, 0x284L, 0x0,4 },
    { 0x2092e0, 0xfe40L, 0x0,4 },
    { 0x2092e4, 0xbc56L, 0x0,4 },
    { 0x2092e8, 0x1L, 0x0,4 },
    { 0x2092f0, 0x0L, 0x7,1 },
    { 0x2092f4, 0x2L, 0x0,1 },
    { 0x2092f8, 0xffffL, 0x0,2 },
    { 0x2092fc, 0xffffL, 0x0,2 },
    { 0x209300, 0xffffL, 0x0,2 },
    { 0x209880, 0x0L, 0x3f,1 },
    { 0x209304, 0x8fffL, 0x0,2 },
    { 0x209308, 0x8fffL, 0x0,2 },
    { 0x20930c, 0x8fffL, 0x0,2 },
    { 0x209310, 0x3caaL, 0x0,2 },
    { 0x209314, 0x0L, 0x0,2 },
    { 0x209318, 0x1L, 0x3fff,2 },
    { 0x20931c, 0x100L, 0x3fff,2 },
    { 0x209320, 0x1L, 0x3fff,2 },
    { 0x209328, 0x100L, 0x3fff,2 },
    { 0x20932c, 0x6L, 0xcf,1 },
    { 0x209330, 0x0L, 0xf,1 },
    { 0x209334, 0x780L, 0x0,2 },
    { 0x209338, 0x438L, 0x0,2 },
    { 0x20933c, 0x1000000L, 0x0,4 },
    { 0x209340, 0xbdd800L, 0x0,4 },
    { 0x209344, 0x17bb000L, 0x0,4 },
    { 0x209348, 0x0L, 0x0,4 },
    { 0x20908c, 0x0L, 0xe,1 },
    { 0x20934c, 0x0L, 0x0,4 },
    { 0x209350, 0x0L, 0xf,1 },
    { 0x209354, 0xf00L, 0x0,4 },
    { 0x209358, 0x2L, 0x3,1 },
    { 0x20935c, 0x0L, 0x3f,1 },
    { 0x209360, 0x0L, 0x7,1 },
    { 0x209890, 0xf9bbL, 0x0,2 },
    { 0x209364, 0x1000000L, 0x0,4 },
    { 0x209368, 0x1000000L, 0x0,4 },
    { 0x20936c, 0xf9b0L, 0x0,2 },
    { 0x209370, 0x3600L, 0x0,2 },
    { 0x209374, 0x0L, 0xf,1 },
    { 0x209378, 0x0L, 0x0,1 },
    { 0x209094, 0x0L, 0x0,4 },
    { 0x20937c, 0x0L, 0x0,1 },
    { 0x209380, 0x0L, 0x0,1 },
    { 0x209384, 0x70L, 0x0,1 },
    { 0x209388, 0x1L, 0x3,1 },
    { 0x20938c, 0x0L, 0x0,4 },
    { 0x209390, 0x0L, 0x0,4 },
    { 0x209898, 0x0L, 0xf,1 },
    { 0x209394, 0x0L, 0x0,2 },
    { 0x209398, 0x6L, 0x7,1 },
    { 0x20939c, 0xfffffL, 0x0,4 },
    { 0x2093a0, 0xfffffL, 0x0,4 },
    { 0x20989c, 0x0L, 0x0,1 },
    { 0x2098a0, 0x0L, 0x0,1 },
    { 0x2090a4, 0x0L, 0x0,4 },
    { 0x2090a8, 0x780L, 0x0,2 },
    { 0x2098ac, 0x1L, 0x3,1 },
    { 0x2094a4, 0xfL, 0xf19fdf0f,4 },
    { 0x2094a8, 0x1000700L, 0xf0f1f03,4 },
    { 0x2094ac, 0xffffL, 0x0,2 },
    { 0x2094b0, 0xaL, 0x0,2 },
    { 0x2094b4, 0x780L, 0x0,2 },
    { 0x2094b8, 0x0L, 0x0,2 },
    { 0x2094bc, 0x780L, 0x0,2 },
    { 0x2094c0, 0xffffL, 0x0,2 },
    { 0x2094c4, 0x14L, 0x0,2 },
    { 0x2094c8, 0x438L, 0x0,2 },
    { 0x2094cc, 0x780L, 0x0,2 },
    { 0x2094d0, 0x438L, 0x0,2 },
    { 0x2094d4, 0x1L, 0x87,1 },
    { 0x2094d8, 0x1L, 0x7,1 },
    { 0x2094e4, 0x4380780L, 0x0,4 },
    { 0x2094e8, 0x3L, 0x7,1 },
    { 0x2094ec, 0x0L, 0x0,4 },
    { 0x2094f0, 0x1df1L, 0x0,4 },
    { 0x2094f8, 0x10000000L, 0x0,4 },
    { 0x2094fc, 0x10000000L, 0x0,4 },
    { 0x209504, 0x1e00L, 0x0,4 },
    { 0x209508, 0x3L, 0x33,1 },
    { 0x20964c, 0x40305L, 0x70707,4 },
    { 0x209650, 0x50000L, 0x70007,4 },
    { 0x209654, 0x0L, 0x3,1 },
    { 0x209658, 0xfL, 0x19fdf0f,4 },
    { 0x20965c, 0x1000700L, 0xf0f1f03,4 },
    { 0x209660, 0xffffL, 0x0,2 },
    { 0x209664, 0x0L, 0x0,2 },
    { 0x209668, 0x780L, 0x0,2 },
    { 0x20966c, 0x0L, 0x0,2 },
    { 0x209670, 0x0L, 0x0,2 },
    { 0x209674, 0xffffL, 0x0,2 },
    { 0x209678, 0x1L, 0x0,2 },
    { 0x20967c, 0x438L, 0x0,2 },
    { 0x209680, 0x780L, 0x0,2 },
    { 0x209684, 0x438L, 0x0,2 },
    { 0x209688, 0x1L, 0x87,1 },
    { 0x20968c, 0x1L, 0x7,1 },
    { 0x209690, 0x0L, 0x1,1 },
    { 0x209694, 0x0L, 0x1,1 },
    { 0x2096a0, 0x26L, 0x0,4 },
    { 0x2096a4, 0x780L, 0x0,4 },
    { 0x2096a8, 0x8155L, 0x0,4 },
    { 0x2096ac, 0x12L, 0x0,4 },
    { 0x2096b0, 0x0L, 0x0,4 },
    { 0x2096b4, 0x439L, 0x0,4 },
    { 0x2096b8, 0x82e6L, 0x0,4 },
    { 0x2096bc, 0x20L, 0x0,4 },
    { 0x2096c0, 0x8L, 0x0,4 },
    { 0x209120, 0x0L, 0x1001f,4 },
    { 0x2096c4, 0xfa9dL, 0x0,4 },
    { 0x2096c8, 0x828cL, 0x0,4 },
    { 0x2096cc, 0xfL, 0x0,4 },
    { 0x2096d0, 0x284L, 0x0,4 },
    { 0x2096d4, 0xfe40L, 0x0,4 },
    { 0x2096d8, 0xf36eL, 0x0,4 },
    { 0x2096dc, 0x1L, 0x0,4 },
    { 0x2096e4, 0x0L, 0x7,1 },
    { 0x2096e8, 0x5L, 0x0,1 },
    { 0x2096ec, 0xffffL, 0x0,2 },
    { 0x2096f0, 0xffffL, 0x0,2 },
    { 0x2096f4, 0xffffL, 0x0,2 },
    { 0x2096f8, 0x8fffL, 0x0,2 },
    { 0x2096fc, 0x8fffL, 0x0,2 },
    { 0x209700, 0x8fffL, 0x0,2 },
    { 0x209704, 0x3caaL, 0x0,2 },
    { 0x209708, 0x0L, 0x0,2 },
    { 0x20970c, 0x1L, 0x3fff,2 },
    { 0x209710, 0x100L, 0x3fff,2 },
    { 0x209714, 0x1L, 0x3fff,2 },
    { 0x20971c, 0x100L, 0x3fff,2 },
    { 0x209720, 0x6L, 0xcf,1 },
    { 0x209724, 0x0L, 0xf,1 },
    { 0x209728, 0x780L, 0x0,2 },
    { 0x20972c, 0x438L, 0x0,2 },
    { 0x209730, 0x2000000L, 0x0,4 },
    { 0x209734, 0xfd2000L, 0x0,4 },
    { 0x209738, 0x1baf800L, 0x0,4 },
    { 0x20973c, 0x0L, 0x0,4 },
    { 0x209740, 0x0L, 0x0,4 },
    { 0x209744, 0x0L, 0xf,1 },
    { 0x209748, 0xf00L, 0x0,4 },
    { 0x20974c, 0x2L, 0x3,1 },
    { 0x209750, 0x0L, 0x3f,1 },
    { 0x209754, 0x0L, 0x7,1 },
    { 0x209758, 0x2000000L, 0x0,4 },
    { 0x20975c, 0x2000000L, 0x0,4 },
    { 0x209760, 0xf9b7L, 0x0,2 },
    { 0x209764, 0x2fd5L, 0x0,2 },
    { 0x209768, 0x0L, 0xf,1 },
    { 0x20976c, 0x0L, 0x0,1 },
    { 0x209770, 0x0L, 0x0,1 },
    { 0x209774, 0x0L, 0x0,1 },
    { 0x209778, 0x70L, 0x0,1 },
    { 0x20977c, 0x1L, 0x3,1 },
    { 0x209780, 0x0L, 0x0,4 },
    { 0x209784, 0x0L, 0x0,4 },
    { 0x209788, 0xfL, 0x19fdf0f,4 },
    { 0x20978c, 0x1000700L, 0xf0f1f03,4 },
    { 0x209790, 0xffffL, 0x0,2 },
    { 0x209794, 0x0L, 0x0,2 },
    { 0x209798, 0x780L, 0x0,2 },
    { 0x20979c, 0x0L, 0x0,2 },
    { 0x2097a0, 0x0L, 0x0,2 },
    { 0x2097a4, 0xffffL, 0x0,2 },
    { 0x2097a8, 0x0L, 0x0,2 },
    { 0x2097ac, 0x439L, 0x0,2 },
    { 0x2097b0, 0x780L, 0x0,2 },
    { 0x2097b4, 0x438L, 0x0,2 },
    { 0x2097b8, 0x1L, 0x87,1 },
    { 0x2097bc, 0x1L, 0x7,1 },
    { 0x2097c0, 0x0L, 0x1,1 },
    { 0x2097c4, 0x0L, 0x1,1 },
    { 0x2097d0, 0x26L, 0x0,4 },
    { 0x2097d4, 0x780L, 0x0,4 },
    { 0x2097d8, 0x815aL, 0x0,4 },
    { 0x2097dc, 0x12L, 0x0,4 },
    { 0x2097e0, 0x1L, 0x0,4 },
    { 0x2097e4, 0x439L, 0x0,4 },
    { 0x2097e8, 0x82e7L, 0x0,4 },
    { 0x2097ec, 0x20L, 0x0,4 },
    { 0x2097f0, 0x8L, 0x0,4 },
    { 0x2097f4, 0xfa9dL, 0x0,4 },
    { 0x2097f8, 0x828cL, 0x0,4 },
    { 0x2097fc, 0xfL, 0x0,4 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};


static acam_reg_t fs_lin_4exp[] = {
    { 0x18ed4, 0x1020200L, 0x3030303,4 },
    { 0x18eac, 0x0L, 0x30,1 },
    { 0x18f98, 0x10007L, 0x70007,4 },
    { 0x18e8c, 0x1000000L, 0x3000000,4 },
    { 0x18fe4, 0x3L, 0x3,1 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};


static acam_reg_t settings_context[] = {
    { 0x19000, 0xf000f0L, 0xfff0fff,4 },
    { 0x1ae7c, 0xb2b4b4c8L, 0x0,4 },
    { 0x1b28c, 0x0L, 0x0,2 },
    { 0x1abb0, 0x1L, 0x31,1 },
    { 0x19004, 0xf000L, 0xfffff,4 },
    { 0x1b104, 0x0L, 0xfff,2 },
    { 0x19008, 0x6000180L, 0xfff0fff,4 },
    { 0x192ac, 0xffffL, 0x0,2 },
    { 0x1bbac, 0x1L, 0x77,1 },
    { 0x1900c, 0xc000600L, 0xfff0fff,4 },
    { 0x19010, 0x1800180L, 0xfff0fff,4 },
    { 0x19358, 0x6eaL, 0x0,2 },
    { 0x19014, 0x1000100L, 0xfff0fff,4 },
    { 0x1b144, 0xfffL, 0xfff,2 },
    { 0x1b038, 0x5dcL, 0xfff,2 },
    { 0x19018, 0x100L, 0xfff,2 },
    { 0x1b004, 0x40L, 0xfff0fff,4 },
    { 0x1aeb0, 0x81d461cL, 0x0,4 },
    { 0x1901c, 0x80000L, 0xfffff,4 },
    { 0x1b0e8, 0x800L, 0xfff,2 },
    { 0x1b138, 0xfffL, 0xfff,2 },
    { 0x19020, 0x21400L, 0x3f3f3f,4 },
    { 0x192b0, 0x400L, 0x0,2 },
    { 0x19024, 0x2000040L, 0xfff0fff,4 },
    { 0x1b0f4, 0x333L, 0x0,2 },
    { 0x1b0d8, 0x0L, 0x0,2 },
    { 0x19028, 0x0L, 0x3fffff,4 },
    { 0x1935c, 0x0L, 0x0,4 },
    { 0x1902c, 0x0L, 0xfff00ff,4 },
    { 0x1c0f0, 0x4380780L, 0x0,4 },
    { 0x1b2cc, 0x0L, 0xfff,2 },
    { 0x1ac20, 0x100L, 0xfff,2 },
    { 0x19030, 0x0L, 0x3fffff,4 },
    { 0x1b008, 0x200L, 0xfff,2 },
    { 0x1b100, 0xfbd8L, 0x0,2 },
    { 0x19034, 0x0L, 0xfffff,4 },
    { 0x1b028, 0xc83L, 0xfff,2 },
    { 0x19038, 0x0L, 0xfff,2 },
    { 0x1abb4, 0x400040L, 0x7f007f,4 },
    { 0x1b2b0, 0x1ffL, 0xfff,2 },
    { 0x1903c, 0x0L, 0x3fffff,4 },
    { 0x1afe4, 0x10a5L, 0x1fff,2 },
    { 0x1c070, 0x0L, 0xfff0fff,4 },
    { 0x1b128, 0x0L, 0xfff,2 },
    { 0x19040, 0x0L, 0xfffff,4 },
    { 0x1ac60, 0x0L, 0xfffff,4 },
    { 0x19044, 0x0L, 0xfff0fff,4 },
    { 0x1b048, 0xfffL, 0xfff,2 },
    { 0x1c124, 0x0L, 0x1ff,2 },
    { 0x19048, 0x400100L, 0xff0fff,4 },
    { 0x1b00c, 0xf8L, 0xfff0fff,4 },
    { 0x1b0d4, 0x1L, 0x1,1 },
    { 0x1904c, 0x3L, 0x10107,4 },
    { 0x19050, 0xdac0dacL, 0xfff0fff,4 },
    { 0x1abb8, 0x10000040L, 0x1fff1fff,4 },
    { 0x19054, 0xdac0dacL, 0xfff0fff,4 },
    { 0x1c1e0, 0x100L, 0xfff,2 },
    { 0x1ac5c, 0x0L, 0x3,1 },
    { 0x19058, 0x8000800L, 0xfff0fff,4 },
    { 0x1b2d0, 0xfffL, 0xfff,2 },
    { 0x1b2a0, 0x3ffL, 0x3ff,2 },
    { 0x1905c, 0x200800L, 0xfff0fff,4 },
    { 0x1afcc, 0x300L, 0xfff,2 },
    { 0x1b118, 0xe7b4L, 0x0,2 },
    { 0x19060, 0x800040L, 0xfff0fff,4 },
    { 0x1b010, 0x7adL, 0xfff,2 },
    { 0x1ac64, 0x1000100L, 0xfff0fff,4 },
    { 0x1ac54, 0x100L, 0x3ffff,4 },
    { 0x1ac68, 0x1000100L, 0xfff0fff,4 },
    { 0x1abbc, 0x0L, 0x1,1 },
    { 0x1926c, 0x100L, 0x1fff,2 },
    { 0x1b148, 0xffffL, 0x0,2 },
    { 0x1ac3c, 0x700202L, 0x3ff0303,4 },
    { 0x19270, 0xf000L, 0xfffff,4 },
    { 0x19368, 0x1e02L, 0xff07,2 },
    { 0x1c08c, 0x6a40032L, 0xffff00ff,4 },
    { 0x19274, 0x0L, 0xfffff,4 },
    { 0x1aecc, 0x3330333L, 0x1fff1fff,4 },
    { 0x1ac4c, 0xb4dc0a01L, 0xffff0f01,4 },
    { 0x19278, 0x0L, 0xfffff,4 },
    { 0x1b014, 0x320L, 0xfff0fff,4 },
    { 0x1b290, 0x5L, 0x0,2 },
    { 0x1927c, 0x0L, 0xfffff,4 },
    { 0x1b108, 0xf0L, 0xfff,2 },
    { 0x19280, 0x0L, 0xfffff,4 },
    { 0x1abc0, 0x7d0L, 0x0,2 },
    { 0x1b160, 0x100L, 0xfff,2 },
    { 0x19284, 0xf000L, 0xfffff,4 },
    { 0x1ac44, 0xffff0000L, 0x0,4 },
    { 0x1ac24, 0x0L, 0xfffff,4 },
    { 0x18e88, 0x4380780L, 0x0,4 },
    { 0x1936c, 0x0L, 0x0,2 },
    { 0x18e8c, 0x0L, 0x3030303,4 },
    { 0x1b03c, 0x190L, 0xfff0fff,4 },
    { 0x19290, 0x0L, 0x0,2 },
    { 0x1b018, 0x960L, 0xfff,2 },
    { 0x1aeb4, 0x1f8bL, 0x1fff,2 },
    { 0x19294, 0xfc300aaL, 0xfff0fff,4 },
    { 0x1b2bc, 0xc4L, 0xfff,2 },
    { 0x1b13c, 0xffffL, 0x0,2 },
    { 0x19298, 0x8000L, 0xffffff,4 },
    { 0x1abc4, 0xf000L, 0xfffff,4 },
    { 0x1b280, 0xd0L, 0xfff,2 },
    { 0x1929c, 0xaa0040L, 0xffff00ff,4 },
    { 0x1b04c, 0x20L, 0xfff0fff,4 },
    { 0x192a0, 0x80011dL, 0xff0fff,4 },
    { 0x19370, 0x4000L, 0x0,2 },
    { 0x192a4, 0x0L, 0x0,4 },
    { 0x1c0f4, 0x5000000L, 0x0,4 },
    { 0x192a8, 0x0L, 0x0,2 },
    { 0x1aa1c, 0x1L, 0x3,1 },
    { 0x1c078, 0x1L, 0x1,1 },
    { 0x18eac, 0x30L, 0x3f,1 },
    { 0x1aec0, 0x808b2L, 0xffffff,4 },
    { 0x1b02c, 0x6eL, 0xfff0fff,4 },
    { 0x18eb0, 0x2L, 0x1f,1 },
    { 0x1abc8, 0xf000L, 0xfffff,4 },
    { 0x1b2b4, 0x40L, 0xfff,2 },
    { 0x192b4, 0x0L, 0x17f,2 },
    { 0x1afe8, 0x1016L, 0x1fff,2 },
    { 0x1b12c, 0xf0L, 0xfff,2 },
    { 0x18eb8, 0x0L, 0x7,1 },
    { 0x19374, 0x8000L, 0x0,2 },
    { 0x1b278, 0x10L, 0xfff,2 },
    { 0x1c074, 0x0L, 0xfff,2 },
    { 0x18ebc, 0x0L, 0x7f,1 },
    { 0x1afdc, 0x21c03c0L, 0x0,4 },
    { 0x1b0dc, 0x0L, 0x0,1 },
    { 0x1c128, 0x0L, 0x0,4 },
    { 0x18ec0, 0xc5L, 0x0,1 },
    { 0x1aa20, 0x2L, 0x1f,1 },
    { 0x18ec4, 0x0L, 0xf,1 },
    { 0x1b14c, 0x1010L, 0x3f3f,2 },
    { 0x18ec8, 0x2L, 0x1f,1 },
    { 0x1abcc, 0xf000L, 0xfffff,4 },
    { 0x1c1e8, 0x0L, 0xfff,2 },
    { 0x18ecc, 0x0L, 0x301,2 },
    { 0x1c1e4, 0x0L, 0xfff0fff,4 },
    { 0x1b01c, 0x100L, 0xfff0fff,4 },
    { 0x18ed0, 0x1000000L, 0x1010226,4 },
    { 0x19378, 0xc000L, 0x0,2 },
    { 0x1b2a4, 0x0L, 0x3ff,2 },
    { 0x18ed4, 0x3010200L, 0x3030303,4 },
    { 0x1b11c, 0x0L, 0xfff,2 },
    { 0x18ed8, 0x0L, 0x1,1 },
    { 0x1aa24, 0x2L, 0xff0f,2 },
    { 0x1b164, 0xed8L, 0x0,2 },
    { 0x18edc, 0x3L, 0x0,1 },
    { 0x1ac28, 0x1L, 0x1,1 },
    { 0x18ee0, 0xfffffL, 0xfffff,4 },
    { 0x1abd0, 0xf000L, 0xfffff,4 },
    { 0x18ee4, 0xfffffL, 0xfffff,4 },
    { 0x1b124, 0xe7b4L, 0x0,2 },
    { 0x18ee8, 0xfffffL, 0xfffff,4 },
    { 0x1937c, 0x40000000L, 0x0,4 },
    { 0x1c090, 0x1180118L, 0x3fff3fff,4 },
    { 0x18eec, 0x8ffffL, 0xfffff,4 },
    { 0x1ac6c, 0x0L, 0x1,1 },
    { 0x18ef0, 0x8ffffL, 0xfffff,4 },
    { 0x1aa28, 0x7800L, 0xff07,2 },
    { 0x1b294, 0xfffaL, 0x0,2 },
    { 0x18ef4, 0x8ffffL, 0xfffff,4 },
    { 0x1b050, 0x0L, 0xfff,2 },
    { 0x1b0d0, 0x1L, 0x1,1 },
    { 0x18ef8, 0x0L, 0x0,2 },
    { 0x1aed4, 0x4000L, 0xfffff,4 },
    { 0x18efc, 0xfffffL, 0xfffff,4 },
    { 0x1b2c4, 0x2121L, 0x0,2 },
    { 0x1c100, 0x0L, 0x0,4 },
    { 0x1ae80, 0x5dL, 0x0,1 },
    { 0x1ac58, 0x1000L, 0x3ffff,4 },
    { 0x1b158, 0xed8L, 0x0,2 },
    { 0x1c144, 0x0L, 0x21f,2 },
    { 0x1ac30, 0x0L, 0xfffff,4 },
    { 0x18f08, 0x0L, 0x1,1 },
    { 0x1aa2c, 0x0L, 0x0,2 },
    { 0x1c080, 0xa004cL, 0xff00ff,4 },
    { 0x1aeb8, 0x1fa4L, 0x1fff,2 },
    { 0x18f0c, 0x3L, 0x0,1 },
    { 0x1c104, 0x0L, 0x0,4 },
    { 0x18f10, 0xfffffL, 0xfffff,4 },
    { 0x1aed8, 0xfa00000L, 0xfff0000,4 },
    { 0x1b27c, 0x20L, 0xfff,2 },
    { 0x18f14, 0xfffffL, 0xfffff,4 },
    { 0x1b0fc, 0x258L, 0xfff,2 },
    { 0x18f18, 0xfffffL, 0xfffff,4 },
    { 0x1ae84, 0x140064L, 0xfff0fff,4 },
    { 0x18f1c, 0x8ffffL, 0xfffff,4 },
    { 0x1c0f8, 0x0L, 0x0,4 },
    { 0x18f20, 0x8ffffL, 0xfffff,4 },
    { 0x1aa30, 0x0L, 0x0,2 },
    { 0x1c1ec, 0x1L, 0x1,1 },
    { 0x18f24, 0x8ffffL, 0xfffff,4 },
    { 0x1b030, 0xcdL, 0xfff,2 },
    { 0x18f28, 0x0L, 0x0,2 },
    { 0x1aedc, 0x4000L, 0xfffff,4 },
    { 0x1b2b8, 0xc7L, 0xfff,2 },
    { 0x18f2c, 0xfffffL, 0xfffff,4 },
    { 0x1afec, 0x101fL, 0x1fff,2 },
    { 0x1c260, 0x0L, 0x21f,2 },
    { 0x1b130, 0xe7b4L, 0x0,2 },
    { 0x1afc8, 0x1L, 0x1,1 },
    { 0x19288, 0x7d0L, 0x0,2 },
    { 0x1b134, 0x0L, 0xfff,2 },
    { 0x1b0ec, 0x800L, 0xfff,2 },
    { 0x1c064, 0x1L, 0x1,1 },
    { 0x1ac2c, 0x40807fL, 0xffffff,4 },
    { 0x18f38, 0x0L, 0x1,1 },
    { 0x1aa34, 0x0L, 0x0,2 },
    { 0x1b10c, 0xe7b4L, 0x0,2 },
    { 0x18f3c, 0x3L, 0x0,1 },
    { 0x18f40, 0xfffffL, 0xfffff,4 },
    { 0x1aee0, 0x4eL, 0xff0fff,4 },
    { 0x18f44, 0xfffffL, 0xfffff,4 },
    { 0x1aec4, 0xf0L, 0xfff0fff,4 },
    { 0x1b020, 0x2d0L, 0xfff,2 },
    { 0x18f48, 0xfffffL, 0xfffff,4 },
    { 0x1928c, 0x5L, 0xcd,1 },
    { 0x1b2a8, 0x1ffL, 0xfff,2 },
    { 0x18f4c, 0x8ffffL, 0xfffff,4 },
    { 0x1b054, 0x0L, 0x0,1 },
    { 0x1b120, 0xf0L, 0xfff,2 },
    { 0x18f50, 0x8ffffL, 0xfffff,4 },
    { 0x1aa38, 0x0L, 0x0,2 },
    { 0x18f54, 0x8ffffL, 0xfffff,4 },
    { 0x1c11c, 0xde78adf4L, 0x0,4 },
    { 0x18f58, 0x0L, 0x0,2 },
    { 0x1aee4, 0x4000L, 0xfffff,4 },
    { 0x18f5c, 0xfffffL, 0xfffff,4 },
    { 0x1b2d4, 0x0L, 0xfff,2 },
    { 0x1b730, 0x1L, 0x77,1 },
    { 0x19360, 0x0L, 0x0,4 },
    { 0x1ae90, 0x8000800L, 0xfff0fff,4 },
    { 0x1c094, 0x0L, 0xf,1 },
    { 0x19364, 0xffffffffL, 0x0,4 },
    { 0x1c1d8, 0x1L, 0x1,1 },
    { 0x1c108, 0x0L, 0xf,1 },
    { 0x18f68, 0x0L, 0x1,1 },
    { 0x1aa3c, 0x40L, 0x0,4 },
    { 0x1ae88, 0xf00064L, 0xfff0fff,4 },
    { 0x18f6c, 0x3L, 0x0,1 },
    { 0x1b298, 0x2121L, 0x0,2 },
    { 0x1ac50, 0x400L, 0x0,2 },
    { 0x18f70, 0xfffffL, 0xfffff,4 },
    { 0x1aee8, 0xfa0L, 0xfff,2 },
    { 0x18f74, 0xfffffL, 0xfffff,4 },
    { 0x1b154, 0x100L, 0xfff,2 },
    { 0x1c10c, 0x1e00L, 0x0,4 },
    { 0x18f78, 0xfffffL, 0xfffff,4 },
    { 0x1ae94, 0x800L, 0xfff0fff,4 },
    { 0x1b0f8, 0x0L, 0xfff,2 },
    { 0x18f7c, 0x8ffffL, 0xfffff,4 },
    { 0x1ac48, 0xffff0000L, 0x0,4 },
    { 0x1ac34, 0xd9999L, 0xfffff,4 },
    { 0x18f80, 0x8ffffL, 0xfffff,4 },
    { 0x1b040, 0xd48L, 0xfff,2 },
    { 0x1c084, 0x12cL, 0xff03ff,4 },
    { 0x1aebc, 0x1L, 0x1,1 },
    { 0x18f84, 0x8ffffL, 0xfffff,4 },
    { 0x1b000, 0x171L, 0x1fff,2 },
    { 0x18f88, 0x0L, 0x0,2 },
    { 0x1aeec, 0x4000L, 0xfffff,4 },
    { 0x1b288, 0x0L, 0x0,2 },
    { 0x18f8c, 0xfffffL, 0xfffff,4 },
    { 0x1afd4, 0x200fffL, 0xff0fff,4 },
    { 0x1ac40, 0x200L, 0x3ff,2 },
    { 0x1ae98, 0x0L, 0xfff0fff,4 },
    { 0x1b110, 0x0L, 0xfff,2 },
    { 0x1c0fc, 0x0L, 0x0,4 },
    { 0x1b2c8, 0xfffL, 0xfff,2 },
    { 0x18f98, 0x20000L, 0x70007,4 },
    { 0x1b044, 0x5dcL, 0xfff0fff,4 },
    { 0x18f9c, 0x0L, 0x3ffff,4 },
    { 0x1b034, 0x46L, 0xfff0fff,4 },
    { 0x18fa0, 0x0L, 0x1fff,2 },
    { 0x1aff0, 0x159L, 0x1fff,2 },
    { 0x1aeac, 0x0L, 0x0,1 },
    { 0x18fa4, 0x0L, 0xfff,2 },
    { 0x18fa8, 0x0L, 0x0,4 },
    { 0x1ae9c, 0x11d1cL, 0xffffff,4 },
    { 0x1c2b8, 0x0L, 0x21f,2 },
    { 0x18fac, 0x0L, 0x0,2 },
    { 0x1b0f0, 0xcccL, 0xfff,2 },
    { 0x18fb0, 0x0L, 0xf0f0f0f,4 },
    { 0x19348, 0x5cL, 0x0,1 },
    { 0x1b15c, 0x0L, 0xfff,2 },
    { 0x1b140, 0x0L, 0xfff,2 },
    { 0x18fb4, 0x0L, 0xfff0fff,4 },
    { 0x1c0ec, 0x202L, 0xbdf,2 },
    { 0x18fb8, 0x0L, 0xfff0fff,4 },
    { 0x1aff4, 0x103aL, 0x1fff,2 },
    { 0x18fbc, 0x0L, 0xfff0fff,4 },
    { 0x1c1dc, 0x1000100L, 0xfff0fff,4 },
    { 0x1b024, 0xfff01f4L, 0xfff0fff,4 },
    { 0x18fc0, 0x0L, 0xfff0fff,4 },
    { 0x1aea0, 0x0L, 0x0,1 },
    { 0x1b2ac, 0x40L, 0xfff,2 },
    { 0x18fc4, 0x0L, 0xfff0fff,4 },
    { 0x1afe0, 0x1bbL, 0x1fff,2 },
    { 0x1b0e4, 0x3fL, 0x7f,1 },
    { 0x1b284, 0xe0L, 0xfff,2 },
    { 0x18fc8, 0x0L, 0xfff0fff,4 },
    { 0x1934c, 0x3aL, 0x3f,1 },
    { 0x1c068, 0x1000100L, 0xfff0fff,4 },
    { 0x1b764, 0x2121L, 0x0,2 },
    { 0x18fcc, 0x0L, 0xfff0fff,4 },
    { 0x1b0e0, 0x96L, 0xfff,2 },
    { 0x18fd0, 0x0L, 0xfff0fff,4 },
    { 0x1aff8, 0x15L, 0x1fff,2 },
    { 0x1abd4, 0xf000L, 0xfffff,4 },
    { 0x1b29c, 0x0L, 0x1,1 },
    { 0x1afd8, 0xe95L, 0x0,2 },
    { 0x1aea4, 0xcf01b3L, 0xff0fff,4 },
    { 0x1aed0, 0x8L, 0xff0fff,4 },
    { 0x1aec8, 0x157c8000L, 0x0,4 },
    { 0x1afd0, 0x40000c8L, 0xfff0fff,4 },
    { 0x19350, 0x8L, 0x0,1 },
    { 0x1ae8c, 0x960171L, 0xfff0fff,4 },
    { 0x18fe4, 0x2L, 0xff03,2 },
    { 0x1c06c, 0x100L, 0xfff,2 },
    { 0x18fe8, 0x1000100L, 0xfff0fff,4 },
    { 0x1affc, 0x1086L, 0x1fff,2 },
    { 0x1b150, 0x0L, 0xfff,2 },
    { 0x1b114, 0xf0L, 0xfff,2 },
    { 0x18fec, 0x100L, 0xfff,2 },
    { 0x1c110, 0x1L, 0xf,1 },
    { 0x18ff0, 0xc000f00L, 0xfff0fff,4 },
    { 0x1aea8, 0x5596L, 0xffffff,4 },
    { 0x18ff4, 0xc000f00L, 0xfff0fff,4 },
    { 0x1ac38, 0x100L, 0xfff,2 },
    { 0x18ff8, 0xc000f00L, 0xfff0fff,4 },
    { 0x19354, 0x21c03c0L, 0x0,4 },
    { 0x1c088, 0x3e803e8L, 0x3ffffff,4 },
    { 0x18ffc, 0xf000f0L, 0xfff0fff,4 },
    { 0x1b2c0, 0x1b29acL, 0x0,4 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};


static acam_reg_t fpga_linear[] = {
    { 0x209650, 0x50000L, 0x70007,4 },
    { 0x209654, 0x0L, 0x3,1 },
    { 0x209398, 0x1L, 0x3,1 },
    { 0x20964c, 0x30303L, 0x70707,4 },
    //stop sequence - address is 0x0000
    { 0x0000, 0x0000, 0x0000, 0x0000 }
};

static const acam_reg_t *seq_table[] = {
    linear,
    settings,
    fpga_fs_lin,
    fs_lin_2exp,
    fs_lin_3exp,
    settings_fpga,
    fs_lin_4exp,
    settings_context,
    fpga_linear
};

#define SENSOR_ISP_SEQUENCE_DEFAULT seq_table

#define SENSOR_ISP_SEQUENCE_DEFAULT_LINEAR    0
#define SENSOR_ISP_SEQUENCE_DEFAULT_SETTINGS    1
#define SENSOR_ISP_SEQUENCE_DEFAULT_FPGA_FS_LIN    2
#define SENSOR_ISP_SEQUENCE_DEFAULT_FS_LIN_2EXP    3
#define SENSOR_ISP_SEQUENCE_DEFAULT_FS_LIN_3EXP    4
#define SENSOR_ISP_SEQUENCE_DEFAULT_SETTINGS_FPGA    5
#define SENSOR_ISP_SEQUENCE_DEFAULT_FS_LIN_4EXP    6
#define SENSOR_ISP_SEQUENCE_DEFAULT_SETTINGS_CONTEXT    7
#define SENSOR_ISP_SEQUENCE_DEFAULT_FPGA_LINEAR    8
#endif /* __ISP_SENSOR_H__ */
