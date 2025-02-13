#include "queue.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using ::testing::_;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::Return;

class MockMemory : public IMemory {
  std::vector<void *> vect;
  uint8_t temp_mem[2048];

public:
  MOCK_METHOD(void *, malloc, (size_t _size), (override));
  MOCK_METHOD(void, free, (void *_ptr), (override));

  void *allocate(size_t _size) {
    static size_t pos{0};
    void *ptr{nullptr};

    if (pos >= sizeof(temp_mem)) {
      throw std::out_of_range("Overflow.");
    } else {
      void *ptr{&temp_mem[pos]};
      vect.push_back(ptr);
      pos += _size;
    }

    return ptr;
    // void *ptr{std::malloc(_size)};
    // if (ptr != nullptr) {
    //   vect.push_back(ptr);
    // }
  }
  void release(void *ptr) {
    vect.erase(std::remove(vect.begin(), vect.end(), ptr));

    // auto it {std::find(vect.begin(), vect.end(), ptr)};
    // if (it != vect.end()) {
    //   vect.erase(it, ++it);
    // }
  }

  ~MockMemory() { EXPECT_EQ(0, vect.size()); }
};

template <typename T> class QueueFixture : public ::testing::Test {
  std::tuple<std::vector<int>, std::vector<float>, std::vector<std::string>>
      allValues{{1, 2, 3, 4, 5},
                {1.1f, 2.2f, 3.3f, 4.4f, 5.5f},
                {"One", "two", "THREE", "4", "fivE_"}};

protected:
  const std::vector<T> values{std::get<std::vector<T>>(allValues)};

  void SetUp(void) override {}

  void TearDown(void) override {}
};

using Types = ::testing::Types<int, float, std::string>;
TYPED_TEST_SUITE(QueueFixture, Types);

TYPED_TEST(QueueFixture, EMPTY) {}
