#include "node.h"
#include <ostream>
#include <set>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <stack>

int node::node_id = 1;
std::set<node*> node::nodes;

node::node(const std::string& name){
    if(name==""){
        //converts node id from int to str
        std::stringstream stream;
        stream << node_id;
        std::string id = stream.str();
        //sets  name to node and cur id
        std::string new_name = "node_" + id; 
        set_name(new_name);
        //increments global id
        node_id++;
    }
    else{
        //sets name to constructor parameter
        set_name(name);
    }

}

node::~node(){
    for(auto child:*children){
        delete child;
    }
    children->clear();
    nr_children = 0;
}

std::string node::get_name(){
    return this->name;
}

int node::get_nr_children(){
    return this->nr_children;
}

void node::set_name(std::string new_name){
    this->name = new_name;
}

void node::add_child(node* child){
    this->children->push_back(child);
    nr_children++;
    if(nodes.count(child)==0){
        child->depth = this->depth+1;
    }
    
    nodes.insert(this);
    nodes.insert(child);
}

node* node::get_child(int i){
    int len_children = this->children->size();

    //handle index out of range
    if (get_nr_children()<i) {return nullptr;}

    node* child = this->children->at(i);
    return child;

}

node* create_complete_tree(int nr_child_nodes, int tree_depth,int current_depth){
    if (tree_depth==0) {
        return nullptr;
    }

    node* root = new node();
    root->depth = current_depth;
    
    //for every child: create child and add to current root
    for(int i=0;i<nr_child_nodes;i++){
       //recursively assigns children 
        node* child = create_complete_tree(nr_child_nodes, tree_depth-1,current_depth+1);
        //if the child is not null it will be added to root
        if (child!=nullptr) {
            root->add_child(child);
        }
    }

    return root;
    
}

std::vector<node*>* node::get_children(){
    return this->children;
}

void node::print_rec(std::ostream& str,int depth,std::set<node*> visited){
    //creates indent depending depth
    for(int i=0;i<depth;i++){
        str<<"   ";
    }

    str<<this->get_name()<<std::endl;

    for(node* child: *this->get_children()){
        //if node has not been visited yet, it will be added to set
        //otherwise --> cycle
        if(visited.count(child)==0){
            visited.insert(child);
            child->print_rec(str,depth+1,visited);
        }
        else{
            str<<"cycle detected [  ";
            for(node* node:visited){
                
                str<<node->get_name()<<"  ";
            }
            str<<"]\n";
        }
    }
}

void node::print_it(std::ostream& str){
    std::stack<node*> nodes;
    std::set<node*> visited;
    
    nodes.push(this);
    
    while (nodes.size()!=0) {
        node* node = nodes.top();
        visited.insert(node);
        nodes.pop();
        for(auto child:*node->get_children()){
            if(visited.count(child)==0){
                nodes.push(child);
            }
        }
            
        for(int i=0;i<node->depth;i++){
            str<<"   ";
        }
        str<<node->get_name()<<"\n";
    }

    std::set<node*> cycle = detect_cycle(this);
    if (!cycle.empty()) {
        for (auto node:cycle) {
            std::cout<<node->get_name();
            std::cout<<" ";
        }

            std::cout<<"]"<<std::endl;
    }

}

//DFS for detecting cycle
std::set<node*> detect_cycle(node* root){
    std::stack<node*> nodes;
    std::set<node*> visited;

    nodes.push(root);
    
    while (nodes.size()) {
        visited.insert(nodes.top());
        node* cur_node = nodes.top();
        nodes.pop();
        for(auto child:*cur_node->get_children()){
            if(visited.count(child)){
                std::cout<<"CYCLE DETECTED: [ ";
                return visited;
            }
            nodes.push(child);
        }

    }
    return {};

}


std::ostream& operator<<(std::ostream& os, node* node){
    std::cout<<"-----Print Methode rekursiv------"<<std::endl;
    node->print_rec(os,0,{});
    std::cout<<"-----Print Methode iterativ------"<<std::endl;
    
    node->print_it(os);
    return os;
}