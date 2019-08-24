#include <iostream>
#include <math.h>

#define CHARGES 3

class Vector
{
public:
    Vector();
    Vector(double x_pos, double y_pos);

    double x;
    double y;


    Vector operator+(const Vector right);
    Vector operator-(const Vector right);
    Vector operator*(const double right);
    Vector operator/(const double right);
    double r();
    Vector unit();
};

Vector::Vector(){
    x = 0.;
    y = 0.;
}

// Define what common operations look like for vectors

Vector Vector::operator+(const Vector right)
{
    return Vector(x+right.x, y+right.y);
}

Vector Vector::operator-(const Vector right)
{
    return Vector(x-right.x, y-right.y);
}

Vector Vector::operator*(const double right)
{
    return Vector(x*right, y*right);
}

Vector Vector::operator/(const double right)
{
    return Vector(x/right, y/right);
}

Vector::Vector(double x_pos, double y_pos)
{
    x = x_pos;
    y = y_pos;
}

double Vector::r() {
    return sqrt(x*x + y*y);
}

Vector Vector::unit()
{
    return Vector(x, y)/r();
}

// Create some more abscract classes that act on each other

class Particle
{
public:
    Particle();
    Particle(double charge, double mass, Vector position);

    Vector E(Vector loc);

    double q;
    double m;
    Vector pos;
};

Particle::Particle() {
    q = 0;
    m = 0;
}


Particle::Particle(double charge, double mass, Vector position)
{
    q = charge;
    m = mass;
    pos = position;
}

Vector Particle::E(Vector loc)
{
    Vector r_p = loc - pos;
    Vector E_loc = r_p.unit() * q / pow((r_p.r()), 2);
    return E_loc;
}

class World
{
public:
    World(Particle particles[CHARGES]);
    Vector E(Vector loc);

private:
    Particle particle [CHARGES];
};

World::World(Particle particles[CHARGES])
{
    for (int i=0; i<CHARGES; i++) {
        particle[i] = particles[i];
    }
}

Vector World::E(Vector loc)
{
    Vector E_loc = Vector(0., 0.);

    for (int i=0; i<CHARGES; i++) {
        E_loc = E_loc + particle[i].E(loc);
    }

    return E_loc;
}

// Simulate each step with the integrator

int integrator(World* world, Particle test_charge, double time_step, int steps, Vector *pos) {
    pos[0] = test_charge.pos;

    for (int i=1; i<steps; i++) {
        Vector a = world->E(pos[i-1])*(test_charge.q/test_charge.m);
        Vector new_pos = test_charge.pos + a*time_step;

        pos[i] = new_pos;
        test_charge.pos = new_pos;
    }

    return 0;
}

// Build and simulate the world

int main() {
    std::cout << "Calculating Path..." << std::endl;

    Particle particles[CHARGES] = {Particle(1., 1., Vector(1.,1.)),
                                   Particle(1., 1., Vector(-1.,1.)),
                                   Particle(1., 1., Vector(-1.,-1.))};

    World world = World(particles);

    int steps = 100;

    Vector pos [steps];

    Particle test_charge = Particle(1., 1., Vector(.5,.1));

    integrator(&world, test_charge, .1, steps, pos);

    for (int i=0; i<steps; i++) {
        std::cout << pos[i].x << ", " << pos[i].y << std::endl;
        int a = 0;
    }

    return 0;
}
