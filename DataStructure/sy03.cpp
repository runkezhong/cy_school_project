#include <iostream>
#include <vector>
#include <stdexcept>

class Stack {
private:
    std::vector<int> data;
public:
    Stack() {}

    void push(int value) {
        data.push_back(value);
    }

    // pop操作
    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty. Cannot pop.");
        }
        int topValue = data.back();
        data.pop_back();
        return topValue;
    }

    // 查看栈顶元素
    int top() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty. Cannot retrieve top element.");
        }
        return data.back();
    }

    bool isEmpty() {
        return data.empty();
    }

    void printStack() {
        std::cout << "Stack: ";
        for (int i = data.size() - 1; i >= 0; --i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
   Stack stack;
 
   // 初始化栈
   std::cout << "Initializing stack..." << std::endl;
   stack.printStack(); // 应该显示空栈
 
   // 插入元素
   std::cout << "Pushing elements onto the stack..." << std::endl;
   stack.push(10);
   stack.push(20);
   stack.push(30);
   stack.printStack(); // 应该显示 30 20 10
 
   // 删除元素
   std::cout << "Popping elements from the stack..." << std::endl;
   try {
       std::cout << "Popped: " << stack.pop() << std::endl;
       std::cout << "Popped: " << stack.pop() << std::endl;
       stack.printStack(); // 应该显示 10
   } catch (const std::out_of_range& e) {
       std::cerr << "Error: " << e.what() << std::endl;
   }
 
   // 尝试删除空栈中的元素
   std::cout << "Trying to pop from an empty stack..." << std::endl;
   try {
       stack.pop();
       stack.pop(); // 这里会抛出异常
   } catch (const std::out_of_range& e) {
       std::cerr << "Error: " << e.what() << std::endl;
   }
 
   return 0;
}