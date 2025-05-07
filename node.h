#ifndef NODE_H
#define NODE_H

#include <new>
#include <ostream>
#include <string>
#include <vector>
#include <set>

class node{
    private:
    static int node_id;
    std::string name;
    int nr_children = 0;
    std::vector<node*> *children = new std::vector<node*>();

    public:
    //destructor
    virtual ~node();
    //constructor
    node(const std::string& name="");
    //overloaded << operator
    friend std::ostream& operator<<(std::ostream& os,  node* node);

    //getters and setters
    std::string get_name();
    void set_name(std::string new_name);
    int get_nr_children();
    node* get_child(int i);
    void add_child(node* child);
    std::vector<node*>* get_children();
    //print functions for tree output
    void print_rec(std::ostream& str,int depth,std::set<node*> visited);
    void print_it(std::ostream& str);
    int depth= 0; 

};

node* create_complete_tree(int nr_child_nodes,int tree_depth);


#endif
