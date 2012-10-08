/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "filters.h"

void JNIFUNCF(ImageFilterGeometry, nativeApplyFilterFlip, jobject src, jint srcWidth, jint srcHeight, jobject dst, jint dstWidth, jint dstHeight, jint flip) {
    char* destination = 0;
    char* source = 0;
    int len = dstWidth * dstHeight * 4;
    if (srcWidth != dstWidth || srcHeight != dstHeight) {
        return;
    }
    AndroidBitmap_lockPixels(env, src, (void**) &source);
    AndroidBitmap_lockPixels(env, dst, (void**) &destination);
    int i = 0;
    for (; i < len; i += 4) {
        int r = source[RED];
        int g = source[GREEN];
        int b = source[BLUE];
        // TODO: implement flip
        destination[RED] = 255;
        destination[GREEN] = g;
        destination[BLUE] = b;
    }
    AndroidBitmap_unlockPixels(env, dst);
    AndroidBitmap_unlockPixels(env, src);
}

void JNIFUNCF(ImageFilterGeometry, nativeApplyFilterRotate, jobject src, jint srcWidth, jint srcHeight, jobject dst, jint dstWidth, jint dstHeight, jfloat rotate) {
    char* destination = 0;
    char* source = 0;
    int len = dstWidth * dstHeight * 4;
    AndroidBitmap_lockPixels(env, src, (void**) &source);
    AndroidBitmap_lockPixels(env, dst, (void**) &destination);
    // TODO: implement rotate
    int i = 0;
    for (; i < len; i += 4) {
        int r = source[RED];
        int g = source[GREEN];
        int b = source[BLUE];
        destination[RED] = r;
        destination[GREEN] = 255;
        destination[BLUE] = b;
    }
    AndroidBitmap_unlockPixels(env, dst);
    AndroidBitmap_unlockPixels(env, src);
}

void JNIFUNCF(ImageFilterGeometry, nativeApplyFilterCrop, jobject src, jint srcWidth, jint srcHeight, jobject dst, jint dstWidth, jint dstHeight, jint offsetWidth, jint offsetHeight) {
    char* destination = 0;
    char* source = 0;
    int len = dstWidth * dstHeight * 4;
    AndroidBitmap_lockPixels(env, src, (void**) &source);
    AndroidBitmap_lockPixels(env, dst, (void**) &destination);
    // TODO: implement crop
    int i = 0;
    for (; i < len; i += 4) {
        int r = source[RED];
        int g = source[GREEN];
        int b = source[BLUE];
        destination[RED] = r;
        destination[GREEN] = g;
        destination[BLUE] = 255;
    }
    AndroidBitmap_unlockPixels(env, dst);
    AndroidBitmap_unlockPixels(env, src);
}

void JNIFUNCF(ImageFilterGeometry, nativeApplyFilterStraighten, jobject src, jint srcWidth, jint srcHeight, jobject dst, jint dstWidth, jint dstHeight, jfloat straightenAngle) {
    char* destination = 0;
    char* source = 0;
    int len = dstWidth * dstHeight * 4;
    AndroidBitmap_lockPixels(env, src, (void**) &source);
    AndroidBitmap_lockPixels(env, dst, (void**) &destination);
    // TODO: implement straighten
    int i = 0;
    for (; i < len; i += 4) {
        int r = source[RED];
        int g = source[GREEN];
        int b = source[BLUE];
        destination[RED] = 128;
        destination[GREEN] = g;
        destination[BLUE] = 128;
    }
    AndroidBitmap_unlockPixels(env, dst);
    AndroidBitmap_unlockPixels(env, src);
}
