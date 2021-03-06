/* A brain is composed of a set of neurons.

A brain needs to know:
- How to draw/redraw itself
- How to load/save to a file
- How to starts/pause a simulation
 */

class brain_t {
public:
    brain_t(std::string filename);
    ~brain_t();
    void draw();
    void save(std::string filename);
    void pause();
    void start();
private:
    void compute_locations();
    std::vector<node_t*> neurons;
    void gajer_et_al();
};

struct fire_t {
    node_t* source;
    node_t* destination;
    voltage_t weight;
    fire_t(node_t* _source, node_t* _destination, voltage_t _weight):source(_source), destination(_destination), weight(_weight){}
};

class simulator_t {
    static const int MAX_TIME = 800;
    int current_time;
    std::vector<fire_t> future_task;
    void add_fire(fire_t connection, int distance);
    void increment();
};

void brain_t::compute_locations() {
    /* Need to decide how to place the neurons for drawings.

    May want to recompute during the simulation as well.

    Will use this function to call the actual implementation,
    allows for easy interchange of algorithms.

    Is technically inefficient to compile the different algorithms
    since it will be determined at compile-time (for now).

    Overall, this function should assign each node a location (coordinate).
    */
    
}

void brain_t::gajer_et_al() {
    /* Implemention of the gajer_et_al algorithm, as found here:
    https://cs.brown.edu/people/rtamassi/gdhandbook/chapters/force-directed.pdf
    */

}