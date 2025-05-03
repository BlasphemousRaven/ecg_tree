#ifndef NODE_H
#define NODE_H

#include <new>
#include <string>
#include <vector>

class node{
    private:
    std::string name;
    int nr_children = 0;
    std::vector<node*> *children = new std::vector<node*>();

    public:
    virtual ~node();
    node(const std::string&);
    std::string get_name();
    
    void set_name(std::string new_name);
    
    int get_nr_children();

    node* get_child(int i);

    void add_child(node* child);
};

#endif
