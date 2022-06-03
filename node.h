/* Each network node will follow this interface. 


*/
#include <vector>

class node_t {
public:
    node_t();
    ~node_t();
    void add_connection(node_t* connection);
    bool sample();
private:
    std::vector<node_t*> axon_connections;
    void fire();

    static int COOLDOWN_LENGTH;
    int cooldown_time_remaining;
    static int THRESHOLD;
    int potential;
};

class pacemaker_node_t : node_t {
    
}