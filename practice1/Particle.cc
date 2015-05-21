#include <Particle.h>
#include <iostream>

using namespace std;

unsigned Particle::getNDaughters() const
{
  unsigned counter = m_directDaughters.size();
  for (auto & daughterPtr : m_directDaughters) {
    counter += daughterPtr->getNDaughters();
  }
  return counter;
}

void Particle::addDaughter(const Particle& particle)
{
  cout << "Adding particle "  << particle.getName()
       << " to the particle " << m_name << endl;
  m_directDaughters.push_back(&particle);
}

std::string Particle::getName() const
{
  return m_name;
}
