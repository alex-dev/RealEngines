#pragma once

namespace base {
  struct not_constructible {
    not_constructible() = delete;
    not_constructible(not_constructible const&) = delete;
    not_constructible(not_constructible&&) = delete;
    ~not_constructible() = delete;
    not_constructible& operator=(not_constructible const&) = delete;
  };
}
