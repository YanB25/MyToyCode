#ifndef _USER_INTERFACE_HPP_
#define _USER_INTERFACE_HPP_
#include <string>
#include <vector>
using std::string;
using std::vector;
class Node {
public:
    Node(const string& msg, size_t n = 0, const string& err_msg = "") : match(msg), error_msg(err_msg) {
        child.resize(n);
    }
    
private:
   string error_msg;
   string match;
   vector<Node> child;
};
class UserInterface {
public:
private:
#endif
