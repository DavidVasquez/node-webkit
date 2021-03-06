// Copyright (c) 2012 Intel Corp
// Copyright (c) 2012 The Chromium Authors
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy 
// of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell co
// pies of the Software, and to permit persons to whom the Software is furnished
//  to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in al
// l copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IM
// PLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNES
// S FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
//  OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WH
// ETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

// Multiply-included file, no traditional include guard.
#include <string>

#include "base/values.h"
#include "chrome/common/extensions/draggable_region.h"
#include "content/public/common/common_param_traits.h"
#include "ipc/ipc_message_macros.h"

#define IPC_MESSAGE_START ShellMsgStart

IPC_STRUCT_TRAITS_BEGIN(extensions::DraggableRegion)
  IPC_STRUCT_TRAITS_MEMBER(draggable)
  IPC_STRUCT_TRAITS_MEMBER(bounds)
IPC_STRUCT_TRAITS_END()

IPC_MESSAGE_ROUTED3(ShellViewHostMsg_Allocate_Object,
                    int /* object id */,
                    std::string /* type name */,
                    DictionaryValue /* option */)

IPC_MESSAGE_ROUTED1(ShellViewHostMsg_Deallocate_Object,
                    int /* object id */)

IPC_MESSAGE_ROUTED4(ShellViewHostMsg_Call_Object_Method,
                    int /* object id */,
                    std::string /* type name */,
                    std::string /* method name */,
                    ListValue /* arguments */)

IPC_SYNC_MESSAGE_ROUTED4_1(ShellViewHostMsg_Call_Object_Method_Sync,
                           int /* object id */,
                           std::string /* type name */,
                           std::string /* method name */,
                           ListValue /* arguments */,
                           ListValue /* result */)

IPC_MESSAGE_ROUTED3(ShellViewHostMsg_Call_Static_Method,
                    std::string /* type name */,
                    std::string /* method name */,
                    ListValue /* arguments */)

IPC_SYNC_MESSAGE_ROUTED3_1(ShellViewHostMsg_Call_Static_Method_Sync,
                           std::string /* type name */,
                           std::string /* method name */,
                           ListValue /* arguments */,
                           ListValue /* result */)

IPC_MESSAGE_ROUTED3(ShellViewMsg_Object_On_Event,
                    int /* object id */,
                    std::string /* event name */,
                    ListValue /* arguments */)

// Tell browser we have an uncaughtException from node.
IPC_MESSAGE_ROUTED1(ShellViewHostMsg_UncaughtException,
                    std::string /* err */)

// Sent by the renderer when the draggable regions are updated.
IPC_MESSAGE_ROUTED1(ShellViewHostMsg_UpdateDraggableRegions,
                    std::vector<extensions::DraggableRegion> /* regions */)

// The browser want to open a file.
IPC_MESSAGE_CONTROL1(ShellViewMsg_Open,
                     std::string /* file name */)
