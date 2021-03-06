/*
 * Copyright (c) 2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#include <stdio.h>  // fprintf(), NULL
#include <stdlib.h> // exit(), EXIT_SUCCESS

#include "test.h" // PASS(), FAIL(), XPASS(), XFAIL()

#include <stdlib.h>
#include <new>

//
// This test case verifies that calling operator new[] in libstdc++.dylib
// will turn around and call operator new in this main exectuable
//

static void* ptr;

void* operator new(size_t s) throw (std::bad_alloc)
{
  ptr = malloc(s);
  return ptr;
}


int main()
{
	char* stuff = new char[24];
	if ( (void*)stuff == ptr )
		PASS("operator-new");
	else
		FAIL("operator-new");
	return EXIT_SUCCESS;
}

