#pragma once
#include <string>
#include <vector>

/** This is a base class for particles in out Project.
 *
 *  Later we will subclass this.
 */
class Particle {
public:
  /** Constructing Particle with a name.
   *
   *  The syntax after the colon means, that the member m_name will be constructed
   *  with the value of the argument name and is called an initialization list.
   */
  Particle(const std::string& name) :
    m_name(name) {
  }

  /** Getter for Numer of Daughter Particles.
   *
   *  The "const" tells the compiler, that it is not allowed to change a member of the class Particle
   *  inside the function. <br>
   *  This function is only DECLARED here, but DEFINED in a separate .cc file.
   */
  unsigned getNDaughters() const;

  /** Adding a daughter Particle to this Particle.
   *
   *  We will take the address of the particle and store it internally.
   */
  void addDaughter(const Particle& particle);

  /** Getter for the name of the particle.*/
  std::string getName() const;

  bool operator == (const Particle& particle) {
    return (m_name == particle.m_name);
  }

private:
  std::string m_name;
  std::vector<Particle const*> m_directDaughters;
};
