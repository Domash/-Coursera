#include <algorithm>
#include <string>
#include <vector>
#include <set>

class Learner {
 private:
  std::set<std::string> dict;

 public:
  int Learn(const std::vector<std::string>& words) {
    int newWords = 0;
    for (const auto& word : words) {
      if(dict.find(word) == dict.end()) {
        newWords++;
        dict.insert(word);
      }
    }
    return newWords;
  }

  std::vector<std::string> KnownWords() {
    std::vector<std::string> all(dict.begin(), dict.end());
    return all;
  }
};

int main() {

}

