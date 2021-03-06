/**
 * Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMETSUCHI_STATUS_H
#define AMETSUCHI_STATUS_H

#include <ametsuchi/file/file.h>
#include <iomanip>
#include <sstream>
#include <string>

namespace ametsuchi {
/**
 * This function is used to dump any object into string. Consider it as
 * implementation if toString() method.
 * @tparam T
 * @param obj
 * @return string
 */
template <typename T>
static std::string dump(const T& obj) {
  return nullptr;
}

/**
 * Dump ByteArray into hex string. Efficiency of this function does not matter.
 * @param blob
 * @return
 */
template <>
std::string dump<ByteArray>(const ByteArray& blob) {
  std::stringstream ret;
  ret << std::hex;
  for (auto&& b : blob) {
    ret << std::setw(2) << std::setfill('0') << static_cast<int>(b);
  }
  return ret.str();
}
}

#endif  // AMETSUCHI_STATUS_H
