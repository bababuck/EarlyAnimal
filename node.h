/* Each network node will follow this interface. 

Want to track the recent contributions before firing. If one input gives a lot of input right before the neuron fires, LPT
*/
#include <vector>

typedef connection_t;
typedef std::pair<int, int> coordinate_t;

class node_t {
public:
    node_t();
    ~node_t();
    void add_connection(connection_t* connection);
    bool sample();
private:
    coordinate_t location;
    std::vector<connection_t*> axon_connections;
    void fire();
    void draw();
    void draw_connection(coordinate_t destination); 

    static int COOLDOWN_LENGTH;
    int cooldown_time_remaining;
    static int THRESHOLD;
    int potential;
    int id; // For saving state
};

class pacemaker_node_t : node_t {
    
};

struct connection_t {
    int weight;
    node_t* towards;
};