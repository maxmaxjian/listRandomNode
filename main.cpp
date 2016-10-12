#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

struct ListNode {
  int val;
  std::shared_ptr<ListNode> next;
  ListNode(int x) : val(x), next(nullptr){}
};

using pNode = std::shared_ptr<ListNode>;

class solution {
public:
  solution(const pNode & head) : list(head) {
    std::srand(std::time(NULL));
  }

  int getRandom() {
    // std::cout << "len = " << getLength() << std::endl;
    int idx = int(rand()%getLength());
    pNode curr = list;
    while (idx-- > 0)
      curr = curr->next;
    return curr->val;
  }

private:
  int getLength() {
    int len = 0;
    pNode curr = list;
    while (curr != nullptr) {
      curr = curr->next;
      len++;
    }
    return len;
  }

private:
  pNode list;
};

int main() {
  pNode head = std::make_shared<ListNode>(1);
  head->next = std::make_shared<ListNode>(2);
  head->next->next = std::make_shared<ListNode>(3);

  solution soln(head);
  std::cout << soln.getRandom() << std::endl;
}
