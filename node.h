#ifndef NODE_H
#define NODE_H

#include <new>
#include <ostream>
#include <string>
#include <vector>

class node{
    private:
    static int node_id;
    std::string name;
    int nr_children = 0;
    std::vector<node*> *children = new std::vector<node*>();

    public:
    virtual ~node();
    friend std::ostream& operator<<(std::ostream& os,  node* node);

    node(const std::string& name="");
    std::string get_name();
    
    void set_name(std::string new_name);
    
    int get_nr_children();

    node* get_child(int i);

    void add_child(node* child);
    void print(std::ostream& str);
};

node* create_complete_tree(int nr_child_nodes,int tree_depth);


#endif
