#include "test_runner.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Editor {
 public:

  Editor() {
    it = text.begin();
  }
  
  void Left() {
    if(it != text.begin()) {
      it--;
    }
  }
  
  void Right() {
    if(it != text.end()) {
      it++;
    }
  }

  void Insert(char token) {
    it = next(text.emplace(it, token));
  }

  void Cut(size_t tokens = 1) {
    for(size_t i = 0; i < tokens; ++i) {
      if(it == text.end()) break;
      copyBuffer.push_back(*it);
      it = (text.erase(it));
    }
  }

  void Copy(size_t tokens = 1) {
    for(size_t i = 0; i < tokens; ++i) {
      if(it == text.end()) break;
      copyBuffer.push_back(*it);
      it++;
    }

  } 
  
  void Paste() {
    for(const auto& it : copyBuffer) {
      Insert(it);
    }
  }

  std::string GetText() const {
    return std::string(text.begin(), text.end());
  }

private:
  
  std::list<char> text;
  std::list<char> copyBuffer;

  std::list<char>::iterator it;

};

void TypeText(Editor& editor, const std::string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    
    //cout << editor.GetText() << endl;

    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {



  TestRunner tr;
   RUN_TEST(tr, TestEditing);
   RUN_TEST(tr, TestReverse);
   RUN_TEST(tr, TestNoText);
   RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}