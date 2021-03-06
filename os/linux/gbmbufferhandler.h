/*
// Copyright (c) 2016 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#ifndef OS_LINUX_GBMBUFFERHANDLER_H_
#define OS_LINUX_GBMBUFFERHANDLER_H_

#include <gbm.h>

#include <nativebufferhandler.h>

namespace hwcomposer {

class GpuDevice;

class GbmBufferHandler : public NativeBufferHandler {
 public:
  explicit GbmBufferHandler(uint32_t fd);
  ~GbmBufferHandler() override;

  bool Init();

  bool CreateBuffer(uint32_t w, uint32_t h, int format,
                    HWCNativeHandle *handle) override;
  bool DestroyBuffer(HWCNativeHandle handle) override;
  bool ImportBuffer(HWCNativeHandle handle, HwcBuffer *bo) override;

 private:
  uint32_t fd_;
  struct gbm_device *device_;
};

}  // namespace hardware
#endif  // OS_LINUX_GBMBUFFERHANDLER_H_
