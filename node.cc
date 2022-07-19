void node_t::fire() {
    fire_time = get_time(); // HELP
    for (connection_t connection : axon_connections) {
        add_fire(fire_t(this, connection.towards, connection.weight), DISTANCE);
    }
}

void node_t::recieve(voltage_t volts) {
    potential += volts;
    if (potential >= THRESHOLD) {
        fire();
    }
}

void node_t::draw() {
    sf::CircleShape body(get_size());
    body.setFillColor(sf::Color(150, 50, 250));
    body.setPosition(location[0], location[1]);
    window.draw(shape);
    for (connection_t connection : axon_connections) {
        draw_connection(conection.towards->location);
    }
}

void node_t::draw_connection(coordinate_t destination) {
    float width = ; // HELP: need to calculate angle? Or approximate?
    float height = ;
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setSize(sf::Vector2f(100.f, 100.f));
}

float node_t::get_size(){
    /* Abstract the size so we can base off window size and total nodes. */
    return 5.0f;
}

