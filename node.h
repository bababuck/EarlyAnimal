/* Each network node will follow this interface. 

Want to track the recent contributions before firing. If one input gives a lot of input right before the neuron fires, LPT
*/
#include <vector>

typedef connection_t;
typedef std::pair<int, int> coordinate_t;
typedef int32_t voltage_t;

class node_t {
public:
    node_t();
    ~node_t();
    void add_connection(connection_t connection);
    bool sample();
private:
    int fire_time;
    coordinate_t location;
    std::vector<connection_t> axon_connections;
    void fire();
    void recieve(voltage_t volts);
    void draw();
    void draw_connection(coordinate_t destination);
    float get_size();

    static int COOLDOWN_LENGTH;
    int cooldown_time_remaining;
    const static int THRESHOLD = 100;
    const static int DISTANCE = 5;
    voltage_t potential;
    int id; // For saving state
};

class pacemaker_node_t : node_t {
    
};

struct connection_t {
    voltage_t weight;
    node_t* towards;
};