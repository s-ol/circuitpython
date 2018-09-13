/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_GROUP_H
#define MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_GROUP_H

#include <stdbool.h>
#include <stdint.h>

#include "py/obj.h"

typedef struct {
    mp_obj_base_t base;
    int16_t x;
    int16_t y;
    uint16_t size;
    uint16_t max_size;
    mp_obj_t* children;
    bool needs_refresh;
} displayio_group_t;


void common_hal_displayio_group_construct(displayio_group_t* self, uint32_t max_size);
void common_hal_displayio_group_append(displayio_group_t* self, mp_obj_t layer);

void displayio_group_construct(displayio_group_t* self, mp_obj_t* child_array, uint32_t max_size);
bool displayio_group_get_pixel(displayio_group_t *group, int16_t x, int16_t y, uint16_t *pixel);
bool displayio_group_needs_refresh(displayio_group_t *self);
void displayio_group_finish_refresh(displayio_group_t *self);

#endif // MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_GROUP_H
