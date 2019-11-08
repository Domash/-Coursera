#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>

template <typename Iterator>
class IteratorRange {
public:
  IteratorRange(Iterator first, Iterator second) {
    this -> first = first;
    this -> second = second; 
  } 

  Iterator begin() const {
    return first;
  }

  Iterator end() const {
    return second;
  }

  std::size_t size() {
    return std::distance(first, second);
  } 

  std::size_t size() const {
    return std::distance(first, second);
  }

private:
  Iterator first;
  Iterator second;

};

template <typename Iterator>
class Paginator {
public:

  Paginator(Iterator begin, Iterator end, std::size_t page_size) 
    : begin_(begin), end_(end), page_size_(page_size) {

      std::size_t all = std::distance(begin, end);
      std::size_t residue = all - (all / page_size) * page_size;

      pages_number_ = all / page_size;

      auto it = begin;
      for(std::size_t i = 0; i < all / page_size; ++i) {
        IteratorRange<Iterator> range(it, it + page_size);
        data.emplace_back(range);
        it += page_size;
      }

      if(residue) {
        pages_number_++;
        IteratorRange<Iterator> range(it, end);
        data.emplace_back(range);
      }

    }

  auto begin() const {
    return data.begin();
  }

  auto end() const {
    return data.end();
  }

  std::size_t size() {
    return pages_number_;
  }

  std::size_t size() const {
    return pages_number_;
  }

private:

  Iterator begin_;
  Iterator end_;
  std::size_t page_size_;
  std::size_t pages_number_;
  std::vector<IteratorRange<Iterator>> data;

};

template <typename C>
auto Paginate(C& c, std::size_t page_size) {
  return Paginator {c.begin(), c.end(), page_size};
}

// void TestLooping() {
//   vector<int> v(15);
//   iota(begin(v), end(v), 1);

//   Paginator<vector<int>::iterator> paginate_v(v.begin(), v.end(), 6);
//   ostringstream os;
//   for (const auto& page : paginate_v) {
//     for (int x : page) {
//       os << x << ' ';
//     }
//     os << '\n';
//   }

//   ASSERT_EQUAL(os.str(), "1 2 3 4 5 6 \n7 8 9 10 11 12 \n13 14 15 \n");
// }

// void TestModification() {
//   vector<string> vs = {"one", "two", "three", "four", "five"};
//   for (auto page : Paginate(vs, 2)) {
//     for (auto& word : page) {
//       word[0] = toupper(word[0]);
//     }
//   }

//   const vector<string> expected = {"One", "Two", "Three", "Four", "Five"};
//   ASSERT_EQUAL(vs, expected);
// }

// void TestPageSizes() {
//   string letters(26, ' ');

//   Paginator letters_pagination(letters.begin(), letters.end(), 11);
//   vector<size_t> page_sizes;
//   for (const auto& page : letters_pagination) {
//     page_sizes.push_back(page.size());
//   }

//   const vector<size_t> expected = {11, 11, 4};
//   ASSERT_EQUAL(page_sizes, expected);
// }

// void TestConstContainer() {
//   const string letters = "abcdefghijklmnopqrstuvwxyz";

//   vector<string> pages;
//   for (const auto& page : Paginate(letters, 10)) {
//     pages.push_back(string(page.begin(), page.end()));
//   }

//   const vector<string> expected = {"abcdefghij", "klmnopqrst", "uvwxyz"};
//   ASSERT_EQUAL(pages, expected);
// }

// void TestPagePagination() {
//   vector<int> v(22);
//   iota(begin(v), end(v), 1);

//   vector<vector<int>> lines;
//   for (const auto& split_by_9 : Paginate(v, 9)) {
//     for (const auto& split_by_4 : Paginate(split_by_9, 4)) {
//       lines.push_back({});
//       for (int item : split_by_4) {
//         lines.back().push_back(item);
//       }
//     }
//   }

//   const vector<vector<int>> expected = {
//       {1, 2, 3, 4},
//       {5, 6, 7, 8},
//       {9},
//       {10, 11, 12, 13},
//       {14, 15, 16, 17},
//       {18},
//       {19, 20, 21, 22}
//   };
//   ASSERT_EQUAL(lines, expected);
// }

int main() {

}