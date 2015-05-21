//
//  Composition.cpp
//  UML
//
//  Created by Manuel Giffels on 12.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//
#include <cmath>
#include <iostream>

class FourVector {
public:
    FourVector(double px, double py, double pz, double e):m_px(px),
                                                          m_py(py),
                                                          m_pz(pz),
                                                          m_e(e)
    {}
    double mag2() const {
        return m_e*m_e-m_px*m_px-m_py*m_py-m_pz*m_pz;
    }
private:
    double m_px,m_py,m_pz,m_e;
};

class Particle {
private:
    FourVector* m_momentum;
    
public:
    Particle(double px, double py, double pz, double e){
        m_momentum = new FourVector(px,py,pz,e);
    }
    ~Particle() {
        delete m_momentum;
    }

    double invariant_mass() const {
        double mag2 = m_momentum->mag2();
        return mag2 < 0.0 ? sqrt(-mag2) : sqrt(mag2);
    }

};

int main(int argc, char* argv[]) {
    Particle my_particle = Particle(1,2,3,4);
    std::cout << my_particle.invariant_mass() << std::endl;
    return 0;
}