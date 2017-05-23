/*
 * Copyright 2017, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   libharu_test.cpp
 * Author: alex
 *
 * Created on May 16, 2017, 9:20 PM
 */

#include "hpdf.h"

#include <iostream>

#include "staticlib/config/assert.hpp"

void test_write() {
    HPDF_Doc pdf = HPDF_New([](HPDF_STATUS error_no, HPDF_STATUS detail_no, void*) {
        std::cout << "hpdf error: no: [" << std::hex << error_no << "], detail: [" << detail_no << "]" << std::endl;
    }, nullptr);
    slassert(pdf);
    HPDF_UseUTFEncodings(pdf);
    HPDF_SetCompressionMode(pdf, HPDF_COMP_ALL);
    HPDF_SetPageMode(pdf, HPDF_PAGE_MODE_USE_OUTLINE);
    HPDF_Page page = HPDF_AddPage(pdf);

    auto font_name = HPDF_LoadTTFontFromFile(pdf, "../test/DejaVuSans.ttf", HPDF_TRUE);
    HPDF_Font font = HPDF_GetFont(pdf, font_name, "UTF-8");
    HPDF_Page_SetFontAndSize(page, font, 42);
    
    HPDF_Page_BeginText(page);
    HPDF_Page_TextOut(page, 50, 50, "\xd0\xbf\xd1\x80\xd0\xb8\xd0\xb2\xd0\xb5\xd1\x82 pdf!");
    HPDF_Page_EndText(page);
    
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_B5, HPDF_PAGE_LANDSCAPE);
    HPDF_SaveToFile(pdf, "test.pdf");
    HPDF_Free(pdf);
}

int main() {
    try {
        test_write();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
